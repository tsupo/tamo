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
 * 18きっぷの発売期間、通用期間を最近の状況に合わせて修正
 *
 * Revision 1.76  2007/02/08  02:44:01  tsujimura543
 * 夏時間の開始、終了関連処理を変更・追加
 *
 * Revision 1.75  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.74  2003/03/17  07:36:50  tsujimura543
 * ソース整理
 *
 * Revision 1.73  2003/03/14  09:37:59  tsujimura543
 * 関数を整理
 *
 * Revision 1.72  2003/03/11  02:09:28  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.71  2003/03/07  03:16:24  tsujimura543
 * ローマ暦(ユリウス暦)の ides 表示を追加
 *
 * Revision 1.70  2003/02/28  06:53:31  tsujimura543
 * 2002年5月6日が振替休日と表示されない不具合を修正(Rev1.69の修正ミスが原因)
 *
 * Revision 1.69  2003/02/25  06:03:55  tsujimura543
 * 2003年5月5日が振替休日と表示されてしまう不具合に対処
 *
 * Revision 1.68  2003/02/19  07:29:36  tsujimura543
 * ネパール暦対応
 *
 * Revision 1.67  2003/02/10  05:02:42  tsujimura543
 * フランス革命記念日、ドイツ統一記念日等を追加
 *
 * Revision 1.66  2003/02/07  04:47:44  tsujimura543
 * イスラム暦の祝祭日表記を若干変更
 *
 * Revision 1.65  2003/02/06  09:41:58  tsujimura543
 * ユダヤ歴の祝祭日を追加
 *
 * Revision 1.64  2003/02/05  10:08:32  tsujimura543
 * さっぽろ雪まつりの開催期間が2月5日からになったのに対応
 *
 * Revision 1.63  2001/06/15  11:11:21  tsujimura543
 * 「老人の日」対応
 *
 * Revision 1.62  2001/06/13  13:02:52  tsujimura543
 * 「ロシアの日」を追加
 *
 * Revision 1.61  2001/05/25  13:52:26  tsujimura543
 * 2003年から、海の日と敬老の日がそれぞれ7月、9月の第3月曜日になるのに対応
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.57  2001/02/05  21:57:57  tsujimura543
 * 今回が何回目の「さっぽろ雪祭り」か表示するように変更
 * 
 * Revision 1.56  2001/02/02  16:14:56  tsujimura543
 * (1) 「さっぽろ雪祭り」の表示機能を追加
 * (2) 「映画の日」の表示機能を変更(1956年以降の年のみ表示するようにした)
 * 
 * Revision 1.55  2001/01/22  22:18:34  tsujimura543
 * (1) (int)0xFFFFFFFF の値が負の値になるマシンで祝日が表示されなくなる不具合
 *     に対処
 * (2) ビスケットの日、換気の日、などの表示機能を追加
 * (3) 戦前の祝日をいくつか追加
 * (4) 13星座の算出関数を追加
 * 
 * Revision 1.54  2000/06/01  10:24:06  tsujimura543
 * 夏時間の開始日の表示用関数をアメリカとヨーロッパで別のものにした
 * 
 * Revision 1.53  2000/03/30  20:41:36  tsujimura543
 * (1) 孫の日、ボスの日の表示機能を追加
 * (2) 中国の敬老の日の表示機能を追加
 * 
 * Revision 1.52  1999/11/01  17:24:21  tsujimura543
 * 18切符の使用期間の表示を修正(改行を追加)
 * 
 * Revision 1.51  1999/07/13  12:00:36  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1998/02/06  15:37:58  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.8  95/12/03 12:03:54  tsujimura
 * コメントの整理・修正
 * 
 * Revision 1.7  95/12/03 02:32:26  tsujimura
 * trainService() の bug fix
 * 
 * Revision 1.6  95/12/03 02:12:06  tsujimura
 * JRの料金計算の特例日算出を追加
 * 
 * Revision 1.5  95/12/03 01:53:14  tsujimura
 * 日本の祝祭日を明治期以降に関して完全対応
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
} z[12] = {     "水瓶座  Aquarius",      1,     20,
                "  魚座  Pisces",        2,     19,
                "牡羊座  Aries",         3,     21,
                "牡牛座  Taurus",        4,     20,
                "双子座  Gemini",        5,     21,
                "  蟹座  Cancer",        6,     22,
                "獅子座  Leo",           7,     23,
                "乙女座  Virgo",         8,     23,
                "天秤座  Libra",         9,     23,
                "  蠍座  Scorpio",      10,     24,
                "射手座  Sagitarius",   11,     22,
                "山羊座  Capricorn",    12,     22  };

