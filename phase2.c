/*
 *  phase2.c
 *      arrenged by H.Tsujimura     1989,1990,1991,1995,1998,1999,2000,2001
 *      Last updated:   20th February 2001
 *
 *      This program is for computing the phase of the moon.
 *
 * History :
 * $Log: phase2.c $
 * Revision 1.61  2003/02/21  02:41:33  tsujimura543
 * 月齢計算を最新の moon.c のものに変更
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.52  2000/08/23  11:01:57  tsujimura543
 * 計算精度の向上を試みる
 * 
 * Revision 1.51  1999/07/08  18:05:27  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう
 * 
 * Revision 1.1  1996/08/19  02:10:16  tsujimura
 * Initial revision
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 * moon.c を元に月齢算出部分のみを取り出す
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "dates.h"

#ifdef  M_PI
#define PI  M_PI
#else
#define PI 3.14159265358979323846  /* Assume not near black hole nor in
                                      Tennessee */
#endif

/*  Handy mathematical functions  */

#define sgn(x)      (((x) < 0) ? -1 : ((x) > 0 ? 1 : 0))    /* Extract sign */
#define abs(x)      ((x) < 0 ? (-(x)) : (x))                /* Absolute val */
#define fixangle(a) ((a) - 360.0 * (floor((a) / 360.0)))    /* Fix angle    */
#define torad(d)    ((d) * (PI / 180.0))                    /* Deg->Rad     */
#define todeg(d)    ((d) * (180.0 / PI))                    /* Rad->Deg     */
#define dsin(x)     (sin(torad((x))))                       /* Sin from deg */
#define dcos(x)     (cos(torad((x))))                       /* Cos from deg */

#define TRUE    1
#define FALSE   (!TRUE)

/*  Forward functions  */

#ifdef  __STDC__
static double   jtime( long, long, long, long, long, long );
static double   phasehunt( double );
static void     jyear( double, long *, long *, long* );
static void     jhms( double, long *, long *, long* );
#else
double  jtime();
double  phasehunt();
void    jyear(), jhms();
#endif

/*  JDATE  --  Convert internal GMT date and time to Julian day
               and fraction.  */

static long jdate( yy, mm, dd )
long    yy, mm, dd;
{
    long    c;

    if (mm > 2L)
        mm = mm - 3L;
    else {
        mm = mm + 9L;
        yy--;
    }
    c = yy / 100L;              /* Compute century */
    yy -= 100L * c;
    return dd + (c * 146097L) / 4L + (yy * 1461L) / 4L +
           (mm * 153L + 2L) / 5L + 1721119L;
}

/* JTIME --    Convert internal GMT date and time to astronomical Julian
               time (i.e. Julian date plus day fraction, expressed as
               a double).  */

static double jtime( yy, mm, dd, HH, MM, SS )
long    yy, mm, dd, HH, MM, SS;
{
    return (jdate( yy, mm, dd ) - 0.5) + 
           (SS + 60 * (MM + 60 * HH)) / 86400.0;
}

/*  JYEAR  --  Convert Julian date to year, month, day, which are
               returned via integer pointers to integers.  */

static void jyear(td, yy, mm, dd)
double  td;
long    *yy, *mm, *dd;
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

static void jhms(j, h, m, s)
double  j;
long    *h, *m, *s;
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

