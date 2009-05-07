/*
 *  print.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      7 March 2003
 *  Copyright (c) 2003, 2004, 2005, 2006, 2007  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: print.c $
 * Revision 1.35  2007/02/14  08:48:53  tsujimura543
 * �W���o�͂����_�C���N�g���Ă���ꍇ�A����html���[�h�̂Ƃ��A
 * 1�s�ڂɃ^�C�g�������̕�����(���N���������̗�)��}������悤
 * �ɂ���
 *
 * Revision 1.34  2007/02/06  10:56:12  tsujimura543
 * copyright �\�L���A�b�v�f�[�g
 *
 * Revision 1.33  2006/05/29  05:12:32  tsujimura543
 * �C���^�[�l�b�g���ԑΉ�
 *
 * Revision 1.32  2005/05/13  13:11:56  tsujimura543
 * RSS �A�C�R����\������悤�ɂ���
 *
 * Revision 1.31  2004/10/25  00:36:40  tsujimura543
 * hi-ho �� URL ��ύX
 *
 * Revision 1.30  2004/03/22  12:53:48  tsujimura543
 * PHP�������́u�����͉��̓��v��ǉ�
 *
 * Revision 1.29  2003/11/11  09:11:42  tsujimura543
 * �����E�X��A�C�X������A���_����̕\�����œK��
 *
 * Revision 1.28  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.27  2003/10/30  08:13:54  tsujimura543
 * Another HTML-lint �ŕ]����100�_�ɂȂ�悤�ɏC��
 *
 * Revision 1.26  2003/10/24  01:35:04  tsujimura543
 * Solaris9 ��ŃR���p�C���A����m�F
 *
 * Revision 1.25  2003/06/05  11:08:21  tsujimura543
 * �C���h���A��A�l�p�[�����A��̑Ή��J�n�N�����̔�����������C��
 *
 * Revision 1.24  2003/06/05  10:58:46  tsujimura543
 * �l�p�[�����A��A�C���h���z��̕\�����Ԃ��ߋ������Ɋg��(1970�N�܂ők�s)
 *
 * Revision 1.23  2003/05/30  10:46:40  tsujimura543
 * �l�p�[���̍s���A�j�Փ��̕\�����ꕔ�Ή�
 *
 * Revision 1.22  2003/05/30  09:55:37  tsujimura543
 * �l�p�[�����A��A�C���h���z��̕\�����Ԃ��g�� (tithi.txt �̊g���ɔ���)
 *
 * Revision 1.21  2003/05/26  07:47:50  tsujimura543
 * �C���h������(���Ɨ�)�Ή��A�l�p�[�����A��C��
 *
 * Revision 1.20  2003/05/23  07:07:31  tsujimura543
 * �֘A�����N��2���ǉ�
 *
 * Revision 1.19  2003/05/20  05:55:50  tsujimura543
 * �t�����X�v����𓱓��シ�ׂĂ̊��Ԃɂ킽���ĕ\���\�Ƃ���
 *
 * Revision 1.18  2003/04/25  11:22:40  tsujimura543
 * HTML���[�h���̕\�����኱�ύX
 *
 * Revision 1.17  2003/04/25  02:08:39  tsujimura543
 * �֘A�����N��1���ǉ�
 *
 * Revision 1.16  2003/04/24  09:46:25  tsujimura543
 * �֘A�����N�̕\�����኱�ύX
 *
 * Revision 1.15  2003/04/24  04:29:28  tsujimura543
 * �֘A�����N��\������悤�ɂ���(html���[�h��)
 *
 * Revision 1.14  2003/04/23  11:09:07  tsujimura543
 * ���~�A���Đ��A�y�p�̕\���𑾗z��̕��ֈڂ�
 * (����̏C���ŕK�v�Ȃ��Ȃ����֐����폜)
 *
 * Revision 1.13  2003/04/16  05:56:37  tsujimura543
 * �f�[�^�t�@�C�������̋K���ɂ��������ĒT�����I�[�v������悤�ɂ���
 *
 * Revision 1.12  2003/04/11  10:58:56  tsujimura543
 * (1) �C���h���A��\���̌����ɉ��Ԗڂ̌����𕹋L����悤�ɂ���
 * (2) �l�p�[�����A��\����ǉ� (�b��)
 *
 * Revision 1.11  2003/04/02  10:28:42  tsujimura543
 * �C�X������1�N1��1���ȑO�͕\�����Ȃ��悤�ɏC��
 *
 * Revision 1.10  2003/04/02  10:20:09  tsujimura543
 * �G�`�I�s�A����T�|�[�g
 *
 * Revision 1.9  2003/03/31  11:24:31  tsujimura543
 * �a��(���z���A��)�֘A�����ISO�֘A�C��
 * �t�����X�v����̕\���\���Ԃ��g��
 *
 * Revision 1.8  2003/03/24  08:58:03  tsujimura543
 * (1) �a��(���A���z��)�̕\���\���Ԃ��g��
 * (2) �友�Ɠy�p�̉N�̓����d�Ȃ����ꍇ�A�Е������\������Ȃ��s����C��
 *
 * Revision 1.7  2003/03/20  09:18:02  tsujimura543
 * �e���̕\����ǉ�
 *
 * Revision 1.6  2003/03/19  05:12:11  tsujimura543
 * tprintf() ���C��
 *
 * Revision 1.5  2003/03/19  04:46:08  tsujimura543
 * ���x�̏o�͕����𑼂̗�Ɠ����ɂ���
 *
 * Revision 1.4  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.3  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.2  2003/03/14  09:56:25  tsujimura543
 * ���������Ή����� #3
 *
 * Revision 1.1  2003/03/14  09:37:59  tsujimura543
 * Initial revision
 *
 */

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/print.c 1.35 2007/02/14 08:48:53 tsujimura543 Exp tsujimura543 $";
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
 *  �w�b�_���o��
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
 "koyomi,today,moon phase,tithi,calendar,�����͉��̓�,��,�V��,����,����\">\n",
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
            printf( "%d�N%2d��%2d���̗�", yy, mm, dd );
            fputs(  "</TITLE>\n</HEAD>\n\n<BODY>\n", stdout );
            printf( "<H1>%d�N%2d��%2d���̗�</H1>\n", yy, mm, dd );
        }
    }
    else {
        if ( !isatty( fileno( stdout ) ) )
            printf( "%04d�N%2d��%2d���̗�\n", yy, mm, dd );
    }
}