static struct ZODIAC13  {
        char    *sign;
        int     mm;
        int     dd;
} z13[13] = {   "山羊座  Capricorn",     1,     19,
                "水瓶座  Aquarius",      2,     16,
                "  魚座  Pisces",        3,     11,
                "牡羊座  Aries",         4,     19,
                "牡牛座  Taurus",        5,     14,
                "双子座  Gemini",        6,     21,
                "  蟹座  Cancer",        7,     20,
                "獅子座  Leo",           8,     11,
                "乙女座  Virgo",         9,     16,
                "天秤座  Libra",        10,     30,
                "  蠍座  Scorpio",      11,     23,
                "蛇遣座  Ophiuchus",    11,     30,
                "射手座  Sagitarius",   12,     18  };

static struct holiday {
        char    *name;  /* 祝祭日名 */
        int     mm;     /* 月       */
        int     dd;     /* 日       */
        int     s_yy;   /* 開始年   */
        int     e_yy;   /* 終了年   */
} h[] = {
        "四方拝(新年)",    1,    1,        0,   1945,
        "元日",            1,    1,     1949,   MAXINT, /* 昭和23年制定   */
        "元始祭",          1,    3,     1928,   1945,
                                /* 明治3年開始, 明治41年制定, 昭和2年公布 */
        "新年宴会",        1,    5,     1872,   1945,
        "成人の日",        1,   15,     1949,   1999,   /* 昭和23年制定   */
                              /* 成人の日は平成12年より1月第2月曜日となる */
        "紀元節",          1,   29,     1873,   1873,   /* 明治6年のみ    */
        "孝明天皇祭",      1,   31,     1872,   1912,   /* 孝明天皇崩御日 */
        "紀元節",          2,   11,     1874,   1945,   /* 神武天皇即位日 */
        "建国記念の日",    2,   11,     1967,   MAXINT, /* 昭和41年制定   */
        "地久節",          3,    6,     1827,   1945,   /* 昭和皇后誕生日 */
    /*  "春分の日",        3,   21,        0,   MAXINT, */
        "神武天皇祭",      4,    3,     1872,   1945,   /* 神武天皇崩御日 */
        "天長節",          4,   29,     1927,   1948,   /* 昭和天皇誕生日 */
        "天皇誕生日",      4,   29,     1949,   1988,   /* 昭和23年制定   */
        "みどりの日",      4,   29,     1989,   MAXINT, /* 平成元年制定   */
        "憲法記念日",      5,    3,     1949,   MAXINT, /* 昭和23年制定   */
        "国民の休日",      5,    4,     1989,   MAXINT,
        "こどもの日",      5,    5,     1949,   MAXINT, /* 昭和23年制定   */
        "地久節",          5,   28,     1874,   1912,   /* 明治皇后誕生日 */
        "地久節",          6,   25,     1913,   1926,   /* 大正皇后誕生日 */
        "海の日",          7,   20,     1996,   2002,
                             /* 海の日は平成15年より7月第3月曜日となる    */
        "明治天皇祭",      7,   30,     1912,   1926,   /* 明治天皇崩御日 */
        "天長節",          8,   31,     1912,   1912,   /* 大正天皇誕生日 */
        "としよりの日",    9,   15,     1954,   1963,
        "老人の日",        9,   15,     1964,   1965,
        "敬老の日",        9,   15,     1966,   2002,
                             /* 敬老の日は平成15年より9月第3月曜日となる  */
    /*  "秋分の日",        9,   23,        0,   MAXINT, */
        "体育の日",       10,   10,     1966,   1999,
                             /* 体育の日は平成12年より10月第2月曜日となる */
        "神嘗祭",         10,   17,     1879,   1944,
        "天長節祝日",     10,   31,     1913,   1926,   /* 大正2年～      */
        "天長節",         11,    3,     1873,   1911,   /* 明治天皇誕生日 */
                                        /* 明治元年～5年は旧暦の9月22日   */
        "明治節",         11,    3,     1927,   1945,   /* 昭和2年制定    */
        "文化の日",       11,    3,     1948,   MAXINT,
        "新嘗祭",         11,   23,     1872,   1944,
                                        /* 明治5年以前は11月第2の卯の日   */
        "勤労感謝の日",   11,   23,     1948,   MAXINT,
        "天皇誕生日",     12,   23,     1989,   MAXINT,
        "大正天皇誕生祭", 12,   25,     1927,   1944,   /* 大正天皇崩御日 */
        NULL,              0,    0,        0,   0       };

