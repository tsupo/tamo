/*
 *      holiday.c
 *                      by H.Tsujimura  tsupo@na.rim.or.jp
 *                                              2 March 1991
 *      Copyright (c) 1991-1995,1998,1999,2000,2001,2003    Hiroshi Tsujimura
 *      All Rights Reserved.
 *
 * History :
 * $Log: holiday.c $
 * Revision 1.78  2009/04/27  11:33:46  tsujimura543
 * bug fixed
 *
 * Revision 1.77  2007/02/20  04:47:37  tsujimura543
 * 18�����Ղ̔������ԁA�ʗp���Ԃ��ŋ߂̏󋵂ɍ��킹�ďC��
 *
 * Revision 1.76  2007/02/08  02:44:01  tsujimura543
 * �Ď��Ԃ̊J�n�A�I���֘A������ύX�E�ǉ�
 *
 * Revision 1.75  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.74  2003/03/17  07:36:50  tsujimura543
 * �\�[�X����
 *
 * Revision 1.73  2003/03/14  09:37:59  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.72  2003/03/11  02:09:28  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.71  2003/03/07  03:16:24  tsujimura543
 * ���[�}��(�����E�X��)�� ides �\����ǉ�
 *
 * Revision 1.70  2003/02/28  06:53:31  tsujimura543
 * 2002�N5��6�����U�֋x���ƕ\������Ȃ��s����C��(Rev1.69�̏C���~�X������)
 *
 * Revision 1.69  2003/02/25  06:03:55  tsujimura543
 * 2003�N5��5�����U�֋x���ƕ\������Ă��܂��s��ɑΏ�
 *
 * Revision 1.68  2003/02/19  07:29:36  tsujimura543
 * �l�p�[����Ή�
 *
 * Revision 1.67  2003/02/10  05:02:42  tsujimura543
 * �t�����X�v���L�O���A�h�C�c����L�O������ǉ�
 *
 * Revision 1.66  2003/02/07  04:47:44  tsujimura543
 * �C�X������̏j�Փ��\�L���኱�ύX
 *
 * Revision 1.65  2003/02/06  09:41:58  tsujimura543
 * ���_�����̏j�Փ���ǉ�
 *
 * Revision 1.64  2003/02/05  10:08:32  tsujimura543
 * �����ۂ��܂�̊J�Ê��Ԃ�2��5������ɂȂ����̂ɑΉ�
 *
 * Revision 1.63  2001/06/15  11:11:21  tsujimura543
 * �u�V�l�̓��v�Ή�
 *
 * Revision 1.62  2001/06/13  13:02:52  tsujimura543
 * �u���V�A�̓��v��ǉ�
 *
 * Revision 1.61  2001/05/25  13:52:26  tsujimura543
 * 2003�N����A�C�̓��ƌh�V�̓������ꂼ��7���A9���̑�3���j���ɂȂ�̂ɑΉ�
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.57  2001/02/05  21:57:57  tsujimura543
 * ���񂪉���ڂ́u�����ۂ��Ղ�v���\������悤�ɕύX
 * 
 * Revision 1.56  2001/02/02  16:14:56  tsujimura543
 * (1) �u�����ۂ��Ղ�v�̕\���@�\��ǉ�
 * (2) �u�f��̓��v�̕\���@�\��ύX(1956�N�ȍ~�̔N�̂ݕ\������悤�ɂ���)
 * 
 * Revision 1.55  2001/01/22  22:18:34  tsujimura543
 * (1) (int)0xFFFFFFFF �̒l�����̒l�ɂȂ�}�V���ŏj�����\������Ȃ��Ȃ�s�
 *     �ɑΏ�
 * (2) �r�X�P�b�g�̓��A���C�̓��A�Ȃǂ̕\���@�\��ǉ�
 * (3) ��O�̏j�����������ǉ�
 * (4) 13�����̎Z�o�֐���ǉ�
 * 
 * Revision 1.54  2000/06/01  10:24:06  tsujimura543
 * �Ď��Ԃ̊J�n���̕\���p�֐����A�����J�ƃ��[���b�p�ŕʂ̂��̂ɂ���
 * 
 * Revision 1.53  2000/03/30  20:41:36  tsujimura543
 * (1) ���̓��A�{�X�̓��̕\���@�\��ǉ�
 * (2) �����̌h�V�̓��̕\���@�\��ǉ�
 * 
 * Revision 1.52  1999/11/01  17:24:21  tsujimura543
 * 18�ؕ��̎g�p���Ԃ̕\�����C��(���s��ǉ�)
 * 
 * Revision 1.51  1999/07/13  12:00:36  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1998/02/06  15:37:58  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.8  95/12/03 12:03:54  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.7  95/12/03 02:32:26  tsujimura
 * trainService() �� bug fix
 * 
 * Revision 1.6  95/12/03 02:12:06  tsujimura
 * JR�̗����v�Z�̓�����Z�o��ǉ�
 * 
 * Revision 1.5  95/12/03 01:53:14  tsujimura
 * ���{�̏j�Փ��𖾎����ȍ~�Ɋւ��Ċ��S�Ή�
 * 
 * Revision 1.4  92/03/29 03:19:38  tsujimura
 * test release
 * 
 * Revision 1.3  91/03/17 17:01:20  tsujimura
 * test version
 * 
 * Revision 1.2  91/03/17 17:01:20  tsujimura
 * (1) added some holidays
 * (2) changed functions for calculation of old-japanese-calendar
 * 
 * Revision 1.1  91/03/02 06:00:48  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if     0
#include <values.h>
#else
#define MAXINT  (int)(999999)
#endif
#include "dates.h"

#ifndef lint
static char     *rcs_id =
        "$Header: C:/user/local/src/tamo/RCS/holiday.c 1.78 2009/04/27 11:33:46 tsujimura543 Exp tsujimura543 $";
#endif

static long     easterday;
static long     roshHaShanah;   /* @@ */
static long     passoverday;
static long     tishaBAvday;    /* @@ */
static long     risshunday;
static long     shunbunday;
static long     geshiday;
static long     risshuuday;
static long     shuubunday;

static struct ZODIAC    {
        char    *sign;
        int     mm;
        int     dd;
} z[12] = {     "���r��  Aquarius",      1,     20,
                "  ����  Pisces",        2,     19,
                "���r��  Aries",         3,     21,
                "������  Taurus",        4,     20,
                "�o�q��  Gemini",        5,     21,
                "  �I��  Cancer",        6,     22,
                "���q��  Leo",           7,     23,
                "������  Virgo",         8,     23,
                "�V����  Libra",         9,     23,
                "  嶍�  Scorpio",      10,     24,
                "�ˎ��  Sagitarius",   11,     22,
                "�R�r��  Capricorn",    12,     22  };

static struct ZODIAC13  {
        char    *sign;
        int     mm;
        int     dd;
} z13[13] = {   "�R�r��  Capricorn",     1,     19,
                "���r��  Aquarius",      2,     16,
                "  ����  Pisces",        3,     11,
                "���r��  Aries",         4,     19,
                "������  Taurus",        5,     14,
                "�o�q��  Gemini",        6,     21,
                "  �I��  Cancer",        7,     20,
                "���q��  Leo",           8,     11,
                "������  Virgo",         9,     16,
                "�V����  Libra",        10,     30,
                "  嶍�  Scorpio",      11,     23,
                "�֌���  Ophiuchus",    11,     30,
                "�ˎ��  Sagitarius",   12,     18  };

