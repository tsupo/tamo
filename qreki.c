/*---------------------------------------------------------------------------*\
| Taian_teller :taian.exe version 0.90   [11469bytes]                         |
|     written by ral with Turbo Pascal Ver. 5.0                               |
| Taian_teller :taian.exe version 0.90e1 [24142bytes]                         |
|     modified by ethyl with MS-C Ver. 5.10A                                  |
\*---------------------------------------------------------------------------*/

/*
 *	���o�l����	listings.byte
 *
 *	���o BYTE / January 1988 Hobby
 *		����C���ł��ꔭ�ł킩��Z�j�v���O���� p.239-243
 *		��؁@��
 *
 *		���z�ƌ��̉��o�𗘗p����
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
 *		���̃\�[�X�v���O������ ral���� Taian_teller (Turbo Pascal��)
 *		�� ethyl���� MS-C �ɈڐA�������̂���K�v�Ȋ֐������o���A��
 *		���������̂ł��B����A���o�A�ߋC�̌v�Z�͂����܂ł��ߎ��ł���
 *		�Ŏ��ۂƐH���Ⴂ�������邱�Ƃ�����܂��B
 *
 *                                                       3 December 1995
 *              ����ɁA�X���j���� today.exe �̃\�[�X�̈ꕔ(inreki.c) ���Q�l
 *              �Ɂu���v�̎Z�o������ǉ����܂����B
 *
 * History :
 * $Log: qreki.c $
 * Revision 1.67  2003/03/31  05:21:49  tsujimura543
 * �w�b�_�t�@�C���̈ˑ��֌W�𐮗�
 *
 * Revision 1.66  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.65  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.64  2003/03/11  02:04:01  tsujimura543
 * for Tsuporone's Activity memo
 *
 * Revision 1.63  2003/03/03  07:48:04  tsujimura543
 * �s���A���ɑΉ�
 *
 * Revision 1.62  2002/12/20  07:51:57  tsujimura543
 * �c���̕\����ǉ�
 *
 * Revision 1.61  2001/02/21  14:16:36  tsujimura543
 * HTML���[�h�Ή��ς݂� revision �Ɠ���
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.53  2001/01/22  08:44:28  tsujimura543
 * �����ŋ߂̔N��24�ߋC�֘A�̓��t����������(2001�N�̐ߕ���2��1���ƕ\������
 * ��A�Ȃ�)�s��ɑΏ�
 * 
 * Revision 1.52  2000/08/23  11:03:57  tsujimura543
 * 2000�N�̓��~�̓��t�����������s��ɑΏ�
 * 
 * Revision 1.51  1999/07/06  18:49:09  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ�
 *
 * Revision 1.50  1996/08/19  02:10:16  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.7  95/12/03 11:43:58  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.6  95/12/02 19:07:00  tsujimura
 * ���̕\����ǉ�
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
|        ����Z�o���[�`��                                                     |
\*---------------------------------------------------------------------------*/

static char *sk[] = {"�t��", "����", "���J", "����", "����", "䊎�",
                     "�Ď�", "����", "�友", "���H", "����", "���I",
                     "�H��", "���I", "���~", "���~", "����", "���",
                     "�~��", "����", "�劦", "���t", "�J��", "�[�"};
static char *rk[] = {"�揟", "�F��", "�敉", "����", "���", "�Ԍ�"};


static double	sun_cel_value;
static double	years;

struct	CONST_TBL {				/* constant table	  */
	double	ef;	/* �U��     */		/* amplitude of vibration */
	double	ph;	/* �����ʑ� */		/* initial phase	  */
	double	sc;	/* �p���x   */		/* angular velocity	  */
};

#define	MOON_N	13	/* �� ���o �ۓ����̐� */

