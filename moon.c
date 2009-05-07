/*
 *  moon.c
 *      arrenged by H.Tsujimura     1989,1990,1991,1995,1998,1999,2000,
 *                                  2001,2002
 *      Last updated:   20th December 2002
 *
 *      This program is for computing the phase of the moon.
 *
 * History :
 * $Log: moon.c $
 * Revision 1.2  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.1  2003/10/24  01:35:04  tsujimura543
 * Initial revision (renewal)
 *
 * Revision 1.69  2003/03/03  12:09:08  tsujimura543
 * �o�O�C�� (�Q�Ƃ��Ă���ϐ����Ԉ���Ă���)
 *
 * Revision 1.68  2003/03/03  12:07:41  tsujimura543
 * CGI �Ƀp�����[�^��n����悤�ɂ���
 *
 * Revision 1.67  2003/02/24  09:25:42  tsujimura543
 * ���s�`���̊g���q�� .cgi �̏ꍇ�AContent-type: �s���o�͂���悤�ɂ���
 *
 * Revision 1.66  2003/02/07  08:08:35  tsujimura543
 * �N�����I�v�V�����Ƃ��� -H, -v �𐳎��T�|�[�g
 *
 * Revision 1.65  2002/12/20  07:49:27  tsujimura543
 * �P�x�̕\����ǉ�
 *
 * Revision 1.64  2002/12/20  06:43:32  tsujimura543
 * ��`���̍� �̕\���� 1 lunation �O�̂��̂�\�����Ă��܂����Ƃ�
 * ����s��ɑΏ�
 *
 * Revision 1.63  2001/04/17  13:43:38  tsujimura543
 * jdate() �� jtime() �̈�����ύX (2038�N��肩����)
 *
 * Revision 1.62  2001/02/22  13:31:23  tsujimura543
 * 1970�N1��1���ȑO�A2038�N1��19���ȍ~�̓������w�肷���mktime()�ŗ�O������
 * ���錻�ۂɑΏ�
 *
 * Revision 1.61  2001/02/22  12:47:08  tsujimura543
 * moon2.c �� moon.c �ɓ����B����ɁAWeb �A�v���P�[�V�����Ƃ��Ď��^�p���Ă�
 * ���łƓ����B
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.54  2001/01/17  18:09:23  tsujimura543
 * lunation �̕ς��ڂ̒��O�ɂȂ�ƌ�����̒l�ɂȂ��Ă��܂����Ƃ�����s��
 * ���ɑΏ�
 * 
 * Revision 1.53  2000/10/18  15:43:28  tsujimura543
 * �����\���������N�������R�}���h���C���Ŏw��ł���悤�ɂ���
 * 
 * Revision 1.52  1999/12/20  15:39:04  tsujimura543
 * ���ۂ̌����� ��1.5 ���炢�傫�Ȓl�ɂȂ��Ă��܂��s��ɑΏ�
 * 
 * Revision 1.51  1999/03/29  15:53:10  tsujimura543
 * moon.c �̎��������o�[�W���� (moon2.c)
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ�
 *
 * Revision 1.1  1996/08/19  12:01:10  tsujimura
 * Initial revision
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
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

#ifdef  __STDC__
static double   jtime( long, long, long, long, long, long  );
static double   phase( double, double *, double *, double *, double *, double *, double * );
static void     phasehunt( double, double * );
static void     jyear( double, long *, long *, long* );
static void     jhms( double, long *, long *, long* );
#else
double  jtime(), phase();
void    phasehunt();
void    jyear(), jhms();
#endif

/*  JDATE  --  Convert internal GMT date and time to Julian day
               and fraction.  */

