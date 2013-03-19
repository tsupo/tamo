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
 * $Log: tamo_qreki.c $
 * Revision 1.91  2013/01/22  10:28:38  tsujimura543
 * 土用関連、修正
 *
 * Revision 1.90  2013/01/22  08:01:10  tsujimura543
 * 二十四節季関連を修正
 *
 * Revision 1.89  2012/08/21  11:02:10  tsujimura543
 * 「中秋節(中国)」を追加
 *
 * Revision 1.88  2012/08/21  07:40:17  tsujimura543
 * 「亥の子」を追加
 *
 * Revision 1.87  2012/08/20  09:06:37  tsujimura543
 * 旧暦の2033年問題の対策を実装
 *
 * Revision 1.86  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.85  2003/11/07  12:03:00  tsujimura543
 * 諸外国の祝祭日を追加
 *
 * Revision 1.84  2003/10/24  02:41:14  tsujimura543
 * データファイルの置き場所を統一
 *
 * Revision 1.83  2003/05/30  07:49:50  tsujimura543
 * 土用関連の行事を追加
 *
 * Revision 1.82  2003/04/25  04:49:21  tsujimura543
 * sun_cel_value をグローバル変数ではなくしたことによる不具合を修正
 * (旧暦の年表示が1年小さく表示されることがある)
 *
 * Revision 1.81  2003/04/23  12:04:33  tsujimura543
 * 不要なコードを削除
 *
 * Revision 1.80  2003/04/23  12:00:37  tsujimura543
 * 土用の丑と土用の二の丑を区別できるようにした
 *
 * Revision 1.79  2003/04/23  11:30:44  tsujimura543
 * 1880年の入梅が6月10日と11日の両方になってしまう不具合に対処
 *
 * Revision 1.78  2003/04/23  11:19:44  tsujimura543
 * 1975年以前の雑節(入梅、半夏生、土用)の表示に対応
 *
 * Revision 1.77  2003/04/23  11:09:07  tsujimura543
 * 入梅、半夏生、土用の表示を太陽暦の方へ移す
 * (今回の修正で必要なくなった関数を削除)
 *
 * Revision 1.76  2003/04/23  09:44:15  tsujimura543
 * 社日の表示を太陰太陽暦の方からは外す
 *
 * Revision 1.75  2003/04/23  09:27:12  tsujimura543
 * 24節気の表示を太陰太陽暦(旧暦)から太陽暦(新暦)の方に移す
 *
 * Revision 1.74  2003/04/16  05:56:37  tsujimura543
 * データファイルを一定の規則にしたがって探索しオープンするようにした
 *
 * Revision 1.73  2003/04/15  12:36:01  tsujimura543
 * qdate.csv を使って旧暦を求める場合、(新暦)12月のみ新月(旧暦1日)以降の表示が
 * おかしくなる(新暦と同じ年月日になってしまう)不具合を修正
 *
 * Revision 1.72  2003/04/15  05:25:58  tsujimura543
 * 旧暦の行事を追加
 *
 * Revision 1.71  2003/03/31  11:24:31  tsujimura543
 * 和暦(太陽太陰暦)関連修正 (getSekkiDateByName() を追加)
 *
 * Revision 1.70  2003/03/31  05:21:49  tsujimura543
 * ヘッダファイルの依存関係を整理
 *
 * Revision 1.69  2003/03/24  08:58:03  tsujimura543
 * (1) 和暦(太陰太陽暦)の表示可能期間を拡張
 * (2) 大暑と土用の丑の日が重なった場合、片方しか表示されない不具合を修正
 *
 * Revision 1.68  2003/03/20  10:04:33  tsujimura543
 * 凶会日を「節入日による月」ではなく、実際の旧暦の月を元に計算するよう修正
 *
 * Revision 1.67  2003/03/20  09:18:02  tsujimura543
 * 各種暦注の表示を追加
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
#include "tamo.h"

#define	RAD_PER_DEG	(PI * 2.0 / 360.0)
#define	DAY_PER_YEAR	(1.0 / 365.25)


#ifndef	lint
static char	*rcs_id =
  "$Header: C:/user/local/src/tamo/RCS/tamo_qreki.c 1.91 2013/01/22 10:28:38 tsujimura543 Exp tsujimura543 $";
