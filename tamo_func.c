/*
 *      tamo_func.c
 *                      by H.Tsujimura  tsupo@na.rim.or.jp
 *                                              2 March 1991
 *      Copyright (c) 1991-1995,1998-2001,2003-2005,2007 Hiroshi Tsujimura
 *      All Rights Reserved.
 *
 * History :
 * $Log: tamo_func.c $
 * Revision 1.109  2013/01/22  08:00:30  tsujimura543
 * サンマータイム開始の条件式を修正
 *
 * Revision 1.108  2012/12/13  04:56:18  tsujimura543
 * ブルームーンに対応した
 *
 * Revision 1.107  2011/08/08  04:19:57  tsujimura543
 * 台湾の父親節、児童節を追加
 *
 * Revision 1.106  2009/04/27  11:41:54  tsujimura543
 * インデント修正
 *
 * Revision 1.105  2007/10/18  12:17:49  tsujimura543
 * 「家族の日」対応
 *
 * Revision 1.104  2007/02/20  04:47:37  tsujimura543
 * 18きっぷの発売期間、通用期間を最近の状況に合わせて修正
 *
 * Revision 1.103  2007/02/08  06:41:41  tsujimura543
 * 夏時間関連の処理を修正
 *
 * Revision 1.102  2007/02/08  02:44:01  tsujimura543
 * 夏時間の開始、終了関連処理を変更・追加
 *
 * Revision 1.101  2007/02/06  10:50:23  tsujimura543
 * copyright 表記をアップデート
 *
 * Revision 1.100  2007/02/06  10:48:33  tsujimura543
 * Chandeleur を追加
 *
 * Revision 1.99  2007/02/05  15:13:52  tsujimura543
 * Bank Holiday の振り替え休日に対応した
 *
 * Revision 1.98  2005/05/13  12:54:44  tsujimura543
 * 振替休日の扱い方を新しい祝日法に合わせて修正
 *
 * Revision 1.97  2005/05/13  02:54:10  tsujimura543
 * 2007年から4月29日が「昭和の日」、5月4日が「みどりの日」になる祝日法
 * 改正に対応
 *
 * Revision 1.96  2004/09/16  01:08:57  tsujimura543
 * 大喪の礼(昭和天皇)等1日限りの祝日をいくつか追加
 *
 * Revision 1.95  2004/01/13  10:54:58  tsujimura543
 * 「敬老の日」と「秋分の日」にはさまれた「国民の休日」に対応。
 *
 * Revision 1.94  2003/11/11  09:11:42  tsujimura543
 * ユリウス暦、イスラム暦、ユダヤ暦の表示を最適化
 *
 * Revision 1.93  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.92  2003/11/07  12:03:00  tsujimura543
 * 諸外国の祝祭日を追加
 *
 * Revision 1.91  2003/06/20  04:14:27  tsujimura543
 * マーズウイーク(約6万年に1回の火星超大接近)に対応
 *
 * Revision 1.90  2003/05/30  07:49:19  tsujimura543
 * 国際的な行事日を追加
 *
 * Revision 1.89  2003/05/28  11:00:11  tsujimura543
 * 寒九などに対応
 *
 * Revision 1.88  2003/05/27  12:20:06  tsujimura543
 * tamo_func.c 内の #define の一部を tamo.h に移動
 *
 * Revision 1.87  2003/05/27  09:56:35  tsujimura543
 * 薮入り、針供養などを追加
 *
 * Revision 1.86  2003/05/27  09:05:33  tsujimura543
 * 御用始め、御用納めに対応
 *
 * Revision 1.85  2003/05/20  06:00:31  tsujimura543
 * 全期間にわたって24節季を表示するようにした
 *
 * Revision 1.84  2003/04/23  11:09:07  tsujimura543
 * 入梅、半夏生、土用の表示を太陽暦の方へ移す
 * (今回の修正で必要なくなった関数を削除)
 *
 * Revision 1.83  2003/04/23  09:27:12  tsujimura543
 * 24節気の表示を太陰太陽暦(旧暦)から太陽暦(新暦)の方に移す
 *
 * Revision 1.82  2003/04/17  10:34:15  tsujimura543
 * 表示桁数を調整
 *
 * Revision 1.81  2003/04/15  05:25:33  tsujimura543
 * 「地蔵盆」を追加
 *
 * Revision 1.80  2003/03/24  08:58:03  tsujimura543
 * (1) 和暦(太陰太陽暦)の表示可能期間を拡張
 * (2) 大暑と土用の丑の日が重なった場合、片方しか表示されない不具合を修正
 *
 * Revision 1.79  2003/03/20  10:04:33  tsujimura543
 * 凶会日を「節入日による月」ではなく、実際の旧暦の月を元に計算するよう修正
 *
 * Revision 1.78  2003/03/20  09:18:02  tsujimura543
 * 各種暦注の表示を追加
 *
 * Revision 1.77  2003/03/19  04:46:08  tsujimura543
 * 干支の出力方式を他の暦と同じにする
 *
 * Revision 1.76  2003/03/19  03:05:48  tsujimura543
 * 旧暦関係の出力方法を他の暦と同じ方式にする
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
#include "tamo.h"

#ifndef lint
static char     *rcs_id =
        "$Header: C:/user/local/src/tamo/RCS/tamo_func.c 1.109 2013/01/22 08:00:30 tsujimura543 Exp tsujimura543 $";
#endif

/*
 * 各国の祝祭日は
 *    http://www.holidayfestival.com/
 *  が参考になる
 */

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
        "みどりの日",      4,   29,     1989,   2006,   /* 平成元年制定   */
        "昭和の日",        4,   29,     2007,   MAXINT, /* 平成17年制定   */
        "憲法記念日",      5,    3,     1949,   MAXINT, /* 昭和23年制定   */
        "国民の休日",      5,    4,     1989,   2006,
        "みどりの日",      5,    4,     2007,   MAXINT, /* 平成17年制定   */
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
    "Chandeleur (クレープを食べる日) [仏]",      2,      2,     0,    MAXINT,
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
zodiac( long g, int year )
{
    register int    i;

    for ( i = 0; i < 12; i++ ) {
        if ( g < absoluteFromGregorian( z[i].dd, z[i].mm, year ) )
            break;
    }

    return ( z[( --i + 12) % 12 ].sign );
}

char    *
zodiac13( long g, int year )
{
    register int    i;

    for ( i = 0; i < 13; i++ ) {
        if ( g < absoluteFromGregorian( z13[i].dd, z13[i].mm, year ) )
            break;
    }

    return ( z13[( --i + 13) % 13 ].sign );
}


long
seijinNoHi( int year )
{
    return ( NthKday( SECOND, MONDAY, JANUARY, year ) );
                                                /* 2nd Monday in January */
}


long
KingsBirthday( int year )
{
    return ( NthKday( THIRD, MONDAY, JANUARY, year ) );
                                                /* 3rd Monday in January */
}


long
waitangiDay( int year )
{
    return ( NthKday( FIRST, SUNDAY, FEBRUARY, year ) );
                                                /* 1st Sunday in February */
}


long
australiaDay( int year )
{
    return ( NthKday( FIRST, MONDAY, FEBRUARY, year ) );
                                                /* 1st Monday in February */
}


long
WashingtonBirthday( int year )
{
    return ( NthKday( THIRD, MONDAY, FEBRUARY, year ) );
                                                /* 3rd Monday in February */
}

long
russianDay( int dd, int mm, int yy )
{
    if ( yy > 1990 )
        return ( absoluteFromGregorian( 12, JUNE, yy ) );
    else
        return ( -1 );
}


long
mothersDay( int year )
{
    return ( NthKday( SECOND, SUNDAY, MAY, year ) );
                                                /* 2nd Sunday in May */
}


long
fathersDay( int year )
{
    return ( NthKday( THIRD, SUNDAY, JUNE, year ) );
                                                /* 3rd Sunday in June */
}


long
umiNoHi( int year )
{
    return ( NthKday( THIRD, MONDAY, JULY, year ) );
                                                /* 3rd Monday in July */
}


long
keirouNoHi( int year )
{
    return ( NthKday( THIRD, MONDAY, SEPTEMBER, year ) );
                                                /* 3rd Monday in September */
}


long
taiikuNoHi( int year )
{
    return ( NthKday( SECOND, MONDAY, OCTOBER, year ) );
                                                /* 2nd Monday in October */
}

long
magoNoHi( int year )
{
    return ( NthKday( THIRD, SUNDAY, OCTOBER, year ) );
                                                /* 3rd Sunday in October */
}


#if     0
dateList        *
secretarysDay( int year )
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
checkDateList( long g, const long *dates, const char *s )
{
    while ( *dates ) {
        if ( g == *dates++ ) {
            printf( "  %s", s );
            break;
        }
    }
}


