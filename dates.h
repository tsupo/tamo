/*
 *  dates.h
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      17 February 1991
 *  Copyright (c) 1991-1995,1999,2000,2001,2002,2003    Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: dates.h $
 * Revision 1.77  2007/02/08  06:41:41  tsujimura543
 * �Ď��Ԋ֘A�̏������C��
 *
 * Revision 1.76  2007/02/08  02:44:01  tsujimura543
 * �Ď��Ԃ̊J�n�A�I���֘A������ύX�E�ǉ�
 *
 * Revision 1.75  2003/03/31  05:23:50  tsujimura543
 * �w�b�_�t�@�C���̈ˑ��֌W�𐮗�
 *
 * Revision 1.74  2003/03/19  04:46:08  tsujimura543
 * ���x�̏o�͕����𑼂̗�Ɠ����ɂ���
 *
 * Revision 1.73  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.72  2003/03/14  09:37:59  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.71  2003/03/12  10:05:31  tsujimura543
 * ���������Ή����� #2
 *
 * Revision 1.70  2003/03/11  02:01:03  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.69  2003/03/07  03:16:24  tsujimura543
 * ���[�}��(�����E�X��)�� ides �\����ǉ�
 *
 * Revision 1.68  2003/03/03  07:48:25  tsujimura543
 * �C���h���A��Ή�
 *
 * Revision 1.67  2003/02/28  07:30:49  tsujimura543
 * �����E�X��̌����\��(���e����)��ǉ�
 *
 * Revision 1.66  2003/02/24  10:48:05  tsujimura543
 * �l�p�[����̎����b�\�L�ɑΉ�
 *
 * Revision 1.65  2003/02/21  05:05:20  tsujimura543
 * �t�����X�v����̎����\����ON/OFF�ł���悤�ɂ���
 *
 * Revision 1.64  2003/02/19  07:29:36  tsujimura543
 * �l�p�[����Ή�
 *
 * Revision 1.63  2003/02/07  04:46:02  tsujimura543
 * �C�X������̌����𕹋L����悤�ɂ���
 *
 * Revision 1.62  2003/02/06  09:41:58  tsujimura543
 * ���_�����̏j�Փ���ǉ�
 *
 * Revision 1.61  2003/02/06  04:02:42  tsujimura543
 * today �̒a�����f�[�^�t�@�C��(birthday.tbl)�ɑΉ�
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.54  2001/02/02  14:46:40  tsujimura543
 * �a���ԁA�L�����y�[��(XX�T�ԁAXX���ԂȂ�)�̊e�Z�o�֐���ǉ�
 * 
 * Revision 1.53  2000/08/23  10:57:41  tsujimura543
 * ���[���b�p�ł̉Ď��Ԃ̊J�n���Z�o�֐���ǉ�
 * 
 * Revision 1.52  2000/06/06  17:57:36  tsujimura543
 * 13�����̎Z�o�֐���ǉ�
 * 
 * Revision 1.51  1999/07/13  11:59:21  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1996/08/19  02:07:54  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.9  95/12/03 11:48:16  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.8  95/12/02 23:30:48  tsujimura
 * JR�̗����v�Z�̓�����Z�o�֐� trainService() �̃v���g�^�C�v�錾��ǉ�
 * 
 * Revision 1.7  95/12/02 15:13:22  tsujimura
 * �t�����X�v����Z�o�֐� fdate() �̃v���g�^�C�v�錾��ǉ�
 * 
 * Revision 1.6  92/03/29 01:03:38  tsujimura
 * test release
 * 
 * Revision 1.5  91/04/26 23:12:04  tsujimura
 * supported for information of new comics
 * 
 * Revision 1.4  91/04/08 01:12:48  tsujimura
 * test version
 * 
 * Revision 1.3  91/03/22 12:58:02  tsujimura
 * added and changed many functions
 * 
 * Revision 1.2  91/03/02 05:36:12  tsujimura
 * added many features
 * 
 * Revision 1.1  91/02/17 10:14:10  tsujimura
 * Initial revision
 * 
 */

