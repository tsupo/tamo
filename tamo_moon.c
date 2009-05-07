/*
 *  moon.c
 *      arrenged by H.Tsujimura     1989,1990,1991,1995,1998,1999,2000,
 *                                  2001,2002,2003
 *      Last updated:   20th December 2002
 *
 *      This program is for computing the phase of the moon.
 *
 * History :
 * $Log: tamo_moon.c $
 * Revision 1.78  2007/02/14  09:10:47  tsujimura543
 * 環境変数 TZ が未設定の場合にも対応
 *
 * Revision 1.77  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.76  2003/10/30  08:13:54  tsujimura543
 * Another HTML-lint で評価が100点になるように修正
 *
 * Revision 1.75  2003/05/26  07:47:50  tsujimura543
 * インド国民暦(国家暦)対応、ネパール太陰暦修正
 *
 * Revision 1.74  2003/04/25  11:15:29  tsujimura543
 * HTMLモード時の表示を若干変更
 *
 * Revision 1.73  2003/03/17  05:13:25  tsujimura543
 * HTML出力内容を整理
 *
 * Revision 1.72  2003/03/12  10:05:31  tsujimura543
 * 活動メモ対応準備 #2
 *
 * Revision 1.71  2003/03/11  12:11:43  tsujimura543
 * 月齢計算の範囲を1年～9999年まで対応した(精度はともかくとして)
 *
 * Revision 1.70  2003/03/11  02:04:49  tsujimura543
 * for Tsuporone's Activity memo
 *
 * Revision 1.69  2003/03/03  12:09:08  tsujimura543
 * バグ修正 (参照している変数が間違っていた)
 *
 * Revision 1.68  2003/03/03  12:07:41  tsujimura543
 * CGI にパラメータを渡せるようにした
 *
 * Revision 1.67  2003/02/24  09:25:42  tsujimura543
 * 実行形式の拡張子が .cgi の場合、Content-type: 行を出力するようにした
 *
 * Revision 1.66  2003/02/07  08:08:35  tsujimura543
 * 起動時オプションとして -H, -v を正式サポート
 *
 * Revision 1.65  2002/12/20  07:49:27  tsujimura543
 * 輝度の表示を追加
 *
 * Revision 1.64  2002/12/20  06:43:32  tsujimura543
 * 朔～次の朔 の表示が 1 lunation 前のものを表示してしまうことが
 * ある不具合に対処
 *
 * Revision 1.63  2001/04/17  13:43:38  tsujimura543
 * jdate() と jtime() の引数を変更 (2038年問題から解放)
 *
 * Revision 1.62  2001/02/22  13:31:23  tsujimura543
 * 1970年1月1日以前、2038年1月19日以降の日時を指定するとmktime()で例外が発生
 * する現象に対処
 *
 * Revision 1.61  2001/02/22  12:47:08  tsujimura543
 * moon2.c を moon.c に統合。さらに、Web アプリケーションとして実運用してい
 * た版と統合。
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.54  2001/01/17  18:09:23  tsujimura543
 * lunation の変わり目の直前になると月齢が負の値になってしまうことがある不具
 * 合に対処
 * 
 * Revision 1.53  2000/10/18  15:43:28  tsujimura543
 * 月齢を表示したい年月日をコマンドラインで指定できるようにする
 * 
 * Revision 1.52  1999/12/20  15:39:04  tsujimura543
 * 実際の月齢より 約1.5 くらい大きな値になってしまう不具合に対処
 * 
 * Revision 1.51  1999/03/29  15:53:10  tsujimura543
 * moon.c の次期実験バージョン (moon2.c)
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう
 *
 * Revision 1.1  1996/08/19  12:01:10  tsujimura
 * Initial revision
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 * 
 */

