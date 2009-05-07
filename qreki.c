/*---------------------------------------------------------------------------*\
| Taian_teller :taian.exe version 0.90   [11469bytes]                         |
|     written by ral with Turbo Pascal Ver. 5.0                               |
| Taian_teller :taian.exe version 0.90e1 [24142bytes]                         |
|     modified by ethyl with MS-C Ver. 5.10A                                  |
\*---------------------------------------------------------------------------*/

/*
 *	日経Ｍｉｘ	listings.byte
 *
 *	日経 BYTE / January 1988 Hobby
 *		大安，仏滅が一発でわかる六曜プログラム p.239-243
 *		鈴木　隆
 *
 *		太陽と月の黄経を利用して
 *		1987.11.11. (WED)
 *		Ver.    1.01
 *		By      Takashi S.
 */

/*
 *	inreki.c
 *
 *	1990. 4. 7. SAT version 0.05b
 *	1990. 3.31. SAT version 0.05a
 *	1990. 3.24. SAT version 0.05
 *	1990. 3.11. SUN version 0.04a
 *	1990. 2.28. WED version 0.04
 *	1990. 2.27. TUE version 0.03
 *	1990. 2.26. MON	version 0.02 MS-DOS & UNIX debug
 *	1990. 2.25. SUN	version 0.01
 *
 *	Translated for MS-DOS & Human68k & UNIX By Yoshifumi Mori
 */

/*
 *	qreki.c
 *
 *		modified by Tsuporone (H.Tsujimura) tsupo@na.rim.or.jp
 *							17 February 1991
 *		このソースプログラムは ral氏の Taian_teller (Turbo Pascal版)
 *		を ethyl氏が MS-C に移植したものから必要な関数を取り出し、改
 *		造したものです。旧暦、黄経、節気の計算はあくまでも近似ですの
 *		で実際と食い違いが生じることがあります。
 *
 *                                                       3 December 1995
 *              さらに、森佳史氏の today.exe のソースの一部(inreki.c) を参考
 *              に「潮」の算出処理を追加しました。
 *
 * History :
 * $Log: qreki.c $
 * Revision 1.67  2003/03/31  05:21:49  tsujimura543
 * ヘッダファイルの依存関係を整理
 *
 * Revision 1.66  2003/03/19  03:05:48  tsujimura543
 * 旧暦関係の出力方法を他の暦と同じ方式にする
 *
 * Revision 1.65  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.64  2003/03/11  02:04:01  tsujimura543
 * for Tsuporone's Activity memo
 *
 * Revision 1.63  2003/03/03  07:48:04  tsujimura543
 * 不成就日に対応
 *
 * Revision 1.62  2002/12/20  07:51:57  tsujimura543
 * 臘日の表示を追加
 *
 * Revision 1.61  2001/02/21  14:16:36  tsujimura543
 * HTMLモード対応済みの revision と統合
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.53  2001/01/22  08:44:28  tsujimura543
 * ここ最近の年の24節気関連の日付がおかしい(2001年の節分が2月1日と表示され
 * る、など)不具合に対処
 * 
 * Revision 1.52  2000/08/23  11:03:57  tsujimura543
 * 2000年の入梅の日付がおかしい不具合に対処
 * 
 * Revision 1.51  1999/07/06  18:49:09  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう
 *
 * Revision 1.50  1996/08/19  02:10:16  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.7  95/12/03 11:43:58  tsujimura
 * コメントの整理・修正
 * 
 * Revision 1.6  95/12/02 19:07:00  tsujimura
 * 潮の表示を追加
 * 
 * Revision 1.5  92/03/29 16:28:58  tsujimura
 * test release
 * 
 * Revision 1.4  91/03/17 16:40:16  tsujimura
 * test version
 * 
 * Revision 1.3  91/03/17 16:40:16  tsujimura
 * changed functions for calculation of old-japanese-calendar
 * 
 * Revision 1.2  91/03/02 05:53:30  tsujimura
 * added many features
 * 
 * Revision 1.1  91/02/17 10:58:08  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <math.h>
#ifdef	MSDOS
#define	PI	3.1415926535897932
#endif
#ifdef	unix
#define	PI	M_PI
#endif
#ifndef PI
#define PI  3.1415926535897932
#endif

#include <stdlib.h>
#include <string.h>
#include "dates.h"

#define	RAD_PER_DEG	(PI * 2.0 / 360.0)
#define	DAY_PER_YEAR	(1.0 / 365.25)


#ifndef	lint
static char	*rcs_id =
	"$Header: D:/user/local/src/tamo/RCS/qreki.c 1.67 2003/03/31 05:21:49 tsujimura543 Exp $";
#endif

#ifdef	__STDC__
static int	calc_new_moon( double yrs, double *mn_kk, double *sn_kk);
#else
static int	calc_new_moon();
#endif


/*---------------------------------------------------------------------------*\
|        旧暦算出ルーチン                                                     |
\*---------------------------------------------------------------------------*/