#ifndef __dates_h__
#define __dates_h__     /* ��dinclude�h�~�p */

#ifndef TRUE
#define TRUE    1
#define FALSE   (!TRUE)
#endif
#define BOOL    int

#define ON  1
#define OFF 0

#ifndef NUL
#define NUL     '\0'
#endif

#ifndef NULL
#define NULL    ((void *)0)
#endif

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

#define MAXLIST 5
typedef long    dateList[MAXLIST];

#ifdef	__STDC__
#define _(def)  def
#else
#define _(def)  ()
#endif

#define leapyear( year )    ( ((year)%4==0) && \
                              (((year)%100!=0) || ((year)%400==0)) )

/* ���[�e�B���e�B�֐� */
int         lastDayOfGregorianMonth _(( int, int ));
long        absoluteFromGregorian _(( int, int, int ));
void        gregorianFromAbsolute _(( long, int *, int *, int * ));
long        KdayOnOrBefore _(( long, long ));
long        absoluteFromIso _(( int, int, int ));
void        isoFromAbsolute _(( long, int *, int *, int * ));
int         lastDayOfJulianMonth _(( int, int ));
long        absoluteFromJulian _(( int, int, int ));
void        julianFromAbsolute _(( long, int *, int *, int * ));
int         islamicLeapYear _(( int ));
int         lastDayOfIslamicMonth _(( int, int ));
long        absoluteFromIslamic _(( int, int, int ));
void        islamicFromAbsolute _(( long, int *, int *, int * ));
#if	0
int         hebrewLeapYear _(( int ));
int         lastMonthOfHebrewYear _(( int ));
#endif
int         lastDayOfHebrewMonth _(( int, int ));
long        hebrewCalendarElapsedDays _(( int ));
long        daysInHebrewYear _(( int ));
int         longHeshvan _(( int ));
int         shortKislev _(( int ));
long        absoluteFromHebrew _(( int, int, int ));
void        hebrewFromAbsolute _(( long, int *, int *, int * ));
#if	0
long        independenceDay _(( int ));
long        christmas _(( int ));
long        pentecost _(( int ));
dateList    *easternOrthodoxChristmas _(( int ));
#endif
long        NthKday _(( int, int, int, int ));
long        laborDay _(( int ));
long        columbusDay _(( int ));
long        loadMayorDay _(( int ));
long        memorialDay _(( int ));
long        daylightSavingsStart _(( int ));
long        daylightSavingsStartInEurope _(( int ));
long        daylightSavingsStartInAustralia _(( int ));
long        daylightSavingsStartInNewZealand _(( int ));
long        daylightSavingsStartInBrazil _(( int ));
long        daylightSavingsEnd _(( int ));
long        daylightSavingsEndInEurope _(( int ));
long        daylightSavingsEndInAustralia _(( int ));
long        daylightSavingsEndInNewZealand _(( int ));
long        daylightSavingsEndInBrazil _(( int ));
long        advent _(( int ));
long        epiphany _(( int ));
long        nicaeanRuleEaster _(( int ));
long        easter _(( int ));
long        harvestMoon _(( int ));
long        huntersMoon _(( int ));
dateList    *islamicDate _(( int, int, int ));
dateList    *muladAlNabi _(( int ));
long        yomKippur _(( int ));
long        passover _(( int ));
long        tuBShvat _(( int ));
long        purim _(( int ));
long        taAnitEsther _(( int ));
long        tishaBAv _(( int ));
long        hebrewBirthday _(( int, int, int, int ));
long        yahrzeit _(( int, int, int, int ));

void        printDateList _(( long * ));

