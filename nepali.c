/*
 *  nepali.c                tsupo@na.rim.or.jp
 *      ネパール暦算出プログラム    19 February 2003
 *  Copyright (c) 2003 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: nepali.c $
 * Revision 1.19  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.18  2003/10/24  02:41:14  tsujimura543
 * データファイルの置き場所を統一
 *
 * Revision 1.17  2003/06/02  11:23:15  tsujimura543
 * ネパール太陰暦の算出方法、表示方法を修正。インド太陰暦の閏月表示を修正。
 *
 * Revision 1.16  2003/05/30  10:46:40  tsujimura543
 * ネパールの行事、祝祭日の表示を一部対応
 *
 * Revision 1.15  2003/05/26  08:32:30  tsujimura543
 * インド国民暦に関する不具合修正
 *
 * Revision 1.14  2003/05/26  07:49:56  tsujimura543
 * インド国民暦(国家暦)対応、ネパール太陰暦修正
 *
 * Revision 1.13  2003/04/16  05:56:37  tsujimura543
 * データファイルを一定の規則にしたがって探索しオープンするようにした
 *
 * Revision 1.12  2003/04/11  10:58:56  tsujimura543
 * (1) インド太陰暦表示の月名に何番目の月かを併記するようにした
 * (2) ネパール太陰暦表示を追加 (暫定)
 *
 * Revision 1.11  2003/04/04  08:45:38  tsujimura543
 * インド太陰暦の「年」表示を西暦表示から本来のインド暦表示にした
 *
 * Revision 1.10  2003/03/31  11:22:59  tsujimura543
 * コメントを追加
 *
 * Revision 1.9  2003/03/20  01:36:51  tsujimura543
 * コメントを追加
 *
 * Revision 1.8  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.7  2003/03/11  02:03:24  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.6  2003/03/04  06:03:32  tsujimura543
 * インド太陰暦の閏月対応
 *
 * Revision 1.5  2003/03/03  07:48:25  tsujimura543
 * インド太陰暦対応
 *
 * Revision 1.4  2003/02/24  10:48:05  tsujimura543
 * ネパール暦の時分秒表記に対応
 *
 * Revision 1.3  2003/02/19  09:00:33  tsujimura543
 * BS紀元以前かどうかのチェック処理の不具合を修正
 *
 * Revision 1.2  2003/02/19  08:09:15  tsujimura543
 * BS2061年1月1日がBS2060年13月1日になってしまう不具合を修正
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

#define NEPALICYCLE (27 + 27 + 27 + 27 + 27 + 4)    /* 周期 */
    /* 「27年周期が5つ続いた後、4年の固まりが1つ続く」パターンを繰り返す */

static long nepaliDays[12] = {
    30, 31, 31, 31, 31, 30, 29, 29, 29, 29, 29, 30
};

