/*
 *  print.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      7 March 2003
 *  Copyright (c) 2003, 2004, 2005, 2006, 2007, 2012  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: print.c $
 * Revision 1.38  2012/10/12  10:49:56  tsujimura543
 * printBahaiCalendar() を修正
 *
 * Revision 1.37  2012/10/12  10:37:07  tsujimura543
 * バハイ暦に対応
 *
 * Revision 1.36  2012/10/12  09:04:38  tsujimura543
 * ペルシャ暦に対応した
 *
 * Revision 1.35  2007/02/14  08:48:53  tsujimura543
 * 標準出力をリダイレクトしている場合、かつ非htmlモードのとき、
 * 1行目にタイトル相当の文字列(何年何月何日の暦)を挿入するよう
 * にした
 *
 * Revision 1.34  2007/02/06  10:56:12  tsujimura543
 * copyright 表記をアップデート
 *
 * Revision 1.33  2006/05/29  05:12:32  tsujimura543
 * インターネット時間対応
 *
 * Revision 1.32  2005/05/13  13:11:56  tsujimura543
 * RSS アイコンを表示するようにした
 *
 * Revision 1.31  2004/10/25  00:36:40  tsujimura543
 * hi-ho の URL を変更
 *
 * Revision 1.30  2004/03/22  12:53:48  tsujimura543
 * PHP研究所の「今日は何の日」を追加
 *
 * Revision 1.29  2003/11/11  09:11:42  tsujimura543
 * ユリウス暦、イスラム暦、ユダヤ暦の表示を最適化
 *
 * Revision 1.28  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.27  2003/10/30  08:13:54  tsujimura543
 * Another HTML-lint で評価が100点になるように修正
 *
 * Revision 1.26  2003/10/24  01:35:04  tsujimura543
 * Solaris9 上でコンパイル、動作確認
 *
 * Revision 1.25  2003/06/05  11:08:21  tsujimura543
 * インド太陰暦、ネパール太陰暦の対応開始年月日の判定条件誤りを修正
 *
 * Revision 1.24  2003/06/05  10:58:46  tsujimura543
 * ネパール太陰暦、インド太陽暦の表示期間を過去方向に拡張(1970年まで遡行)
 *
 * Revision 1.23  2003/05/30  10:46:40  tsujimura543
 * ネパールの行事、祝祭日の表示を一部対応
 *
 * Revision 1.22  2003/05/30  09:55:37  tsujimura543
 * ネパール太陰暦、インド太陽暦の表示期間を拡張 (tithi.txt の拡張に伴う)
 *
 * Revision 1.21  2003/05/26  07:47:50  tsujimura543
 * インド国民暦(国家暦)対応、ネパール太陰暦修正
 *
 * Revision 1.20  2003/05/23  07:07:31  tsujimura543
 * 関連リンクを2件追加
 *
 * Revision 1.19  2003/05/20  05:55:50  tsujimura543
 * フランス革命暦を導入後すべての期間にわたって表示可能とした
 *
 * Revision 1.18  2003/04/25  11:22:40  tsujimura543
 * HTMLモード時の表示を若干変更
 *
 * Revision 1.17  2003/04/25  02:08:39  tsujimura543
 * 関連リンクを1件追加
 *
 * Revision 1.16  2003/04/24  09:46:25  tsujimura543
 * 関連リンクの表示を若干変更
 *
 * Revision 1.15  2003/04/24  04:29:28  tsujimura543
 * 関連リンクを表示するようにした(htmlモード時)
 *
 * Revision 1.14  2003/04/23  11:09:07  tsujimura543
 * 入梅、半夏生、土用の表示を太陽暦の方へ移す
 * (今回の修正で必要なくなった関数を削除)
 *
 * Revision 1.13  2003/04/16  05:56:37  tsujimura543
 * データファイルを一定の規則にしたがって探索しオープンするようにした
 *
 * Revision 1.12  2003/04/11  10:58:56  tsujimura543
 * (1) インド太陰暦表示の月名に何番目の月かを併記するようにした
 * (2) ネパール太陰暦表示を追加 (暫定)
 *
 * Revision 1.11  2003/04/02  10:28:42  tsujimura543
 * イスラム暦1年1月1日以前は表示しないように修正
 *
 * Revision 1.10  2003/04/02  10:20:09  tsujimura543
 * エチオピア暦をサポート
 *
 * Revision 1.9  2003/03/31  11:24:31  tsujimura543
 * 和暦(太陽太陰暦)関連およびISO関連修正
 * フランス革命暦の表示可能期間を拡張
 *
 * Revision 1.8  2003/03/24  08:58:03  tsujimura543
 * (1) 和暦(太陰太陽暦)の表示可能期間を拡張
 * (2) 大暑と土用の丑の日が重なった場合、片方しか表示されない不具合を修正
 *
 * Revision 1.7  2003/03/20  09:18:02  tsujimura543
 * 各種暦注の表示を追加
 *
 * Revision 1.6  2003/03/19  05:12:11  tsujimura543
 * tprintf() を修正
 *
 * Revision 1.5  2003/03/19  04:46:08  tsujimura543
 * 干支の出力方式を他の暦と同じにする
 *
 * Revision 1.4  2003/03/19  03:05:48  tsujimura543
 * 旧暦関係の出力方法を他の暦と同じ方式にする
 *
 * Revision 1.3  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.2  2003/03/14  09:56:25  tsujimura543
 * 活動メモ対応準備 #3
 *
 * Revision 1.1  2003/03/14  09:37:59  tsujimura543
 * Initial revision
 *
 */

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/print.c 1.38 2012/10/12 10:49:56 tsujimura543 Exp tsujimura543 $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined (__STDC__) || defined (WIN32)
#include <stdarg.h>
#else
#ifdef  UNIX
#include <varargs.h>
#endif
#endif
#ifdef  WIN32
#include <io.h>
#endif
#include "tamo.h"