/*
 *  �t�b�^���o��
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
 *  �啶�o��
 */

void
printMainStatement( int yy, int mm, int dd, int HH, int MM, int SS,
                    int printTime, int htmlMode )
{
    if ( htmlMode == ON )
        fputs(  "<P>\n", stdout );
    if ( printTime == ON )
        printf( "������ %d�N%2d��%2d�� �ŁA������ %2d��%2d��%2d�b �ł�\n",
                yy, mm, dd, HH, MM, SS );
    else
        printf( "������ %d�N%2d��%2d�� �ł�\n",
                yy, mm, dd );
    if ( htmlMode == ON ) {
        /* RSS �\�� */
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
 *  �S�́E�e�[�u���w�b�_�o��
 */

void
printTableHeader( int htmlMode )
{
    if ( htmlMode == ON ) {
        fputs( "<DIV ALIGN=\"CENTER\">\n", stdout );
        fputs(
           "<TABLE BORDER=\"0\" ALIGN=\"CENTER\" SUMMARY=\"��\">\n<TR><TD>\n",
               stdout );
    }
}


/*
 *  �S�́E�e�[�u���t�b�^�o��
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
 *  �S�́E�e�[�u���Ԏd�؂蕔�o��
 */

void
printTableSeparator( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "</TD><TD WIDTH=\"20\"><BR></TD><TD>\n", stdout );
}



/*
 *  �e���񕔏o��
 */

void
tamo_information( int yy, int mm, int dd, long g,
                  int htmlMode, int printTrain )
{
    /* �e���񕔁E�w�b�_�o�� */
    if ( htmlMode == ON )
        fputs( "<PRE>", stdout );

    /* JR�c�Ə��o�� */
    if ( printTrain == ON )
        trainService( g, dd, mm, yy );

    /* �a���΁A�a���ԁE�Ԍ��t�o�� */
    flower( g, dd, mm, yy );

    /* �e���񕔁E�t�b�^�o�� */
    if ( htmlMode == ON )
        fputs( "</PRE>\n", stdout );
}


/*
 *  �s�����o��
 */

void
printLineHeader( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "<TR><TD>", stdout );
}


/*
 *  �s�����o��
 */

void
printLineFooter( int htmlMode )
{

    if ( htmlMode == ON )
        fputs( "</TD></TR>", stdout );
    putchar( '\n' );
}


/*
 *  ����ݕ��E�e�[�u���w�b�_�o��
 */

void
printKoyomiTableHeader( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "<TABLE BORDER=\"0\" ALIGN=\"CENTER\" SUMMARY=\"��{���\">\n",
               stdout );
}