void
checkJapanese( long g, int dd, int mm, int yy, int htmlMode )
{
    register int    i     = 0;
    int             reset = 1;
    int             tsuki;
    long            fushi;
    char            *p;

    tprintf( htmlMode, &reset, "  %s", kyusei( g ) );
    tprintf( htmlMode, &reset, "  %s", nijuhachishuku( g ) );
    tprintf( htmlMode, &reset, "  %s",
	     junichoku( g, dd, mm, yy, &tsuki, &fushi ) );
    if ( ( p = sanrinbou( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = manbaibi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = kurobi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = jisshinichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = kikonichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = fukunichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = chiImiNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = tenKaNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = jiKaNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = ouMouNichi( g, tsuki, fushi ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = boSouNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = tsukiTokuNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );

    if ( ( mm == FEBRUARY ) || ( mm == MARCH )     ||
         ( mm == MAY )      || ( mm == SEPTEMBER )    )
        risshunday = springStartDay( yy );
    if ( mm == MARCH )
        shunbunday = midSpringDay( yy );
    if ( ( mm == JUNE ) || ( mm == JULY ) || ( mm == AUGUST ) ) {
        geshiday   = midSummerDay( yy );
        risshuuday = autumnStartDay( yy );
    }
    if ( mm == SEPTEMBER )
        shuubunday = midAutumnDay( yy );

    checkTenShaNichi( g, mm, yy, htmlMode, &reset );

    if ( mm == JANUARY ) {
        long    shouKanDay = sekkiDay( SK24_SHOUKAN, yy );

        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  チェコ共和国独立記念日" );
        if ( (dd == 2) && (g % 7 == MONDAY) )
            tprintf( htmlMode, &reset, "  New Year's Day [英]" );
        if ( yy >= 1874 ) {
            if ( ((dd == 4) && (g % 7 != SATURDAY) && (g % 7 != SUNDAY)) ||
                 ((dd == 5) && (g % 7 == MONDAY))                        ||
                 ((dd == 6) && (g % 7 == MONDAY))                           )
                tprintf( htmlMode, &reset, "  官庁御用始め" );
        }
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  人日" );
            tprintf( htmlMode, &reset, "  七草" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  鏡開き" );
        if ( yy >= 2000 ) {     /* 平成12年から */
            if ( g == seijinNoHi( yy ) )
                tprintf( htmlMode, &reset, "  成人の日" );
        }
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  ザンジバル革命記念日(タンザニア)" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  薮入り" );
        if ( g == shouKanDay )
            tprintf( htmlMode, &reset, "  小寒" );
        else if ( g == shouKanDay + 4 )
            tprintf( htmlMode, &reset, "  寒四郎" );
        else if ( g == shouKanDay + 9 )
            tprintf( htmlMode, &reset, "  寒九" );
        else if ( g == sekkiDay( SK24_DAIKAN, yy ) )
            tprintf( htmlMode, &reset, "  大寒" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  サンパウロ市創立記念日" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  共和国記念日(インド)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  建国記念日(オーストラリア)" );
    }
    if ( mm == FEBRUARY ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  首都制定日(マレーシア)" );
        if ( (dd == 2) && (yy >= 2007) ) 
            tprintf( htmlMode, &reset, "  情報セキュリティの日" );
        if ( g == setsubun( yy ) )
            tprintf( htmlMode, &reset, "  節分" );
        else if ( g == risshunday )
            tprintf( htmlMode, &reset, "  立春" );
        else if ( g == sekkiDay( SK24_USUI, yy ) )
            tprintf( htmlMode, &reset, "  雨水" );
        if ( shi( g ) == UMA ) {
            if ( g <= absoluteFromGregorian( 12, 2, yy ) )
                tprintf( htmlMode, &reset, "  初午" );
            else if ( g <= absoluteFromGregorian( 24, 2, yy ) )
                tprintf( htmlMode, &reset, "  二の午" );
        }
        if ( (((dd >= 6)  && (dd <= 11))   ||
              ((dd == 5)  && (yy >= 2002)) ||
              ((dd == 12) && (g % 7 == MONDAY) && (yy >= 1973))) &&
             (yy >= 1950) ) {
            tprintf( htmlMode, &reset, "  第%d回さっぽろ雪祭り", yy - 1949 );
                /* 通常は 2月6日から11日までが「雪祭り」だが、12日  */
                /* が振替休日になった場合は、12日までが「雪祭り」の */
                /* 期間となる                                       */
                /* 追記: 第53回(2002年)から2月5日開始になった       */
        }
        if ( dd ==  5 )
            tprintf( htmlMode, &reset, "  憲法記念日(メキシコ)" );
        if ( dd ==  7 )
            tprintf( htmlMode, &reset, "  北方領土の日" );
        if ( dd ==  8 )
            tprintf( htmlMode, &reset, "  針供養" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  バレンタインデー" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  金正日誕生日(北朝鮮)" );
        if ( yy >= 1998 ) {     /* 平成10年から */
            if ( dd == 20 )
                tprintf( htmlMode, &reset, "  旅券の日" );
        }
        if ( dd == 21 )
            tprintf( htmlMode, &reset,
                     "  ベンガル語国語化運動記念日(バングラディッシュ)" );
        if ( yy >= 1989 ) {     /* 平成元年から */
            if ( dd == 23 )
                tprintf( htmlMode, &reset, "  皇太子誕生日" );
        }
        if ( dd == 23 )
            tprintf( htmlMode, &reset, "  祖国防衛者の日(ロシア)" );
        if ( ( yy == 1989 ) && ( dd == 24 ) )
            tprintf( htmlMode, &reset, "  大喪の礼(昭和天皇)" );
        if ( ( yy > 1996 ) && ( dd == 27 ) )
            tprintf( htmlMode, &reset,
                     "  ポケットモンスター%d周年", yy - 1996 );
        if ( dd == 28 ) {
            tprintf( htmlMode, &reset, "  ビスケットの日" );
            tprintf( htmlMode, &reset, "  和平記念日(台湾)" );
        }
    }
    if ( mm == MARCH ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  独立運動記念日(韓国)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  テキサス独立記念日" );
        if ( dd == 3 ) {
            tprintf( htmlMode, &reset, "  上巳の節句(ひな祭り)" );
            if ( yy >= 1955 )
                tprintf( htmlMode, &reset, "  第%d回耳の日", yy - 1954 );
        }
        if ( dd == 4 )
            tprintf( htmlMode, &reset, " 民族舞踊の日(パナマ)" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  国際婦女節(中国)" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  ホワイトデー" );
        if ( dd == 15 )
            if ( yy >= 1849 )
                tprintf( htmlMode, &reset, "  1848年革命記念日(ハンガリー)" );
        if ( g == shunbunday ) {
            tprintf( htmlMode, &reset, "  春分" );
            if ( yy >= 1878 ) {
                if ( yy <= 1945 )
                    tprintf( htmlMode, &reset, "  春季皇霊祭" );
                else
                    tprintf( htmlMode, &reset, "  春分の日" );
            }
        }
        else if ( g == sekkiDay( SK24_KEICHITSU, yy ) )
            tprintf( htmlMode, &reset, "  啓蟄" );
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shunbunday ) < 5 ) ||
               ( shunbunday - g == 5 )          )    ) 
            tprintf( htmlMode, &reset, "  社日" );
        if ( dd == 21 ) {
            tprintf( htmlMode, &reset, "  ベニートフアレス誕生日(メキシコ)" );
            tprintf( htmlMode, &reset, "  人権記念日(南アフリカ)" );
        }
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  独立記念日(ギリシア)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  独立記念日(バングラディッシュ)" );
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  革命先烈記念日(台湾)" );
    }

    if ( g - shunbunday == 15 )
        tprintf( htmlMode, &reset, "  清明節(中国)" );

    if ( mm == APRIL ) {
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  国際こどもの本の日" );
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  児童節(台湾)" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  植木の日(韓国)" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, "  世界保健デー" );
        if ( dd == 8 ) {
            tprintf( htmlMode, &reset, "  潅仏会" );
            tprintf( htmlMode, &reset, "  花まつり" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  戦争記念日(フィリピン)" );
        if ( ( yy == 1959 ) && ( dd == 10 ) )
            tprintf( htmlMode, &reset, "  結婚の儀(明仁親王)" );
        if ( dd == 15 )
            tprintf( htmlMode, &reset, "  金日成誕生日(北朝鮮)" );
        if ( dd == 18 )
            tprintf( htmlMode, &reset, "  独立記念日(ジンバブエ)" );
        if ( dd == 19 )
            tprintf( htmlMode, &reset, "  独立宣言記念日(ベネズエラ)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  逓信記念日" );
        if ( dd == 21 ) {
            tprintf( htmlMode, &reset, "  民放の日" );
            tprintf( htmlMode, &reset, "  家族の日(南アフリカ)" );
        }
        if ( dd == 23 ) {
            tprintf( htmlMode, &reset, "  世界本の日" );
            if ( yy > 1920 )
                tprintf( htmlMode, &reset, "  国民主権と子供の日(トルコ)" );
        }
        if ( dd == 25 ) {
            tprintf( htmlMode, &reset, "  アンザック・デー" );
            tprintf( htmlMode, &reset, "  解放記念日(イタリア)" );
            tprintf( htmlMode, &reset, "  革命記念日(ポルトガル)" );
            tprintf( htmlMode, &reset, "  シナイ返還記念日(エジプト)" );
            tprintf( htmlMode, &reset, "  人民軍創設記念日(北朝鮮)" );
        }
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  連合記念日(タンザニア)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  自由の日(南アフリカ)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  南部戦没者記念日(アメリカ南部)" );
        /* 秘書の日
         *  4月の一番最後の 7日間揃った週の水曜日
         *  (つまり、最終土曜の 3日前)
         */
        if ( (yy >= 1952) && (g == secretarysDay( yy )) )
            tprintf( htmlMode, &reset, "  秘書の日" );
        if ( g == sekkiDay( SK24_SEIMEI, yy ) )
            tprintf( htmlMode, &reset, "  清明" );
        else if ( g == sekkiDay( SK24_KOKUU, yy ) )
            tprintf( htmlMode, &reset, "  穀雨" );
        if ( g == NthKday( LAST, WEDNESDAY, APRIL, yy ) )
            tprintf( htmlMode, &reset, "  国際盲導犬の日" );
        if ( (yy >= 1976) && (dd == 30) )
            tprintf( htmlMode, &reset, "  南部ベトナム開放記念日(ベトナム)" );

        if ( (yy == 1949) && (g == NthKday( FIRST, SATURDAY, APRIL, yy ) + 1) )
            tprintf( htmlMode, &reset, "  サンマータイム開始" );
    }
    if ( mm == MAY ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  国際労働節(中国)" );
        if ( dd == 2 ) {
            tprintf( htmlMode, &reset, "  国民の休日(ポーランド)" );
            tprintf( htmlMode, &reset, "  若者の日(ルーマニア)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset, "  憲法記念日(ポーランド)" );
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  中国青年節(中国)" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  端午の節句" );
            tprintf( htmlMode, &reset, "  国王即位記念日(タイ)" );
            tprintf( htmlMode, &reset, "  解放記念日(オランダ)" );
        }
        if ( g == hachijuHachiYa( yy ) )
            tprintf( htmlMode, &reset, "  八十八夜" );
        if ( dd == 8 ) {
            tprintf( htmlMode, &reset, "  世界赤十字デー" );
            tprintf( htmlMode, &reset, "  解放記念日(チェコ)" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  戦勝記念日(ロシア)" );
        if ( g == mothersDay( yy ) )
            tprintf( htmlMode, &reset, "  母の日" );
        if ( g == summerStartDay( yy ) )
            tprintf( htmlMode, &reset, "  立夏" );
        else if ( g == sekkiDay( SK24_SHOUMAN, yy ) )
            tprintf( htmlMode, &reset, "  小満" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  両親の日(韓国)" );
        if ( dd == 17 )
            tprintf( htmlMode, &reset, "  憲法記念日(ノルウェー)" );
        if ( dd == 19 ) {
            tprintf( htmlMode, &reset, "  ビクトリア女王誕生日" );
            tprintf( htmlMode, &reset, "  青年とスポーツの日(トルコ)" );
        }
        if ( dd == 21 )
            tprintf( htmlMode, &reset, "  イキケ海戦記念日(チリ)" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  5月革命記念日(アルゼンチン)" );
        if ( (dd == 25) || (dd == 26) )
            tprintf( htmlMode, &reset, "  アフリカデー(ジンバブエ)" );
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  民主化記念日(ナイジェリア)" );

        if ( ((yy == 1948) || (yy == 1950) || (yy == 1951)) &&
             (g == NthKday( FIRST, SATURDAY, MAY, yy ) + 1)    ) 
            tprintf( htmlMode, &reset, "  サンマータイム開始" );
    }
    if ( mm == JUNE ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  国際児童節(中国)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  共和国記念日(イタリア)" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  世界環境デー" );
            tprintf( htmlMode, &reset, "  憲法記念日(デンマーク)" );
        }
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  顕忠日(韓国)" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, "  国王誕生記念日(マレーシア)" );
        if ( ( yy == 1993 ) && ( dd == 9 ) )
            tprintf( htmlMode, &reset, "  結婚の儀(徳仁親王)" );
        if ( dd == 12 ) {
            tprintf( htmlMode, &reset, "  独立記念日(フィリピン)" );
            tprintf( htmlMode, &reset, "  独立記念日(ロシア)" );
        }
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  国旗の日(アルゼンチン)" );
            tprintf( htmlMode, &reset, "  青年の日(南アフリカ)" );
        }
        if ( g == fathersDay( yy ) )
            tprintf( htmlMode, &reset, "  父の日" );
        if ( (yy >= 2000) &&
             ( g == NthKday( FIRST, MONDAY, JUNE, yy ) ) )
            tprintf( htmlMode, &reset, "  寄席の日" );
                                        /* 6月の第1月曜日 (2000年～) */
        if ( (yy >= 2000) && (dd == 26) ) {
            tprintf( htmlMode, &reset, "  国際麻薬乱用撲滅デー" );
        }
        if ( g == sekkiDay( SK24_BOUSHU, yy ) )
            tprintf( htmlMode, &reset, "  芒種" );
        else if ( g == geshiday )
            tprintf( htmlMode, &reset, "  夏至" );
        if ( dd == 24 ) {
            tprintf( htmlMode, &reset, "  聖バプティスト記念日(ケベック州)" );
            tprintf( htmlMode, &reset, "  カラボボ戦勝記念日(ベネズエラ)" );
        }
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  聖ペドロと聖パブロの日(ペルー)" );
        if ( (dd == 20) && (yy == 2005) )
            tprintf( htmlMode, &reset, "  北海道サマータイム開始" );
        if ( (dd == 21) && (yy == 2006) )
            tprintf( htmlMode, &reset, "  北海道サマータイム開始" );
    }
    if ( mm == JULY ) {
        if ( (dd == 1) && (yy == 2004) )
            tprintf( htmlMode, &reset, "  北海道サマータイム開始" );
        if ( dd == 1 ) {
            if ( yy >= 2000 )
                tprintf( htmlMode, &reset, "  特別行政区設立記念日(香港)" );
            tprintf( htmlMode, &reset, "  建国記念日(カナダ)" );
        }
        if ( g == NthKday( FIRST, SATURDAY, JULY, yy ) )
            tprintf( htmlMode, &reset, "  勤労青少年の日" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  聖職者来訪の日(チェコ)" );
            tprintf( htmlMode, &reset, "  独立記念日(ベネズエラ)" );
        }
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  ヤン・フスの日(チェコ)" );
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  七夕" );
            tprintf( htmlMode, &reset, "  サバ・サバディ(タンザニア)" );
        }
        if ( dd == 9 ) {
            tprintf( htmlMode, &reset, "  サンパウロ州革命記念日" );
            tprintf( htmlMode, &reset, "  独立記念日(アルゼンチン)" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  フラマン語圏共同体祝日(ベルギー)" );
        if ( dd == 13 )
            tprintf( htmlMode, &reset, "  盆迎え火" );
        if ( dd == 15 )
            tprintf( htmlMode, &reset, "  盆" );
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  盆送り火" );
            tprintf( htmlMode, &reset, "  薮入り" );
        }
        if ( dd == 17 )
            tprintf( htmlMode, &reset, "  憲法記念日(韓国)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  独立記念日(コロンビア)" );
        if ( dd == 21 )
            tprintf( htmlMode, &reset, "  海の日(ケニア)" );
        if ( dd == 23 )
            tprintf( htmlMode, &reset, "  革命記念日(エジプト)" );
        if ( dd == 24 ) {
            tprintf( htmlMode, &reset, "  地蔵盆" );
            tprintf( htmlMode, &reset, "  ボリバル生誕記念日(ベネズエラ)" );
        }
        if ( yy >= 2003 ) {     /* 平成15年から */
            if ( g == umiNoHi( yy ) )
                tprintf( htmlMode, &reset, "  海の日" );
        }
        if ( (yy >= 1932) && (g == NthKday( THIRD, SATURDAY, JULY, yy )) )
            tprintf( htmlMode, &reset, "  協同組合の国際デー" );
        if ( g == sekkiDay( SK24_SHOUSHO, yy ) )
            tprintf( htmlMode, &reset, "  小暑" );
        else if ( g == sekkiDay( SK24_TAISHO, yy ) )
            tprintf( htmlMode, &reset, "  大暑" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  ニコヤ地区併合の日(コスタリカ)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  国際麻薬乱用撲滅デー" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  戦勝記念日(北朝鮮)" );
        if ( (dd == 28) || (dd == 29) )
            tprintf( htmlMode, &reset, "  独立記念日(ペルー)" );
        if ( (dd == 31) && ((yy == 2004) || (yy == 2005)) )
            tprintf( htmlMode, &reset, "  北海道サマータイム終了" );
    }
    if ( ( mm == JULY ) || ( mm == AUGUST ) ) {
        if ( kan( g ) == KANOE ) {
            if ( ( g >= geshiday + 20 ) && ( g < geshiday + 30 ) )
                tprintf( htmlMode, &reset, "  初伏" );
            if ( ( g >= geshiday + 30 ) && ( g < geshiday + 40 ) )
                tprintf( htmlMode, &reset, "  中伏" );
            if ( ( g >= risshuuday ) && ( g < risshuuday + 10 ) )
                tprintf( htmlMode, &reset, "  末伏" );
        }
    }

    if ( mm == AUGUST ) {
        if ( dd == 1 ) {
            tprintf( htmlMode, &reset, "  八朔" );
            tprintf( htmlMode, &reset, "  建軍節(中国)" );
            tprintf( htmlMode, &reset, "  独立記念日(スイス)" );
        }
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  市民の日(カナダ)" );
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  アブダビ首長就任記念日(UAE)" );
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  ボヤカ戦勝記念日(コロンビア)" );
            tprintf( htmlMode, &reset, "  独立記念日(コートジボアール)" );
        }
        if ( dd == 8 ) {
            tprintf( htmlMode, &reset, "  農民祭(タンザニア)" );
            tprintf( htmlMode, &reset, "  父親節(台湾)" );
        }
        if ( dd == 9 ) {
            if ( yy >= 1946 )
                tprintf( htmlMode, &reset, "  独立記念日(シンガポール)" );
            tprintf( htmlMode, &reset, "  全国婦人の日(南アフリカ)" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  独立戦士記念日(ジンバブエ)" );
        if ( dd == 12 ) {
            tprintf( htmlMode, &reset, "  王妃誕生日(タイ)" );
            tprintf( htmlMode, &reset, "  国軍記念日(ジンバブエ)" );
        }
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  月遅れ盆" );
            if ( yy >= 1946 )
                tprintf( htmlMode, &reset, "  光復節(韓国)" );
            tprintf( htmlMode, &reset, "  パナマ市創立記念日" );
        }
        if ( dd == 18 )
            tprintf( htmlMode, &reset,
                     "  サンマルティン将軍逝去の日(アルゼンチン)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset,
                     "  聖イシュトバーンの日/憲法記念日(ハンガリー)" );
        if ( g == risshuuday )
            tprintf( htmlMode, &reset, "  立秋" );
        else if ( g == sekkiDay( SK24_SHOSHO, yy ) )
            tprintf( htmlMode, &reset, "  処暑" );
        if ( yy == 2003 ) {
            if ( (dd >= 22) && (dd <= 31) ) {
                tprintf( htmlMode, &reset, "  マーズウィーク" );
                if ( dd == 27 )
                    tprintf( htmlMode, &reset, "  火星超大接近" );
            }
        }
        if ( dd == 30 ) {
            tprintf( htmlMode, &reset, "  サンタ・ロサの日(ペルー)" );
            if ( yy > 1922 )
                tprintf( htmlMode, &reset, "  戦勝記念日(トルコ)" );
        }
        if ( dd == 31 ) {
            tprintf( htmlMode, &reset, "  英雄記念日(フィリピン)" );
            tprintf( htmlMode, &reset, "  独立記念日(マレーシア)" );
        }
        if ( (dd == 11) && (yy == 2006) )
            tprintf( htmlMode, &reset, "  北海道サマータイム終了" );
    }
    if ( mm == SEPTEMBER ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  勤労感謝の日(カナダ)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  国慶節(ベトナム)" );
        if ( g == nihyakuTohKa( yy ) )
            tprintf( htmlMode, &reset, "  二百十日" );
        if ( g == nihyakuHatsuKa( yy ) )
            tprintf( htmlMode, &reset, "  二百二十日" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, " 独立記念日(ブラジル)" );
        if ( dd == 9 ) {
            tprintf( htmlMode, &reset, "  菊の節句(重陽)" );
            tprintf( htmlMode, &reset, "  建国記念日(北朝鮮)" );
        }
        if ( g == sekkiDay( SK24_HAKURO, yy ) )
            tprintf( htmlMode, &reset, "  白露" );
        else if ( g == shuubunday ) {
            tprintf( htmlMode, &reset, "  秋分" );
            if ( yy >= 1878 ) {
                if ( yy < 1945 )
                    tprintf( htmlMode, &reset, "  秋季皇霊祭" );
                else
                    tprintf( htmlMode, &reset, "  秋分の日" );
            }
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shuubunday ) < 5 ) ||
               ( shuubunday - g == 5 )          )    ) 
            tprintf( htmlMode, &reset, "  社日" );
        if ( yy >= 2003 ) {     /* 平成15年から */
            if ( dd == 15 )
                tprintf( htmlMode, &reset, "  老人の日" ); /* 平日 */
            if ( g == keirouNoHi( yy ) )
                tprintf( htmlMode, &reset, "  敬老の日" ); /* 祝日 */
            else if ( (g == keirouNoHi( yy ) + 1) &&
                      (g == shuubunday - 1)       &&
                      (g % 7 == TUESDAY)             ) {
                tprintf( htmlMode, &reset, "  国民の休日" );
                    /* 前日が「敬老の日」で翌日が「秋分の日」 */
                    /* の場合、その日は「国民の休日」となる   */
                    /* (2003年以降)                           */
            }
        }
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  独立記念日(コスタリカ)" );
            tprintf( htmlMode, &reset, "  敬老の日(ケニア)" );
        }
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  独立記念日(メキシコ)" );
        if ( dd == 18 )
            tprintf( htmlMode, &reset, "  独立記念日(チリ)" );
        if ( dd == 19 )
            tprintf( htmlMode, &reset, "  陸軍記念日(チリ)" );
        if ( dd == 24 )
            tprintf( htmlMode, &reset, "  文化遺産記念日(南アフリカ)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  フラマン語圏共同体祝日(ベルギー)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  チェコ国家の日" );

        if ( ((yy >= 1949) && (yy <= 1951)) &&
             (g == NthKday( SECOND, SATURDAY, SEPTEMBER, yy )) )
            tprintf( htmlMode, &reset, "  サンマータイム終了" );
    }
    if ( mm == OCTOBER ) {
        if ( dd == 1 ) {
            tprintf( htmlMode, &reset, "  共同募金" );
            tprintf( htmlMode, &reset, "  国慶節(中国)" );
            tprintf( htmlMode, &reset, "  独立記念日(ナイジェリア)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset, "  開天節(韓国)" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  共和国記念日(ポルトガル)" );
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  戦勝記念日(エジプト)" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  アンガモス海戦記念日(ペルー)" );
        if ( dd == 10 ) {
            tprintf( htmlMode, &reset, "  国慶節(台湾)" );
            tprintf( htmlMode, &reset, "  モイ・デー(ケニア)" );
            tprintf( htmlMode, &reset, "  朝鮮労働党結成記念日(北朝鮮)" );
        }
        if ( dd == 12 ) {
            if ( g % 7 != SUNDAY )
                tprintf( htmlMode, &reset, "  国家祝日(スペイン)" );
            tprintf( htmlMode, &reset, "  聖母の日(ブラジル)" );
            tprintf( htmlMode, &reset, "  民族の日(アルゼンチン)" );
            tprintf( htmlMode, &reset, "  民族祭(チリ)" );
            tprintf( htmlMode, &reset,
                     "  アメリカ大陸発見記念日(ベネズエラ)" );
            tprintf( htmlMode, &reset, "  二文明出会いの日(コスタリカ)" );
        }
        if ( dd == 13 )
            tprintf( htmlMode, &reset, "  感謝祭(カナダ)" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  ニエレレ記念日(タンザニア)" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  ボスの日" );
        if ( yy >= 1999 ) {     /* 平成11年から */
            if ( g == magoNoHi( yy ) )
                tprintf( htmlMode, &reset, "  孫の日" );
        }
        if ( g == magoNoHi( yy ) )
            tprintf( htmlMode, &reset, "  敬老の日(中国)" );
        if ( yy >= 2000 ) {     /* 平成12年から */
            if ( g == taiikuNoHi( yy ) )
                tprintf( htmlMode, &reset, "  体育の日" );
        }
        if ( g == sekkiDay( SK24_KANRO, yy ) )
            tprintf( htmlMode, &reset, "  寒露" );
        else if ( g == sekkiDay( SK24_SOUKOU, yy ) )
            tprintf( htmlMode, &reset, "  霜降" );
        if ( (yy >= 1990) && (g == NthKday( SECOND, WEDNESDAY, OCTOBER, yy )) )
            tprintf( htmlMode, &reset, "  国際防災の日" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  ケニヤッタ・デー(ケニア)" );
        if ( dd == 23 ) {
            tprintf( htmlMode, &reset, "  チョラロンコン大王祭(タイ)" );
            tprintf( htmlMode, &reset, "  ハンガリー蜂起記念日" );
        }
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  台湾光復節" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  建国記念日(オーストリア)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  チェコスロバキア独立記念日" );
        if ( dd == 29 )
            if ( yy > 1923 )
                tprintf( htmlMode, &reset, "  共和国宣言記念日(トルコ)" );
        if ( dd == 31 )
            tprintf( htmlMode, &reset, "  先総統蒋公記念日(台湾)" );
    }
    if ( mm == NOVEMBER ) {
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  ソ連革命記念日" );
            tprintf( htmlMode, &reset, "  合意と和解の日(ロシア)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset,
                     "  コロンビアからの独立記念日(パナマ)" );
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  国旗の日(パナマ)" );
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  換気の日" );
        if ( dd == 10 )
            tprintf( htmlMode, &reset,
                     "  スペインからの独立宣言の日(パナマ)" );
        if ( dd == 11 ) {
            tprintf( htmlMode, &reset, "  独立記念日(ポーランド)" );
            tprintf( htmlMode, &reset, "  戦争記念日(カナダ)" );
        }
        if ( ( yy == 1990 ) && ( dd == 12 ) )
            tprintf( htmlMode, &reset, "  即位礼正殿の儀" );
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  国父誕辰記念日(台湾)" );
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  ドイツ語圏共同体祝日(ベルギー)" );
            tprintf( htmlMode, &reset, "  共和制宣言記念日(ブラジル)" );
            tprintf( htmlMode, &reset, "  平和の日(コートジボワール)" );
        }
        if ( dd == 17 ) {
            tprintf( htmlMode, &reset, "  自由・民主主義闘争記念日(チェコ)" );
            tprintf( htmlMode, &reset, "  カルタヘーナ独立記念日(コロンビア)" );
        }
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  革命記念日(メキシコ)" );
        if ( g == winterStartDay( yy ) )
            tprintf( htmlMode, &reset, "  立冬" );
        else if ( g == sekkiDay( SK24_SHOUSETSU, yy ) )
            tprintf( htmlMode, &reset, "  小雪" );
        if ( g == NthKday( THIRD, THURSDAY, NOVEMBER, yy ) )
            tprintf( htmlMode, &reset, "  ボジョレヌーボー解禁" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  スペインからの独立記念日(パナマ)" );
        if ( dd == 30 )
            tprintf( htmlMode, &reset, "  ボニファシオ記念日(フィリピン)" );

        if ( (yy >= 2007) && (g == NthKday( THIRD, SUNDAY, NOVEMBER, yy )) )
            tprintf( htmlMode, &reset, "  家族の日" );
    }
    if ( mm == DECEMBER ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  世界エイズデー" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  統一記念日(ルーマニア)" );
        if ( (dd == 2) || (dd == 3) )
            tprintf( htmlMode, &reset, "  連邦結成記念日(UAE)" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  国王誕生日(タイ)" );
        if ( dd == 6 ) {
            tprintf( htmlMode, &reset, "  憲法記念日(スペイン)" );
            tprintf( htmlMode, &reset, "  独立記念日(フィンランド)" );
        }
        if ( dd ==  8 ) {
            tprintf( htmlMode, &reset, "  針供養" );
            tprintf( htmlMode, &reset, "  憲法記念日(ルーマニア)" );
            tprintf( htmlMode, &reset, "  母の日(パナマ)" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  独立記念日(タンザニア)" ); 
        if ( dd == 10 ) {
            tprintf( htmlMode, &reset, "  世界人権デー" );
            tprintf( htmlMode, &reset, "  憲法記念日(タイ)" );
        }
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  憲法記念日(ロシア)" );
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  戦勝記念日(バングラディッシュ)" );
            tprintf( htmlMode, &reset, "  和解の日(南アフリカ)" );
        }
        if ( dd == 22 )
            tprintf( htmlMode, &reset,
                     "  ナショナルユニティーデー(ジンバブエ)" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  行憲記念日(台湾)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  善意の日(南アフリカ)" );
        if ( dd == 27 ) {
            tprintf( htmlMode, &reset, "  憲法記念日(北朝鮮)" );
            if ( g % 7 == MONDAY )
                tprintf( htmlMode, &reset,
                         "  Christmas Day Bank Holiday [England, Wales]" );
            if ( g % 7 == TUESDAY )
                tprintf( htmlMode, &reset,
                         "  Boxing Day Bank Holiday [England, Wales]" );
        }
        if ( dd == 28 )
            if ( g % 7 == MONDAY )
                tprintf( htmlMode, &reset,
                         "  Boxing Day Bank Holiday [England, Wales]" );
        if ( g == sekkiDay( SK24_TAISETSU, yy ) )
            tprintf( htmlMode, &reset, "  大雪" );
        else if ( g == sekkiDay( SK24_TOUJI, yy ) )
            tprintf( htmlMode, &reset, "  冬至" );
        if ( yy >= 1873 ) {
            if ( ((dd == 28) && (g % 7 != SATURDAY) && (g % 7 != SUNDAY)) ||
                 ((dd == 27) && (g % 7 == FRIDAY))                        ||
                 ((dd == 26) && (g % 7 == FRIDAY))                           )
                tprintf( htmlMode, &reset, "  官庁御用納め" );
        }
        if ( dd == 30 ) {
            tprintf( htmlMode, &reset, "  リサール記念日(フィリピン)" );
            tprintf( htmlMode, &reset, "  建国記念日(ルーマニア)" );
        }
    }

    if ( ( mm % 3 == 0 ) && ( dd == 1 ) && ( yy >= 1956 ) )
        tprintf( htmlMode, &reset, "  映画の日" ); /* 1956年～ */
    if ( ( ( mm == MARCH )     && ( g == higanInSpring( yy ) ) ) ||
         ( ( mm == SEPTEMBER ) && ( g == higanInAutumn( yy ) ) )    )
        tprintf( htmlMode, &reset, "  彼岸の入り" );
    if ( ( ( mm == JUNE )     && ( dd == 30 ) ) ||
         ( ( mm == DECEMBER ) && ( dd == 31 ) )    )
        tprintf( htmlMode, &reset, "  大祓" );

    if ( ( yy >= 1973 ) && ( g % 7 == MONDAY )               &&
         ( ((mm == MARCH)     && (g - 1 == shunbunday)) ||
           ((mm == SEPTEMBER) && (g - 1 == shuubunday))    )    ) {
        tprintf( htmlMode, &reset, "  振替休日" );
    }

    if ( ( p = zassetsu( dd, mm, yy ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );

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
            /* [2003年以降、「敬老の日」が前日、「秋分の日」が翌日となるよ  */
            /*  うな形での国民の休日が存在し得るようになった。]             */
            /* ※ 2005年の「祝日法」改正により、5月4日は「みどりの日」に    */
            /*    なった(2007年から適用)                                    */
            if ( h[i].dd == dd ) {
                if ( ( h[i].s_yy <= yy ) &&
                     ( h[i].e_yy >= yy )    )
                    if ( !( ((yy >= 1989) && (yy <= 2006)) &&
                            (mm == 5) && (dd == 4) &&
                            ( (g % 7 == SUNDAY) ||
                              (g % 7 == MONDAY)    )                  ) )
                        tprintf( htmlMode, &reset, "  %s", h[i].name );
            }

            /* 5月4日以外の「国民の休日」が日曜と重なった場合の翌日(月曜日) */
            if ( ( yy >= 1973 )        &&
                 ( h[i].dd == dd - 1 ) &&
                 ( h[i].s_yy <= yy )   &&
                 ( h[i].e_yy >= yy )   &&
                 ( g % 7 == MONDAY )      ) {
                if ( (mm != 5) || (dd != 5) )
                    tprintf( htmlMode, &reset, "  振替休日" );
            }
        }

        /* 前日が前月末で祝日かつ日曜日の場合     */
        /*   (現時点では、該当する日は存在しない) */
        if ( ( yy >= 1973 ) && ( dd == 1 ) && ( g % 7 == MONDAY )  &&
             ( h[i].mm == mm - 1 )                                 &&
             ( h[i].dd == lastDayOfGregorianMonth( h[i].mm, yy ) )    )
            tprintf( htmlMode, &reset, "  振替休日" );

        i++;
    }                               /* 振替休日は昭和48年から実施 */
    /* 5月4日が火曜～土曜の場合、国民の休日、 */
    /*         日曜の場合、      通常の日曜、 */
    /*         月曜の場合、      振替休日     */
    /* となる(平成元年以降)                   */

    /* 2007年より、5月3日または5月4日が日曜の場合の5月6日も振替休日 */
    /* になった                                                     */
    if ( (yy >= 2007) && (mm == 5) && (dd == 6) &&
         ((g % 7 == TUESDAY) || (g % 7 == WEDNESDAY)) )
         tprintf( htmlMode, &reset, "  振替休日" );
}


void
checkAmerican( long g, int dd, int mm, int yy, int htmlMode, int *reset )
{
    register int    i      = 0;
    int             length = 41;

#if     0
    if ( dd == 1 )
        if ( mm % 3 == 1 )
            tprintf( htmlMode, reset, "  quater day [米]" );
#endif
    if ( mm == JANUARY ) {
        if ( ( yy >= 1986 ) && ( g == KingsBirthday( yy ) ) )
            tprintf( htmlMode, reset,
                     "  キング記念祝日(Martin Luther King Day)[米]" );
        if ( ( yy > 1934 ) && ( yy % 4 == 0 ) && ( dd == 20 ) )
            tprintf( htmlMode, reset,
                     "  大統領就任式(Inauguration Day)[米]" );
    }
    if ( mm == FEBRUARY ) {
        if ( g == waitangiDay( yy ) )
            tprintf( htmlMode, reset,
                     "  Waitangi Day [New Zealand]" );
        if ( g == australiaDay( yy ) )
            tprintf( htmlMode, reset,
                     "  Australia Day [Vic,WA,SA,Tas Aust]" );
        if ( g == WashingtonBirthday( yy ) )
            tprintf( htmlMode, reset,
                     "  President's Day [米]" );
        if ( g == daylightSavingsEndInBrazil( yy ) )
            tprintf( htmlMode, reset, "  夏時間終了 [ブラジル]" );
    }
    if ( ( mm >= FEBRUARY ) && ( mm <= JUNE ) ) {
        easterday = easter( yy );
        /*
         *      Easter の日付に依存して毎年変わる祝祭日
         */
        if ( g == septuagestima( yy ) )
            tprintf( htmlMode, reset, "  Septuagestima" );
        if ( g == sexagesima( yy ) )                        /* @@ */
            tprintf( htmlMode, reset, "  Sexagesima" );     /* @@ */
        if ( g == quinquagesima( yy ) )
            tprintf( htmlMode, reset, "  Quinquagesima" );
        if ( g == shroveMonday( yy ) )                      /* @@ */
            tprintf( htmlMode, reset, "  Shrove Monday" );  /* @@ */
        if ( g == quadragesima( yy ) )
            tprintf( htmlMode, reset, "  Quadragesima" );
        if ( g == mardiGras( yy ) ) {
            tprintf( htmlMode, reset, "  Mardi Gras" );
            tprintf( htmlMode, reset, "  Shrove Tuesday" );
            tprintf( htmlMode, reset, "  Pancake Day" );
        }
        if ( ( g >= ashWednesday( yy ) ) && ( g < easterday ) &&
             ( g % 7 != SUNDAY ) )
            tprintf( htmlMode, reset, "  Lent" );
        if ( g == ashWednesday( yy ) )
            tprintf( htmlMode, reset, "  Ash Wednesday" );
        if ( g == britishMothersDay( yy ) )
            tprintf( htmlMode, reset, "  母の日 [英]" );
        if ( g == passionSunday( yy ) )
            tprintf( htmlMode, reset, "  Passion Sunday" );
        if ( g == palmSunday( yy ) )
            tprintf( htmlMode, reset, "  Palm Sunday" );
        if ( g == holyThursday( yy ) ) {
            tprintf( htmlMode, reset, "  Holy Thursday" );
            tprintf( htmlMode, reset, "  Maundy Thursday" );
        }
        if ( g == goodFriday( yy ) )
            tprintf( htmlMode, reset, "  Good Friday" );
        if ( g == holySaturday( yy ) )
            tprintf( htmlMode, reset, "  Holy Saturday" );
        if ( g == easterMonday( yy ) )
            tprintf( htmlMode, reset, "  Easter Monday" );
        if ( g == easterday )
            tprintf( htmlMode, reset, "  復活祭(Easter)" );
        if ( g == lowSunday( yy ) )
            tprintf( htmlMode, reset, "  Low Sunday" );
        if ( g == pentecost( yy ) )
            tprintf( htmlMode, reset, "  Pentecost" );
        if ( g == rogationSunay( yy ) )                         /* @@ */
            tprintf( htmlMode, reset, "  Rogation Sunday" );    /* @@ */
        if ( ( g >= rogationDay( yy )  ) &&
             ( g <  ascensionDay( yy ) )    )
            tprintf( htmlMode, reset, "  Rogation Day" );
        if ( g == ascensionDay( yy ) )
            tprintf( htmlMode, reset, "  Ascension Day" );
        if ( g == whitsunday( yy ) )
            tprintf( htmlMode, reset, "  Whitsunday" );
        if ( g == whitmonday( yy ) )
            tprintf( htmlMode, reset, "  Whitmonday" );
        if ( g == trinity( yy ) )
            tprintf( htmlMode, reset, "  Trinity" );
        if ( g == corpusChristiDay( yy ) )
            tprintf( htmlMode, reset, "  Corpus Christi Day" );
    }
    if ( mm == MARCH ) {
        if ( ( yy <= 1934 ) && ( yy % 4 == 0 ) && ( dd == 4 ) )
            tprintf( htmlMode, reset,
                     "  大統領就任式(Inauguration Day)[米]" );
        if ( dd == 8 )
            tprintf( htmlMode, reset, "  国際女性デー" );
        if ( (yy >= 2007) && (g == daylightSavingsStart( yy )) )
            tprintf( htmlMode, reset, "  夏時間開始 [米]" );
        if ( g == daylightSavingsStartInEurope( yy ) )
            tprintf( htmlMode, reset, "  夏時間開始 [欧]" );
        if ( g == daylightSavingsEndInAustralia( yy ) )
            tprintf( htmlMode, reset, "  夏時間終了 [豪]" );
        if ( g == daylightSavingsEndInNewZealand( yy ) )
            tprintf( htmlMode, reset, "  夏時間終了 [ニュージーランド]" );
    }
    if ( mm == APRIL ) {
        if ( (yy <= 2006) && (g == daylightSavingsStart( yy )) )
            tprintf( htmlMode, reset, "  夏時間開始 [米]" );
    }
    if ( mm == MAY ) {
        if ( g == memorialDay( yy ) )
            tprintf( htmlMode, reset, "  Memorial Day [米]" );
        if ( ( g == NthKday( FIRST, MONDAY, MAY, yy ) ) ||
             ( g == NthKday( LAST,  MONDAY, MAY, yy ) )    )
            tprintf( htmlMode, reset, "  bank holiday [英]" );
    }
    if ( mm == JUNE ) {
        if ( g == NthKday( FIRST, WEDNESDAY, JUNE, yy ) )
            tprintf( htmlMode, reset, "  Derby Day [英]" );
        if ( (yy >= 1856) && (g == NthKday( SECOND, SUNDAY, JUNE, yy )) )
            tprintf( htmlMode, reset, "  花の日 [米]" );
        if ( g == russianDay( dd, mm, yy ) )
            tprintf( htmlMode, reset, "  ロシアの日" );
    }
    if ( mm == JULY ) {
        if ( (yy >= 1933) && (g == NthKday( SECOND, MONDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  大リーグ・オールスターゲーム [米]" );
        if ( (yy >= 1995) && (g == NthKday( FOURTH, MONDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  父母の日 [米]" );
        if ( (yy >= 2000) && (g == NthKday( LAST, FRIDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  システム管理者の日" );
    }
    if ( mm == AUGUST ) {
        if ( g == NthKday( FIRST, MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset, "  bank holiday [Scotland]" );
        if ( g == NthKday( LAST,  MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset, "  bank holiday [England, Wales]" );
        if ( g == NthKday( FOURTH, MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset,
                     "  Hurricane Supplication Day [the Virgin Islands]" );
    }
    if ( mm == SEPTEMBER ) {
        if ( g == laborDay( yy ) )
            tprintf( htmlMode, reset, "  Labor Day" );
        if ( g == harvestMoon( yy ) )
            tprintf( htmlMode, reset, "  Harvest Moon" );
    }
    if ( mm == OCTOBER ) {
        if ( (yy <= 2006) && (g == daylightSavingsEnd( yy )) )
            tprintf( htmlMode, reset, "  夏時間終了 [米]" );
        if ( g == daylightSavingsEndInEurope( yy ) )
            tprintf( htmlMode, reset, "  夏時間終了 [欧]" );
        if ( g == columbusDay( yy ) )
            tprintf( htmlMode, reset, "  コロンブス記念日(Columbus Day)" );
        if ( g == huntersMoon( yy ) )
            tprintf( htmlMode, reset, "  Hunter's Moon" );
        if ( g == NthKday( THIRD, SATURDAY, OCTOBER, yy ) )
            tprintf( htmlMode, reset, "  sweetest day [米]" );
        if ( g == NthKday( FOURTH, SUNDAY, OCTOBER, yy ) )
            tprintf( htmlMode, reset, "  義母の日 [米]" );
        if ( g == daylightSavingsStartInAustralia( yy ) )
            tprintf( htmlMode, reset, "  夏時間開始 [豪]" );
        if ( g == daylightSavingsStartInNewZealand( yy ) )
            tprintf( htmlMode, reset, "  夏時間開始 [ニュージーランド]" );
        if ( g == daylightSavingsStartInBrazil( yy ) )
            tprintf( htmlMode, reset, "  夏時間開始 [ブラジル]" );
    }
    if ( mm == NOVEMBER ) {
        if ( (yy >= 2007) && (g == daylightSavingsEnd( yy )) )
            tprintf( htmlMode, reset, "  夏時間終了 [米]" );
        if ( ( yy % 4 == 2 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            tprintf( htmlMode, reset, "  General Election Day [米]" );
        }
        if ( ( yy % 4 == 0 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            tprintf( htmlMode, reset, "  Election Day [米]" );
        }
        if ( g == loadMayorDay( yy ) ) {
            tprintf( htmlMode, reset, "  ロンドン市長就任式 [英]" );
        }
        if ( g == rememberanceDay( yy ) ) {
            tprintf( htmlMode, reset, "  Rememberance Day [英]" );
        }
        if ( g == thanksGivingDay( yy ) ) {
            tprintf( htmlMode, reset, "  感謝祭(Thanks Giving Day) [米]" );
        }
        if ( g == thanksGivingDay( yy ) + 1L ) {
            tprintf( htmlMode, reset, "  day after Thanksgiving [米]" );
        }
    }
    if ( ( ( mm == NOVEMBER ) || ( mm == DECEMBER ) ) ) {
        if ( g == advent( yy ) ) {
            tprintf( htmlMode, reset, "  Advent Sunday" );
        }
        else if ( ( g > advent( yy ) )                   &&
              ( ( mm == NOVEMBER ) || ( dd <= 23 ) )    ) {
            tprintf( htmlMode, reset, "  Advent" );
        }
    }

    while( hh[i].name ) {
        if ( hh[i].mm > mm )
            break;
        if ( hh[i].mm == mm ) {
            if ( hh[i].dd == dd ) {
                tprintf( htmlMode, reset, "  %s", hh[i].name );
            }
        }
        i++;
    }

    if ((yy >= 1946) && (dd >= 29) && isFullMoonDay(yy, mm, dd)) {
        // 同じ月に2回満月がある場合、2回目の方をブルームーンと
        // 呼ぶようになったのは1946年から
        for (i = 3; i > 0; i--) {
            if (isFullMoonDay(yy, mm, i)) {
                tprintf( htmlMode, reset, "  ブルームーン" );   // mm月2回目の満月の日
                break;
            }
        }
    }
}


int
checkGreek( char *buf,
            long g,
            int d, int m, int y,    /* Julian date     */
            int mm,                 /* Gregorian month */
            int yy,                 /* Gregorian year  */
            int htmlMode, int *reset )
{
    int     _d, _m, _y;
    size_t  l = strlen( buf );

    if ( g == nicaeanRuleEaster( yy ) )
        tsprintf( buf, htmlMode, reset, "  Nicaean Rule Easter" );
#if     0
    checkDateList( g, easternOrthodoxChristmas( yy ),
                   "Eastern Orthodox Christmas" );
#else
    if ( ( m == DECEMBER ) && ( d == 25 ) )
        tsprintf( buf, htmlMode, reset, "  Eastern Orthodox Christmas" );
#endif
    if ( ( y >= 1743 ) && ( m == APRIL ) && ( d == 2 ) )
        tsprintf( buf, htmlMode, reset, "  Jefferson's Birthday" );
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

    return ( (l != strlen( buf )) ? 1 : 0 );
}


int
checkIslamic( char *buf,
              long g,
              int d, int m, int y,  /* Islamic date   */
              int yy,               /* Gregorian year */
              int htmlMode )
{
    int reset = 1;

    buf[0] = '\0';

    if ( m == 9 )
        tsprintf( buf, htmlMode, &reset, "  断食月" );
    if ( (m == 1) && (d == 1) )
        tsprintf( buf, htmlMode, &reset, "  Islamic New Year %d", y );
    if ( (m == 1) && (d == 10) )
        tsprintf( buf, htmlMode, &reset, "  Ashura" );
    if ( (m == 3) && (d == 12) )
        tsprintf( buf, htmlMode, &reset,
                  "  Mulad-Al-Nabi (Mohammed's Birthday)" );
    if ( (m == 7) && (d == 26) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e-Mi\'raj" );
    if ( (m == 8) && (d == 15) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e-Bara\'t" );
    if ( (m == 9) && (d == 27) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e Qadr" );
    if ( (m == 10) && (d == 1) )
        tsprintf( buf, htmlMode, &reset, "  Id-al-Fitr (開斎節)" );
    if ( (m == 12) && (d == 10) )
        tsprintf( buf, htmlMode, &reset, "  Id-al-Adha" );

    return ( (buf[0] != '\0') ? 1 : 0 );
}

#if 0
long
daynameOnOrBefore( int dayname, long date )
{
    return ( date - ((date - dayname) % 7) );
}
#else
#define daynameOnOrBefore( dayname, date )  KdayOnOrBefore( date, dayname )
#endif

int
checkHebrew( char *buf,
             long g,
             int d, int m, int y,   /* Hebrew date     */
             int mm,                /* Gregorian month */
             int yy,                /* Gregorian year  */
             int htmlMode )
{
    int     _yy, _mm;                                               /* @@ */
    int     hanukkahYear, __mm, __dd, __yy, ___yy;                  /* @@ */
    long    hanukkah;                                               /* @@ */
    int     reset = 1;

    buf[0] = '\0';

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
            tsprintf( buf, htmlMode, &reset, "  Erev Hanukkah" );
        if ( (g >= hanukkah) && (g <= hanukkah + 7L) )
            tsprintf( buf, htmlMode, &reset, "  Hanukkah" );
    }                                                           /* @@ */
    if ( g == erevRoshHaShanah( yy ) )                          /* @@ */
        tsprintf( buf, htmlMode, &reset,"  Erev Rosh HaShanah");/* @@ */
    if ( (g == roshHaShanah) || (g == roshHaShanah2( yy )) )    /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Rosh HaShanah" );   /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah - 4 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Selichot (night)" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah + 7 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Shuvah" );  /* @@ */
    if ( g == tzomGedaliah( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Tzom Gedaliah" );   /* @@ */
    if ( g == erevYomKippur( yy ) )                             /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Yom Kippur" ); /* @@ */
    if ( g == yomKippur( yy ) )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom Kippur" );
    if ( g == erevSukkot( yy ) )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Sukkot" );     /* @@ */
    if ( (g == sukkot( yy )) || (g == sukkot2( yy )) )          /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Sukkot" );          /* @@ */
    if ( (g >= holHamoedSukkot( yy ) ) &&                       /* @@ */
         (g <= holHamoedSukkot4( yy ))    )                     /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Hol Hamoed Sukkot");/* @@ */
    if ( g == hoshannahRabbah( yy ) )                           /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Hoshannah Rabbah" );/* @@ */
    if ( g == sheminiAtzeret( yy ) )                            /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shemini Atzeret" ); /* @@ */
    if ( g == simchatTorah( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Simchat Torah" );   /* @@ */
    if ( g == erevPassover( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Passover" );   /* @@ */
    if ( g == passoverday )
        tsprintf( buf, htmlMode, &reset, "  Passover Begins" );
    if ( ( g > passoverday ) && ( g < passoverday + 6L ) ) {
        if ( (g >= passoverday + 2L) && (g == passoverday + 5L) )
            tsprintf( buf, htmlMode, &reset, "  Hol Hamoed Passover" );
        else
            tsprintf( buf, htmlMode, &reset, "  Passover" );
    }
    if ( g == passoverday + 7L )
        tsprintf( buf, htmlMode, &reset, "  Passover Ends" );
    if ( g == yomHaShoah( yy ) )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  YomHa Shoah" );     /* @@ */
    if ( g == lagBaOmer( yy ) )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Lag BaOmer" );      /* @@ */
    if ( g == yomYerushalim( yy ) )                             /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom Yerushalim" );  /* @@ */
    if ( g == erevShavuot( yy ) )                               /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Shavuot" );    /* @@ */
    if ( (g == shavuot( yy )) || (g == shavuot2( yy )) )        /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shavuot" );         /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 43 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Shekalim" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 30 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Zachor" );  /* @@ */
    if ( g == daynameOnOrBefore(SATURDAY, passoverday-14) - 7 ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Parah" );   /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 14 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat HaHodesh" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday -  1 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat HaGadol" ); /* @@ */
#if 0   /* 'Ta Anit Esther' と同じなので、削除 */
    if ( (((passoverday % 7) == 2) &&                           /* @@ */
          (g == passoverday - 33)     ) ||                      /* @@ */
         (g == passoverday - 31)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Fast of Esther" );  /* @@ */
    }                                                           /* @@ */
#endif
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday - 28)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shushan Purim" );   /* @@ */
    }                                                           /* @@ */
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday + 18)     ) ||                      /* @@ */
         (((passoverday % 7) == 6) &&                           /* @@ */
          (g == passoverday + 20)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom HaAtzma\'ut" ); /* @@ */
    }                                                           /* @@ */
    if ( g == tuBShvat( yy ) )
        tsprintf( buf,  htmlMode, &reset, "  Tu B' Shuvat" );   /* @@ */
                /* Tu B' Shevat ? */
                /*         ~      */
    if ( g == purim( yy ) )
        tsprintf( buf,  htmlMode, &reset, "  Purim" );
    if ( g == purim( yy ) - 1 )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Purim" );      /* @@ */
    if ( g == taAnitEsther( yy ) )
        tsprintf( buf, htmlMode, &reset, "  Ta Anit Esther" );
    if ( g == tishaBAvday )
        tsprintf( buf, htmlMode, &reset, "  Tisha B' Av" );
    if ( g == tishaBAvday - 21 )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Tzom Tammuz" );     /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, tishaBAvday ) )      /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Hazon" );   /* @@ */
    if ( g == tishaBAvday + 7 )                                 /* @@ */
        tsprintf( buf,  htmlMode, &reset, "  Shabbat Nahamu" ); /* @@ */

    if ( g == hebrewPentecost( yy ) )
        tsprintf( buf, htmlMode, &reset, "  Pentecost" );

    if ( kiddushHaHamah == 1 )
        tsprintf( buf, htmlMode, &reset, "  Kiddush HaHamah" );
    if ( talUmatar == 1 )                                           /* @@ */
        tsprintf( buf,  htmlMode, &reset, "  Tal Umatar (evening)");/* @@ */
    if ( m == 10 ) {                                                /* @@ */
        hebrewFromAbsolute( absoluteFromGregorian( 28, mm, yy ),    /* @@ */
                            &__dd, &__mm, &__yy );                  /* @@ */
        if ( (absoluteFromHebrew( 10, 10, __yy ) % 7) == 6 ) {      /* @@ */
            if ( d == 11 )                                          /* @@ */
                tsprintf( buf, htmlMode, &reset, "  Tzom Teveth" ); /* @@ */
        }                                                           /* @@ */
        else if ( d == 10 )                                         /* @@ */
            tsprintf( buf, htmlMode, &reset, "  Tzom Teveth" );     /* @@ */
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
            tprintf( htmlMode, &reset, "  Shabbat Shirah" );
    }

    /* 以下、2003.02.06 追加 (参考: hdate.lib) */
    switch ( m ) {
    case 7: /* Tishrey */
        switch ( d ) {
        case 1:
            tsprintf( buf, htmlMode, &reset, "  New year I" );
            break;
        case 2:
            tsprintf( buf, htmlMode, &reset, "  New year II" );
            break;
        case 3:
            if ( (g % 7) != SATURDAY ) {
                tsprintf( buf, htmlMode, &reset, "  Gdalya fast" );
            }
            break;
        case 4:
            if ( (g % 7) == SUNDAY ) {
                tsprintf( buf, htmlMode, &reset, "  Gdalya fast" );
            }
            break;
        case 10:
            tsprintf( buf, htmlMode, &reset, "  Day of Cipurim" );
            break;
        case 22:
            tsprintf( buf, htmlMode, &reset, "  Tora happiness" );
            break;
        }
        break;

    case 2:     /* Iyar */
        if ( yy >= 1948 ) {
            switch ( d ) {
            case 3:
            case 4:
                if ( (g % 7) == THURSDAY ) {
                    tsprintf( buf, htmlMode, &reset, "  Independence Day" );
                }
                break;
            case 5:
                if ( ((g % 7) != FRIDAY) && ((g % 7) != SATURDAY) ) {
                    tsprintf( buf, htmlMode, &reset, "  Independence Day" );
                }
                break;
            }
        }
        break;

    case 5:     /* Av */
        switch ( d ) {
        case 15:
            tsprintf( buf, htmlMode, &reset, "  Day of love" );
            break;
        }
        break;
    }

    return ( (buf[0] != '\0') ? 1 : 0 );
}


void
checkTsupo( long g, int d, int m, int y )
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
 *                      (新幹線の自由席特急料金は通年同一料金)
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

int
checkTermIdle( long g, int d, int m, int y )
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
trainService( long g, int d, int m, int y )
{
    int     kind = TERM_NORMAL;

    if ( ( y >= 1990 ) || ( ( y == 1989 ) && ( m >= 4 ) ) ) {
        /* この制度は 1989年4月1日から実施 */
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
    }

    if ( y >= 2005 ) {  /* 何年からか不明[暫定的に2005年からとしておく] */
        /*
         * 2007年現在、発売期間・利用期間は以下のようになっている
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
            printf( "\n- 18きっぷの発売/通用期間 -\n    " );
        if ( (m == 7) || (m == 12) ) {
            printf( "18きっぷ発売中。" );
            if ( (d >= 20) || ((m == 12) && (d >= 10)) )
                printf( "18きっぷが使えます\n" );
            else
                printf( "%sの18きっぷの使用可能期間はまだ始まっていません\n",
                        (m == 12) ? "冬" : "夏" );
        }
        else if ( m == 1 ) {
            if ( d <= 10 )
                printf( "18きっぷ発売中。18きっぷが使えます\n" );
            else if ( d <= 20 )
                printf( "冬の18きっぷの発売期間は終了していますが、18きっぷは"
                        "使えます\n" );
            else
                printf( "冬の18きっぷの使用可能期間は終了しています\n" );
        }
        else if ( m == 2 ) {
            if ( d >= 20 )
                printf( "18きっぷ発売中。春の18きっぷの使用可能期間はまだ"
                        "始まっていません\n" );
            else
                printf( "春の18きっぷの発売はまだ始まっていません\n" );
        }
        else if ( (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( "%sの18きっぷの発売期間は終了していますが、18きっぷは"
                        "使えます\n",
                        m == 4 ? "春" : "夏" );
            else
                printf( "%sの18きっぷの使用可能期間は終了しています\n",
                        m == 4 ? "春" : "夏" );
        }
        else if ( (m == 3) || (m == 8) )
            printf( "18きっぷ発売中。18きっぷが使えます\n" );
    }
    else if ( y >= 1983 ) {
        /* 18きっぷの発売は1983年が最初
         *   少なくとも1995年頃は、以下の発売期間・利用期間だった
         *
         *      春休み 
         *          発売期間:3月1日～4月10日 
         *          利用期間:3月10日～4月20日 
         *      夏休み 
         *          発売期間:7月1日～9月10日 
         *          利用期間:7月10日～9月20日 
         *      冬休み 
         *          発売期間:12月1日～1月10日 
         *          利用期間:12月10日～1月20日 
         */
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


int
checkRoman( char *buf, long g, int d, int m, int y, int htmlMode, int *reset )
{
    buf[0] = '\0';

    switch ( m ) {
    case MARCH:
    case MAY:
    case JULY:
    case OCTOBER:
        if ( d == 15 )
            tsprintf( buf, htmlMode, reset, "  ides" );
        break;
    default:
        if ( d == 13 )
            tsprintf( buf, htmlMode, reset, "  ides" );
        break;
    }

    return ( (buf[0] != '\0') ? 1 : 0 );
}


static int  kamiYoshiNichi[] = {
     1,  3,  5,  6,  8,  9, 13, 15,
    18, 20, 21, 24, 27, 30, 32, 33,
    35, 36, 37, 39, 41, 42, 43, 44,
    45, 47, 48, 51, 54, 55, 56, 57,
    59, -1
};

static int  daiMyouNichi[] = {
     5,  6,  7,  8,  9, 13, 15, 18, 20, 23, 28, 31,
    38, 40, 41, 42, 43, 45, 46, 47, 52, 54, 55, 56,
    57, -1
};

static int  kuENichi[][13] = {
    { 27, 50, -1, },                                        /*  1月 */
    { 15, 51, 57, -1, },                                    /*  2月 */
    {  0,  1,  2,  3,  4,  8, 16, 20, 32, 40, 44, 56, -1 }, /*  3月 */
    {  4,  7, 19, 31, 35, 42, 43, 54, 55, 59, -1, },        /*  4月 */
    { 42, 54, -1, },                                        /*  5月 */
    {  5, 42, 43, 53, 55, -1, },                            /*  6月 */
    { 21, 40, 56, -1, },                                    /*  7月 */
    { 45, 51, 57, -1, },                                    /*  8月 */
    { 10, 27, 28, 29, 30, 31, 32, 33, 34, 46, 50, -1, },    /*  9月 */
    {  1,  5, 13, 24, 25, 34, 35, 37, 48, 49, 53, 59, -1 }, /* 10月 */
    { 24, 42, 48, -1, },                                    /* 11月 */
    { 24, 43, 48, 59, -1, }                                 /* 12月 */
};

void
checkTenShaNichi( long g, int mm, int yy, int htmlMode, int *reset )
{
    long    rikkaday = 0, rittouday = 0;
    int     ks   = ( g + 14 ) % 60;
    int     eto  = ( g +  2 ) % 12;
    int     flag = OFF;
    int     i;

    switch ( mm ) {
    case FEBRUARY:
        if ( g < risshunday ) {
            if ( ks == 0 )  /* 甲子 */
                flag = ON;
        }
        else {
            if ( ks == 14 ) /* 戊寅 */
                flag = ON;
        }
        break;
    case MARCH:
    case APRIL:
        if ( ks == 14 )     /* 戊寅 */
            flag = ON;
        break;
    case MAY:
        rikkaday  = summerStartDay( yy );
        if ( g < rikkaday ) {
            if ( ks == 14 ) /* 戊寅 */
                flag = ON;
        }
        else {
            if ( ks == 30 ) /* 甲午 */
                flag = ON;
        }
        break;
    case JUNE:
    case JULY:
        if ( ks == 30 )     /* 甲午 */
            flag = ON;
        break;
    case AUGUST:
        if ( g < risshuuday ) {
            if ( ks == 30 ) /* 甲午 */
                flag = ON;
        }
        else {
            if ( ks == 44 ) /* 戊申 */
                flag = ON;
        }
        break;
    case SEPTEMBER:
    case OCTOBER:
        if ( ks == 44 )     /* 戊申 */
            flag = ON;
        break;
    case NOVEMBER:
        rittouday = winterStartDay( yy );
        if ( g < rittouday ) {
            if ( ks == 44 ) /* 戊申 */
                flag = ON;
        }
        else {
            if ( ks == 0 )  /* 甲子 */
                flag = ON;
        }
        break;
    case DECEMBER:
    case JANUARY:
        if ( ks == 0 )      /* 甲子 */
            flag = ON;
        break;
    }

    if ( flag == ON )
        tprintf( htmlMode, reset, "  天赦日" );

    for ( i = 0; kamiYoshiNichi[i] != -1; i++ ) {
        if ( ks == kamiYoshiNichi[i] ) {
            tprintf( htmlMode, reset, "  神吉日" );
            break;
        }
    }
    for ( i = 0; daiMyouNichi[i] != -1; i++ ) {
        if ( ks == daiMyouNichi[i] ) {
            tprintf( htmlMode, reset, "  大明日" );
            break;
        }
    }

    if ( (eto == 5) || (eto == 11) )    /* 巳, 亥 */
        tprintf( htmlMode, reset, "  重日" );

    if (  (ks <=  4)                ||  /* 甲子, 乙丑, 丙寅, 丁卯, 戊辰 */
         ((ks >= 15) && (ks <= 19)) ||  /* 己卯, 庚辰, 辛巳, 壬午, 癸未 */
         ((ks >= 45) && (ks <= 49))    )/* 己酉, 庚戌, 辛亥, 壬子, 癸丑 */
        tprintf( htmlMode, reset, "  天恩日" );
}


char    *
kuenichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "凶会日";
    int     ks = ( g + 14 ) % 60;
    int     i;

    if ( tsuki == 0 )
        tsuki = 12;
    for ( i = 0; kuENichi[tsuki - 1][i] != -1; i++ ) {
        if ( ks == kuENichi[tsuki - 1][i] ) {
            p = q;
            break;
        }
    }

    return ( p );
}

