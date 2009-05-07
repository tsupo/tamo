/*
 *      tamo.c
 *                      by H.Tsujimura  tsupo@na.rim.or.jp
 *                                              17 February 1991
 *      Copyright (c) 1991,1992,1995,1997,1999-2001,2003,2007 Hiroshi Tsujimura
 *      All Rights Reserved.
 *
 * History :
 * $Log: tamo.c $
 * Revision 1.90  2007/02/06  10:58:53  tsujimura543
 * copyright �\�L���A�b�v�f�[�g
 *
 * Revision 1.89  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.88  2003/05/06  09:33:53  tsujimura543
 * htmlMode �� OFF �̂Ƃ��A�L�����y�[����\������悤�ɂ���
 *
 * Revision 1.87  2003/04/25  11:24:15  tsujimura543
 * ���C�΍���\������悤�ɂ���
 *
 * Revision 1.86  2003/04/24  04:29:28  tsujimura543
 * �֘A�����N��\������悤�ɂ���(html���[�h��)
 *
 * Revision 1.85  2003/04/23  06:09:29  tsujimura543
 * HTML���[�h���A�I���O�͑Ή����Ă��Ȃ��|�A�\������悤�ɂ���
 *
 * Revision 1.84  2003/04/16  05:56:37  tsujimura543
 * �f�[�^�t�@�C�������̋K���ɂ��������ĒT�����I�[�v������悤�ɂ���
 *
 * Revision 1.83  2003/03/14  09:56:25  tsujimura543
 * ���������Ή����� #3
 *
 * Revision 1.82  2003/03/14  09:37:59  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.81  2003/03/12  10:18:22  tsujimura543
 * HTML�o�͎��̃t�����X�v����̏o�͌`����ύX
 *
 * Revision 1.80  2003/03/12  10:05:31  tsujimura543
 * ���������Ή����� #2
 *
 * Revision 1.79  2003/03/12  06:49:40  tsujimura543
 * ���������Ή�����
 *
 * Revision 1.78  2003/03/11  12:11:43  tsujimura543
 * ����v�Z�͈̔͂�1�N�`9999�N�܂őΉ�����(���x�͂Ƃ������Ƃ���)
 *
 * Revision 1.77  2003/03/11  02:08:09  tsujimura543
 * Tsuporone's Activity Memo --- preview version
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
#include <sys/stat.h>
#include "tamo.h"

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/tamo.c 1.90 2007/02/06 10:58:53 tsujimura543 Exp tsujimura543 $";
#endif


#ifdef  __TURBOC__
extern unsigned _stklen = 8192U;
#endif

char    execpath[MAXFNAMELEN];

static void
version( void )
{
    printf( "Tsuporone's Activity MemO $Revision: 1.90 $ by H.Tsujimura\n" );
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
usage( void )
{
  printf("Usage:\n");
  printf("  tamo [-advAJTM] [{YYYY|yy}[mm[dd [HH[MM[SS]]]]]]]\n");
  printf("    -A: print out all information, if possibble.\n" );
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



#define getParamFromURL( param, target )    \
    if ( !strncmp( p, (param), 2 ) ) {      \
        p += 2;                             \
        q = &(buf[0]);                      \
        while ( *p && (*p != '&') )         \
            *q++ = *p++;                    \
        *q = NUL;                           \
        if ( *p == '&' )                    \
            p++;                            \
        r = decodeURL( buf );               \
        if ( (*r >= '0') && (*r <= '9') ) { \
            (target) = atoi( r );           \
            flag = ON;                      \
        }                                   \
    }

static void
setParameter( const char *p, int *yy, int *mm, int *dd,
              int *HH, int *MM, int *SS, int *printTime )
{
    char    *q, *r;
    char    buf[BUFSIZ];
    int     flag = OFF;

    while ( *p ) {
        q = NULL;

        getParamFromURL( "y=", *yy );
        getParamFromURL( "m=", *mm );
        getParamFromURL( "d=", *dd );
        getParamFromURL( "H=", *HH );
        getParamFromURL( "M=", *MM );
        getParamFromURL( "S=", *SS );

        if ( !q )
            p++;
    }

    *printTime = flag;
}


/*
 * ���C�A�E�g
 *
 *   +-----------------------------------------------------+
 *   |�w�b�_��                                             |
 *   | <HTML>                                              |
 *   | <HEAD>                                              |
 *   | <TITLE>.....</TITLE>                                |
 *   | </HEAD>                                             |
 *   | <BODY>                                              |
 *   +-----------------------------------------------------+
 *   |�啶                                                 |
 *   | <P>.....                                            |
 *   +-----------------------------------------------------+
 *   |�S�́E�e�[�u���w�b�_                                 |
 *   | <TABLE>                                             |
 *   | <TR><TD>                                            |
 *   +----------------------------+------------------------+
 *   |����ݕ��E�e�[�u���w�b�_    |���o�E���v��            |
 *   |   <TABLE>                  |  <P>.....              |
 *   +----------------------------+                        |
 *   |����ݕ�                    +------------------------+
 *   |   <TR><TD>                 |����E�e�[�u���w�b�_  |
 *   |     .....                  |  <TABLE>               |
 *   |   </TD><TD>                +------------------------+
 *   |     .....                  |���                  |
 *   |   </TD></TR>               |  <TR><TD>              |
 *   |                            |    .....               |
 *   +----------------------------+  </TD><TD>             |
 *   | ����ݕ��E�e�[�u���t�b�^   |    .....               |
 *   |   </TABLE>                 |  </TD></TR>            |
 *   |                            +------------------------+
 *   +----------------------------+����E�e�[�u���t�b�^  |
 *   |�e����                  |  </TABLE>              |
 *   |   <P>.....                 |                        |
 *   +----------------------------+                        |
 *   |�S�́E�e�[�u���Ԏd�؂蕔    |                        |
 *   | </TD><TD>                  |                        |
 *   +----------------------------+------------------------+
 *   |�S�́E�e�[�u���t�b�^                                 |
 *   | </TD></TR>                                          |
 *   | <TR><TD COLSPAN="2" ALIGN="CENTER">                 |
 *   |   �J�����_�[                                        |
 *   | </TD></TR>                                          |
 *   | </TABLE>                                            |
 *   +-----------------------------------------------------+
 *   |�t�b�^��                                             |
 *   | </BODY>                                             |
 *   | </HTML>                                             |
 *   +-----------------------------------------------------+
 *
 */