/*
 *  ヘッダ部出力
 */

void
printHeader( int yy, int mm, int dd, int htmlMode, int withHeader )
{
    if ( htmlMode == ON ) {
        if ( withHeader == ON ) {
            fputs(
       "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n",
                   stdout );
            fputs( "<HTML lang=\"ja\">\n<HEAD>\n", stdout );
            fputs( "<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; ",
                   stdout );
#ifdef  UNIX
            fputs( "charset=EUC-JP\">\n", stdout );
#else
            fputs( "charset=Shift_JIS\">\n", stdout );
#endif
            fputs( 
    "<META http-equiv=\"Content-Script-Type\" content=\"text/javascript\">\n",
                   stdout );
            fputs( "<META name=\"keywords\" content=\"", stdout );
            fputs(
 "koyomi,today,moon phase,tithi,calendar,今日は何の日,暦,天文,旧暦,月齢\">\n",
                   stdout );
#ifdef  RIMNET
            fputs( "<LINK REL=\"alternate\" TYPE=\"application/rss+xml\" "
                   "TITLE=\"RSS\" HREF=\"/~tsupo/koyomi/koyomi.rdf\">\n",
                   stdout );
            fputs( "<LINK REV=\"MADE\" HREF=\"mailto:%74%73%75%70%6F%40%6E"
                   "%61%2E%72%69%6D%2E%6F%72%2E%6A%70\">\n", stdout );
            fputs( "<LINK REL=\"CONTENTS\" HREF=\"/~tsupo/tsupo.shtml\">\n",
                   stdout );
            fputs( "<LINK REL=\"PREV\" HREF=\"/~tsupo/anotherMemo/mt/\">\n",
                   stdout );
            fputs( "<LINK REL=\"NEXT\" HREF=\"/~tsupo/memo/\">\n", stdout );
            fputs(
            "<LINK REL=\"SHORTCUT ICON\" HREF=\"/~tsupo/image/tsupo.ico\">\n",
                   stdout );
#else   /* !RIMNET */
            fputs( "<LINK REL=\"alternate\" TYPE=\"application/rss+xml\" "
                   "TITLE=\"RSS\" HREF=\"/~tsujimura543/mt/koyomi.rdf\">\n",
                   stdout );
#endif  /* !RIMNET */
            fputs( "<TITLE>", stdout );
            printf( "%d年%2d月%2d日の暦", yy, mm, dd );
            fputs(  "</TITLE>\n</HEAD>\n\n<BODY>\n", stdout );
            printf( "<H1>%d年%2d月%2d日の暦</H1>\n", yy, mm, dd );
        }
    }
    else {
        if ( !isatty( fileno( stdout ) ) )
            printf( "%04d年%2d月%2d日の暦\n", yy, mm, dd );
    }
}

/*
 *  フッタ部出力
 */

