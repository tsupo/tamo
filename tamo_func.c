/*
 *      tamo_func.c
 *                      by H.Tsujimura  tsupo@na.rim.or.jp
 *                                              2 March 1991
 *      Copyright (c) 1991-1995,1998-2001,2003-2005,2007 Hiroshi Tsujimura
 *      All Rights Reserved.
 *
 * History :
 * $Log: tamo_func.c $
 * Revision 1.106  2009/04/27  11:41:54  tsujimura543
 * �C���f���g�C��
 *
 * Revision 1.105  2007/10/18  12:17:49  tsujimura543
 * �u�Ƒ��̓��v�Ή�
 *
 * Revision 1.104  2007/02/20  04:47:37  tsujimura543
 * 18�����Ղ̔������ԁA�ʗp���Ԃ��ŋ߂̏󋵂ɍ��킹�ďC��
 *
 * Revision 1.103  2007/02/08  06:41:41  tsujimura543
 * �Ď��Ԋ֘A�̏������C��
 *
 * Revision 1.102  2007/02/08  02:44:01  tsujimura543
 * �Ď��Ԃ̊J�n�A�I���֘A������ύX�E�ǉ�
 *
 * Revision 1.101  2007/02/06  10:50:23  tsujimura543
 * copyright �\�L���A�b�v�f�[�g
 *
 * Revision 1.100  2007/02/06  10:48:33  tsujimura543
 * Chandeleur ��ǉ�
 *
 * Revision 1.99  2007/02/05  15:13:52  tsujimura543
 * Bank Holiday �̐U��ւ��x���ɑΉ�����
 *
 * Revision 1.98  2005/05/13  12:54:44  tsujimura543
 * �U�֋x���̈�������V�����j���@�ɍ��킹�ďC��
 *
 * Revision 1.97  2005/05/13  02:54:10  tsujimura543
 * 2007�N����4��29�����u���a�̓��v�A5��4�����u�݂ǂ�̓��v�ɂȂ�j���@
 * �����ɑΉ�
 *
 * Revision 1.96  2004/09/16  01:08:57  tsujimura543
 * ��r�̗�(���a�V�c)��1������̏j�����������ǉ�
 *
 * Revision 1.95  2004/01/13  10:54:58  tsujimura543
 * �u�h�V�̓��v�Ɓu�H���̓��v�ɂ͂��܂ꂽ�u�����̋x���v�ɑΉ��B
 *
 * Revision 1.94  2003/11/11  09:11:42  tsujimura543
 * �����E�X��A�C�X������A���_����̕\�����œK��
 *
 * Revision 1.93  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.92  2003/11/07  12:03:00  tsujimura543
 * ���O���̏j�Փ���ǉ�
 *
 * Revision 1.91  2003/06/20  04:14:27  tsujimura543
 * �}�[�Y�E�C�[�N(��6���N��1��̉ΐ�����ڋ�)�ɑΉ�
 *
 * Revision 1.90  2003/05/30  07:49:19  tsujimura543
 * ���ۓI�ȍs������ǉ�
 *
 * Revision 1.89  2003/05/28  11:00:11  tsujimura543
 * ����ȂǂɑΉ�
 *
 * Revision 1.88  2003/05/27  12:20:06  tsujimura543
 * tamo_func.c ���� #define �̈ꕔ�� tamo.h �Ɉړ�
 *
 * Revision 1.87  2003/05/27  09:56:35  tsujimura543
 * ������A�j���{�Ȃǂ�ǉ�
 *
 * Revision 1.86  2003/05/27  09:05:33  tsujimura543
 * ��p�n�߁A��p�[�߂ɑΉ�
 *
 * Revision 1.85  2003/05/20  06:00:31  tsujimura543
 * �S���Ԃɂ킽����24�ߋG��\������悤�ɂ���
 *
 * Revision 1.84  2003/04/23  11:09:07  tsujimura543
 * ���~�A���Đ��A�y�p�̕\���𑾗z��̕��ֈڂ�
 * (����̏C���ŕK�v�Ȃ��Ȃ����֐����폜)
 *
 * Revision 1.83  2003/04/23  09:27:12  tsujimura543
 * 24�ߋC�̕\���𑾉A���z��(����)���瑾�z��(�V��)�̕��Ɉڂ�
 *
 * Revision 1.82  2003/04/17  10:34:15  tsujimura543
 * �\�������𒲐�
 *
 * Revision 1.81  2003/04/15  05:25:33  tsujimura543
 * �u�n���~�v��ǉ�
 *
 * Revision 1.80  2003/03/24  08:58:03  tsujimura543
 * (1) �a��(���A���z��)�̕\���\���Ԃ��g��
 * (2) �友�Ɠy�p�̉N�̓����d�Ȃ����ꍇ�A�Е������\������Ȃ��s����C��
 *
 * Revision 1.79  2003/03/20  10:04:33  tsujimura543
 * ��������u�ߓ����ɂ�錎�v�ł͂Ȃ��A���ۂ̋���̌������Ɍv�Z����悤�C��
 *
 * Revision 1.78  2003/03/20  09:18:02  tsujimura543
 * �e���̕\����ǉ�
 *
 * Revision 1.77  2003/03/19  04:46:08  tsujimura543
 * ���x�̏o�͕����𑼂̗�Ɠ����ɂ���
 *
 * Revision 1.76  2003/03/19  03:05:48  tsujimura543
 * ����֌W�̏o�͕��@�𑼂̗�Ɠ��������ɂ���
 *
 * Revision 1.75  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.74  2003/03/17  07:36:50  tsujimura543
 * �\�[�X����
 *
 * Revision 1.73  2003/03/14  09:37:59  tsujimura543
 * �֐��𐮗�
 *
 * Revision 1.72  2003/03/11  02:09:28  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.71  2003/03/07  03:16:24  tsujimura543
 * ���[�}��(�����E�X��)�� ides �\����ǉ�
 *
 * Revision 1.70  2003/02/28  06:53:31  tsujimura543
 * 2002�N5��6�����U�֋x���ƕ\������Ȃ��s����C��(Rev1.69�̏C���~�X������)
 *
 * Revision 1.69  2003/02/25  06:03:55  tsujimura543
 * 2003�N5��5�����U�֋x���ƕ\������Ă��܂��s��ɑΏ�
 *
 * Revision 1.68  2003/02/19  07:29:36  tsujimura543
 * �l�p�[����Ή�
 *
 * Revision 1.67  2003/02/10  05:02:42  tsujimura543
 * �t�����X�v���L�O���A�h�C�c����L�O������ǉ�
 *
 * Revision 1.66  2003/02/07  04:47:44  tsujimura543
 * �C�X������̏j�Փ��\�L���኱�ύX
 *
 * Revision 1.65  2003/02/06  09:41:58  tsujimura543
 * ���_�����̏j�Փ���ǉ�
 *
 * Revision 1.64  2003/02/05  10:08:32  tsujimura543
 * �����ۂ��܂�̊J�Ê��Ԃ�2��5������ɂȂ����̂ɑΉ�
 *
 * Revision 1.63  2001/06/15  11:11:21  tsujimura543
 * �u�V�l�̓��v�Ή�
 *
 * Revision 1.62  2001/06/13  13:02:52  tsujimura543
 * �u���V�A�̓��v��ǉ�
 *
 * Revision 1.61  2001/05/25  13:52:26  tsujimura543
 * 2003�N����A�C�̓��ƌh�V�̓������ꂼ��7���A9���̑�3���j���ɂȂ�̂ɑΉ�
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.57  2001/02/05  21:57:57  tsujimura543
 * ���񂪉���ڂ́u�����ۂ��Ղ�v���\������悤�ɕύX
 * 
 * Revision 1.56  2001/02/02  16:14:56  tsujimura543
 * (1) �u�����ۂ��Ղ�v�̕\���@�\��ǉ�
 * (2) �u�f��̓��v�̕\���@�\��ύX(1956�N�ȍ~�̔N�̂ݕ\������悤�ɂ���)
 * 
 * Revision 1.55  2001/01/22  22:18:34  tsujimura543
 * (1) (int)0xFFFFFFFF �̒l�����̒l�ɂȂ�}�V���ŏj�����\������Ȃ��Ȃ�s�
 *     �ɑΏ�
 * (2) �r�X�P�b�g�̓��A���C�̓��A�Ȃǂ̕\���@�\��ǉ�
 * (3) ��O�̏j�����������ǉ�
 * (4) 13�����̎Z�o�֐���ǉ�
 * 
 * Revision 1.54  2000/06/01  10:24:06  tsujimura543
 * �Ď��Ԃ̊J�n���̕\���p�֐����A�����J�ƃ��[���b�p�ŕʂ̂��̂ɂ���
 * 
 * Revision 1.53  2000/03/30  20:41:36  tsujimura543
 * (1) ���̓��A�{�X�̓��̕\���@�\��ǉ�
 * (2) �����̌h�V�̓��̕\���@�\��ǉ�
 * 
 * Revision 1.52  1999/11/01  17:24:21  tsujimura543
 * 18�ؕ��̎g�p���Ԃ̕\�����C��(���s��ǉ�)
 * 
 * Revision 1.51  1999/07/13  12:00:36  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1998/02/06  15:37:58  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.8  95/12/03 12:03:54  tsujimura
 * �R�����g�̐����E�C��
 * 
 * Revision 1.7  95/12/03 02:32:26  tsujimura
 * trainService() �� bug fix
 * 
 * Revision 1.6  95/12/03 02:12:06  tsujimura
 * JR�̗����v�Z�̓�����Z�o��ǉ�
 * 
 * Revision 1.5  95/12/03 01:53:14  tsujimura
 * ���{�̏j�Փ��𖾎����ȍ~�Ɋւ��Ċ��S�Ή�
 * 
 * Revision 1.4  92/03/29 03:19:38  tsujimura
 * test release
 * 
 * Revision 1.3  91/03/17 17:01:20  tsujimura
 * test version
 * 
 * Revision 1.2  91/03/17 17:01:20  tsujimura
 * (1) added some holidays
 * (2) changed functions for calculation of old-japanese-calendar
 * 
 * Revision 1.1  91/03/02 06:00:48  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if     0
#include <values.h>
#else
#define MAXINT  (int)(999999)
#endif
#include "tamo.h"

#ifndef lint
static char     *rcs_id =
        "$Header: C:/user/local/src/tamo/RCS/tamo_func.c 1.106 2009/04/27 11:41:54 tsujimura543 Exp tsujimura543 $";
#endif

/*
 * �e���̏j�Փ���
 *    http://www.holidayfestival.com/
 *  ���Q�l�ɂȂ�
 */

static long     easterday;
static long     roshHaShanah;   /* @@ */
static long     passoverday;
static long     tishaBAvday;    /* @@ */
static long     risshunday;
static long     shunbunday;
static long     geshiday;
static long     risshuuday;
static long     shuubunday;

static struct ZODIAC    {
        char    *sign;
        int     mm;
        int     dd;
} z[12] = {     "���r��  Aquarius",      1,     20,
                "  ����  Pisces",        2,     19,
                "���r��  Aries",         3,     21,
                "������  Taurus",        4,     20,
                "�o�q��  Gemini",        5,     21,
                "  �I��  Cancer",        6,     22,
                "���q��  Leo",           7,     23,
                "������  Virgo",         8,     23,
                "�V����  Libra",         9,     23,
                "  嶍�  Scorpio",      10,     24,
                "�ˎ��  Sagitarius",   11,     22,
                "�R�r��  Capricorn",    12,     22  };

static struct ZODIAC13  {
        char    *sign;
        int     mm;
        int     dd;
} z13[13] = {   "�R�r��  Capricorn",     1,     19,
                "���r��  Aquarius",      2,     16,
                "  ����  Pisces",        3,     11,
                "���r��  Aries",         4,     19,
                "������  Taurus",        5,     14,
                "�o�q��  Gemini",        6,     21,
                "  �I��  Cancer",        7,     20,
                "���q��  Leo",           8,     11,
                "������  Virgo",         9,     16,
                "�V����  Libra",        10,     30,
                "  嶍�  Scorpio",      11,     23,
                "�֌���  Ophiuchus",    11,     30,
                "�ˎ��  Sagitarius",   12,     18  };

