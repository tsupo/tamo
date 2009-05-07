/*
 *  ftime.c             tsupo@na.rim.or.jp
 *      �t�����X�v����Z�o�v���O����    2 December 1995
 *  Copyright (c) 1995,1996,1999, 2001, 2003, 2007 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: ftime.c $
 * Revision 1.70  2007/02/06  10:54:43  tsujimura543
 * copyright �\�L���A�b�v�f�[�g
 *
 * Revision 1.69  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.68  2003/03/31  11:23:24  tsujimura543
 * �o�͏��������^��
 *
 * Revision 1.67  2003/03/31  05:48:05  tsujimura543
 * irint() �����S�� floor() �ɒu��������
 *
 * Revision 1.66  2003/03/18  10:20:50  tsujimura543
 * �o�͌��ʂ����ꂢ�ɂȂ�悤�ɒ���
 *
 * Revision 1.65  2003/03/12  10:18:22  tsujimura543
 * HTML�o�͎��̃t�����X�v����̏o�͌`����ύX
 *
 * Revision 1.64  2003/03/12  10:05:31  tsujimura543
 * ���������Ή����� #2
 *
 * Revision 1.63  2003/03/11  02:22:57  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.62  2003/02/21  05:05:20  tsujimura543
 * �t�����X�v����̎����\����ON/OFF�ł���悤�ɂ���
 *
 * Revision 1.61  2003/02/07  04:44:43  tsujimura543
 * �t�����X�v����̌��̖��O���J�^�J�i�\������p��ł̕\�L�ɕύX
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * ���̔h���o�[�W�����Ɠ������邽�߁A�������� revision ���Œ�
 *
 * Revision 1.51  1999/07/13  12:01:40  tsujimura543
 * �J������ Win32 �Ɉڂ�
 * -- HTML �o�͑Ή���Ƃ⓮��m�F�͍����UNIX (peach.na.rim.or.jp) ��ōs�Ȃ� 
 *
 * Revision 1.50  1996/08/19  02:10:14  tsujimura
 * Withdrawal from `shizuka' (UNIX��ł̊J���I����)
 *
 * Revision 1.3  95/12/16 05:42:48  tsujimura
 * �t�����X�v������{����(17920923-17991110(?))�̗���𐳊m��
 * �Z�o���邽�߂̃e�[�u���𓱓�
 * 
 * Revision 1.2  95/12/02 20:36:26  tsujimura
 * RCS�pident�����񖄂߂���
 * 
 * Revision 1.1  95/12/02 15:46:22  tsujimura
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tamo_dates.h"

#ifndef	lint
static char	*rcs_id =
	"$Header: C:/user/local/src/tamo/RCS/ftime.c 1.70 2007/02/06 10:54:43 tsujimura543 Exp tsujimura543 $";
#endif

static int	baseYear = 1792;	/* 1792�N9��22�������a��1�N������1�� */
static char	*fmonth[]	= {
	"Vendemiaire ������",
	"Brumaire ����",
	"Frimaire ����",
	"Nivose �ጎ",
	"Pluviose �J��",
	"Ventose ����",
	"Germinal �萶��",
	"Floreal �Ԍ�",
	"Prairial ����",
	"Messidor ���n��",
	"Thermidor �M��",
	"Fructidor ����",
	"Sansculottide(�J���҂̓�)"
};
static char	*fday[] = {
	"��", "�˔\", "�J��", "���_", "��V", "�[��"
};

/* ���ۂɃt�����X�v����g��ꂽ���Ԃ����ł����m�ȗ����������悤�� */
/* ������1��1�����O���S���I��̉��N���������ɑ������邩���Ђ����߂̃e�[ */
/* �u����p�ӂ���                                                       */
static int	_baseDate[] = {
    /* 1792�N9�� */ 22,
    /* 1793�N9�� */ 22,
    /* 1794�N9�� */ 22,
    /* 1795�N9�� */ 23,
    /* 1796�N9�� */ 22,
    /* 1797�N9�� */ 22,
    /* 1798�N9�� */ 22,
    /* 1799�N9�� */ 23,
    /* 1800�N9�� */ 23,
};

/*
 *	change standard time to French-Revolution-Calendar's time
 *
 *	hh:mm:ss     �� fh:fm:fs
 *      1�� = 24����	1�� =  10����
 *	1���� = 60��	1���� = 100��
 *	1��   = 60�b	1��   = 100�b
 */

static char	*
ftime( int hh, int mm, int ss )
{
    long    	fh, fm, fs, tm;
    double	td;
    static char	s[13];

    tm = (hh * 60L + mm) * 60L + ss;
#if	0
    td = ((tm * 1.0) / (24.0 * 60.0 * 60.0)) * (10.0 * 100.0 * 100.0);
#else
    td = tm * 125.0 / 108.0;
#endif
    tm = (long)floor( td );
    fs = tm % 100L;
    fm = ((tm - fs) / 100L) % 100L;
    fh = ((tm - fm * 100L - fs) / 100L) / 100L;

    sprintf( s, "%2ld��%2ld��%2ld�b", fh, fm, fs );

    return ( s );
}


char	*
fdate( long g, int dd, int mm, int yy, int HH, int MM, int SS,
       int printTime, int htmlMode )
{
    static char buf[60];
    long        gg, baseDate, fg;
    int         fy, fm, fd;

    gg = absoluteFromGregorian( _baseDate[0], 9, baseYear );
    if ( g < gg )	/* �t�����X�v������{�ȑO */
        return ( "�܂����{����Ă��܂���" );

    gg = absoluteFromGregorian( _baseDate[1800 - baseYear], 9, 1800 );
    if ( g < gg )
        baseDate = absoluteFromGregorian( _baseDate[yy - baseYear], 9, yy );
    else
        baseDate = midAutumnDay( yy ); /* �V�N�͏H���̓�����n�܂� */
    if ( g >= baseDate ) {
        fy = yy - baseYear + 1;
        fg = g - baseDate;
    }
    else {
        fy = yy - baseYear;
        if ( g < gg )
            fg = g - absoluteFromGregorian(_baseDate[yy-1 - baseYear],
                                           9, yy-1 );
        else
            fg = g - midAutumnDay( yy - 1 );
    }
    fm = (int)(fg / 30L);
    fd = (int)(fg % 30L) + 1;
    if ( fm == 12 ) {
        fd--;
        sprintf( buf, "���a�� %d�N %s %s",
                 fy, fmonth[fm], fday[fd] );
    }
    else
        sprintf( buf, "���a�� %d�N%2d��(%s)%2d��",
                 fy, fm + 1, fmonth[fm], fd );

	if ( printTime == ON ) {
		int	len = strlen( buf );

        sprintf( &buf[len], "%s%s",
                 htmlMode == ON ? "<BR>" : " ",
                 ftime( HH, MM, SS ) );
	}

    return ( buf );
}