/*

    A Moon for the Sun

    Release 2.0

    Designed and implemented by John Walker in December 1987,
    revised and updated in February of 1988.

    Make with:

    cc -O moontool.c -o moontool -lm -lsuntool -lsunwindow -lpixrect

    Adding  appropriate  floating  point  options  to your hardware.  This
    program is a SunView tool which displays, as the  icon  for  a  closed
    window,  the  current phase of the Moon.  A subtitle in the icon gives
    the age of the Moon in days  and  hours.   If  called  with  the  "-t"
    switch,  it  rapidly  increments  forward  through time to display the
    cycle of phases.

    If you open the window, additional information is displayed  regarding
    the  Moon.   The  information  is  generally  accurate  to  within ten
    minutes.

    The algorithms used in this program to calculate the positions Sun and
    Moon as seen from the Earth are given in the book "Practical Astronomy
    With  Your  Calculator"  by  Peter  Duffett-Smith,   Second   Edition,
    Cambridge University Press, 1981.  Ignore the word "Calculator" in the
    title;  this  is  an  essential  reference  if  you're  interested  in
    developing  software  which  calculates  planetary  positions, orbits,
    eclipses, and  the  like.   If  you're  interested  in  pursuing  such
    programming, you should also obtain:

    "Astronomical  Formulae for Calculators" by Jean Meeus, Third Edition,
    Willmann-Bell, 1985.  A must-have.

    "Planetary  Programs  and  Tables  from  -4000  to  +2800"  by  Pierre
    Bretagnon  and Jean-Louis Simon, Willmann-Bell, 1986.  If you want the
    utmost  (outside  of  JPL)  accuracy  for  the  planets,  it's   here.

    "Celestial BASIC" by Eric Burgess, Revised Edition, Sybex, 1985.  Very
    cookbook oriented, and many of the algorithms are hard to dig  out  of
    the turgid BASIC code, but you'll probably want it anyway.

    Many of these references can be obtained from Willmann-Bell, P.O.  Box
    35025,  Richmond,  VA 23235, USA.  Phone: (804) 320-7016.  In addition
    to their own publications, they stock most of the standard  references
    for mathematical and positional astronomy.

    This program was written by:

       John Walker
       Autodesk, Inc.
       2320 Marinship Way
       Sausalito, CA  94965
       (415) 332-2344 Ext. 829

       Usenet: {sun!well}!acad!kelvin

    This  program is in the public domain: "Do what thou wilt shall be the
    whole of the law".  I'd appreciate  receiving  any  bug  fixes  and/or
    enhancements,  which  I'll  incorporate  in  future  versions  of  the
    program.  Please leave the original attribution information intact  so
    that credit and blame may be properly apportioned.

*/

/*  Astronomical constants  */

#define epoch       2444238.5      /* 1980 January 0.0 */

/*  Constants defining the Sun's apparent orbit  */

#define elonge      278.833540     /* Ecliptic longitude of the Sun
                                      at epoch 1980.0 */
#define elongp      282.596403     /* Ecliptic longitude of the Sun at
                                      perigee */
#define eccent      0.016718       /* Eccentricity of Earth's orbit */
#define sunsmax     1.495985e8     /* Semi-major axis of Earth's orbit, km */
#define sunangsiz   0.533128       /* Sun's angular size, degrees, at
                                      semi-major axis distance */

/*  Elements of the Moon's orbit, epoch 1980.0  */

#define mmlong      64.975464      /* Moon's mean lonigitude at the epoch */
#define mmlongp     349.383063     /* Mean longitude of the perigee at the
                                      epoch */
#define mlnode      151.950429     /* Mean longitude of the node at the
                                      epoch */
#define minc        5.145396       /* Inclination of the Moon's orbit */
#define mecc        0.054900       /* Eccentricity of the Moon's orbit */
#define mangsiz     0.5181         /* Moon's angular size at distance a
                                      from Earth */
#define msmax       384401.0       /* Semi-major axis of Moon's orbit in km */
#define mparallax   0.9507         /* Parallax at distance a from Earth */
#define synmonth    29.53058868    /* Synodic month (new Moon to new Moon) */
#define lunatbase   2423436.0      /* Base date for E. W. Brown's numbered
                                      series of lunations (1923 January 16) */

/*  Properties of the Earth  */

#define earthrad    6378.16        /* Radius of Earth in kilometres */

#ifdef	WIN32
# include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "tamo.h"

#ifdef  M_PI
# define PI  M_PI
#else
# define PI 3.14159265358979323846  /* Assume not near black hole nor in
                                       Tennessee */
#endif

/*  Handy mathematical functions  */

#define sgn(x) (((x) < 0) ? -1 : ((x) > 0 ? 1 : 0))       /* Extract sign */
#define abs(x) ((x) < 0 ? (-(x)) : (x))                   /* Absolute val */
#define fixangle(a) ((a) - 360.0 * (floor((a) / 360.0)))  /* Fix angle    */
#define torad(d) ((d) * (PI / 180.0))                     /* Deg->Rad     */
#define todeg(d) ((d) * (180.0 / PI))                     /* Rad->Deg     */
#define dsin(x) (sin(torad((x))))                         /* Sin from deg */
#define dcos(x) (cos(torad((x))))                         /* Cos from deg */

#ifndef WIN32
# ifndef    TRUE
#  define   TRUE    1
#  define   FALSE   (!TRUE)
# endif
#endif

#if	0
static int testmode = FALSE;       /* Rapid warp through time for debugging */
#endif

/*  Forward functions  */

static double   jtime( long, long, long, long, long, long  );
static double   phase( double, double *, double *, double *,
                       double *, double *, double * );
static void     phasehunt( double, double * );
static void     jyear( double, long *, long *, long* );
static void     jhms( double, long *, long *, long* );

/*  JDATE  --  Convert internal GMT date and time to Julian day
               and fraction.  */

static long
jdate( long yy, long mm, long dd )
{
    long    c, m, y;

    y = yy;
    m = mm;
    if (m > 2)
        m = m - 3;
    else {
        m = m + 9;
        y--;
    }
    c = y / 100L;              /* Compute century */
    y -= 100L * c;
    return dd + (c * 146097L) / 4 + (y * 1461L) / 4 +
               (m * 153L + 2) / 5 + 1721119L;
}