static struct holiday {
        char    *name;  /* �j�Փ��� */
        int     mm;     /* ��       */
        int     dd;     /* ��       */
        int     s_yy;   /* �J�n�N   */
        int     e_yy;   /* �I���N   */
} h[] = {
        "�l���q(�V�N)",    1,    1,        0,   1945,
        "����",            1,    1,     1949,   MAXINT, /* ���a23�N����   */
        "���n��",          1,    3,     1928,   1945,
                                /* ����3�N�J�n, ����41�N����, ���a2�N���z */
        "�V�N����",        1,    5,     1872,   1945,
        "���l�̓�",        1,   15,     1949,   1999,   /* ���a23�N����   */
                              /* ���l�̓��͕���12�N���1����2���j���ƂȂ� */
        "�I����",          1,   29,     1873,   1873,   /* ����6�N�̂�    */
        "�F���V�c��",      1,   31,     1872,   1912,   /* �F���V�c����� */
        "�I����",          2,   11,     1874,   1945,   /* �_���V�c���ʓ� */
        "�����L�O�̓�",    2,   11,     1967,   MAXINT, /* ���a41�N����   */
        "�n�v��",          3,    6,     1827,   1945,   /* ���a�c�@�a���� */
    /*  "�t���̓�",        3,   21,        0,   MAXINT, */
        "�_���V�c��",      4,    3,     1872,   1945,   /* �_���V�c����� */
        "�V����",          4,   29,     1927,   1948,   /* ���a�V�c�a���� */
        "�V�c�a����",      4,   29,     1949,   1988,   /* ���a23�N����   */
        "�݂ǂ�̓�",      4,   29,     1989,   2006,   /* �������N����   */
        "���a�̓�",        4,   29,     2007,   MAXINT, /* ����17�N����   */
        "���@�L�O��",      5,    3,     1949,   MAXINT, /* ���a23�N����   */
        "�����̋x��",      5,    4,     1989,   2006,
        "�݂ǂ�̓�",      5,    4,     2007,   MAXINT, /* ����17�N����   */
        "���ǂ��̓�",      5,    5,     1949,   MAXINT, /* ���a23�N����   */
        "�n�v��",          5,   28,     1874,   1912,   /* �����c�@�a���� */
        "�n�v��",          6,   25,     1913,   1926,   /* �吳�c�@�a���� */
        "�C�̓�",          7,   20,     1996,   2002,
                             /* �C�̓��͕���15�N���7����3���j���ƂȂ�    */
        "�����V�c��",      7,   30,     1912,   1926,   /* �����V�c����� */
        "�V����",          8,   31,     1912,   1912,   /* �吳�V�c�a���� */
        "�Ƃ����̓�",    9,   15,     1954,   1963,
        "�V�l�̓�",        9,   15,     1964,   1965,
        "�h�V�̓�",        9,   15,     1966,   2002,
                             /* �h�V�̓��͕���15�N���9����3���j���ƂȂ�  */
    /*  "�H���̓�",        9,   23,        0,   MAXINT, */
        "�̈�̓�",       10,   10,     1966,   1999,
                             /* �̈�̓��͕���12�N���10����2���j���ƂȂ� */
        "�_����",         10,   17,     1879,   1944,
        "�V���ߏj��",     10,   31,     1913,   1926,   /* �吳2�N�`      */
        "�V����",         11,    3,     1873,   1911,   /* �����V�c�a���� */
                                        /* �������N�`5�N�͋����9��22��   */
        "������",         11,    3,     1927,   1945,   /* ���a2�N����    */
        "�����̓�",       11,    3,     1948,   MAXINT,
        "�V����",         11,   23,     1872,   1944,
                                        /* ����5�N�ȑO��11����2�̉K�̓�   */
        "�ΘJ���ӂ̓�",   11,   23,     1948,   MAXINT,
        "�V�c�a����",     12,   23,     1989,   MAXINT,
        "�吳�V�c�a����", 12,   25,     1927,   1944,   /* �吳�V�c����� */
        NULL,              0,    0,        0,   0       };

static struct holiday   hh[] = {
    "New Year's Day",                            1,      1,     0,    MAXINT,
    "quarter day [��]",                          1,      1,     0,    MAXINT,
    "12���ߑO���(Twelfth Night)",               1,      5,     0,    MAXINT,
    "������(Epiphany, Twelfth Day)",             1,      6,     0,    MAXINT,
    "Australia Day [NSW,ACT,Qld,NT Aust]",       1,     26,     0,    MAXINT,
    "���a���L�O�� [�C���h]",                     1,     26,     0,    MAXINT,
    "���C��(Candlemas)",                         2,      2,     0,    MAXINT,
    "Chandeleur (�N���[�v��H�ׂ��) [��]",      2,      2,     0,    MAXINT,
    "Ground Hog Day",                            2,      2,     0,    MAXINT,
    "�����J�[���a����",                          2,     12,     0,    MAXINT,
    "St. Valentine's Day",                       2,     14,     0,    MAXINT,
    "����̋V��",                              2,     15,     0,    MAXINT,
    "���V���g���a����",                          2,     22,     0,    MAXINT,
    "St. David's Day",                           3,      1,     0,    MAXINT,
    "St. Patrick's Day",                         3,     17,     0,    MAXINT,
    "�������̏j��(Lady Day)",                    3,     25,     0,    MAXINT,
    "�����(All Fools' Day)",                    4,      1,     0,    MAXINT,
    "quarter day [��]",                          4,      1,     0,    MAXINT,
    "St. George's Day",                          4,     23,     0,    MAXINT,
    "May Day",                                   5,      1,     0,    MAXINT,
    "��2�����E���x��L�O��[��]",               5,      8,  1945,    MAXINT,
    "��������L�O��(Flag Day)[��]",              6,     14,     0,    MAXINT,
    "����҃��n�l�̍Փ�(Midsummer Day)",         6,     24,     0,    MAXINT,
    "�����L�O��(Dominion Day)[�J�i�_]",          7,      1,     0,    MAXINT,
    "quarter day [��]",                          7,      1,     0,    MAXINT,
    "�A�����J�Ɨ��L�O��(Independence Day)",      7,      4,  1776,    MAXINT,
    "Bastille Day [��]",                         7,      4,     0,    MAXINT,
    "�v���L�O��[��]",                            7,     14,     0,    MAXINT,
    "���n��(Lammas)",                            8,      1,     0,    MAXINT,
    "�ϗe�̏j��(Transfiguration)",               8,      6,     0,    MAXINT,
    "����폸�V�̏j��(Assumption)",              8,     15,     0,    MAXINT,
    "����}���A�a����(Nativity)",                9,      8,     0,    MAXINT,
    "�~�J�G����(Michaelmas)",                    9,     29,     0,    MAXINT,
    "quarter day [��]",                         10,      1,     0,    MAXINT,
    "����L�O��[��]",                           10,      3,     0,    MAXINT,
    "Halloween",                                10,     31,     0,    MAXINT,
    "������(All Saints' Day)",                  11,      1,     0,    MAXINT,
    "�����(All Souls' Day)",                   11,      2,     0,    MAXINT,
    "Guy Fawkes Day",                           11,      5,     0,    MAXINT,
    "���}���^����(Martinmas)",                  11,     11,     0,    MAXINT,
#ifdef  OLDFASHIONED
    "Armistice Day",                            11,     11,     0,    MAXINT,
#else
    "Veterans Day",                             11,     11,     0,    MAXINT,
#endif
    "��1�����E���x��L�O��[��]",              11,     11,  1918,    MAXINT,
    "�����߉��ق̏j��(Immaculate Conception)",  12,      8,     0,    MAXINT,
    "�c��̓�(Forefathers' Day)",               12,     22,     0,    MAXINT,
    "Christmas Eve",                            12,     24,     0,    MAXINT,
    "Christmas",                                12,     25,     0,    MAXINT,
    "Boxing Day [England, Wales]",              12,     26,     0,    MAXINT,
    "�����d���}���҂̏j��(Innocents's Day)",    12,     28,     0,    MAXINT,
    "New Year's Eve",                           12,     31,     0,    MAXINT,
    "Hogmanay [Scotland]",                      12,     31,     0,    MAXINT,
    NULL,                                        0,      0,     0,         0  };

static int      kiddushHaHamah = 0;
static int      talUmatar      = 0;


#define septuagestima(y)        ( easterday    - 63 )
#define sexagesima(y)           ( easterday    - 56 )           /* @@ */
#define quinquagesima(y)        ( easterday    - 49 )
#define shroveSunday(y)         ( easterday    - 49 )           /* @@ */
#define shroveMonday(y)         ( easterday    - 48 )           /* @@ */
#define mardiGras(y)            ( easterday    - 47 )
#define shroveTuesday(y)        ( easterday    - 47 )           /* @@ */
#define ashWednesday(y)         ( easterday    - 46 )
#define quadragesima(y)         ( easterday    - 42 )
#define britishMothersDay(y)    ( easterday    - 21 )
#define passionSunday(y)        ( easterday    - 14 )
#define palmSunday(y)           ( easterday    -  7 )
#define holyThursday(y)         ( easterday    -  3 )
#define maundyThursday(y)       ( easterday    -  3 )           /* @@ */
#define goodFriday(y)           ( easterday    -  2 )
#define holySaturday(y)         ( easterday    -  1 )
#define easterMonday(y)         ( easterday    +  1 )
#define lowSunday(y)            ( easterday    +  7 )
#define rogationSunay(y)        ( easterday    + 35 )           /* @@ */
#define rogationDay(y)          ( easterday    + 36 )
#define ascensionDay(y)         ( easterday    + 39 )
#define whitsunday(y)           ( easterday    + 49 )
#define pentecost(y)            ( easterday    + 49 )
#define whitmonday(y)           ( easterday    + 50 )
#define trinity(y)              ( easterday    + 56 )
#define corpusChristiDay(y)     ( easterday    + 60 )

#define erevRoshHaShanah(y)     ( roshHaShanah -  1 )           /* @@ */
#define roshHaShanah2(y)        ( roshHaShanah +  1 )           /* @@ */
#define tzomGedaliah(y)         ( (roshHaShanah % 7) == 4   \
                                         ? roshHaShanah + 3 \
                                         : roshHaShanah + 2   ) /* @@ */
#define erevYomKippur(y)        ( roshHaShanah +  8 )           /* @@ */
#define erevSukkot(y)           ( roshHaShanah + 13 )           /* @@ */
#define sukkot(y)               ( roshHaShanah + 14 )           /* @@ */
#define sukkot2(y)              ( roshHaShanah + 15 )           /* @@ */
#define holHamoedSukkot(y)      ( roshHaShanah + 16 )           /* @@ */
#define holHamoedSukkot2(y)     ( roshHaShanah + 17 )           /* @@ */
#define holHamoedSukkot3(y)     ( roshHaShanah + 18 )           /* @@ */
#define holHamoedSukkot4(y)     ( roshHaShanah + 19 )           /* @@ */
#define hoshannahRabbah(y)      ( roshHaShanah + 20 )           /* @@ */
#define sheminiAtzeret(y)       ( roshHaShanah + 21 )           /* @@ */
#define simchatTorah(y)         ( roshHaShanah + 22 )           /* @@ */
#define erevPassover(y)         ( passoverday  - 1 )            /* @@ */
#define yomHaShoah(y)           ( passoverday  + 12 )           /* @@ */
#define lagBaOmer(y)            ( passoverday  + 33 )           /* @@ */
#define yomYerushalim(y)        ( passoverday  + 43 )           /* @@ */
#define erevShavuot(y)          ( passoverday  + 49 )           /* @@ */
#define shavuot(y)              ( passoverday  + 50 )           /* @@ */
#define hebrewPentecost(y)      ( passoverday  + 51 )
#define shavuot2(y)             ( passoverday  + 51 )           /* @@ */

#define KINOE           0
#define KINOTO          1
#define HINOE           2
#define HINOTO          3
#define TSUCHINOE       4
#define TSUCHINOTO      5
#define KANOE           6
#define KANOTO          7
#define MIZUNOE         8
#define MIZUNOTO        9

#define NEE             0
#define USHI            1
#define TORA            2
#define UU              3
#define TATSU           4
#define MEE             5
#define UMA             6
#define HITSUJI         7
#define SARU            8
#define TORI            9
#define IMU             10
#define WII             11

#define setsubun(y)             ( risshunday  -   1 )
#define hachijuHachiYa(y)       ( risshunday  +  87 )
#define nihyakuTohKa(y)         ( risshunday  + 209 )
#define nihyakuHatsuKa(y)       ( risshunday  + 219 )
#define higanInSpring(y)        ( shunbunday  -   3 )
#define higanInAutumn(y)        ( shuubunday  -   3 )

#define kan(g)                  ( ( (g) + 4 ) %  10 )
#define shi(g)                  ( ( (g) + 2 ) %  12 )

char    *
zodiac( long g, int year )
{
    register int    i;

    for ( i = 0; i < 12; i++ ) {
        if ( g < absoluteFromGregorian( z[i].dd, z[i].mm, year ) )
            break;
    }

    return ( z[( --i + 12) % 12 ].sign );
}

char    *
zodiac13( long g, int year )
{
    register int    i;

    for ( i = 0; i < 13; i++ ) {
        if ( g < absoluteFromGregorian( z13[i].dd, z13[i].mm, year ) )
            break;
    }

    return ( z13[( --i + 13) % 13 ].sign );
}


long
seijinNoHi( int year )
{
    return ( NthKday( SECOND, MONDAY, JANUARY, year ) );
                                                /* 2nd Monday in January */
}


long
KingsBirthday( int year )
{
    return ( NthKday( THIRD, MONDAY, JANUARY, year ) );
                                                /* 3rd Monday in January */
}


long
waitangiDay( int year )
{
    return ( NthKday( FIRST, SUNDAY, FEBRUARY, year ) );
                                                /* 1st Sunday in February */
}


long
australiaDay( int year )
{
    return ( NthKday( FIRST, MONDAY, FEBRUARY, year ) );
                                                /* 1st Monday in February */
}


long
WashingtonBirthday( int year )
{
    return ( NthKday( THIRD, MONDAY, FEBRUARY, year ) );
                                                /* 3rd Monday in February */
}

long
russianDay( int dd, int mm, int yy )
{
    if ( yy > 1990 )
        return ( absoluteFromGregorian( 12, JUNE, yy ) );
    else
        return ( -1 );
}


long
mothersDay( int year )
{
    return ( NthKday( SECOND, SUNDAY, MAY, year ) );
                                                /* 2nd Sunday in May */
}


long
fathersDay( int year )
{
    return ( NthKday( THIRD, SUNDAY, JUNE, year ) );
                                                /* 3rd Sunday in June */
}