static	struct	CONST_TBL	mn[14] = {	/* �� ���o */	/* 21 */
    /*  �U���@ �����ʑ��@�@   �p���x  */
    { 0.0000 , 124.8754 ,  4812.67881 }, /* �����l  ���ϊp���x */
    { 6.2887 , 338.915  ,   4771.9886 }, /* ���S��(�@�ߓ_��: 27.55455��) */
    { 1.2740 , 107.248  ,  -4133.3536 }, /*  �o ��(�@�@�@�@: 31.81194��) */
    { 0.6583 ,  51.668  ,   8905.3422 }, /* ��ύ�(����]��: 14.76529��) */
    { 0.2136 , 317.831  ,   9543.9773 }, /* �@�@�@(���ߓ_��: 13.77728��) */
    { 0.1856 , 176.531  ,    359.9905 }, /*  �N ��(�@�ߓ_�N:365.25964��) */
    { 0.1143 , 292.463  ,   9664.0404 },
    { 0.0588 ,  86.160  ,    638.6350 },
    { 0.0572 , 103.780  ,  -3773.3630 },
    { 0.0533 ,  30.580  ,  13677.3310 },
    { 0.0459 , 124.860  ,  -8545.3520 },
    { 0.0410 , 342.380  ,   4411.9980 },
    { 0.0348 ,  25.830  ,   4452.6710 }, /* ���p��(�@��]��: 29.53059��) */
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
#define	MOON_M	4	/* �� ���� �ۓ����̐� */

static	struct	CONST_TBL	mn2[5] = {	/* �� ���� */	/* 10 */
   /*  �U���@ �����ʑ��@�@   �p���x */
    { 0.0000 ,   0.000 ,      0.0000 },	/* �����l ?? */
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

#define	SUN_N	10	/* ���z ���o �ۓ����̐� */
#define	SUN_EF1	0.00005

static	struct	CONST_TBL	sn[11] = {	/* ���z ���o */	/* 16 */
    /*  �U���@ �����ʑ��@�@   �p���x   */
    { 0.0000 , 279.0358 ,    360.00769 }, /* �����l  ���ϊp���x		     */
    { 1.9159 , 356.531  ,    359.9910  }, /*       (�@�ߓ_�N:365.25964��) */
    { 0.0200 , 353.060  ,    719.9810  }, /*       (���ߓ_�N:182.62982��) */
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


/*�@�����E�X���I�����߂�  */
double
julcen(ld)
long ld;	/* �����E�X�� */
{
	return((ld - 15019.5) / 36525);
}

/*  �����E�X���I �� ���̗��p �� ����@*/
int
geturei(ld)
long ld;	/* �����E�X�� */
{
	long l;	/* �����_�ȉ��؎̂ėp�̃e���|���� */
	double a, b, rikaku;

	a = julcen(ld);
	b = 350.434164 + 444960.0 * a + 307.114217 * a +
	    1.436 * a * a * 10E-03;
	l = (long)(b / 360.0);
	rikaku = b - (double)l * 360.0;
	return( (int)(29.4 * rikaku / 360.0) );
}


/*** ��N(1975�N1��1��)����̔N�� ***/
static
double	year_sum( d, m, y )
int	d, m, y;
{
	int	tmp;

	tmp = absoluteFromGregorian(d,m,y)-720988L;

	return (((double)tmp + (-9.0 / 24.0)) / 365.25);
}


/*** �� ���o ***/
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


/*** ���z ���o ***/
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

#define	NEE     0   /* �q */
#define	USHI    1   /* �N */
#define	TORA    2   /* �� */
#define	UU      3   /* �K */
#define	TATSU   4   /* �C */
#define	MEE     5   /* �� */
#define	UMA     6   /* �� */
#define	HITSUJI 7   /* �� */
#define	SARU    8   /* �\ */
#define	TORI    9   /* �� */
#define	IMU     10  /* �� */
#define	WII     11  /* �� */

#define	shi(g)			( ( (g) + 2 ) %  12 )

/*** ��\�l�ߋC ***/
char	*
getSekkiName( day, month, year, sekki_no, kokei )
int	day, month, year, *sekki_no, *kokei;
{
	int     sekki, sekki1, sekki2;
	double  sun_cel1, sun_cel2, yrs;

	/*** ���z ���o ***/
	years = yrs = year_sum(day, month, year);
	sun_cel1 = sun_cel(yrs);
	sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
	if (sun_cel2 < sun_cel1)
		sun_cel2 += 360.0;

	/*** ��\�l�ߋC ***/
	sekki  = -1;
	sekki1 = (int)sun_cel1 / 15;
	sekki2 = (int)sun_cel2 / 15;

	*sekki_no = -1;
	*kokei = (int)sun_cel2 / 1;
	if ( *kokei % 90 == 27 )
		return( "�y�p" );
	if ( ( *kokei >= 117 ) && ( *kokei < 135 ) )
		if ( shi( absoluteFromGregorian(day,month,year) ) == USHI )
			return ( "�y�p�̉N" );
	if ( (*kokei == 80) && (sun_cel1 <= 80.0) ) {	/* for 2000.06.10-11 */
		return( "���~" );
	}
	if ( *kokei == 100 )
		return( "���Đ�" );

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

	tmp = d - 720987L;	/* 1975�N 1�� 1������̒ʓ� */
	do {
		/*** ���z ���o ***/
		yrs = ((double)tmp + (-9.0 / 24.0)) / 365.25;
		tmp++; d++;
		sun_cel1 = sun_cel(yrs);
		sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
		if (sun_cel2 < sun_cel1)
			sun_cel2 += 360.0;

		/*** ��\�l�ߋC ***/
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

	tmp = d - 720987.0;	/* 1975�N 1�� 1������̒ʓ� */

	do {
		/*** ���z ���o ***/
		yrs = (tmp + (-9.0 / 24.0)) / 365.25;
		tmp += 1.0;
		d++;
		sun_cel1 = sun_cel(yrs);
		sun_cel2 = sun_cel(yrs + DAY_PER_YEAR);
		if (sun_cel2 < sun_cel1)
			sun_cel2 += 360.0;

		/*** ��\�l�ߋC ***/
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
 *	���t�̓������߂�
 */
long
springStartDay( y )
int	y;
{
	return ( getSekkiDate( 2, 2, y ) );
}

/*
 *	�t���̓������߂�
 */
long
midSpringDay( y )
int	y;
{
	return ( getSekkiDate( 19, 3, y ) );
}

/*
 *	�Ď��̓������߂�
 */
long
midSummerDay( y )
int	y;
{
	return ( getSekkiDate( 20, 6, y ) );
}

/*
 *	���H�̓������߂�
 */
long
autumnStartDay( y )
int	y;
{
	return ( getSekkiDate( 6, 8, y ) );
}

/*
 *	�H���̓������߂�
 */
long
midAutumnDay( y )
int	y;
{
	return ( getSekkiDate( 22, 9, y ) );
}

/*
 *	�ߓ���̓������߂�
 */
long
setsuStartDay( mm, yy )
int	mm, yy;
{
	static int	day[] = {
		2,	/* ������  (���t) */
		5,	/* �񌎐�  (�[�) */
		4,	/* �O����  (����) */
		5,	/* �l����  (����) */
		5,	/* �܌���  (䊎�) */
		6,	/* �Z����  (����) */
		6,	/* ������  (���H) */
		7,	/* ������  (���I) */
		8,	/* �㌎��  (���I) */
		7,	/* �\����  (���~) */
		6,	/* �\�ꌎ��(���) */
		5	/* �\�񌎐�(����) */
	};
	return ( getSekkiDate( day[(mm-1)%12], mm, yy ) );
}

/*** �O�̍� ***/
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

/*** ���̍� ***/
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

/*** ���� ***/
static
int	calc_new_moon(yrs, mn_kk, sn_kk)
double	yrs;
double	*mn_kk, *sn_kk;
{
	int	new_moon_flag;
	double	sn_kk1, mn_kk1;
	double	sn_kk2, mn_kk2;

	/*** ���o ***/
	mn_kk1 = moon_cel(yrs);
	sn_kk1 = sun_cel(yrs);
	mn_kk2 = moon_cel(yrs + DAY_PER_YEAR);
	sn_kk2 = sun_cel(yrs + DAY_PER_YEAR);
	if (mn_kk2 < mn_kk1)
		mn_kk2 += 360.0;
	if (sn_kk2 < sn_kk1)
		sn_kk2 += 360.0;

	/*** �� ***/
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


/*** ���E��C�ɂ��A��v�Z ***/
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

	/*** �����̍� ***/
	new_moon_flag = calc_new_moon(yrs, &cel_mn, &cel_sn);
	new_moon_before = (int)cel_sn / 30;
	if (cel_mn < cel_sn)
		cel_mn += 360.0;
	if (new_moon_flag == 0) {
		day_before = (int)(cel_mn - cel_sn) / 13 - 28;
		new_moon_before = back_new_moon(yrs, &day_before);
	}
	*day = day_before;				/* ���A�� �� */
	lc_month0 = new_moon_before + 2;

	/*** �����̍� ***/
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

	/*** �O�̂Q���Q�� ***/
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

	/*** ���̂Q���Q�� ***/
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
        printf( "  ����" );
    if ( ( d == 11 ) || ( d == 26 ) )
        printf( "  �ᒪ" );
    if ( ( ( d >=  3 ) && ( d <=  6 ) ) ||
         ( ( d >= 12 ) && ( d <= 13 ) ) ||
         ( ( d >= 18 ) && ( d <= 21 ) ) ||
         ( ( d >= 27 ) && ( d <= 28 ) )    )
        printf( "  ����" );
    if (   ( d <=  2 )                   ||
         ( ( d >= 14 ) && ( d <= 17 ) ) ||
           ( d >= 29 )                      )
        printf( "  �咪" );
    if ( ( ( d >=  7 ) && ( d <=  9 ) ) ||
         ( ( d >= 22 ) && ( d <= 24 ) )    )
        printf( "  ����" );

    if ( ( m == 1 ) && ( d == 1 ) )
        printf( "  ������" );
    if ( ( m == 8 ) && ( d == 15 ) )
        printf( "  �\�ܖ�" );
    if ( ( m == 9 ) && ( d == 13 ) )
        printf( "  �\�O��" );

    if ( ( m == 12 ) && ( d == 8 ) )
        printf( "  �c��" );

    switch ( m ) {
    case  1 : /* �� 1�� */
    case  7 : /* �� 7�� */
        if ( (d + 5) % 8 == 0 )	/* 3��,11��,19��,27�� */
            printf( "  �s���A��" );
        break;
    case  2 : /* �� 2�� */
    case  8 : /* �� 8�� */
        if ( (d + 6) % 8 == 0 )	/* 2��,10��,18��,26�� */
            printf( "  �s���A��" );
        break;
    case  3 : /* �� 3�� */
    case  9 : /* �� 9�� */
        if ( (d + 7) % 8 == 0 )	/* 1��,9��,17��,25�� */
            printf( "  �s���A��" );
        break;
    case  4 : /* �� 4�� */
    case 10 : /* ��10�� */
        if ( (d + 4) % 8 == 0 )	/* 4��,12��,20��,28�� */
            printf( "  �s���A��" );
        break;
    case  5 : /* �� 5�� */
    case 11 : /* ��11�� */
        if ( (d + 3) % 8 == 0 )	/* 5��,13��,21��,29�� */
            printf( "  �s���A��" );
        break;
    case  6 : /* �� 6�� */
    case 12 : /* ��12�� */
        if ( (d + 2) % 8 == 0 )	/* 6��,14��,22��,30�� */
            printf( "  �s���A��" );
        break;
    }
}
