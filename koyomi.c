/*
 *      koyomi.c
 *                      by H.Tsujimura  tsupo@na.rim.or.jp
 *                                              17 February 1991
 *      Copyright (c) 1991 Hiroshi Tsujimura
 *      All Rights Reserved.
 *
 * History :
 * $Log: koyomi.c $
 * Revision 1.80  2003/10/24  01:35:04  tsujimura543
 * Solaris9 ��ŃR���p�C���A����m�F
 *
 * Revision 1.79  2003/03/19  04:46:08  tsujimura543
 * ���x�̏o�͕����𑼂̗�Ɠ����ɂ���
 *
 * Revision 1.78  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.77  2003/03/14  09:40:04  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.1  2003/03/14  09:37:59  tsujimura543
 * Initial revision
 *
 * Revision 1.76  2003/03/07  03:16:24  tsujimura543
 * ���[�}��(�����E�X��)�� ides �\����ǉ�
 *
 * Revision 1.75  2003/03/04  06:04:12  tsujimura543
 * �C���h���A��̎Z�o�\���Ԃ̏���Ɖ������g��
 *
 * Revision 1.74  2003/03/03  07:48:25  tsujimura543
 * �C���h���A��Ή�
 *
 * Revision 1.73  2003/02/28  07:30:49  tsujimura543
 * �����E�X��̌����\��(���e����)��ǉ�
 *
 * Revision 1.72  2003/02/27  08:41:01  tsujimura543
 * �剻�ȍ~�̌����ɑΉ�
 *
 * Revision 1.71  2003/02/25  05:52:46  tsujimura543
 * CGI�Ƀp�����[�^��n����悤�ɂ���
 *
 * Revision 1.70  2003/02/24  10:48:05  tsujimura543
 * �l�p�[����̎����b�\�L�ɑΉ�
 *
 * Revision 1.69  2003/02/24  09:25:42  tsujimura543
 * ���s�`���̊g���q�� .cgi �̏ꍇ�AContent-type: �s���o�͂���悤�ɂ���
 *
 * Revision 1.68  2003/02/21  05:18:38  tsujimura543
 * HTML���[�h�ł��A�O���S���I��A�C�X������A���_����̌����\��������
 * �悤�ɂ���
 *
 * Revision 1.67  2003/02/21  05:06:24  tsujimura543
 * (1) 13�����ASpinden���̃}����̕\�����f�t�H���g�ł� OFF �ɂ���
 * (2) �t�����X�v����̎����̕\����ON/OFF��-d�I�v�V�����̎w�肠��/�Ȃ���
 *     �A��������悤�ɂ���
 * (3) usage �̕\���𐮗�����
 *
 * Revision 1.66  2003/02/19  09:00:33  tsujimura543
 * usage �ŕ\���������e���C��
 *
 * Revision 1.65  2003/02/19  07:29:36  tsujimura543
 * �l�p�[����Ή�
 *
 * Revision 1.64  2003/02/07  04:46:59  tsujimura543
 * �C�X�������јa��̌������\������悤�ɂ���
 *
 * Revision 1.63  2003/02/06  09:41:58  tsujimura543
 * ���_�����̏j�Փ���ǉ�
 *
 * Revision 1.62  2001/06/13  13:24:23  tsujimura543
 * �u����v�A�u�����v�\���Ή�
 *
 * Revision 1.61  2001/02/21  14:16:36  tsujimura543
 * HTML���[�h�Ή��ς݂� revision �Ɠ���
 *
 * Revision 1.60  2001/02/20  12:28:19  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.52  2000/06/06  17:57:36  tsujimura543
 * 13�����̕\����ǉ�
 * 
 * Revision 1.51  1999/07/08  18:08:27  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1997/01/21  19:40:28  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.14  95/12/16 06:13:18  tsujimura
 * TSUPO�`���̕\���J�n�ʒu���C��
 * 
 * Revision 1.13  95/12/03 11:42:38  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.12  95/12/02 23:29:52  tsujimura
 * JR�̗����v�Z������\���@�\(-J�I�v�V����)��ǉ�
 * 
 * Revision 1.11  95/12/02 15:50:28  tsujimura
 * �t�����X�v����̕\����ǉ�
 * 
 * Revision 1.10  92/03/29 02:57:58  tsujimura
 * test release
 * 
 * Revision 1.9  91/04/29 23:03:08  tsujimura
 * enlarged stack size (for TURBO C)
 * 
 * Revision 1.8  91/04/26 23:11:14  tsujimura
 * supported for information of new comics
 * 
 * Revision 1.7  91/04/08 05:53:26  tsujimura
 * Bug fix: shift argument correctly (multiple option with -)
 * 
 * Revision 1.6  91/04/08 05:41:00  tsujimura
 * Bug fix: compute yymmdd from command-line-arguments correctly
 * 
 * Revision 1.5  91/04/08 02:04:24  tsujimura
 * changed version()
 * 
 * Revision 1.4  91/04/08 01:47:48  tsujimura
 * added analyze options
 * 
 * Revision 1.3  91/03/24 03:22:58  tsujimura
 * changed functions for calculation of old-japanese-calendar
 * 
 * Revision 1.2  91/03/02 05:58:56  tsujimura
 * added many features
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dates.h"

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/koyomi.c 1.80 2003/10/24 01:35:04 tsujimura543 Exp $";
#endif

static int simplemode        = OFF;
static int printIdolEvent    = OFF;
static int printBirthday     = ON;
static int printAircheckInfo = OFF;
static int printComicsInfo   = OFF;
static int printHistory      = ON;
static int printEvent        = OFF;
static int printToday        = OFF;
static int printTsupo        = OFF;
static int printTime         = ON;
static int printTrain        = OFF;
static int printZodiac13     = OFF;
static int printSpinden      = OFF;
static int latexMode         = OFF;
int        htmlMode          = OFF;
static int withHeader        = ON;
int        yesterday         = 0;
int        tomorrow          = 0;
static int cgi               = OFF;

#ifdef  __TURBOC__
extern unsigned _stklen = 8192U;
#endif

#ifdef  __STDC__
char    *decodeURL( char *pp );
#else
char    *decodeURL();
#endif


static void
version()
{
    printf( "koyomi $Revision: 1.80 $ by H.Tsujimura\n" );
#ifdef  __TURBOC__
#if     __TURBOC__ == 0x0200
    printf( "Compiled with Borland's Turbo C Ver2.0\n" );
#else
    printf( "Compiled with Borland's Turbo C++ Ver1.01\n" );
#endif
#endif
    printf( "Bug reports are welcome. Send E-mail to:\n" );
    printf( "  tsupo@na.rim.or.jp\n" );
    printf( "\n" );
}

static void
usage()
{
  printf("Usage:\n");
  printf("  koyomi [-abcdehimstvzAEHJLM] [{YYYY|yy}[mm[dd [HH[MM[SS]]]]]]]\n");
  printf("    or\n" );
  printf("  koyomi [-abcdehimstvzAEHJLM] {yesterday|tomorrow}\n");
  printf("    -A: print out all information, if possibble.\n" );
  printf("    -L: print out by LaTeX formatted text.\n" );
  printf("    -M: print out by HTMP formatted text.\n" );
  printf("    YYYY: year   (0001-9999)\n");
  printf("      yy: year   (00-99)\n");
  printf("      mm: month  (01-12)\n");
  printf("      dd: day    (01-31)\n");
  printf("      HH: hour   (00-23)\n");
  printf("      MM: minute (00-59)\n");
  printf("      SS: second (00-59)\n");
  printf("\n");
}

static void
setParameter( p, yy, mm, dd, HH, MM, SS )
char    *p;
int     *yy, *mm, *dd, *HH, *MM, *SS;
{
    char    *q, *r;
    char    buf[BUFSIZ];
    int     flag = OFF;

    while ( *p ) {
        q = NULL;

        if ( !strncmp( p, "y=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *yy = atoi( r );
        }

        if ( !strncmp( p, "m=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *mm = atoi( r );
        }

        if ( !strncmp( p, "d=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') )
                *dd = atoi( r );
        }

        if ( !strncmp( p, "H=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *HH = atoi( r );
                flag = ON;
            }
        }

        if ( !strncmp( p, "M=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *MM = atoi( r );
                flag = ON;
            }
        }

        if ( !strncmp( p, "S=", 2 ) ) {
            p += 2;
            q = &(buf[0]);
            while ( *p && (*p != '&') )
                *q++ = *p++;
            *q = NUL;
            if ( *p == '&' )
                p++;
            r = decodeURL( buf );
            if ( (*r >= '0') && (*r <= '9') ) {
                *SS = atoi( r );
                flag = ON;
            }
        }

        if ( !q )
            p++;
    }

    printTime = flag;
}

static void
showMethod( yy, mm, dd, HH, MM, SS )
int yy, mm, dd, HH, MM, SS;
{
    int     a1, a2, a3;
    long    g = absoluteFromGregorian( dd, mm, yy );

    printf("<P ALIGN=\"CENTER\">\n" );
    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���N</A>\n",
           yy - 1, mm, dd, HH, MM, SS );

    a3 = yy;
    a2 = mm - 1;
    a1 = dd;
    if ( a2 == 0 ) {
        a3 = yy - 1;
        a2 = 12;
    }
    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">�挎</A>\n",
           a3, a2, a1, HH, MM, SS );

    gregorianFromAbsolute( g - 1, &a1, &a2, &a3 );
    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���</A>\n",
           a3, a2, a1, HH, MM, SS );

    printf("<A HREF=\"koyomi.cgi?y=0&m=0&d=0&H=0\">����</A>\n");

    gregorianFromAbsolute( g + 1, &a1, &a2, &a3 );
    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">����</A>\n",
           a3, a2, a1, HH, MM, SS );

    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">����</A>\n",
           yy, mm + 1, dd, HH, MM, SS );

    printf(
"<A HREF=\"koyomi.cgi?y=%04d&m=%02d&d=%02d&H=%02d&M=%02d&S=%02d\">���N</A>\n",
           yy + 1, mm, dd, HH, MM, SS );
}


static char     *
split2( s )
char    *s;
{
    static char buf[BUFSIZ];
    int         i = 0;

    while ( *s == ' ' )
        s++;
    while ( *s ) {
        if ( *s == ' ' ) {
            while ( *s == ' ' )
                s++;
            buf[i] = '&';
        }
        else
            buf[i] = *s++;
        i++;
    }
    buf[i] = '\0';

    return ( buf );
}

static char     *
splitEto( s )
char    *s;
{
    static char buf[BUFSIZ];
    int         i = 0;

    strcpy( buf, "\\multicolumn{2}{l|}{" );
    i += strlen(buf);
    while ( *s ) {
        if ( !strncmp( s, "��", strlen("��") ) ) {
            buf[i++] = *s++;
            buf[i++] = *s++;
            buf[i++] = '}';
            buf[i++] = '&';
        }
        else
            buf[i++] = *s++;
    }
    buf[i] = '\0';

    return ( buf );
}

static void
koyomi( yy, mm, dd, HH, MM, SS )
int     yy, mm, dd, HH, MM, SS;
{
    int     a1, a2, a3, uruu;
    long    g;
    char    *p;

    g = absoluteFromGregorian( dd, mm, yy ); /* ����1�N1��1������̒ʓ� */
    gregorianFromAbsolute( g, &a1, &a2, &a3 );
    yy = a3; mm = a2; dd = a1;

    if ( latexMode == ON ) {
        if ( withHeader == ON ) {
            printf( "\\documentstyle[a4j]{jarticle}\n" );
            printf( "\\pagestyle{empty}\n" );
            printf( "\\begin{document}\n" );
        }
        printf( "\\begin{center}\n" );
        printf( "{\\large �����̗�}\\\\\n" );
        printf( "\\end{center}\n" );
        printf( "\\medskip\n\\medskip\n" );
        printf( "\\begin{center}\n" );

        if ( printTime == ON )
            printf(
                 "������ %d�N%2d��%2d�� �ŁA������ %2d��%2d��%2d�b �ł�\\\\\n",
                    yy, mm, dd, HH, MM, SS );
        else
            printf( "������ %d�N%2d��%2d�� �ł�\\\\\n", yy, mm, dd );
        printf( "\\end{center}\n" );
        printf( "\\medskip\n\\par\n" );
        printf( "\\begin{table}[htbp]\n" );
        printf( "\\begin{center}\n" );
        printf( "\\begin{tabular}{|l||l|ll|}\n" );
        printf( "\\hline\n" );
    }
    else if ( htmlMode == ON ) {
        if ( withHeader == ON ) {
            printf( "<HTML>\n<HEAD>\n" );
            printf( "<TITLE>%d�N%02d��%02d���̗�</TITLE>\n", yy, mm, dd );
            printf( "</HEAD>\n\n<BODY>\n<H1>�����̗�</H1>\n<P>\n" );
        }

        if ( printTime == ON )
            printf("%s�� %d�N%2d��%2d�� �ŁA������ %2d��%2d��%2d�b �ł�<BR>\n",
                   tomorrow ? "����" : yesterday ? "���" : "����",
                   yy, mm, dd, HH, MM, SS );
        else
            printf( "%s�� %d�N%2d��%2d�� �ł�<BR>\n",
                    tomorrow ? "����" : yesterday ? "���" : "����",
                    yy, mm, dd );

        printf( "<P>\n<CENTER><TABLE BORDER=0 ALIGN=\"CENTER\">\n" );
    }
    else if ( printTime == ON )
        printf( "%s�� %d�N%2d��%2d�� �ŁA������ %2d��%2d��%2d�b �ł�\n",
                tomorrow ? "����" : yesterday ? "���" : "����",
                yy, mm, dd, HH, MM, SS );
    else
        printf( "%s�� %d�N%2d��%2d�� �ł�\n",
                tomorrow ? "����" : yesterday ? "���" : "����",
                yy, mm, dd );

    if ( latexMode == ON )
        printf( "�����E�X�� & %ld�� & ", g + 1721425L );
    else if ( htmlMode == ON )
        printf( "<TR><TD>�����E�X��</TD><TD>%ld��</TD><TD>",
                g + 1721425L );
    else
        printf( "�����E�X��             %ld��", g + 1721425L );
    {
#ifdef  PRINT_UTC
        int     h = HH;

        h -= 9;
        if ( h < 0 ) {
            h += 24;
        }
        printf( "  %02d��%02d��%02d�b UTC", h, MM, SS );
#endif
#if     0
        if ( ((yy > 1970) && (yy < 2038))                   ||
             ((yy == 1970) &&
              ((mm > 1) ||
               ((mm == 1) && ((dd >  1) ||
                              (dd == 1) && (HH > 9)))))     ||
             ((yy == 2038) &&
              ((mm == 1) &&
               ((dd <  19) ||
                (dd == 19) &&
                ((HH <  3) ||
                 (HH == 3) && ((MM <  14) ||
                               (MM == 14) && (SS <= 7))))))    ) {
            if ( latexMode == ON ) {
                printf( "���� %2.1f & \\\\\n",
                        moonPhase2( yy, mm, dd, HH, MM, SS ) );
                printf( "\\hline\n" );
            }
            else {
                printf( "  ���� %2.1f\n",
                        moonPhase2( yy, mm, dd, HH, MM, SS ) );
            }
        }
        else {
            if ( latexMode == ON )
                printf( " & \\\\\n\\hline\n" );
            else
                putchar( '\n' );
        }
#else
        if ( latexMode == ON ) {
            printf( "���� %2.1f & \\\\\n",
                    moonPhase2( yy, mm, dd, HH, MM, SS ) );
            printf( "\\hline\n" );
        }
        else if ( htmlMode == ON ) {
            printf( "���� %2.1f</TD></TR>\n",
                    moonPhase2( yy, mm, dd, HH, MM, SS ) );
        }
        else {
            printf( "  ���� %2.1f\n",
                    moonPhase2( yy, mm, dd, HH, MM, SS ) );
        }
#endif
    }

    if ( printTsupo == ON ) {
        if ( latexMode == ON ) {
            printf( "\\hline\n" );
            printf( "TSUPO�`�� & %s & \\multicolumn{2}{l|}{",
                    tsupodate( dd, mm, yy ) );
        }
        else if ( htmlMode == ON ) {
            printf( "<TR><TD>TSUPO�`��</TD><TD>%s</TD><TD>",
                    tsupodate( dd, mm, yy ) );
        }
        else
            printf( "TSUPO�`��       %s", tsupodate( dd, mm, yy ) );
        checkTsupo( g, dd, mm, yy );
        if ( latexMode == ON )
            printf( "}\\\\\n\\hline" );
        else if ( htmlMode == ON )
            printf( "</TD></TR>" );
        printf( "\n" );
    }
    isoFromAbsolute( g, &a1, &a2, &a3 );
    if ( latexMode == ON ) {
        printf( "\\hline\n" );
        printf( "ISO�`�� & \\multicolumn{3}{l|}{%4d�N��%2d�T��%2d��}\\\\\n",
                a3, a1, a2);
        printf( "\\hline\n\\hline\n" );
    }
    else if ( htmlMode == ON )
        printf(
           "<TR><TD>ISO�`��</TD><TD COLSPAN=2>%4d�N��%2d�T��%2d��</TD></TR>\n",
               a3, a1, a2 );
    else
        printf( "ISO�`��           %4d�N��%2d�T��%2d��\n", a3, a1, a2 );

    if ( latexMode == ON )
        printf("�O���S���I�� & %4d�N%2d��%2d�� & \\multicolumn{2}{l|}{%s�j�� ",
               yy, mm, dd, weekday(g) );
    else if ( htmlMode == ON )
        printf(
	     "<TR><TD>�O���S���I��</TD><TD>%4d�N%2d��(%s)%2d��</TD><TD>%s�j��",
                yy, mm, englishMonthName(mm), dd, weekday(g) );
    else
        printf( "�O���S���I��      %4d�N%2d��(%s)%2d��  %s�j��",
                yy, mm, englishMonthName(mm), dd, weekday(g) );
    checkAmerican( g, dd, mm, yy, htmlMode );
    if ( latexMode == ON )
        printf( "}\\\\\n\\hline" );
    else if ( htmlMode == ON )
        printf( "</TD></TR>" );
    printf( "\n" );

    julianFromAbsolute( g, &a1, &a2, &a3 );
    if ( latexMode == ON )
        printf( "�����E�X�� & %4d�N%2d��%2d�� & \\multicolumn{2}{l|}{",
                a3, a2, a1 );
    else if ( htmlMode == ON )
        printf( "<TR><TD>�����E�X��</TD><TD>%4d�N%2d��(%s)%2d��</TD><TD>",
                a3, a2, latinMonthName(a2), a1 );
    else
        printf( "�����E�X��        %4d�N%2d��(%s)%2d��",
	        a3, a2, latinMonthName(a2), a1 );
    checkRoman( g, a1, a2, a3 );
    checkGreek( g, a1, a2, a3, mm, yy );
    if ( latexMode == ON )
        printf( "}\\\\\n\\hline" );
    else if ( htmlMode == ON )
        printf( "</TD></TR>" );
    printf( "\n" );

    islamicFromAbsolute( g, &a1, &a2, &a3 );
    if ( latexMode == ON )
        printf( "�C�X������ & %4d�N%2d��%2d�� & \\multicolumn{2}{l|}{",
                a3, a2, a1 );
    else if ( htmlMode == ON )
        printf( "<TR><TD>�C�X������</TD><TD>%4d�N%2d��(%s)%2d��</TD><TD>",
                a3, a2, islamicMonthName(a2), a1 );
    else
        printf( "�C�X������        %4d�N%2d��(%s)%2d��",
                a3, a2, islamicMonthName(a2), a1 );
    checkIslamic( g, a1, a2, a3, yy );
    if ( latexMode == ON )
        printf( "}\\\\\n\\hline" );
    else if ( htmlMode == ON )
        printf( "</TD></TR>" );
    printf( "\n" );

    hebrewFromAbsolute( g, &a1, &a2, &a3 );
    if ( latexMode == ON )
        printf( "���_���� & %4d�N%2d��%2d�� & \\multicolumn{2}{l|}{",
                a3, a2, a1 );
    else if ( htmlMode == ON )
        printf(
	    "<TR><TD>���_����</TD><TD>%4d�N%2d��(%s)%2d��</TD><TD COILSPAN=2>",
                a3, a2, hebrewMonthName(a2, a3), a1 );
    else
        printf( "���_����          %4d�N%2d��(%s)%2d��",
                a3, a2, hebrewMonthName(a2, a3), a1 );
    checkHebrew( g, a1, a2, a3, mm, yy );
    if ( latexMode == ON )
        printf( "}\\\\\n\\hline" );
    else if ( htmlMode == ON )
        printf( "</TD></TR>" );
    printf( "\n" );

    if ( simplemode == OFF ) {
        /*
         * �}���֘A�w��ł̒���Ɋ�Â��}��������
         */
        if ( latexMode == ON ) {
            printf( "\\hline\n" );
            printf( "�}�������� & %s & \\multicolumn{2}{l|}{%s %s}\\\\\n",
                    mayaFromAbsolute( g ),
                    tsolkinFromAbsolute( g ),
                    haabuFromAbsolute( g )    );
        }
        else if ( htmlMode == ON )
            printf( "<TR><TD>�}��������</TD><TD>%s</TD><TD>%s %s</TD></TR>\n",
                    mayaFromAbsolute( g ),
                    tsolkinFromAbsolute( g ),
                    haabuFromAbsolute( g )    );
        else {
            printf( "�}��������        %s\t%s %s\n",
                    mayaFromAbsolute( g ),
                    tsolkinFromAbsolute( g ),
                    haabuFromAbsolute( g )    );
#if     0
/*
 * �ȉ���
 *     ``Calendrical Calculations, Part II: Three Historical Calendars''
 *     by E. M. Reingold,  N. Dershowitz, and S. M. Clamen,
 *     Software--Practice and Experience, Volume 23, Number 4 (April, 1993),
 *     pages 383-404.
 * �ɂ��Z�o���@�Ɋ�Â��}��������
 * (GNU Emacs �� calendar�֘AELISP�v���O�����ō̗p���Ă���B������2������
 *  �t���Ⴍ�Ȃ��Ă���)
 */
            printf( "Goodman-Martinez-Thompson���Ɋ�Â��}��������\n" );
            printf( "                  %s\t%s %s\n",
                    mayaFromAbsolute( g - 2L ),
                    tsolkinFromAbsolute( g - 2L ),
                    haabuFromAbsolute( g - 2L )    );
#endif

        /*
         * Spinden���Ɋ�Â��}��������
         *    Spinden���͒���Ɏ����ŗL�͂Ȑ�
         */
            if ( printSpinden == ON ) {
                printf( "Spinden���Ɋ�Â��}��������\n" );
                printf( "                  %s\t%s %s\n",
                        mayaFromAbsolute(g - 2L + (1137140L - 1232041L)),
                        tsolkinFromAbsolute(g - 2L + (1137140L - 1232041L)),
                        haabuFromAbsolute(g - 2L + (1137140L - 1232041L))   );
            }
        }

        /*
         * �}���֘A�w��ł̒���Ɋ�Â��}���Z����
         */
        if ( latexMode == ON ) {
            printf( "\\hline\n" );
            printf( "�}���Z���� & \\multicolumn{3}{l|}{%s}\\\\\n",
                    katunFromAbsolute( g ) );
            printf( "\\hline\n" );
        }
        else if ( htmlMode == ON )
            printf( "<TR><TD>�}���Z����</TD><TD COLSPAN=2>%s</TD></TR>\n",
                    katunFromAbsolute( g ) );
        else
            printf( "�}���Z����     %s\n", katunFromAbsolute( g ) );
    }

    if ( (yy >= 1975) || (yy <= 1799) ||
         ((yy == 1974) &&
          (g >= absoluteFromGregorian( 23, 9, 1974 )))  ||
         ((yy == 1800) &&
          (g <= absoluteFromGregorian( 22, 9, 1800 )))     ) {
        if ( latexMode == ON ) {
            printf( "\\hline\n" );
            printf( "�t�����X�v���� & \\multicolumn{3}{l|}{%s}\\\\\n",
                    fdate( g, dd, mm, yy, HH, MM, SS, printTime, OFF ) );
            printf( "\\hline\n" );
        }
        else if ( htmlMode == ON )
            printf( "<TR><TD>�t�����X�v����</TD><TD COLSPAN=2>%s</TD></TR>\n",
                    fdate( g, dd, mm, yy, HH, MM, SS, printTime, htmlMode ) );
        else
            printf( "�t�����X�v����  %s\n",
                    fdate( g, dd, mm, yy, HH, MM, SS, printTime, htmlMode ) );
    }
    if ( latexMode == ON ) {
        printf( "\\hline\n" );
        printf( "�a�� & %s  & \\multicolumn{2}{l|}{%s %s %s",
                wareki( dd, mm, yy, 0 ), kyusei(g), nijuhachishuku( g ),
                junichoku( g, dd, mm, yy, &a1 ) );
        if ( ( p = sanrinbou( g, a1 ) ) != NULL )
            printf( " %s", p );
    }
    else if ( htmlMode == ON ) {
        printf( "<TR><TD>�a��(���z��)</TD><TD>%s</TD><TD>%s %s %s",
                wareki( dd, mm, yy, 0 ), kyusei(g), nijuhachishuku( g ),
                junichoku( g, dd, mm, yy, &a1 ) );
        if ( ( p = sanrinbou( g, a1 ) ) != NULL )
            printf( " %s", p );
    }
    else {
        printf( "�a�� ���z��     %s  %s  %s  %s",
                wareki( dd, mm, yy, 0 ), kyusei(g), nijuhachishuku( g ),
                junichoku( g, dd, mm, yy, &a1 ) );
        if ( ( p = sanrinbou( g, a1 ) ) != NULL )
            printf( "  %s", p );
    }
    checkJapanese( g, dd, mm, yy );
    if ( latexMode == ON )
        printf( "}\\\\\n\\hline" );
    else if ( htmlMode == ON )
        printf( "</TD></TR>" );
    printf( "\n" );
    if ( ( ( yy >  1975 ) && ( yy < 2064 ) ) ||
         ( ( yy == 1975 ) && ( ( mm >  3 ) ||
                               ( mm == 3 ) && ( dd >= 13 ) ) ) ||
         ( ( yy == 2064 ) && ( ( mm <  9 ) ||
                               ( mm == 9 ) && ( dd <= 16 ) ) ) ) {
        a1 = dd; a2 = mm; a3 = yy;
        p  = get_kyureki( &a1, &a2, &a3, &uruu );
        if ( latexMode == ON ) {
            printf( "���A���z�� & %s & \\multicolumn{2}{l|}{",
                    wareki( a1, a2, a3, uruu ) );
            checkKyureki( a1, a2, a3, uruu, p, htmlMode );
            printf( "}\\\\\n" );
            printf( "\\hline\n" );
        }
        else if ( htmlMode == ON ) {
            printf( "<TR><TD>(���A���z��)</TD><TD>%s</TD><TD>",
                    wareki( a1, a2, a3, uruu ) );
            checkKyureki( a1, a2, a3, uruu, p, htmlMode );
            printf( "</TD></TR>\n" );
        }
        else {
            printf( "     ���A���z�� %s", wareki( a1, a2, a3, uruu ) );
            checkKyureki( a1, a2, a3, uruu, p, htmlMode );
            putchar( '\n' );
        }
    }

    if ( latexMode == ON ) {
        printf( "���x & %s", splitEto( eto( g, yy, OFF ) ) );
        checkEto( g, htmlMode );
        printf( "\\\\\n" );

        printf( "\\hline\n\\hline\n" );
        printf( "���� & %s & \\\\\n", split2( zodiac( g, yy ) ) );
        printf( "\\hline\n" );
        if ( printZodiac13 == ON ) {
            printf( "13���� & %s & \\\\\n", split2( zodiac13(g,yy) ) );
            printf( "\\hline\n" );
        }
    }
    else if ( htmlMode == ON ) {
        printf( "<TR><TD>���x</TD><TD>%s",
                eto( g, yy, htmlMode ));
        checkEto( g, htmlMode );
        printf( "</TD></TR>\n" );

        printf("<TR><TD>�����I��</TD><TD COLSPAN=2>%4d�N%2d��%2d��</TD></TR>\n"
               , yy + 543, mm, dd );
        printf( "<TR><TD>�l�p�[����</TD><TD COLSPAN=2>%s</TD></TR>\n",
                nepdate(g, dd, mm, yy, HH, MM, SS, printTime) );
        printf( "<TR><TD>����</TD><TD COLSPAN=2>%s</TD></TR>\n",
                zodiac(g,yy));
        if ( printZodiac13 == ON )
            printf( "<TR><TD>13����</TD><TD COLSPAN=2>%s</TD></TR>\n",
                    zodiac13(g,yy));
    }
    else {
        printf( "     ���x       %s", eto( g, yy, htmlMode ) );
        checkEto( g, htmlMode );
        putchar( '\n' );

        printf( "     �c�I         %4d�N%2d��%2d��\n", yy + 660, mm, dd );
        printf( "�����I��          %4d�N%2d��%2d��\n", yy + 543, mm, dd );
        printf( "�l�p�[����        %s\n",
                nepdate(g, dd, mm, yy, HH, MM, SS, printTime) );
        if ( ((yy == 2001) && (mm == 12) && (dd >  15)) ||
             ((yy >= 2002) && (yy <= 2011))             ||
             ((yy == 2012) && (mm ==  1) && (dd <= 22))    ) {
            char    *p = indianLunarDate( dd, mm, yy, HH, MM, SS );
            if ( p ) {
                printf( "�C���h���A��      %s\n", p );
            }
        }
        printf( "����                      %s\n", zodiac( g, yy ) );
        if ( printZodiac13 == ON )
            printf( "13����                    %s\n", zodiac13( g, yy ) );
    }

    if ( latexMode == ON ) {
        printf( "\\end{tabular}\n\\end{center}\\end{table}\n" );
        printf( "\\begin{verbatim}\n" );
    }
    else if ( htmlMode == ON ) {
        printf( "</TABLE></CENTER>\n<P><PRE>\n" );
    }

    if ( printTrain == ON )
        trainService( g, dd, mm, yy );
    if ( printBirthday == ON )
        birthday( g, dd, mm, yy );
    if ( printIdolEvent == ON )
        idolevent( g, dd, mm, yy );

    if ( htmlMode == ON ) {
        printf( "</PRE>\n" );
    }

    if ( printComicsInfo == ON )
        comics( g, dd, mm, yy );
    if ( latexMode == ON ) {
        printf( "\\end{verbatim}\n" );
        if ( withHeader == ON )
            printf( "\\end{document}\n" );
    }
    else if ( htmlMode == ON ) {
        if ( cgi == ON )
            showMethod( yy, mm, dd, HH, MM, SS );
        if ( withHeader == ON )
            printf( "</BODY>\n</HTML>\n" );
    }
}