static struct holiday {
        char    *name;  /* �j�Փ��� */
        int     mm;     /* ��       */
        int     dd;     /* ��       */
        int     s_yy;   /* �J�n�N   */
        int     e_yy;   /* �I���N   */
} h[] = {
        "�l���q(�V�N)",    1,    1,        0,   1945,
        "����",            1,    1,     1949,   MAXINT, /* ���a23�N����   */
        "���n��",          1,    3,     1928,   1945,
                                /* ����3�N�J�n, ����41�N����, ���a2�N���z */
        "�V�N����",        1,    5,     1872,   1945,
        "���l�̓�",        1,   15,     1949,   1999,   /* ���a23�N����   */
                              /* ���l�̓��͕���12�N���1����2���j���ƂȂ� */
        "�I����",          1,   29,     1873,   1873,   /* ����6�N�̂�    */
        "�F���V�c��",      1,   31,     1872,   1912,   /* �F���V�c����� */
        "�I����",          2,   11,     1874,   1945,   /* �_���V�c���ʓ� */
        "�����L�O�̓�",    2,   11,     1967,   MAXINT, /* ���a41�N����   */
        "�n�v��",          3,    6,     1827,   1945,   /* ���a�c�@�a���� */
    /*  "�t���̓�",        3,   21,        0,   MAXINT, */
        "�_���V�c��",      4,    3,     1872,   1945,   /* �_���V�c����� */
        "�V����",          4,   29,     1927,   1948,   /* ���a�V�c�a���� */
        "�V�c�a����",      4,   29,     1949,   1988,   /* ���a23�N����   */
        "�݂ǂ�̓�",      4,   29,     1989,   MAXINT, /* �������N����   */
        "���@�L�O��",      5,    3,     1949,   MAXINT, /* ���a23�N����   */
        "�����̋x��",      5,    4,     1989,   MAXINT,
        "���ǂ��̓�",      5,    5,     1949,   MAXINT, /* ���a23�N����   */
        "�n�v��",          5,   28,     1874,   1912,   /* �����c�@�a���� */
        "�n�v��",          6,   25,     1913,   1926,   /* �吳�c�@�a���� */
        "�C�̓�",          7,   20,     1996,   2002,
                             /* �C�̓��͕���15�N���7����3���j���ƂȂ�    */
        "�����V�c��",      7,   30,     1912,   1926,   /* �����V�c����� */
        "�V����",          8,   31,     1912,   1912,   /* �吳�V�c�a���� */
        "�Ƃ����̓�",    9,   15,     1954,   1963,
        "�V�l�̓�",        9,   15,     1964,   1965,
        "�h�V�̓�",        9,   15,     1966,   2002,
                             /* �h�V�̓��͕���15�N���9����3���j���ƂȂ�  */
    /*  "�H���̓�",        9,   23,        0,   MAXINT, */
        "�̈�̓�",       10,   10,     1966,   1999,
                             /* �̈�̓��͕���12�N���10����2���j���ƂȂ� */
        "�_����",         10,   17,     1879,   1944,
        "�V���ߏj��",     10,   31,     1913,   1926,   /* �吳2�N�`      */
        "�V����",         11,    3,     1873,   1911,   /* �����V�c�a���� */
                                        /* �������N�`5�N�͋����9��22��   */
        "������",         11,    3,     1927,   1945,   /* ���a2�N����    */
        "�����̓�",       11,    3,     1948,   MAXINT,
        "�V����",         11,   23,     1872,   1944,
                                        /* ����5�N�ȑO��11����2�̉K�̓�   */
        "�ΘJ���ӂ̓�",   11,   23,     1948,   MAXINT,
        "�V�c�a����",     12,   23,     1989,   MAXINT,
        "�吳�V�c�a����", 12,   25,     1927,   1944,   /* �吳�V�c����� */
        NULL,              0,    0,        0,   0       };

static struct holiday   hh[] = {
    "New Year's Day",                            1,      1,     0,    MAXINT,
    "quarter day [��]",                          1,      1,     0,    MAXINT,
    "12���ߑO���(Twelfth Night)",               1,      5,     0,    MAXINT,
    "������(Epiphany, Twelfth Day)",             1,      6,     0,    MAXINT,
    "Australia Day [NSW,ACT,Qld,NT Aust]",       1,     26,     0,    MAXINT,
    "���a���L�O�� [�C���h]",                     1,     26,     0,    MAXINT,
    "���C��(Candlemas)",                         2,      2,     0,    MAXINT,
    "Ground Hog Day",                            2,      2,     0,    MAXINT,
    "�����J�[���a����",                          2,     12,     0,    MAXINT,
    "St. Valentine's Day",                       2,     14,     0,    MAXINT,
    "����̋V��",                              2,     15,     0,    MAXINT,
    "���V���g���a����",                          2,     22,     0,    MAXINT,
    "St. David's Day",                           3,      1,     0,    MAXINT,
    "St. Patrick's Day",                         3,     17,     0,    MAXINT,
    "�������̏j��(Lady Day)",                    3,     25,     0,    MAXINT,
    "�����(All Fools' Day)",                    4,      1,     0,    MAXINT,
    "quarter day [��]",                          4,      1,     0,    MAXINT,
    "St. George's Day",                          4,     23,     0,    MAXINT,
    "May Day",                                   5,      1,     0,    MAXINT,
    "��2�����E���x��L�O��[��]",               5,      8,  1945,    MAXINT,
    "��������L�O��(Flag Day)[��]",              6,     14,     0,    MAXINT,
    "����҃��n�l�̍Փ�(Midsummer Day)",         6,     24,     0,    MAXINT,
    "�����L�O��(Dominion Day)[�J�i�_]",          7,      1,     0,    MAXINT,
    "quarter day [��]",                          7,      1,     0,    MAXINT,
    "�A�����J�Ɨ��L�O��(Independence Day)",      7,      4,  1776,    MAXINT,
    "Bastille Day [��]",                         7,      4,     0,    MAXINT,
    "�v���L�O��[��]",                            7,     14,     0,    MAXINT,
    "���n��(Lammas)",                            8,      1,     0,    MAXINT,
    "�ϗe�̏j��(Transfiguration)",               8,      6,     0,    MAXINT,
    "����폸�V�̏j��(Assumption)",              8,     15,     0,    MAXINT,
    "����}���A�a����(Nativity)",                9,      8,     0,    MAXINT,
    "�~�J�G����(Michaelmas)",                    9,     29,     0,    MAXINT,
    "quarter day [��]",                         10,      1,     0,    MAXINT,
    "����L�O��[��]",                           10,      3,     0,    MAXINT,
    "Halloween",                                10,     31,     0,    MAXINT,
    "������(All Saints' Day)",                  11,      1,     0,    MAXINT,
    "�����(All Souls' Day)",                   11,      2,     0,    MAXINT,
    "Guy Fawkes Day",                           11,      5,     0,    MAXINT,
    "���}���^����(Martinmas)",                  11,     11,     0,    MAXINT,
#ifdef  OLDFASHIONED
    "Armistice Day",                            11,     11,     0,    MAXINT,
#else
    "Veterans Day",                             11,     11,     0,    MAXINT,
#endif
    "��1�����E���x��L�O��[��]",              11,     11,  1918,    MAXINT,
    "�����߉��ق̏j��(Immaculate Conception)",  12,      8,     0,    MAXINT,
    "�c��̓�(Forefathers' Day)",               12,     22,     0,    MAXINT,
    "Christmas Eve",                            12,     24,     0,    MAXINT,
    "Christmas",                                12,     25,     0,    MAXINT,
    "Boxing Day [England, Wales]",              12,     26,     0,    MAXINT,
    "�����d���}���҂̏j��(Innocents's Day)",    12,     28,     0,    MAXINT,
    "New Year's Eve",                           12,     31,     0,    MAXINT,
    "Hogmanay [Scotland]",                      12,     31,     0,    MAXINT,
    NULL,                                        0,      0,     0,         0  };

static int      kiddushHaHamah = 0;
static int      talUmatar      = 0;

#define JANUARY         1
#define FEBRUARY        2
#define MARCH           3
#define APRIL           4
#define MAY             5
#define JUNE            6
#define JULY            7
#define AUGUST          8
#define SEPTEMBER       9
#define OCTOBER         10
#define NOVEMBER        11
#define DECEMBER        12

#define SUNDAY          0
#define MONDAY          1
#define TUESDAY         2
#define WEDNESDAY       3
#define THURSDAY        4
#define FRIDAY          5
#define SATURDAY        6

#define FIRST           1
#define SECOND          2
#define THIRD           3
#define FOURTH          4
#define LAST            -1