/* JTIME --    Convert internal GMT date and time to astronomical Julian
               time (i.e. Julian date plus day fraction, expressed as
               a double).  */

static double
jtime( long yy, long mm, long dd, long HH, long MM, long SS )
{
    return (jdate(yy, mm, dd) - 0.5) + 
               (SS + 60 * (MM + 60 * HH)) / 86400.0;
}

/*  JYEAR  --  Convert Julian date to year, month, day, which are
               returned via integer pointers to integers.  */

static void
jyear( double td, long *yy, long *mm, long *dd )
{
    double  j, d, y, m;

    td += 0.5;                 /* Astronomical to civil */
    j = floor(td);
    j = j - 1721119.0;
    y = floor(((4 * j) - 1) / 146097.0);
    j = (j * 4.0) - (1.0 + (146097.0 * y));
    d = floor(j / 4.0);
    j = floor(((4.0 * d) + 3.0) / 1461.0);
    d = ((4.0 * d) + 3.0) - (1461.0 * j);
    d = floor((d + 4.0) / 4.0);
    m = floor(((5.0 * d) - 3) / 153.0);
    d = (5.0 * d) - (3.0 + (153.0 * m));
    d = floor((d + 5.0) / 5.0);
    y = (100.0 * y) + j;
    if (m < 10.0)
        m = m + 3;
    else {
        m = m - 9;
        y = y + 1;
    }
    *yy = (long)y;
    *mm = (long)m;
    *dd = (long)d;
}

/*  JHMS  --  Convert Julian time to hour, minutes, and seconds.  */

static void
jhms( double j, long *h, long *m, long *s )
{
    long    ij;

    j += 0.5;                  /* Astronomical to civil */
    ij = (long)((j - floor(j)) * 86400.0);
    *h = ij / 3600L;
    *m = (ij / 60L) % 60L;
    *s = ij % 60L;
}

/*  MEANPHASE  --  Calculates mean phase of the Moon for a given
                   base date and desired phase:
                       0.0   New Moon
                       0.25  First quarter
                       0.5   Full moon
                       0.75  Last quarter
                    Beware!!!  This routine returns meaningless
                    results for any other phase arguments.  Don't
                    attempt to generalise it without understanding
                    that the motion of the moon is far more complicated
                    that this calculation reveals. */

static double
meanphase( double sdate, double phase, double *usek, int *cnt )
{
    long            yy, mm, dd;
    double          k, t, t2, t3, nt1;
    double          preK;
    static double   preNt1 = 0.0;

    jyear(sdate, &yy, &mm, &dd);

    preK = k = (yy + ((mm - 1L) * (1.0 / 12.0)) - 1900.0) * 12.3685;

    /* Time in Julian centuries from 1900 January 0.5 */
    t  = (sdate - 2415020.0) / 36525.64;
    t2 = t * t;                /* Square for frequent use */
    t3 = t2 * t;               /* Cube for frequent use */

    *usek = k = floor(k) + phase;
    nt1 = 2415020.75933 + synmonth * k
              + 0.0001178 * t2
              - 0.000000155 * t3
              + 0.00033 * dsin(166.56 + 132.87 * t - 0.009173 * t2);

    if ( *cnt >= 1 ) {
        /* printf( "nt1 = %f, preNt1 = %f\n", nt1, preNt1 ); */
        if ( nt1 - preNt1 > 45.0 ) {
            *usek = k = floor(preK) - 1.0;
            nt1 = 2415020.75933 + synmonth * k
                      + 0.0001178 * t2
                      - 0.000000155 * t3
                      + 0.00033 * dsin(166.56 + 132.87 * t - 0.009173 * t2);
        }
    }
    (*cnt)++;
    preNt1 = nt1;

    return nt1;
}

/*  TRUEPHASE  --  Given a K value used to determine the
                   mean phase of the new moon, and a phase
                   selector (0.0, 0.25, 0.5, 0.75), obtain
                   the true, corrected phase time.  */

