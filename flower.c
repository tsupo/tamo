/*
 *  flower.c
 *              by H.Tsujimura  (tsupo@na.rim.or.jp)
 *                      7 March 2003
 *
 *  Copyright (c) 1991-1996,1999,2001,2002,2003 Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: flower.c $
 * Revision 1.71  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.70  2003/04/16  05:56:37  tsujimura543
 * �f�[�^�t�@�C�������̋K���ɂ��������ĒT�����I�[�v������悤�ɂ���
 *
 * Revision 1.69  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.68  2003/03/14  09:37:59  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.67  2003/03/11  12:13:53  tsujimura543
 * �R�����g�𐮗�
 *
 * Revision 1.66  2003/03/11  02:12:35  tsujimura543
 * �a�����E�a�����̉ԁA�Ԍ��t�݂̂ɋ@�\���i��
 *
 * Revision 1.65  2003/02/21  10:53:35  tsujimura543
 * K&R��C�ŃR���p�C���ł��Ȃ��Ȃ��Ă����̂��A�ĂуR���p�C���ł���悤�ɏC��
 *
 * Revision 1.64  2003/02/10  07:25:58  tsujimura543
 * �C�x���g���\���������C��
 *
 * Revision 1.63  2003/02/10  04:23:14  tsujimura543
 * �����ɔ����āA�e�֐����ē��\�ɂ���
 *
 * Revision 1.62  2003/02/06  04:02:42  tsujimura543
 * today �̒a�����f�[�^�t�@�C��(birthday.tbl)�ɑΉ�
 *
 * Revision 1.61  2001/06/13  13:24:23  tsujimura543
 * �u����v�A�u�����v�\���Ή�
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.54  2001/02/19  22:15:28  tsujimura543
 * �a���Ԃ̎Z�o�֐��ɁA�a�����̉ԁA�a���΂�\�����邽�߂̋@�\��ǉ�
 * 
 * Revision 1.53  2001/02/02  16:05:33  tsujimura543
 * �a���ԁA�L�����y�[��(XX�T�ԁAXX���ԂȂ�)�̊e�Z�o�֐���ǉ�
 * 
 * Revision 1.52  2000/08/23  11:01:18  tsujimura543
 * �R�~�b�N�V�����̊i�[����Ă���t�@�C���`���������_�� fj.rec.comics �ŗ�
 * �ʂ��Ă�����̂ɍ��킹���B�܂��A�t�@�C�����̊����R�[�h�� JIS �̂܂܂ł���
 * ���ł���悤�ɂ���
 * 
 * Revision 1.51  1999/07/06  18:52:13  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1996/12/13  17:17:06  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.10  95/12/03 11:42:10  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.9  92/03/29 04:22:40  tsujimura
 * test release
 * 
 * Revision 1.8  91/05/01 14:02:54  tsujimura
 * changed date format of "idol event"
 * 
 * Revision 1.7  91/04/27 00:08:48  tsujimura
 * BUG FIX: spacing() is working OK, even if string includes KANJI
 * 
 * Revision 1.6  91/04/26 23:47:56  tsujimura
 * supported for information of new comics
 * 
 * Revision 1.5  91/04/08 02:19:56  tsujimura
 * Bug fix: idolevent() reports future events
 * 
 * Revision 1.4  91/03/24 03:54:24  tsujimura
 * test version
 * 
 * Revision 1.3  91/03/24 03:54:24  tsujimura
 * bug fixed (getDataPath)
 * 
 * Revision 1.2  91/03/24 03:29:52  tsujimura
 * (1) changed how to print out birthday-calendar
 * (2) added a function to print out idol-event-calendar
 * 
 * Revision 1.1  91/03/02 06:02:20  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#ifdef	UNIX
#include <sys/param.h>
#endif
#include <string.h>
#include "tamo.h"

#ifndef	lint
static char	*rcs_id =
	"$Header: C:/user/local/src/tamo/RCS/flower.c 1.71 2003/11/11 07:02:19 tsujimura543 Exp tsujimura543 $";
#endif


/* �f�[�^�t�@�C���� */
static char	*flowerTblFile  = "tbl/flower.tbl";


/* �a���� */
static char	*birthStone[12] = {
    "�������",             "������",       "���ʁA����",
    "�_�C�������h",         "�G�������h",   "�^��A������",
    "���r�[",               "�Ԏ�����",     "�T�t�@�C�A",
    "�I�p�[���A�g���}����", "�g�p�[�Y",     "�g���R�΁A�W���R��"
};

/* �a�����̉� */
static char	*birthFlower[12] = {
    "�J�[�l�[�V�����A�X�m�[�h���b�v",
    "�X�~���A�T�N���\�E",
    "�L�Y�C�Z���A�X�~��",
    "�q�i�M�N�A�X�C�[�g�s�[",
    "�T���U�V�A�X�Y����",
    "�o���A�X�C�J�Y��",
    "�q�G���\�E�A�X�C����",
    "�O���W�I���X�A�P�V",
    "�A�T�K�I�A�V�I��",
    "�L���Z���J�A�R�X���X",
    "�L�N",
    "�X�C�Z���A�Z�C���E�q�C���M�A�|�C���Z�`�A"
};


void
flower( long g, int dd, int mm, int yy )
{
    FILE    *fp;
    char    buf[BUFSIZ], *p = NULL, *q = NULL;
    long    m, d;
    int     found = 0;

    if ( ( fp = tfopen( flowerTblFile, "r" ) ) == NULL )
        return;

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
        if ( (*p >= '0') && (*p <= '1') ) {
            q = strchr( p, ' ' );
            if ( q && (*(q + 1) >= '0' && (*(q + 1) <= '9')) ) {
                m = atoi( p );
                d = atoi( q + 1 );
                if ( (m == mm) && (d == dd) ) {
                    found = 1;
                    break;
                }
            }
        }
    }
    tfclose( fp );

    if ( (found == 1) && q ) {
        p = strchr( q + 1, ' ' );
        if ( !p )
            p = strchr( q + 1, '\t' );
        if ( p && *(p + 1) ) {
            q = strchr( p + 1, ' ' );
            if ( !q )
                q = strchr( p + 1, '\t' );
            if ( q && *(q + 1) ) {
                *q++ = NUL;
                while ( (*p == ' ') || (*p == '\t') )
                    p++;
                while ( (*q == ' ') || (*q == '\t') )
                    q++;
                while ( (q[strlen(q) - 1] == '\n') ||
                        (q[strlen(q) - 1] == ' ' ) ||
                        (q[strlen(q) - 1] == '\t')    )
                    q[strlen(q) - 1] = NUL;
                if ( *q ) {
                    putchar( '\n' );
                    printf( "�����̒a����: %s\n      �a����: %s\n",
                            birthStone[mm - 1], birthFlower[mm - 1] );
                    printf( "�����̒a����: %s\n      �Ԍ��t: �w%s�x\n",
                            p, q );
                }
            }
        }
    }
}