static char *sk[] = {"春分", "清明", "穀雨", "立夏", "小満", "芒種",
                     "夏至", "小暑", "大暑", "立秋", "処暑", "白露",
                     "秋分", "寒露", "霜降", "立冬", "小雪", "大雪",
                     "冬至", "小寒", "大寒", "立春", "雨水", "啓蟄"};
static char *rk[] = {"先勝", "友引", "先負", "仏滅", "大安", "赤口"};


static double	sun_cel_value;
static double	years;

struct	CONST_TBL {				/* constant table	  */
	double	ef;	/* 振幅     */		/* amplitude of vibration */
	double	ph;	/* 初期位相 */		/* initial phase	  */
	double	sc;	/* 角速度   */		/* angular velocity	  */
};

#define	MOON_N	13	/* 月 黄経 摂動項の数 */

static	struct	CONST_TBL	mn[14] = {	/* 月 黄経 */	/* 21 */
    /*  振幅　 初期位相　　   角速度  */
    { 0.0000 , 124.8754 ,  4812.67881 }, /* 初期値  平均角速度 */
    { 6.2887 , 338.915  ,   4771.9886 }, /* 中心差(　近点月: 27.55455日) */
    { 1.2740 , 107.248  ,  -4133.3536 }, /*  出 差(　　　　: 31.81194日) */
    { 0.6583 ,  51.668  ,   8905.3422 }, /* 二均差(半朔望月: 14.76529日) */
    { 0.2136 , 317.831  ,   9543.9773 }, /* 　　　(半近点月: 13.77728日) */
    { 0.1856 , 176.531  ,    359.9905 }, /*  年 差(　近点年:365.25964日) */
    { 0.1143 , 292.463  ,   9664.0404 },
    { 0.0588 ,  86.160  ,    638.6350 },
    { 0.0572 , 103.780  ,  -3773.3630 },
    { 0.0533 ,  30.580  ,  13677.3310 },
    { 0.0459 , 124.860  ,  -8545.3520 },
    { 0.0410 , 342.380  ,   4411.9980 },
    { 0.0348 ,  25.830  ,   4452.6710 }, /* 月角差(　朔望月: 29.53059日) */
    { 0.0305 , 155.450  ,   5131.9790 }
/*  { 0.0153 , 240.790  ,    758.6980 },
 *  { 0.0125 , 271.380  ,  14436.0290 },
 *  { 0.0110 , 226.450  ,  -4892.0520 },
 *  { 0.0107 ,  55.580  , -13038.6960 },
 *  { 0.0100 , 296.750  ,  14315.9660 },
 *  { 0.0085 ,  34.500  ,  -8266.7100 },
 *  { 0.0079 , 290.700  ,  -4493.3400 }
 */
};

#if	0
#define	MOON_M	4	/* 月 黄緯 摂動項の数 */

static	struct	CONST_TBL	mn2[5] = {	/* 月 黄緯 */	/* 10 */
   /*  振幅　 初期位相　　   角速度 */
    { 0.0000 ,   0.000 ,      0.0000 },	/* 初期値 ?? */
    { 5.1282 , 236.231 ,   4832.0202 },
    { 0.2806 , 215.147 ,   9604.0088 },
    { 0.2777 ,  77.316 ,     60.0316 },
    { 0.1732 ,   4.563 ,  -4073.3220 }
/*  { 0.0554 , 308.980 ,   8965.3740 },	*/
/*  { 0.0463 , 343.480 ,    698.6670 },	*/
/*  { 0.0326 , 287.900 ,  13737.3620 },	*/
/*  { 0.0172 , 194.060 ,  14375.9970 },	*/
/*  { 0.0093 ,  25.600 ,  -8845.3100 },	*/
/*  { 0.0088 ,  98.400 ,  -4711.9600 }	*/
};
#endif