#endif

static int	calc_new_moon( double yrs, double *mn_kk, double *sn_kk );


/*---------------------------------------------------------------------------*\
|        旧暦算出ルーチン                                                     |
\*---------------------------------------------------------------------------*/

#if 0
static char *sk[] = {"春分", "清明", "穀雨", "立夏", "小満", "芒種",
                     "夏至", "小暑", "大暑", "立秋", "処暑", "白露",
                     "秋分", "寒露", "霜降", "立冬", "小雪", "大雪",
                     "冬至", "小寒", "大寒", "立春", "雨水", "啓蟄"};
#endif
static char *rk[] = {"先勝", "友引", "先負", "仏滅", "大安", "赤口"};


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
julcen( long ld )   /* ld: ユリウス日 */
{
    return((ld - 15019.5) / 36525);
}

/*  ユリウス世紀 → 月の離角 → 月齢　*/
int
geturei( long ld )  /* ld: ユリウス日 */
{
    long    l;  /* 小数点以下切捨て用のテンポラリ */
    double  a, b, rikaku;

    a = julcen(ld);
    b = 350.434164 + 444960.0 * a + 307.114217 * a +
            1.436 * a * a * 10E-03;
    l = (long)(b / 360.0);
    rikaku = b - (double)l * 360.0;
    return( (int)(29.4 * rikaku / 360.0) );
}


/*** 基準年(1975年1月1日)からの年数 ***/
static double
year_sum( int d, int m, int y )
{
    int tmp;

    tmp = absoluteFromGregorian(d,m,y)-720988L;
    return (((double)tmp + (-9.0 / 24.0)) / 365.25);
}


/*** 月 黄経 ***/
static double
moon_cel( double yrs )
{
    register int    i;
    double          moon_cel_val;

    moon_cel_val = mn[0].ph + mn[0].sc * yrs;
    for (i = 1; i <= MOON_N; i++) {
        moon_cel_val +=
                    mn[i].ef * sin(RAD_PER_DEG * (mn[i].ph + mn[i].sc * yrs));
    }
    return ( fmod( moon_cel_val, 360.0 ) );
}