static double
truephase( double k, double phase )
{
    double  t, t2, t3, pt, m, mprime, f;
    int     apcor = FALSE;

    k += phase;                /* Add phase to new moon time */
    t = k / 1236.85;           /* Time in Julian centuries from
                                  1900 January 0.5 */
    t2 = t * t;                /* Square for frequent use */
    t3 = t2 * t;               /* Cube for frequent use */
    pt = 2415020.75933         /* Mean time of phase */
             + synmonth * k
             + 0.0001178 * t2
             - 0.000000155 * t3
             + 0.00033 * dsin(166.56 + 132.87 * t - 0.009173 * t2);

    m = 359.2242               /* Sun's mean anomaly */
            + 29.10535608 * k
            - 0.0000333 * t2
            - 0.00000347 * t3;
    mprime = 306.0253          /* Moon's mean anomaly */
                 + 385.81691806 * k
                 + 0.0107306 * t2
                 + 0.00001236 * t3;
    f = 21.2964                /* Moon's argument of latitude */
            + 390.67050646 * k
            - 0.0016528 * t2
            - 0.00000239 * t3;
    if ((phase < 0.01) || (abs(phase - 0.5) < 0.01)) {
        /* Corrections for New and Full Moon */
        pt += (0.1734 - 0.000393 * t) * dsin(m)
                  + 0.0021 * dsin(2 * m)
                  - 0.4068 * dsin(mprime)
                  + 0.0161 * dsin(2 * mprime)
                  - 0.0004 * dsin(3 * mprime)
                  + 0.0104 * dsin(2 * f)
                  - 0.0051 * dsin(m + mprime)
                  - 0.0074 * dsin(m - mprime)
                  + 0.0004 * dsin(2 * f + m)
                  - 0.0004 * dsin(2 * f - m)
                  - 0.0006 * dsin(2 * f + mprime)
                  + 0.0010 * dsin(2 * f - mprime)
                  + 0.0005 * dsin(m + 2 * mprime);
        apcor = TRUE;
    }
    else if ((abs(phase - 0.25) < 0.01 || (abs(phase - 0.75) < 0.01))) {
        pt += (0.1721 - 0.0004 * t) * dsin(m)
                  + 0.0021 * dsin(2 * m)
                  - 0.6280 * dsin(mprime)
                  + 0.0089 * dsin(2 * mprime)
                  - 0.0004 * dsin(3 * mprime)
                  + 0.0079 * dsin(2 * f)
                  - 0.0119 * dsin(m + mprime)
                  - 0.0047 * dsin(m - mprime)
                  + 0.0003 * dsin(2 * f + m)
                  - 0.0004 * dsin(2 * f - m)
                  - 0.0006 * dsin(2 * f + mprime)
                  + 0.0021 * dsin(2 * f - mprime)
                  + 0.0003 * dsin(m + 2 * mprime)
                  + 0.0004 * dsin(m - 2 * mprime)
                  - 0.0003 * dsin(2 * m + mprime);
        if (phase < 0.5)
            /* First quarter correction */
            pt += 0.0028 - 0.0004 * dcos(m) + 0.0003 * dcos(mprime);
        else
            /* Last quarter correction */
            pt += -0.0028 + 0.0004 * dcos(m) - 0.0003 * dcos(mprime);
        apcor = TRUE;
    }
    if (!apcor) {
        fprintf(stderr, "TRUEPHASE called with invalid phase selector.\n");
        abort();
    }
    return pt;
}

/*  PHASEHUNT  --  Find time of phases of the moon which surround
                   the current date.  Five phases are found, starting
                   and ending with the new moons which bound the
                   current lunation.  */

static void
phasehunt( double sdate, double phases[5] )
{
    double  adate, k1, k2, nt1, nt2;
    int     cnt = 0;

    adate = sdate - 45.0;
    nt1   = meanphase(adate, 0.0, &k1, &cnt);
    while (TRUE) {
        adate += synmonth;
        nt2 = meanphase(adate, 0.0, &k2, &cnt);
        if ((nt1 <= sdate) && (nt2 > sdate))
            break;
        nt1 = nt2;
        k1  = k2;
    }

    if (k2 - k1 >= 2.0)
        k2 = k1 + 1.0;

    phases[0] = truephase(k1, 0.0);
    phases[1] = truephase(k1, 0.25);
    phases[2] = truephase(k1, 0.5);
    phases[3] = truephase(k1, 0.75);
    phases[4] = truephase(k2, 0.0);
}

/*  KEPLER  --  Solve the equation of Kepler.  */

static double
kepler( double m, double ecc )
{
    double  e, delta;
#define EPSILON 1E-6

    e = m = torad(m);
    do {
        delta = e - ecc * sin(e) - m;
        e -= delta / (1 - ecc * cos(e));
    } while (abs(delta) > EPSILON);
    return e;
}

/*  PHASE  --  Calculate phase of moon as a fraction:

        The argument is the time for which the phase is requested,
        expressed as a Julian date and fraction.  Returns the terminator
        phase angle as a percentage of a full circle (i.e., 0 to 1),
        and stores into pointer arguments the illuminated fraction of
        the Moon's disc, the Moon's age in days and fraction, the
        distance of the Moon from the centre of the Earth, and the
        angular diameter subtended by the Moon as seen by an observer
        at the centre of the Earth.

*/