#define	SUN_N	10	/* 太陽 黄経 摂動項の数 */
#define	SUN_EF1	0.00005

static	struct	CONST_TBL	sn[11] = {	/* 太陽 黄経 */	/* 16 */
    /*  振幅　 初期位相　　   角速度   */
    { 0.0000 , 279.0358 ,    360.00769 }, /* 初期値  平均角速度		     */
    { 1.9159 , 356.531  ,    359.9910  }, /*       (　近点年:365.25964日) */
    { 0.0200 , 353.060  ,    719.9810  }, /*       (半近点年:182.62982日) */
    { -.0048 , 248.640  ,    -19.3410  },
    { 0.0020 , 285.000  ,    329.6400  },
    { 0.0018 , 334.200  ,  -4452.6700  },
    { 0.0018 , 293.700  ,      0.2000  },
    { 0.0015 , 242.400  ,    450.3700  },
    { 0.0013 , 211.100  ,    225.1800  },
    { 0.0008 , 208.000  ,    659.2900  },
    { 0.0007 ,  53.500  ,     90.3800  }
/*  { 0.0007 ,  12.100  ,    -30.3500  },
 *  { 0.0006 , 239.100  ,    337.1800  },
 *  { 0.0005 ,  10.100  ,     -1.5000  },
 *  { 0.0005 ,  99.100  ,    -22.8100  },
 *  { 0.0004 , 264.800  ,    315.5600  }
 */
};


/*　ユリウス世紀を求める  */
double
julcen(ld)
long ld;	/* ユリウス日 */
{
	return((ld - 15019.5) / 36525);
}

/*  ユリウス世紀 → 月の離角 → 月齢　*/
int
geturei(ld)
long ld;	/* ユリウス日 */
{
	long l;	/* 小数点以下切捨て用のテンポラリ */
	double a, b, rikaku;

	a = julcen(ld);
	b = 350.434164 + 444960.0 * a + 307.114217 * a +
	    1.436 * a * a * 10E-03;
	l = (long)(b / 360.0);
	rikaku = b - (double)l * 360.0;
	return( (int)(29.4 * rikaku / 360.0) );
}


/*** 基準年(1975年1月1日)からの年数 ***/
static
double	year_sum( d, m, y )
int	d, m, y;
{
	int	tmp;

	tmp = absoluteFromGregorian(d,m,y)-720988L;

	return (((double)tmp + (-9.0 / 24.0)) / 365.25);
}


/*** 月 黄経 ***/
static
double	moon_cel(yrs)
double	yrs;
{
	register int	i;
	double		moon_cel_val;

	moon_cel_val = mn[0].ph + mn[0].sc * yrs;
	for (i = 1; i <= MOON_N; i++) {
		moon_cel_val +=
		    mn[i].ef * sin(RAD_PER_DEG * (mn[i].ph + mn[i].sc * yrs));
	}
	return ( fmod( moon_cel_val, 360.0 ) );
}


/*** 太陽 黄経 ***/
static
double	sun_cel(yrs)
double	yrs;
{
	register int	i;

	sun_cel_value = sn[0].ph + sn[0].sc * yrs;
	if (SUN_N > 1) {
	    sun_cel_value -=
		SUN_EF1 * yrs * sin(RAD_PER_DEG * (sn[1].ph + sn[1].sc * yrs));
	}
	for (i = 1; i <= SUN_N; i++) {
	    sun_cel_value +=
	        sn[i].ef * sin(RAD_PER_DEG * (sn[i].ph + sn[i].sc * yrs));
	}
	return ( fmod( sun_cel_value, 360.0 ) );
}

#define	NEE     0   /* 子 */
#define	USHI    1   /* 丑 */
#define	TORA    2   /* 寅 */
#define	UU      3   /* 卯 */
#define	TATSU   4   /* 辰 */
#define	MEE     5   /* 巳 */
#define	UMA     6   /* 午 */
#define	HITSUJI 7   /* 未 */
#define	SARU    8   /* 申 */
#define	TORI    9   /* 酉 */
#define	IMU     10  /* 戌 */
#define	WII     11  /* 亥 */

#define	shi(g)			( ( (g) + 2 ) %  12 )

