/*
 *  tamo.h
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      7 March 2003
 *  Copyright (c) 2003  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: tamo.h $
 * Revision 1.16  2009/04/27  11:34:39  tsujimura543
 * bug fixed
 *
 * Revision 1.15  2003/11/11  09:11:42  tsujimura543
 * ユリウス暦、イスラム暦、ユダヤ暦の表示を最適化
 *
 * Revision 1.14  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.13  2003/05/27  12:20:06  tsujimura543
 * tamo_func.c 内の #define の一部を tamo.h に移動
 *
 * Revision 1.12  2003/05/26  07:47:50  tsujimura543
 * インド国民暦(国家暦)対応、ネパール太陰暦修正
 *
 * Revision 1.11  2003/05/06  09:33:53  tsujimura543
 * htmlMode が OFF のとき、キャンペーンを表示するようにした
 *
 * Revision 1.10  2003/04/25  11:25:23  tsujimura543
 * 磁気偏差を表示するようにした
 *
 * Revision 1.9  2003/04/24  04:29:28  tsujimura543
 * 関連リンクを表示するようにした(htmlモード時)
 *
 * Revision 1.8  2003/04/16  05:56:37  tsujimura543
 * データファイルを一定の規則にしたがって探索しオープンするようにした
 *
 * Revision 1.7  2003/03/31  11:24:31  tsujimura543
 * 和暦(太陽太陰暦)関連およびISO関連修正
 * フランス革命暦の表示可能期間を拡張
 *
 * Revision 1.6  2003/03/24  08:58:03  tsujimura543
 * (1) 和暦(太陰太陽暦)の表示可能期間を拡張
 * (2) 大暑と土用の丑の日が重なった場合、片方しか表示されない不具合を修正
 *
 * Revision 1.5  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.4  2003/03/14  09:37:59  tsujimura543
 * 関数を整理
 *
 * Revision 1.3  2003/03/12  06:49:40  tsujimura543
 * 活動メモ対応準備
 *
 * Revision 1.2  2003/03/11  12:13:53  tsujimura543
 * コメントを整理
 *
 * Revision 1.1  2003/03/11  01:38:18  tsujimura543
 * Initial revision
 *
 */

#ifndef __tamo_h__
#define __tamo_h__

#ifndef MAXFNAMELEN
# ifdef MAX_PATH
#  define MAXFNAMELEN   MAX_PATH
# else
#  define MAXFNAMELEN   BUFSIZ
# endif
#endif

#include "tamo_dates.h"

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


#define SK24_SHOUKAN     1  /* 小寒 */
#define SK24_DAIKAN      2  /* 大寒 */
#define SK24_RISSHUN     3  /* 立春 */
#define SK24_USUI        4  /* 雨水 */
#define SK24_KEICHITSU   5  /* 啓蟄 */
#define SK24_SHUNBUN     6  /* 春分 */
#define SK24_SEIMEI      7  /* 清明 */
#define SK24_KOKUU       8  /* 穀雨 */
#define SK24_RIKKA       9  /* 立夏 */
#define SK24_SHOUMAN    10  /* 小満 */
#define SK24_BOUSHU     11  /* 芒種 */
#define SK24_GESHI      12  /* 夏至 */
#define SK24_SHOUSHO    13  /* 小暑 */
#define SK24_TAISHO     14  /* 大暑 */
#define SK24_RISSHUU    15  /* 立秋 */
#define SK24_SHOSHO     16  /* 処暑 */
#define SK24_HAKURO     17  /* 白露 */
#define SK24_SHUUBUN    18  /* 秋分 */
#define SK24_KANRO      19  /* 寒露 */
#define SK24_SOUKOU     20  /* 霜降 */
#define SK24_RITTOU     21  /* 立冬 */
#define SK24_SHOUSETSU  22  /* 小雪 */
#define SK24_TAISETSU   23  /* 大雪 */
#define SK24_TOUJI      24  /* 冬至 */

#define leapyear( year )    ( ((year)%4==0) && \
                              (((year)%100!=0) || ((year)%400==0)) )

char    *getSekkiName2 _(( int day, int month, int year, int *sekki_no ));
void    getLunarCalendar2 _(( int *day, int *month, int *year, int *uruu ));
char                              *get_kyureki2 _(( int *d, int *m, int *y, int *u ));

BOOL    isFullMoonDay _(( long _yy, long _mm, long _dd ));
void    tamo_moon _(( long _yy, long _mm, long _dd,
                      long _hh, long _mmm, long _ss,
                      int flag ));
void    tamo_solar _(( long yy, long mm, long dd, int htmlMode ));

void    tamo_koyomi _(( int yy, int mm, int dd, int HH, int MM, int SS,
                        long g, int htmlMode, int printTime, int printTsupo));

void    flower _(( long g, int dd, int mm, int yy ));
void    tamo_information _(( int yy, int mm, int dd, long g,
                             int htmlMode, int printTrain ));

void    tamo_link _(( int yy, int mm, int dd, int htmlMode ));
void    tamo_campaign _(( int yy, int mm, int dd, long g, int htmlMode ));


void    showMethod _(( int yy, int mm, int dd, int HH, int MM, int SS ));
void    calendar _(( int yy, int mm, int dd, int HH, int MM, int SS ));

long    sekkiDay _(( int sekkiKind, int y ));
char    *zassetsu _(( int day, int month, int year ));

double  igrf _(( int year, int month, int day,
                 double latitude, double longitude ));
void    tamo_igrf _(( long yy, long mm, long dd, int htmlMode ));

void    memo _(( int dd, int mm, int yy ));

char    *decodeURL _(( const char *pp ));

void    printHeader _(( int yy, int mm, int dd,
                        int htmlMode, int withHeader ));
void    printFooter _(( int htmlMode, int withHeader ));
void    printMainStatement _(( int yy, int mm, int dd, int HH, int MM, int SS,
                               int printTime, int htmlMode ));
void    printTableHeader _(( int htmlMode ));
void    printTableFooter _(( int yy, int mm, int dd, int HH, int MM, int SS,
                             int htmlMode ));
void    printTableSeparator _(( int htmlMode ));

int     tprintf _(( int htmlMode, int *reset, const char *format, ... ));
int     tsprintf _(( char *buf, int htmlMode, int *reset,
                     const char *format, ... ));
FILE    *tfopen _(( const char *filename, const char *mode ));
#define tfclose(fp)     fclose(fp)

extern  char    execpath[];

#endif  /* __tamo_h__ */