long
umiNoHi( int year )
{
    return ( NthKday( THIRD, MONDAY, JULY, year ) );
                                                /* 3rd Monday in July */
}


long
keirouNoHi( int year )
{
    return ( NthKday( THIRD, MONDAY, SEPTEMBER, year ) );
                                                /* 3rd Monday in September */
}


long
taiikuNoHi( int year )
{
    return ( NthKday( SECOND, MONDAY, OCTOBER, year ) );
                                                /* 2nd Monday in October */
}

long
magoNoHi( int year )
{
    return ( NthKday( THIRD, SUNDAY, OCTOBER, year ) );
                                                /* 3rd Sunday in October */
}


#if     0
dateList        *
secretarysDay( int year )
{
    static dateList dates;
    int             i, day, month;
    long            g1, g2, *p = dates;

    for ( i = 0; i < MAXLIST; i++ )
        dates[ i ] = 0;
    for ( month = JANUARY, i = 0; month <= DECEMBER; month++ ) {
        day = lastDayOfGregorianMonth( month, year );
        g1  = absoluteFromGregorian( day, month, year );
        g2  = NthKday( LAST, SATURDAY, month, year );
                                        /* last Saturday in month */
        if ( g1 == g2 )
            dates[ i++ ] = g1 - 3;
                                        /* last Wednesday in month */
    }

    return ( ( dateList *)p );
}
#endif


void
checkDateList( long g, const long *dates, const char *s )
{
    while ( *dates ) {
        if ( g == *dates++ ) {
            printf( "  %s", s );
            break;
        }
    }
}