static double meanphase(sdate, phase, usek, cnt)
double  sdate, phase;
double  *usek;
int     *cnt;
{
    long    yy, mm, dd;
    double  k, t, t2, t3, nt1;
    double  preK;
    static double   preNt1 = 0.0;

    jyear(sdate, &yy, &mm, &dd);

    preK = k = (yy + ((mm - 1L) * (1.0 / 12.0)) - 1900.0) * 12.3685;

    /* Time in Julian centuries from 1900 January 0.5 */
    t = (sdate - 2415020.0) / 36525.64;
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
                   mean phase of the new moon, and corrected
                   phase time.  */

static double truephase(k)
double  k;
{
    double  t, t2, t3, pt, m, mprime, f;
    int     apcor = FALSE;

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
    return pt;
}

/*  PHASEHUNT  --  Find time of phases of the moon which surround
                   the current date.  Five phases are found, starting
                   and ending with the new moons which bound the
                   current lunation.  */

static double phasehunt(sdate)
double  sdate;
{
    double  adate, k1, k2, nt1, nt2;
    int     cnt = 0;

    adate = sdate - 45.0;
    nt1 = meanphase(adate, 0.0, &k1, &cnt);
    while (TRUE) {
        adate += synmonth;
        nt2 = meanphase(adate, 0.0, &k2, &cnt);
        if ((nt1 <= sdate) && (nt2 > sdate))
            break;
        nt1 = nt2;
        k1  = k2;
    }

    return ( truephase(k1) );
}


/*  qpom3() is based on qpom() from qpom.c */
/*
**  qpom.c
**  Christopher Osburn 911102
**
**  Routines returning age of the moon (qpom), quantity of lunar face
**  under illumination (illum), and the current lunation number
**  (lunation) using the extremely cheesy epoch/iteration method.
**
*/

#define LPERIOD  (2551442.9)   /* synodic period of the moon, seconds,
                                  from astronomical almanac 1992 */

#ifdef  __STDC__
double qpom3(double now, double epoch_near)
#else
double qpom3(now, epoch_near)
double	now, epoch_near;
#endif
{
    double  diff, howfar;

    diff = (double) now - epoch_near;
                /* 本家の qpom() は epoch_near の部分に固定値を使用している
                 * ため、lunation の進行に伴って誤差がどんどん増えていくとい
                 * う欠点がある(実際に、qpom.c は数年毎に固定値部分を変更す
                 * る修正版が出ている)。
                 * qpom2() では、固定値ではなく、直近の epoch (朔のユリウス
                 * 日)を算出し、使用することで、長期にわたってプログラム変
                 * 更せずに済ませることができるものを目指している。
                 */
    howfar = diff / LPERIOD;
    return LPERIOD * (howfar - (long) howfar) / 86400.0;
}


#ifdef	UNIX
#ifdef	SYSV
#define	_timezone   timezone
#else
static long _timezone;
#endif
#endif

#ifdef	__STDC__
double
moonPhase2( int _y, int _m, int _d, int _H, int _M, int _S )
#else
double
moonPhase2( _y, _m, _d, _H, _M, _S )
int _y, _m, _d, _H, _M, _S;
#endif
{
    double      jd, aom, lptime;
    double      t1, t2;
    long        yy, mm, dd, HH, MM, SS, tt;
    int		__y, __m, __d;
#ifdef	UNIX
    struct tm   *gm;
    time_t	t = 0;

    gm = localtime( &t );
#ifndef	SYSV
    _timezone = -(gm->tm_gmtoff);
#endif
#endif
    t1 = ((((double)absoluteFromGregorian( _d, _m, _y ) * 24.0 +
            (double)_H) * 60.0) + (double)_M) * 60.0 +
            (double)_S + (double)_timezone;
    tt = (_H * 60 + _M) * 60 + _S + _timezone;
    if ( tt < 0 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _d, _m, _y ) - 1,
                               &__d, &__m, &__y );
        _y = __y;
        _m = __m;
        _d = __d;
    }
    else if ( tt > 24 * 60 * 60 ) {
        gregorianFromAbsolute( absoluteFromGregorian( _d, _m, _y ) + 1,
                               &__d, &__m, &__y );
        _y = __y;
        _m = __m;
        _d = __d;
    }
    _H = ((_H * 60 * 60 + _timezone) / (60 * 60)) % 24;
    _M = ((_M * 60 + _timezone / 60) / 60) % 60;
    _S = (_S + _timezone) % 60;
    jd = jtime( _y, _m, _d, _H, _M, _S );

    if ( jd > 0.0 ) {
        lptime = phasehunt( jd );
        jyear( lptime, &yy, &mm, &dd );
        jhms( lptime, &HH, &MM, &SS );
        t2 = ((((double)absoluteFromGregorian( dd, mm, yy ) * 24.0 +
                (double)HH) * 60.0) + (double)MM) * 60.0 + (double)SS;
        aom = qpom3( t1, t2 );
        if ( aom < 0.0 )
            aom += synmonth;
    }
    else {
        printf( "月齢計算不能\n" );
        aom = -1.0;
    }

    return ( aom /* + 0.05 */ );
}