static double
phase( double pdate,
       double *pphase,      /* Illuminated fraction        */
       double *mage,        /* Age of moon in days         */
       double *dist,        /* Distance in kilometres      */
       double *angdia,      /* Angular diameter in degrees */
       double *sudist,      /* Distance to Sun             */
       double *suangdia )   /* Sun's angular diameter      */
{
    double  Day, N, M, Ec, Lambdasun, ml, MM, MN, Ev, Ae, A3, MmP,
            mEc, A4, lP, V, lPP, NP, y, x, Lambdamoon,
            MoonAge, MoonPhase,
            MoonDist, MoonDFrac, MoonAng,
            F, SunDist, SunAng;

    /* Calculation of the Sun's position */

    Day = pdate - epoch;                    /* Date within epoch */
    N = fixangle((360.0 / 365.2422) * Day); /* Mean anomaly of the Sun */
    M = fixangle(N + elonge - elongp);      /* Convert from perigee
                                               co-ordinates to epoch 1980.0 */
    Ec = kepler(M, eccent);                 /* Solve equation of Kepler */
    Ec = sqrt((1.0 + eccent) / (1.0 - eccent)) * tan(Ec / 2.0);
    Ec = 2.0 * todeg(atan(Ec));             /* True anomaly */
    Lambdasun = fixangle(Ec + elongp);      /* Sun's geocentric ecliptic
                                               longitude */
    /* Orbital distance factor */
    F = ((1.0 + eccent * cos(torad(Ec))) / (1.0 - eccent * eccent));
    SunDist = sunsmax / F;              /* Distance to Sun in km */
    SunAng = F * sunangsiz;             /* Sun's angular size in degrees */

    /* Calculation of the Moon's position */
    /* Moon's mean longitude */
    ml = fixangle(13.1763966 * Day + mmlong);

    /* Moon's mean anomaly */
    MM = fixangle(ml - 0.1114041 * Day - mmlongp);

    /* Moon's ascending node mean longitude */
    MN = fixangle(mlnode - 0.0529539 * Day);

    /* Evection */
    Ev = 1.2739 * sin(torad(2.0 * (ml - Lambdasun) - MM));

    /* Annual equation */
    Ae = 0.1858 * sin(torad(M));

    /* Correction term */
    A3 = 0.37 * sin(torad(M));

    /* Corrected anomaly */
    MmP = MM + Ev - Ae - A3;

    /* Correction for the equation of the centre */
    mEc = 6.2886 * sin(torad(MmP));

    /* Another correction term */
    A4 = 0.214 * sin(torad(2.0 * MmP));

    /* Corrected longitude */
    lP = ml + Ev + mEc - Ae + A4;

    /* Variation */
    V = 0.6583 * sin(torad(2.0 * (lP - Lambdasun)));

    /* True longitude */
    lPP = lP + V;

    /* Corrected longitude of the node */
    NP = MN - 0.16 * sin(torad(M));

    /* Y inclination coordinate */
    y = sin(torad(lPP - NP)) * cos(torad(minc));

    /* X inclination coordinate */
    x = cos(torad(lPP - NP));

    /* Ecliptic longitude */
    Lambdamoon = todeg(atan2(y, x));
    Lambdamoon += NP;

#if 0
    /* Ecliptic latitude */
    (void)todeg(asin(sin(torad(lPP - NP)) * sin(torad(minc))));
#endif

    /* Calculation of the phase of the Moon */
    /* Age of the Moon in degrees */
    MoonAge = lPP - Lambdasun;

    /* Phase of the Moon */
    MoonPhase = (1.0 - cos(torad(MoonAge))) / 2.0;

    /* Calculate distance of moon from the centre of the Earth */

    MoonDist = (msmax * (1.0 - mecc * mecc)) /
                   (1.0 + mecc * cos(torad(MmP + mEc)));

    /* Calculate Moon's angular diameter */

    MoonDFrac = MoonDist / msmax;
    MoonAng = mangsiz / MoonDFrac;

#if	0
    /* Calculate Moon's parallax */
    MoonPar = mparallax / MoonDFrac;
#endif
    *pphase   = MoonPhase;
    *mage     = synmonth * (fixangle(MoonAge) / 360.0);
    *dist     = MoonDist;
    *angdia   = MoonAng;
    *sudist   = SunDist;
    *suangdia = SunAng;
    return fixangle(MoonAge) / 360.0;
}

/*** qpom3() is arranged from qpom(). qpom() is written by Christopher Osburn.
/*
**  qpom.c
**  Christopher Osburn 911102
**
**  Routines returning age of the moon (qpom), quantity of lunar face
**  under illumination (illum), and the current lunation number
**  (lunation) using the extremely cheesy epoch/iteration method.
**
*/

#define LPERIOD  ((double)2551442.9)   /* synodic period of the moon, seconds,
                                          from astronomical almanac 1992 */
double
qpom3( double now, double epoch_near )
{
    double  diff, howfar;

    diff = (double) now - epoch_near;
                /* 本家の qpom() は epoch_near の部分に固定値を使用している
                 * ため、lunation の進行に伴って誤差がどんどん増えていくとい
                 * う欠点がある(実際に、qpom.c は数年毎に固定値部分を変更す
                 * る修正版が出ている)。
                 * qpom3() では、固定値ではなく、直近の epoch (朔のユリウス
                 * 日)を算出し、使用することで、長期にわたってプログラム変
                 * 更せずに済ませることができるものを目指している。
                 */
    howfar = diff / LPERIOD;
    return LPERIOD * (howfar - (long) howfar) / 86400.0;
}