/*** 太陽 黄経 ***/
static double
sun_cel( double yrs )
{
    int     i;
    double	sun_cel_value;

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

static double
sun_cel_val( double yrs )
{
    int     i;
    double	sun_cel_value;

    sun_cel_value = sn[0].ph + sn[0].sc * yrs;
    if (SUN_N > 1) {
        sun_cel_value -=
                SUN_EF1 * yrs * sin(RAD_PER_DEG * (sn[1].ph + sn[1].sc * yrs));
    }
    for (i = 1; i <= SUN_N; i++) {
        sun_cel_value +=
                sn[i].ef * sin(RAD_PER_DEG * (sn[i].ph + sn[i].sc * yrs));
    }
    return ( sun_cel_value );
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

long
getSekkiDate( int day, int month, int year )
{
    long    d = absoluteFromGregorian( day, month, year ) - 1;
    double  sun_cel1, sun_cel2, yrs;
    double  sekki, sekki1, sekki2, tmp;

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
    } while ( sekki - floor(sekki) > 0.1 );

    return ( d );
}

/*
 *	立春の日を求める
 */
long
springStartDay( int y )
{
    return ( getSekkiDate( 2, 2, y ) );
}

/*
 *	春分の日を求める
 */
long
midSpringDay( int y )
{
    return ( getSekkiDate( 19, 3, y ) );
}

/*
 *	立夏の日を求める
 */
long
summerStartDay( int y )
{
    return ( getSekkiDate( 4, 5, y ) );
}

/*
 *	夏至の日を求める
 */
long
midSummerDay( int y )
{
    return ( getSekkiDate( 19, 6, y ) );
}

/*
 *	立秋の日を求める
 */
long
autumnStartDay( int y )
{
    return ( getSekkiDate( 5, 8, y ) );
}

/*
 *	秋分の日を求める
 */
long
midAutumnDay( int y )
{
    return ( getSekkiDate( 21, 9, y ) );
}

/*
 *	立冬の日を求める
 */
long
winterStartDay( int y )
{
    return ( getSekkiDate( 6, 11, y ) );
}

/*
 *  24節気の日を求める
 */

long
sekkiDay( int sekkiKind, int y )
{
    long    d = -1;

    switch ( sekkiKind ) {
    case SK24_SHOUKAN:      /* 小寒 */
        d = getSekkiDate( 5, 1, y );
        break;
    case SK24_DAIKAN:       /* 大寒 */
        d = getSekkiDate( 19, 1, y );
        break;
    case SK24_RISSHUN:      /* 立春 */
        d = springStartDay( y );
        break;
    case SK24_USUI:         /* 雨水 */
        d = getSekkiDate( 16, 2, y );
        break;
    case SK24_KEICHITSU:    /* 啓蟄 */
        d = getSekkiDate( 5, 3, y );
        break;
    case SK24_SHUNBUN:      /* 春分 */
        d = midSpringDay( y );
        break;
    case SK24_SEIMEI:       /* 清明 */
        d = getSekkiDate( 4, 4, y );
        break;
    case SK24_KOKUU:        /* 穀雨 */
        d = getSekkiDate( 18, 4, y );
        break;
    case SK24_RIKKA:        /* 立夏 */
        d = summerStartDay( y );
        break;
    case SK24_SHOUMAN:      /* 小満 */
        d = getSekkiDate( 18, 5, y );
        break;
    case SK24_BOUSHU:       /* 芒種 */
        d = getSekkiDate( 4, 6, y );
        break;
    case SK24_GESHI:        /* 夏至 */
        d = midSummerDay( y );
        break;
    case SK24_SHOUSHO:      /* 小暑 */
        d = getSekkiDate( 5, 7, y );
        break;
    case SK24_TAISHO:       /* 大暑 */
        d = getSekkiDate( 19, 7, y );
        break;
    case SK24_RISSHUU:      /* 立秋 */
        d = autumnStartDay( y );
        break;
    case SK24_SHOSHO:       /* 処暑 */
        d = getSekkiDate( 20, 8, y );
        break;
    case SK24_HAKURO:       /* 白露 */
        d = getSekkiDate( 5, 9, y );
        break;
    case SK24_SHUUBUN:      /* 秋分 */
        d = midAutumnDay( y );
        break;
    case SK24_KANRO:        /* 寒露 */
        d = getSekkiDate( 7, 10, y );
        break;
    case SK24_SOUKOU:       /* 霜降 */
        d = getSekkiDate( 22, 10, y );
        break;
    case SK24_RITTOU:       /* 立冬 */
        d = winterStartDay( y );
        break;
    case SK24_SHOUSETSU:    /* 小雪 */
        d = getSekkiDate( 21, 11, y );
        break;
    case SK24_TAISETSU:     /* 大雪 */
        d = getSekkiDate( 6, 12, y );
        break;
    case SK24_TOUJI:        /* 冬至 */
        d = getSekkiDate( 20, 12, y );
        break;
    }

    return ( d );
}

/*
 *	節入りの日を求める
 */
long
setsuStartDay( int mm, int yy )
{
    static int  day[] = {
        2,  /* 正月節  (立春) */
        5,  /* 二月節  (啓蟄) */
        4,  /* 三月節  (清明) */
        5,  /* 四月節  (立夏) */
       	5,  /* 五月節  (芒種) */
        6,  /* 六月節  (小暑) */
        6,  /* 七月節  (立秋) */
       	7,  /* 八月節  (白露) */
        8,  /* 九月節  (寒露) */
        7,  /* 十月節  (立冬) */
       	6,  /* 十一月節(大雪) */
        5   /* 十二月節(小寒) */
    };

    return ( getSekkiDate( day[(mm-1)%12], mm, yy ) );
}

/*** 前の朔 ***/
static int
back_new_moon( double yrs, int *day_before )
{
    int     new_moon_flag;
    double  sn_kk, tmp;

    (*day_before) += 28;
    do {
        new_moon_flag =
                calc_new_moon(yrs - DAY_PER_YEAR * (*day_before),&tmp,&sn_kk);
        (*day_before)++;
    } while (new_moon_flag == 0);
    return ((int)sn_kk / 30);
}

/*** 次の朔 ***/
static int
next_new_moon( double yrs, int *day_after )
{
    int     new_moon_flag;
    double  sn_kk, tmp;

    (*day_after) += 28;
    do {
        new_moon_flag =
                calc_new_moon(yrs + DAY_PER_YEAR * (*day_after),&tmp,&sn_kk);
        (*day_after)++;
    } while (new_moon_flag == 0);
    return ((int)sn_kk / 30);
}

/*** 月朔 ***/
static int
calc_new_moon( double yrs, double *mn_kk, double *sn_kk )
{
    int     new_moon_flag;
    double  sn_kk1, mn_kk1;
    double  sn_kk2, mn_kk2;

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
/*      sn_kk2 += 360.0;        */
    }
    *mn_kk = mn_kk1;
    *sn_kk = sn_kk1;
    return (new_moon_flag);
}


