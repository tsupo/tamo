/*
 *  nepali.c                tsupo@na.rim.or.jp
 *      �l�p�[����Z�o�v���O����    19 February 2003
 *  Copyright (c) 2003 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: nepali.c $
 * Revision 1.19  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.18  2003/10/24  02:41:14  tsujimura543
 * �f�[�^�t�@�C���̒u���ꏊ�𓝈�
 *
 * Revision 1.17  2003/06/02  11:23:15  tsujimura543
 * �l�p�[�����A��̎Z�o���@�A�\�����@���C���B�C���h���A��̉[���\�����C���B
 *
 * Revision 1.16  2003/05/30  10:46:40  tsujimura543
 * �l�p�[���̍s���A�j�Փ��̕\�����ꕔ�Ή�
 *
 * Revision 1.15  2003/05/26  08:32:30  tsujimura543
 * �C���h������Ɋւ���s��C��
 *
 * Revision 1.14  2003/05/26  07:49:56  tsujimura543
 * �C���h������(���Ɨ�)�Ή��A�l�p�[�����A��C��
 *
 * Revision 1.13  2003/04/16  05:56:37  tsujimura543
 * �f�[�^�t�@�C�������̋K���ɂ��������ĒT�����I�[�v������悤�ɂ���
 *
 * Revision 1.12  2003/04/11  10:58:56  tsujimura543
 * (1) �C���h���A��\���̌����ɉ��Ԗڂ̌����𕹋L����悤�ɂ���
 * (2) �l�p�[�����A��\����ǉ� (�b��)
 *
 * Revision 1.11  2003/04/04  08:45:38  tsujimura543
 * �C���h���A��́u�N�v�\���𐼗�\������{���̃C���h��\���ɂ���
 *
 * Revision 1.10  2003/03/31  11:22:59  tsujimura543
 * �R�����g��ǉ�
 *
 * Revision 1.9  2003/03/20  01:36:51  tsujimura543
 * �R�����g��ǉ�
 *
 * Revision 1.8  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.7  2003/03/11  02:03:24  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.6  2003/03/04  06:03:32  tsujimura543
 * �C���h���A��̉[���Ή�
 *
 * Revision 1.5  2003/03/03  07:48:25  tsujimura543
 * �C���h���A��Ή�
 *
 * Revision 1.4  2003/02/24  10:48:05  tsujimura543
 * �l�p�[����̎����b�\�L�ɑΉ�
 *
 * Revision 1.3  2003/02/19  09:00:33  tsujimura543
 * BS�I���ȑO���ǂ����̃`�F�b�N�����̕s����C��
 *
 * Revision 1.2  2003/02/19  08:09:15  tsujimura543
 * BS2061�N1��1����BS2060�N13��1���ɂȂ��Ă��܂��s����C��
 *
 * Revision 1.1  2003/02/19  07:29:36  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef	TAMO
# include "tamo.h"
# include "tamo_dates.h"
#else
# include "dates.h"
# define tfopen(filename,mode)   fopen((filename),(mode))
# define tfclose(fp)             fclose(fp)
#endif

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/nepali.c 1.19 2003/11/11 07:02:19 tsujimura543 Exp tsujimura543 $";
#endif

static char *nepaliMonthName[] =
{
    "Baishak", "Jyestha", "Ashad", "Sharwan", "Bhadra", "Ashwin",
    "Kartik",  "Mangsir", "Poush", "Margh",   "Falgun", "Chaitra"
};

#define NEPALICYCLE (27 + 27 + 27 + 27 + 27 + 4)    /* ���� */
    /* �u27�N������5��������A4�N�̌ł܂肪1�����v�p�^�[�����J��Ԃ� */

static long nepaliDays[12] = {
    30, 31, 31, 31, 31, 30, 29, 29, 29, 29, 29, 30
};