static void
koyomi( int yy, int mm, int dd, int HH, int MM, int SS,
        int htmlMode, int withHeader,
        int printTime, int printTrain, int printTsupo )
{
    int     a1, a2, a3;
    long    g;

    /* �N�����̐��K�� (��: 2003�N13��32�� �� 2003�N14��1�� �� 2004�N2��1��) */
    g = absoluteFromGregorian( dd, mm, yy ); /* ����1�N1��1������̒ʓ� */
    gregorianFromAbsolute( g, &a1, &a2, &a3 );
    yy = a3; mm = a2; dd = a1;

    /* �w�b�_���o�� */
    printHeader( yy, mm, dd, htmlMode, withHeader );

    if ( (yy <= 0) && htmlMode ) {
        printf("<P>�I���O�ɂ͑Ή����Ă��܂���B�������炸�A���������������B");
        printf("<P><A HREF=\"tamo.cgi\">�߂�</A>\n</BODY>\n</HTML>\n");
        return;
    }

    /* �啶�o�� */
    printMainStatement( yy, mm, dd, HH, MM, SS, printTime, htmlMode );

    /* �S�́E�e�[�u���w�b�_�o�� */
    printTableHeader( htmlMode );

    /* --- ���㕔�o�� --- */
    /* ����ݕ��o�� */
    tamo_koyomi( yy, mm, dd, HH, MM, SS, g, htmlMode, printTime, printTsupo );

    /* �e���� */
    tamo_information( yy, mm, dd, g, htmlMode, printTrain );

    /* �S�́E�e�[�u���Ԏd�؂蕔�o�� */
    printTableSeparator( htmlMode );

    /* --- �E�㕔�o�� --- */
    /* ���o�E���v���o�� */
    tamo_solar( yy, mm, dd, htmlMode );

    /* ���C�΍����o�� */
    tamo_igrf( yy, mm, dd, htmlMode );

    /* ����o�� */
    tamo_moon( yy, mm, dd, HH, MM, SS, htmlMode );

    /* �L�����y�[���o�� */
    tamo_campaign( yy, mm, dd, g, htmlMode );

    /* �֘A�y�[�WURL�o�� */
    tamo_link( yy, mm, dd, htmlMode );

    /* �S�́E�e�[�u���t�b�^�o�� */
    printTableFooter( yy, mm, dd, HH, MM, SS, htmlMode );

    /* �t�b�^���o�� */
    printFooter( htmlMode, withHeader );
}