/*** 定朔・定気による陰暦計算 ***/
void
getLunarCalendar( int *day, int *month, int *year, int *uruu )
{
    int     day_before;
    int     day_after;
    int     year_up;
    int     lc_month0;
    int     sk_month0;
    int     moon_before;
    int     moon_after;
    int     new_moon_flag;
    int     new_moon_before;
    int     new_moon_after;
    double  yrs;
    double  cel_mn, cel_sn;
    int yyyy = *year, mm = *month, dd = *day;

    yrs = year_sum( *day, *month, *year );
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
    if ((sun_cel_val(yrs) - (double)((long)(yrs) * 360L)) > 360.0)
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

    /* 2033年問題対策 */
    // 参考: http://ja.wikipedia.org/wiki/%E6%97%A7%E6%9A%A62033%E5%B9%B4%E5%95%8F%E9%A1%8C
    if (((yyyy == 2033) && ((mm > 8)                  ||
                            ((mm == 8) && (dd >= 25))   )) ||
        ((yyyy == 2034) && ((mm < 3)                  ||
                            ((mm == 3) && (dd <  20))   ))   ) {
        if (*uruu == 1)
        {
            if (*month == 7) {
                // 閏7月 → 8月
                (*month)++;
                *uruu = 0;
            }
            else if (*month == 1) {
                // 閏1月 → 1月
                *uruu = 0;
            }
        }
        else if ((*month == 8) || (*month == 9)) {
            // 8月 → 9月、9月 → 10月
            (*month)++;
        }
        else if (*month == 1) {
            // 1月 → 12月
            (*year)--;
            (*month)--;
        }

        // 11月と閏11月はそのまま
    }
}