static long nepaliMonthPattern[13][12] = {
    /* ��1�O���[�v */
    /*  �p�^�[�� K */   { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, /*  0 */
    /*  �p�^�[�� A */   { 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, /*  1 */
    /*  �p�^�[�� F */   { 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, /*  2 */
    /*  �p�^�[�� I */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 }, /*  3 */

    /* ��2�O���[�v */
    /*  �p�^�[�� B */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1 }, /*  4 */
    /*  �p�^�[�� G */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 }, /*  5 */

    /* ��3�O���[�v */
    /*  �p�^�[�� H */   { 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 }, /*  6 */
    /*  �p�^�[�� E */   { 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 }, /*  7 */
    /*  �p�^�[�� C */   { 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1 }, /*  8 */
    /*  �p�^�[�� N */   { 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /*  9 */
    /*  �p�^�[�� M */   { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 10 */
    /*  �p�^�[�� J */   { 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 }, /* 11 */

    /* ��4�O���[�v */
    /*  �p�^�[�� D */   { 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0 }  /* 12 */
};

static long nepaliYearPattern[NEPALICYCLE] = {
    /* �ŏ���27�N                          */
    /*   ABMD ABCD ABED FBHD IGHD IGDD BJD */
     1 /* A */,  4 /* B */, 10 /* M */, 12 /* D */,
     1 /* A */,  4 /* B */,  8 /* C */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
                 4 /* B */, 11 /* J */, 12 /* D */,

    /* 2�Ԗڂ�27�N                         */
    /*   ABMD ABCD ABED ABHD IGHD IGDD BJD */
     1 /* A */,  4 /* B */, 10 /* M */, 12 /* D */,
     1 /* A */,  4 /* B */,  8 /* C */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
                 4 /* B */, 11 /* J */, 12 /* D */,

    /* 3�Ԗڂ�27�N                         */
    /*   ABJD ABND ABED ABED FGHD IGDD IGD */
     1 /* A */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* 4�Ԗڂ�27�N                         */
    /*   KBJD ABND ABED ABED FBHD IGDD IGD */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* 5�Ԗڂ�27�N                         */
    /*   KBJD ABND ABED ABED FBHD IGHD IGD */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* �Ō��4�N                           */
    /*   KBJD                              */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */
    /*           ~~~~~~~~~~                          */
    /*            �� ���̗�ɕ���ł���N��366���̔N */
    /*               ����ȊO��365���̔N             */
};

/* Bikram Sambat 2053�N Baishak�� 1�� �� ���� 1996�N4��13��         */
/* �{�v���O�����ł́A�ȒP�̂��߁ABikram Sambat 2060�N Baishak�� 1�� */
/* (=2003�N4��14��) ������Ƃ���                                  */



/* �w�肵���l�p�[����́u�N�v��1�N�Ԃ̓��������߂� */
long
nepDaysOfYear( int yy ) /* yy: �l�p�[����́u�N�v */
{
    int pattern = (yy + 25) % NEPALICYCLE;
    int days    = 365;

    if ( (nepaliYearPattern[pattern] == 4) ||
         (nepaliYearPattern[pattern] == 5)    ) {
        /* �p�^�[��B �܂��� �p�^�[��G �̔N�̂� 366�� */
        days++;
    }

    return ( days );
}


/* �����E�X������Ή�����l�p�[����̔N���������߂�                        */
/*   (1) �����b[�l�p�[�����n����]                                          */
/*        ���{���ԂƂ̎����� -3����15��, GMT �Ƃ̎����� +5����45��         */
/*   (2) �j�Փ��̕\���͏����Ή�                                            */
/*        �E����̔N�����Ɋ�Â��j�Փ��� dd, mm, yy ��茈��               */
/*        �E�l�p�[����(���z��)�Ɋ�Â��j�Փ��� nY, nM, nD �ɂ�茈��       */
/*        �E���A��(tithi)�Ɋ�Â��j�Փ��́A�ʓr�A���A����Z�o����K�v����  */
char    *
nepdate(long g, int dd, int mm, int yy, int HH, int MM, int SS, int printTime)
{
    static char buf[BUFSIZ];
    int         nY, nM = 1, nD = 1, nHH, nMM, nSS;
    long        base, d, _d;
    long        pattern;

    if ( yy <= -57 ) {
        return ( "Bikram Sambat ���N �����ߋ��̗�̓T�|�[�g���Ă��܂���" );
    }

    if ( (printTime == ON) ||
         (HH != 0) || (MM != 0) || (SS != 0) ) {
        nHH = HH - 3;
        nMM = MM - 15;
        nSS = SS;
        if ( nMM < 0 ) {
            nHH--;
            nMM += 60;
        }
        if ( nHH < 0 ) {
            g--;
            nHH += 24;
        }
    }

    /* �܂��A�l�p�[����́u�N�v�����߂� */
    base = absoluteFromGregorian( 14, 4, 2003 );
    d    = base;
    if ( g >= base ) {
        /* �����薢���̓��t�̏ꍇ */
        for ( nY = 2060; ; nY++ ) {
            _d = nepDaysOfYear( nY );
            if ( d + _d > g ) {
                break;
            }
            d += _d;
        }
    }
    else {
        /* ������ߋ��̓��t�̏ꍇ */
        for ( nY = 2059; ; nY-- ) {
            _d = nepDaysOfYear( nY );
            d -= _d;
            if ( d <= g ) {
                break;
            }
        }
    }
    pattern = (nY + 25) % NEPALICYCLE;

    /* �u���v�����߂� */
    nM = nD = _d = 1;
    do {
        _d = nepaliDays[nM - 1] +
                 nepaliMonthPattern[nepaliYearPattern[pattern]][nM - 1];
        if ( _d >= g - d + 1 ) {
            break;
        }
        nM++;
        d += _d;
    } while ( nM <= 12 );

    /* �u���v�����߂� */
    nD = g - d + 1;

    if ( printTime == ON ) {
        sprintf( buf, "%4d�N%2d��(%s)%2d�� %2d��%2d��%2d�b",
                 nY, nM, nepaliMonthName[(nM + 11) % 12], nD,
                 nHH, nMM, nSS );
    }
    else {
        sprintf( buf, "%4d�N%2d��(%s)%2d��",
                 nY, nM, nepaliMonthName[(nM + 11) % 12], nD );
    }

#ifdef  TAMO
    if ( (mm == 3) && (dd > 1) && isFullMoonDay( yy, mm, dd ) )
        strcat( buf, "*�z�[���[����" );
    if ( (nM == 1) && (nD == 1) )
        strcat( buf, "*�V�N*�r�X�P�[�g��" );
    if ( (nM == 12) &&
         (nD == nepaliDays[nM - 1] +
                nepaliMonthPattern[nepaliYearPattern[pattern]][nM - 1]) )
        strcat( buf, "*��A��*�r�X�P�[�g��(������)" );
    if ( (mm == 11) && (dd == 8) )  /* ���� 11��8�� */
        strcat( buf, "*���@�L�O��" );
#endif

    return ( buf );
}



static void
changeFormat( char *p )
{
    int     yy, mm, dd;
    char    buf[BUFSIZ];
    char    *q = p;

    dd = (*q - '0') * 10 + (*(q + 1) - '0');
    q +=3;
    mm = (*q - '0') * 10 + (*(q + 1) - '0');
    q +=3;
    yy = atol( q );
    q += 4;
    sprintf( buf, "%04d%02d%02d%s", yy, mm, dd, q );
    strcpy( p, buf );
}


long
indianYear( int yy, int mm, char *monthName )
{
    int     year = yy + 1925 - 2003;

    if ( mm <= 2 ) {
        year--;
    }
    else if ( (mm == 3) || (mm == 4) ) {
        if ( strcmp( monthName, "Chaitra" ) != 0 ) {
            year--;
        }
    }

    return ( year );
}


static char *indianMonthName[] = {
    "Chaitra", "Vaishakh", "Jyeshta",     "Ashadha", "Shravana", "Bhadrapad",
    "Ashvin",  "Kartik",   "Margashirsh", "Paush",   "Magh",     "Phalgun"
};

char    *
indianMonth( const char *monthName )
{
    static char buf[BUFSIZ];
    const char  *p   = monthName;
    int         uruu = 0;
    int         i;

    buf[0] = '\0';
    if ( !strncmp( monthName, "Adhik ", strlen("Adhik ") ) ) {
        p += strlen("Adhik ");
        uruu = 1;
    }
    else if ( !strncmp( monthName, "Nij ", strlen("Nij ") ) ) {
        p += strlen("Nij ");
    }

    for ( i = 0; i < 12; i++ ) {
        if ( !strcmp( p, indianMonthName[i] ) ) {
            if ( uruu )
                sprintf( buf, "�[%2d��(%s)", i + 1, monthName );
            else
                sprintf( buf, "%2d��(%s)",   i + 1, monthName );
            break;
        }
    }

    return ( buf );
}


#define WHITE   0
#define BLACK   1

char    *
nepaliLunarMonth( char *monthName,
                  int year, int month,  /* ����N�� */
                  int whiteBlack )
{
    static char buf[BUFSIZ];
    char        *p   = monthName;
    int         uruu = 0, adhik = 0, nij = 0;
    int         i, j;

    year = year + 2060 - 2003;
    buf[0] = '\0';
    if ( !strncmp( monthName, "Adhik ", strlen("Adhik ") ) ) {
        p += strlen("Adhik ");
        adhik = 1;
     /* if ( whiteBlack == BLACK ) */
            uruu = 1;
    }
    else if ( !strncmp( monthName, "Nij ", strlen("Nij ") ) ) {
        p += strlen("Nij ");
        if ( whiteBlack == WHITE ) {
         /* uruu = 1; */
            nij  = 1;
        }
    }

    for ( i = 0; i < 12; i++ ) {
        if ( !strcmp( p, indianMonthName[i] ) ) {
            j = i;
            if ( (whiteBlack == WHITE) || adhik )
                j = (i + 11) % 12;
            if ( month <= 4 )
                if ( (j % 12) + 1 >= 9 )
                    year--;
            if ( uruu )
                sprintf( buf, "%4d�N�[%2d��(Adhik %s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            else if ( nij )
                sprintf( buf, "%4d�N%2d��(Nij %s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            else
                sprintf( buf, "%4d�N%2d��(%s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            break;
        }
    }

    return ( buf );
}


/*
 *  �C���h���A��(tithi)
 *      �V��(��)�ɂȂ����u�Ԃ�����1���ŁA�Ȍ�A���������Ă����ɂ�A
 *      ����2���A3���A...�A15���ƂȂ�B�܂��A���������Ă����ɂ�A
 *      ����1���A2���A...�A15���ƂȂ�B�C���h���A���1���́A�V������
 *      ���̐V���܂ł̌��̈ʑ���0�x����360�x�Ƃ����Ƃ��A360/30 = 12�x
 *      �����鎞�Ԃł���A1���̒����͈�肵�Ă��Ȃ�(24���Ԃ��Z��
 *      �Ƃ�������΁A�����Ƃ�������)�B���������āA���t�ύX�̃^�C�~
 *      ���O�́A���̖��������̏󋵂Ɉˑ�����(���̗�ƈႢ�A���t�ύX
 *      �̃^�C�~���O�́A�n����̂ǂ̈ʒu�ł������ɂȂ�[�������Ȃ�])�B
 *      ��{�I�ɁA��A�W�A���瓌��A�W�A�Ŏg���鑾�A��� tithi ��
 *      ���邪�A����1���������ƂȂ�n�悪�������A�l�p�[���ł͍���1��
 *      �������ƂȂ�ȂǁA�����ɒn��ɂ���ĉ^�p���@���قȂ�B�C���h
 *      �����ł́AChaitra �̔���1���AChaitra �̍���1���AKartik �̔���
 *      1���AKartik �̍���1���̂��ꂼ�ꂪ�N���ƂȂ�������e�n��ɋ���
 *      ���Ă���B
 *      �{�v���O�����ł́AChaitra �̔���1����N���Ƃ�����\������B
 *
 *      tithi.txt �� ����2001�N12��15���`2012�N1��22���� tithi �̓�
 *      �t�ύX�^�C�~���O���f�ڂ���B���� tithi.txt �́A
 *
 *          Tithi Timer v.01 March 2002 (����)
 *            by Michael W. Taft   http://www.jyotish.net/
 *              (http://www.jyotish.net/tithi_timer_download.htm)
 *
 *      �ɂ��o�͌��ʂ����ɍ쐬�������̂ł���BindianLunarDate() ��
 *      tithi.txt �����ɁAtithi �̓��t�����肷��B
 *
 *      ����2003�N4��3�����C���h���A��1925�N1��(Chaitra)����1���A
 *                        �C���h���z��1925�N1��(Chaitra)13��
 *      �ɑ�������B
 *
 */

char    *
indianLunarDate( int dd, int mm, int yy, int HH, int MM, int SS )
{
    static char dateString[80];
    char        targetString[80];
    char        buf[BUFSIZ], *p, *q, *r, *s;
    int         len, year, preYear, flag;
    char        monthName[16], preMonthName[16];
    char        preString[BUFSIZ];
    FILE        *fp;
    int         r1 = 0, r2;

    if ( ( fp = tfopen( "tbl/tithi.txt", "r" ) ) == NULL ) {
        return ( NULL );
    }

    preMonthName[0] = '\0';
    preString[0]    = '\0';
    year = preYear = 0;
    sprintf( targetString, "%04d%02d%02d %02d:%02d:%02d",
             yy, mm, dd, HH, MM, SS );
    len  = strlen( targetString );
    flag = 0;

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
        while ( (*p == '\t') || (*p == ' ') )
            p++;
        if ( !(*p) || (*p == '\n') )
            continue;
        if ( (*p < '0') || (*p > '9') ) {
            q = strchr( p, ' ' );
            if ( q ) {
                if ( (*(q + 1) < '0') || (*(q + 1) > '9') ) {
					/* �[���Ή� */
                    char    *r = strchr( q + 1, ' ' );
                    q = r;
                }
                if ( q ) {
                    *q = '\0';
                    strcpy( monthName, p );
                    year = atol( q + 1 );
                    flag = 0;
                }
            }
            continue;
        }

        changeFormat( p );
        r2 = strncmp( p, targetString, len );
        if ( r2 > 0 ) {
            p = preString;
            p += len;
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            while ( (*p != ' ') && (*p != '\t') )
                p++;
            while ( (*p == ' ') || (*p == '\t') )
                p++;

            q = strchr( p, '.' ) + 1;
            if ( q ) {
                while ( (*q == ' ') || (*q == '\t') )
                    q++;

                s = q;
                while ( (*s != ' ') && (*s != '\t') )
                    s++;
                while ( (*s == ' ') || (*s == '\t') )
                    s++;

                if ( (r = strchr( q, '\t' )) != NULL )
                    *r = '\0';
                if ( (r = strchr( q, ' '  )) != NULL )
                    *r = '\0';

                sprintf( dateString, "%4d�N%s %s��%2d�� %s",
                         indianYear( yy, mm, preMonthName ),
                         indianMonth( preMonthName ),
                         strstr( s, "Shukla" ) != NULL ? "��" : "��",
                         atol( p ), q );
            }

            break;
        }

        if ( flag == 0 ) {
            strcpy( preMonthName, monthName );
            preYear = year;
            flag    = 1;
        }

        strcpy( preString, p );
        r1 = r2;
    }
    tfclose( fp );

    return ( dateString[0] == '\0' ? NULL : dateString );
}



/*
 *  �l�p�[�����A��
 *      �C���h���A��(tithi)�����Ƀl�p�[�����A������߂�B
 *      Baishak���̍���1�����N���ƂȂ�B
 */

char    *
nepaliLunarDate( int dd, int mm, int yy, int HH, int MM, int SS )
{
    static char dateString[80];
    char        targetString[80];
    char        buf[BUFSIZ], *p, *q, *r, *s;
    int         len, year, preYear, flag;
    char        monthName[16], preMonthName[16];
    char        preString[BUFSIZ];
    FILE        *fp;
    int         r1 = 0, r2;

    if ( ( fp = tfopen( "tbl/tithi.txt", "r" ) ) == NULL ) {
        return ( NULL );
    }

    preMonthName[0] = '\0';
    preString[0]    = '\0';
    year = preYear = 0;
    sprintf( targetString, "%04d%02d%02d %02d:%02d:%02d",
             yy, mm, dd, HH, MM, SS );
    len  = strlen( targetString );
    flag = 0;

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
        while ( (*p == '\t') || (*p == ' ') )
            p++;
        if ( !(*p) || (*p == '\n') )
            continue;
        if ( (*p < '0') || (*p > '9') ) {
            q = strchr( p, ' ' );
            if ( q ) {
                if ( (*(q + 1) < '0') || (*(q + 1) > '9') ) {
					/* �[���Ή� */
                    char    *r = strchr( q + 1, ' ' );
                    q = r;
                }
                if ( q ) {
                    *q = '\0';
                    strcpy( monthName, p );
                    year = atol( q + 1 );
                    flag = 0;
                }
            }
            continue;
        }

        changeFormat( p );
        r2 = strncmp( p, targetString, len );
        if ( r2 > 0 ) {
            p = preString;
            p += len;
            while ( (*p == ' ') || (*p == '\t') )
                p++;
            while ( (*p != ' ') && (*p != '\t') )
                p++;
            while ( (*p == ' ') || (*p == '\t') )
                p++;

            q = strchr( p, '.' ) + 1;
            if ( q ) {
                while ( (*q == ' ') || (*q == '\t') )
                    q++;

                s = q;
                while ( (*s != ' ') && (*s != '\t') )
                    s++;
                while ( (*s == ' ') || (*s == '\t') )
                    s++;

                if ( (r = strchr( q, '\t' )) != NULL )
                    *r = '\0';
                if ( (r = strchr( q, ' '  )) != NULL )
                    *r = '\0';

                sprintf( dateString, "%s %s��%2d��",
                         nepaliLunarMonth( preMonthName,
                                           yy, mm,
                                           strstr( s, "Shukla" ) != NULL
                                                ? WHITE
                                                : BLACK
                                         ),
                         strstr( s, "Shukla" ) != NULL ? "��" : "��",
                         atol( p )
                       );
            }

            break;
        }

        if ( flag == 0 ) {
            strcpy( preMonthName, monthName );
            preYear = year;
            flag    = 1;
        }

        strcpy( preString, p );
        r1 = r2;
    }
    tfclose( fp );

    return ( dateString[0] == '\0' ? NULL : dateString );
}


/*
 * �C���h���Ɨ�(������) Indian National Calendar
 *   Saka�I���̗�����ɁA�C���h���{��1957�N�ɐ���B
 *   ���Ԉ�ʂł́A���܂�g���Ă��Ȃ��炵���B
 *
 *    �Q�l: http://www.indianastrology.com/learn/calander.asp
 *      �C���h���Ɨ�
 *        ���z�Ɋ�Â�����B1�N�͑��z���Y�r���ɓ���Ƃ��Ɏn�܂�B
 *        1957�N3��22������C���h���{�ɂ��g�p�J�n�B1957�N3��22����
 *        Saka�I��1879�N Chaitra ����1���ɑΉ��B�e���̊J�n�����ȉ���
 *        �悤�Ɋ��蓖�Ă�B
 *
 *          ����       ���� �J�n��
 *          Chaitra    30�� �O���S���I��� 3��22��
 *                      (�������A�O���S���I��̉[�N�ɂ�����N�͓�����
 *                       31���Ƃ��A�J�n�����O���S���I���3��21���Ƃ���)
 *          Vaisakha   31�� �O���S���I��� 4��21��
 *          Jyaistha   31�� �O���S���I��� 5��22��
 *          Asadha     31�� �O���S���I��� 6��22��
 *          Sravana    31�� �O���S���I��� 7��23��
 *          Bhadra     31�� �O���S���I��� 8��23��
 *          Asvina     30�� �O���S���I��� 9��23��
 *          Kartika    30�� �O���S���I���10��23��
 *          Agrahayana 30�� �O���S���I���11��22��
 *          Pausa      30�� �O���S���I���12��22��
 *          Magha      30�� �O���S���I��� 1��21��
 *          Phalgun    30�� �O���S���I��� 2��20��
 */

static int  startDay[12] = {
    21, 20, 22, 21, 22, 22, 23, 23, 23, 23, 22, 22
};

char    *
indianNationalDate( int dd, int mm, int yy )
{
    static char dateString[80];
    int         iyy, imm, idd;
    long        g1, g2;

    iyy = yy - 1957 + 1879;
    if ( ( mm <= 2)                             ||
         ((mm == 3) &&
          ((leapyear(yy)  && (dd <= 20)) ||
           (!leapyear(yy) && (dd <= 21))    ) )    ) {
        iyy--;
    }

    g1 = absoluteFromGregorian( startDay[mm - 1], mm, yy );
    if ( (mm == 3) && leapyear(yy) )
        g1--;
    g2 = absoluteFromGregorian( dd, mm, yy );
    if ( g1 > g2 ) {
        imm = (mm + 8) % 12;
        g1 = absoluteFromGregorian( startDay[(mm + 10) % 12],
                                    ((mm + 10) % 12) + 1,
                                    mm == 1 ? yy - 1 : yy );
        if ( (mm - 1 == 3) && leapyear(yy) )
            g1--;
        idd = g2 - g1 + 1;
    }
    else {
        imm = (mm + 9) % 12;
        idd = g2 - g1 + 1;
    }

    sprintf( dateString, "%4d�N%2d��(%s)%2d��", iyy, imm + 1, indianMonthName[imm], idd );

    return ( dateString );
}
