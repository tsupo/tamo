/*
 *  coptic.c				tsupo@na.rim.or.jp
 *      �G�`�I�s�A��Z�o�v���O����    2 April 2003
 *  Copyright (c) 2003 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: coptic.c $
 * Revision 1.2  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.1  2003/04/02  10:19:14  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamo.h"

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/coptic.c 1.2 2003/11/11 07:02:19 tsujimura543 Exp tsujimura543 $";
#endif

/*
 * �R�v�g��(�G�`�I�s�A��)
 *   30���̌���12��������A5��(�[�N�̂Ƃ���6��)�̌���1��1�N���\���B
 *   ���݂́A�[�N�͐���(�O���S���I��)�ɍ��킹�Ă���B
 *   (���ẮA�����E�X��Ɠ��l�A4�Ŋ���؂��N���[�N�Ƃ��A900�N��2��
 *    �␳���s�����@���̗p���Ă����炵��)
 */

static char     *coptMonthName[] = {
  "Meskerem",   /*  1�� (�}�X�J����)   �G�W�v�g�\�L: Thuout             */
  "Tikemet",    /*  2�� (�e�P���g)     �G�W�v�g�\�L: Paopi              */
  "Hidar",      /*  3�� (�w�_��)       �G�W�v�g�\�L: Athor              */
  "Tahesas",    /*  4�� (�^�[�T�X)     �G�W�v�g�\�L: Khoiak             */
  "Tir",        /*  5�� (�e��)         �G�W�v�g�\�L: Tobi               */
  "Yekatit",    /*  6�� (�C�F�J�e�B�g) �G�W�v�g�\�L: Mekhir             */
  "Megabit",    /*  7�� (���K�r�g)     �G�W�v�g�\�L: Fameno / Baramhat  */
  "Miyaza",     /*  8�� (�~�A�W�A)     �G�W�v�g�\�L: Farmou / Baramouda */
  "Ginbot",     /*  9�� (�O�G���{�g)   �G�W�v�g�\�L: Pakhon             */
  "Sene",       /* 10�� (�Z�l)         �G�W�v�g�\�L: Paony              */
  "Hamle",      /* 11�� (�n����)       �G�W�v�g�\�L: Epep               */
  "Nehase",     /* 12�� (�l�n�b�Z)     �G�W�v�g�\�L: Mesori             */
  "Paguemen",   /* 13�� (�p�S�E����)   �G�W�v�g�\�L: Nasie              */
  NULL
};

static int      coptDays[] = {
    30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5
};

/*
 *	�O���S���I��2002�N9��11�����G�`�I�s�A��1995�N1��1���ɑ�������
 */

int
copDaysOfYear( int cY )
{
    int     y = cY - 1995 + 2003 + 1;   /* �Ō�� + 1 �� �[�N�� when.exe ��
                                           ���킹�邽�߂̕␳               */
    return ( leapyear(y) ? 366 : 365 );
}


char    *
copdate( long g, int dd, int mm, int yy )
{
    static char buf[BUFSIZ];
    int         cY, cM, cD;
    int         d, _d;
    long        base;

    if (  (yy <= 7) ||
         ((yy == 8) &&
             ( (mm <  9) ||
              ((mm == 9) && (dd < 11)))) ) {
        return ( "���̎����̃G�`�I�s�A��̓T�|�[�g���Ă��܂���" );
    }

    /* �܂��A�G�`�I�s�A��́u�N�v�����߂� */
    base = absoluteFromGregorian( 11, 9, 2002 );
    d    = base;
    if ( g >= base ) {
        /* �����薢���̓��t�̏ꍇ */
        for ( cY = 1995; ; cY++ ) {
            _d = copDaysOfYear( cY );
            if ( d + _d > g ) {
                break;
            }
            d += _d;
        }
    }
    else {
        /* ������ߋ��̓��t�̏ꍇ */
        for ( cY = 1994; ; cY-- ) {
            _d = copDaysOfYear( cY );
            d -= _d;
            if ( d <= g ) {
                break;
            }
        }
    }

    /* �u���v�����߂� */
    cM = cD = _d = 1;
    do {
        _d = coptDays[cM - 1];
        if ( _d >= g - d + 1 ) {
            break;
        }
        cM++;
        d += _d;
    } while ( cM <= 12 );

    /* �u���v�����߂� */
    cD = g - d + 1;

    sprintf( buf, "%4d�N%2d��(%s)%2d��",
             cY, cM, coptMonthName[cM - 1], cD );

    return ( buf );
}