void
checkJapanese( long g, int dd, int mm, int yy, int htmlMode )
{
    register int    i     = 0;
    int             reset = 1;
    int             tsuki;
    long            fushi;
    char            *p;

    tprintf( htmlMode, &reset, "  %s", kyusei( g ) );
    tprintf( htmlMode, &reset, "  %s", nijuhachishuku( g ) );
    tprintf( htmlMode, &reset, "  %s",
	     junichoku( g, dd, mm, yy, &tsuki, &fushi ) );
    if ( ( p = sanrinbou( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = manbaibi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = kurobi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = jisshinichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = kikonichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = fukunichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = chiImiNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = tenKaNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = jiKaNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = ouMouNichi( g, tsuki, fushi ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = boSouNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );
    if ( ( p = tsukiTokuNichi( g, tsuki ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );

    if ( ( mm == FEBRUARY ) || ( mm == MARCH )     ||
         ( mm == MAY )      || ( mm == SEPTEMBER )    )
        risshunday = springStartDay( yy );
    if ( mm == MARCH )
        shunbunday = midSpringDay( yy );
    if ( ( mm == JUNE ) || ( mm == JULY ) || ( mm == AUGUST ) ) {
        geshiday   = midSummerDay( yy );
        risshuuday = autumnStartDay( yy );
    }
    if ( mm == SEPTEMBER )
        shuubunday = midAutumnDay( yy );

    checkTenShaNichi( g, mm, yy, htmlMode, &reset );

    if ( mm == JANUARY ) {
        long    shouKanDay = sekkiDay( SK24_SHOUKAN, yy );

        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  �`�F�R���a���Ɨ��L�O��" );
        if ( (dd == 2) && (g % 7 == MONDAY) )
            tprintf( htmlMode, &reset, "  New Year's Day [�p]" );
        if ( yy >= 1874 ) {
            if ( ((dd == 4) && (g % 7 != SATURDAY) && (g % 7 != SUNDAY)) ||
                 ((dd == 5) && (g % 7 == MONDAY))                        ||
                 ((dd == 6) && (g % 7 == MONDAY))                           )
                tprintf( htmlMode, &reset, "  ������p�n��" );
        }
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  �l��" );
            tprintf( htmlMode, &reset, "  ����" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  ���J��" );
        if ( yy >= 2000 ) {     /* ����12�N���� */
            if ( g == seijinNoHi( yy ) )
                tprintf( htmlMode, &reset, "  ���l�̓�" );
        }
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  �U���W�o���v���L�O��(�^���U�j�A)" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  ������" );
        if ( g == shouKanDay )
            tprintf( htmlMode, &reset, "  ����" );
        else if ( g == shouKanDay + 4 )
            tprintf( htmlMode, &reset, "  ���l�Y" );
        else if ( g == shouKanDay + 9 )
            tprintf( htmlMode, &reset, "  ����" );
        else if ( g == sekkiDay( SK24_DAIKAN, yy ) )
            tprintf( htmlMode, &reset, "  �劦" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  �T���p�E���s�n���L�O��" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  ���a���L�O��(�C���h)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  �����L�O��(�I�[�X�g�����A)" );
    }
    if ( mm == FEBRUARY ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  ��s�����(�}���[�V�A)" );
        if ( (dd == 2) && (yy >= 2007) ) 
            tprintf( htmlMode, &reset, "  ���Z�L�����e�B�̓�" );
        if ( g == setsubun( yy ) )
            tprintf( htmlMode, &reset, "  �ߕ�" );
        else if ( g == risshunday )
            tprintf( htmlMode, &reset, "  ���t" );
        else if ( g == sekkiDay( SK24_USUI, yy ) )
            tprintf( htmlMode, &reset, "  �J��" );
        if ( shi( g ) == UMA ) {
            if ( g <= absoluteFromGregorian( 12, 2, yy ) )
                tprintf( htmlMode, &reset, "  ����" );
            else if ( g <= absoluteFromGregorian( 24, 2, yy ) )
                tprintf( htmlMode, &reset, "  ��̌�" );
        }
        if ( (((dd >= 6)  && (dd <= 11))   ||
              ((dd == 5)  && (yy >= 2002)) ||
              ((dd == 12) && (g % 7 == MONDAY) && (yy >= 1973))) &&
             (yy >= 1950) ) {
            tprintf( htmlMode, &reset, "  ��%d�񂳂��ۂ��Ղ�", yy - 1949 );
                /* �ʏ�� 2��6������11���܂ł��u��Ղ�v�����A12��  */
                /* ���U�֋x���ɂȂ����ꍇ�́A12���܂ł��u��Ղ�v�� */
                /* ���ԂƂȂ�                                       */
                /* �ǋL: ��53��(2002�N)����2��5���J�n�ɂȂ���       */
        }
        if ( dd ==  5 )
            tprintf( htmlMode, &reset, "  ���@�L�O��(���L�V�R)" );
        if ( dd ==  7 )
            tprintf( htmlMode, &reset, "  �k���̓y�̓�" );
        if ( dd ==  8 )
            tprintf( htmlMode, &reset, "  �j���{" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  �o�����^�C���f�[" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  �������a����(�k���N)" );
        if ( yy >= 1998 ) {     /* ����10�N���� */
            if ( dd == 20 )
                tprintf( htmlMode, &reset, "  �����̓�" );
        }
        if ( dd == 21 )
            tprintf( htmlMode, &reset,
                     "  �x���K���ꍑ�ꉻ�^���L�O��(�o���O���f�B�b�V��)" );
        if ( yy >= 1989 ) {     /* �������N���� */
            if ( dd == 23 )
                tprintf( htmlMode, &reset, "  �c���q�a����" );
        }
        if ( dd == 23 )
            tprintf( htmlMode, &reset, "  �c���h�q�҂̓�(���V�A)" );
        if ( ( yy == 1989 ) && ( dd == 24 ) )
            tprintf( htmlMode, &reset, "  ��r�̗�(���a�V�c)" );
        if ( ( yy > 1996 ) && ( dd == 27 ) )
            tprintf( htmlMode, &reset,
                     "  �|�P�b�g�����X�^�[%d���N", yy - 1996 );
        if ( dd == 28 ) {
            tprintf( htmlMode, &reset, "  �r�X�P�b�g�̓�" );
            tprintf( htmlMode, &reset, "  �a���L�O��(��p)" );
        }
    }
    if ( mm == MARCH ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  �Ɨ��^���L�O��(�؍�)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  �e�L�T�X�Ɨ��L�O��" );
        if ( dd == 3 ) {
            tprintf( htmlMode, &reset, "  �㖤�̐ߋ�(�ЂȍՂ�)" );
            if ( yy >= 1955 )
                tprintf( htmlMode, &reset, "  ��%d�񎨂̓�", yy - 1954 );
        }
        if ( dd == 4 )
            tprintf( htmlMode, &reset, " �������x�̓�(�p�i�})" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  ���ەw����(����)" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  �z���C�g�f�[" );
        if ( dd == 15 )
            if ( yy >= 1849 )
                tprintf( htmlMode, &reset, "  1848�N�v���L�O��(�n���K���[)" );
        if ( g == shunbunday ) {
            tprintf( htmlMode, &reset, "  �t��" );
            if ( yy >= 1878 ) {
                if ( yy <= 1945 )
                    tprintf( htmlMode, &reset, "  �t�G�c���" );
                else
                    tprintf( htmlMode, &reset, "  �t���̓�" );
            }
        }
        else if ( g == sekkiDay( SK24_KEICHITSU, yy ) )
            tprintf( htmlMode, &reset, "  �[�" );
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shunbunday ) < 5 ) ||
               ( shunbunday - g == 5 )          )    ) 
            tprintf( htmlMode, &reset, "  �Г�" );
        if ( dd == 21 ) {
            tprintf( htmlMode, &reset, "  �x�j�[�g�t�A���X�a����(���L�V�R)" );
            tprintf( htmlMode, &reset, "  �l���L�O��(��A�t���J)" );
        }
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�M���V�A)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�o���O���f�B�b�V��)" );
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  �v�����L�O��(��p)" );
    }

    if ( g - shunbunday == 15 )
        tprintf( htmlMode, &reset, "  ������(����)" );

    if ( mm == APRIL ) {
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  ���ۂ��ǂ��̖{�̓�" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  �A�؂̓�(�؍�)" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, "  ���E�ی��f�[" );
        if ( dd == 8 ) {
            tprintf( htmlMode, &reset, "  ������" );
            tprintf( htmlMode, &reset, "  �Ԃ܂�" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  �푈�L�O��(�t�B���s��)" );
        if ( ( yy == 1959 ) && ( dd == 10 ) )
            tprintf( htmlMode, &reset, "  �����̋V(���m�e��)" );
        if ( dd == 15 )
            tprintf( htmlMode, &reset, "  �������a����(�k���N)" );
        if ( dd == 18 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�W���o�u�G)" );
        if ( dd == 19 )
            tprintf( htmlMode, &reset, "  �Ɨ��錾�L�O��(�x�l�Y�G��)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  ���M�L�O��" );
        if ( dd == 21 ) {
            tprintf( htmlMode, &reset, "  �����̓�" );
            tprintf( htmlMode, &reset, "  �Ƒ��̓�(��A�t���J)" );
        }
        if ( dd == 23 ) {
            tprintf( htmlMode, &reset, "  ���E�{�̓�" );
            if ( yy > 1920 )
                tprintf( htmlMode, &reset, "  �����匠�Ǝq���̓�(�g���R)" );
        }
        if ( dd == 25 ) {
            tprintf( htmlMode, &reset, "  �A���U�b�N�E�f�[" );
            tprintf( htmlMode, &reset, "  ����L�O��(�C�^���A)" );
            tprintf( htmlMode, &reset, "  �v���L�O��(�|���g�K��)" );
            tprintf( htmlMode, &reset, "  �V�i�C�ԊҋL�O��(�G�W�v�g)" );
            tprintf( htmlMode, &reset, "  �l���R�n�݋L�O��(�k���N)" );
        }
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  �A���L�O��(�^���U�j�A)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  ���R�̓�(��A�t���J)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  �암��v�ҋL�O��(�A�����J�암)" );
        /* �鏑�̓�
         *  4���̈�ԍŌ�� 7���ԑ������T�̐��j��
         *  (�܂�A�ŏI�y�j�� 3���O)
         */
        if ( (yy >= 1952) && (g == secretarysDay( yy )) )
            tprintf( htmlMode, &reset, "  �鏑�̓�" );
        if ( g == sekkiDay( SK24_SEIMEI, yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        else if ( g == sekkiDay( SK24_KOKUU, yy ) )
            tprintf( htmlMode, &reset, "  ���J" );
        if ( g == NthKday( LAST, WEDNESDAY, APRIL, yy ) )
            tprintf( htmlMode, &reset, "  ���ۖӓ����̓�" );
        if ( (yy >= 1976) && (dd == 30) )
            tprintf( htmlMode, &reset, "  �암�x�g�i���J���L�O��(�x�g�i��)" );

        if ( (yy == 1949) && (g == NthKday( FIRST, SATURDAY, APRIL, yy ) + 1) )
            tprintf( htmlMode, &reset, "  �T���}�[�^�C���J�n" );
    }
    if ( mm == MAY ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  ���ۘJ����(����)" );
        if ( dd == 2 ) {
            tprintf( htmlMode, &reset, "  �����̋x��(�|�[�����h)" );
            tprintf( htmlMode, &reset, "  ��҂̓�(���[�}�j�A)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset, "  ���@�L�O��(�|�[�����h)" );
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  �����N��(����)" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  �[�߂̐ߋ�" );
            tprintf( htmlMode, &reset, "  �������ʋL�O��(�^�C)" );
            tprintf( htmlMode, &reset, "  ����L�O��(�I�����_)" );
        }
        if ( g == hachijuHachiYa( yy ) )
            tprintf( htmlMode, &reset, "  ���\����" );
        if ( dd == 8 ) {
            tprintf( htmlMode, &reset, "  ���E�ԏ\���f�[" );
            tprintf( htmlMode, &reset, "  ����L�O��(�`�F�R)" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  �폟�L�O��(���V�A)" );
        if ( g == mothersDay( yy ) )
            tprintf( htmlMode, &reset, "  ��̓�" );
        if ( g == summerStartDay( yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        else if ( g == sekkiDay( SK24_SHOUMAN, yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  ���e�̓�(�؍�)" );
        if ( dd == 17 )
            tprintf( htmlMode, &reset, "  ���@�L�O��(�m���E�F�[)" );
        if ( dd == 19 ) {
            tprintf( htmlMode, &reset, "  �r�N�g���A�����a����" );
            tprintf( htmlMode, &reset, "  �N�ƃX�|�[�c�̓�(�g���R)" );
        }
        if ( dd == 21 )
            tprintf( htmlMode, &reset, "  �C�L�P�C��L�O��(�`��)" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  5���v���L�O��(�A���[���`��)" );
        if ( (dd == 25) || (dd == 26) )
            tprintf( htmlMode, &reset, "  �A�t���J�f�[(�W���o�u�G)" );
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  ���剻�L�O��(�i�C�W�F���A)" );

        if ( ((yy == 1948) || (yy == 1950) && (yy == 1951)) &&
             (g == NthKday( FIRST, SATURDAY, MAY, yy ) + 1)    ) 
            tprintf( htmlMode, &reset, "  �T���}�[�^�C���J�n" );
    }
    if ( mm == JUNE ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  ���ێ�����(����)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  ���a���L�O��(�C�^���A)" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  ���E���f�[" );
            tprintf( htmlMode, &reset, "  ���@�L�O��(�f���}�[�N)" );
        }
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  ������(�؍�)" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, "  �����a���L�O��(�}���[�V�A)" );
        if ( ( yy == 1993 ) && ( dd == 9 ) )
            tprintf( htmlMode, &reset, "  �����̋V(���m�e��)" );
        if ( dd == 12 ) {
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�t�B���s��)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(���V�A)" );
        }
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  �����̓�(�A���[���`��)" );
            tprintf( htmlMode, &reset, "  �N�̓�(��A�t���J)" );
        }
        if ( g == fathersDay( yy ) )
            tprintf( htmlMode, &reset, "  ���̓�" );
        if ( (yy >= 2000) &&
             ( g == NthKday( FIRST, MONDAY, JUNE, yy ) ) )
            tprintf( htmlMode, &reset, "  ��Ȃ̓�" );
                                        /* 6���̑�1���j�� (2000�N�`) */
        if ( (yy >= 2000) && (dd == 26) ) {
            tprintf( htmlMode, &reset, "  ���ۖ��򗐗p�o�Ńf�[" );
        }
        if ( g == sekkiDay( SK24_BOUSHU, yy ) )
            tprintf( htmlMode, &reset, "  䊎�" );
        else if ( g == geshiday )
            tprintf( htmlMode, &reset, "  �Ď�" );
        if ( dd == 24 ) {
            tprintf( htmlMode, &reset, "  ���o�v�e�B�X�g�L�O��(�P�x�b�N�B)" );
            tprintf( htmlMode, &reset, "  �J���{�{�폟�L�O��(�x�l�Y�G��)" );
        }
        if ( dd == 29 )
            tprintf( htmlMode, &reset, "  ���y�h���Ɛ��p�u���̓�(�y���[)" );
        if ( (dd == 20) && (yy == 2005) )
            tprintf( htmlMode, &reset, "  �k�C���T�}�[�^�C���J�n" );
        if ( (dd == 21) && (yy == 2006) )
            tprintf( htmlMode, &reset, "  �k�C���T�}�[�^�C���J�n" );
    }
    if ( mm == JULY ) {
        if ( (dd == 1) && (yy == 2004) )
            tprintf( htmlMode, &reset, "  �k�C���T�}�[�^�C���J�n" );
        if ( dd == 1 ) {
            if ( yy >= 2000 )
                tprintf( htmlMode, &reset, "  ���ʍs����ݗ��L�O��(���`)" );
            tprintf( htmlMode, &reset, "  �����L�O��(�J�i�_)" );
        }
        if ( g == NthKday( FIRST, SATURDAY, JULY, yy ) )
            tprintf( htmlMode, &reset, "  �ΘJ���N�̓�" );
        if ( dd == 5 ) {
            tprintf( htmlMode, &reset, "  ���E�җ��K�̓�(�`�F�R)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�x�l�Y�G��)" );
        }
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  �����E�t�X�̓�(�`�F�R)" );
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  ���[" );
            tprintf( htmlMode, &reset, "  �T�o�E�T�o�f�B(�^���U�j�A)" );
        }
        if ( dd == 9 ) {
            tprintf( htmlMode, &reset, "  �T���p�E���B�v���L�O��" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�A���[���`��)" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  �t���}���ꌗ�����̏j��(�x���M�[)" );
        if ( dd == 13 )
            tprintf( htmlMode, &reset, "  �~�}����" );
        if ( dd == 15 )
            tprintf( htmlMode, &reset, "  �~" );
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  �~�����" );
            tprintf( htmlMode, &reset, "  ������" );
        }
        if ( dd == 17 )
            tprintf( htmlMode, &reset, "  ���@�L�O��(�؍�)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�R�����r�A)" );
        if ( dd == 21 )
            tprintf( htmlMode, &reset, "  �C�̓�(�P�j�A)" );
        if ( dd == 23 )
            tprintf( htmlMode, &reset, "  �v���L�O��(�G�W�v�g)" );
        if ( dd == 24 ) {
            tprintf( htmlMode, &reset, "  �n���~" );
            tprintf( htmlMode, &reset, "  �{���o�����a�L�O��(�x�l�Y�G��)" );
        }
        if ( yy >= 2003 ) {     /* ����15�N���� */
            if ( g == umiNoHi( yy ) )
                tprintf( htmlMode, &reset, "  �C�̓�" );
        }
        if ( (yy >= 1932) && (g == NthKday( THIRD, SATURDAY, JULY, yy )) )
            tprintf( htmlMode, &reset, "  �����g���̍��ۃf�[" );
        if ( g == sekkiDay( SK24_SHOUSHO, yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        else if ( g == sekkiDay( SK24_TAISHO, yy ) )
            tprintf( htmlMode, &reset, "  �友" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  �j�R���n�敹���̓�(�R�X�^���J)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  ���ۖ��򗐗p�o�Ńf�[" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  �폟�L�O��(�k���N)" );
        if ( (dd == 28) || (dd == 29) )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�y���[)" );
        if ( (dd == 31) && ((yy == 2004) || (yy == 2005)) )
            tprintf( htmlMode, &reset, "  �k�C���T�}�[�^�C���I��" );
    }
    if ( ( mm == JULY ) || ( mm == AUGUST ) ) {
        if ( kan( g ) == KANOE ) {
            if ( ( g >= geshiday + 20 ) && ( g < geshiday + 30 ) )
                tprintf( htmlMode, &reset, "  ����" );
            if ( ( g >= geshiday + 30 ) && ( g < geshiday + 40 ) )
                tprintf( htmlMode, &reset, "  ����" );
            if ( ( g >= risshuuday ) && ( g < risshuuday + 10 ) )
                tprintf( htmlMode, &reset, "  ����" );
        }
    }

    if ( mm == AUGUST ) {
        if ( dd == 1 ) {
            tprintf( htmlMode, &reset, "  ����" );
            tprintf( htmlMode, &reset, "  ���R��(����)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�X�C�X)" );
        }
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  �s���̓�(�J�i�_)" );
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  �A�u�_�r�񒷏A�C�L�O��(UAE)" );
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  �{���J�폟�L�O��(�R�����r�A)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�R�[�g�W�{�A�[��)" );
        }
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  �_����(�^���U�j�A)" );
        if ( dd == 9 ) {
            if ( yy >= 1946 )
                tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�V���K�|�[��)" );
            tprintf( htmlMode, &reset, "  �S���w�l�̓�(��A�t���J)" );
        }
        if ( dd == 11 )
            tprintf( htmlMode, &reset, "  �Ɨ���m�L�O��(�W���o�u�G)" );
        if ( dd == 12 ) {
            tprintf( htmlMode, &reset, "  ���ܒa����(�^�C)" );
            tprintf( htmlMode, &reset, "  ���R�L�O��(�W���o�u�G)" );
        }
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  ���x��~" );
            if ( yy >= 1946 )
                tprintf( htmlMode, &reset, "  ������(�؍�)" );
            tprintf( htmlMode, &reset, "  �p�i�}�s�n���L�O��" );
        }
        if ( dd == 18 )
            tprintf( htmlMode, &reset,
                     "  �T���}���e�B�����R�����̓�(�A���[���`��)" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset,
                     "  ���C�V���g�o�[���̓�/���@�L�O��(�n���K���[)" );
        if ( g == risshuuday )
            tprintf( htmlMode, &reset, "  ���H" );
        else if ( g == sekkiDay( SK24_SHOSHO, yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        if ( yy == 2003 ) {
            if ( (dd >= 22) && (dd <= 31) ) {
                tprintf( htmlMode, &reset, "  �}�[�Y�E�B�[�N" );
                if ( dd == 27 )
                    tprintf( htmlMode, &reset, "  �ΐ�����ڋ�" );
            }
        }
        if ( dd == 30 ) {
            tprintf( htmlMode, &reset, "  �T���^�E���T�̓�(�y���[)" );
            if ( yy > 1922 )
                tprintf( htmlMode, &reset, "  �폟�L�O��(�g���R)" );
        }
        if ( dd == 31 ) {
            tprintf( htmlMode, &reset, "  �p�Y�L�O��(�t�B���s��)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�}���[�V�A)" );
        }
        if ( (dd == 11) && (yy == 2006) )
            tprintf( htmlMode, &reset, "  �k�C���T�}�[�^�C���I��" );
    }
    if ( mm == SEPTEMBER ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  �ΘJ���ӂ̓�(�J�i�_)" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  ���c��(�x�g�i��)" );
        if ( g == nihyakuTohKa( yy ) )
            tprintf( htmlMode, &reset, "  ��S�\��" );
        if ( g == nihyakuHatsuKa( yy ) )
            tprintf( htmlMode, &reset, "  ��S��\��" );
        if ( dd == 7 )
            tprintf( htmlMode, &reset, " �Ɨ��L�O��(�u���W��)" );
        if ( dd == 9 ) {
            tprintf( htmlMode, &reset, "  �e�̐ߋ�(�d�z)" );
            tprintf( htmlMode, &reset, "  �����L�O��(�k���N)" );
        }
        if ( g == sekkiDay( SK24_HAKURO, yy ) )
            tprintf( htmlMode, &reset, "  ���I" );
        else if ( g == shuubunday ) {
            tprintf( htmlMode, &reset, "  �H��" );
            if ( yy >= 1878 ) {
                if ( yy < 1945 )
                    tprintf( htmlMode, &reset, "  �H�G�c���" );
                else
                    tprintf( htmlMode, &reset, "  �H���̓�" );
            }
        }
        if ( ( kan( g ) == TSUCHINOE )            &&
             ( ( abs( g - shuubunday ) < 5 ) ||
               ( shuubunday - g == 5 )          )    ) 
            tprintf( htmlMode, &reset, "  �Г�" );
        if ( yy >= 2003 ) {     /* ����15�N���� */
            if ( dd == 15 )
                tprintf( htmlMode, &reset, "  �V�l�̓�" ); /* ���� */
            if ( g == keirouNoHi( yy ) )
                tprintf( htmlMode, &reset, "  �h�V�̓�" ); /* �j�� */
            else if ( (g == keirouNoHi( yy ) + 1) &&
                      (g == shuubunday - 1)       &&
                      (g % 7 == TUESDAY)             ) {
                tprintf( htmlMode, &reset, "  �����̋x��" );
                    /* �O�����u�h�V�̓��v�ŗ������u�H���̓��v */
                    /* �̏ꍇ�A���̓��́u�����̋x���v�ƂȂ�   */
                    /* (2003�N�ȍ~)                           */
            }
        }
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�R�X�^���J)" );
            tprintf( htmlMode, &reset, "  �h�V�̓�(�P�j�A)" );
        }
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(���L�V�R)" );
        if ( dd == 18 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�`��)" );
        if ( dd == 19 )
            tprintf( htmlMode, &reset, "  ���R�L�O��(�`��)" );
        if ( dd == 24 )
            tprintf( htmlMode, &reset, "  ������Y�L�O��(��A�t���J)" );
        if ( dd == 27 )
            tprintf( htmlMode, &reset, "  �t���}���ꌗ�����̏j��(�x���M�[)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  �`�F�R���Ƃ̓�" );

        if ( ((yy >= 1949) && (yy <= 1951)) &&
             (g == NthKday( SECOND, SATURDAY, SEPTEMBER, yy )) )
            tprintf( htmlMode, &reset, "  �T���}�[�^�C���I��" );
    }
    if ( mm == OCTOBER ) {
        if ( dd == 1 ) {
            tprintf( htmlMode, &reset, "  �������" );
            tprintf( htmlMode, &reset, "  ���c��(����)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�i�C�W�F���A)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset, "  �J�V��(�؍�)" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  ���a���L�O��(�|���g�K��)" );
        if ( dd == 6 )
            tprintf( htmlMode, &reset, "  �폟�L�O��(�G�W�v�g)" );
        if ( dd == 8 )
            tprintf( htmlMode, &reset, "  �A���K���X�C��L�O��(�y���[)" );
        if ( dd == 10 ) {
            tprintf( htmlMode, &reset, "  ���c��(��p)" );
            tprintf( htmlMode, &reset, "  ���C�E�f�[(�P�j�A)" );
            tprintf( htmlMode, &reset, "  ���N�J���}�����L�O��(�k���N)" );
        }
        if ( dd == 12 ) {
            if ( g % 7 != SUNDAY )
                tprintf( htmlMode, &reset, "  ���Əj��(�X�y�C��)" );
            tprintf( htmlMode, &reset, "  ����̓�(�u���W��)" );
            tprintf( htmlMode, &reset, "  �����̓�(�A���[���`��)" );
            tprintf( htmlMode, &reset, "  ������(�`��)" );
            tprintf( htmlMode, &reset,
                     "  �A�����J�嗤�����L�O��(�x�l�Y�G��)" );
            tprintf( htmlMode, &reset, "  �񕶖��o��̓�(�R�X�^���J)" );
        }
        if ( dd == 13 )
            tprintf( htmlMode, &reset, "  ���Ӎ�(�J�i�_)" );
        if ( dd == 14 )
            tprintf( htmlMode, &reset, "  �j�G�����L�O��(�^���U�j�A)" );
        if ( dd == 16 )
            tprintf( htmlMode, &reset, "  �{�X�̓�" );
        if ( yy >= 1999 ) {     /* ����11�N���� */
            if ( g == magoNoHi( yy ) )
                tprintf( htmlMode, &reset, "  ���̓�" );
        }
        if ( g == magoNoHi( yy ) )
            tprintf( htmlMode, &reset, "  �h�V�̓�(����)" );
        if ( yy >= 2000 ) {     /* ����12�N���� */
            if ( g == taiikuNoHi( yy ) )
                tprintf( htmlMode, &reset, "  �̈�̓�" );
        }
        if ( g == sekkiDay( SK24_KANRO, yy ) )
            tprintf( htmlMode, &reset, "  ���I" );
        else if ( g == sekkiDay( SK24_SOUKOU, yy ) )
            tprintf( htmlMode, &reset, "  ���~" );
        if ( (yy >= 1990) && (g == NthKday( SECOND, WEDNESDAY, OCTOBER, yy )) )
            tprintf( htmlMode, &reset, "  ���ۖh�Ђ̓�" );
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  �P�j���b�^�E�f�[(�P�j�A)" );
        if ( dd == 23 ) {
            tprintf( htmlMode, &reset, "  �`���������R���剤��(�^�C)" );
            tprintf( htmlMode, &reset, "  �n���K���[�I�N�L�O��" );
        }
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  ��p������" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  �����L�O��(�I�[�X�g���A)" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  �`�F�R�X���o�L�A�Ɨ��L�O��" );
        if ( dd == 29 )
            if ( yy > 1923 )
                tprintf( htmlMode, &reset, "  ���a���錾�L�O��(�g���R)" );
        if ( dd == 31 )
            tprintf( htmlMode, &reset, "  �摍���ӌ��L�O��(��p)" );
    }
    if ( mm == NOVEMBER ) {
        if ( dd == 7 ) {
            tprintf( htmlMode, &reset, "  �\�A�v���L�O��" );
            tprintf( htmlMode, &reset, "  ���ӂƘa���̓�(���V�A)" );
        }
        if ( dd == 3 )
            tprintf( htmlMode, &reset,
                     "  �R�����r�A����̓Ɨ��L�O��(�p�i�})" );
        if ( dd == 4 )
            tprintf( htmlMode, &reset, "  �����̓�(�p�i�})" );
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  ���C�̓�" );
        if ( dd == 10 )
            tprintf( htmlMode, &reset,
                     "  �X�y�C������̓Ɨ��錾�̓�(�p�i�})" );
        if ( dd == 11 ) {
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�|�[�����h)" );
            tprintf( htmlMode, &reset, "  �푈�L�O��(�J�i�_)" );
        }
        if ( ( yy == 1990 ) && ( dd == 12 ) )
            tprintf( htmlMode, &reset, "  ���ʗ琳�a�̋V" );
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  �����a�C�L�O��(��p)" );
        if ( dd == 15 ) {
            tprintf( htmlMode, &reset, "  �h�C�c�ꌗ�����̏j��(�x���M�[)" );
            tprintf( htmlMode, &reset, "  ���a���錾�L�O��(�u���W��)" );
            tprintf( htmlMode, &reset, "  ���a�̓�(�R�[�g�W�{���[��)" );
        }
        if ( dd == 17 ) {
            tprintf( htmlMode, &reset, "  ���R�E�����`�����L�O��(�`�F�R)" );
            tprintf( htmlMode, &reset, "  �J���^�w�[�i�Ɨ��L�O��(�R�����r�A)" );
        }
        if ( dd == 20 )
            tprintf( htmlMode, &reset, "  �v���L�O��(���L�V�R)" );
        if ( g == winterStartDay( yy ) )
            tprintf( htmlMode, &reset, "  ���~" );
        else if ( g == sekkiDay( SK24_SHOUSETSU, yy ) )
            tprintf( htmlMode, &reset, "  ����" );
        if ( g == NthKday( THIRD, THURSDAY, NOVEMBER, yy ) )
            tprintf( htmlMode, &reset, "  �{�W�����k�[�{�[����" );
        if ( dd == 28 )
            tprintf( htmlMode, &reset, "  �X�y�C������̓Ɨ��L�O��(�p�i�})" );
        if ( dd == 30 )
            tprintf( htmlMode, &reset, "  �{�j�t�@�V�I�L�O��(�t�B���s��)" );

        if ( (yy >= 2007) && (g == NthKday( THIRD, SUNDAY, NOVEMBER, yy )) )
            tprintf( htmlMode, &reset, "  �Ƒ��̓�" );
    }
    if ( mm == DECEMBER ) {
        if ( dd == 1 )
            tprintf( htmlMode, &reset, "  ���E�G�C�Y�f�[" );
        if ( dd == 2 )
            tprintf( htmlMode, &reset, "  ����L�O��(���[�}�j�A)" );
        if ( (dd == 2) || (dd == 3) )
            tprintf( htmlMode, &reset, "  �A�M�����L�O��(UAE)" );
        if ( dd == 5 )
            tprintf( htmlMode, &reset, "  �����a����(�^�C)" );
        if ( dd == 6 ) {
            tprintf( htmlMode, &reset, "  ���@�L�O��(�X�y�C��)" );
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�t�B�������h)" );
        }
        if ( dd ==  8 ) {
            tprintf( htmlMode, &reset, "  �j���{" );
            tprintf( htmlMode, &reset, "  ���@�L�O��(���[�}�j�A)" );
            tprintf( htmlMode, &reset, "  ��̓�(�p�i�})" );
        }
        if ( dd == 9 )
            tprintf( htmlMode, &reset, "  �Ɨ��L�O��(�^���U�j�A)" ); 
        if ( dd == 10 ) {
            tprintf( htmlMode, &reset, "  ���E�l���f�[" );
            tprintf( htmlMode, &reset, "  ���@�L�O��(�^�C)" );
        }
        if ( dd == 12 )
            tprintf( htmlMode, &reset, "  ���@�L�O��(���V�A)" );
        if ( dd == 16 ) {
            tprintf( htmlMode, &reset, "  �폟�L�O��(�o���O���f�B�b�V��)" );
            tprintf( htmlMode, &reset, "  �a���̓�(��A�t���J)" );
        }
        if ( dd == 22 )
            tprintf( htmlMode, &reset,
                     "  �i�V���i�����j�e�B�[�f�[(�W���o�u�G)" );
        if ( dd == 25 )
            tprintf( htmlMode, &reset, "  �s���L�O��(��p)" );
        if ( dd == 26 )
            tprintf( htmlMode, &reset, "  �P�ӂ̓�(��A�t���J)" );
        if ( dd == 27 ) {
            tprintf( htmlMode, &reset, "  ���@�L�O��(�k���N)" );
            if ( g % 7 == MONDAY )
                tprintf( htmlMode, &reset,
                         "  Christmas Day Bank Holiday [England, Wales]" );
            if ( g % 7 == TUESDAY )
                tprintf( htmlMode, &reset,
                         "  Boxing Day Bank Holiday [England, Wales]" );
        }
        if ( dd == 28 )
            if ( g % 7 == MONDAY )
                tprintf( htmlMode, &reset,
                         "  Boxing Day Bank Holiday [England, Wales]" );
        if ( g == sekkiDay( SK24_TAISETSU, yy ) )
            tprintf( htmlMode, &reset, "  ���" );
        else if ( g == sekkiDay( SK24_TOUJI, yy ) )
            tprintf( htmlMode, &reset, "  �~��" );
        if ( yy >= 1873 ) {
            if ( ((dd == 28) && (g % 7 != SATURDAY) && (g % 7 != SUNDAY)) ||
                 ((dd == 27) && (g % 7 == FRIDAY))                        ||
                 ((dd == 26) && (g % 7 == FRIDAY))                           )
                tprintf( htmlMode, &reset, "  ������p�[��" );
        }
        if ( dd == 30 ) {
            tprintf( htmlMode, &reset, "  ���T�[���L�O��(�t�B���s��)" );
            tprintf( htmlMode, &reset, "  �����L�O��(���[�}�j�A)" );
        }
    }

    if ( ( mm % 3 == 0 ) && ( dd == 1 ) && ( yy >= 1956 ) )
        tprintf( htmlMode, &reset, "  �f��̓�" ); /* 1956�N�` */
    if ( ( ( mm == MARCH )     && ( g == higanInSpring( yy ) ) ) ||
         ( ( mm == SEPTEMBER ) && ( g == higanInAutumn( yy ) ) )    )
        tprintf( htmlMode, &reset, "  �ފ݂̓���" );
    if ( ( ( mm == JUNE )     && ( dd == 30 ) ) ||
         ( ( mm == DECEMBER ) && ( dd == 31 ) )    )
        tprintf( htmlMode, &reset, "  ���P" );

    if ( ( yy >= 1973 ) && ( g % 7 == MONDAY )               &&
         ( ((mm == MARCH)     && (g - 1 == shunbunday)) ||
           ((mm == SEPTEMBER) && (g - 1 == shuubunday))    )    ) {
        tprintf( htmlMode, &reset, "  �U�֋x��" );
    }

    if ( ( p = zassetsu( dd, mm, yy ) ) != NULL )
        tprintf( htmlMode, &reset, "  %s", p );

    while( h[i].name ) {
        if ( h[i].mm > mm )
            break;
        if ( h[i].mm == mm ) {
            /* 5��4����                                                     */
            /*     ���j�Əd�Ȃ����ꍇ�́A                                   */
            /*       �����̓��j�ɂȂ�(�����̋x���ɂ͂Ȃ�Ȃ�)               */
            /*     ���j�Əd�Ȃ����ꍇ�́A                                   */
            /*       �����̐U�֋x���ɂȂ�(�����̋x���ɂ͂Ȃ�Ȃ�)           */
            /*   ���m�ɂ́A�u���̓��̑O���Ɨ����������̋x���ł���ꍇ�A���� */
            /*   ���������ł���΁A���̓��������̋x���Ƃ���v�B���j����ѐU */
            /*   �֋x���͕����ł͂Ȃ��̂ŁA���Y�����Ηj��������j���̂��Â� */
            /*   ���ł���ꍇ�̂݁A�����̋x���ƂȂ� (���ʓI�ɂ́A�j���Ɋ֌W */
            /*   �Ȃ��x�݂̓��ɂȂ�)   �����_�ł́u���̓��v��5��4�������Ȃ� */
            /* [2003�N�ȍ~�A�u�h�V�̓��v���O���A�u�H���̓��v�������ƂȂ��  */
            /*  ���Ȍ`�ł̍����̋x�������݂�����悤�ɂȂ����B]             */
            /* �� 2005�N�́u�j���@�v�����ɂ��A5��4���́u�݂ǂ�̓��v��    */
            /*    �Ȃ���(2007�N����K�p)                                    */
            if ( h[i].dd == dd ) {
                if ( ( h[i].s_yy <= yy ) &&
                     ( h[i].e_yy >= yy )    )
                    if ( !( ((yy >= 1989) && (yy <= 2006)) &&
                            (mm == 5) && (dd == 4) &&
                            ( (g % 7 == SUNDAY) ||
                              (g % 7 == MONDAY)    )                  ) )
                        tprintf( htmlMode, &reset, "  %s", h[i].name );
            }

            /* 5��4���ȊO�́u�����̋x���v�����j�Əd�Ȃ����ꍇ�̗���(���j��) */
            if ( ( yy >= 1973 )        &&
                 ( h[i].dd == dd - 1 ) &&
                 ( h[i].s_yy <= yy )   &&
                 ( h[i].e_yy >= yy )   &&
                 ( g % 7 == MONDAY )      ) {
                if ( (mm != 5) || (dd != 5) )
                    tprintf( htmlMode, &reset, "  �U�֋x��" );
            }
        }

        /* �O�����O�����ŏj�������j���̏ꍇ     */
        /*   (�����_�ł́A�Y��������͑��݂��Ȃ�) */
        if ( ( yy >= 1973 ) && ( dd == 1 ) && ( g % 7 == MONDAY )  &&
             ( h[i].mm == mm - 1 )                                 &&
             ( h[i].dd == lastDayOfGregorianMonth( h[i].mm, yy ) )    )
            tprintf( htmlMode, &reset, "  �U�֋x��" );

        i++;
    }                               /* �U�֋x���͏��a48�N������{ */
    /* 5��4�����Ηj�`�y�j�̏ꍇ�A�����̋x���A */
    /*         ���j�̏ꍇ�A      �ʏ�̓��j�A */
    /*         ���j�̏ꍇ�A      �U�֋x��     */
    /* �ƂȂ�(�������N�ȍ~)                   */

    /* 2007�N���A5��3���܂���5��4�������j�̏ꍇ��5��6�����U�֋x�� */
    /* �ɂȂ���                                                     */
    if ( (yy >= 2007) && (mm == 5) && (dd == 6) &&
         ((g % 7 == TUESDAY) || (g % 7 == WEDNESDAY)) )
         tprintf( htmlMode, &reset, "  �U�֋x��" );
}


void
checkAmerican( long g, int dd, int mm, int yy, int htmlMode, int *reset )
{
    register int    i      = 0;
    int             length = 41;

#if     0
    if ( dd == 1 )
        if ( mm % 3 == 1 )
            tprintf( htmlMode, reset, "  quater day [��]" );
#endif
    if ( mm == JANUARY ) {
        if ( ( yy >= 1986 ) && ( g == KingsBirthday( yy ) ) )
            tprintf( htmlMode, reset,
                     "  �L���O�L�O�j��(Martin Luther King Day)[��]" );
        if ( ( yy > 1934 ) && ( yy % 4 == 0 ) && ( dd == 20 ) )
            tprintf( htmlMode, reset,
                     "  �哝�̏A�C��(Inauguration Day)[��]" );
    }
    if ( mm == FEBRUARY ) {
        if ( g == waitangiDay( yy ) )
            tprintf( htmlMode, reset,
                     "  Waitangi Day [New Zealand]" );
        if ( g == australiaDay( yy ) )
            tprintf( htmlMode, reset,
                     "  Australia Day [Vic,WA,SA,Tas Aust]" );
        if ( g == WashingtonBirthday( yy ) )
            tprintf( htmlMode, reset,
                     "  President's Day [��]" );
        if ( g == daylightSavingsEndInBrazil( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [�u���W��]" );
    }
    if ( ( mm >= FEBRUARY ) && ( mm <= JUNE ) ) {
        easterday = easter( yy );
        /*
         *      Easter �̓��t�Ɉˑ����Ė��N�ς��j�Փ�
         */
        if ( g == septuagestima( yy ) )
            tprintf( htmlMode, reset, "  Septuagestima" );
        if ( g == sexagesima( yy ) )                        /* @@ */
            tprintf( htmlMode, reset, "  Sexagesima" );     /* @@ */
        if ( g == quinquagesima( yy ) )
            tprintf( htmlMode, reset, "  Quinquagesima" );
        if ( g == shroveMonday( yy ) )                      /* @@ */
            tprintf( htmlMode, reset, "  Shrove Monday" );  /* @@ */
        if ( g == quadragesima( yy ) )
            tprintf( htmlMode, reset, "  Quadragesima" );
        if ( g == mardiGras( yy ) ) {
            tprintf( htmlMode, reset, "  Mardi Gras" );
            tprintf( htmlMode, reset, "  Shrove Tuesday" );
            tprintf( htmlMode, reset, "  Pancake Day" );
        }
        if ( ( g >= ashWednesday( yy ) ) && ( g < easterday ) &&
             ( g % 7 != SUNDAY ) )
            tprintf( htmlMode, reset, "  Lent" );
        if ( g == ashWednesday( yy ) )
            tprintf( htmlMode, reset, "  Ash Wednesday" );
        if ( g == britishMothersDay( yy ) )
            tprintf( htmlMode, reset, "  ��̓� [�p]" );
        if ( g == passionSunday( yy ) )
            tprintf( htmlMode, reset, "  Passion Sunday" );
        if ( g == palmSunday( yy ) )
            tprintf( htmlMode, reset, "  Palm Sunday" );
        if ( g == holyThursday( yy ) ) {
            tprintf( htmlMode, reset, "  Holy Thursday" );
            tprintf( htmlMode, reset, "  Maundy Thursday" );
        }
        if ( g == goodFriday( yy ) )
            tprintf( htmlMode, reset, "  Good Friday" );
        if ( g == holySaturday( yy ) )
            tprintf( htmlMode, reset, "  Holy Saturday" );
        if ( g == easterMonday( yy ) )
            tprintf( htmlMode, reset, "  Easter Monday" );
        if ( g == easterday )
            tprintf( htmlMode, reset, "  ������(Easter)" );
        if ( g == lowSunday( yy ) )
            tprintf( htmlMode, reset, "  Low Sunday" );
        if ( g == pentecost( yy ) )
            tprintf( htmlMode, reset, "  Pentecost" );
        if ( g == rogationSunay( yy ) )                         /* @@ */
            tprintf( htmlMode, reset, "  Rogation Sunday" );    /* @@ */
        if ( ( g >= rogationDay( yy )  ) &&
             ( g <  ascensionDay( yy ) )    )
            tprintf( htmlMode, reset, "  Rogation Day" );
        if ( g == ascensionDay( yy ) )
            tprintf( htmlMode, reset, "  Ascension Day" );
        if ( g == whitsunday( yy ) )
            tprintf( htmlMode, reset, "  Whitsunday" );
        if ( g == whitmonday( yy ) )
            tprintf( htmlMode, reset, "  Whitmonday" );
        if ( g == trinity( yy ) )
            tprintf( htmlMode, reset, "  Trinity" );
        if ( g == corpusChristiDay( yy ) )
            tprintf( htmlMode, reset, "  Corpus Christi Day" );
    }
    if ( mm == MARCH ) {
        if ( ( yy <= 1934 ) && ( yy % 4 == 0 ) && ( dd == 4 ) )
            tprintf( htmlMode, reset,
                     "  �哝�̏A�C��(Inauguration Day)[��]" );
        if ( dd == 8 )
            tprintf( htmlMode, reset, "  ���ۏ����f�[" );
        if ( (yy >= 2007) && (g == daylightSavingsStart( yy )) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsStartInEurope( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsEndInAustralia( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [��]" );
        if ( g == daylightSavingsEndInNewZealand( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [�j���[�W�[�����h]" );
    }
    if ( mm == APRIL ) {
        if ( (yy <= 2006) && (g == daylightSavingsStart( yy )) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [��]" );
    }
    if ( mm == MAY ) {
        if ( g == memorialDay( yy ) )
            tprintf( htmlMode, reset, "  Memorial Day [��]" );
        if ( ( g == NthKday( FIRST, MONDAY, MAY, yy ) ) ||
             ( g == NthKday( LAST,  MONDAY, MAY, yy ) )    )
            tprintf( htmlMode, reset, "  bank holiday [�p]" );
    }
    if ( mm == JUNE ) {
        if ( g == NthKday( FIRST, WEDNESDAY, JUNE, yy ) )
            tprintf( htmlMode, reset, "  Derby Day [�p]" );
        if ( (yy >= 1856) && (g == NthKday( SECOND, SUNDAY, JUNE, yy )) )
            tprintf( htmlMode, reset, "  �Ԃ̓� [��]" );
        if ( g == russianDay( dd, mm, yy ) )
            tprintf( htmlMode, reset, "  ���V�A�̓�" );
    }
    if ( mm == JULY ) {
        if ( (yy >= 1933) && (g == NthKday( SECOND, MONDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  �僊�[�O�E�I�[���X�^�[�Q�[�� [��]" );
        if ( (yy >= 1995) && (g == NthKday( FOURTH, MONDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  ����̓� [��]" );
        if ( (yy >= 2000) && (g == NthKday( LAST, FRIDAY, JULY, yy )) )
            tprintf( htmlMode, reset, "  �V�X�e���Ǘ��҂̓�" );
    }
    if ( mm == AUGUST ) {
        if ( g == NthKday( FIRST, MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset, "  bank holiday [Scotland]" );
        if ( g == NthKday( LAST,  MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset, "  bank holiday [England, Wales]" );
        if ( g == NthKday( FOURTH, MONDAY, AUGUST, yy ) )
            tprintf( htmlMode, reset,
                     "  Hurricane Supplication Day [the Virgin Islands]" );
    }
    if ( mm == SEPTEMBER ) {
        if ( g == laborDay( yy ) )
            tprintf( htmlMode, reset, "  Labor Day" );
        if ( g == harvestMoon( yy ) )
            tprintf( htmlMode, reset, "  Harvest Moon" );
    }
    if ( mm == OCTOBER ) {
        if ( (yy <= 2006) && (g == daylightSavingsEnd( yy )) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [��]" );
        if ( g == daylightSavingsEndInEurope( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [��]" );
        if ( g == columbusDay( yy ) )
            tprintf( htmlMode, reset, "  �R�����u�X�L�O��(Columbus Day)" );
        if ( g == huntersMoon( yy ) )
            tprintf( htmlMode, reset, "  Hunter's Moon" );
        if ( g == NthKday( THIRD, SATURDAY, OCTOBER, yy ) )
            tprintf( htmlMode, reset, "  sweetest day [��]" );
        if ( g == NthKday( FOURTH, SUNDAY, OCTOBER, yy ) )
            tprintf( htmlMode, reset, "  �`��̓� [��]" );
        if ( g == daylightSavingsStartInAustralia( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [��]" );
        if ( g == daylightSavingsStartInNewZealand( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [�j���[�W�[�����h]" );
        if ( g == daylightSavingsStartInBrazil( yy ) )
            tprintf( htmlMode, reset, "  �Ď��ԊJ�n [�u���W��]" );
    }
    if ( mm == NOVEMBER ) {
        if ( (yy >= 2007) && (g == daylightSavingsEnd( yy )) )
            tprintf( htmlMode, reset, "  �Ď��ԏI�� [��]" );
        if ( ( yy % 4 == 2 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            tprintf( htmlMode, reset, "  General Election Day [��]" );
        }
        if ( ( yy % 4 == 0 ) &&
             ( g == NthKday( FIRST, MONDAY, NOVEMBER, yy ) + 1L ) ) {
            tprintf( htmlMode, reset, "  Election Day [��]" );
        }
        if ( g == loadMayorDay( yy ) ) {
            tprintf( htmlMode, reset, "  �����h���s���A�C�� [�p]" );
        }
        if ( g == rememberanceDay( yy ) ) {
            tprintf( htmlMode, reset, "  Rememberance Day [�p]" );
        }
        if ( g == thanksGivingDay( yy ) ) {
            tprintf( htmlMode, reset, "  ���Ӎ�(Thanks Giving Day) [��]" );
        }
        if ( g == thanksGivingDay( yy ) + 1L ) {
            tprintf( htmlMode, reset, "  day after Thanksgiving [��]" );
        }
    }
    if ( ( ( mm == NOVEMBER ) || ( mm == DECEMBER ) ) ) {
        if ( g == advent( yy ) ) {
            tprintf( htmlMode, reset, "  Advent Sunday" );
        }
        else if ( ( g > advent( yy ) )                   &&
              ( ( mm == NOVEMBER ) || ( dd <= 23 ) )    ) {
            tprintf( htmlMode, reset, "  Advent" );
        }
    }

    while( hh[i].name ) {
        if ( hh[i].mm > mm )
            break;
        if ( hh[i].mm == mm ) {
            if ( hh[i].dd == dd ) {
                tprintf( htmlMode, reset, "  %s", hh[i].name );
            }
        }
        i++;
    }
}


int
checkGreek( char *buf,
            long g,
            int d, int m, int y,    /* Julian date     */
            int mm,                 /* Gregorian month */
            int yy,                 /* Gregorian year  */
            int htmlMode, int *reset )
{
    int     _d, _m, _y;
    size_t  l = strlen( buf );

    if ( g == nicaeanRuleEaster( yy ) )
        tsprintf( buf, htmlMode, reset, "  Nicaean Rule Easter" );
#if     0
    checkDateList( g, easternOrthodoxChristmas( yy ),
                   "Eastern Orthodox Christmas" );
#else
    if ( ( m == DECEMBER ) && ( d == 25 ) )
        tsprintf( buf, htmlMode, reset, "  Eastern Orthodox Christmas" );
#endif
    if ( ( y >= 1743 ) && ( m == APRIL ) && ( d == 2 ) )
        tsprintf( buf, htmlMode, reset, "  Jefferson's Birthday" );
    if ( ( m == MARCH ) && ( d == 26 ) )
        kiddushHaHamah = 1;
    if ( m == NOVEMBER ) {
        mm--;
        if ( mm <= 0 ) {
            yy--;
            mm = 12;
        }
        julianFromAbsolute( absoluteFromGregorian( 1, mm, yy ),
                            &_d, &_m, &_y );
        if ( ((_y + 1) % 4) == 0 ) {
            if ( d == 22 )
                talUmatar = 1;
        }
        else if ( d == 21 )
            talUmatar = 1;
    }

    return ( (l != strlen( buf )) ? 1 : 0 );
}


int
checkIslamic( char *buf,
              long g,
              int d, int m, int y,  /* Islamic date   */
              int yy,               /* Gregorian year */
              int htmlMode )
{
    int reset = 1;

    buf[0] = '\0';

    if ( m == 9 )
        tsprintf( buf, htmlMode, &reset, "  �f�H��" );
    if ( (m == 1) && (d == 1) )
        tsprintf( buf, htmlMode, &reset, "  Islamic New Year %d", y );
    if ( (m == 1) && (d == 10) )
        tsprintf( buf, htmlMode, &reset, "  Ashura" );
    if ( (m == 3) && (d == 12) )
        tsprintf( buf, htmlMode, &reset,
                  "  Mulad-Al-Nabi (Mohammed's Birthday)" );
    if ( (m == 7) && (d == 26) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e-Mi\'raj" );
    if ( (m == 8) && (d == 15) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e-Bara\'t" );
    if ( (m == 9) && (d == 27) )
        tsprintf( buf, htmlMode, &reset, "  Shab-e Qadr" );
    if ( (m == 10) && (d == 1) )
        tsprintf( buf, htmlMode, &reset, "  Id-al-Fitr (�J�֐�)" );
    if ( (m == 12) && (d == 10) )
        tsprintf( buf, htmlMode, &reset, "  Id-al-Adha" );

    return ( (buf[0] != '\0') ? 1 : 0 );
}

#if 0
long
daynameOnOrBefore( int dayname, long date )
{
    return ( date - ((date - dayname) % 7) );
}
#else
#define daynameOnOrBefore( dayname, date )  KdayOnOrBefore( date, dayname )
#endif

int
checkHebrew( char *buf,
             long g,
             int d, int m, int y,   /* Hebrew date     */
             int mm,                /* Gregorian month */
             int yy,                /* Gregorian year  */
             int htmlMode )
{
    int     _yy, _mm;                                               /* @@ */
    int     hanukkahYear, __mm, __dd, __yy, ___yy;                  /* @@ */
    long    hanukkah;                                               /* @@ */
    int     reset = 1;

    buf[0] = '\0';

    roshHaShanah = yomKippur( yy ) - 9L;                            /* @@ */
    passoverday  = passover( yy );
    tishaBAvday  = tishaBAv( yy );                                  /* @@ */

    if ( (mm == 1) || (mm == 2) || ((mm >= 10) && (mm <= 12)) ) {   /* @@ */
        _mm = mm + 1;
        _yy = yy;
        if ( _mm > 12 ) {
            _mm = 1;
            _yy++;
        }
        hebrewFromAbsolute( absoluteFromGregorian( 
                                lastDayOfGregorianMonth( _mm, _yy ),
                                _mm, _yy ),
                            &__dd,
                            &__mm,
                            &hanukkahYear );
        hanukkah = absoluteFromHebrew( 25, 9, hanukkahYear );
        if ( g == hanukkah - 1L )
            tsprintf( buf, htmlMode, &reset, "  Erev Hanukkah" );
        if ( (g >= hanukkah) && (g <= hanukkah + 7L) )
            tsprintf( buf, htmlMode, &reset, "  Hanukkah" );
    }                                                           /* @@ */
    if ( g == erevRoshHaShanah( yy ) )                          /* @@ */
        tsprintf( buf, htmlMode, &reset,"  Erev Rosh HaShanah");/* @@ */
    if ( (g == roshHaShanah) || (g == roshHaShanah2( yy )) )    /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Rosh HaShanah" );   /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah - 4 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Selichot (night)" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, roshHaShanah + 7 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Shuvah" );  /* @@ */
    if ( g == tzomGedaliah( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Tzom Gedaliah" );   /* @@ */
    if ( g == erevYomKippur( yy ) )                             /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Yom Kippur" ); /* @@ */
    if ( g == yomKippur( yy ) )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom Kippur" );
    if ( g == erevSukkot( yy ) )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Sukkot" );     /* @@ */
    if ( (g == sukkot( yy )) || (g == sukkot2( yy )) )          /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Sukkot" );          /* @@ */
    if ( (g >= holHamoedSukkot( yy ) ) &&                       /* @@ */
         (g <= holHamoedSukkot4( yy ))    )                     /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Hol Hamoed Sukkot");/* @@ */
    if ( g == hoshannahRabbah( yy ) )                           /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Hoshannah Rabbah" );/* @@ */
    if ( g == sheminiAtzeret( yy ) )                            /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shemini Atzeret" ); /* @@ */
    if ( g == simchatTorah( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Simchat Torah" );   /* @@ */
    if ( g == erevPassover( yy ) )                              /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Passover" );   /* @@ */
    if ( g == passoverday )
        tsprintf( buf, htmlMode, &reset, "  Passover Begins" );
    if ( ( g > passoverday ) && ( g < passoverday + 6L ) ) {
        if ( (g >= passoverday + 2L) && (g == passoverday + 5L) )
            tsprintf( buf, htmlMode, &reset, "  Hol Hamoed Passover" );
        else
            tsprintf( buf, htmlMode, &reset, "  Passover" );
    }
    if ( g == passoverday + 7L )
        tsprintf( buf, htmlMode, &reset, "  Passover Ends" );
    if ( g == yomHaShoah( yy ) )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  YomHa Shoah" );     /* @@ */
    if ( g == lagBaOmer( yy ) )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Lag BaOmer" );      /* @@ */
    if ( g == yomYerushalim( yy ) )                             /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom Yerushalim" );  /* @@ */
    if ( g == erevShavuot( yy ) )                               /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Shavuot" );    /* @@ */
    if ( (g == shavuot( yy )) || (g == shavuot2( yy )) )        /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shavuot" );         /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 43 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Shekalim" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 30 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Zachor" );  /* @@ */
    if ( g == daynameOnOrBefore(SATURDAY, passoverday-14) - 7 ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Parah" );   /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday - 14 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat HaHodesh" );/* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, passoverday -  1 ) ) /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat HaGadol" ); /* @@ */
#if 0   /* 'Ta Anit Esther' �Ɠ����Ȃ̂ŁA�폜 */
    if ( (((passoverday % 7) == 2) &&                           /* @@ */
          (g == passoverday - 33)     ) ||                      /* @@ */
         (g == passoverday - 31)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Fast of Esther" );  /* @@ */
    }                                                           /* @@ */
#endif
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday - 28)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shushan Purim" );   /* @@ */
    }                                                           /* @@ */
    if ( (((passoverday % 7) == 0) &&                           /* @@ */
          (g == passoverday + 18)     ) ||                      /* @@ */
         (((passoverday % 7) == 6) &&                           /* @@ */
          (g == passoverday + 20)     ) ||                      /* @@ */
         (g == passoverday - 29)           ) {                  /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Yom HaAtzma\'ut" ); /* @@ */
    }                                                           /* @@ */
    if ( g == tuBShvat( yy ) )
        tsprintf( buf,  htmlMode, &reset, "  Tu B' Shuvat" );   /* @@ */
                /* Tu B' Shevat ? */
                /*         ~      */
    if ( g == purim( yy ) )
        tsprintf( buf,  htmlMode, &reset, "  Purim" );
    if ( g == purim( yy ) - 1 )                                 /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Erev Purim" );      /* @@ */
    if ( g == taAnitEsther( yy ) )
        tsprintf( buf, htmlMode, &reset, "  Ta Anit Esther" );
    if ( g == tishaBAvday )
        tsprintf( buf, htmlMode, &reset, "  Tisha B' Av" );
    if ( g == tishaBAvday - 21 )                                /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Tzom Tammuz" );     /* @@ */
    if ( g == daynameOnOrBefore( SATURDAY, tishaBAvday ) )      /* @@ */
        tsprintf( buf, htmlMode, &reset, "  Shabbat Hazon" );   /* @@ */
    if ( g == tishaBAvday + 7 )                                 /* @@ */
        tsprintf( buf,  htmlMode, &reset, "  Shabbat Nahamu" ); /* @@ */

    if ( g == hebrewPentecost( yy ) )
        tsprintf( buf, htmlMode, &reset, "  Pentecost" );

    if ( kiddushHaHamah == 1 )
        tsprintf( buf, htmlMode, &reset, "  Kiddush HaHamah" );
    if ( talUmatar == 1 )                                           /* @@ */
        tsprintf( buf,  htmlMode, &reset, "  Tal Umatar (evening)");/* @@ */
    if ( m == 10 ) {                                                /* @@ */
        hebrewFromAbsolute( absoluteFromGregorian( 28, mm, yy ),    /* @@ */
                            &__dd, &__mm, &__yy );                  /* @@ */
        if ( (absoluteFromHebrew( 10, 10, __yy ) % 7) == 6 ) {      /* @@ */
            if ( d == 11 )                                          /* @@ */
                tsprintf( buf, htmlMode, &reset, "  Tzom Teveth" ); /* @@ */
        }                                                           /* @@ */
        else if ( d == 10 )                                         /* @@ */
            tsprintf( buf, htmlMode, &reset, "  Tzom Teveth" );     /* @@ */
    }
    if ( m == 11 ) {
        _mm = mm + 1;
        _yy = yy;
        if ( _mm > 12 ) {
            _mm = 1;
            _yy++;
        }
        hebrewFromAbsolute( absoluteFromGregorian( 
                                lastDayOfGregorianMonth( _mm, _yy ),
                                _mm, _yy ),
                            &__dd,
                            &__mm,
                            &__yy );
        if ( (absoluteFromHebrew( 1, 7, __yy ) % 7) == 6 ) {
            hebrewFromAbsolute( daynameOnOrBefore(
                                    SATURDAY,
                                    absoluteFromHebrew( 17, 11, __yy ) ),
                                &__dd,
                                &__mm,
                                &___yy );
        }
        else {
            hebrewFromAbsolute( daynameOnOrBefore(
                                    SATURDAY,
                                    absoluteFromHebrew( 16, 11, __yy ) ),
                                &__dd,
                                &__mm,
                                &___yy );
        }
        if ( d == __dd )
            tprintf( htmlMode, &reset, "  Shabbat Shirah" );
    }

    /* �ȉ��A2003.02.06 �ǉ� (�Q�l: hdate.lib) */
    switch ( m ) {
    case 7: /* Tishrey */
        switch ( d ) {
        case 1:
            tsprintf( buf, htmlMode, &reset, "  New year I" );
            break;
        case 2:
            tsprintf( buf, htmlMode, &reset, "  New year II" );
            break;
        case 3:
            if ( (g % 7) != SATURDAY ) {
                tsprintf( buf, htmlMode, &reset, "  Gdalya fast" );
            }
            break;
        case 4:
            if ( (g % 7) == SUNDAY ) {
                tsprintf( buf, htmlMode, &reset, "  Gdalya fast" );
            }
            break;
        case 10:
            tsprintf( buf, htmlMode, &reset, "  Day of Cipurim" );
            break;
        case 22:
            tsprintf( buf, htmlMode, &reset, "  Tora happiness" );
            break;
        }
        break;

    case 2:     /* Iyar */
        if ( yy >= 1948 ) {
            switch ( d ) {
            case 3:
            case 4:
                if ( (g % 7) == THURSDAY ) {
                    tsprintf( buf, htmlMode, &reset, "  Independence Day" );
                }
                break;
            case 5:
                if ( ((g % 7) != FRIDAY) && ((g % 7) != SATURDAY) ) {
                    tsprintf( buf, htmlMode, &reset, "  Independence Day" );
                }
                break;
            }
        }
        break;

    case 5:     /* Av */
        switch ( d ) {
        case 15:
            tsprintf( buf, htmlMode, &reset, "  Day of love" );
            break;
        }
        break;
    }

    return ( (buf[0] != '\0') ? 1 : 0 );
}


void
checkTsupo( long g, int d, int m, int y )
{
    if ( ( m == OCTOBER ) && ( d == 28 ) ) {
        if ( y > 1988 )
            printf( "  Tsuporone's BBS �J��%d���N", y - 1988 );
        else if ( y == 1988 )
            printf( "  Tsuporone's BBS �J��" );
    }
}


/*
 *      JR�̉^���v�Z�̓�����̎Z�o (1995�N12������)
 *
 *              �ʏ��: �ՎU���ƔɖZ���ȊO�̓�
 *              �ՎU��: 1��16���`2������, 6�E9�E11��, 12��1���`20�� �̊e����
 *                      �̌��j�`�ؗj (�������A�x���Ƃ��̑O���͏���)
 *              �ɖZ��: 3��21���`4��5��, 4��28���`5��6��, 7��21���`8��31��,
 *                      12��25���`1��10��
 *
 *              ���}����(�V�����̎w��ȓ��}�������܂�)
 *                      �ՎU���͒ʏ����200�~�����A�ɖZ���͒ʏ����200�~�����B
 *                      �������AJR�����{�́u�΂��v�E�u���܂����v��������
 *                      ����-�S�R�̊Ԃ̔C�ӂ̉w�����R�`-�H�c�̊Ԃ̔C�ӂ̉w�ŏ�
 *                      �~����ꍇ�́A�ՎU���͒ʏ���� 340�~�����A�ɖZ���͒ʏ�
 *                      ����340�~����
 *                      (�V�����̎��R�ȓ��}�����͒ʔN���ꗿ��)
 *              �w��Ȍ�
 *                      �ՎU���ȊO�͊ՎU����200�~����(�������AJR�k�C��, JR��
 *                      �B�͒ʔN���ꗿ��)
 *              �񐔌�
 *                      4��27���`5��6��, 8��11���`20��, 12��28���`1��6���̊e��
 *                      �Ԃ́A�񐔌��𗘗p�ł��Ȃ�
 */

#define TERM_NORMAL     0
#define TERM_IDLE       1
#define TERM_BUSY       2
#define TERM_VERYBUSY   3

int
checkTermIdle( long g, int d, int m, int y )
{
    long    w = g % 7L;

    if ( ( w == 0L ) || ( w >= 5L ) )
        return ( TERM_NORMAL );
    if ( ( m == 1 ) && ( d == 16 ) && ( w == 1L ) )
        return ( TERM_NORMAL );
    if ( m == 2 ) {
        if ( ( d == 10 )                    ||
             ( d == 11 )                    ||
             ( ( d == 12 ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    if ( m == 9 ) {
        if ( ( d == 14 )                    ||
             ( d == 15 )                    ||
             ( ( d == 16 ) && ( w == 1L ) )    )
            return ( TERM_NORMAL );
        if ( ( g == shunbunday - 1L )                    ||
             ( g == shunbunday )                         ||
             ( ( g == shunbunday + 1L ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    if ( m == 11 ) {
        if ( ( d == 2 )                    ||
             ( d == 3 )                    ||
             ( ( d == 4 ) && ( w == 1L ) )    )
            return ( TERM_NORMAL );
        if ( ( d == 22 )                    ||
             ( d == 23 )                    ||
             ( ( d == 24 ) && ( w == 1L ) )    )
        return ( TERM_NORMAL );
    }
    return ( TERM_IDLE );
}

void
trainService( long g, int d, int m, int y )
{
    int     kind = TERM_NORMAL;

    if ( ( y >= 1990 ) || ( ( y == 1989 ) && ( m >= 4 ) ) ) {
        /* ���̐��x�� 1989�N4��1��������{ */
        switch ( m ) {
        case  1:
            if ( d <= 6 )
                kind = TERM_VERYBUSY;
            else if ( d <= 10 )
                kind = TERM_BUSY;
            else if ( d >= 16 )
                kind = checkTermIdle( g, d, m, y );
            break;
        case  2:
        case  6:
        case  9:
        case 11:
            kind = checkTermIdle( g, d, m, y );
            break;
        case  3:
            if ( d >= 21 )
                kind = TERM_BUSY;
            break;
        case  4:
            if ( d <= 5 )
                kind = TERM_BUSY;
            else if ( d >= 27 )
                kind = TERM_VERYBUSY;
            break;
        case  5:
            if ( d <= 6 )
                kind = TERM_VERYBUSY;
            break;
        case  7:
            if ( d >= 21 )
                kind = TERM_BUSY;
            break;
        case  8:
            kind = TERM_BUSY;
            if ( ( d >= 11 ) && ( d <= 20 ) )
                kind = TERM_VERYBUSY;
            break;
        case 12:
            if ( d <= 20 )
                kind = checkTermIdle( g, d, m, y );
            else if ( d >= 28 )
                kind = TERM_VERYBUSY;
            else if ( d >= 25 )
                kind = TERM_BUSY;
            break;
        }

        printf( "\n- JR�^���v�Z�̊��� -\n" );
        switch ( kind ) {
        case TERM_NORMAL:
            printf( "�ʏ��\n" );
            break;
        case TERM_IDLE:
            printf( "�ՎU��\n" );
            printf( "    ���}�����͒ʏ����芄������܂�\n" );
            break;
        case TERM_BUSY:
        case TERM_VERYBUSY:
            if ( ( m == 4 ) && ( d == 27 ) )
                printf( "�ʏ��\n    �������A���̓��͓���Ƃ��āA" );
            else {
                printf( "�ɖZ��\n" );
                printf( "    ���}�����͒ʏ����芄������܂�\n" );
                if ( kind == TERM_VERYBUSY )
                    printf( "    �܂��A" );
            }
            if ( kind == TERM_VERYBUSY )
                printf( "�V�������̉񐔌��͎g���܂���\n" );
            break;
        }
    }

    if ( y >= 2005 ) {  /* ���N���炩�s��[�b��I��2005�N����Ƃ��Ă���] */
        /*
         * 2007�N���݁A�������ԁE���p���Ԃ͈ȉ��̂悤�ɂȂ��Ă���
         *  �t�x�� 
         *      ��������:2��20���`3��31�� 
         *      ���p����:3��1���`4��10�� 
         *  �ċx�� 
         *      ��������:7��1���`8��31�� 
         *      ���p����:7��20���`9��10�� 
         *  �~�x�� 
         *      ��������:12��1���`1��10�� 
         *      ���p����:12��10���`1��20�� 
         */
        if ( (m == 1) || (m == 2) || (m == 3) || (m == 4) || (m == 7) ||
             (m == 8) || (m == 9) || (m == 12) )
            printf( "\n- 18�����Ղ̔���/�ʗp���� -\n    " );
        if ( (m == 7) || (m == 12) ) {
            printf( "18�����Ք������B" );
            if ( (d >= 20) || ((m == 12) && (d >= 10)) )
                printf( "18�����Ղ��g���܂�\n" );
            else
                printf( "%s��18�����Ղ̎g�p�\���Ԃ͂܂��n�܂��Ă��܂���\n",
                        (m == 12) ? "�~" : "��" );
        }
        else if ( m == 1 ) {
            if ( d <= 10 )
                printf( "18�����Ք������B18�����Ղ��g���܂�\n" );
            else if ( d <= 20 )
                printf( "�~��18�����Ղ̔������Ԃ͏I�����Ă��܂����A18�����Ղ�"
                        "�g���܂�\n" );
            else
                printf( "�~��18�����Ղ̎g�p�\���Ԃ͏I�����Ă��܂�\n" );
        }
        else if ( m == 2 ) {
            if ( d >= 20 )
                printf( "18�����Ք������B�t��18�����Ղ̎g�p�\���Ԃ͂܂�"
                        "�n�܂��Ă��܂���\n" );
            else
                printf( "�t��18�����Ղ̔����͂܂��n�܂��Ă��܂���\n" );
        }
        else if ( (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( "%s��18�����Ղ̔������Ԃ͏I�����Ă��܂����A18�����Ղ�"
                        "�g���܂�\n",
                        m == 4 ? "�t" : "��" );
            else
                printf( "%s��18�����Ղ̎g�p�\���Ԃ͏I�����Ă��܂�\n",
                        m == 4 ? "�t" : "��" );
        }
        else if ( (m == 3) || (m == 8) )
            printf( "18�����Ք������B18�����Ղ��g���܂�\n" );
    }
    else if ( y >= 1983 ) {
        /* 18�����Ղ̔�����1983�N���ŏ�
         *   ���Ȃ��Ƃ�1995�N���́A�ȉ��̔������ԁE���p���Ԃ�����
         *
         *      �t�x�� 
         *          ��������:3��1���`4��10�� 
         *          ���p����:3��10���`4��20�� 
         *      �ċx�� 
         *          ��������:7��1���`9��10�� 
         *          ���p����:7��10���`9��20�� 
         *      �~�x�� 
         *          ��������:12��1���`1��10�� 
         *          ���p����:12��10���`1��20�� 
         */
        if ( (m == 1) || (m == 3) || (m == 4) || (m == 7) || (m == 8) ||
             (m == 9) || (m == 12) )
            printf( "\n- 18�ؕ��̔���/�ʗp���� -\n    " );
        if ( (m == 3) || (m == 7) || (m == 12) ) {
            printf( "18�ؕ��������B" );
            if ( d >= 10 )
                printf( "18�ؕ����g���܂�\n" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͂܂��n�܂��Ă��܂���\n",
                        (m == 12) ? "�~" : (m == 3) ? "�t" : "��" );
        }
        else if ( m == 8 )
            printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
        else if ( (m == 1) || (m == 4) || (m == 9) ) {
            if ( d <= 10 )
                printf( "18�ؕ��������B18�ؕ����g���܂�\n" );
            else if ( d <= 20 )
                printf(
                 "%s��18�ؕ��̔������Ԃ͏I�����Ă��܂����A18�ؕ��͎g���܂�\n",
                        (m == 1) ? "�~" : (m == 4) ? "�t" : "��" );
            else
                printf( "%s��18�ؕ��̎g�p�\���Ԃ͏I�����Ă��܂�\n",
                        (m == 1) ? "�~" : (m == 4) ? "�t" : "��" );
        }
    }
}


int
checkRoman( char *buf, long g, int d, int m, int y, int htmlMode, int *reset )
{
    buf[0] = '\0';

    switch ( m ) {
    case MARCH:
    case MAY:
    case JULY:
    case OCTOBER:
        if ( d == 15 )
            tsprintf( buf, htmlMode, reset, "  ides" );
        break;
    default:
        if ( d == 13 )
            tsprintf( buf, htmlMode, reset, "  ides" );
        break;
    }

    return ( (buf[0] != '\0') ? 1 : 0 );
}


static int  kamiYoshiNichi[] = {
     1,  3,  5,  6,  8,  9, 13, 15,
    18, 20, 21, 24, 27, 30, 32, 33,
    35, 36, 37, 39, 41, 42, 43, 44,
    45, 47, 48, 51, 54, 55, 56, 57,
    59, -1
};

static int  daiMyouNichi[] = {
     5,  6,  7,  8,  9, 13, 15, 18, 20, 23, 28, 31,
    38, 40, 41, 42, 43, 45, 46, 47, 52, 54, 55, 56,
    57, -1
};

static int  kuENichi[][13] = {
    { 27, 50, -1, },                                        /*  1�� */
    { 15, 51, 57, -1, },                                    /*  2�� */
    {  0,  1,  2,  3,  4,  8, 16, 20, 32, 40, 44, 56, -1 }, /*  3�� */
    {  4,  7, 19, 31, 35, 42, 43, 54, 55, 59, -1, },        /*  4�� */
    { 42, 54, -1, },                                        /*  5�� */
    {  5, 42, 43, 53, 55, -1, },                            /*  6�� */
    { 21, 40, 56, -1, },                                    /*  7�� */
    { 45, 51, 57, -1, },                                    /*  8�� */
    { 10, 27, 28, 29, 30, 31, 32, 33, 34, 46, 50, -1, },    /*  9�� */
    {  1,  5, 13, 24, 25, 34, 35, 37, 48, 49, 53, 59, -1 }, /* 10�� */
    { 24, 42, 48, -1, },                                    /* 11�� */
    { 24, 43, 48, 59, -1, }                                 /* 12�� */
};

void
checkTenShaNichi( long g, int mm, int yy, int htmlMode, int *reset )
{
    long    rikkaday = 0, rittouday = 0;
    int     ks   = ( g + 14 ) % 60;
    int     eto  = ( g +  2 ) % 12;
    int     flag = OFF;
    int     i;

    switch ( mm ) {
    case FEBRUARY:
        if ( g < risshunday ) {
            if ( ks == 0 )  /* �b�q */
                flag = ON;
        }
        else {
            if ( ks == 14 ) /* ��� */
                flag = ON;
        }
        break;
    case MARCH:
    case APRIL:
        if ( ks == 14 )     /* ��� */
            flag = ON;
        break;
    case MAY:
        rikkaday  = summerStartDay( yy );
        if ( g < rikkaday ) {
            if ( ks == 14 ) /* ��� */
                flag = ON;
        }
        else {
            if ( ks == 30 ) /* �b�� */
                flag = ON;
        }
        break;
    case JUNE:
    case JULY:
        if ( ks == 30 )     /* �b�� */
            flag = ON;
        break;
    case AUGUST:
        if ( g < risshuuday ) {
            if ( ks == 30 ) /* �b�� */
                flag = ON;
        }
        else {
            if ( ks == 44 ) /* ��\ */
                flag = ON;
        }
        break;
    case SEPTEMBER:
    case OCTOBER:
        if ( ks == 44 )     /* ��\ */
            flag = ON;
        break;
    case NOVEMBER:
        rittouday = winterStartDay( yy );
        if ( g < rittouday ) {
            if ( ks == 44 ) /* ��\ */
                flag = ON;
        }
        else {
            if ( ks == 0 )  /* �b�q */
                flag = ON;
        }
        break;
    case DECEMBER:
    case JANUARY:
        if ( ks == 0 )      /* �b�q */
            flag = ON;
        break;
    }

    if ( flag == ON )
        tprintf( htmlMode, reset, "  �V�͓�" );

    for ( i = 0; kamiYoshiNichi[i] != -1; i++ ) {
        if ( ks == kamiYoshiNichi[i] ) {
            tprintf( htmlMode, reset, "  �_�g��" );
            break;
        }
    }
    for ( i = 0; daiMyouNichi[i] != -1; i++ ) {
        if ( ks == daiMyouNichi[i] ) {
            tprintf( htmlMode, reset, "  �喾��" );
            break;
        }
    }

    if ( (eto == 5) || (eto == 11) )    /* ��, �� */
        tprintf( htmlMode, reset, "  �d��" );

    if (  (ks <=  4)                ||  /* �b�q, ���N, ����, ���K, ��C */
         ((ks >= 15) && (ks <= 19)) ||  /* �ȉK, �M�C, �h��, �p��, ᡖ� */
         ((ks >= 45) && (ks <= 49))    )/* �ȓ�, �M��, �h��, �p�q, ᡉN */
        tprintf( htmlMode, reset, "  �V����" );
}


char    *
kuenichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "�����";
    int     ks = ( g + 14 ) % 60;
    int     i;

    if ( tsuki == 0 )
        tsuki = 12;
    for ( i = 0; kuENichi[tsuki - 1][i] != -1; i++ ) {
        if ( ks == kuENichi[tsuki - 1][i] ) {
            p = q;
            break;
        }
    }

    return ( p );
}