void
printFooter( int htmlMode, int withHeader )
{
    if ( htmlMode == ON ) {
        if ( withHeader == ON )
            fputs( "</BODY>\n</HTML>\n", stdout );
    }
}


/*
 *  主文出力
 */

void
printMainStatement( int yy, int mm, int dd, int HH, int MM, int SS,
                    int printTime, int htmlMode )
{
    if ( htmlMode == ON )
        fputs(  "<P>\n", stdout );
    if ( printTime == ON )
        printf( "今日は %d年%2d月%2d日 で、時刻は %2d時%2d分%2d秒 です\n",
                yy, mm, dd, HH, MM, SS );
    else
        printf( "今日は %d年%2d月%2d日 です\n",
                yy, mm, dd );
    if ( htmlMode == ON ) {
        /* RSS 表示 */
#ifdef  RIMNET
        fprintf( stdout, "<a href=\"%s\">",
                 "http://www.na.rim.or.jp/~tsupo/koyomi/koyomi.rdf" );
        fprintf( stdout, "<img src=\"%s\" width=\"36\" height=\"14\" border=\"0\" alt=\"RDF\">",
                 "http://www.na.rim.or.jp/~tsupo/rss/image/rdf.png" );
#else   /* !RIMNET */
        fprintf( stdout, "<a href=\"%s\">",
                 "/~tsujimura543/mt/koyomi.rdf" );
        fprintf( stdout, "<img src=\"%s\" width=\"36\" height=\"14\" border=\"0\" alt=\"RDF\">",
                 "/images/rdf.png" );
#endif  /* !RIMNET */
        fputs( "</a> (RSS 1.0)", stdout );

        fputs(  "</P>\n", stdout );
    }
}


/*
 *  全体・テーブルヘッダ出力
 */

void
printTableHeader( int htmlMode )
{
    if ( htmlMode == ON ) {
        fputs( "<DIV ALIGN=\"CENTER\">\n", stdout );
        fputs(
           "<TABLE BORDER=\"0\" ALIGN=\"CENTER\" SUMMARY=\"暦\">\n<TR><TD>\n",
               stdout );
    }
}


/*
 *  全体・テーブルフッタ出力
 */

void
printTableFooter( int yy, int mm, int dd, int HH, int MM, int SS,
                  int htmlMode )
{
    if ( htmlMode == ON ) {
        fputs( "</TD></TR>\n<TR><TD COLSPAN=\"3\" ALIGN=\"CENTER\">\n",
               stdout );
        calendar( yy, mm, dd, HH, MM, SS );
        fputs( "</TD></TR>\n</TABLE></DIV>\n", stdout );
    }
}


/*
 *  全体・テーブル間仕切り部出力
 */

void
printTableSeparator( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "</TD><TD WIDTH=\"20\"><BR></TD><TD>\n", stdout );
}



/*
 *  各種情報部出力
 */

void
tamo_information( int yy, int mm, int dd, long g,
                  int htmlMode, int printTrain )
{
    /* 各種情報部・ヘッダ出力 */
    if ( htmlMode == ON )
        fputs( "<PRE>", stdout );

    /* JR営業情報出力 */
    if ( printTrain == ON )
        trainService( g, dd, mm, yy );

    /* 誕生石、誕生花・花言葉出力 */
    flower( g, dd, mm, yy );

    /* 各種情報部・フッタ出力 */
    if ( htmlMode == ON )
        fputs( "</PRE>\n", stdout );
}


/*
 *  行頭部出力
 */

void
printLineHeader( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "<TR><TD>", stdout );
}


/*
 *  行末部出力
 */

void
printLineFooter( int htmlMode )
{

    if ( htmlMode == ON )
        fputs( "</TD></TR>", stdout );
    putchar( '\n' );
}


/*
 *  こよみ部・テーブルヘッダ出力
 */

void
printKoyomiTableHeader( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "<TABLE BORDER=\"0\" ALIGN=\"CENTER\" SUMMARY=\"基本情報\">\n",
               stdout );
}


/*
 *  こよみ部・テーブルフッタ出力
 */

void
printKoyomiTableFooter( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "</TABLE>\n", stdout );
}


/*
 *  こよみ部・ユリウス日出力
 */

