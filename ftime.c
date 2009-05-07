/*
 *  ftime.c             tsupo@na.rim.or.jp
 *      フランス革命暦算出プログラム    2 December 1995
 *  Copyright (c) 1995,1996,1999, 2001, 2003, 2007 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: ftime.c $
 * Revision 1.70  2007/02/06  10:54:43  tsujimura543
 * copyright 表記をアップデート
 *
 * Revision 1.69  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.68  2003/03/31  11:23:24  tsujimura543
 * 出力処理を小型化
 *
 * Revision 1.67  2003/03/31  05:48:05  tsujimura543
 * irint() を完全に floor() に置き換えた
 *
 * Revision 1.66  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.65  2003/03/12  10:18:22  tsujimura543
 * HTML出力時のフランス革命暦の出力形式を変更
 *
 * Revision 1.64  2003/03/12  10:05:31  tsujimura543
 * 活動メモ対応準備 #2
 *
 * Revision 1.63  2003/03/11  02:22:57  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.62  2003/02/21  05:05:20  tsujimura543
 * フランス革命暦の時刻表示をON/OFFできるようにした
 *
 * Revision 1.61  2003/02/07  04:44:43  tsujimura543
 * フランス革命暦の月の名前をカタカナ表示から英語での表記に変更
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.51  1999/07/13  12:01:40  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1996/08/19  02:10:14  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.3  95/12/16 05:42:48  tsujimura
 * フランス革命暦実施時期(17920923-17991110(?))の暦日を正確に
 * 算出するためのテーブルを導入
 * 
 * Revision 1.2  95/12/02 20:36:26  tsujimura
 * RCS用ident文字列埋めこみ
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

static int	baseYear = 1792;	/* 1792年9月22日が共和国1年葡萄月1日 */
static char	*fmonth[]	= {
	"Vendemiaire 葡萄月",
	"Brumaire 霧月",
	"Frimaire 霜月",
	"Nivose 雪月",
	"Pluviose 雨月",
	"Ventose 風月",
	"Germinal 芽生月",
	"Floreal 花月",
	"Prairial 草月",
	"Messidor 収穫月",
	"Thermidor 熱月",
	"Fructidor 実月",
	"Sansculottide(労働者の日)"
};
static char	*fday[] = {
	"徳", "才能", "労働", "言論", "報酬", "閏日"
};

/* 実際にフランス革命暦が使われた期間だけでも正確な暦日が得られるように */
/* 葡萄月1月1日がグレゴリオ暦の何年何月何日に相当するかをひくためのテー */
/* ブルを用意する                                                       */
static int	_baseDate[] = {
    /* 1792年9月 */ 22,
    /* 1793年9月 */ 22,
    /* 1794年9月 */ 22,
    /* 1795年9月 */ 23,
    /* 1796年9月 */ 22,
    /* 1797年9月 */ 22,
    /* 1798年9月 */ 22,
    /* 1799年9月 */ 23,
    /* 1800年9月 */ 23,
};

/*
 *	change standard time to French-Revolution-Calendar's time
 *
 *	hh:mm:ss     → fh:fm:fs
 *      1日 = 24時間	1日 =  10時間
 *	1時間 = 60分	1時間 = 100分
 *	1分   = 60秒	1分   = 100秒
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

    sprintf( s, "%2ld時%2ld分%2ld秒", fh, fm, fs );

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
    if ( g < gg )	/* フランス革命暦実施以前 */
        return ( "まだ実施されていません" );

    gg = absoluteFromGregorian( _baseDate[1800 - baseYear], 9, 1800 );
    if ( g < gg )
        baseDate = absoluteFromGregorian( _baseDate[yy - baseYear], 9, yy );
    else
        baseDate = midAutumnDay( yy ); /* 新年は秋分の日から始まる */
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
        sprintf( buf, "共和国 %d年 %s %s",
                 fy, fmonth[fm], fday[fd] );
    }
    else
        sprintf( buf, "共和国 %d年%2d月(%s)%2d日",
                 fy, fm + 1, fmonth[fm], fd );

	if ( printTime == ON ) {
		int	len = strlen( buf );

        sprintf( &buf[len], "%s%s",
                 htmlMode == ON ? "<BR>" : " ",
                 ftime( HH, MM, SS ) );
	}

    return ( buf );
}

