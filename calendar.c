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
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.6  2003/10/30  08:13:54  tsujimura543
 * Another HTML-lint �ŕ]����100�_�ɂȂ�悤�ɏC��
 *
 * Revision 1.5  2003/10/24  01:35:04  tsujimura543
 * Solaris9 ��ŃR���p�C���A����m�F
 *
 * Revision 1.4  2003/04/23  06:09:29  tsujimura543
 * HTML���[�h���A�I���O�͑Ή����Ă��Ȃ��|�A�\������悤�ɂ���
 *
 * Revision 1.3  2003/03/17  05:13:25  tsujimura543
 * HTML�o�͓��e�𐮗�
 *
 * Revision 1.2  2003/03/11  12:13:53  tsujimura543
 * �R�����g�𐮗�
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
    long    w = g % 7;  /* ���Y����1���̗j�� */
    long    l = lastDayOfGregorianMonth( mm, yy );
    long    a = 0, b = 0;
    int     d;
    int     by, bm, bd;
    int     i, j;

    printf( "<TABLE BORDER=\"1\" SUMMARY=\"�N�������w�肵�Ă�������\">\n" );
    printf( "<TR><TD ALIGN=\"CENTER\" COLSPAN=\"7\">\n " );
    if ( yy > 1 ) {
        printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1�N�O</A> ",
                yy - 1, mm, dd );
    }
    else {
        printf( "1�N�O " );
    }
    if ( (yy > 1) || (mm > 1) ) {
        printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1���O</A> ",
                mm ==  1 ? yy - 1 : yy, mm ==  1 ? 12 : mm - 1, dd );
    }
    else {
        printf( "1���O " );
    }
    printf( "* <STRONG>%4d�N%2d��</STRONG> * ", yy, mm );
    printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1����</A> ",
            mm == 12 ? yy + 1 : yy, mm == 12 ?  1 : mm + 1, dd );
    printf( "<A HREF=\"tamo.cgi?y=%d&amp;m=%d&amp;d=%d\">1�N��</A> \n",
            yy + 1, mm, dd );
    printf( "</TD></TR>\n" );

    printf( "<TR>\n" );
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">��</TD>\n");
    printf( "<TD ALIGN=\"CENTER\" BGCOLOR=\"#FFCCFF\" WIDTH=\"30\">�y</TD>\n");
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
    printf("<INPUT type=\"text\" name=\"y\" size=4 value=%d>�N ", yy );
    printf("<INPUT type=\"text\" name=\"m\" size=2 value=%d>�� ", mm );
    printf("<INPUT type=\"text\" name=\"d\" size=2 value=%d>�� ", dd  );
    printf("<INPUT type=\"text\" name=\"H\" size=2 value=%d>�� ", HH );
    printf("<INPUT type=\"text\" name=\"M\" size=2 value=%d>�� ", MM );
    printf("<INPUT type=\"text\" name=\"S\" size=2 value=%d>�b<BR>\n", SS);
    printf("<INPUT type=\"submit\" accesskey=\"d\" value=\"�w��N���������b�̗��\��\"> ");
    printf("<INPUT type=\"reset\"  accesskey=\"r\" value=\"���Z�b�g\"><BR>\n");
    printf("<INPUT type=\"button\" accesskey=\"n\" value=\"�����_�̗��\��\" "
           "onClick=\"window.navigate(&quot;tamo.cgi&quot;)\" "
           "onKeyPress=\"window.navigate(&quot;tamo.cgi&quot;)\">\n" );
    printf("</FORM></DIV>\n" );
}