#define septuagestima(y)        ( easterday    - 63 )
#define sexagesima(y)           ( easterday    - 56 )           /* @@ */
#define quinquagesima(y)        ( easterday    - 49 )
#define shroveSunday(y)         ( easterday    - 49 )           /* @@ */
#define shroveMonday(y)         ( easterday    - 48 )           /* @@ */
#define mardiGras(y)            ( easterday    - 47 )
#define shroveTuesday(y)        ( easterday    - 47 )           /* @@ */
#define ashWednesday(y)         ( easterday    - 46 )
#define quadragesima(y)         ( easterday    - 42 )
#define britishMothersDay(y)    ( easterday    - 21 )
#define passionSunday(y)        ( easterday    - 14 )
#define palmSunday(y)           ( easterday    -  7 )
#define holyThursday(y)         ( easterday    -  3 )
#define maundyThursday(y)       ( easterday    -  3 )           /* @@ */
#define goodFriday(y)           ( easterday    -  2 )
#define holySaturday(y)         ( easterday    -  1 )
#define easterMonday(y)         ( easterday    +  1 )
#define lowSunday(y)            ( easterday    +  7 )
#define rogationSunay(y)        ( easterday    + 35 )           /* @@ */
#define rogationDay(y)          ( easterday    + 36 )
#define ascensionDay(y)         ( easterday    + 39 )
#define whitsunday(y)           ( easterday    + 49 )
#define pentecost(y)            ( easterday    + 49 )
#define whitmonday(y)           ( easterday    + 50 )
#define trinity(y)              ( easterday    + 56 )
#define corpusChristiDay(y)     ( easterday    + 60 )

#define erevRoshHaShanah(y)     ( roshHaShanah -  1 )           /* @@ */
#define roshHaShanah2(y)        ( roshHaShanah +  1 )           /* @@ */
#define tzomGedaliah(y)         ( (roshHaShanah % 7) == 4   \
                                         ? roshHaShanah + 3 \
                                         : roshHaShanah + 2   ) /* @@ */
#define erevYomKippur(y)        ( roshHaShanah +  8 )           /* @@ */
#define erevSukkot(y)           ( roshHaShanah + 13 )           /* @@ */
#define sukkot(y)               ( roshHaShanah + 14 )           /* @@ */
#define sukkot2(y)              ( roshHaShanah + 15 )           /* @@ */
#define holHamoedSukkot(y)      ( roshHaShanah + 16 )           /* @@ */
#define holHamoedSukkot2(y)     ( roshHaShanah + 17 )           /* @@ */
#define holHamoedSukkot3(y)     ( roshHaShanah + 18 )           /* @@ */
#define holHamoedSukkot4(y)     ( roshHaShanah + 19 )           /* @@ */
#define hoshannahRabbah(y)      ( roshHaShanah + 20 )           /* @@ */
#define sheminiAtzeret(y)       ( roshHaShanah + 21 )           /* @@ */
#define simchatTorah(y)         ( roshHaShanah + 22 )           /* @@ */
#define erevPassover(y)         ( passoverday  - 1 )            /* @@ */
#define yomHaShoah(y)           ( passoverday  + 12 )           /* @@ */
#define lagBaOmer(y)            ( passoverday  + 33 )           /* @@ */
#define yomYerushalim(y)        ( passoverday  + 43 )           /* @@ */
#define erevShavuot(y)          ( passoverday  + 49 )           /* @@ */
#define shavuot(y)              ( passoverday  + 50 )           /* @@ */
#define hebrewPentecost(y)      ( passoverday  + 51 )
#define shavuot2(y)             ( passoverday  + 51 )           /* @@ */

#define KINOE           0
#define KINOTO          1
#define HINOE           2
#define HINOTO          3
#define TSUCHINOE       4
#define TSUCHINOTO      5
#define KANOE           6
#define KANOTO          7
#define MIZUNOE         8
#define MIZUNOTO        9

#define NEE             0
#define USHI            1
#define TORA            2
#define UU              3
#define TATSU           4
#define MEE             5
#define UMA             6
#define HITSUJI         7
#define SARU            8
#define TORI            9
#define IMU             10
#define WII             11

#define setsubun(y)             ( risshunday  -   1 )
#define hachijuHachiYa(y)       ( risshunday  +  87 )
#define nihyakuTohKa(y)         ( risshunday  + 209 )
#define nihyakuHatsuKa(y)       ( risshunday  + 219 )
#define higanInSpring(y)        ( shunbunday  -   3 )
#define higanInAutumn(y)        ( shuubunday  -   3 )

#define kan(g)                  ( ( (g) + 4 ) %  10 )
#define shi(g)                  ( ( (g) + 2 ) %  12 )

char    *
zodiac( g, year )
long    g;
int     year;
{
    register int    i;

    for ( i = 0; i < 12; i++ ) {
        if ( g < absoluteFromGregorian( z[i].dd, z[i].mm, year ) )
            break;
    }

    return ( z[( --i + 12) % 12 ].sign );
    }

char    *
zodiac13( g, year )
long    g;
int     year;
{
    register int    i;

    for ( i = 0; i < 13; i++ ) {
        if ( g < absoluteFromGregorian( z13[i].dd, z13[i].mm, year ) )
            break;
    }

    return ( z13[( --i + 13) % 13 ].sign );
}


long
seijinNoHi( year )
int     year;
{
    return ( NthKday( SECOND, MONDAY, JANUARY, year ) );
                                                /* 2nd Monday in January */
}


long
KingsBirthday( year )
int     year;
{
    return ( NthKday( THIRD, MONDAY, JANUARY, year ) );
                                                /* 3rd Monday in January */
}


long
waitangiDay( year )
int     year;
{
    return ( NthKday( FIRST, SUNDAY, FEBRUARY, year ) );
                                                /* 1st Sunday in February */
}


long
australiaDay( year )
int     year;
{
    return ( NthKday( FIRST, MONDAY, FEBRUARY, year ) );
                                                /* 1st Monday in February */
}


long
WashingtonBirthday( year )
int     year;
{
    return ( NthKday( THIRD, MONDAY, FEBRUARY, year ) );
                                                /* 3rd Monday in February */
}

long
russianDay( dd, mm, yy )
int     dd;
int     mm;
int     yy;
{
    if ( yy > 1990 )
        return ( absoluteFromGregorian( 12, JUNE, yy ) );
    else
        return ( -1 );
}


long
mothersDay( year )
int     year;
{
    return ( NthKday( SECOND, SUNDAY, MAY, year ) );
                                                /* 2nd Sunday in May */
}


long
fathersDay( year )
int     year;
{
    return ( NthKday( THIRD, SUNDAY, JUNE, year ) );
                                                /* 3rd Sunday in June */
}


long
umiNoHi( year )
int     year;
{
    return ( NthKday( THIRD, MONDAY, JULY, year ) );
                                                /* 3rd Monday in July */
}


long
keirouNoHi( year )
int     year;
{
    return ( NthKday( THIRD, MONDAY, SEPTEMBER, year ) );
                                                /* 3rd Monday in September */
}


long
taiikuNoHi( year )
int     year;
{
    return ( NthKday( SECOND, MONDAY, OCTOBER, year ) );
                                                /* 2nd Monday in October */
}

long
magoNoHi( year )
int     year;
{
    return ( NthKday( THIRD, SUNDAY, OCTOBER, year ) );
                                                /* 3rd Sunday in October */
}


#if     0
dateList        *
secretarysDay( year )
int     year;
{
    static dateList dates;
    int             i, day, month;
    long            g1, g2, *p = dates;

    for ( i = 0; i < MAXLIST; i++ )
        dates[ i ] = 0;
    for ( month = JANUARY, i = 0; month <= DECEMBER; month++ ) {
        day = lastDayOfGregorianMonth( month, year );
        g1  = absoluteFromGregorian( day, month, year );
        g2  = NthKday( LAST, SATURDAY, month, year );
                                        /* last Saturday in month */
        if ( g1 == g2 )
            dates[ i++ ] = g1 - 3;
                                        /* last Wednesday in month */
    }

    return ( ( dateList *)p );
}
#endif


void
checkDateList( g, dates, s )
long    g;
long    *dates;
char    *s;
{
    while ( *dates ) {
        if ( g == *dates++ ) {
            printf( "  %s", s );
            break;
        }
    }
}