static struct holiday   hh[] = {
    "New Year's Day",                            1,      1,     0,    MAXINT,
    "quarter day [米]",                          1,      1,     0,    MAXINT,
    "12日節前夜祭(Twelfth Night)",               1,      5,     0,    MAXINT,
    "顕現日(Epiphany, Twelfth Day)",             1,      6,     0,    MAXINT,
    "Australia Day [NSW,ACT,Qld,NT Aust]",       1,     26,     0,    MAXINT,
    "共和国記念日 [インド]",                     1,     26,     0,    MAXINT,
    "聖燭節(Candlemas)",                         2,      2,     0,    MAXINT,
    "Ground Hog Day",                            2,      2,     0,    MAXINT,
    "リンカーン誕生日",                          2,     12,     0,    MAXINT,
    "St. Valentine's Day",                       2,     14,     0,    MAXINT,
    "厄払いの儀式",                              2,     15,     0,    MAXINT,
    "ワシントン誕生日",                          2,     22,     0,    MAXINT,
    "St. David's Day",                           3,      1,     0,    MAXINT,
    "St. Patrick's Day",                         3,     17,     0,    MAXINT,
    "お告げの祝日(Lady Day)",                    3,     25,     0,    MAXINT,
    "万愚節(All Fools' Day)",                    4,      1,     0,    MAXINT,
    "quarter day [米]",                          4,      1,     0,    MAXINT,
    "St. George's Day",                          4,     23,     0,    MAXINT,
    "May Day",                                   5,      1,     0,    MAXINT,
    "第2次世界大戦休戦記念日[仏]",               5,      8,  1945,    MAXINT,
    "国旗制定記念日(Flag Day)[米]",              6,     14,     0,    MAXINT,
    "洗礼者ヨハネの祭日(Midsummer Day)",         6,     24,     0,    MAXINT,
    "自治記念日(Dominion Day)[カナダ]",          7,      1,     0,    MAXINT,
    "quarter day [米]",                          7,      1,     0,    MAXINT,
    "アメリカ独立記念日(Independence Day)",      7,      4,  1776,    MAXINT,
    "Bastille Day [仏]",                         7,      4,     0,    MAXINT,
    "革命記念日[仏]",                            7,     14,     0,    MAXINT,
    "収穫祭(Lammas)",                            8,      1,     0,    MAXINT,
    "変容の祝日(Transfiguration)",               8,      6,     0,    MAXINT,
    "聖母被昇天の祝日(Assumption)",              8,     15,     0,    MAXINT,
    "聖母マリア誕生日(Nativity)",                9,      8,     0,    MAXINT,
    "ミカエル祭(Michaelmas)",                    9,     29,     0,    MAXINT,
    "quarter day [米]",                         10,      1,     0,    MAXINT,
    "統一記念日[独]",                           10,      3,     0,    MAXINT,
    "Halloween",                                10,     31,     0,    MAXINT,
    "万聖節(All Saints' Day)",                  11,      1,     0,    MAXINT,
    "万霊節(All Souls' Day)",                   11,      2,     0,    MAXINT,
    "Guy Fawkes Day",                           11,      5,     0,    MAXINT,
    "聖マルタン祭(Martinmas)",                  11,     11,     0,    MAXINT,
#ifdef  OLDFASHIONED
    "Armistice Day",                            11,     11,     0,    MAXINT,
#else
    "Veterans Day",                             11,     11,     0,    MAXINT,
#endif
    "第1次世界大戦休戦記念日[仏]",              11,     11,  1918,    MAXINT,
    "無原罪懐胎の祝日(Immaculate Conception)",  12,      8,     0,    MAXINT,
    "祖先の日(Forefathers' Day)",               12,     22,     0,    MAXINT,
    "Christmas Eve",                            12,     24,     0,    MAXINT,
    "Christmas",                                12,     25,     0,    MAXINT,
    "Boxing Day [England, Wales]",              12,     26,     0,    MAXINT,
    "無こ嬰児殉教者の祝日(Innocents's Day)",    12,     28,     0,    MAXINT,
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
            printf( "  人日  七草" );
        if ( dd == 11 )
            printf( "  鏡開き" );
        if ( yy >= 2000 ) {     /* 平成12年から */
            if ( g == seijinNoHi( yy ) )
                printf( "  成人の日" );
        }
    }
    if ( mm == FEBRUARY ) {
        if ( g == setsubun( yy ) )
            printf( "  節分" );
        if ( shi( g ) == UMA ) {
            if ( g <= absoluteFromGregorian( 12, 2, yy ) )
                printf( "  初午" );
            else if ( g <= absoluteFromGregorian( 24, 2, yy ) )
                printf( "  二の午" );
        }
        if ( (((dd >= 6)  && (dd <= 11))   ||
              ((dd == 5)  && (yy >= 2002)) ||
              ((dd == 12) && (g % 7 == MONDAY) && (yy >= 1973))) &&
             (yy >= 1950) ) {
            printf( "  第%d回さっぽろ雪祭り", yy - 1949 );
                /* 通常は 2月6日から11日までが「雪祭り」だが、12日  */
                /* が振替休日になった場合は、12日までが「雪祭り」の */
                /* 期間となる                                       */
                /* 追記: 第53回(2002年)から2月5日開始になった       */
        }
        if ( dd ==  7 )
            printf( "  北方領土の日" );
        if ( dd == 14 )
            printf( "  バレンタインデー" );
        if ( yy >= 1998 ) {     /* 平成10年から */
            if ( dd == 20 )
                printf( "  旅券の日" );
        }
        if ( yy >= 1989 ) {     /* 平成元年から */
            if ( dd == 23 )
                printf( "  皇太子誕生日" );
        }
        if ( ( yy > 1996 ) && ( dd == 27 ) )
            printf( "  ポケットモンスター%d周年", yy - 1996 );
        if ( dd == 28 )
            printf( "  ビスケットの日" );
    }
    if ( mm == MARCH ) {
        if ( dd == 3 )
            printf( "  上巳の節句(ひな祭り)" );
        if ( dd == 14 )
            printf( "  ホワイトデー" );
        if ( g == shunbunday ) {
            if ( ( yy >= 1878 ) && ( yy <= 1945 ) )
                printf( "  春季皇霊祭" );
            else
                printf( "  春分の日" );
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shunbunday ) < 5 ) ||
               ( shunbunday - g == 5 )          )    ) 
            printf( "  社日" );
    }
    if ( mm == APRIL ) {
        if ( dd == 8 )
            printf( "  潅仏会 花まつり" );
        /* 秘書の日
         *  4月の一番最後の 7日間揃った週の水曜日
         *  (つまり、最終土曜の 3日前)
         */
        if ( g == secretarysDay( yy ) )
            printf( "  秘書の日" );
    }
    if ( mm == MAY ) {
        if ( dd == 5 )
            printf( "  端午の節句" );
        if ( g == hachijuHachiYa( yy ) )
            printf( "  八十八夜" );
        if ( g == mothersDay( yy ) )
            printf( "  母の日" );
    }
    if ( mm == JUNE ) {
        if ( g == fathersDay( yy ) )
            printf( "  父の日" );
        if ( (yy >= 2000) &&
             ( g == NthKday( FIRST, MONDAY, JUNE, yy ) ) )
            printf( "  寄席の日" ); /* 6月の第1月曜日 (2000年～) */
        if ( (yy >= 2000) && (dd == 26) ) {
            printf( "  国際麻薬乱用撲滅デー" );
        }
    }
    if ( mm == JULY ) {
        if ( dd == 7 )
            printf( "  七夕" );
        if ( dd == 15 )
            printf( "  盆" );
        if ( yy >= 2003 ) {     /* 平成15年から */
            if ( g == umiNoHi( yy ) )
                printf( "  海の日" );
        }
    }
    if ( ( mm == JULY ) || ( mm == AUGUST ) ) {
        if ( kan( g ) == KANOE ) {
            if ( ( g >= geshiday + 20 ) && ( g < geshiday + 30 ) )
                printf( "  初伏" );
            if ( ( g >= geshiday + 30 ) && ( g < geshiday + 40 ) )
                printf( "  中伏" );
            if ( ( g >= risshuuday ) && ( g < risshuuday + 10 ) )
                printf( "  末伏" );
        }
    }
    if ( mm == AUGUST ) {
        if ( dd == 1 )
            printf( "  八朔" );
        if ( dd == 15 )
            printf( "  月遅れ盆" );
    }
    if ( mm == SEPTEMBER ) {
        if ( g == nihyakuTohKa( yy ) )
            printf( "  二百十日" );
        if ( g == nihyakuHatsuKa( yy ) )
            printf( "  二百二十日" );
        if ( dd == 9 )
            printf( "  菊の節句(重陽)" );
        if ( g == shuubunday ) {
            if ( ( yy >= 1878 ) && ( yy < 1945 ) )
                printf( "  秋季皇霊祭" );
            else
                printf( "  秋分の日" );
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shuubunday ) < 5 ) ||
               ( shuubunday - g == 5 )          )    ) 
            printf( "  社日" );
        if ( yy >= 2003 ) {     /* 平成15年から */
            if ( g == keirouNoHi( yy ) )
                printf( "  敬老の日" ); /* 祝日 */
            if ( dd == 15 )
                printf( "  老人の日" ); /* 平日 */
        }
    }
    if ( mm == OCTOBER ) {
        if ( dd == 1 )
            printf( "  共同募金" );
        if ( dd == 16 )
            printf( "  ボスの日" );
        if ( yy >= 1999 ) {     /* 平成11年から */
            if ( g == magoNoHi( yy ) )
                printf( "  孫の日" );
        }
        if ( g == magoNoHi( yy ) )
            printf( "  敬老の日(中国)" );
        if ( yy >= 2000 ) {     /* 平成12年から */
            if ( g == taiikuNoHi( yy ) )
                printf( "  体育の日" );
        }
    }
    if ( mm == NOVEMBER ) {
        if ( dd == 7 )
            printf( "  ソ連革命記念日" );
        if ( dd == 9 )
            printf( "  換気の日" );
    }

    if ( ( mm % 3 == 0 ) && ( dd == 1 ) && ( yy >= 1956 ) )
        printf( "  映画の日" ); /* 1956年～ */
    if ( ( ( mm == MARCH )     && ( g == higanInSpring( yy ) ) ) ||
         ( ( mm == SEPTEMBER ) && ( g == higanInAutumn( yy ) ) )    )
        printf( "  彼岸の入り" );
    if ( ( ( mm == JUNE )     && ( dd == 30 ) ) ||
         ( ( mm == DECEMBER ) && ( dd == 31 ) )    )
        printf( "  大祓" );

    if ( ( yy >= 1973 ) && ( g % 7 == MONDAY )               &&
         ( ((mm == MARCH)     && (g - 1 == shunbunday)) ||
           ((mm == SEPTEMBER) && (g - 1 == shuubunday))    )    ) {
        printf( "  振替休日" );
    }

    while( h[i].name ) {
        if ( h[i].mm > mm )
            break;
        if ( h[i].mm == mm ) {
            /* 5月4日が                                                     */
            /*     日曜と重なった場合は、                                   */
            /*       ただの日曜になる(国民の休日にはならない)               */
            /*     月曜と重なった場合は、                                   */
            /*       ただの振替休日になる(国民の休日にはならない)           */
            /*   正確には、「その日の前日と翌日が国民の休日である場合、その */
            /*   日が平日であれば、その日も国民の休日とする」。日曜および振 */
            /*   替休日は平日ではないので、当該日が火曜日から金曜日のいづれ */
            /*   かである場合のみ、国民の休日となる (結果的には、曜日に関係 */
            /*   なく休みの日になる)   現時点では「その日」は5月4日しかない */
            if ( h[i].dd == dd ) {
                if ( ( h[i].s_yy <= yy ) &&
                     ( h[i].e_yy >= yy )    )
                    if ( !( (yy >= 1989) && (mm == 5) && (dd == 4) &&
                            ( (g % 7 == SUNDAY) ||
                              (g % 7 == MONDAY)    )                  ) )
                        printf( "  %s", h[i].name );
            }

            /* 5月4日以外の「国民の休日」が日曜と重なった場合の翌日(月曜日) */
            if ( ( yy >= 1973 )        &&
                 ( h[i].dd == dd - 1 ) &&
                 ( h[i].s_yy <= yy )   &&
                 ( h[i].e_yy >= yy )   &&
                 ( g % 7 == MONDAY )      ) {
                if ( (mm != 5) || (dd != 5) )
                    printf( "  振替休日" );
            }
        }

        /* 前日が前月末で祝日かつ日曜日の場合     */
        /*   (現時点では、該当する日は存在しない) */
        if ( ( yy >= 1973 ) && ( dd == 1 ) && ( g % 7 == MONDAY )  &&
             ( h[i].mm == mm - 1 )                                 &&
             ( h[i].dd == lastDayOfGregorianMonth( h[i].mm, yy ) )    )
            printf( "  振替休日" );

        i++;
    }                               /* 振替休日は昭和48年から実施 */
    /* 5月4日が火曜～土曜の場合、国民の休日、 */
    /*         日曜の場合、      通常の日曜、 */
    /*         月曜の場合、      振替休日     */
    /* となる(平成元年以降)                   */
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
            printf( "  quater day [米]" );