int
main( int argc, char *argv[] )
{
    int     yy, mm, dd, HH, MM, SS;
    int     printTsupo = OFF;
    int     printTime  = ON;
    int     printTrain = OFF;
    int     htmlMode   = OFF;
    int     withHeader = ON;
    char    *p;

    yy = mm = dd = HH = MM = SS = 0;
    strcpy( execpath, argv[0] );
    if ( ( p = strrchr( execpath, '/' ) ) != NULL )
        *p = '\0';
#ifndef UNIX
    else if ( ( p = strrchr( execpath, '\\' ) ) != NULL )
        *p = '\0';
#endif
    else /* if ( p == NULL ) */
        strcpy( execpath, "." );

    if ( (strlen(argv[0]) >= 4) &&
         !strcmp( &argv[0][strlen(argv[0]) - 4], ".cgi" ) ) {

        if ( ( p = getenv( "REQUEST_METHOD" ) ) != NULL ) {
            if ( !strcmp( p, "HEAD" ) ) {
                struct stat s;

                if ( !stat( argv[0], &s ) ) {
                    printf( "Last-Modified: %s", ctime( &(s.st_ctime) ) );
                }
                else {
                    time_t  t = time( NULL );
                    printf( "Last-Modified: %s", ctime( &t ) );
                }
                fputs( "Content-type: text/html\n\n", stdout );
                return ( 0 );
            }
        }

        htmlMode   = ON;
        withHeader = ON;
        fputs( "Content-type: text/html\n\n", stdout );
        if ( ( p = getenv( "QUERY_STRING" ) ) != NULL )
            setParameter( p, &yy, &mm, &dd, &HH, &MM, &SS, &printTime );
    }

    if ( argc > 1 ) {
        int     i;

        for ( i = 1; i < argc; i++ ) {
            if ( argv[i][0] == '-' ) {
                do {
                    switch ( argv[i][1] ) {
                      case 'v' :    /* version */
                        version();
                        return ( 255 );
                        break;
                      case 'h' :    /* help */
                      case '?' :
                        usage();
                        return ( 255 );
                        break;
                      case 'd' :
                        printTime = OFF;
                        break;
                      case 'T' :
                        printTsupo = ON;
                        break;
                      case 'J' :
                        printTrain = ON;
                        break;
                      case 'a' :
                      case 'A' :
                        printTsupo = ON;
                        printTrain = ON;
                        break;
                      case 'M':
                        htmlMode = ON;
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
        tm = localtime( &t );

        yy = tm->tm_year + 1900;
        mm = tm->tm_mon  + 1;
        dd = tm->tm_mday;
        HH = tm->tm_hour;
        MM = tm->tm_min;
        SS = tm->tm_sec;

        if ( htmlMode )
            printTime = ON;
    }

    koyomi( yy, mm, dd, HH, MM, SS,
            htmlMode, withHeader, printTime, printTrain, printTsupo );

    return ( 0 );
}