void
checkJapanese( g, dd, mm, yy )
long    g;
int     dd, mm, yy;
{
    register int    i = 0;

    if ( ( mm == FEBRUARY ) || ( mm == MARCH )     ||
         ( mm == MAY )      || ( mm == SEPTEMBER )    )
        risshunday = springStartDay( yy );
    if ( mm == MARCH )
        shunbunday = midSpringDay( yy );
    if ( ( mm == JULY ) || ( mm == AUGUST ) ) {
        geshiday   = midSummerDay( yy );
        risshuuday = autumnStartDay( yy );
    }
    if ( mm == SEPTEMBER )
        shuubunday = midAutumnDay( yy );

    if ( mm == JANUARY ) {
        if ( dd == 7 )
            printf( "  �l��  ����" );
        if ( dd == 11 )
            printf( "  ���J��" );
        if ( yy >= 2000 ) {     /* ����12�N���� */
            if ( g == seijinNoHi( yy ) )
                printf( "  ���l�̓�" );
        }
    }
    if ( mm == FEBRUARY ) {
        if ( g == setsubun( yy ) )
            printf( "  �ߕ�" );
        if ( shi( g ) == UMA ) {
            if ( g <= absoluteFromGregorian( 12, 2, yy ) )
                printf( "  ����" );
            else if ( g <= absoluteFromGregorian( 24, 2, yy ) )
                printf( "  ��̌�" );
        }
        if ( (((dd >= 6)  && (dd <= 11))   ||
              ((dd == 5)  && (yy >= 2002)) ||
              ((dd == 12) && (g % 7 == MONDAY) && (yy >= 1973))) &&
             (yy >= 1950) ) {
            printf( "  ��%d�񂳂��ۂ��Ղ�", yy - 1949 );
                /* �ʏ�� 2��6������11���܂ł��u��Ղ�v�����A12��  */
                /* ���U�֋x���ɂȂ����ꍇ�́A12���܂ł��u��Ղ�v�� */
                /* ���ԂƂȂ�                                       */
                /* �ǋL: ��53��(2002�N)����2��5���J�n�ɂȂ���       */
        }
        if ( dd ==  7 )
            printf( "  �k���̓y�̓�" );
        if ( dd == 14 )
            printf( "  �o�����^�C���f�[" );
        if ( yy >= 1998 ) {     /* ����10�N���� */
            if ( dd == 20 )
                printf( "  �����̓�" );
        }
        if ( yy >= 1989 ) {     /* �������N���� */
            if ( dd == 23 )
                printf( "  �c���q�a����" );
        }
        if ( ( yy > 1996 ) && ( dd == 27 ) )
            printf( "  �|�P�b�g�����X�^�[%d���N", yy - 1996 );
        if ( dd == 28 )
            printf( "  �r�X�P�b�g�̓�" );
    }
    if ( mm == MARCH ) {
        if ( dd == 3 )
            printf( "  �㖤�̐ߋ�(�ЂȍՂ�)" );
        if ( dd == 14 )
            printf( "  �z���C�g�f�[" );
        if ( g == shunbunday ) {
            if ( ( yy >= 1878 ) && ( yy <= 1945 ) )
                printf( "  �t�G�c���" );
            else
                printf( "  �t���̓�" );
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shunbunday ) < 5 ) ||
               ( shunbunday - g == 5 )          )    ) 
            printf( "  �Г�" );
    }
    if ( mm == APRIL ) {
        if ( dd == 8 )
            printf( "  ������ �Ԃ܂�" );
        /* �鏑�̓�
         *  4���̈�ԍŌ�� 7���ԑ������T�̐��j��
         *  (�܂�A�ŏI�y�j�� 3���O)
         */
        if ( g == secretarysDay( yy ) )
            printf( "  �鏑�̓�" );
    }
    if ( mm == MAY ) {
        if ( dd == 5 )
            printf( "  �[�߂̐ߋ�" );
        if ( g == hachijuHachiYa( yy ) )
            printf( "  ���\����" );
        if ( g == mothersDay( yy ) )
            printf( "  ��̓�" );
    }
    if ( mm == JUNE ) {
        if ( g == fathersDay( yy ) )
            printf( "  ���̓�" );
        if ( (yy >= 2000) &&
             ( g == NthKday( FIRST, MONDAY, JUNE, yy ) ) )
            printf( "  ��Ȃ̓�" ); /* 6���̑�1���j�� (2000�N�`) */
        if ( (yy >= 2000) && (dd == 26) ) {
            printf( "  ���ۖ��򗐗p�o�Ńf�[" );
        }
    }
    if ( mm == JULY ) {
        if ( dd == 7 )
            printf( "  ���[" );
        if ( dd == 15 )
            printf( "  �~" );
        if ( yy >= 2003 ) {     /* ����15�N���� */
            if ( g == umiNoHi( yy ) )
                printf( "  �C�̓�" );
        }
    }
    if ( ( mm == JULY ) || ( mm == AUGUST ) ) {
        if ( kan( g ) == KANOE ) {
            if ( ( g >= geshiday + 20 ) && ( g < geshiday + 30 ) )
                printf( "  ����" );
            if ( ( g >= geshiday + 30 ) && ( g < geshiday + 40 ) )
                printf( "  ����" );
            if ( ( g >= risshuuday ) && ( g < risshuuday + 10 ) )
                printf( "  ����" );
        }
    }
    if ( mm == AUGUST ) {
        if ( dd == 1 )
            printf( "  ����" );
        if ( dd == 15 )
            printf( "  ���x��~" );
    }
    if ( mm == SEPTEMBER ) {
        if ( g == nihyakuTohKa( yy ) )
            printf( "  ��S�\��" );
        if ( g == nihyakuHatsuKa( yy ) )
            printf( "  ��S��\��" );
        if ( dd == 9 )
            printf( "  �e�̐ߋ�(�d�z)" );
        if ( g == shuubunday ) {
            if ( ( yy >= 1878 ) && ( yy < 1945 ) )
                printf( "  �H�G�c���" );
            else
                printf( "  �H���̓�" );
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shuubunday ) < 5 ) ||
               ( shuubunday - g == 5 )          )    ) 
            printf( "  �Г�" );
        if ( yy >= 2003 ) {     /* ����15�N���� */
            if ( g == keirouNoHi( yy ) )
                printf( "  �h�V�̓�" ); /* �j�� */
            if ( dd == 15 )
                printf( "  �V�l�̓�" ); /* ���� */
        }
    }
    if ( mm == OCTOBER ) {
        if ( dd == 1 )
            printf( "  �������" );
        if ( dd == 16 )
            printf( "  �{�X�̓�" );
        if ( yy >= 1999 ) {     /* ����11�N���� */
            if ( g == magoNoHi( yy ) )
                printf( "  ���̓�" );
        }
        if ( g == magoNoHi( yy ) )
            printf( "  �h�V�̓�(����)" );
        if ( yy >= 2000 ) {     /* ����12�N���� */
            if ( g == taiikuNoHi( yy ) )
                printf( "  �̈�̓�" );
        }
    }
    if ( mm == NOVEMBER ) {
        if ( dd == 7 )
            printf( "  �\�A�v���L�O��" );
        if ( dd == 9 )
            printf( "  ���C�̓�" );
    }

    if ( ( mm % 3 == 0 ) && ( dd == 1 ) && ( yy >= 1956 ) )
        printf( "  �f��̓�" ); /* 1956�N�` */
    if ( ( ( mm == MARCH )     && ( g == higanInSpring( yy ) ) ) ||
         ( ( mm == SEPTEMBER ) && ( g == higanInAutumn( yy ) ) )    )
        printf( "  �ފ݂̓���" );
    if ( ( ( mm == JUNE )     && ( dd == 30 ) ) ||
         ( ( mm == DECEMBER ) && ( dd == 31 ) )    )
        printf( "  ���P" );

    if ( ( yy >= 1973 ) && ( g % 7 == MONDAY )               &&
         ( ((mm == MARCH)     && (g - 1 == shunbunday)) ||
           ((mm == SEPTEMBER) && (g - 1 == shuubunday))    )    ) {
        printf( "  �U�֋x��" );
    }

    while( h[i].name ) {
        if ( h[i].mm > mm )
            break;
        if ( h[i].mm == mm ) {
            /* 5��4����                                                     */
            /*     ���j�Əd�Ȃ����ꍇ�́A                                   */
            /*       �����̓��j�ɂȂ�(�����̋x���ɂ͂Ȃ�Ȃ�)               */
            /*     ���j�Əd�Ȃ����ꍇ�́A                                   */
            /*       �����̐U�֋x���ɂȂ�(�����̋x���ɂ͂Ȃ�Ȃ�)           */
            /*   ���m�ɂ́A�u���̓��̑O���Ɨ����������̋x���ł���ꍇ�A���� */
            /*   ���������ł���΁A���̓��������̋x���Ƃ���v�B���j����ѐU */
            /*   �֋x���͕����ł͂Ȃ��̂ŁA���Y�����Ηj��������j���̂��Â� */
            /*   ���ł���ꍇ�̂݁A�����̋x���ƂȂ� (���ʓI�ɂ́A�j���Ɋ֌W */
            /*   �Ȃ��x�݂̓��ɂȂ�)   �����_�ł́u���̓��v��5��4�������Ȃ� */
            if ( h[i].dd == dd ) {
                if ( ( h[i].s_yy <= yy ) &&
                     ( h[i].e_yy >= yy )    )
                    if ( !( (yy >= 1989) && (mm == 5) && (dd == 4) &&
                            ( (g % 7 == SUNDAY) ||
                              (g % 7 == MONDAY)    )                  ) )
                        printf( "  %s", h[i].name );
            }

            /* 5��4���ȊO�́u�����̋x���v�����j�Əd�Ȃ����ꍇ�̗���(���j��) */
            if ( ( yy >= 1973 )        &&
                 ( h[i].dd == dd - 1 ) &&
                 ( h[i].s_yy <= yy )   &&
                 ( h[i].e_yy >= yy )   &&
                 ( g % 7 == MONDAY )      ) {
                if ( (mm != 5) || (dd != 5) )
                    printf( "  �U�֋x��" );
            }
        }

        /* �O�����O�����ŏj�������j���̏ꍇ     */
        /*   (�����_�ł́A�Y��������͑��݂��Ȃ�) */
        if ( ( yy >= 1973 ) && ( dd == 1 ) && ( g % 7 == MONDAY )  &&
             ( h[i].mm == mm - 1 )                                 &&
             ( h[i].dd == lastDayOfGregorianMonth( h[i].mm, yy ) )    )
            printf( "  �U�֋x��" );

        i++;
    }                               /* �U�֋x���͏��a48�N������{ */
    /* 5��4�����Ηj�`�y�j�̏ꍇ�A�����̋x���A */
    /*         ���j�̏ꍇ�A      �ʏ�̓��j�A */
    /*         ���j�̏ꍇ�A      �U�֋x��     */
    /* �ƂȂ�(�������N�ȍ~)                   */
}


