/*
 *  calendar.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      7 March 2003
 *  Copyright (c) 2003  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: calendar.c $
 * Revision 1.7  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.6  2003/10/30  08:13:54  tsujimura543
 * Another HTML-lint で評価が100点になるように修正
 *
 * Revision 1.5  2003/10/24  01:35:04  tsujimura543
 * Solaris9 上でコンパイル、動作確認
 *
 * Revision 1.4  2003/04/23  06:09:29  tsujimura543
 * HTMLモード時、紀元前は対応していない旨、表示するようにした
 *
 * Revision 1.3  2003/03/17  05:13:25  tsujimura543
 * HTML出力内容を整理
 *
 * Revision 1.2  2003/03/11  12:13:53  tsujimura543
 * コメントを整理
 *
 * Revision 1.1  2003/03/11  01:42:04  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamo.h"


void
calendar( int yy, int mm, int dd, int HH, int MM, int SS )
{
    long    g = absoluteFromGregorian( 1, mm, yy );
    long    w = g % 7;  /* 当該月の1日の曜日 */
    long    l = lastDayOfGregorianMonth( mm, yy );
    long    a = 0, b = 0;
    int     d;
    int     by, bm, bd;
    int     i, j;

    printf( "<TABLE BORDER=\"1\" SUMMARY=\"年月日を指定してください\">\n" );
    printf( "<TR><TD ALIGN=\"CENTER\" COLSPAN=\"7\">\n " );
    if ( yy > 1 ) {
        printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1年前</A> ",
                yy - 1, mm, dd );
    }
    else {
        printf( "1年前 " );
    }
    if ( (yy > 1) || (mm > 1) ) {
        printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1月前</A> ",
                mm ==  1 ? yy - 1 : yy, mm ==  1 ? 12 : mm - 1, dd );
    }
    else {
        printf( "1月前 " );
    }
    printf( "* <STRONG>%4d年%2d月</STRONG> * ", yy, mm );
    printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1月後</A> ",
            mm == 12 ? yy + 1 : yy, mm == 12 ?  1 : mm + 1, dd );
    printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1年後</A> \n",
            yy + 1, mm, dd );
    printf( "</TD></TR>\n" );

    printf( "<TR>\n" );
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">日</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">月</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">火</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">水</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">木</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">金</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">土</TD>\n");
    printf( "</TR>\n" );

    if ( w == 0 )
        d = 1;
    else {
        d = -w + 1;
        b = absoluteFromGregorian( d, mm, yy );
        gregorianFromAbsolute( b, &bd, &bm, &by );
    }
    for ( i = 0; i < 6; i++ ) {
        for ( j = 0; j < 7; j++ ) {
            if ( j == 0 ) {
                printf( "<TR>\n" );
            }

            printf( "<TD ALIGN=\"RIGHT\">" );
            if ( d <= 0 ) {
                if ( by <= 0 ) {
                    printf( "%2d", bd + 1 );
                }
                else {
                    printf(
                        "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">%2d</A>",
                            by, bm, bd, bd );
                }
                bd++;
            }
            else if ( d > l ) {
                if ( a == 0 ) {
                    a = absoluteFromGregorian( 1, mm + 1, yy );
                    gregorianFromAbsolute( a, &bd, &bm, &by );
                }
                printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">%2d</A>",
                        by, bm, bd, bd );
                bd++;
            }
            else {
                printf(
       "<STRONG><A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">%2d</A></STRONG>",
                        yy, mm, d, d );
            }
            printf( "</TD>\n" );

            if ( j == 6 ) {
                printf( "</TR>\n" );
            }
            d++;
        }
        if ( d > l )
            break;
    }

    printf("</TABLE>\n" );

    printf("<DIV ALIGN=\"CENTER\">\n" );
    printf("<FORM METHOD=\"GET\" ACTION=\"tamo.cgi\">\n" );
    printf("<INPUT type=\"text\" name=\"y\" size=4 value=%d>年 ", yy );
    printf("<INPUT type=\"text\" name=\"m\" size=2 value=%d>月 ", mm );
    printf("<INPUT type=\"text\" name=\"d\" size=2 value=%d>日 ", dd  );
    printf("<INPUT type=\"text\" name=\"H\" size=2 value=%d>時 ", HH );
    printf("<INPUT type=\"text\" name=\"M\" size=2 value=%d>分 ", MM );
    printf("<INPUT type=\"text\" name=\"S\" size=2 value=%d>秒<BR>\n", SS);
    printf("<INPUT type=\"submit\" accesskey=\"d\" value=\"指定年月日時分秒の暦を表示\"> ");
    printf("<INPUT type=\"reset\"  accesskey=\"r\" value=\"リセット\"><BR>\n");
    printf("<INPUT type=\"button\" accesskey=\"n\" value=\"現時点の暦を表示\" "
           "onClick=\"window.navigate(&quot;tamo.cgi&quot;)\" "
           "onKeyPress=\"window.navigate(&quot;tamo.cgi&quot;)\">\n" );
    printf("</FORM></DIV>\n" );
}