static long nepaliMonthPattern[13][12] = {
    /* 第1グループ */
    /*  パターン K */   { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, /*  0 */
    /*  パターン A */   { 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, /*  1 */
    /*  パターン F */   { 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, /*  2 */
    /*  パターン I */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 }, /*  3 */

    /* 第2グループ */
    /*  パターン B */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1 }, /*  4 */
    /*  パターン G */   { 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 }, /*  5 */

    /* 第3グループ */
    /*  パターン H */   { 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 }, /*  6 */
    /*  パターン E */   { 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 }, /*  7 */
    /*  パターン C */   { 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1 }, /*  8 */
    /*  パターン N */   { 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /*  9 */
    /*  パターン M */   { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 10 */
    /*  パターン J */   { 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 }, /* 11 */

    /* 第4グループ */
    /*  パターン D */   { 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0 }  /* 12 */
};

static long nepaliYearPattern[NEPALICYCLE] = {
    /* 最初の27年                          */
    /*   ABMD ABCD ABED FBHD IGHD IGDD BJD */
     1 /* A */,  4 /* B */, 10 /* M */, 12 /* D */,
     1 /* A */,  4 /* B */,  8 /* C */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
                 4 /* B */, 11 /* J */, 12 /* D */,

    /* 2番目の27年                         */
    /*   ABMD ABCD ABED ABHD IGHD IGDD BJD */
     1 /* A */,  4 /* B */, 10 /* M */, 12 /* D */,
     1 /* A */,  4 /* B */,  8 /* C */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
                 4 /* B */, 11 /* J */, 12 /* D */,

    /* 3番目の27年                         */
    /*   ABJD ABND ABED ABED FGHD IGDD IGD */
     1 /* A */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* 4番目の27年                         */
    /*   KBJD ABND ABED ABED FBHD IGDD IGD */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* 5番目の27年                         */
    /*   KBJD ABND ABED ABED FBHD IGHD IGD */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */,
     1 /* A */,  4 /* B */,  9 /* N */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     1 /* A */,  4 /* B */,  7 /* E */, 12 /* D */,
     2 /* F */,  4 /* B */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */,  6 /* H */, 12 /* D */,
     3 /* I */,  5 /* G */, 12 /* D */,

    /* 最後の4年                           */
    /*   KBJD                              */
     0 /* K */,  4 /* B */, 11 /* J */, 12 /* D */
    /*           ~~~~~~~~~~                          */
    /*            ↑ この列に並んでいる年が366日の年 */
    /*               それ以外は365日の年             */
};

/* Bikram Sambat 2053年 Baishak月 1日 は 西暦 1996年4月13日         */
/* 本プログラムでは、簡単のため、Bikram Sambat 2060年 Baishak月 1日 */
/* (=2003年4月14日) を基準日とする                                  */



/* 指定したネパール暦の「年」の1年間の日数を求める */
long
nepDaysOfYear( int yy ) /* yy: ネパール暦の「年」 */
{
    int pattern = (yy + 25) % NEPALICYCLE;
    int days    = 365;

    if ( (nepaliYearPattern[pattern] == 4) ||
         (nepaliYearPattern[pattern] == 5)    ) {
        /* パターンB または パターンG の年のみ 366日 */
        days++;
    }

    return ( days );
}


/* ユリウス日から対応するネパール暦の年月日を求める                        */
/*   (1) 時分秒[ネパール現地時間]                                          */
/*        日本時間との時差は -3時間15分, GMT との時差は +5時間45分         */
/*   (2) 祝祭日の表示は将来対応                                            */
/*        ・西暦の年月日に基づく祝祭日は dd, mm, yy より決定               */
/*        ・ネパール暦(太陽暦)に基づく祝祭日は nY, nM, nD により決定       */
/*        ・太陰暦(tithi)に基づく祝祭日は、別途、太陰暦を算出する必要あり  */
char    *
nepdate(long g, int dd, int mm, int yy, int HH, int MM, int SS, int printTime)
{
    static char buf[BUFSIZ];
    int         nY, nM = 1, nD = 1, nHH, nMM, nSS;
    long        base, d, _d;
    long        pattern;

    if ( yy <= -57 ) {
        return ( "Bikram Sambat 元年 よりも過去の暦はサポートしていません" );
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

    /* まず、ネパール暦の「年」を求める */
    base = absoluteFromGregorian( 14, 4, 2003 );
    d    = base;
    if ( g >= base ) {
        /* 基準日より未来の日付の場合 */
        for ( nY = 2060; ; nY++ ) {
            _d = nepDaysOfYear( nY );
            if ( d + _d > g ) {
                break;
            }
            d += _d;
        }
    }
    else {
        /* 基準日より過去の日付の場合 */
        for ( nY = 2059; ; nY-- ) {
            _d = nepDaysOfYear( nY );
            d -= _d;
            if ( d <= g ) {
                break;
            }
        }
    }
    pattern = (nY + 25) % NEPALICYCLE;

    /* 「月」を求める */
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

    /* 「日」を求める */
    nD = g - d + 1;

    if ( printTime == ON ) {
        sprintf( buf, "%4d年%2d月(%s)%2d日 %2d時%2d分%2d秒",
                 nY, nM, nepaliMonthName[(nM + 11) % 12], nD,
                 nHH, nMM, nSS );
    }
    else {
        sprintf( buf, "%4d年%2d月(%s)%2d日",
                 nY, nM, nepaliMonthName[(nM + 11) % 12], nD );
    }

#ifdef  TAMO
    if ( (mm == 3) && (dd > 1) && isFullMoonDay( yy, mm, dd ) )
        strcat( buf, "*ホーリー満月" );
    if ( (nM == 1) && (nD == 1) )
        strcat( buf, "*新年*ビスケート祭" );
    if ( (nM == 12) &&
         (nD == nepaliDays[nM - 1] +
                nepaliMonthPattern[nepaliYearPattern[pattern]][nM - 1]) )
        strcat( buf, "*大晦日*ビスケート祭(柱建立)" );
    if ( (mm == 11) && (dd == 8) )  /* 西暦 11月8日 */
        strcat( buf, "*憲法記念日" );
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
                sprintf( buf, "閏%2d月(%s)", i + 1, monthName );
            else
                sprintf( buf, "%2d月(%s)",   i + 1, monthName );
            break;
        }
    }

    return ( buf );
}


#define WHITE   0
#define BLACK   1

char    *
nepaliLunarMonth( char *monthName,
                  int year, int month,  /* 西暦年月 */
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
                sprintf( buf, "%4d年閏%2d月(Adhik %s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            else if ( nij )
                sprintf( buf, "%4d年%2d月(Nij %s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            else
                sprintf( buf, "%4d年%2d月(%s)",
                         year,
                         (j % 12) + 1,
                         nepaliMonthName[j % 12] );
            break;
        }
    }

    return ( buf );
}


/*
 *  インド太陰暦(tithi)
 *      新月(朔)になった瞬間が白の1日で、以後、月が満ちていくにつれ、
 *      白の2日、3日、...、15日となる。また、月が欠けていくにつれ、
 *      黒の1日、2日、...、15日となる。インド太陰暦の1日は、新月から
 *      次の新月までの月の位相を0度から360度としたとき、360/30 = 12度
 *      増える時間であり、1日の長さは一定していない(24時間より短い
 *      ときもあれば、長いときもある)。したがって、日付変更のタイミ
 *      ングは、月の満ち欠けの状況に依存する(他の暦と違い、日付変更
 *      のタイミングは、地球上のどの位置でも同じになる[時差がない])。
 *      基本的に、南アジアから東南アジアで使われる太陰暦は tithi で
 *      あるが、白の1日が月初となる地域が多い中、ネパールでは黒の1日
 *      が月初となるなど、微妙に地域によって運用方法が異なる。インド
 *      国内では、Chaitra の白の1日、Chaitra の黒の1日、Kartik の白の
 *      1日、Kartik の黒の1日のそれぞれが年初となる方式が各地域に共存
 *      している。
 *      本プログラムでは、Chaitra の白の1日を年初とする暦を表示する。
 *
 *      tithi.txt に 西暦2001年12月15日～2012年1月22日の tithi の日
 *      付変更タイミングを掲載する。この tithi.txt は、
 *
 *          Tithi Timer v.01 March 2002 (β版)
 *            by Michael W. Taft   http://www.jyotish.net/
 *              (http://www.jyotish.net/tithi_timer_download.htm)
 *
 *      による出力結果を元に作成したものである。indianLunarDate() は
 *      tithi.txt を元に、tithi の日付を決定する。
 *
 *      西暦2003年4月3日がインド太陰暦1925年1月(Chaitra)白の1日、
 *                        インド太陽暦1925年1月(Chaitra)13日
 *      に相当する。
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
					/* 閏月対応 */
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

                sprintf( dateString, "%4d年%s %sの%2d日 %s",
                         indianYear( yy, mm, preMonthName ),
                         indianMonth( preMonthName ),
                         strstr( s, "Shukla" ) != NULL ? "白" : "黒",
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
 *  ネパール太陰暦
 *      インド太陰暦(tithi)を元にネパール太陰暦を求める。
 *      Baishak月の黒の1日が年初となる。
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
					/* 閏月対応 */
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

                sprintf( dateString, "%s %sの%2d日",
                         nepaliLunarMonth( preMonthName,
                                           yy, mm,
                                           strstr( s, "Shukla" ) != NULL
                                                ? WHITE
                                                : BLACK
                                         ),
                         strstr( s, "Shukla" ) != NULL ? "白" : "黒",
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
 * インド国家暦(国民暦) Indian National Calendar
 *   Saka紀元の暦を元に、インド政府が1957年に制定。
 *   世間一般では、あまり使われていないらしい。
 *
 *    参考: http://www.indianastrology.com/learn/calander.asp
 *      インド国家暦
 *        太陽に基づいた暦。1年は太陽が雄羊座に入るときに始まる。
 *        1957年3月22日からインド政府により使用開始。1957年3月22日は
 *        Saka紀元1879年 Chaitra 月第1日に対応。各月の開始日を以下の
 *        ように割り当てる。
 *
 *          月名       日数 開始日
 *          Chaitra    30日 グレゴリオ暦の 3月22日
 *                      (ただし、グレゴリオ暦の閏年にあたる年は日数を
 *                       31日とし、開始日をグレゴリオ暦の3月21日とする)
 *          Vaisakha   31日 グレゴリオ暦の 4月21日
 *          Jyaistha   31日 グレゴリオ暦の 5月22日
 *          Asadha     31日 グレゴリオ暦の 6月22日
 *          Sravana    31日 グレゴリオ暦の 7月23日
 *          Bhadra     31日 グレゴリオ暦の 8月23日
 *          Asvina     30日 グレゴリオ暦の 9月23日
 *          Kartika    30日 グレゴリオ暦の10月23日
 *          Agrahayana 30日 グレゴリオ暦の11月22日
 *          Pausa      30日 グレゴリオ暦の12月22日
 *          Magha      30日 グレゴリオ暦の 1月21日
 *          Phalgun    30日 グレゴリオ暦の 2月20日
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

    sprintf( dateString, "%4d年%2d月(%s)%2d日", iyy, imm + 1, indianMonthName[imm], idd );

    return ( dateString );
}