void
checkAmerican( g, dd, mm, yy, htmlMode )
long    g;
int     dd, mm, yy, htmlMode;
{
    register int    i = 0;
    int             length = 41;

#if     0
    if ( dd == 1 )
        if ( mm % 3 == 1 )
            printf( "  quater day [��]" );
#endif
    if ( mm == JANUARY ) {
        if ( ( yy >= 1986 ) && ( g == KingsBirthday( yy ) ) )
            printf("  �L���O�L�O�j��(Martin Luther King Day)[��]");
        if ( ( yy > 1934 ) && ( yy % 4 == 0 ) && ( dd == 20 ) )
            printf( "  �哝�̏A�C��(Inauguration Day)[��]");
    }
    if ( mm == FEBRUARY ) {
        if ( g == waitangiDay( yy ) )
            printf( "  Waitangi Day [New Zealand]" );
        if ( g == australiaDay( yy ) )
            printf( "  Australia Day [Vic,WA,SA,Tas Aust]" );
        if ( g == WashingtonBirthday( yy ) )
            printf( "  President's Day [��]" );
        if ( g == daylightSavingsEndInBrazil( yy ) )
            printf( "  �Ď��ԏI�� [�u���W��]" );
    }
    if ( ( mm >= FEBRUARY ) && ( mm <= JUNE ) ) {
        easterday = easter( yy );
        /*
         *      Easter �̓��t�Ɉˑ����Ė��N�ς��j�Փ�
         */
        if ( g == septuagestima( yy ) )
            printf( "  Septuagestima" );
        if ( g == sexagesima( yy ) )        /* @@ */
            printf( "  Sexagesima" );       /* @@ */
        if ( g == quinquagesima( yy ) )
            printf( "  Quinquagesima" );
        if ( g == shroveMonday( yy ) )      /* @@ */
            printf( "  Shrove Monday" );    /* @@ */
        if ( g == quadragesima( yy ) )
            printf( "  Quadragesima" );
        if ( g == mardiGras( yy ) )
#if     0
            printf( "  Mardi Gras, Shrove Tuesday, Pancake Day" );
#else
            printf( "  Mardi Gras" );
#endif
        if ( ( g >= ashWednesday( yy ) ) && ( g < easterday ) &&
             ( g % 7 != SUNDAY ) )
            printf( "  Lent" );
        if ( g == ashWednesday( yy ) )
            printf( "  Ash Wednesday" );
        if ( g == britishMothersDay( yy ) )
            printf( "  ��̓� [�p]" );
        if ( g == passionSunday( yy ) )
            printf( "  Passion Sunday" );
        if ( g == palmSunday( yy ) )
            printf( "  Palm Sunday" );
        if ( g == holyThursday( yy ) )
            printf( "  Holy Thursday, Maundy Thursday" );
        if ( g == goodFriday( yy ) )
            printf( "  Good Friday" );
        if ( g == holySaturday( yy ) )
            printf( "  Holy Saturday" );
        if ( g == easterMonday( yy ) )
            printf( "  Easter Monday" );
        if ( g == easterday )
            printf( "  ������(Easter)" );
        if ( g == lowSunday( yy ) )
            printf( "  Low Sunday" );
        if ( g == pentecost( yy ) )
            printf( "  Pentecost" );
        if ( g == rogationSunay( yy ) )     /* @@ */
            printf( "  Rogation Sunday" );  /* @@ */
        if ( ( g >= rogationDay( yy )  ) &&
             ( g <  ascensionDay( yy ) )    )
            printf( "  Rogation Day" );
        if ( g == ascensionDay( yy ) )
            printf( "  Ascension Day" );
        if ( g == whitsunday( yy ) )
            printf( "  Whitsunday" );
        if ( g == whitmonday( yy ) )
            printf( "  Whitmonday" );
        if ( g == trinity( yy ) )
            printf( "  Trinity" );
        if ( g == corpusChristiDay( yy ) )
            printf( "  Corpus Christi Day" );
    }
    if ( mm == MARCH ) {
        if ( ( yy <= 1934 ) && ( yy % 4 == 0 ) && ( dd == 4 ) )
            printf( "  �哝�̏A�C��(Inauguration Day)[��]");
        if ( dd == 8 )
            printf( "  ���ۏ����f�[" );
        if ( (yy >= 2007) && (g == daylightSavingsStart( yy )) )
            printf( "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsStartInEurope( yy ) )
            printf( "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsEndInAustralia( yy ) )
            printf( "  �Ď��ԏI�� [��]" );
        if ( g == daylightSavingsEndInNewZealand( yy ) )
            printf( "  �Ď��ԏI�� [�j���[�W�[�����h]" );
    }
    if ( mm == APRIL ) {
        if ( (yy <= 2006) && (g == daylightSavingsStart( yy )) )
            printf( "  �Ď��ԊJ�n [��]" );
    }
    if ( mm == MAY ) {
        if ( g == memorialDay( yy ) )
            printf( "%sMemorial Day [��]", htmlMode ? "�E" : "  ");
        if ( ( g == NthKday( FIRST, MONDAY, MAY, yy ) ) ||
             ( g == NthKday( LAST,  MONDAY, MAY, yy ) )    )
        printf( "%sbank holiday [�p]", htmlMode ? "�E" : "  ");
    }
    if ( mm == JUNE ) {
        if ( g == NthKday( FIRST, WEDNESDAY, JUNE, yy ) )
            printf( "  Derby Day [�p]" );
        if ( g == russianDay( dd, mm, yy ) )
            printf( "  ���V�A�̓�" );
    }
    if ( mm == AUGUST ) {
        if ( g == NthKday( FIRST, MONDAY, AUGUST, yy ) )
            printf( "  bank holiday [Scotland]" );
        if ( g == NthKday( LAST,  MONDAY, AUGUST, yy ) )
            printf( "  bank holiday [England, Wales]" );
        if ( g == NthKday( FOURTH, MONDAY, AUGUST, yy ) )
            printf( "  Hurricane Supplication Day [the Virgin Islands]" );
    }
    if ( mm == SEPTEMBER ) {
        if ( g == laborDay( yy ) )
            printf( "  Labor Day" );
        if ( g == harvestMoon( yy ) )
            printf( "  Harvest Moon" );
    }
    if ( mm == OCTOBER ) {
        if ( (yy <= 2006) && (g == daylightSavingsEnd( yy )) )
            printf( "  �Ď��ԏI�� [��]" );
        if ( g == daylightSavingsEndInEurope( yy ) )
            printf( "  �Ď��ԏI�� [��]" );
        if ( g == columbusDay( yy ) )
            printf( "  �R�����u�X�L�O��(Columbus Day)" );
        if ( g == huntersMoon( yy ) )
            printf( "  Hunter's Moon" );
        if ( g == daylightSavingsStartInAustralia( yy ) )
            printf( "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsStartInNewZealand( yy ) )
            printf( "  �Ď��ԊJ�n [�j���[�W�[�����h]" );
        if ( g == daylightSavingsStartInBrazil( yy ) )
            printf( "  �Ď��ԊJ�n [�u���W��]" );
    }
    if ( mm == NOVEMBER ) {
        if ( (yy >= 2007) && (g == daylightSavingsEnd( yy )) )
            printf( "  �Ď��ԏI�� [��]" );
        if ( ( yy % 4 == 2 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            printf( "  General Election Day [��]" );
            length += strlen( "  General Election Day [��]" );
        }
        if ( ( yy % 4 == 0 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            printf( "  Election Day [��]" );
            length += strlen( "  Election Day [��]" );
        }
        if ( g == loadMayorDay( yy ) ) {
            printf( "  �����h���s���A�C�� [�p]" );
            length += strlen( "  �����h���s���A�C�� [�p]" );
        }
        if ( g == rememberanceDay( yy ) ) {
            printf( "  Rememberance Day [�p]" );
            length += strlen( "  Rememberance Day [�p]" );
        }
        if ( g == thanksGivingDay( yy ) ) {
            printf( "  ���Ӎ�(Thanks Giving Day) [��]" );
            length += strlen( "  ���Ӎ�(Thanks Giving Day) [��]" );
        }
        if ( g == thanksGivingDay( yy ) + 1L ) {
            printf( "  day after Thanksgiving [��]" );
            length += strlen( "  day after Thanksgiving [��]" );
        }
    }
    if ( ( ( mm == NOVEMBER ) || ( mm == DECEMBER ) ) ) {
        if ( g == advent( yy ) ) {
            printf( "  Advent Sunday" );
            length += strlen( "  Advent Sunday" );
        }
        else if ( ( g > advent( yy ) )                   &&
              ( ( mm == NOVEMBER ) || ( dd <= 23 ) )    ) {
            printf( "  Advent" );
            length += strlen( "  Advent" );
        }
    }

    while( hh[i].name ) {
        if ( hh[i].mm > mm )
            break;
        if ( hh[i].mm == mm ) {
            if ( hh[i].dd == dd ) {
                if (length + (int)strlen(hh[i].name) >= 79) {
                    unsigned int    j;
                    printf( "\n                                        " );
                    length = 41;
                    for ( j = 0;
                          j < strlen(englishMonthName(mm)) + 2;
                          j++ ) {
                        putchar( ' ' );
                    }
                }
                printf( "  %s", hh[i].name );
                length += strlen( hh[i].name ) + 2;
            }
        }
        i++;
    }
}


void
checkGreek( g, d, m, y, mm, yy )
long    g;
int     d, m, y;        /* Julian date     */
int     mm;             /* Gregorian month */
int     yy;             /* Gregorian year  */
{
    int     _d, _m, _y;

    if ( g == nicaeanRuleEaster( yy ) )
        printf( "  Nicaean Rule Easter" );
#if     0
    checkDateList( g, easternOrthodoxChristmas( yy ),
                   "Eastern Orthodox Christmas" );
#else
    if ( ( m == DECEMBER ) && ( d == 25 ) )
        printf( "  Eastern Orthodox Christmas" );
#endif
    if ( ( y >= 1743 ) && ( m == APRIL ) && ( d == 2 ) )
        printf( "  Jefferson's Birthday" );
    if ( ( m == MARCH ) && ( d == 26 ) )
        kiddushHaHamah = 1;
    if ( m == NOVEMBER ) {
        mm--;
        if ( mm <= 0 ) {
            yy--;
            mm = 12;
        }
        julianFromAbsolute( absoluteFromGregorian( 1, mm, yy ),
                            &_d, &_m, &_y );
        if ( ((_y + 1) % 4) == 0 ) {
            if ( d == 22 )
                talUmatar = 1;
        }
        else if ( d == 21 )
            talUmatar = 1;
    }
}


void
checkIslamic( g, d, m, y, yy )
long    g;
int     d, m, y;        /* Islamic date   */
int     yy;             /* Gregorian year */
{
    if ( m == 9 )
        printf( "  �f�H��" );
    if ( (m == 1) && (d == 1) )
        printf( "  Islamic New Year %d", y );
    if ( (m == 1) && (d == 10) )
        printf( "  Ashura" );
    if ( (m == 3) && (d == 12) )
        printf( "  Mulad-Al-Nabi (Mohammed's Birthday)" );
    if ( (m == 7) && (d == 26) )
        printf( "  Shab-e-Mi\'raj" );
    if ( (m == 8) && (d == 15) )
        printf( "  Shab-e-Bara\'t" );
    if ( (m == 9) && (d == 27) )
        printf( "  Shab-e Qadr" );
    if ( (m == 10) && (d == 1) )
        printf( "  Id-al-Fitr (�J�֐�)" );
    if ( (m == 12) && (d == 10) )
        printf( "  Id-al-Adha" );
}

#if 0
long
daynameOnOrBefore( dayname, date )
int     dayname;
long    date;
{
    return ( date - ((date - dayname) % 7) );
}
#else
#define daynameOnOrBefore( dayname, date )  KdayOnOrBefore( date, dayname )
#endif

void
checkHebrew( g, d, m, y, mm, yy )
long    g;
int     d, m, y;        /* Hebrew date     */
int     mm;             /* Gregorian month */
int     yy;             /* Gregorian year  */
{
    int     _yy, _mm;                                               /* @@ */
    int     hanukkahYear, __mm, __dd, __yy, ___yy;                  /* @@ */
    long    hanukkah;                                               /* @@ */

    roshHaShanah = yomKippur( yy ) - 9L;                            /* @@ */
    passoverday  = passover( yy );
    tishaBAvday  = tishaBAv( yy );                                  /* @@ */

    if ( (mm == 1) || (mm == 2) || ((mm >= 10) && (mm <= 12)) ) {   /* @@ */
        _mm = mm + 1;
        _yy = yy;
        if ( _mm > 12 ) {
            _mm = 1;
            _yy++;
        }
        hebrewFromAbsolute( absoluteFromGregorian( 
                                lastDayOfGregorianMonth( _mm, _yy ),
                                _mm, _yy ),
                            &__dd,
                            &__mm,
                            &hanukkahYear );
        hanukkah = absoluteFromHebrew( 25, 9, hanukkahYear );
        if ( g == hanukkah - 1L )
            printf( "  Erev Hanukkah" );
        if ( (g >= hanukkah) && (g <= hanukkah + 7L) )
            printf( "  Hanukkah" );
    }                                                           /* @@ */
    if ( g == erevRoshHaShanah( yy ) )                          /* @@ */
        printf( "  Erev Rosh HaShanah" );                       /* @@ */
    if ( (g == roshHaShanah) || (g == roshHaShanah2( yy )) )    /* @@ */
        printf( "  Rosh HaShanah" );                            /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah - 4 ) ) /* @@ */
        printf( "  Selichot (night)" );                         /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah + 7 ) ) /* @@ */
        printf( "  Shabbat Shuvah" );                           /* @@ */
    if ( g == tzomGedaliah( yy ) )                              /* @@ */
        printf( "  Tzom Gedaliah" );                            /* @@ */
    if ( g == erevYomKippur( yy ) )                             /* @@ */
        printf( "  Erev Yom Kippur" );                          /* @@ */
    if ( g == yomKippur( yy ) )                                 /* @@ */
        printf( "  Yom Kippur" );
    if ( g == erevSukkot( yy ) )                                /* @@ */
        printf( "  Erev Sukkot" );                              /* @@ */
    if ( (g == sukkot( yy )) || (g == sukkot2( yy )) )          /* @@ */
        printf( "  Sukkot" );                                   /* @@ */
    if ( (g >= holHamoedSukkot( yy ) ) &&                       /* @@ */
         (g <= holHamoedSukkot4( yy ))    )                     /* @@ */
        printf( "  Hol Hamoed Sukkot" );                        /* @@ */
    if ( g == hoshannahRabbah( yy ) )                           /* @@ */
        printf( "  Hoshannah Rabbah" );                         /* @@ */
    if ( g == sheminiAtzeret( yy ) )                            /* @@ */
        printf( "  Shemini Atzeret" );                          /* @@ */
    if ( g == simchatTorah( yy ) )                              /* @@ */
        printf( "  Simchat Torah" );                            /* @@ */
    if ( g == erevPassover( yy ) )                              /* @@ */
        printf( "  Erev Passover" );                            /* @@ */
    if ( g == passoverday )
        printf( "  Passover Begins" );
    if ( ( g > passoverday ) && ( g < passoverday + 6L ) ) {
        if ( (g >= passoverday + 2L) && (g == passoverday + 5L) )
            printf( "  Hol Hamoed Passover" );
        else
            printf( "  Passover" );
    }
    if ( g == passoverday + 7L )
        printf( "  Passover Ends" );
    if ( g == yomHaShoah( yy ) )                                /* @@ */
        printf( "  YomHa Shoah" );                              /* @@ */
    if ( g == lagBaOmer( yy ) )                                 /* @@ */
        printf( "  Lag BaOmer" );                               /* @@ */
    if ( g == yomYerushalim( yy ) )                             /* @@ */
        printf( "  Yom Yerushalim" );                           /* @@ */
    if ( g == erevShavuot( yy ) )                               /* @@ */
        printf( "  Erev Shavuot" );                             /* @@ */
    if ( (g == shavuot( yy )) || (g == shavuot2( yy )) )        /* @@ */
        printf( "  Shavuot" );                                  /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 43 ) ) /* @@ */
        printf( "  Shabbat Shekalim" );                         /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 30 ) ) /* @@ */
        printf( "  Shabbat Zachor" );                           /* @@ */
    if ( g == daynameOnOrBefore(SATURDAY, passoverday-14) - 7 ) /* @@ */
        printf( "  Shabbat Parah" );                            /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 14 ) ) /* @@ */
        printf( "  Shabbat HaHodesh" );                         /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday -  1 ) ) /* @@ */
        printf( "  Shabbat HaGadol" );                          /* @@ */