#ifdef	UNIX
#ifdef	SYSV
#define	_tzname		tzname
#define	_timezone	timezone
#else
char	*_tzname[2];
long	_timezone;
#endif
#endif


void
tamo_moon( long _yy, long _mm, long _dd, long _hh, long _mmm, long _ss,
	       int flag )
{
    double          jd, aom, cphase, cdist, cangdia, csund, csuang, lptime;
    long            yy, mm, dd, hh, mmm, ss; /* (直前の)朔の年月日時分秒    */
    long            uyy, umm, udd, uhh, ummm, uss;   /* UTC変換後の現在日時 */
    double          phasar[5];
    long            lunation;
    static double   nptime = 0.0; /* Next new moon time */

    double          t1, t2;
    int	            __y, __m, __d;
    long            tt;
    struct tm       *lm;
    time_t          t = 0;

    /*
     *  timezone を求める (UTC とローカル時間の時差を求める)
     */
    lm = localtime( &t );
#ifdef	UNIX
# ifndef	SYSV
    /* BSD系のUNIXでは、以下の処理が必要
     *  (ANSI C 登場以前の UNIX では、BSD系でない場合でも、別途対応が必要
     *   であると思われる)
     */
    if ( (lm->tm_isdst != 0) && (lm->tm_isdst != 1) ) {
        lm->tm_isdst  = 0;
        lm->tm_gmtoff = 9 * 60 * 60;
        lm->tm_zone   = "JST";
    }
    _tzname[lm->tm_isdst] = lm->tm_zone;
    _timezone = -(lm->tm_gmtoff);
# endif
#else	/* !UNIX */
# ifdef	WIN32
    {
        OSVERSIONINFO   osverInfo;
        BOOL            ret;

        osverInfo.dwOSVersionInfoSize = sizeof ( OSVERSIONINFO );
        if ( ret = GetVersionEx( &osverInfo ) ) {
            if ( (osverInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) ||
                 (osverInfo.dwPlatformId == VER_PLATFORM_WIN32s       )    ) {
                /* Windows 3.x (Win32S環境), Windows95, Windows98 の場合は、
                 * 以下の処理が必要
                 */
                lm->tm_isdst = 0;
                _tzname[lm->tm_isdst] = "JST";
                _timezone = -(9 * 60 * 60);
            }
        }
    }
# endif
#endif

    /*
     *  ローカル時間で指定された年月日時分秒を UTC に変換する
     */
    t1 = ((((double)absoluteFromGregorian( _dd, _mm, _yy ) * 24.0 +
            (double)_hh) * 60.0) + (double)_mmm) * 60.0 +
            (double)_ss + (double)_timezone;
    tt = (_hh * 60 + _mmm) * 60 + _ss + _timezone;
    uyy  = _yy;
    umm  = _mm;
    udd  = _dd;
    uhh  = _hh;
    ummm = _mmm;
    uss  = _ss;
    if ( tt < 0 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _dd, _mm, _yy ) - 1,
                               &__d, &__m, &__y );
        uyy = __y;
        umm = __m;
        udd = __d;
    }
    else if ( tt > 24 * 60 * 60 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _dd, _mm, _yy ) + 1,
                               &__d, &__m, &__y );
        uyy = __y;
        umm = __m;
        udd = __d;
    }
    uhh = ((uhh * 60 * 60 + _timezone) / (60 * 60)) % 24;
    if ( uhh < 0 )
        uhh += 24;
    ummm = ((ummm * 60 + _timezone) / 60) % 60;
    if ( ummm < 0 )
        ummm += 60;
    uss = (uss + _timezone) % 60;
    if ( uss < 0 )
        uss += 60;

    /*
     *  UTC をユリウス日に変換する
     */
    jd = jtime( uyy, umm, udd, uhh, ummm, uss );

    /*
     *  当該ユリウス日の直前の朔の日時を求める
     */
    yy = 0;
    (void)phase( jd + 1, &cphase, &aom, &cdist, &cangdia, &csund, &csuang );
    phasehunt( jd, phasar );
    lptime   = phasar[0];
    lunation = (long)(floor(((lptime + 7.0) - lunatbase) / synmonth) + 1.0);
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );

    /*
     *  朔の日時(ユリウス日)を UTC に変換する
     */
    t2 = ((((double)absoluteFromGregorian( dd, mm, yy ) * 24.0 +
            (double)hh) * 60.0) + (double)mmm) * 60.0 + (double)ss;

    /*
     * 2つの UTC の差分を元に月齢を求める
     */
    aom = qpom3( t1, t2 );
    if ( aom < 0.0 )
        aom += synmonth;

    /*
     *  結果を出力する
     */
    if ( flag ) {
        printf( "<TABLE BORDER=\"0\" SUMMARY=\"月齢\">\n<TR><TD>月齢" );
    }
    else {
	    if ( !strncmp( _tzname[lm->tm_isdst], "東京", 4 ) )
	        printf( "%d年%02d月%02d日 %02d時%02d分%02d秒(JST)現在の月齢",
                    _yy, _mm, _dd, _hh, _mmm, _ss );
	    else if ( _tzname[lm->tm_isdst][0] )
	        printf( "%d年%02d月%02d日 %02d時%02d分%02d秒(%s)現在の月齢",
                    _yy, _mm, _dd, _hh, _mmm, _ss, _tzname[lm->tm_isdst] );
        else
	        printf( "%d年%02d月%02d日 %02d時%02d分%02d秒現在の月齢",
                    _yy, _mm, _dd, _hh, _mmm, _ss );
    }

    printf( "%s%.1f (%02d日%02d時%02d分)",
            flag ? "</TD><TD>" : ":\n                 ",
            aom /*+ 0.05*/,
            (int) aom, ((int) (24 * (aom - floor(aom)))),
            ((int) (1440 * (aom - floor(aom)))) % 60 );

    printf( " %s[輝度: %.1f%%]",
	        flag ? "<BR>" : " ",
          (1.0 - cos((2.0 * PI * aom) / (LPERIOD / 86400.0))) / 2.0 * 100.0 );

    if ( flag ) {
        printf( "</TD>\n<TD ROWSPAN=5><IMG SRC=" );
        printf( 
#ifdef  RIMNET
                "\"/~tsupo/qpom/image/moon%2.2d.gif\"",
#else
                "\"qpom/image/moon%2.2d.gif\"",
#endif
                (int)(100.0 * (aom /*+ 0.05*/) / (LPERIOD / 86400.0)) );
        printf( " WIDTH=\"110\" HEIGHT=\"110\"" );
        printf( " ALIGN=\"LEFT\" BORDER=2 ALT=\"[%1d day old Moon]\">\n",
                (long)(aom /*+ 0.05*/));
        printf( "</TD></TR>\n<TR><TD>" );
    }
    else {
        putchar( '\n' );
    }

    printf( "地球-月の距離%s%ldkm%s(地球赤道半径の%.1f倍)\n",
            flag ? "</TD><TD>" : ":   ",
            (long) cdist,
            flag ? "<BR>" : " ",
            cdist / earthrad );

    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "月の視差%s%.4f度\n",
            flag ? "</TD><TD>" : ":        ",
            cangdia );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "地球-太陽の距離%s%.0fkm%s(%.3f天文単位)\n",
            flag ? "</TD><TD>" : ": ",
            csund,
            flag ? "<BR>" : " ",
            csund / sunsmax );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "太陽の視差%s%.4f度\n",
            flag ? "</TD><TD>" : ":      ",
            csuang );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );

    printf( "朔%s%ld年%02ld月%02ld日 %02ld時%02ld分 UTC ",
            flag ? "</TD><TD COLSPAN=2>" : ":              ",
            yy, mm, dd, hh, mmm );
    printf( "(Lunation %ld)\n", lunation );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[1];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "上弦%s%ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
            flag ? "</TD><TD COLSPAN=2>" : ":            ",
            yy, mm, dd, hh, mmm );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[2];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "望%s%ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
            flag ? "</TD><TD COLSPAN=2>" : ":              ",
            yy, mm, dd, hh, mmm );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[3];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "下弦%s%ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
            flag ? "</TD><TD COLSPAN=2>" : ":            ",
            yy, mm, dd, hh, mmm );
    if ( flag )
        printf( "</TD></TR>\n<TR><TD>" );

    nptime = phasar[4];
    jyear( nptime, &yy, &mm, &dd );
    jhms( nptime, &hh, &mmm, &ss );
    printf( "次の朔%s%ld年%02ld月%02ld日 %02ld時%02ld分 UTC ",
            flag ? "</TD><TD COLSPAN=2>" : ":          ",
            yy, mm, dd, hh, mmm );
    printf( "(Lunation %ld)\n", lunation + 1 );
    if ( flag )
        printf( "</TD></TR>\n</TABLE>\n" );

