/*
 *  persian.c                tsupo@na.rim.or.jp
 *      ペルシャ暦算出プログラム    12 October 2012
 *  Copyright (c) 2012 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: persian.c $
 * Revision 1.1  2012/10/12  09:03:50  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef  TAMO
# include "tamo.h"
# include "tamo_dates.h"
#else
# include "dates.h"
#endif

#ifndef lint
static char     *rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/persian.c 1.1 2012/10/12 09:03:50 tsujimura543 Exp tsujimura543 $";
#endif

// ペルシャ暦 (イラン暦、アフガニスタン暦)
//   epoch はユリウス暦622年3月19日 [ヒジュラの年の春分の日]
//   (西暦622年が紀元なのはヒジュラ紀元(イスラム暦)と共通。ただし、ヒジュラ暦とは違って
//    ペルシャ暦は太陽暦。1年は12ヶ月)
//   第1月～第6月は31日、第12月は29日(平年)または30日(閏年)、それ以外の月は30日
//   新年は春分点通過の瞬間
//   閏年は現在は128年に31回。以前は33年に8回。初期は120年に1回
//     閏年の配置方法 (「128年に31回」を21回と「132年に32回」を1回の組み合わせ)
//      (1) 128年を 29年 + 33年 + 33年 + 33年 の4つの固まり(小サイクル)に分け、
//          それぞれの小サイクルについて、一定の法則で閏年を割当てる
//        第1小サイクル 29年:  7回
//        第2小サイクル 33年:  8回
//        第3小サイクル 33年:  8回
//        第4小サイクル 33年:  8回
//                合計      : 31回
//      (2) 132年を 29年 + 33年 + 33年 + 37年 の4つの固まり(小サイクル)に分け、
//          それぞれの小サイクルについて、一定の法則で閏年を割当てる
//        第1小サイクル 29年:  7回
//        第2小サイクル 33年:  8回
//        第3小サイクル 33年:  8回
//        第4小サイクル 37年:  9回
//                合計      : 32回
//      (1) の大サイクルを21回繰り返した後、(2) の大サイクルを1回実施する(2820年で1周)
//        第1大サイクル (1年目～128年目)
//          第1小サイクル 29年:  7回
//          第2小サイクル 33年:  8回
//          第3小サイクル 33年:  8回
//          第4小サイクル 33年:  8回
//        第2大サイクル (129年目～256年目)
//          第1小サイクル 29年:  7回
//          第2小サイクル 33年:  8回
//          第3小サイクル 33年:  8回
//          第4小サイクル 33年:  8回
//        …………………………………………
//        第21大サイクル (2560年目～2688年目)
//          第1小サイクル 29年:  7回
//          第2小サイクル 33年:  8回
//          第3小サイクル 33年:  8回
//          第4小サイクル 33年:  8回
//        第22大サイクル (2689年目～2820年目)
//          第1小サイクル 29年:  7回
//          第2小サイクル 33年:  8回
//          第3小サイクル 33年:  8回
//          第4小サイクル 37年:  9回
//      グレゴリオ暦より高精度: 約380万年につき1日しかずれない
//      直近の第1大サイクルの開始は西暦1925年(というか、1925年にこの方式に改暦された。
//      それまでは、単純に「33年に8回」が繰り返される方式(ジャラーリー暦)だった)
//   1975年のパーレビ国王即位から1979年のイラン革命勃発までは、ヒジュラ紀元ではなく
//   キュロス紀元(西暦の紀元前550年がepoch)で運用されていた
//   なお、現在のイランでは、実際には、ペルシャ暦ではなく、紀元をヒジュラ紀元にした
//   グレゴリオ暦(年以外は通常のグレゴリオ暦と完全に一致する)が使用されることが多い

// 参考: http://www.nendai.nagoya-u.ac.jp/oxcal/manual/oxcalhelp/hlp_analysis_calend.html
//       http://www.nendai.nagoya-u.ac.jp/oxcal/manual/oxcalhelp/calendar.js
//       http://www.fourmilab.ch/documents/calendar/

static char *persianMonthName[] =
{
    "Farvardin", "Ordibehesht", "Khordad", "Tir", "Mordad", "Shahrivar",
    "Mehr", "Aban", "Azar", "Dei", "Bahman", "Esfand"
};

static long mod(long a, long b)
{
    return ( (long)(a - (b * floor((a * 1.0) / (b * 1.0)))) );
}

long
AbsoluteFromPersian(int pD, int pM, int pY)
{
    long    g = 0;
    long    epbase = pY - ((pY >= 0) ? 474 : 473);
    long    epyear = 474 + mod(epbase, 2820);

    g = pD + (pM <= 7 ? 31 * (pM - 1) : 31 * 6 + 30 * (pM - 7));
    g += (long)(floor(((epyear * 682.0) - 110.0) / 2816.0) +
                (epyear - 1) * 365 +
                floor(epbase / 2820.0) * 1029983.0);
    g += absoluteFromJulian(19, 3, 622) - 1;

    return ( g );
}

void
persianFromAbsolute(long date, int *d, int *m, int *y)
{
    long    depoch = date - AbsoluteFromPersian(1, 1, 475);
    long    ycycle = 0;
    long    cycle = (long)floor(depoch / 1029983.0);
    long    cyear = mod(depoch, 1029983);
    long    yday = 0;

    if (cyear == 1029982)
        ycycle = 2820;
    else
    {
        long    aux1 = (long)floor(cyear / 366.0);
        long    aux2 = mod(cyear, 366);

        ycycle =
            (long)floor(
                ((2134.0 * aux1) + (2816.0 * aux2) + 2815.0) / 1028522.0) +
            aux1 + 1;
    }

    *y = (int)(ycycle + (2820 * cycle) + 474);
    if (*y <= 0)
        (*y)--;

    yday = (date - AbsoluteFromPersian(1, 1, *y)) + 1;
    *m = (yday <= 186) ? (int)ceil(yday / 31.0)
                       : (int)ceil((yday - 6) / 30.0);
    *d = (int)(date - AbsoluteFromPersian(1, *m, *y)) + 1;
}

char *
persianCalendar(long g, int yyyy, int mm, int dd)
{
    static char dateString[80];
    int         pY = 0, pM = 0, pD = 0;

    if (g < absoluteFromJulian(19, 3, 622))
        return ( NULL );

    persianFromAbsolute(g, &pD, &pM, &pY);
    sprintf( dateString,
             "%4d年%2d月(%s)%2d日", pY, pM, persianMonthName[pM - 1], pD );

    return ( dateString );
}