#if 0   /* 'Ta Anit Esther' �Ɠ����Ȃ̂ŁA�폜 */
    if ( (((passoverday % 7) == 2) &&                           /* @@ */
          (g == passoverday - 33)     ) ||                      /* @@ */
         (g == passoverday - 31)           ) {                  /* @@ */
        printf( "  Fast of Esther" );                           /* @@ */
    }                                                           /* @@ */
#endif
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday - 28)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        printf( "  Shushan Purim" );                            /* @@ */
    }                                                           /* @@ */
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday + 18)     ) ||                      /* @@ */
         (((passoverday % 7) == 6) &&                           /* @@ */
          (g == passoverday + 20)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        printf( "  Yom HaAtzma\'ut" );                          /* @@ */
    }                                                           /* @@ */
    if ( g == tuBShvat( yy ) )
        printf( "  Tu B' Shuvat" );                             /* @@ */
                /* Tu B' Shevat ? */
                /*         ~      */
    if ( g == purim( yy ) )
        printf( "  Purim" );
    if ( g == purim( yy ) - 1 )                                 /* @@ */
        printf( "  Erev Purim" );                               /* @@ */
    if ( g == taAnitEsther( yy ) )
        printf( "  Ta Anit Esther" );
    if ( g == tishaBAvday )
        printf( "  Tisha B' Av" );
    if ( g == tishaBAvday - 21 )                                /* @@ */
        printf( "  Tzom Tammuz" );                              /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, tishaBAvday ) )      /* @@ */
        printf( "  Shabbat Hazon" );                            /* @@ */
    if ( g == tishaBAvday + 7 )                                 /* @@ */
        printf( "  Shabbat Nahamu" );                           /* @@ */

    if ( g == hebrewPentecost( yy ) )
        printf( "  Pentecost" );

    if ( kiddushHaHamah == 1 )
        printf( "  Kiddush HaHamah" );
    if ( talUmatar == 1 )                                           /* @@ */
        printf( "  Tal Umatar (evening)" );                         /* @@ */
    if ( m == 10 ) {                                                /* @@ */
        hebrewFromAbsolute( absoluteFromGregorian( 28, mm, yy ),    /* @@ */
                            &__dd, &__mm, &__yy );                  /* @@ */
        if ( (absoluteFromHebrew( 10, 10, __yy ) % 7) == 6 ) {      /* @@ */
            if ( d == 11 )                                          /* @@ */
                printf( "  Tzom Teveth" );                          /* @@ */
        }                                                           /* @@ */
        else if ( d == 10 )                                         /* @@ */
            printf( "  Tzom Teveth" );                              /* @@ */
    }
    if ( m == 11 ) {
        _mm = mm + 1;
        _yy = yy;
        if ( _mm > 12 ) {
            _mm = 1;
            _yy++;
        }
        hebrewFromAbsolute( absoluteFromGregorian( 
                                lastDayOfGregorianMonth( _mm, _yy ),
                                _mm, _yy ),
                            &__dd,
                            &__mm,
                            &__yy );
        if ( (absoluteFromHebrew( 1, 7, __yy ) % 7) == 6 ) {
            hebrewFromAbsolute( daynameOnOrBefore(
                                    SATURDAY,
                                    absoluteFromHebrew( 17, 11, __yy ) ),
                                &__dd,
                                &__mm,
                                &___yy );
        }
        else {
            hebrewFromAbsolute( daynameOnOrBefore(
                                    SATURDAY,
                                    absoluteFromHebrew( 16, 11, __yy ) ),
                                &__dd,
                                &__mm,
                                &___yy );
        }
        if ( d == __dd )
            printf( "  Shabbat Shirah" );
    }

    /* �ȉ��A2003.02.06 �ǉ� (�Q�l: hdate.lib) */
    switch ( m ) {
    case 7: /* Tishrey */
        switch ( d ) {
        case 1:
            printf( "  New year I" );
            break;
        case 2:
            printf( "  New year II" );
            break;
        case 3:
            if ( (g % 7) != SATURDAY ) {
                printf( "  Gdalya fast" );
            }
            break;
        case 4:
            if ( (g % 7) == SUNDAY ) {
                printf( "  Gdalya fast" );
            }
            break;
        case 10:
            printf( "  Day of Cipurim" );
            break;
        case 22:
            printf( "  Tora happiness" );
            break;
        }
        break;

    case 2:     /* Iyar */
        if ( yy >= 1948 ) {
            switch ( d ) {
            case 3:
            case 4:
                if ( (g % 7) == THURSDAY ) {
                    printf( "  Independence Day" );
                }
                break;
            case 5:
                if ( ((g % 7) != FRIDAY) && ((g % 7) != SATURDAY) ) {
                    printf( "  Independence Day" );
                }
                break;
            }
        }
        break;

    case 5:     /* Av */
        switch ( d ) {
        case 15:
            printf( "  Day of love" );
            break;
        }
        break;
    }
}