/*** 二十四節気 ***/
char	*
getSekkiName( day, month, year, sekki_no, kokei )
int	day, month, year, *sekki_no, *kokei;
{
	int     sekki, sekki1, sekki2;
	double  sun_cel1, sun_cel2, yrs;

	/*** 太陽 黄経 ***/
	years = yrs = year_sum(day, month, year);
	sun_cel1 = sun_cel(yrs);
	sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
	if (sun_cel2 < sun_cel1)
		sun_cel2 += 360.0;

	/*** 二十四節気 ***/
	sekki  = -1;
	sekki1 = (int)sun_cel1 / 15;
	sekki2 = (int)sun_cel2 / 15;

	*sekki_no = -1;
	*kokei = (int)sun_cel2 / 1;
	if ( *kokei % 90 == 27 )
		return( "土用" );
	if ( ( *kokei >= 117 ) && ( *kokei < 135 ) )
		if ( shi( absoluteFromGregorian(day,month,year) ) == USHI )
			return ( "土用の丑" );
	if ( (*kokei == 80) && (sun_cel1 <= 80.0) ) {	/* for 2000.06.10-11 */
		return( "入梅" );
	}
	if ( *kokei == 100 )
		return( "半夏生" );

	if (sekki1 < sekki2)
		sekki = sekki2;
	if (sekki == 24)
		sekki = 0;
	if (sekki < 0)
		return ( NULL );

	*sekki_no = sekki;
	return ( sk[sekki] );
}

long
getSekkiDate( day, month, year )
int	day, month, year;
{
	long	d = absoluteFromGregorian( day, month, year ) - 1;
	double	sun_cel1, sun_cel2, yrs;
#ifdef	USE_INTEGER
	int	sekki, sekki1, sekki2, tmp;

	tmp = d - 720987L;	/* 1975年 1月 1日からの通日 */
	do {
		/*** 太陽 黄経 ***/
		yrs = ((double)tmp + (-9.0 / 24.0)) / 365.25;
		tmp++; d++;
		sun_cel1 = sun_cel(yrs);
		sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
		if (sun_cel2 < sun_cel1)
			sun_cel2 += 360.0;

		/*** 二十四節気 ***/
		sekki  = -1;
		sekki1 = (int)sun_cel1 / 15;
		sekki2 = (int)sun_cel2 / 15;

		if (sekki1 < sekki2)
			sekki = sekki2;
		if (sekki == 24)
			sekki = 0;
	} while (sekki < 0);
#else
	double	sekki, sekki1, sekki2, tmp;

	tmp = d - 720987.0;	/* 1975年 1月 1日からの通日 */

	do {
		/*** 太陽 黄経 ***/
		yrs = (tmp + (-9.0 / 24.0)) / 365.25;
		tmp += 1.0;
		d++;
		sun_cel1 = sun_cel(yrs);
		sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
		if (sun_cel2 < sun_cel1)
			sun_cel2 += 360.0;

		/*** 二十四節気 ***/
		sekki  = -1.0;
		sekki1 = sun_cel1 / 15.0;
		sekki2 = sun_cel2 / 15.0;

		if (sekki1 < sekki2)
			sekki = sekki2;
		if (sekki >= 24.0)
			sekki -= 24.0;
	} while ( /* sekki < 0.0 */ sekki - floor(sekki) > 0.1 );
#endif

	return ( d );
}

/*
 *	立春の日を求める
 */
long
springStartDay( y )
int	y;
{
	return ( getSekkiDate( 2, 2, y ) );
}

/*
 *	春分の日を求める
 */
long
midSpringDay( y )
int	y;
{
	return ( getSekkiDate( 19, 3, y ) );
}

/*
 *	夏至の日を求める
 */
long
midSummerDay( y )
int	y;
{
	return ( getSekkiDate( 20, 6, y ) );
}

/*
 *	立秋の日を求める
 */
long
autumnStartDay( y )
int	y;
{
	return ( getSekkiDate( 6, 8, y ) );
}

/*
 *	秋分の日を求める
 */
long
midAutumnDay( y )
int	y;
{
	return ( getSekkiDate( 22, 9, y ) );
}

/*
 *	節入りの日を求める
 */
long
setsuStartDay( mm, yy )
int	mm, yy;
{
	static int	day[] = {
		2,	/* 正月節  (立春) */
		5,	/* 二月節  (啓蟄) */
		4,	/* 三月節  (清明) */
		5,	/* 四月節  (立夏) */
		5,	/* 五月節  (芒種) */
		6,	/* 六月節  (小暑) */
		6,	/* 七月節  (立秋) */
		7,	/* 八月節  (白露) */
		8,	/* 九月節  (寒露) */
		7,	/* 十月節  (立冬) */
		6,	/* 十一月節(大雪) */
		5	/* 十二月節(小寒) */
	};
	return ( getSekkiDate( day[(mm-1)%12], mm, yy ) );
}