static long jdate( yy, mm, dd )
long	yy, mm, dd;
{
    long c, m, y;

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

static double jtime( yy, mm, dd, HH, MM, SS )
long	yy, mm, dd, HH, MM, SS;
{
    return (jdate(yy, mm, dd) - 0.5) + 
               (SS + 60 * (MM + 60 * HH)) / 86400.0;
}

/*  JYEAR  --  Convert Julian date to year, month, day, which are
               returned via integer pointers to integers.  */

static void jyear(td, yy, mm, dd)
double td;
long *yy, *mm, *dd;
{
    double j, d, y, m;

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
double j;
long *h, *m, *s;
{
    long ij;

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
double sdate, phase;
double *usek;
int    *cnt;
{
    long yy, mm, dd;
    double k, t, t2, t3, nt1;
    double preK;
    static double preNt1 = 0.0;

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

static double truephase(k, phase)
double k, phase;
{
    double t, t2, t3, pt, m, mprime, f;
    int apcor = FALSE;

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

static void phasehunt(sdate, phases)
double sdate;
double phases[5];
{
    double adate, k1, k2, nt1, nt2;
    int    cnt = 0;

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

static double kepler(m, ecc)
double m, ecc;
{
    double e, delta;
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

static double phase(pdate, pphase, mage, dist, angdia, sudist, suangdia)
double pdate;
double *pphase;                    /* Illuminated fraction */
double *mage;                      /* Age of moon in days */
double *dist;                      /* Distance in kilometres */
double *angdia;                    /* Angular diameter in degrees */
double *sudist;                    /* Distance to Sun */
double *suangdia;                  /* Sun's angular diameter */
{
    double Day, N, M, Ec, Lambdasun, ml, MM, MN, Ev, Ae, A3, MmP,
           mEc, A4, lP, V, lPP, NP, y, x, Lambdamoon,
           MoonAge, MoonPhase,
           MoonDist, MoonDFrac, MoonAng,
           F, SunDist, SunAng;

    /* Calculation of the Sun's position */

    Day = pdate - epoch;        /* Date within epoch */
    N = fixangle((360.0 / 365.2422) * Day); /* Mean anomaly of the Sun */
    M = fixangle(N + elonge - elongp);    /* Convert from perigee
                                   co-ordinates to epoch 1980.0 */
    Ec = kepler(M, eccent);     /* Solve equation of Kepler */
    Ec = sqrt((1.0 + eccent) / (1.0 - eccent)) * tan(Ec / 2.0);
    Ec = 2.0 * todeg(atan(Ec));   /* True anomaly */
    Lambdasun = fixangle(Ec + elongp);  /* Sun's geocentric ecliptic
                                           longitude */
    /* Orbital distance factor */
    F = ((1.0 + eccent * cos(torad(Ec))) / (1.0 - eccent * eccent));
    SunDist = sunsmax / F;      /* Distance to Sun in km */
    SunAng = F * sunangsiz;     /* Sun's angular size in degrees */

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

/*** qpom2() is arranged from qpom(). qpom() is written by Christopher Osburn.
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
#ifdef  __STDC__
double qpom2(time_t now, time_t epoch_near)
#else
double qpom2(now, epoch_near)
time_t  now, epoch_near;
#endif
{
    double  diff, howfar;

    diff   = (double) now - epoch_near;
                /* �{�Ƃ� qpom() �� epoch_near �̕����ɌŒ�l���g�p���Ă���
                 * ���߁Alunation �̐i�s�ɔ����Č덷���ǂ�ǂ񑝂��Ă����Ƃ�
                 * �����_������(���ۂɁAqpom.c �͐��N���ɌŒ�l������ύX��
                 * ��C���ł��o�Ă���)�B
                 * qpom2() �ł́A�Œ�l�ł͂Ȃ��A���߂� epoch (��̃����E�X
                 * ��)���Z�o���A�g�p���邱�ƂŁA�����ɂ킽���ăv���O������
                 * �X�����ɍς܂��邱�Ƃ��ł�����̂�ڎw���Ă���B
                 */
    howfar = diff / LPERIOD;
    return LPERIOD * (howfar - (int) howfar) / 86400.0;
}


/*
 * phasehunt() �ŋ��߂���A�㌷�A�]�A�����A���̍�̓�����
 * qpom2() �̑�1�����Ɏw�肵���ꍇ�̌�� 0.0, 7.5, 15.0,
 * 22.5, 30.0 �ɂ͂Ȃ�Ȃ�(����v�Z�̕��@���Ⴄ�����̂���)
 * �ȉ��̊֐��́Aqpom2() �̒l�� 0.0, 7.5, 15.0, 22.5, 30.0
 * �ɂȂ���������߂邽�߂̂��̂ł���B
 */

#ifdef  __STDC__
struct tm *
getTruePhaseWithQpom( time_t t1, time_t t2, double curAom, double moonPhase )
#else
struct tm *
getTruePhaseWithQpom( t1, t2, curAom, moonPhase )
time_t t1;
time_t t2;
double curAom;
double moonPhase;
#endif
{
    time_t    t;
    double    aom, diff;
    struct tm *tm;

    diff = moonPhase - curAom;
    t    = t1 + (int)(diff * 24.0 * 60.0 * 60.0);
    aom  = qpom2( t, t2 );
    if ( aom > moonPhase ) {
        t -= (int)((aom - moonPhase) * 24.0 * 60.0 * 60.0);
        aom  = qpom2( t, t2 );
    }
    tm   = gmtime( &t );

    return ( tm );
}

#ifdef  __STDC__
void
getPhasesWithQpom(
    time_t t1, time_t t2, double curAom, /*long lunation,*/ char flag )
#else
getPhasesWithQpom( t1, t2, curAom, /*lunation,*/ flag )
time_t t1;
time_t t2;
double curAom;
/*long lunation;*/
char   flag;
#endif
{
    struct tm *tm;

    if ( (flag & 2) == 0 ) {
	return;
    }

    if ( (flag & 1) == 1 )
        printf( "<TR><TD COLSPAN=2>" );
    printf( "\n�Q�l: \n" );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    tm = getTruePhaseWithQpom( t1, t2, curAom, synmonth * 0.00 );
    printf( 
    /*"  ��%s            %d�N%02d��%02d�� %02d��%02d�� UTC (Lunation %d)\n",*/
      "  ��%s            %d�N%02d��%02d�� %02d��%02d�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min /*,
            lunation*/ );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    tm = getTruePhaseWithQpom( t1, t2, curAom, synmonth * 0.25 );
    printf( "  �㌷%s          %d�N%02d��%02d�� %02d��%02d�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    tm = getTruePhaseWithQpom( t1, t2, curAom, synmonth * 0.50 );
    printf( "  �]%s            %d�N%02d��%02d�� %02d��%02d�� UTC\n",
             (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    tm = getTruePhaseWithQpom( t1, t2, curAom, synmonth * 0.75 );
    printf( "  ����%s          %d�N%02d��%02d�� %02d��%02d�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    tm = getTruePhaseWithQpom( t1, t2, curAom, synmonth * 1.00 );
    printf( 
    /*"  ���̍�%s        %d�N%02d��%02d�� %02d��%02d�� UTC (Lunation %d)\n",*/
      "  ���̍�%s        %d�N%02d��%02d�� %02d��%02d�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            tm->tm_year + 1900, tm->tm_mon + 1,
            tm->tm_mday, tm->tm_hour, tm->tm_min /*,
            lunation + 1*/ );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n" );
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

time_t
getTargetDateTime( argc, argv, flag )
int  argc;
char *argv[];
char *flag;
{
    struct tm   _tm;
    time_t      t = 0;

 /* *flag = 0; */
    if ( argc > 1 ) {
        int   i, j;

        for ( i = 1; i < argc; i++ ) {
            if ( argv[i][0] == '-' ) {
		for ( j = 1; argv[i][j] != '\0'; j++ ) { 
		    switch ( argv[i][j] ) {
		    case 'H':
			*flag |= 1;
			break;
		    case 'v':
			*flag |= 2;
			break;
		    }
		}

		continue;
            }
            else if ( (argv[i][0] >= '0') && (argv[i][0] <= '9') &&
                      ( (strlen( argv[i] ) ==  8) ||
                        (strlen( argv[i] ) == 12) || 
                        (strlen( argv[i] ) == 14)                   )    ) {
                int y, m, d, H = 0, M = 0, S = 0;
                y = (argv[i][0] - '0') * 1000 +
                        (argv[i][1] - '0') * 100 +
                        (argv[i][2] - '0') * 10 +
                        (argv[i][3] - '0');
                m = (argv[i][4] - '0') * 10 + (argv[i][5] - '0');
                d = (argv[i][6] - '0') * 10 + (argv[i][7] - '0');
                if ( argv[i][8] != '\0' ) {
                    H = (argv[i][ 8] - '0') * 10 + (argv[i][ 9] - '0');
                    M = (argv[i][10] - '0') * 10 + (argv[i][11] - '0');
                    if ( argv[i][12] != '\0' ) {
                        S = (argv[i][12] - '0') * 10 + (argv[i][13] - '0');
                    }
                }

                if ( y < 1970 ) {
                    fprintf( stderr,
                            "1970�N�ȑO�̌���v�Z�̓T�|�[�g���Ă��܂���B\n" );
                    exit( 1 );
                }
                if ( (y == 1970) && (m == 1) && (d == 1) && (H < 9) ) {
                    fprintf( stderr, "%s%s\n",
                             "1970�N1��1���̌ߑO9��(���{����)�ȑO��",
                             "����v�Z�̓T�|�[�g���Ă��܂���B" );
                    fprintf( stderr, "%s%s\n",
                             "����ɁA1970�N1��1���̌ߑO9��0��1�b",
                             "(���{����)�̌����\�����܂��B" );
                    H = 9; M = 0; S = 1;
                }
                if ( y > 2038 ) {
                    fprintf( stderr,
                         "2038�N�ȍ~�̌���v�Z�̓T�|�[�g���Ă��܂���B\n" );
                    exit( 1 );
                }
                if ( (y == 2038) &&
                     ( (m >  1) ||
                      ((m == 1) &&
                       ( (d >  19) ||
                        ((d == 19) &&
                         ( (H >  3) ||
                          ((H == 3) &&
                           ( (M >  14) ||
                            ((M == 14) && (S >= 8))
                           )
                          )
                         )
                        )
                       )
                      )
                     ) ) {
                    fprintf( stderr, "%s%s\n",
                             "2038�N1��19���̌ߑO3��14��8�b(���{����)�ȍ~��",
                             "����v�Z�̓T�|�[�g���Ă��܂���B" );
                    fprintf( stderr, "%s%s\n",
                             "����ɁA2038�N1��19���̌ߑO3��14��7�b",
                             "��(���{����)�̌���\�����܂��B" );
                    m = 1; d = 19;
                    H = 3; M = 14; S = 7;
                }

                memset( &_tm, 0, sizeof ( struct tm ) );
                _tm.tm_year = y - 1900;
                _tm.tm_mon  = m - 1;
                _tm.tm_mday = d;
                _tm.tm_hour = H;
                _tm.tm_min  = M;
                _tm.tm_sec  = S;
                t = mktime( &_tm );
            }
            else if ( !strcmp( argv[i], "yesterday" ) ) {
                t = time( NULL ) - 24 * 60 * 60;
            }
            else if ( !strcmp( argv[i], "tomorrow" ) ) {
                t = time( NULL ) + 24 * 60 * 60;
            }
        }
    }

    if ( t == 0 )
        t = time( NULL );

    return ( t );
}


#ifndef NUL
#define NUL '\0'
#endif

#ifdef  __STDC__
char    *decodeURL( const char *pp );
#else
char    *decodeURL();
#endif

static void
setParameter( p, yy, mm, dd, HH, MM, SS )
char    *p;
int     *yy, *mm, *dd, *HH, *MM, *SS;
{
    char    *q, *r;
    char    buf[BUFSIZ];

    while ( *p ) {
        q = NULL;

        if ( !strncmp( p, "y=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *yy = atoi( r );
        }

        if ( !strncmp( p, "m=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *mm = atoi( r );
        }

        if ( !strncmp( p, "d=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *dd = atoi( r );
        }

        if ( !strncmp( p, "H=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *HH = atoi( r );
            }
        }

        if ( !strncmp( p, "M=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *MM = atoi( r );
            }
        }

        if ( !strncmp( p, "S=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *SS = atoi( r );
            }
        }

        if ( !q )
            p++;
    }
}

static int
isLeapYear( yy )
int yy;
{
    int ret = 0;

    if ( (yy % 4) == 0 ) {
        ret = 1;
        if ( (yy % 100) == 0 ) {
            ret = 0;
            if ( (yy % 400) == 0 ) {
                ret = 1;
            }
        }
    }

    return ( ret );
}

static void
showMethod( yy, mm, dd, HH, MM, SS )
int yy, mm, dd, HH, MM, SS;
{
    int     a1, a2, a3;

    printf("<P ALIGN=\"CENTER\">\n" );
    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���N</A>\n",
           yy - 1, mm, dd, HH, MM, SS );

    a3 = yy;
    a2 = mm - 1;
    a1 = dd;
    if ( a2 == 0 ) {
        a3 = yy - 1;
        a2 = 12;
    }
    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">�挎</A>\n",
           a3, a2, a1, HH, MM, SS );

    a3 = yy;
    a2 = mm;
    a1 = dd - 1;
    if ( a1 == 0 ) {
        a2 = mm - 1;
        if ( a2 == 0 ) {
            a3 = yy - 1;
            a2 = 12;
        }
        switch ( a2 ) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            a1 = 31;
            break;
        case 2:
            if ( isLeapYear( a3 ) )
                a1 = 29;
            else
                a1 = 28;
            break;
        default:
            a1 = 30;
            break;
        }
    }
    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���</A>\n",
           a3, a2, a1, HH, MM, SS );

    printf("<A HREF=\"moon.cgi?y=0&m=0&d=0&H=0\">����</A>\n");

    a3 = yy;
    a2 = mm;
    a1 = dd + 1;
    switch ( a2 ) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if ( a1 == 32 ) {
            a2 = mm + 1;
            if ( a2 == 13 ) {
                a3 = yy + 1;
                a2 = 1;
            }
            a1 = 1;
            break;
        }
        break;
    case 2:
        if ( isLeapYear( a3 ) ) {
            if ( a1 == 30 ) {
                a2 = mm + 1;
                a1 = 1;
                break;
            }
        }
        else {
            if ( a1 == 29 ) {
                a2 = mm + 1;
                a1 = 1;
                break;
            }
        }
        break;
    default:
        if ( a1 == 31 ) {
            a2 = mm + 1;
            a1 = 1;
        }
        break;
    }
    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">����</A>\n",
           a3, a2, a1, HH, MM, SS );

    a3 = yy;
    a2 = mm + 1;
    a1 = dd;
    if ( a2 == 13 ) {
        a3 = yy + 1;
        a2 = 1;
    }
    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">����</A>\n",
           a3, a2, a1, HH, MM, SS );

    printf(
  "<A HREF=\"moon.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���N</A>\n",
           yy + 1, mm, dd, HH, MM, SS );
}


int
main( int argc, char *argv[] )
{
    time_t        t, _t;
    double        jd, aom, cphase, cdist, cangdia, csund, csuang, lptime;
    long          yy, mm, dd, hh, mmm, ss;
    long          _yy, _mm, _dd, _hh, _mmm, _ss;
    struct tm     *gm, *lm, _tm, _gm, _lm;
    double        phasar[5];
    long          lunation;
    static double nptime = 0.0; /* Next new moon time */
    char          flag   = 0;
    char          flag2  = 0;
    char          _argv[80];

    if ( (strlen(argv[0]) >= 4) &&
         !strcmp( &argv[0][strlen(argv[0]) - 4], ".cgi" ) ) {
        char    *p;

        flag = flag2 = 1;
        printf( "Content-type: text/html\n\n" );
        printf( "<HTML><HEAD><TITLE>moon phase</TITLE></HEAD><BODY>\n" );
        if ( ( p = getenv( "QUERY_STRING" ) ) != NULL ) {
            setParameter( p, &_yy, &_mm, &_dd, &_hh, &_mmm, &_ss );
            sprintf( _argv, "%04d%02d%02d%02d%02d%02d",
                     _yy, _mm, _dd, _hh, _mmm, _ss );
            if ( (_yy != 0) || (_mm != 0) || (_dd != 0) || (_hh != 0) ) {
                argv[1] = _argv;
                argv[2] = NULL;
                argc = 2;
            }
        }
    }

    t  = getTargetDateTime( argc, argv, &flag );
    gm = gmtime( &t );
    jd = jtime( gm->tm_year + 1900, gm->tm_mon + 1, gm->tm_mday,
                gm->tm_hour, gm->tm_min, gm->tm_sec );
    memcpy( &_gm, gm, sizeof ( struct tm ) );
    gm = &_gm;

    if ( jd <= nptime )
        return ( 0 );

    lm = localtime( &t );
#ifdef	UNIX
# ifndef	SYSV
    /* BSD�n��UNIX�ł́A�ȉ��̏������K�v
     *  (ANSI C �o��ȑO�� UNIX �ł́ABSD�n�łȂ��ꍇ�ł��A�ʓr�Ή����K�v
     *   �ł���Ǝv����)
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
                /* Windows 3.x (Win32S��), Windows95, Windows98 �̏ꍇ�́A
                 * �ȉ��̏������K�v
                 */
                lm->tm_isdst = 0;
                _tzname[lm->tm_isdst] = "JST";
                _timezone = -(9 * 60 * 60);
            }
        }
    }
# endif
#endif
    memcpy( &_lm, lm, sizeof ( struct tm ) );
    lm = &_lm;
    _yy  = lm->tm_year + 1900;
    _mm  = lm->tm_mon  + 1;
    _dd  = lm->tm_mday;
    _hh  = lm->tm_hour;
    _mmm = lm->tm_min;
    _ss  = lm->tm_sec;

    (void)phase( jd + 1, &cphase, &aom, &cdist, &cangdia, &csund, &csuang );
    phasehunt( jd, phasar );
    lptime   = phasar[0];
    lunation = (long)(floor(((lptime + 7.0) - lunatbase) / synmonth) + 1.0);
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );

    memset( &_tm, 0, sizeof ( struct tm ) );
    _tm.tm_year = yy - 1900;
    _tm.tm_mon  = mm - 1;
    _tm.tm_mday = dd;
    _tm.tm_hour = hh;
    _tm.tm_min  = mmm;
    _tm.tm_sec  = ss;
    _t  = mktime( &_tm ) - _timezone;
    aom = qpom2( t, _t );
    if ( aom < 0.0 )
        aom += synmonth;

    if ( (flag & 1) == 1 )
        printf( "<CENTER><TABLE ALIGN=\"CENTER\">\n<TR><TD>" );
        printf( "�����E�X��%s      %.5f\n",
                (flag & 1) == 1 ? "</TD><TD>" : ":", jd + 0.5);
        if ( (flag & 1) == 1 ) {
            printf( "</TD><TD ROWSPAN=6><IMG SRC=" );
            printf(
#ifdef	ORIG_IMAGE
                  "\"http://www.lunaroutreach.org/pom/pics/moon%2.2d.gif\"",
#else
# ifdef  TSUPO
                  "\"http://www.stp-1.com/~tsupo/qpom/image/moon%2.2d.gif\"",
                    /* ���� URL �͂��܂ŗL�����킩��Ȃ� */
# else
                  "\"qpom/image/moon%2.2d.gif\"",
# endif
#endif
                    (int)(100.0 * (aom /*+ 0.05*/) / (LPERIOD / 86400.0)) );
        printf( " ALIGN=\"LEFT\" BORDER=2 ALT=\"[%1d day old Moon]\">\n",

        (long)(aom /*+ 0.05*/));
        printf( "</TD></TR>\n<TR><TD>" );
    }

    printf( "���E���莞(UTC)%s %d�N%02d��%02d�� %02d��%02d��%02d�b\n",
            (flag & 1) == 1 ? "</TD><TD>" : ":",
            gm->tm_year + 1900, gm->tm_mon + 1, gm->tm_mday,
            gm->tm_hour, gm->tm_min, gm->tm_sec );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );
    if ( !strcmp( _tzname[lm->tm_isdst], "JST" ) ) {
        printf( "���{�W����(JST)%s %d�N%02d��%02d�� %02d��%02d��%02d�b\n",
                (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
                lm->tm_year + 1900, lm->tm_mon + 1, lm->tm_mday,
                lm->tm_hour, lm->tm_min, lm->tm_sec );
    }
    else {
        printf( "���[�J����(%s)%s %d�N%02d��%02d�� %02d��%02d��%02d�b\n",
                _tzname[0],
                (flag & 1) == 1 ? "</TD><TD>" : ":",
                lm->tm_year + 1900, lm->tm_mon + 1, lm->tm_mday,
                lm->tm_hour, lm->tm_min, lm->tm_sec );
    }
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    printf( "����%s            %.1f (%02d��%02d��%02d��)\n",
            (flag & 1) == 1 ? "</TD><TD>" : ":",
            aom /*+ 0.05*/,
            (int) aom, ((int) (24 * (aom - floor(aom)))),
            ((int) (1440 * (aom - floor(aom)))) % 60 );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD ALIGN=\"RIGHT\">" );

    printf( "  (�P�x%s         %.1f%%)\n",
            (flag & 1) == 1 ? "</TD><TD>" : ":",
        (1.0 - cos((2.0 * PI * aom) / (LPERIOD / 86400.0))) / 2.0 * 100.0 );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "�n��-���̋���%s   %ldkm (�n���ԓ����a��%.1f�{)\n",
            (flag & 1) == 1 ? "</TD><TD>" : ":",
            (long) cdist, cdist / earthrad );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "���̎���%s        %.4f�x\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            cangdia );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "�n��-���z�̋���%s %.0fkm (%.3f�V���P��)\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            csund, csund / sunsmax );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );
    printf( "���z�̎���%s      %.4f�x\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            csuang );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    printf( "��%s              %ld�N%02ld��%02ld�� %02ld��%02ld�� UTC ",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            yy, mm, dd, hh, mmm );
    printf( "(Lunation %ld)\n", lunation );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[1];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "�㌷%s            %ld�N%02ld��%02ld�� %02ld��%02ld�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            yy, mm, dd, hh, mmm );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[2];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "�]%s              %ld�N%02ld��%02ld�� %02ld��%02ld�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            yy, mm, dd, hh, mmm );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    lptime = phasar[3];
    jyear( lptime, &yy, &mm, &dd );
    jhms( lptime, &hh, &mmm, &ss );
    printf( "����%s            %ld�N%02ld��%02ld�� %02ld��%02ld�� UTC\n",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            yy, mm, dd, hh, mmm );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n<TR><TD>" );

    nptime = phasar[4];
    jyear( nptime, &yy, &mm, &dd );
    jhms( nptime, &hh, &mmm, &ss );
    printf( "���̍�%s          %ld�N%02ld��%02ld�� %02ld��%02ld�� UTC ",
            (flag & 1) == 1 ? "</TD><TD COLSPAN=2>" : ":",
            yy, mm, dd, hh, mmm );
    printf( "(Lunation %ld)\n", lunation + 1 );
    if ( (flag & 1) == 1 )
        printf( "</TD></TR>\n" );

    getPhasesWithQpom( t, _t, aom, /*lunation,*/ flag );

    if ( (flag & 1) == 1 )
        printf( "</TABLE></CENTER>\n" );
    if ( flag2 ) {
        showMethod( _yy, _mm, _dd, _hh, _mmm, _ss );
        printf( "</BODY></HTML>\n" );
    }

    return ( 1 );
}