void
printJulianDate( long g, int HH, int MM, int SS, int htmlMode, int printTime )
{
    int h;

    printLineHeader( htmlMode );
    printf( "ユリウス日%s%ld日",
            htmlMode == ON ? "</TD><TD COLSPAN=2>"
                           : "            ",
            g + 1721425L );
    if ( printTime == ON ) {
        h = HH - 9; /* ローカル時間が JST であることを仮定 */
        if ( h < 0 ) {
            h += 24;
        }
        printf( "  %02d時%02d分%02d秒 UTC", h, MM, SS );
    }
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・TSUPO形式出力
 */

void
printTsupoDate( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "TSUPO形式%s%s",
            htmlMode == ON ? "</TD><TD>"
                           : "       ",
            tsupodate( dd, mm, yy ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkTsupo( g, dd, mm, yy );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ISO形式出力
 */

void
printIsoDate( long g, int yy, int mm, int dd, int htmlMode )
{
    int     a1 = 0, a2 = 0, a3 = yy;

    printLineHeader( htmlMode );
    isoFromAbsolute( g, &a1, &a2, &a3 );
    printf( "ISO形式%s%4d年第%2d週第%2d日",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "           ",
            a3, a1, a2 );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・グレゴリオ暦出力
 */

void
printGregorianCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    int reset = 1;

    printLineHeader( htmlMode );
    printf( "グレゴリオ暦%s%4d年%2d月(%s)%2d日",
            htmlMode == ON ? "</TD><TD>"
                           : "      ",
            yy, mm, englishMonthName(mm), dd );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    tprintf( htmlMode, &reset, "  %s曜日", weekday(g) );
    checkAmerican( g, dd, mm, yy, htmlMode, &reset );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ユリウス暦出力
 */

void
printJulianCalendar( long g, int yy, int mm, int htmlMode )
{
    int     a1, a2, a3;
    int     reset = 1;
    char    buf[BUFSIZ];
    int     checkedOut;

    julianFromAbsolute( g, &a1, &a2, &a3 );
    checkedOut =  checkRoman( buf, g, a1, a2, a3, htmlMode, &reset );
    checkedOut += checkGreek( buf, g, a1, a2, a3, mm, yy, htmlMode, &reset );

    printLineHeader( htmlMode );

    printf( "ユリウス暦%s%4d年%2d月(%s)%2d日",
            htmlMode == OFF ? "        " :
            checkedOut == 0 ? "</TD><TD COLSPAN=\"2\">"
                            : "</TD><TD>",
	        a3, a2, latinMonthName(a2), a1 );

    if ( checkedOut ) {
        if ( htmlMode == ON )
            fputs( "</TD><TD>", stdout );
        fputs( buf, stdout );
    }

    printLineFooter( htmlMode );
}


/*
 *  こよみ部・イスラム暦出力
 */

void
printIslamicCalendar( long g, int yy, int htmlMode )
{
    int     a1, a2, a3;
    char    buf[BUFSIZ];
    int     checkedOut;

    if ( g < absoluteFromGregorian( 19, 7, 622 ) ) {
        /* イスラム暦 1年1月1日以前の場合 */
        return;
    }

    islamicFromAbsolute( g, &a1, &a2, &a3 );
    checkedOut = checkIslamic( buf, g, a1, a2, a3, yy, htmlMode );

    printLineHeader( htmlMode );

    printf( "イスラム暦%s%4d年%2d月(%s)%2d日",
            htmlMode == OFF ? "        " :
            checkedOut == 0 ? "</TD><TD COLSPAN=\"2\">"
                            : "</TD><TD>",
            a3, a2, islamicMonthName(a2), a1 );

    if ( checkedOut ) {
        if ( htmlMode == ON )
            fputs( "</TD><TD>", stdout );
        fputs( buf, stdout );
    }

    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ユダヤ暦出力
 */

void
printHebrewCalendar( long g, int yy, int mm, int htmlMode )
{
    int     a1, a2, a3;
    char    buf[BUFSIZ];
    int     checkedOut;

    hebrewFromAbsolute( g, &a1, &a2, &a3 );
    checkedOut = checkHebrew( buf, g, a1, a2, a3, mm, yy, htmlMode );

    printLineHeader( htmlMode );

    printf( "ユダヤ暦%s%4d年%2d月(%s)%2d日",
            htmlMode == OFF ? "          " :
            checkedOut == 0 ? "</TD><TD COLSPAN=\"2\">"
                            : "</TD><TD>",
            a3, a2, hebrewMonthName(a2, a3), a1 );

    if ( checkedOut ) {
        if ( htmlMode == ON )
            fputs( "</TD><TD>", stdout );
        fputs( buf, stdout );
    }

    printLineFooter( htmlMode );
}


/*
 *  こよみ部・マヤ長期暦出力
 */

void
printMayaCalendar( long g, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "マヤ長期暦%s%s\t%s %s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "        ",
            mayaFromAbsolute( g ),
            tsolkinFromAbsolute( g ),
            haabuFromAbsolute( g )    );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・マヤ短期暦出力
 */

void
printKatunCalendar( long g, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "マヤ短期暦%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "     ",
            katunFromAbsolute( g ) );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・フランス革命暦出力
 */

void
printFrenchCalendar( long g, int yy, int mm, int dd, int HH, int MM, int SS,
                     int htmlMode, int printTime )
{
    printLineHeader( htmlMode );
    printf( "フランス革命暦%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "  ",
            fdate( g, dd, mm, yy, HH, MM, SS, printTime, htmlMode ) );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・和暦(太陽暦)出力
 */

void
printJapaneseCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "和暦(太陽暦)%s%s",
            htmlMode == ON ? "</TD><TD>" : "    ",
            wareki( dd, mm, yy, 0 ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkJapanese( g, dd, mm, yy, htmlMode );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・和暦(太陰太陽暦)出力
 */

void
printOldJapaneseCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    int     a1, a2, a3, uruu;

    if ( ( ( yy >  1975 ) && ( yy < 2064 ) )                   ||
         ( ( yy == 1975 ) && ( ( mm >  3 ) ||
                               ( mm == 3 ) && ( dd >= 13 ) ) ) ||
         ( ( yy == 2064 ) && ( ( mm <  9 ) ||
                               ( mm == 9 ) && ( dd <= 16 ) ) )    ) {
        printLineHeader( htmlMode );
        a1 = dd; a2 = mm; a3 = yy;
        getLunarCalendar( &a1, &a2, &a3, &uruu );
        printf( "%s太陰太陽暦%s%s",
                htmlMode == ON ? "("
                               : "     ",
                htmlMode == ON ? ")</TD><TD>"
                               : " ",
                wareki( a1, a2, a3, uruu ) );
        if ( htmlMode == ON )
            fputs( "</TD><TD>", stdout );
        checkKyureki( g, a1, a2, a3, uruu, htmlMode );
        printLineFooter( htmlMode );
    }
    else if ( ( ( yy >  1870 ) && ( yy <= 2098 ) )                 ||
              ( ( yy == 1870 ) && ( ( mm >  2 ) ||
                                    ( mm == 2 ) && ( dd >= 1 ) ) )    ) {
        printLineHeader( htmlMode );
        a1 = dd; a2 = mm; a3 = yy;
        getLunarCalendar2( &a1, &a2, &a3, &uruu );
        printf( "%s太陰太陽暦%s%s",
                htmlMode == ON ? "("
                               : "     ",
                htmlMode == ON ? ")</TD><TD>"
                               : " ",
                wareki( a1, a2, a3, uruu ) );
        if ( htmlMode == ON )
            fputs( "</TD><TD>", stdout );
        checkKyureki( g, a1, a2, a3, uruu, htmlMode );
        printLineFooter( htmlMode );
    }
}


/*
 *  こよみ部・干支出力
 */

void
printEtoCalendar( long g, int yy, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "     干支%s%s",
            htmlMode == ON ? "</TD><TD>"
                           : "       ",
            eto( g, yy, htmlMode ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkEto( g, htmlMode );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・皇紀出力
 */

void
printKigenCalendar( int yy, int mm, int dd, int htmlMode )
{
    if ( htmlMode == OFF ) {
        printf( "     皇紀         %4d年%2d月%2d日\n", yy + 660, mm, dd );
    }
}


/*
 *  こよみ部・仏教紀元出力
 */

void
printBuddhaCalendar( int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "仏教紀元%s%4d年%2d月%2d日",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "          ",
            yy + 543, mm, dd );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ネパール太陽暦出力
 */

void
printNepaliCalendar( long g, int yy, int mm, int dd, int HH, int MM, int SS,
                     int htmlMode, int printTime )
{
    char    *p, *q, *r;
    int     reset = 1;

    p = nepdate( g, dd, mm, yy, HH, MM, SS, printTime );
    if ( ( q = strchr( p, '*' ) ) != NULL ) {
        *q++ = '\0';
    }

    printLineHeader( htmlMode );
    printf( "ネパール暦%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "        ",
            p );
    if ( q && (strlen(q) >= 20))
        tprintf( htmlMode, &reset, "                        " );
    while  ( q ) {
        r = strchr( q, '*' );
        if ( r ) {
            *r++ = '\0';
        }
        tprintf( htmlMode, &reset, "  %s", q );
        q = r;
    }
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ネパール太陰暦出力
 */

void
printNepaliLunarCalendar( int yy, int mm, int dd, int HH, int MM, int SS,
                          int htmlMode )
{
    if ( ((yy == 1970) && !((mm ==  1) && (dd ==  1)))     ||
         ((yy >= 1971) && (yy <= 2012))                    ||
         ((yy == 2013) && ( (mm <= 11)                ||
                           ((mm == 12) && (dd <= 14))    ))   ) {
        char    *p = nepaliLunarDate( dd, mm, yy, HH, MM, SS );
        char    *q, *r;
        int     reset = 1;

        if ( p ) {
            if ( ( q = strchr( p, '*' ) ) != NULL ) {
                *q++ = '\0';
            }

            printLineHeader( htmlMode );
            printf( "ネパール太陰暦%s%s",
                    htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                                   : "    ",
                    p );
            if ( q && (strlen(q) >= 20))
                tprintf( htmlMode, &reset, "                        " );
            while  ( q ) {
                r = strchr( q, '*' );
                if ( r ) {
                    *r++ = '\0';
                }
                tprintf( htmlMode, &reset, "  %s", q );
                q = r;
            }
            printLineFooter( htmlMode );
        }
    }
}


/*
 *  こよみ部・インド太陰暦出力
 */

void
printIndianLunarCalendar( int yy, int mm, int dd, int HH, int MM, int SS,
                          int htmlMode )
{
    if ( ((yy == 1970) && !((mm ==  1) && (dd ==  1)))     ||
         ((yy >= 1971) && (yy <= 2012))                    ||
         ((yy == 2013) && ( (mm <= 11)                ||
                           ((mm == 12) && (dd <= 14))    ))   ) {
        char    *p = indianLunarDate( dd, mm, yy, HH, MM, SS );

        if ( p ) {
            printLineHeader( htmlMode );
            printf( "インド太陰暦%s%s",
                    htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                                   : "      ",
                    p );
            printLineFooter( htmlMode );
        }
    }

    if ( ((yy == 1957) && ((mm >= 4) || ((mm == 3) && (dd >=21)))) ||
         ( yy >= 1958) ) {
            printLineHeader( htmlMode );
            printf( "インド国民暦%s%s",
                    htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                                   : "      ",
                    indianNationalDate( dd, mm, yy ) );
            printLineFooter( htmlMode );
    }
}


/*
 *  こよみ部・エチオピア暦出力
 */

void
printCopticCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "エチオピア暦%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "      ",
            copdate( g, dd, mm, yy ) );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・ペルシャ暦出力
 */

void
printPersianCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    char    *p = persianCalendar( g, yy, mm, dd );
    if ( p && *p ) {
        printLineHeader( htmlMode );
        printf( "ペルシャ暦%s%s",
                htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                               : "        ",
                p );
        printLineFooter( htmlMode );
    }
}


/*
 *  こよみ部・バハイ暦出力
 */

void
printBahaiCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    int     bY = 0, bM = 0, bD = 0;
    char    *p = bahaiCalendar( g, yy, mm, dd, &bY, &bM, &bD );
    if ( p && *p ) {
        char    buf[BUFSIZ];
        int     checkedOut =
                    checkBahai( buf, bD, bM, bY, dd, mm, yy, htmlMode );

        printLineHeader( htmlMode );
        printf( "バハイ暦%s%s",
                htmlMode == OFF ? "          " :
                checkedOut == 0 ? "</TD><TD COLSPAN=\"2\">"
                                : "</TD><TD>",
                p );

        if ( checkedOut ) {
            if ( htmlMode == ON )
                fputs( "</TD><TD>", stdout );
            fputs( buf, stdout );
        }

        printLineFooter( htmlMode );
    }
}


/*
 *  こよみ部・Swatchインターネット時間出力
 */

void
printBeat( int HH, int MM, int SS, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "インターネット時間%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "      ",
            beatFromAbsolute( HH, MM, SS ) );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部・星座出力
 */

void
printZodiac( long g, int yy, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "星座%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "            ",
            zodiac( g, yy ) );
    printLineFooter( htmlMode );
}


/*
 *  こよみ部出力
 */

void
tamo_koyomi( int yy, int mm, int dd, int HH, int MM, int SS, long g,
             int htmlMode, int printTime, int printTsupo )
{
    /* こよみ部・テーブルヘッダ出力 */
    printKoyomiTableHeader( htmlMode );

    /* ユリウス日、時刻(UTC)出力 */
    printJulianDate( g, HH, MM, SS, htmlMode, printTime );

    /* TSUPO形式出力 */
    if ( printTsupo == ON ) {
        printTsupoDate( g, yy, mm, dd, htmlMode );
    }

    /* ISO形式出力 */
    printIsoDate( g, yy, mm, dd, htmlMode );

    /* グレゴリオ暦出力 */
    printGregorianCalendar( g, yy, mm, dd, htmlMode );

    /* ユリウス暦出力 */
    printJulianCalendar( g, yy, mm, htmlMode );

    /* イスラム暦出力 */
    printIslamicCalendar( g, yy, htmlMode );

    /* ユダヤ暦出力 */
    printHebrewCalendar( g, yy, mm, htmlMode );

    /* マヤ暦出力 */
    /*   --- マヤ関連学会での定説に基づくマヤ長期暦 */
    printMayaCalendar( g, htmlMode );

    /*   --- マヤ関連学会での定説に基づくマヤ短期暦 */
    printKatunCalendar( g, htmlMode );

    /* フランス革命暦出力 */
    printFrenchCalendar( g, yy, mm, dd, HH, MM, SS, htmlMode, printTime );

    /* 和暦(太陽暦)出力 */
    printJapaneseCalendar( g, yy, mm, dd, htmlMode );

    /* 和暦(太陰太陽暦)出力 */
    printOldJapaneseCalendar( g, yy, mm, dd, htmlMode );

    /* 干支出力 */
    printEtoCalendar( g, yy, htmlMode );

    /* 皇紀出力 */
    printKigenCalendar( yy, mm, dd, htmlMode );

    /* 仏教紀元出力 */
    printBuddhaCalendar( yy, mm, dd, htmlMode );

    /* ネパール暦出力 */
    printNepaliCalendar( g, yy, mm, dd, HH, MM, SS, htmlMode, printTime );

    /* ネパール太陰暦出力 */
    printNepaliLunarCalendar( yy, mm, dd, HH, MM, SS, htmlMode );

    /* インド太陰暦出力 */
    printIndianLunarCalendar( yy, mm, dd, HH, MM, SS, htmlMode );

    /* エチオピア暦出力 */
    printCopticCalendar( g, yy, mm, dd, htmlMode );

    /* ペルシャ暦出力 */
    printPersianCalendar( g, yy, mm, dd, htmlMode );

    /* バハイ暦出力 */
    printBahaiCalendar( g, yy, mm, dd, htmlMode );

    /* Swatchインターネット時間出力 */
    printBeat( HH, MM, SS, htmlMode );

    /* 星座出力 */
    printZodiac( g, yy, htmlMode );

    /* こよみ部・テーブルヘッダ出力 */
    printKoyomiTableFooter( htmlMode );
}


/*
 *  関連ページ(リンク集)表示
 */

void
tamo_link( int yy, int mm, int dd, int htmlMode )
{
#if 0
    static char *monthName[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct",
        "Nov", "Dec"
    };
#endif

    if ( htmlMode ) {
        printf( "<HR>\n<P>\n<STRONG>関連ページ</STRONG>\n</P>\n<UL>\n" );
        printf( "<LI><A HREF=\"http://www.google.co.jp/search?sourceid=nav"
                "client&amp;hl=ja&amp;ie=UTF-8&amp;oe=UTF-8&amp;q=%d%%E6%%"
                "9C%%88%d%%E6%%97%%A5\">Google で %2d月%2d日 を検索</A>\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://ja.wikipedia.org/wiki/%d%%E6%%9C%%88%d"
                "%%E6%%97%%A5\">%2d月%2d日 今日は何の日</A> "
                "(ウィキペディア)\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://www.nnh.to/%02d/%02d.html\">%2d月%2d日"
                " 今日は何の日～毎日が記念日～</A> "
                "(日本記念日學會/富山いづみさん)\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://koyomi.vis.ne.jp/cgi/today/today.php?"
                "syy=%d&amp;smm=%d&amp;sdd=%d\">今日は何の日</A> "
                "(かわうそ＠暦さん)\n",
                yy, mm, dd );
        printf(
#if 0
                "<LI><A HREF=\"http://town.hi-ho.ne.jp/cgi-bin/town/cale/"
                "top_link.pl?month=%s&amp;day=%d&amp;member=2&amp;msnflag="
                "0\">日めくりカレンダー (%2d月%2d日)</A> (Panasonic Hi-Ho)",
                monthName[mm - 1], dd, mm, dd
#else
 /* http://kurashi.hi-ho.ne.jp/cale/index.html?year=2004&month=10&day=23 */
                "<LI><A HREF=\"http://kurashi.hi-ho.ne.jp/cale/index.html?"
                "year=%d&amp;month=%d&amp;day=%d\">日めくりカレンダー "
                "(%4d年%2d月%2d日)</A> (Panasonic Hi-Ho)",
                yy, mm, dd, yy, mm, dd
#endif
              );
        printf( "<LI><A HREF=\"http://www.php.co.jp/today/"
                "%02d-%02d.html\">今日は何の日 %2d月%2d日</A> (PHP研究所)",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://www.moonsystem.to/calendar/cgi/"
                "calendar2.cgi?year=%d&amp;month=%d\">月齢カレンダー "
                "(%d年%2d月)</A> (The Moon Age Calendar)\n",
                yy, mm, yy, mm );
        printf( "</UL>\n" );
    }
}


/*
 *  暦注、祝祭日、記念日等の出力
 */

int
tprintf( int htmlMode, int *reset, const char *format, ... )
{
    va_list     args;
    int         len = strlen( format );
    int         r;
    static int  lineLen = 0;

    if ( *reset ) {
        lineLen = 0;
    }

    if ( (lineLen + len >= 28)              ||
         (htmlMode && (lineLen + len > 12))    ) {
        if ( htmlMode && !(*reset) )
            fputs( "<BR>", stdout );
        putchar( '\n' );
        if ( !htmlMode )
            fputs( "                                       ", stdout );
        lineLen = 0;
    }
    *reset  = 0;

    va_start( args, format );
    r = vprintf( format, args );
    lineLen += r;
    va_end( args );

    return ( r );
}

int
tsprintf( char *buf, int htmlMode, int *reset, const char *format, ... )
{
    va_list     args;
    int         len = strlen( format );
    int         r, ll = 0;
    static int  lineLen = 0;

    if ( *reset ) {
        lineLen = 0;
        buf[0] = '\0';
    }
    else
        ll = strlen(buf);

    if ( (lineLen + len >= 28)              ||
         (htmlMode && (lineLen + len > 12))    ) {
        if ( htmlMode && !(*reset) ) {
            strcat( buf, "<BR>" );
            ll += strlen("<BR>");
        }
        buf[ll++] = '\n';
        buf[ll]   = '\0';
        if ( !htmlMode ) {
            strcat ( buf, "                                       " );
            ll += strlen("                                       ");
        }
        lineLen = 0;
    }
    *reset  = 0;

    va_start( args, format );
    r = vsprintf( &buf[ll], format, args );
    lineLen += r;
    va_end( args );

    return ( r );
}


/*
 *  データファイルオープン
 *
 *      以下の順序でファイルを探索する
 *        (1) 今回起動した tamo.exe の存在するディレクトリ
 *        (2) 環境変数 KOYOMI の示すディレクトリ
 *        (3) 今回起動した tamo.exe の存在するディレクトリの直下の koyomi ディ
 *            レクトリ
 *        (4) カレントディレクトリ
 */

FILE    *
tfopen( const char *filename, const char *mode )
{
    FILE    *fp = NULL;
    char    *p  = getenv( "KOYOMI" );
    char    target[MAXFNAMELEN];

    if ( execpath && execpath[0] ) {
        sprintf( target, "%s/%s", execpath, filename );
        fp = fopen( target, mode );
    }

    if ( !fp ) {
        if ( p && *p ) {
            sprintf( target, "%s/%s", p, filename );
            fp = fopen( target, mode );
        }
    }

    if ( !fp ) {
        if ( execpath && execpath[0] ) {
            sprintf( target, "%s/koyomi/%s", execpath, filename );
            fp = fopen( target, mode );
        }
    }

    if ( !fp ) {
        sprintf( target, "./%s", filename );
        fp = fopen( target, mode );
    }

    return ( fp );
}


