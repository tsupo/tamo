/*
 *  coptic.c				tsupo@na.rim.or.jp
 *      エチオピア暦算出プログラム    2 April 2003
 *  Copyright (c) 2003 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: coptic.c $
 * Revision 1.2  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
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
 * コプト暦(エチオピア暦)
 *   30日の月が12続いた後、5日(閏年のときは6日)の月が1つで1年を構成。
 *   現在は、閏年は西暦(グレゴリオ暦)に合わせている。
 *   (かつては、ユリウス暦と同様、4で割り切れる年を閏年とし、900年に2回
 *    補正を行う方法を採用していたらしい)
 */

static char     *coptMonthName[] = {
  "Meskerem",   /*  1月 (マスカラム)   エジプト表記: Thuout             */
  "Tikemet",    /*  2月 (テケムト)     エジプト表記: Paopi              */
  "Hidar",      /*  3月 (ヘダル)       エジプト表記: Athor              */
  "Tahesas",    /*  4月 (ターサス)     エジプト表記: Khoiak             */
  "Tir",        /*  5月 (テル)         エジプト表記: Tobi               */
  "Yekatit",    /*  6月 (イェカティト) エジプト表記: Mekhir             */
  "Megabit",    /*  7月 (メガビト)     エジプト表記: Fameno / Baramhat  */
  "Miyaza",     /*  8月 (ミアジア)     エジプト表記: Farmou / Baramouda */
  "Ginbot",     /*  9月 (グエンボト)   エジプト表記: Pakhon             */
  "Sene",       /* 10月 (セネ)         エジプト表記: Paony              */
  "Hamle",      /* 11月 (ハムレ)       エジプト表記: Epep               */
  "Nehase",     /* 12月 (ネハッセ)     エジプト表記: Mesori             */
  "Paguemen",   /* 13月 (パゴウメン)   エジプト表記: Nasie              */
  NULL
};

static int      coptDays[] = {
    30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5
};

/*
 *	グレゴリオ暦2002年9月11日がエチオピア暦1995年1月1日に相当する
 */

int
copDaysOfYear( int cY )
{
    int     y = cY - 1995 + 2003 + 1;   /* 最後の + 1 は 閏年を when.exe に
                                           合わせるための補正               */
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
        return ( "その時期のエチオピア暦はサポートしていません" );
    }

    /* まず、エチオピア暦の「年」を求める */
    base = absoluteFromGregorian( 11, 9, 2002 );
    d    = base;
    if ( g >= base ) {
        /* 基準日より未来の日付の場合 */
        for ( cY = 1995; ; cY++ ) {
            _d = copDaysOfYear( cY );
            if ( d + _d > g ) {
                break;
            }
            d += _d;
        }
    }
    else {
        /* 基準日より過去の日付の場合 */
        for ( cY = 1994; ; cY-- ) {
            _d = copDaysOfYear( cY );
            d -= _d;
            if ( d <= g ) {
                break;
            }
        }
    }

    /* 「月」を求める */
    cM = cD = _d = 1;
    do {
        _d = coptDays[cM - 1];
        if ( _d >= g - d + 1 ) {
            break;
        }
        cM++;
        d += _d;
    } while ( cM <= 12 );

    /* 「日」を求める */
    cD = g - d + 1;

    sprintf( buf, "%4d年%2d月(%s)%2d日",
             cY, cM, coptMonthName[cM - 1], cD );

    return ( buf );
}