void
checkTsupo( g, d, m, y )
long    g;
int     d, m, y;
{
    if ( ( m == OCTOBER ) && ( d == 28 ) ) {
        if ( y > 1988 )
            printf( "  Tsuporone's BBS �J��%d���N", y - 1988 );
        else if ( y == 1988 )
            printf( "  Tsuporone's BBS �J��" );
    }
}


/*
 *      JR�̉^���v�Z�̓�����̎Z�o (1995�N12������)
 *
 *              �ʏ��: �ՎU���ƔɖZ���ȊO�̓�
 *              �ՎU��: 1��16���`2������, 6�E9�E11��, 12��1���`20�� �̊e����
 *                      �̌��j�`�ؗj (�������A�x���Ƃ��̑O���͏���)
 *              �ɖZ��: 3��21���`4��5��, 4��28���`5��6��, 7��21���`8��31��,
 *                      12��25���`1��10��
 *
 *              ���}����(�V�����̎w��ȓ��}�������܂�)
 *                      �ՎU���͒ʏ����200�~�����A�ɖZ���͒ʏ����200�~�����B
 *                      �������AJR�����{�́u�΂��v�E�u���܂����v��������
 *                      ����-�S�R�̊Ԃ̔C�ӂ̉w�����R�`-�H�c�̊Ԃ̔C�ӂ̉w�ŏ�
 *                      �~����ꍇ�́A�ՎU���͒ʏ���� 340�~�����A�ɖZ���͒ʏ�
 *                      ����340�~����
 *              �w��Ȍ�
 *                      �ՎU���ȊO�͊ՎU����200�~����(�������AJR�k�C��, JR��
 *                      �B�͒ʔN���ꗿ��)
 *              �񐔌�
 *                      4��27���`5��6��, 8��11���`20��, 12��28���`1��6���̊e��
 *                      �Ԃ́A�񐔌��𗘗p�ł��Ȃ�
 */

