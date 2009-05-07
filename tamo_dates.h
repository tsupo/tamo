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
 * 夏時間の開始、終了関連処理を変更・追加
 *
 * Revision 1.83  2006/05/29  05:11:35  tsujimura543
 * インターネット時間対応
 *
 * Revision 1.82  2003/11/11  09:11:42  tsujimura543
 * ユリウス暦、イスラム暦、ユダヤ暦の表示を最適化
 *
 * Revision 1.81  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.80  2003/05/26  07:47:50  tsujimura543
 * インド国民暦(国家暦)対応、ネパール太陰暦修正
 *
 * Revision 1.79  2003/04/11  10:58:56  tsujimura543
 * (1) インド太陰暦表示の月名に何番目の月かを併記するようにした
 * (2) ネパール太陰暦表示を追加 (暫定)
 *
 * Revision 1.78  2003/04/02  10:20:09  tsujimura543
 * エチオピア暦をサポート
 *
 * Revision 1.77  2003/03/31  05:21:49  tsujimura543
 * ヘッダファイルの依存関係を整理
 *
 * Revision 1.76  2003/03/20  09:18:02  tsujimura543
 * 各種暦注の表示を追加
 *
 * Revision 1.75  2003/03/19  04:46:08  tsujimura543
 * 干支の出力方式を他の暦と同じにする
 *
 * Revision 1.74  2003/03/19  03:05:48  tsujimura543
 * 旧暦関係の出力方法を他の暦と同じ方式にする
 *
 * Revision 1.73  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.72  2003/03/14  09:37:59  tsujimura543
 * 関数を整理
 *
 * Revision 1.71  2003/03/12  10:05:31  tsujimura543
 * 活動メモ対応準備 #2
 *
 * Revision 1.70  2003/03/11  02:01:03  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.69  2003/03/07  03:16:24  tsujimura543
 * ローマ暦(ユリウス暦)の ides 表示を追加
 *
 * Revision 1.68  2003/03/03  07:48:25  tsujimura543
 * インド太陰暦対応
 *
 * Revision 1.67  2003/02/28  07:30:49  tsujimura543
 * ユリウス暦の月名表示(ラテン語)を追加
 *
 * Revision 1.66  2003/02/24  10:48:05  tsujimura543
 * ネパール暦の時分秒表記に対応
 *
 * Revision 1.65  2003/02/21  05:05:20  tsujimura543
 * フランス革命暦の時刻表示をON/OFFできるようにした
 *
 * Revision 1.64  2003/02/19  07:29:36  tsujimura543
 * ネパール暦対応
 *
 * Revision 1.63  2003/02/07  04:46:02  tsujimura543
 * イスラム暦の月名を併記するようにした
 *
 * Revision 1.62  2003/02/06  09:41:58  tsujimura543
 * ユダヤ歴の祝祭日を追加
 *
 * Revision 1.61  2003/02/06  04:02:42  tsujimura543
 * today の誕生日データファイル(birthday.tbl)に対応
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.54  2001/02/02  14:46:40  tsujimura543
 * 誕生花、キャンペーン(XX週間、XX月間など)の各算出関数を追加
 * 
 * Revision 1.53  2000/08/23  10:57:41  tsujimura543
 * ヨーロッパでの夏時間の開始日算出関数を追加
 * 
 * Revision 1.52  2000/06/06  17:57:36  tsujimura543
 * 13星座の算出関数を追加
 * 
 * Revision 1.51  1999/07/13  11:59:21  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1996/08/19  02:07:54  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.9  95/12/03 11:48:16  tsujimura
 * コメントの整理・修正
 * 
 * Revision 1.8  95/12/02 23:30:48  tsujimura
 * JRの料金計算の特例日算出関数 trainService() のプロトタイプ宣言を追加
 * 
 * Revision 1.7  95/12/02 15:13:22  tsujimura
 * フランス革命暦算出関数 fdate() のプロトタイプ宣言を追加
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
#define __tamo_dates_h__        /* 二重include防止用 */

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

/* ユーティリティ関数 */
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

/* 24節気、旧暦 */
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

/* 和暦 */
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

/* 特別な日、祝祭日、記念日 */
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

/* 誕生日、イベント、その他 */
void        birthday _(( long, int, int, int ));
void        birthday2 _(( long, int, int, int, int ));
void        idolevent _(( long, int, int, int ));
void        comics _(( long, int, int, int ));
void        flower _(( long, int, int, int ));
void        campaign _(( long, int, int, int ));
void        trainService _(( long, int, int, int ));

/* マヤ暦 */
char        *mayaFromAbsolute _(( long ));
long        absoluteFromMaya _(( char * ));
char        *tsolkinFromAbsolute _(( long ));
char        *haabuFromAbsolute _(( long ));
char        *katunFromAbsolute _(( long ));

/* 旧暦 */
void        getLunarCalendar _(( int *, int *, int *, int * ));

/* 各暦での月の名前 */
char        *hebrewMonthName _(( int, int ));
char        *englishMonthName _(( int ));
char        *latinMonthName _(( int ));
char        *islamicMonthName _(( int ));

/* 月齢 */
double      moonPhase _(( double, int, int, int ));
double      moonPhase2 _(( int, int, int, int, int, int ));

/* フランス革命暦 */
char        *fdate _(( long, int, int, int, int, int, int, int, int ));

/* ネパール暦 */
char	    *nepdate _(( long, int, int, int, int, int, int, int ));
char        *nepaliLunarDate _(( int, int, int, int, int, int ));


/* インド太陰暦 */
char        *indianLunarDate _(( int, int, int, int, int, int ));
/* インド国家暦 */
char        *indianNationalDate _(( int, int, int ));


/* エチオピア暦 */
char        *copdate _(( long, int, int, int ));

/* Swatch インターネット時間 */
char        *beatFromAbsolute _(( int, int, int ));

#endif	/* __tamo_dates_h__ */