#ifdef  __TEST_20030507__
    if ( !flag ) {
        double  target = 0.0;

        lptime   = phasar[0];
        jyear( lptime, &yy, &mm, &dd );
        jhms( lptime, &hh, &mmm, &ss );
        printf( "  月齢 %f : %ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
                target, yy, mm, dd, hh, mmm );
        target += 1.0;

        do {
            jyear( lptime, &yy, &mm, &dd );
            jhms( lptime, &hh, &mmm, &ss );
            /*
            t1 = ((((double)absoluteFromGregorian( dd, mm, yy ) * 24.0 +
                    (double)hh) * 60.0) + (double)mmm) * 60.0 +
                    (double)ss;
         // aom = qpom3( t1, t2 );
            */

            jd = jtime( yy, mm, dd, hh, mmm, ss );
            phase( jd + 1, &cphase, &aom, &cdist, &cangdia, &csund, &csuang );

            /*
            if ( aom < 0.0 )
                aom += synmonth;
            */
         // printf( "aom = %f\n", aom );
            /*
                jyear( lptime, &yy, &mm, &dd );
                jhms( lptime, &hh, &mmm, &ss );
                printf( "  月齢 %f : %ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
                        aom, yy, mm, dd, hh, mmm );
            */
         // if ( aom > 1.0 )
         //     break;
            if ( floor(target * 100.0) == floor(aom * 100.00) ) {
                printf( "  月齢 %f : %ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
                        target - 1.0, yy, mm, dd, hh, mmm );
                target += 1.0;
            }
            lptime += 1.0 / (24.0 * 3600.0);
         /* lptime += 0.001; */
        } while ( floor(aom * 100.00) != 0.0 );

        lptime = phasar[4];
        jyear( lptime, &yy, &mm, &dd );
        jhms( lptime, &hh, &mmm, &ss );
        printf( "  月齢 %f : %ld年%02ld月%02ld日 %02ld時%02ld分 UTC\n",
                target, yy, mm, dd, hh, mmm );
    }
