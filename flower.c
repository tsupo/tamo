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
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.70  2003/04/16  05:56:37  tsujimura543
 * データファイルを一定の規則にしたがって探索しオープンするようにした
 *
 * Revision 1.69  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.68  2003/03/14  09:37:59  tsujimura543
 * 関数を整理
 *
 * Revision 1.67  2003/03/11  12:13:53  tsujimura543
 * コメントを整理
 *
 * Revision 1.66  2003/03/11  02:12:35  tsujimura543
 * 誕生月・誕生日の花、花言葉のみに機能を絞る
 *
 * Revision 1.65  2003/02/21  10:53:35  tsujimura543
 * K&RなCでコンパイルできなくなっていたのを、再びコンパイルできるように修正
 *
 * Revision 1.64  2003/02/10  07:25:58  tsujimura543
 * イベント情報表示処理を修正
 *
 * Revision 1.63  2003/02/10  04:23:14  tsujimura543
 * 将来に備えて、各関数を再入可能にする
 *
 * Revision 1.62  2003/02/06  04:02:42  tsujimura543
 * today の誕生日データファイル(birthday.tbl)に対応
 *
 * Revision 1.61  2001/06/13  13:24:23  tsujimura543
 * 「昨日」、「明日」表示対応
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.54  2001/02/19  22:15:28  tsujimura543
 * 誕生花の算出関数に、誕生月の花、誕生石を表示するための機能を追加
 * 
 * Revision 1.53  2001/02/02  16:05:33  tsujimura543
 * 誕生花、キャンペーン(XX週間、XX月間など)の各算出関数を追加
 * 
 * Revision 1.52  2000/08/23  11:01:18  tsujimura543
 * コミック新刊情報の格納されているファイル形式を現時点の fj.rec.comics で流
 * 通しているものに合わせた。また、ファイル中の漢字コードが JIS のままでも処
 * 理できるようにした
 * 
 * Revision 1.51  1999/07/06  18:52:13  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1996/12/13  17:17:06  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.10  95/12/03 11:42:10  tsujimura
 * コメントの整理・修正
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


/* データファイル名 */
static char	*flowerTblFile  = "tbl/flower.tbl";


/* 誕生石 */
static char	*birthStone[12] = {
    "ざくろ石",             "紫水晶",       "藍玉、血石",
    "ダイヤモンド",         "エメラルド",   "真珠、月長石",
    "ルビー",               "赤縞瑪瑙",     "サファイア",
    "オパール、トルマリン", "トパーズ",     "トルコ石、ジルコン"
};

/* 誕生月の花 */
static char	*birthFlower[12] = {
    "カーネーション、スノードロップ",
    "スミレ、サクラソウ",
    "キズイセン、スミレ",
    "ヒナギク、スイートピー",
    "サンザシ、スズラン",
    "バラ、スイカズラ",
    "ヒエンソウ、スイレン",
    "グラジオラス、ケシ",
    "アサガオ、シオン",
    "キンセンカ、コスモス",
    "キク",
    "スイセン、セイヨウヒイラギ、ポインセチア"
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
                    printf( "今月の誕生石: %s\n      誕生花: %s\n",
                            birthStone[mm - 1], birthFlower[mm - 1] );
                    printf( "今日の誕生花: %s\n      花言葉: 『%s』\n",
                            p, q );
                }
            }
        }
    }
}

