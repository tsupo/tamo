/*
 *  maya.c              tsupo@na.rim.or.jp
 *      マヤ暦算出プログラム    24 February 1991
 *  Copyright (c) 1991-1995,1996,1999, 2001, 2003, 2007 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: maya.c $
 * Revision 1.63  2007/02/06  10:55:29  tsujimura543
 * copyright 表記をアップデート
 *
 * Revision 1.62  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.61  2003/03/11  02:22:57  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.51  1999/07/06  19:42:48  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1996/08/19  12:01:10  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.5  95/12/03 11:46:34  tsujimura
 * コメントの整理・修正
 * 
 * Revision 1.4  91/03/02 05:59:36  tsujimura
 * test release
 * 
 * Revision 1.3  91/03/02 05:59:36  tsujimura
 * test version
 * 
 * Revision 1.2  91/03/02 05:59:36  tsujimura
 * changed the date of base for calculating Maya-calendar
 * 
 * Revision 1.1  91/03/02 05:59:36  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXKETA	20
#ifndef	NUL
#define	NUL	'\0'
#endif

#ifndef	lint
static char	*rcs_id =
	"$Header: C:/user/local/src/tamo/RCS/maya.c 1.63 2007/02/06 10:55:29 tsujimura543 Exp tsujimura543 $";
#endif

static char	*tsolkin[] = {
	"イミシ", "イク", "アクバル", "カン", "チッチャン", "キミ", "マニク",
	"ラマト", "ムルク", "オク", "チュエン", "エブ", "ベン", "イシ", "メン",
	"キブ", "カバン", "エツナブ", "カワク", "アハウ" };

static char	*haabu[] = {
	"ポップ", "ウオ", "シップ", "ソツ", "ツェク", "シュル", "ヤシキン",
	"モル", "チェン", "ヤシ", "サク", "ケ", "マク", "カンキン", "ムアン",
	"パシ", "カヤブ", "クムフ", "ワエィブ" };


char	*
ten2twenty( long i )
{
	static char buf[BUFSIZ];
	char        tmp[4];
	long        num[MAXKETA];
	int         j = 0;

	while ( i >= 20 ) {
		num[ j++ ] = i % 20;
		i /= 20;
	}
	num[ j++ ] = i;

	buf[ 0 ] = NUL;
	while ( j-- ) {
		sprintf( tmp, "%ld.", num[ j ] );
		strcat( buf, tmp );
	}
	buf[ strlen( buf ) - 1 ] = NUL;

	return ( buf );
}


long
twenty2ten( const char *s )
{
	long    i = 0, j = 0;
	char    tmp[4];

	tmp[0] = NUL;
	while ( *s ) {
		if ( *s == '.' ) {
			tmp[j] = NUL;
			i = i * 20 + atol( tmp );
			j = 0; tmp[0] = NUL; s++;
			continue;
		}
		tmp[j++] = *s++;
	}
	tmp[j] = NUL;
	i = i * 20 + atol( tmp );

	return ( i );
}


char	*
ten2twentyForCal( long i )
{
	static char buf[BUFSIZ];
	char        tmp[5];
	long        num[MAXKETA];
	long        mod[2];
	int         j = 0;

	mod[0] = 20; mod[1] = 18;

	while ( ( j < 2 ) && ( i >= mod[j] ) ) {
		num[j] = i % mod[j];
		i /= mod[j]; j++;
	}
	while ( i >= 20 ) {
		num[ j++ ] = i % 20;
		i /= 20;
	}
	num[ j++ ] = i;
	while ( j < 5 )
		num[ j++ ] = 0;

	buf[ 0 ] = NUL;
	while ( j-- ) {
		sprintf( tmp, "%ld.", num[ j ] );
		strcat( buf, tmp );
	}
	buf[ strlen( buf ) - 1 ] = NUL;

	return ( buf );
}


long
twenty2tenForCal( const char *s )
{
	long    l = 0;
	int     i = 0, j = 0;
	long    num[MAXKETA], mod[2];
	char    tmp[4];

	mod[0] = 18; mod[1] = 20;

	tmp[0] = NUL;
	while ( *s ) {
		if ( *s == '.' ) {
			tmp[j] = NUL;
			num[i++] = atol( tmp );
			j = 0; tmp[0] = 0; s++;
			continue;
		}
		tmp[j++] = *s++;
	}
	tmp[j] = NUL;
	num[i++] = atol( tmp );

	j = 0;
	while ( j < i - 2 ) {
		l = l * 20 + num[j++];
	}
	while ( j < i ) {
		l = l * mod[2-(i-j)] + num[j++];
	}

	return ( l );
}


char	*
mayaFromAbsolute( long date )
{
	return ( ten2twentyForCal( date + 1137142L ) );
}


long
absoluteFromMaya( const char *s )
{
	return ( twenty2tenForCal( s ) - 1137142L );
}


char	*
tsolkinFromAbsolute( long date )
{
    static char buf[16];

    while ( date - 4 < 0 )
        date += 13 * 20;
    sprintf( buf, "%2ld%s", (date-4) % 13 + 1, tsolkin[(date+1) % 20] );
    return ( buf );
}


char	*
haabuFromAbsolute( long date )
{
    static char buf[16];

    while ( date + 150 < 0 )
        date += 20 * 365;
    date = ( date + 150 ) % 365;
    sprintf( buf, "%2ld%s", date % 20, haabu[ date / 20 ] );
    return ( buf );
}


char	*
katunFromAbsolute( long date )
{
    static char buf[80];
    long        ahau;
    long        baktun = 0, katun = 0, tun = 0, uinal = 0, kin = 0;

    date += 1137142L;

    if ( date >= 20 ) {
        kin = date % 20;
        date /= 20;
    }
    if ( date >= 18 ) {
        uinal = date % 18;
        date /= 18;
    }
    if ( date >= 20 ) {
        tun = date % 20;
        date /= 20;
    }

    if ( ( tun == 0 ) && ( uinal == 0 ) && ( kin == 0 ) )
        date--;
    if ( date >= 20 ) {
        katun = date % 20;
        date /= 20;
    }
    baktun = date;
    ahau = ( baktun * 144000L + katun * 7200 + 1 ) % 13 + 1;
    sprintf( buf, "%2ldアハウのカトゥン %2ldトゥン %2ldウィナル %2ldキン",
             ahau, tun, uinal, kin );
    return ( buf );
}



#ifdef	TEST
int
main()
{
	printf( "12345 -> %s -> %ld\n",
		ten2twenty( 12345L ), twenty2ten( ten2twenty( 12345L ) ) );
	printf( "7865782 -> %s -> %ld\n",
		ten2twenty( 7865782 ), twenty2ten( ten2twenty( 7865782 ) ) );
	printf( "10.4.3.6.9 -> %ld -> %s\n",
		twenty2ten( "10.4.3.6.9" ),
		ten2twenty( twenty2ten( "10.4.3.6.9" ) ) );
	printf( "12345 -> %s -> %ld\n",
		ten2twentyForCal( 12345L ),
		twenty2tenForCal( ten2twentyForCal( 12345L ) ) );
	printf( "7865782 -> %s -> %ld\n",
		ten2twentyForCal( 7865782 ),
		twenty2tenForCal( ten2twentyForCal( 7865782 ) ) );
	printf( "244865782 -> %s -> %ld\n",
		ten2twentyForCal( 244865782 ),
		twenty2tenForCal( ten2twentyForCal( 244865782 ) ) );
	printf( "10.4.3.6.9 -> %ld -> %s\n",
		twenty2tenForCal( "10.4.3.6.9" ),
		ten2twentyForCal( twenty2tenForCal( "10.4.3.6.9" ) ) );
	printf( "5.9.4.8.9.2 -> %ld -> %s\n",
		twenty2tenForCal( "5.9.4.8.9.2" ),
		ten2twentyForCal( twenty2tenForCal( "5.9.4.8.9.2" ) ) );
	printf( "12.15.7.8.9.6 -> %ld -> %s\n",
		twenty2tenForCal( "12.15.7.8.9.6" ),
		ten2twentyForCal( twenty2tenForCal( "12.15.7.8.9.6" ) ) );
	printf( "12.18.17.11.14 -> %ld -> %s\n",
		twenty2tenForCal( "12.18.17.11.14" ),
		ten2twentyForCal( twenty2tenForCal( "12.18.17.11.14" ) ) );
	printf( "8.14.3.1.12 -> %ld -> %s -> %s %s\n",
		twenty2tenForCal( "8.14.3.1.12" ),
		ten2twentyForCal( twenty2tenForCal( "8.14.3.1.12" ) ),
		tsolkinFromAbsolute( absoluteFromMaya( "8.14.3.1.12" ) ),
		haabuFromAbsolute( absoluteFromMaya( "8.14.3.1.12" ) ) );
	printf( "9.14.13.4.17 -> %s %s\n",
		tsolkinFromAbsolute( absoluteFromMaya( "9.14.13.4.17" ) ),
		haabuFromAbsolute( absoluteFromMaya( "9.14.13.4.17" ) ) );

    return ( 1 );
}
#endif