void
checkKyureki( long g, int d, int m, int y, int u, int htmlMode )
{
    int     reset   = 1;
    int     yearEto = ( y +  8 ) % 12;
    int     ks      = ( g + 14 ) % 60;
    char    *p;
	char	*d0 = "  %s";
	char	*d1 = "不成就日";
	char	*d2 = "歳下食";

    tprintf( htmlMode, &reset, d0, rk[(m + d - 2) % 6] );

    if ( ( d == 10 ) || ( d == 25 ) )
        tprintf( htmlMode, &reset, "  長潮" );
    if ( ( d == 11 ) || ( d == 26 ) )
        tprintf( htmlMode, &reset, "  若潮" );
    if ( ( ( d >=  3 ) && ( d <=  6 ) ) ||
         ( ( d >= 12 ) && ( d <= 13 ) ) ||
         ( ( d >= 18 ) && ( d <= 21 ) ) ||
         ( ( d >= 27 ) && ( d <= 28 ) )    )
        tprintf( htmlMode, &reset, "  中潮" );
    if (   ( d <=  2 )                   ||
         ( ( d >= 14 ) && ( d <= 17 ) ) ||
           ( d >= 29 )                      )
        tprintf( htmlMode, &reset, "  大潮" );
    if ( ( ( d >=  7 ) && ( d <=  9 ) ) ||
         ( ( d >= 22 ) && ( d <= 24 ) )    )
        tprintf( htmlMode, &reset, "  小潮" );

    if ( m == 1 ) {
        if ( d == 1 )
            tprintf( htmlMode, &reset, "  旧正月" );
        if ( d == 7 )
            tprintf( htmlMode, &reset, "  旧七草" );
        if ( (d >= 3) && (d <= 9) )
            tprintf( htmlMode, &reset, "  春節(中国)" );
        if ( d == 15 )
            tprintf( htmlMode, &reset, "  元宵節(中国)" );
        if ( d == 20 )
            tprintf( htmlMode, &reset, "  二十日正月" );
    }
    if ( ( m == 2 ) && ( d == 2 ) )
        tprintf( htmlMode, &reset, "  二日灸" );
    if ( ( m == 3 ) && ( d == 3 ) )
        tprintf( htmlMode, &reset, "  旧ひな祭" );
    if ( ( m == 4 ) && ( d == 8 ) )
        tprintf( htmlMode, &reset, "  旧潅仏" );
    if ( m == 5 ) {
        if ( d == 5 ) {
            tprintf( htmlMode, &reset, "  旧端午の節句" );
            tprintf( htmlMode, &reset, "  端午節(中国)" );
        }
        if ( d == 29 )
            tprintf( htmlMode, &reset, "  達努節(中国)" );
    }
    if ( m == 6 ) {
        if ( (d == 24) || (d == 25) )
            tprintf( htmlMode, &reset, "  火把節(中国)" );
    }
    if ( m == 7 ) {
        if ( d == 7 )
            tprintf( htmlMode, &reset, "  旧七夕" );
        if ( d == 15 )
            tprintf( htmlMode, &reset, "  旧盆" );
        if ( d == 24 )
            tprintf( htmlMode, &reset, "  旧地蔵盆" );
    }
    if ( m == 8 ) {
        if ( d == 1 )
            tprintf( htmlMode, &reset, "  旧八朔" );
        if ( d == 14 )
            tprintf( htmlMode, &reset, "  待宵月" );
        if ( d == 15 ) {
            tprintf( htmlMode, &reset, "  十五夜" );
            tprintf( htmlMode, &reset, "  中秋節(中国)" );
        }
        if ( d == 16 )
            tprintf( htmlMode, &reset, "  十六夜" );
        if ( d == 17 )
            tprintf( htmlMode, &reset, "  立待月" );
        if ( d == 18 )
            tprintf( htmlMode, &reset, "  居待月" );
        if ( d == 19 )
            tprintf( htmlMode, &reset, "  臥待月" );
        if ( d == 20 )
            tprintf( htmlMode, &reset, "  更待月" );
    }
    if ( m == 9 ) {
        if ( d == 9 ) {
            tprintf( htmlMode, &reset, "  御九日" );
            tprintf( htmlMode, &reset, "  重陽節(中国)" );
        }
        if ( d == 13 )
            tprintf( htmlMode, &reset, "  十三夜" );
        if ( d == 28 )
            tprintf( htmlMode, &reset, "  孔子祭(中国)" );
    }
    if ( m == 10 ) {
        if ( d <= 12 ) {
            if ( shi( g ) == WII )
                tprintf( htmlMode, &reset, "  炉開き" );
                                    /* 旧暦10月最初の亥の日 */
        }
        if ( d == 5 )
            tprintf( htmlMode, &reset, "  残菊の宴" );
        if ( d == 10 )
            tprintf( htmlMode, &reset, "  十日夜" );
        if ( shi( g ) == WII )
            tprintf( htmlMode, &reset, "  亥の子" );
    }
    if ( ( m == 12 ) && ( d == 8 ) )
        tprintf( htmlMode, &reset, "  臘日" );

    switch ( m ) {
    case  1 : /* 旧 1月 */
    case  7 : /* 旧 7月 */
        if ( (d + 5) % 8 == 0 )	/* 3日,11日,19日,27日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    case  2 : /* 旧 2月 */
    case  8 : /* 旧 8月 */
        if ( (d + 6) % 8 == 0 )	/* 2日,10日,18日,26日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    case  3 : /* 旧 3月 */
    case  9 : /* 旧 9月 */
        if ( (d + 7) % 8 == 0 )	/* 1日,9日,17日,25日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    case  4 : /* 旧 4月 */
    case 10 : /* 旧10月 */
        if ( (d + 4) % 8 == 0 )	/* 4日,12日,20日,28日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    case  5 : /* 旧 5月 */
    case 11 : /* 旧11月 */
        if ( (d + 3) % 8 == 0 )	/* 5日,13日,21日,29日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    case  6 : /* 旧 6月 */
    case 12 : /* 旧12月 */
        if ( (d + 2) % 8 == 0 )	/* 6日,14日,22日,30日 */
            tprintf( htmlMode, &reset, d0, d1 );
        break;
    }

    switch ( yearEto ) {
    case 0:	/* 子の年 */
        if ( ks == 13 )    /* 丁丑 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 1:	/* 丑の年 */
        if ( ks == 26 )    /* 庚寅 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 2:	/* 寅の年 */
        if ( ks ==  3 )    /* 丁卯 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 3:	/* 卯の年 */
        if ( ks == 28 )    /* 壬辰 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 4:	/* 辰の年 */
        if ( ks == 53 )    /* 丁巳 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 5:	/* 巳の年 */
        if ( ks == 42 )    /* 丙午 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 6:	/* 午の年 */
        if ( ks == 43 )    /* 丁未 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 7:	/* 未の年 */
        if ( ks == 56 )    /* 庚申 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 8:	/* 申の年 */
        if ( ks == 33 )    /* 丁酉 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 9:	/* 酉の年 */
        if ( ks == 22 )    /* 丙戌 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 10:	/* 戌の年 */
        if ( ks == 47 )    /* 辛亥 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    case 11:	/* 亥の年 */
        if ( ks == 36 )    /* 庚子 */
            tprintf( htmlMode, &reset, d0, d2 );
        break;
    }

    if ( ( p = kuenichi( g, m ) ) != NULL )
        tprintf( htmlMode, &reset, d0, p );
}