/*** 前の朔 ***/
static
int	back_new_moon(yrs, day_before)
double	yrs;
int	*day_before;
{
	int	new_moon_flag;
	double	sn_kk, tmp;

	(*day_before) += 28;
	do {
	    new_moon_flag =
		calc_new_moon(yrs - DAY_PER_YEAR * (*day_before),&tmp,&sn_kk);
	    (*day_before)++;
	} while (new_moon_flag == 0);
	return	((int)sn_kk / 30);
}

/*** 次の朔 ***/
static
int	next_new_moon(yrs, day_after)
double	yrs;
int	*day_after;
{
	int	new_moon_flag;
	double	sn_kk, tmp;

	(*day_after) += 28;
	do {
	    new_moon_flag =
		calc_new_moon(yrs + DAY_PER_YEAR * (*day_after),&tmp,&sn_kk);
	    (*day_after)++;
	} while (new_moon_flag == 0);
	return	((int)sn_kk / 30);
}

/*** 月朔 ***/
static
int	calc_new_moon(yrs, mn_kk, sn_kk)
double	yrs;
double	*mn_kk, *sn_kk;
{
	int	new_moon_flag;
	double	sn_kk1, mn_kk1;
	double	sn_kk2, mn_kk2;

	/*** 黄経 ***/
	mn_kk1 = moon_cel(yrs);
	sn_kk1 = sun_cel(yrs);
	mn_kk2 = moon_cel(yrs + DAY_PER_YEAR);
	sn_kk2 = sun_cel(yrs + DAY_PER_YEAR);
	if (mn_kk2 < mn_kk1)
		mn_kk2 += 360.0;
	if (sn_kk2 < sn_kk1)
		sn_kk2 += 360.0;

	/*** 朔 ***/
	new_moon_flag = 0;
	if ((mn_kk1 < sn_kk1) && (mn_kk2 > sn_kk2))
		new_moon_flag = 1;
	if ((mn_kk1 < (sn_kk1 + 360.0)) && ((sn_kk2 + 360.0) < mn_kk2)) {
		new_moon_flag = 1;
		sn_kk1 += 360.0;
/*		sn_kk2 += 360.0;	*/
	}
	*mn_kk = mn_kk1;
	*sn_kk = sn_kk1;
	return	(new_moon_flag);
}


/*** 定朔・定気による陰暦計算 ***/
void
getLunarCalendar(day, month, year, uruu)
int	*day, *month, *year, *uruu;
{
	int	day_before;
	int	day_after;
	int	year_up;
	int	lc_month0;
	int	sk_month0;
	int	moon_before;
	int	moon_after;
	int	new_moon_flag;
	int	new_moon_before;
	int	new_moon_after;
	double	yrs;
	double	cel_mn, cel_sn;

#if	0
	yrs = year_sum( *day, *month, *year );
#else
	yrs = years;
#endif
	day_before = 1;
	year_up = 0;

	/*** 今月の朔 ***/
	new_moon_flag = calc_new_moon(yrs, &cel_mn, &cel_sn);
	new_moon_before = (int)cel_sn / 30;
	if (cel_mn < cel_sn)
		cel_mn += 360.0;
	if (new_moon_flag == 0) {
		day_before = (int)(cel_mn - cel_sn) / 13 - 28;
		new_moon_before = back_new_moon(yrs, &day_before);
	}
	*day = day_before;				/* 太陰暦 日 */
	lc_month0 = new_moon_before + 2;

	/*** 来月の朔 ***/
	day_after = -day_before;
	new_moon_after = next_new_moon(yrs, &day_after);
	if (new_moon_after < new_moon_before) {
		new_moon_after += 12;
	}
	sk_month0 = (int)new_moon_after / 3 * 3;
	*month = new_moon_after + 2;
	*uruu  = 0;
	if (lc_month0 == *month)
		*uruu = 1;
	*year = 1975 + (int)yrs - 1;
	if ((sun_cel_value - (double)((long)(yrs) * 360L)) > 360.0)
		year_up = 1;

	/*** 前の２分２至 ***/
	moon_before = 0;
	if (new_moon_before > (sk_month0 + 2)) {
		moon_before = new_moon_before - sk_month0 - 2;
		day_before += 29 * moon_before;
	}
	while (new_moon_before >= sk_month0) {
		moon_before++;
		new_moon_before = back_new_moon(yrs, &day_before);
		if (new_moon_before > new_moon_after)
			new_moon_before -= 12;
	}

	/*** 次の２分２至 ***/
	moon_after = 3 - moon_before - 1;
	if (moon_after < 0)
		moon_after = 0;
	day_after += 29 * moon_after;
	while (new_moon_after < (sk_month0 + 3)) {
		moon_after++;
		new_moon_after = next_new_moon(yrs, &day_after);
		if (new_moon_after < new_moon_before)
			new_moon_after += 12;
	}

	if ((moon_before + moon_after) == 3) {
		*month = sk_month0 + 2 + moon_before;
		*uruu  = 0;
	}
	if (*month > 12) {
		(*month) -= 12;
		year_up = 2;
	}
	if (year_up > 0)
		(*year)++;
}