#endif
    if ( mm == JANUARY ) {
        if ( ( yy >= 1986 ) && ( g == KingsBirthday( yy ) ) )
            printf("  キング記念祝日(Martin Luther King Day)[米]");
        if ( ( yy > 1934 ) && ( yy % 4 == 0 ) && ( dd == 20 ) )
            printf( "  大統領就任式(Inauguration Day)[米]");
    }
    if ( mm == FEBRUARY ) {
        if ( g == waitangiDay( yy ) )
            printf( "  Waitangi Day [New Zealand]" );
        if ( g == australiaDay( yy ) )
            printf( "  Australia Day [Vic,WA,SA,Tas Aust]" );
        if ( g == WashingtonBirthday( yy ) )
            printf( "  President's Day [米]" );
        if ( g == daylightSavingsEndInBrazil( yy ) )
            printf( "  夏時間終了 [ブラジル]" );
    }
    if ( ( mm >= FEBRUARY ) && ( mm <= JUNE ) ) {
        easterday = easter( yy );
        /*
         *      Easter の日付に依存して毎年変わる祝祭日
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
            printf( "  母の日 [英]" );
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
            printf( "  復活祭(Easter)" );
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
            printf( "  大統領就任式(Inauguration Day)[米]");
        if ( dd == 8 )
            printf( "  国際女性デー" );
        if ( (yy >= 2007) && (g == daylightSavingsStart( yy )) )
            printf( "  夏時間開始 [米]" );
        if ( g == daylightSavingsStartInEurope( yy ) )
            printf( "  夏時間開始 [欧]" );
        if ( g == daylightSavingsEndInAustralia( yy ) )
            printf( "  夏時間終了 [豪]" );
        if ( g == daylightSavingsEndInNewZealand( yy ) )
            printf( "  夏時間終了 [ニュージーランド]" );
    }
    if ( mm == APRIL ) {
        if ( (yy <= 2006) && (g == daylightSavingsStart( yy )) )
            printf( "  夏時間開始 [米]" );
    }
    if ( mm == MAY ) {
        if ( g == memorialDay( yy ) )
            printf( "%sMemorial Day [米]", htmlMode ? "・" : "  ");
        if ( ( g == NthKday( FIRST, MONDAY, MAY, yy ) ) ||
             ( g == NthKday( LAST,  MONDAY, MAY, yy ) )    )
        printf( "%sbank holiday [英]", htmlMode ? "・" : "  ");
    }
    if ( mm == JUNE ) {
        if ( g == NthKday( FIRST, WEDNESDAY, JUNE, yy ) )
            printf( "  Derby Day [英]" );
        if ( g == russianDay( dd, mm, yy ) )
            printf( "  ロシアの日" );
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
            printf( "  夏時間終了 [米]" );
        if ( g == daylightSavingsEndInEurope( yy ) )
            printf( "  夏時間終了 [欧]" );
        if ( g == columbusDay( yy ) )
            printf( "  コロンブス記念日(Columbus Day)" );
        if ( g == huntersMoon( yy ) )
            printf( "  Hunter's Moon" );
        if ( g == daylightSavingsStartInAustralia( yy ) )
            printf( "  夏時間開始 [豪]" );
        if ( g == daylightSavingsStartInNewZealand( yy ) )
            printf( "  夏時間開始 [ニュージーランド]" );
        if ( g == daylightSavingsStartInBrazil( yy ) )
            printf( "  夏時間開始 [ブラジル]" );
    }
    if ( mm == NOVEMBER ) {
        if ( (yy >= 2007) && (g == daylightSavingsEnd( yy )) )
            printf( "  夏時間終了 [米]" );
        if ( ( yy % 4 == 2 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            printf( "  General Election Day [米]" );
            length += strlen( "  General Election Day [米]" );
        }
        if ( ( yy % 4 == 0 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            printf( "  Election Day [米]" );
            length += strlen( "  Election Day [米]" );
        }
        if ( g == loadMayorDay( yy ) ) {
            printf( "  ロンドン市長就任式 [英]" );
            length += strlen( "  ロンドン市長就任式 [英]" );
        }
        if ( g == rememberanceDay( yy ) ) {
            printf( "  Rememberance Day [英]" );
            length += strlen( "  Rememberance Day [英]" );
        }
        if ( g == thanksGivingDay( yy ) ) {
            printf( "  感謝祭(Thanks Giving Day) [米]" );
            length += strlen( "  感謝祭(Thanks Giving Day) [米]" );
        }
        if ( g == thanksGivingDay( yy ) + 1L ) {
            printf( "  day after Thanksgiving [米]" );
            length += strlen( "  day after Thanksgiving [米]" );
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
        printf( "  断食月" );
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
        printf( "  Id-al-Fitr (開斎節)" );
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
#if 0   /* 'Ta Anit Esther' と同じなので、削除 */
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

    /* 以下、2003.02.06 追加 (参考: hdate.lib) */
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
            printf( "  Tsuporone's BBS 開局%d周年", y - 1988 );
        else if ( y == 1988 )
            printf( "  Tsuporone's BBS 開局" );
    }
}


