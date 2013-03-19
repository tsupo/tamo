/*
 *  bahai.c                  tsupo@na.rim.or.jp
 *      バハイ暦暦算出プログラム    12 October 2012
 *  Copyright (c) 2012 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: bahai.c $
 * Revision 1.2  2012/10/12  10:35:13  tsujimura543
 * 余分なコメントを削除
 *
 * Revision 1.1  2012/10/12  10:34:20  tsujimura543
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
    "$Header: C:/user/local/src/tamo/RCS/bahai.c 1.2 2012/10/12 10:35:13 tsujimura543 Exp tsujimura543 $";
#endif

// バハイ暦
//   1年の始まりは春分の日(グレゴリオ暦の3月21日固定)
//   1年は19ヶ月、1ヶ月は19日
//   第18月と第19月の間に閏日として4日(平年)または5日(閏年)を加える
//   epoch はグレゴリオ暦1844年3月21日
//   グレゴリオ暦2月29日を含むバハイ年が閏年
//     例: グレゴリオ暦2012年2月29日を含むバハイ168年は閏年

static char *bahaiYearName[] =
{
    "Alif", "Ba'", "Ab", "Dal", "Bab", "Vav",
    "Abad", "Jad", "Baha", "Hubb", "Bahhaj", "Javab",
    "Ahad", "Vahhab", "Vidad", "Badi'", "Bahi", "Abha",
    "Vahid"
};

static char *bahaiMonthName[] =
{
    "Baha",         //  1月
    "Jalal",        //  2月
    "Jamal",        //  3月
    "`Azamat",      //  4月
    "Nur",          //  5月
    "Rahmat",       //  6月
    "Kalimat",      //  7月
    "Kamal",        //  8月
    "Asma'",        //  9月
    "`Izzat",       // 10月
    "Mashiyyat",    // 11月
    "`Ilm",         // 12月
    "Qudrat",       // 13月
    "Qawl",         // 14月
    "Masail",       // 15月
    "Sharaf",       // 16月
    "Sultan",       // 17月
    "Mulk",         // 18月
    "Ayyam-i-Ha",   // 閏日 (フランス革命暦の「労働者の日」的な調整用の日)
    "`Ala'"         // 19月
};

static char *bahaiDayName[] =
{
    "Baha", "Jalal", "Jamal", "`Azamat", "Nur", "Rahmat",
    "Kalimat", "Kamal", "Asma'", "`Izzat", "Mashiyyat", "`Ilm",
    "Qudrat", "Qawl", "Masail", "Sharaf", "Sultan", "Mulk",
    "`Ala'"
};


void
bahaiFromAbsolute(long date, int *d, int *m, int *y)
{
    long epoch = absoluteFromGregorian(21, 3, 1844);
    if (date >= epoch)
    {
        int     yy = 0, mm = 0, dd = 0;
        long    ddd = 0, days = 0;
        BOOL    isBahaiLeepYear = FALSE;

        gregorianFromAbsolute( date, &dd, &mm, &yy );

        *y = yy - 1844 + ((mm > 3) || ((mm == 3) && (dd >= 21)) ? 1 : 0);

        isBahaiLeepYear = (*y == 1) ? FALSE :
                          (mm > 3) || ((mm == 3) && (dd >= 21))
                                    ? leapyear(yy + 1)
                                    : leapyear(yy);
        ddd = date - absoluteFromGregorian(
                            21, 3,
                            (mm > 3) || ((mm == 3) && (dd >= 21))
                                ? yy
                                : yy - 1);
        days = isBahaiLeepYear ? 366 : 365;

        if (ddd >= days - 19)
        {   // 19月
            *m = 20;
            *d = (int)(ddd - (days - 19)) + 1; 
        }
        else if (ddd >= 19 * 18)
        {   // 閏日
            *m = 19;
            *d = (int)(ddd - 19 * 18) + 1;
        }
        else
        {   // 1月～18月
            *m = (int)(ddd / 19) + 1;
            *d = (int)(ddd % 19) + 1;
        }
    }
}

long
absoluteFromBahai( int bD, int bM, int bY )
{
    int     year = bY + (1844 - 1);
    long    g = absoluteFromGregorian(21, 3, year) - 1;

    if (bM <= 18)
        g += (bM - 1) * 19 + bD;
    else if (bM == 19)
        g += 19 * 18 + bD;
    else
        g += 19 * 18 + (leapyear(year + 1) ? 5 : 4) + bD;

    return ( g );
}

char    *
bahaiCalendar(long date, int yy, int mm, int dd, int *bY, int *bM, int *bD)
{
    static char dateString[80];

    if (date < absoluteFromGregorian(21, 3, 1844))
        return ( NULL );

    *bY = 0;
    *bM = 0;
    *bD = 0;
    bahaiFromAbsolute( date, bD, bM, bY );

    if ( *bM == 19 )
        sprintf( dateString, "%4d年閏%2d日", *bY, *bD );
    else
        sprintf( dateString, "%4d年%2d月%2d日",
                 *bY, *bM > 19 ? *bM - 1 : *bM, *bD );

    return ( dateString );
}

int
checkBahai( char *buf,
            int bD, int bM, int bY, /* Bahai date   */
            int dd, int mm, int yy, /* Gregorian date */
            int htmlMode )
{
    int         reset  = 1;
    static char *ord[] =
    {
        "First", "Second", "Third", "Fourth", "Fifth",
        "Sixth", "Seventh", "Eighth", "Ninth", "Tenth",
        "Eleventh", "Twelfth"
    };

    buf[0] = NUL;

    if (bM != 19)
        tsprintf( buf, htmlMode, &reset,
                  " (%s の年 %s の月 %s の日)",
                  bahaiYearName[(bY - 1) % 19],
                  bahaiMonthName[(bM - 1) % 20],
                  bahaiDayName[bD - 1] );
    else
        tsprintf( buf, htmlMode, &reset,
                  " (%s の年 %s の %s の日)",
                  bahaiYearName[(bY - 1) % 19],
                  bahaiMonthName[(bM - 1) % 20],
                  bahaiDayName[bD - 1] );

    if (bM == 1 && bD == 1)
        tsprintf( buf, htmlMode, &reset,
                  "  Baha'i New Year (Naw-Ruz) %d", bY );
    if (bM == 20)
        tsprintf( buf, htmlMode, &reset, "  断食月");

    if (mm == 4)
        if (dd >= 21)
            tsprintf( buf, htmlMode, &reset,
                      "  %s Day of Ridvan", ord[dd - 21] );

    if (mm == 5) {
        if (dd <= 2)
            tsprintf( buf, htmlMode, &reset,
                      "  %s Day of Ridvan", ord[dd + 9] );
        if (dd == 23)
            tsprintf( buf, htmlMode, &reset, "  Declaration of the Bab" );
        if (dd == 29)
            tsprintf( buf, htmlMode, &reset, "  Ascension of Baha'u'llah" );
    }

    if (mm == 7)
        if (dd == 9)
            tsprintf( buf, htmlMode, &reset, "  Martyrdom of the Bab" );

    if (mm == 10)
        if (dd == 20)
            tsprintf( buf, htmlMode, &reset, "  Birth of the Bab" );

    if (mm == 11) {
        if (dd == 12)
            tsprintf( buf, htmlMode, &reset, "  Birth of Baha'u'llah" );
        if (dd == 26)
            tsprintf( buf, htmlMode, &reset, "  Day of the Covenant" );
        if (dd == 28)
            tsprintf( buf, htmlMode, &reset, "  Ascension of `Abdu'l-Baha" );
    }

    return ( (buf[0] != '\0') ? 1 : 0 );
}