char	*
get_kyureki( d, m, y, u )
int	*d, *m, *y, *u;
{
	int         sekki, kokei;
	char        *p;

	p = getSekkiName( *d, *m, *y, &sekki, &kokei );
	getLunarCalendar( d, m, y, u );

    return ( p );
}

void
#ifdef  __STDC__
checkKyureki( int d, int m, int y, int u, char *sekkiName, int htmlMode )
#else
checkKyureki( d, m, y, u, sekkiName, htmlMode )
int     d, m, y, u;
char    *sekkiName;
int     htmlMode;
#endif
{
    printf( "  %s", rk[(m + d - 2) % 6] );

    if ( sekkiName )
        printf( "  %s", sekkiName );

    if ( ( d == 10 ) || ( d == 25 ) )
        printf( "  長潮" );
    if ( ( d == 11 ) || ( d == 26 ) )
        printf( "  若潮" );
    if ( ( ( d >=  3 ) && ( d <=  6 ) ) ||
         ( ( d >= 12 ) && ( d <= 13 ) ) ||
         ( ( d >= 18 ) && ( d <= 21 ) ) ||
         ( ( d >= 27 ) && ( d <= 28 ) )    )
        printf( "  中潮" );
    if (   ( d <=  2 )                   ||
         ( ( d >= 14 ) && ( d <= 17 ) ) ||
           ( d >= 29 )                      )
        printf( "  大潮" );
    if ( ( ( d >=  7 ) && ( d <=  9 ) ) ||
         ( ( d >= 22 ) && ( d <= 24 ) )    )
        printf( "  小潮" );

    if ( ( m == 1 ) && ( d == 1 ) )
        printf( "  旧正月" );
    if ( ( m == 8 ) && ( d == 15 ) )
        printf( "  十五夜" );
    if ( ( m == 9 ) && ( d == 13 ) )
        printf( "  十三夜" );

    if ( ( m == 12 ) && ( d == 8 ) )
        printf( "  臘日" );

    switch ( m ) {
    case  1 : /* 旧 1月 */
    case  7 : /* 旧 7月 */
        if ( (d + 5) % 8 == 0 )	/* 3日,11日,19日,27日 */
            printf( "  不成就日" );
        break;
    case  2 : /* 旧 2月 */
    case  8 : /* 旧 8月 */
        if ( (d + 6) % 8 == 0 )	/* 2日,10日,18日,26日 */
            printf( "  不成就日" );
        break;
    case  3 : /* 旧 3月 */
    case  9 : /* 旧 9月 */
        if ( (d + 7) % 8 == 0 )	/* 1日,9日,17日,25日 */
            printf( "  不成就日" );
        break;
    case  4 : /* 旧 4月 */
    case 10 : /* 旧10月 */
        if ( (d + 4) % 8 == 0 )	/* 4日,12日,20日,28日 */
            printf( "  不成就日" );
        break;
    case  5 : /* 旧 5月 */
    case 11 : /* 旧11月 */
        if ( (d + 3) % 8 == 0 )	/* 5日,13日,21日,29日 */
            printf( "  不成就日" );
        break;
    case  6 : /* 旧 6月 */
    case 12 : /* 旧12月 */
        if ( (d + 2) % 8 == 0 )	/* 6日,14日,22日,30日 */
            printf( "  不成就日" );
        break;
    }
}