void
getLunarCalendar2( int *day, int *month, int *year, int *uruu )
{
    FILE    *fp;
    int     yy = *year, mm = *month, dd = *day;
    int     _y, _m, _d, offset;
    int     qy1 = 0, qm1 = 0, qd, uruu1 = 0;
    int     qy2, qm2, uruu2;
    char    *p, *q, *r, buf[BUFSIZ];
    long    g = absoluteFromGregorian( *day, *month, *year );
    long    saku1 = 0, saku2 = 0;

    *uruu = 0;
    if ( ( fp = tfopen( "tbl/qdate.csv", "r" ) ) == NULL )
        return;

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
        _y = atol( p );
        if ( yy < _y ) {
            if ( (saku1 != 0) && (mm == 12) ) {
                qd = g - saku1 + 1;
                *day   = qd;
                *month = qm1;
                *year  = qy1;
                *uruu  = uruu1;
            }
            break;
        }
        q  = strchr( p, ',' ) + 1;
        _m = atol( q );
        r  = strchr( q, ',' ) + 1;
        _d = atol( r );
        q  = strchr( r, ',' ) + 1;
        uruu2 = atol( q );
        r  = strchr( q, ',' ) + 1;
        offset = atol( r );
        saku2 = absoluteFromGregorian( _d, _m, _y );
        qy2 = _y - offset;
        q  = strchr( r, ',' ) + 1;
        qm2 = atol( q );
        if ( (saku1 <= g) && (saku2 > g) ) {
            qd = g - saku1 + 1;
            *day   = qd;
            *month = qm1;
            *year  = qy1;
            *uruu  = uruu1;
            break;
        }
        saku1 = saku2;
        qy1   = qy2;
        qm1   = qm2;
        uruu1 = uruu2;
    }

    tfclose( fp );
}


int
getKokei( int day, int month, int year, double *sun_cel1, double *sun_cel2 )
{
    int     kokei;
    double  yrs;

    /*** 太陽 黄経 ***/
    yrs = year_sum(day, month, year);
    *sun_cel1 = sun_cel(yrs);
    *sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
    if (*sun_cel2 < *sun_cel1)
        *sun_cel2 += 360.0;

    while (*sun_cel1 < 0.0) /* {@@} */  /* for 1880.06.10-11 */
        *sun_cel1 += 360.0; /* {@@} */  /* for 1880.06.10-11 */
    while (*sun_cel2 < 0.0) /* {@@} */  /* for 1000.06.12, etc */
        *sun_cel2 += 360.0; /* {@@} */  /* for 1000.06.12, etc */

    kokei = (int)(*sun_cel2) / 1;

    return ( kokei );
}