/* 24�ߋC�A���� */
char        *get_kyureki _(( int *, int *, int *, int * ));
int         hizuke _(( long ));
void        get_sekki _(( long, int, int ));
int         get_km _(( long, int, int ));
/*
int         sun _(( long ));
*/
double      julcen _(( long ));
int         geturei _(( long ));
int         chk_uruu _(( long, int ));
long        get_jd _(( int, int, int ));
long        springStartDay _(( int ));
long        autumnStartDay _(( int ));
long        midSpringDay _(( int ));
long        midSummerDay _(( int ));
long        midAutumnDay _(( int ));
long        setsuStartDay _(( int, int ));
long        getSekkiDate _(( int, int, int ));

/* �a�� */
char        *wareki _(( int, int, int, int ));
char        *tsupodate _(( int, int, int ));
char        *kyusei _(( long ));
char        *eto _(( long, int, int ));
char        *weekday _(( long ));
char        *nijuhachishuku _(( long ));
char        *junichoku _(( long, int, int, int, int * ));
char        *sanrinbou _(( long, int ));

/* ���ʂȓ��A�j�Փ��A�L�O�� */
long        veteransDay _(( int ));
long        rememberanceDay _(( int ));
long        thanksGivingDay _(( int ));
#if	0
long        ashWednesday _(( int ));
long        passionSunday _(( int ));
long        palmSunday _(( int ));
long        holyThursday _(( int ));
long        holySaturday _(( int ));
long        easterMonday _(( int ));
long        whitsunday _(( int ));
long        britishMothersDay _(( int ));
long        hebrewPentecost _(( int ));
#endif
char        *zodiac _(( long, int ));
char        *zodiac13 _(( long, int ));
long        KingsBirthday _(( int ));
long        mothersDay _(( int ));
long        fathersDay _(( int ));
#if	0
dateList    *secretarysDay _(( int ));
#else
long        secretarysDay _(( int ));
#endif
void        checkDateList _(( long, long *, char * ));
void        checkJapanese _(( long, int, int, int ));
void        checkAmerican _(( long, int, int, int, int ));
void        checkRoman _(( long, int, int, int ));
void        checkGreek _(( long, int, int, int, int, int ));
void        checkIslamic _(( long, int, int, int, int ));
void        checkHebrew _(( long, int, int, int, int, int ));
void        checkTsupo _(( long, int, int, int ));

#ifdef  TAMO
void        checkKyureki _(( int, int, int, int, int ));
#else
void        checkKyureki _(( int, int, int, int, char *, int ));
#endif
void        checkEto _(( long j, int ));


/* �a�����A�C�x���g�A���̑� */
void        birthday _(( long, int, int, int ));
void        birthday2 _(( long, int, int, int, int ));
void        idolevent _(( long, int, int, int ));
void        comics _(( long, int, int, int ));
void        flower _(( long, int, int, int ));
void        campaign _(( long, int, int, int ));
void        trainService _(( long, int, int, int ));

/* �}���� */
char        *mayaFromAbsolute _(( long ));
long        absoluteFromMaya _(( char * ));
char        *tsolkinFromAbsolute _(( long ));
char        *haabuFromAbsolute _(( long ));
char        *katunFromAbsolute _(( long ));

/* ���� */
void        getLunarCalendar _(( int *, int *, int *, int * ));
char        *getSekkiName _(( int, int, int, int *, int * ));

/* �e��ł̌��̖��O */
char        *hebrewMonthName _(( int, int ));
char        *englishMonthName _(( int ));
char        *latinMonthName _(( int ));
char        *islamicMonthName _(( int ));

/* ���� */
double      moonPhase _(( double, int, int, int ));
double      moonPhase2 _(( int, int, int, int, int, int ));

/* �t�����X�v���� */
char        *fdate _(( long, int, int, int, int, int, int, int, int ));

/* �l�p�[���� */
char	    *nepdate _(( long, int, int, int, int, int, int, int ));

/* �C���h���A�� */
char        *indianLunarDate _(( int, int, int, int, int, int ));

#endif	/* __dates_h__ */