#define TERM_NORMAL     0
#define TERM_IDLE       1
#define TERM_BUSY       2
#define TERM_VERYBUSY   3

#ifdef  __STDC__
int     checkTermIdle( long g, int d, int m, int y )
#else
int
checkTermIdle( g, d, m, y )
long    g;
int     d, m, y;
#endif
{
    long    w = g % 7L;

    if ( ( w == 0L ) || ( w >= 5L ) )
        return ( TERM_NORMAL );
    if ( ( m == 1 ) && ( d == 16 ) && ( w == 1L ) )
        return ( TERM_NORMAL );
    if ( m == 2 ) {
        if ( ( d == 10 )                    ||
             ( d == 11 )                    ||
             ( ( d == 12 ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    if ( m == 9 ) {
        if ( ( d == 14 )                    ||
             ( d == 15 )                    ||
             ( ( d == 16 ) && ( w == 1L ) )    )
            return ( TERM_NORMAL );
        if ( ( g == shunbunday - 1L )                    ||
             ( g == shunbunday )                         ||
             ( ( g == shunbunday + 1L ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    if ( m == 11 ) {
        if ( ( d == 2 )                    ||
             ( d == 3 )                    ||
             ( ( d == 4 ) && ( w == 1L ) )    )
            return ( TERM_NORMAL );
        if ( ( d == 22 )                    ||
             ( d == 23 )                    ||
             ( ( d == 24 ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    return ( TERM_IDLE );
}

void
trainService( g, d, m, y )
long    g;
int     d, m, y;
{
    int     kind = TERM_NORMAL;

    if ( ( y <= 1988 ) || ( ( y == 1989 ) && ( m <= 3 ) ) )
        return;         /* ���̐��x�� 1989�N4��1��������{ */

    switch ( m ) {
    case  1:
        if ( d <= 6 )
            kind = TERM_VERYBUSY;
        else if ( d <= 10 )
            kind = TERM_BUSY;
        else if ( d >= 16 )
            kind = checkTermIdle( g, d, m, y );
        break;
    case  2:
    case  6:
    case  9:
    case 11:
        kind = checkTermIdle( g, d, m, y );
        break;
    case  3:
        if ( d >= 21 )
            kind = TERM_BUSY;
        break;
    case  4:
        if ( d <= 5 )
            kind = TERM_BUSY;
        else if ( d >= 27 )
            kind = TERM_VERYBUSY;
        break;
    case  5:
        if ( d <= 6 )
            kind = TERM_VERYBUSY;
        break;
    case  7:
        if ( d >= 21 )
            kind = TERM_BUSY;
        break;
    case  8:
        kind = TERM_BUSY;
        if ( ( d >= 11 ) && ( d <= 20 ) )
            kind = TERM_VERYBUSY;
        break;
    case 12:
        if ( d <= 20 )
            kind = checkTermIdle( g, d, m, y );
        else if ( d >= 28 )
            kind = TERM_VERYBUSY;
        else if ( d >= 25 )
            kind = TERM_BUSY;
        break;
    }

    printf( "\n- JR�^���v�Z�̊��� -\n" );
    switch ( kind ) {
    case TERM_NORMAL:
        printf( "�ʏ��\n" );
        break;
    case TERM_IDLE:
        printf( "�ՎU��\n" );
        printf( "    ���}�����͒ʏ����芄������܂�\n" );
        break;
    case TERM_BUSY:
    case TERM_VERYBUSY:
        if ( ( m == 4 ) && ( d == 27 ) )
            printf( "�ʏ��\n    �������A���̓��͓���Ƃ��āA" );
        else {
            printf( "�ɖZ��\n" );
            printf( "    ���}�����͒ʏ����芄������܂�\n" );
            if ( kind == TERM_VERYBUSY )
                printf( "    �܂��A" );
        }
        if ( kind == TERM_VERYBUSY )
            printf( "�V�������̉񐔌��͎g���܂���\n" );
        break;
    }

    if ( y >= 2005 ) {
        /*
         *  �t�x�� 
         *      ��������:2��20���`3��31�� 
         *      ���p����:3��1���`4��10�� 
         *  �ċx�� 
         *      ��������:7��1���`8��31�� 
         *      ���p����:7��20���`9��10�� 
         *  �~�x�� 
         *      ��������:12��1���`1��10�� 
         *      ���p����:12��10���`1��20�� 
         */
        if ( (m == 1) || (m == 2) || (m == 3) || (m == 4) || (m == 7) ||
             (m == 8) || (m == 9) || (m == 12) )
            printf( "\n- 18�ؕ��̔���/�ʗp���� -\n    " );
        if ( (m == 7) || (m == 12) ) {
            printf( "18�ؕ��������B" );
            if ( (d >= 20) || ((m == 12) && (d >= 10)) )
                printf( "18�ؕ����g���܂�\n" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͂܂��n�܂��Ă��܂���\n",
                        (m == 12) ? "�~" : "��" );
        }
        else if ( m == 1 ) {
            if ( d <= 10 )
                printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
            else if ( d <= 20 )
                printf( "�~��18�ؕ��̔������Ԃ͏I�����Ă��܂����A18�ؕ���"
                        "�g���܂�\n" );
            else
                printf( "�~��18�ؕ��̎g�p�\���Ԃ͏I�����Ă��܂�\n" );
        }
        else if ( m == 2 ) {
            if ( d >= 20 )
                printf( "18�ؕ��������B�t��18�ؕ��̎g�p�\���Ԃ͂܂��n�܂���"
                        "���܂���\n" );
            else
                printf( "�t��18�ؕ��̔����͂܂��n�܂��Ă��܂���\n" );
        }
        else if ( (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( 
                 "%s��18�ؕ��̔������Ԃ͏I�����Ă��܂����A18�ؕ��͎g���܂�\n",
                        m == 4 ? "�t" : "��" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͏I�����Ă��܂�\n",
                        m == 4 ? "�t" : "��" );
        }
        else if ( (m == 3) || (m == 8) )
            printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
    }
    else {
        if ( (m == 1) || (m == 3) || (m == 4) || (m == 7) || (m == 8) ||
             (m == 9) || (m == 12) )
            printf( "\n- 18�ؕ��̔���/�ʗp���� -\n    " );
        if ( (m == 3) || (m == 7) || (m == 12) ) {
            printf( "18�ؕ��������B" );
            if ( d >= 10 )
                printf( "18�ؕ����g���܂�\n" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͂܂��n�܂��Ă��܂���\n",
                        (m == 12) ? "�~" : (m == 3) ? "�t" : "��" );
        }
        else if ( m == 8 )
            printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
        else if ( (m == 1) || (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
            else if ( d <= 20 )
                printf(
                 "%s��18�ؕ��̔������Ԃ͏I�����Ă��܂����A18�ؕ��͎g���܂�\n",
                        (m == 1) ? "�~" : (m == 4) ? "�t" : "��" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͏I�����Ă��܂�\n",
                        (m == 1) ? "�~" : (m == 4) ? "�t" : "��" );
        }
    }
}

void
checkRoman( g, d, m, y )
long    g;
int     d, m, y;
{
    switch ( m ) {
    case MARCH:
    case MAY:
    case JULY:
    case OCTOBER:
        if ( d == 15 )
            printf( "  ides" );
        break;
    default:
        if ( d == 13 )
            printf( "  ides" );
        break;
    }
}