char	*
zassetsu( int day, int month, int year )
{
    int     kokei;
    double  sun_cel1, sun_cel2;

    /*** 太陽 黄経 ***/
    kokei = getKokei( day, month, year, &sun_cel1, &sun_cel2 );
    if ( kokei % 90 == 27 ) {
        if ( shi( absoluteFromGregorian(day,month,year) ) == USHI ) {
            if ( month == 7 )
                return ( "土用  土用の丑" );
        }

        return ( "土用" );
    }
    if ( kokei % 90 == 45 ) {
        long    jd = absoluteFromGregorian( day, month, year );
        if ( month == 2 ) {
            if ( jd == springStartDay( year ) )
                return ( NULL );
        }
        else if ( month == 5 ) {
            if ( jd == summerStartDay( year ) )
                return ( NULL );
        }
        else if ( month == 8 ) {
            if ( jd == autumnStartDay( year ) )
                return ( NULL );
        }
        else if ( month == 11 ) {
            if ( jd == winterStartDay( year ) )
                return ( NULL );
        }
        else
            return ( NULL );

        return ( "土用" );
    }

    if ( ( kokei >= 27 ) && ( kokei < 45 ) ) {      /* 春の土用 */
        long    jd = absoluteFromGregorian( day, month, year );

        //  巳・午・酉
        if ( ( shi( jd ) == MEE  ) ||
             ( shi( jd ) == UMA  ) ||
             ( shi( jd ) == TORI )    )
            return ( "土用の間日" );

        return ( "土用" );
    }

    if ( ( kokei >= 117 ) && ( kokei < 135 ) ) {    /* 夏の土用 */
        long    jd = absoluteFromGregorian( day, month, year );
        if ( shi( jd ) == USHI ) {
            int     y, m, d;

            gregorianFromAbsolute( jd - 12, &d, &m, &y );
            kokei = getKokei( d, m, y, &sun_cel1, &sun_cel2 );
            if ( ( kokei >= 117 ) && ( kokei < 135 ) ) {
                /* 1つ前の丑の日も土用期間中であれば */
                return ( "土用の二の丑" );
            }

            if ( month == 7 ) {
                kokei = getKokei( day - 3, month, year, &sun_cel1, &sun_cel2 );
                if ( kokei % 90 == 27 )
                    return ( "土用の丑  土用三郎" );
            }
            return ( "土用の丑" );
        }

        if ( month == 7 ) {
            kokei = getKokei( day - 3, month, year, &sun_cel1, &sun_cel2 );
            if ( kokei % 90 == 27 )
                return ( "土用三郎" );
        }

        //  卯・辰・申
        if ( ( shi( jd ) == UU    ) ||
             ( shi( jd ) == TATSU ) ||
             ( shi( jd ) == SARU  )    )
            return ( "土用の間日" );

        return ( "土用" );
    }

    if ( ( kokei >= 207 ) && ( kokei < 225 ) ) {    /* 秋の土用 */
        long    jd = absoluteFromGregorian( day, month, year );

        //  未・酉・亥
        if ( ( shi( jd ) == HITSUJI ) ||
             ( shi( jd ) == TORI    ) ||
             ( shi( jd ) == WII     )    )
            return ( "土用の間日" );

        return ( "土用" );
    }

    if ( ( kokei >= 297 ) && ( kokei < 315 ) ) {    /* 冬の土用 */
        long    jd = absoluteFromGregorian( day, month, year );
        if ( shi( jd ) == USHI ) {
            int     y, m, d;

            gregorianFromAbsolute( jd - 12, &d, &m, &y );
            kokei = getKokei( d, m, y, &sun_cel1, &sun_cel2 );
            if ( ( kokei >= 297 ) && ( kokei < 315 ) ) {
                /* 1つ前の丑の日も土用期間中であれば */
                return ( "寒の土用の二の丑(長野県岡谷市)" );
            }

            return ( "寒の土用の丑(長野県岡谷市)" );
        }

        //  卯・巳・寅
        if ( ( shi( jd ) == UU   ) ||
             ( shi( jd ) == MEE  ) ||
             ( shi( jd ) == TORA )    )
            return ("土用の間日");

        return ( "土用" );
    }

    if ( (kokei == 80) && (sun_cel1 <= 80.0) ) {	/* for 2000.06.10-11 */
        return ( "入梅" );
    }
    if ( kokei == 100 )
        return ( "半夏生" );

    return ( NULL );
}