int
main( int argc, char *argv[] )
{
    int     yy, mm, dd, HH, MM, SS;

    yy = mm = dd = HH = MM = SS = 0;

    if ( (strlen(argv[0]) >= 4) &&
         !strcmp( &argv[0][strlen(argv[0]) - 4], ".cgi" ) ) {
        char    *p;

        cgi        = ON;
        htmlMode   = ON;
        withHeader = ON;
        printf( "Content-type: text/html\n\n" );
        if ( ( p = getenv( "QUERY_STRING" ) ) != NULL )
            setParameter( p, &yy, &mm, &dd, &HH, &MM, &SS );
    }

    if ( argc > 1 ) {
        int     i;

        for ( i = 1; i < argc; i++ ) {
            if ( !strcmpi( argv[i], "yesterday" ) ) {
                yesterday = 1;
                continue;
            }
            if ( !strcmpi( argv[i], "tomorrow" ) ) {
                tomorrow = 1;
                continue;
            }
            if ( argv[i][0] == '-' ) {
                do {
                    switch ( argv[i][1] ) {
                      case 'v' :    /* version */
                        version();
                        exit( 255 );
                        break;
                      case 'h' :    /* help */
                      case '?' :
                        usage();
                        exit( 255 );
                        break;
                      case 'd' :
                        printTime = OFF;
                        break;
                      case 'e' :
                        printIdolEvent = ON;
                        break;
                      case 'b' :
                        printBirthday = ON;
                        break;
                      case 'i' :
                        printAircheckInfo = ON;
                        break;
                      case 'c' :
                        printComicsInfo = ON;
                        break;
                      case 'H' :
                        printHistory = ON;
                        break;
                      case 'E' :
                        printEvent = ON;
                        break;
                      case 't' :
                        printToday = ON;
                        break;
                      case 'T' :
                        printTsupo = ON;
                        break;
                      case 's' :
                        simplemode = ON;
                        break;
                      case 'J' :
                        printTrain = ON;
                        break;
                      case 'm' :
                        printSpinden = ON;
                        break;
                      case 'z' :
                        printZodiac13 = ON;
                        break;
                      case 'a' :
                      case 'A' :
                        printIdolEvent    = ON;
                        printBirthday     = ON;
                        printAircheckInfo = ON;
                        printComicsInfo   = ON;
                        printHistory      = ON;
                        printEvent        = ON;
                        printToday        = ON;
                        printTsupo        = ON;
                        printTrain        = ON;
                        printSpinden      = ON;
                        printZodiac13     = ON;
                        break;
                      case 'L':
                      case 'M':
                        if ( argv[i][1] == 'L' ) {
                            latexMode = ON;
                            htmlMode  = OFF;
                        }
                        else {
                            latexMode = OFF;
                            htmlMode  = ON;
                        }
                        if ( (argv[i][2] == '-') || (argv[i][2] == '-') ) {
                            char *p = &argv[i][1];
                            char *q = &argv[i][2];

                            withHeader = (argv[i][2] == '-') ? OFF : ON;
                            *p = *q;
                            while ( *q )
                                *++p = *++q;
                        }
                        break;
                      default :
                        version();
                        usage();
                        return ( 255 );
                        break;
                    }
                    {
                        char *p = &argv[i][1];
                        char *q = &argv[i][2];

                        *p = *q;
                        while ( *q )
                            *++p = *++q;
                    }
                } while ( argv[i][1] != NUL );
                continue;
            }

            if ( ( argv[i][0] >= '0' ) && ( argv[i][0] <= '9' ) ) {
                int         len = strlen( argv[i] );
                static int  count = 0;

                switch ( len ) {
                  case 1 :
                  case 2 :
                    switch ( ++count ) {
                      case 1 :
                        yy = atoi( argv[i] ) + 1900;
                        break;
                      case 2 :
                        mm = atoi( argv[i] );
                        break;
                      case 3 :
                        dd = atoi( argv[i] );
                        break;
                      case 4 :
                        HH = atoi( argv[i] );
                        break;
                      case 5 :
                        MM = atoi( argv[i] );
                        break;
                      case 6 :
                        SS = atoi( argv[i] );
                        break;
                    }
                    break;
                  case 4 :
                    switch ( ++count ) {
                      case 1 :
                        yy = atoi( argv[i] );
                        break;
                      case 2 :
                        mm = atoi( argv[i] ) / 100;
                        dd = atoi( argv[i] ) % 100;
                        count++;
                        break;
                    }
                    break;
                  case 6 :
                    switch ( ++count ) {
                      case 1 :
                        yy = (int)( atol( argv[i] ) / 10000L ) + 1900;
                        mm = (int)( atol( argv[i] ) / 100L % 100L );
                        dd = (int)( atol( argv[i] ) % 100L );
                        count += 2;
                        break;
                      case 4 :
                        HH = (int)( atol( argv[i] ) / 10000L );
                        MM = (int)( atol( argv[i] ) / 100L % 100L );
                        SS = (int)( atol( argv[i] ) % 100L );
                        count += 2;
                        break;
                    }
                    break;
                  case 8 :
                    switch ( ++count ) {
                      case 1 :
                        yy = (int)( atol( argv[i] ) / 10000L );
                        mm = (int)( atol( argv[i] ) / 100L % 100L );
                        dd = (int)( atol( argv[i] ) % 100L );
                        count += 2;
                        break;
                    }
                    break;
                }
            }
        }
    }

    if ( ( yy == 00 ) && ( mm == 00 ) && ( dd == 00 ) ) {
        time_t      t;
        struct tm   *tm;
        int         _mm = 0;

        time( &t );
        if ( tomorrow ) {
            tm = localtime( &t );
            _mm = tm->tm_mon + 1;
            t += 24 * 60 * 60;
        }
        else if ( yesterday ) {
            tm = localtime( &t );
            _mm = tm->tm_mon + 1;
            t -= 24 * 60 * 60;
        }
        tm = localtime( &t );

        yy = tm->tm_year + 1900;
        mm = tm->tm_mon + 1;
        dd = tm->tm_mday;
        HH = tm->tm_hour;
        MM = tm->tm_min;
        SS = tm->tm_sec;

        if ( yesterday || tomorrow ) {
            if ( mm != _mm ) {
                if ( yesterday )
                    yesterday++;
                else
                    tomorrow++;
            }
        }
    }

    koyomi( yy, mm, dd, HH, MM, SS );

    return ( 1 );
}