#endif  /* __TEST_20030507__ */
}


BOOL
isFullMoonDay( long _yy, long _mm, long _dd )
{
    double          jd, aom, cphase, cdist, cangdia, csund, csuang, lptime;
    long            yy, mm, dd, hh, mmm, ss; /* (直前の)朔の年月日時分秒    */
    long            uyy, umm, udd, uhh, ummm, uss;   /* UTC変換後の現在日時 */
    double          phasar[5];

    double          t1;
    int	            __y, __m, __d;
    long            tt;
    struct tm       *lm;
    time_t          t = 0;

    /*
     *  timezone を求める (UTC とローカル時間の時差を求める)
     */
    lm = localtime( &t );
#ifdef	UNIX
# ifndef	SYSV
    /* BSD系のUNIXでは、以下の処理が必要
     *  (ANSI C 登場以前の UNIX では、BSD系でない場合でも、別途対応が必要
     *   であると思われる)
     */
    if ( (lm->tm_isdst != 0) && (lm->tm_isdst != 1) ) {
        lm->tm_isdst  = 0;
        lm->tm_gmtoff = 9 * 60 * 60;
        lm->tm_zone   = "JST";
    }
    _tzname[lm->tm_isdst] = lm->tm_zone;
    _timezone = -(lm->tm_gmtoff);
# endif
#else	/* !UNIX */
# ifdef	WIN32
    {
        OSVERSIONINFO   osverInfo;
        BOOL            ret;

        osverInfo.dwOSVersionInfoSize = sizeof ( OSVERSIONINFO );
        if ( ret = GetVersionEx( &osverInfo ) ) {
            if ( (osverInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) ||
                 (osverInfo.dwPlatformId == VER_PLATFORM_WIN32s       )    ) {
                /* Windows 3.x (Win32S環境), Windows95, Windows98 の場合は、
                 * 以下の処理が必要
                 */
                lm->tm_isdst = 0;
                _tzname[lm->tm_isdst] = "JST";
                _timezone = -(9 * 60 * 60);
            }
        }
    }
# endif
#endif

    /*
     *  ローカル時間で指定された年月日時分秒を UTC に変換する
     */
    t1 = ((double)absoluteFromGregorian( _dd, _mm, _yy )) * 24.0 + _timezone;
    tt = _timezone;
    uyy  = _yy;
    umm  = _mm;
    udd  = _dd;
    uhh  = 0;
    ummm = 0;
    uss  = 0;
    if ( tt < 0 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _dd, _mm, _yy ) - 1,
                               &__d, &__m, &__y );
        uyy = __y;
        umm = __m;
        udd = __d;
    }
    else if ( tt > 24 * 60 * 60 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _dd, _mm, _yy ) + 1,
                               &__d, &__m, &__y );
        uyy = __y;
        umm = __m;
        udd = __d;
    }
    uhh = (_timezone / (60 * 60)) % 24;
    if ( uhh < 0 )
        uhh += 24;
    ummm = (_timezone / 60) % 60;
    if ( ummm < 0 )
        ummm += 60;
    uss = _timezone % 60;
    if ( uss < 0 )
        uss += 60;

    /*
     *  UTC をユリウス日に変換する
     */
    jd = jtime( uyy, umm, udd, uhh, ummm, uss );

    /*
     *  当該ユリウス日の直前の朔の日時を求める
     */
    yy = 0;
    (void)phase( jd + 1, &cphase, &aom, &cdist, &cangdia, &csund, &csuang );
    phasehunt( jd, phasar );

    lptime = phasar[2];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );

    return ( ( (yy == _yy) && (mm == _mm) && (dd == _dd) ) ? TRUE : FALSE );
}