/*
 *  ����ݕ��E�e�[�u���t�b�^�o��
 */

void
printKoyomiTableFooter( int htmlMode )
{
    if ( htmlMode == ON )
        fputs( "</TABLE>\n", stdout );
}


/*
 *  ����ݕ��E�����E�X���o��
 */

void
printJulianDate( long g, int HH, int MM, int SS, int htmlMode, int printTime )
{
    int h;

    printLineHeader( htmlMode );
    printf( "�����E�X��%s%ld��",
            htmlMode == ON ? "</TD><TD COLSPAN=2>"
                           : "            ",
            g + 1721425L );
    if ( printTime == ON ) {
        h = HH - 9; /* ���[�J�����Ԃ� JST �ł��邱�Ƃ����� */
        if ( h < 0 ) {
            h += 24;
        }
        printf( "  %02d��%02d��%02d�b UTC", h, MM, SS );
    }
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��ETSUPO�`���o��
 */

void
printTsupoDate( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "TSUPO�`��%s%s",
            htmlMode == ON ? "</TD><TD>"
                           : "       ",
            tsupodate( dd, mm, yy ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkTsupo( g, dd, mm, yy );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��EISO�`���o��
 */

void
printIsoDate( long g, int yy, int mm, int dd, int htmlMode )
{
    int     a1 = 0, a2 = 0, a3 = yy;

    printLineHeader( htmlMode );
    isoFromAbsolute( g, &a1, &a2, &a3 );
    printf( "ISO�`��%s%4d�N��%2d�T��%2d��",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "           ",
            a3, a1, a2 );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�O���S���I��o��
 */

void
printGregorianCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    int reset = 1;

    printLineHeader( htmlMode );
    printf( "�O���S���I��%s%4d�N%2d��(%s)%2d��",
            htmlMode == ON ? "</TD><TD>"
                           : "      ",
            yy, mm, englishMonthName(mm), dd );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    tprintf( htmlMode, &reset, "  %s�j��", weekday(g) );
    checkAmerican( g, dd, mm, yy, htmlMode, &reset );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�����E�X��o��
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

    printf( "�����E�X��%s%4d�N%2d��(%s)%2d��",
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
 *  ����ݕ��E�C�X������o��
 */

void
printIslamicCalendar( long g, int yy, int htmlMode )
{
    int     a1, a2, a3;
    char    buf[BUFSIZ];
    int     checkedOut;

    if ( g < absoluteFromGregorian( 19, 7, 622 ) ) {
        /* �C�X������ 1�N1��1���ȑO�̏ꍇ */
        return;
    }

    islamicFromAbsolute( g, &a1, &a2, &a3 );
    checkedOut = checkIslamic( buf, g, a1, a2, a3, yy, htmlMode );

    printLineHeader( htmlMode );

    printf( "�C�X������%s%4d�N%2d��(%s)%2d��",
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
 *  ����ݕ��E���_����o��
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

    printf( "���_����%s%4d�N%2d��(%s)%2d��",
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
 *  ����ݕ��E�}��������o��
 */

void
printMayaCalendar( long g, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�}��������%s%s\t%s %s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "        ",
            mayaFromAbsolute( g ),
            tsolkinFromAbsolute( g ),
            haabuFromAbsolute( g )    );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�}���Z����o��
 */

void
printKatunCalendar( long g, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�}���Z����%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "     ",
            katunFromAbsolute( g ) );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�t�����X�v����o��
 */

void
printFrenchCalendar( long g, int yy, int mm, int dd, int HH, int MM, int SS,
                     int htmlMode, int printTime )
{
    printLineHeader( htmlMode );
    printf( "�t�����X�v����%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "  ",
            fdate( g, dd, mm, yy, HH, MM, SS, printTime, htmlMode ) );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�a��(���z��)�o��
 */

void
printJapaneseCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�a��(���z��)%s%s",
            htmlMode == ON ? "</TD><TD>" : "    ",
            wareki( dd, mm, yy, 0 ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkJapanese( g, dd, mm, yy, htmlMode );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�a��(���A���z��)�o��
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
        printf( "%s���A���z��%s%s",
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
        printf( "%s���A���z��%s%s",
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
 *  ����ݕ��E���x�o��
 */

void
printEtoCalendar( long g, int yy, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "     ���x%s%s",
            htmlMode == ON ? "</TD><TD>"
                           : "       ",
            eto( g, yy, htmlMode ) );
    if ( htmlMode == ON )
        fputs( "</TD><TD>", stdout );
    checkEto( g, htmlMode );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�c�I�o��
 */

void
printKigenCalendar( int yy, int mm, int dd, int htmlMode )
{
    if ( htmlMode == OFF ) {
        printf( "     �c�I         %4d�N%2d��%2d��\n", yy + 660, mm, dd );
    }
}


/*
 *  ����ݕ��E�����I���o��
 */

void
printBuddhaCalendar( int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�����I��%s%4d�N%2d��%2d��",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "          ",
            yy + 543, mm, dd );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�l�p�[�����z��o��
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
    printf( "�l�p�[����%s%s",
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
 *  ����ݕ��E�l�p�[�����A��o��
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
            printf( "�l�p�[�����A��%s%s",
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
 *  ����ݕ��E�C���h���A��o��
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
            printf( "�C���h���A��%s%s",
                    htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                                   : "      ",
                    p );
            printLineFooter( htmlMode );
        }
    }

    if ( ((yy == 1957) && ((mm >= 4) || ((mm == 3) && (dd >=21)))) ||
         ( yy >= 1958) ) {
            printLineHeader( htmlMode );
            printf( "�C���h������%s%s",
                    htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                                   : "      ",
                    indianNationalDate( dd, mm, yy ) );
            printLineFooter( htmlMode );
    }
}


/*
 *  ����ݕ��E�G�`�I�s�A��o��
 */

void
printCopticCalendar( long g, int yy, int mm, int dd, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�G�`�I�s�A��%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "      ",
            copdate( g, dd, mm, yy ) );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��ESwatch�C���^�[�l�b�g���ԏo��
 */

void
printBeat( int HH, int MM, int SS, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "�C���^�[�l�b�g����%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "      ",
            beatFromAbsolute( HH, MM, SS ) );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��E�����o��
 */

void
printZodiac( long g, int yy, int htmlMode )
{
    printLineHeader( htmlMode );
    printf( "����%s%s",
            htmlMode == ON ? "</TD><TD COLSPAN=\"2\">"
                           : "            ",
            zodiac( g, yy ) );
    printLineFooter( htmlMode );
}


/*
 *  ����ݕ��o��
 */

void
tamo_koyomi( int yy, int mm, int dd, int HH, int MM, int SS, long g,
             int htmlMode, int printTime, int printTsupo )
{
    /* ����ݕ��E�e�[�u���w�b�_�o�� */
    printKoyomiTableHeader( htmlMode );

    /* �����E�X���A����(UTC)�o�� */
    printJulianDate( g, HH, MM, SS, htmlMode, printTime );

    /* TSUPO�`���o�� */
    if ( printTsupo == ON ) {
        printTsupoDate( g, yy, mm, dd, htmlMode );
    }

    /* ISO�`���o�� */
    printIsoDate( g, yy, mm, dd, htmlMode );

    /* �O���S���I��o�� */
    printGregorianCalendar( g, yy, mm, dd, htmlMode );

    /* �����E�X��o�� */
    printJulianCalendar( g, yy, mm, htmlMode );

    /* �C�X������o�� */
    printIslamicCalendar( g, yy, htmlMode );

    /* ���_����o�� */
    printHebrewCalendar( g, yy, mm, htmlMode );

    /* �}����o�� */
    /*   --- �}���֘A�w��ł̒���Ɋ�Â��}�������� */
    printMayaCalendar( g, htmlMode );

    /*   --- �}���֘A�w��ł̒���Ɋ�Â��}���Z���� */
    printKatunCalendar( g, htmlMode );

    /* �t�����X�v����o�� */
    printFrenchCalendar( g, yy, mm, dd, HH, MM, SS, htmlMode, printTime );

    /* �a��(���z��)�o�� */
    printJapaneseCalendar( g, yy, mm, dd, htmlMode );

    /* �a��(���A���z��)�o�� */
    printOldJapaneseCalendar( g, yy, mm, dd, htmlMode );

    /* ���x�o�� */
    printEtoCalendar( g, yy, htmlMode );

    /* �c�I�o�� */
    printKigenCalendar( yy, mm, dd, htmlMode );

    /* �����I���o�� */
    printBuddhaCalendar( yy, mm, dd, htmlMode );

    /* �l�p�[����o�� */
    printNepaliCalendar( g, yy, mm, dd, HH, MM, SS, htmlMode, printTime );

    /* �l�p�[�����A��o�� */
    printNepaliLunarCalendar( yy, mm, dd, HH, MM, SS, htmlMode );

    /* �C���h���A��o�� */
    printIndianLunarCalendar( yy, mm, dd, HH, MM, SS, htmlMode );

    /* �G�`�I�s�A��o�� */
    printCopticCalendar( g, yy, mm, dd, htmlMode );

    /* Swatch�C���^�[�l�b�g���ԏo�� */
    printBeat( HH, MM, SS, htmlMode );

    /* �����o�� */
    printZodiac( g, yy, htmlMode );

    /* ����ݕ��E�e�[�u���w�b�_�o�� */
    printKoyomiTableFooter( htmlMode );
}


/*
 *  �֘A�y�[�W(�����N�W)�\��
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
        printf( "<HR>\n<P>\n<STRONG>�֘A�y�[�W</STRONG>\n</P>\n<UL>\n" );
        printf( "<LI><A HREF=\"http://www.google.co.jp/search?sourceid=nav"
                "client&amp;hl=ja&amp;ie=UTF-8&amp;oe=UTF-8&amp;q=%d%%E6%%"
                "9C%%88%d%%E6%%97%%A5\">Google �� %2d��%2d�� ������</A>\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://ja.wikipedia.org/wiki/%d%%E6%%9C%%88%d"
                "%%E6%%97%%A5\">%2d��%2d�� �����͉��̓�</A> "
                "(�E�B�L�y�f�B�A)\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://www.nnh.to/%02d/%02d.html\">%2d��%2d��"
                " �����͉��̓��`�������L�O���`</A> "
                "(���{�L�O���{��/�x�R���Â݂���)\n",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://koyomi.vis.ne.jp/cgi/today/today.php?"
                "syy=%d&amp;smm=%d&amp;sdd=%d\">�����͉��̓�</A> "
                "(���키�������)\n",
                yy, mm, dd );
        printf(
#if 0
                "<LI><A HREF=\"http://town.hi-ho.ne.jp/cgi-bin/town/cale/"
                "top_link.pl?month=%s&amp;day=%d&amp;member=2&amp;msnflag="
                "0\">���߂���J�����_�[ (%2d��%2d��)</A> (Panasonic Hi-Ho)",
                monthName[mm - 1], dd, mm, dd
#else
 /* http://kurashi.hi-ho.ne.jp/cale/index.html?year=2004&month=10&day=23 */
                "<LI><A HREF=\"http://kurashi.hi-ho.ne.jp/cale/index.html?"
                "year=%d&amp;month=%d&amp;day=%d\">���߂���J�����_�[ "
                "(%4d�N%2d��%2d��)</A> (Panasonic Hi-Ho)",
                yy, mm, dd, yy, mm, dd
#endif
              );
        printf( "<LI><A HREF=\"http://www.php.co.jp/today/"
                "%02d-%02d.html\">�����͉��̓� %2d��%2d��</A> (PHP������)",
                mm, dd, mm, dd );
        printf( "<LI><A HREF=\"http://www.moonsystem.to/calendar/cgi/"
                "calendar2.cgi?year=%d&amp;month=%d\">����J�����_�[ "
                "(%d�N%2d��)</A> (The Moon Age Calendar)\n",
                yy, mm, yy, mm );
        printf( "</UL>\n" );
    }
}


/*
 *  ��A�j�Փ��A�L�O�����̏o��
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
 *  �f�[�^�t�@�C���I�[�v��
 *
 *      �ȉ��̏����Ńt�@�C����T������
 *        (1) ����N������ tamo.exe �̑��݂���f�B���N�g��
 *        (2) ���ϐ� KOYOMI �̎����f�B���N�g��
 *        (3) ����N������ tamo.exe �̑��݂���f�B���N�g���̒����� koyomi �f�B
 *            ���N�g��
 *        (4) �J�����g�f�B���N�g��
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


