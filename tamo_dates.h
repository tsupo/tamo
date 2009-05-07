/*
 *  tamo_dates.h
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      17 February 1991
 *  Copyright (c) 1991-1995,1999,2000,2001,2002,2003    Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: tamo_dates.h $
 * Revision 1.84  2007/02/08  02:44:01  tsujimura543
 * �Ď��Ԃ̊J�n�A�I���֘A������ύX�E�ǉ�
 *
 * Revision 1.83  2006/05/29  05:11:35  tsujimura543
 * �C���^�[�l�b�g���ԑΉ�
 *
 * Revision 1.82  2003/11/11  09:11:42  tsujimura543
 * �����E�X��A�C�X������A���_����̕\�����œK��
 *
 * Revision 1.81  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.80  2003/05/26  07:47:50  tsujimura543
 * �C���h������(���Ɨ�)�Ή��A�l�p�[�����A��C��
 *
 * Revision 1.79  2003/04/11  10:58:56  tsujimura543
 * (1) �C���h���A��\���̌����ɉ��Ԗڂ̌����𕹋L����悤�ɂ���
 * (2) �l�p�[�����A��\����ǉ� (�b��)
 *
 * Revision 1.78  2003/04/02  10:20:09  tsujimura543
 * �G�`�I�s�A����T�|�[�g
 *
 * Revision 1.77  2003/03/31  05:21:49  tsujimura543
 * �w�b�_�t�@�C���̈ˑ��֌W�𐮗�
 *
 * Revision 1.76  2003/03/20  09:18:02  tsujimura543
 * �e���̕\����ǉ�
 *
 * Revision 1.75  2003/03/19  04:46:08  tsujimura543
 * ���x�̏o�͕����𑼂̗�Ɠ����ɂ���
 *
 * Revision 1.74  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.73  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
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

#ifndef __tamo_dates_h__
#define __tamo_dates_h__        /* ��dinclude�h�~�p */

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

#define MAXLIST 5
typedef long    dateList[MAXLIST];

#ifdef	__STDC__
#define _(def)  def
#else
#define _(def)  ()
#endif

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
long        summerStartDay _(( int ));
long        autumnStartDay _(( int ));
long        winterStartDay _(( int ));
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
char        *junichoku _(( long, int, int, int, int *, long * ));
char        *sanrinbou _(( long, int ));
char        *manbaibi _(( long, int ));
char        *kurobi _(( long, int ));
char        *jisshinichi _(( long, int ));
char        *kikonichi _(( long, int ));
char        *fukunichi _(( long, int ));
char        *chiImiNichi _(( long, int ));
char        *tenKaNichi _(( long, int ));
char        *jiKaNichi _(( long, int ));
char        *ouMouNichi _(( long, int, long ));
char        *boSouNichi _(( long, int ));
char        *tsukiTokuNichi _(( long, int ));
char        *kuenichi _(( long, int ));

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
void        checkDateList _(( long, const long *, const char * ));
void        checkJapanese _(( long, int, int, int, int ));
void        checkAmerican _(( long, int, int, int, int, int * ));
int         checkRoman _(( char *, long, int, int, int, int, int * ));
int         checkGreek _(( char *, long, int, int, int, int, int, int,
                           int * ));
int         checkIslamic _(( char *, long, int, int, int, int, int ));
int         checkHebrew _(( char *, long, int, int, int, int, int, int ));
void        checkTsupo _(( long, int, int, int ));

void        checkKyureki _(( long, int, int, int, int, int ));
void        checkEto _(( long, int ));
void        checkTenShaNichi _(( long, int, int, int, int * ));

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
char        *nepaliLunarDate _(( int, int, int, int, int, int ));


/* �C���h���A�� */
char        *indianLunarDate _(( int, int, int, int, int, int ));
/* �C���h���Ɨ� */
char        *indianNationalDate _(( int, int, int ));


/* �G�`�I�s�A�� */
char        *copdate _(( long, int, int, int ));

/* Swatch �C���^�[�l�b�g���� */
char        *beatFromAbsolute _(( int, int, int ));

#endif	/* __tamo_dates_h__ */