/*
 *      JRの運賃計算の特例日の算出 (1995年12月現在)
 *
 *              通常期: 閑散期と繁忙期以外の日
 *              閑散期: 1月16日～2月末日, 6・9・11月, 12月1日～20日 の各期間
 *                      の月曜～木曜 (ただし、休日とその前日は除く)
 *              繁忙期: 3月21日～4月5日, 4月28日～5月6日, 7月21日～8月31日,
 *                      12月25日～1月10日
 *
 *              特急料金(新幹線の指定席特急料金を含む)
 *                      閑散期は通常期の200円引き、繁忙期は通常期の200円増し。
 *                      ただし、JR東日本の「つばさ」・「こまくさ」を乗りついで
 *                      東京-郡山の間の任意の駅←→山形-秋田の間の任意の駅で乗
 *                      降する場合は、閑散期は通常期の 340円引き、繁忙期は通常
 *                      期の340円増し
 *              指定席券
 *                      閑散期以外は閑散期の200円増し(ただし、JR北海道, JR九
 *                      州は通年同一料金)
 *              回数券
 *                      4月27日～5月6日, 8月11日～20日, 12月28日～1月6日の各期
 *                      間は、回数券を利用できない
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
        return;         /* この制度は 1989年4月1日から実施 */

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

    printf( "\n- JR運賃計算の期間 -\n" );
    switch ( kind ) {
    case TERM_NORMAL:
        printf( "通常期\n" );
        break;
    case TERM_IDLE:
        printf( "閑散期\n" );
        printf( "    特急料金は通常期より割引されます\n" );
        break;
    case TERM_BUSY:
    case TERM_VERYBUSY:
        if ( ( m == 4 ) && ( d == 27 ) )
            printf( "通常期\n    ただし、この日は特例として、" );
        else {
            printf( "繁忙期\n" );
            printf( "    特急料金は通常期より割増されます\n" );
            if ( kind == TERM_VERYBUSY )
                printf( "    また、" );
        }
        if ( kind == TERM_VERYBUSY )
            printf( "新幹線等の回数券は使えません\n" );
        break;
    }

    if ( y >= 2005 ) {
        /*
         *  春休み 
         *      発売期間:2月20日～3月31日 
         *      利用期間:3月1日～4月10日 
         *  夏休み 
         *      発売期間:7月1日～8月31日 
         *      利用期間:7月20日～9月10日 
         *  冬休み 
         *      発売期間:12月1日～1月10日 
         *      利用期間:12月10日～1月20日 
         */
        if ( (m == 1) || (m == 2) || (m == 3) || (m == 4) || (m == 7) ||
             (m == 8) || (m == 9) || (m == 12) )
            printf( "\n- 18切符の発売/通用期間 -\n    " );
        if ( (m == 7) || (m == 12) ) {
            printf( "18切符発売中。" );
            if ( (d >= 20) || ((m == 12) && (d >= 10)) )
                printf( "18切符が使えます\n" );
            else
                printf( "%sの18切符の使用可能期間はまだ始まっていません\n",
                        (m == 12) ? "冬" : "夏" );
        }
        else if ( m == 1 ) {
            if ( d <= 10 )
                printf( "18切符発売中。18切符が使えます\n" );
            else if ( d <= 20 )
                printf( "冬の18切符の発売期間は終了していますが、18切符は"
                        "使えます\n" );
            else
                printf( "冬の18切符の使用可能期間は終了しています\n" );
        }
        else if ( m == 2 ) {
            if ( d >= 20 )
                printf( "18切符発売中。春の18切符の使用可能期間はまだ始まって"
                        "いません\n" );
            else
                printf( "春の18切符の発売はまだ始まっていません\n" );
        }
        else if ( (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( 
                 "%sの18切符の発売期間は終了していますが、18切符は使えます\n",
                        m == 4 ? "春" : "夏" );
            else
                printf( "%sの18切符の使用可能期間は終了しています\n",
                        m == 4 ? "春" : "夏" );
        }
        else if ( (m == 3) || (m == 8) )
            printf( "18切符発売中。18切符が使えます\n" );
    }
    else {
        if ( (m == 1) || (m == 3) || (m == 4) || (m == 7) || (m == 8) ||
             (m == 9) || (m == 12) )
            printf( "\n- 18切符の発売/通用期間 -\n    " );
        if ( (m == 3) || (m == 7) || (m == 12) ) {
            printf( "18切符発売中。" );
            if ( d >= 10 )
                printf( "18切符が使えます\n" );
            else
                printf( "%sの18切符の使用可能期間はまだ始まっていません\n",
                        (m == 12) ? "冬" : (m == 3) ? "春" : "夏" );
        }
        else if ( m == 8 )
            printf( "18切符発売中。18切符が使えます\n" );
        else if ( (m == 1) || (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( "18切符発売中。18切符が使えます\n" );
            else if ( d <= 20 )
                printf(
                 "%sの18切符の発売期間は終了していますが、18切符は使えます\n",
                        (m == 1) ? "冬" : (m == 4) ? "春" : "夏" );
            else
                printf( "%sの18切符の使用可能期間は終了しています\n",
                        (m == 1) ? "冬" : (m == 4) ? "春" : "夏" );
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
