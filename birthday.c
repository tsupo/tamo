/*
 *	birthday.c
 *			by H.Tsujimura	(tsupo@na.rim.or.jp)
 *						2 March 1991
 *
 *	Copyright (c) 1991-1996,1999,2001,2001	Hiroshi Tsujimura
 *	All Rights Reserved.
 *
 * History :
 * $Log: birthday.c $
 * Revision 1.1  2003/10/24  02:41:14  tsujimura543
 * Initial revision
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
#include "dates.h"

#ifndef	lint
static char	*rcs_id =
	"$Header: C:/user/local/src/tamo/RCS/birthday.c 1.1 2003/10/24 02:41:14 tsujimura543 Exp tsujimura543 $";
#endif


#define	isalpha(c)	((((c) >= 'A') && ((c) <= 'Z')) || \
			 (((c) >= 'a') && ((c) <= 'z'))    )
#define	iskanji1(c)	((((c) >= 0x81) && ((c) <= 0x9F)) || \
			 (((c) >= 0xE0) && ((c) <= 0xFC))    )
#ifdef	__STDC__
char	*zen2han( char * );
char    *changeCode( char * );
#else
char	*zen2han();
char    *changeCode();
#endif

#define	MAXFNAMELEN	64
#define	NAMELEN		300

#ifdef	UNIX
static char	*dataPath = "./";
static char	*birthDataFile  = "birth.data";
static char	*birthDataFile2 = "tbl/birthday.tbl";
static char	*eventDataFile  = "idolevnt.table";
static char	*comicDataFile  = "comics.table";
static char	*archkDataFile  = "aircheck.table";
static char	*flowerTblFile  = "tbl/flower.tbl";
static char	*campaignTblFile= "tbl/week.tbl";
#else	/* MSDOS */
static char	*dataPath = ".\\";
static char	*birthDataFile  = "birthday.dat";
static char	*birthDataFile2 = "tbl\\birthday.tbl";
static char	*eventDataFile  = "idolevnt.tbl";
static char	*comicDataFile  = "comics.tbl";
static char	*archkDataFile  = "aircheck.tbl";
static char	*flowerTblFile  = "tbl\\flower.tbl";
static char	*campaignTblFile= "tbl\\week.tbl";
#endif

static char	*birthTitle    = "\n------ 誕生日 ------\n";
static char	*eventTitle    = "\n----- イベント -----\n";
static char	*comicTitle    = "\n----- 新刊情報 -----\n";
static char	*flowerTitle   = "\n------ 誕生花 ------\n";
static char	*campaignTitle = "\n--- キャンペーン ---\n";

extern int      yesterday;
extern int      tomorrow;


struct birthData	{
	char	name[NAMELEN];
	int	dd, mm, yy;
};

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

#ifdef	__STDC__
char	*strchr2( const char *p, int c )
#else
char	*strchr2( p, c )
char	*p;
int	c;
#endif
{
    int             l = strlen( p );
    int             i;
    char            *q = NULL;
    unsigned char   *r = (unsigned char *)p;
    int             flag = 0;

    for ( i = 0; i < l; i++ ) {
	if ( !flag && iskanji1( *r ) ) {
	    r++;
	    flag = 1;
	    continue;
	}
	if ( flag ) {
	    r++;
	    flag = 0;
	    continue;
	}

	if ( *r == c ) {
	    q = r;
	    break;
	}

	r++;
    }

    return ( q );
}


static char	*
spacing( s )
char	*s;
{
	register unsigned char	*p = ( unsigned char *)s;
	int			flag = 0;

	while ( *p ) {
		if ( ( flag == 0 ) && ( iskanji1( *p ) ) ) {
			flag = 1;
		}
		else if ( flag == 1 ) {
			flag = 0;
		}
		else if ( *p == '_' )
			*p = ' ';
		p++;
	}

	return ( s );
}


static void
getdatapath()
{
	static BOOL	executed = FALSE;
	static char	buf[MAXFNAMELEN+1];
	char		*p;
	char		*getenv();

	if ( executed == TRUE )
		return;

	if ( ( ( p = getenv( "ADMIN"  ) ) != NULL ) ||
	     ( ( p = getenv( "KOYOMI" ) ) != NULL ) ||
	     ( ( p = getenv( "BIRTH"  ) ) != NULL ) ||
	     ( ( p = getenv( "TODAY"  ) ) != NULL ) ||
	     ( ( p = getenv( "USRLIB" ) ) != NULL ) ||
	     ( ( p = getenv( "LIB"    ) ) != NULL )    ) {
#ifdef	UNIX
		if ( p[ strlen( p ) - 1 ] == '/' )
			sprintf( buf, "%s", p );
		else
			sprintf( buf, "%s/", p );
#else	/* MS-DOS */
		if ( p[ strlen( p ) - 1 ] == '\\' )
			sprintf( buf, "%s", p );
		else
			sprintf( buf, "%s\\", p );
#endif
	}
	dataPath = buf;
	executed = TRUE;
}


void
birthday( g, dd, mm, yy )
long	g;
int	dd, mm, yy;
{
	struct birthData	b;
	FILE			*fp;
	char			buf[BUFSIZ], *p;
	int			i, d, stat;
	int			flag = 0, first = 1;
	long			g1;

	campaign( g, dd, mm, yy );
	flower( g, dd, mm, yy );

	getdatapath();
	strcpy( buf, dataPath );
	strcat( buf, birthDataFile );

	if ( ( fp = fopen( buf, "r" ) ) == NULL ) {
	        birthday2( g, dd, mm, yy, first );
		return;
	}

	for ( d = 0; d < 7; d++ ) {
	    if ( d > 0 )
		rewind( fp );
	    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
		if ( !strncmp( p, "#tab", 4 ) )
			flag = !flag;
		if ( *p == '#' )
			continue;
		i    = 0;
		b.yy = b.mm = b.dd = 0;
		stat = 0;
		while ( *p ) {
#if	0
			if ( ( *p == ' ' ) || ( *p == '\t' ) ) {
				p++;
				continue;
			}
			stat++;
			if ( stat == 1 ) {
				while ( ( *p != '\t' ) &&
					( flag || ( !flag && (*p!=' ') ) ) ) {
					if ( *p == NUL )
						break;
					b.name[i++] = *p++;
				}
				b.name[i] = NUL;
				continue;
			}
			switch ( stat ) {
			    case 2 :
				if ( isalpha( *p ) )
					p++;
				b.yy = atoi( p );
				break;
			    case 3 :
				b.mm = atoi( p );
				break;
			    case 4 :
				b.dd = atoi( p );
				break;
			}
			if ( stat == 4 )
				break;
			while ( ( *p != ' ' ) && ( *p != '\t' ) ) {
				if ( *p == NUL )
					break;
				p++;
			}
#else
		/*
		 * 以下の形式のファイルから誕生日を取得する
		 *
		 *   86543 辻村浩 S37 12 17 tujimura 052-752-8091 \
		 *         〒464    千種区高見一丁目25-6ジョイフル池下203 B
		 *
		 */
			while ( ( *p == ' ' ) || ( *p == '\t' ) )
			    p++;
			if ( (*p == NUL) || !strncmp( p, "〒", 2 ) )
			    break;
			stat++;
			switch ( stat ) {
			case 2:
			    i = 0;
			    while ( ( *p != '\t' ) && ( *p !=' ' ) ) {
				if ( *p == NUL )
				    break;
				b.name[i++] = *p++;
			    }
			    b.name[i] = NUL;
			    break;
			case 3:
			    b.yy = atoi( p + 1 );
			    switch ( *p ) {
			    case 'M':
				b.yy += 1867;
				break;
			    case 'T':
				b.yy += 1911;
				break;
			    case 'S':
				b.yy += 1925;
				break;
			    case 'H':
				b.yy += 1988;
				break;
			    }
			    break;
			case 4:
			    b.mm = atoi( p );
			    break;
			case 5:
			    b.dd = atoi( p );
			    break;
			}
			while ( ( *p != ' ' ) && ( *p != '\t' ) ) {
				if ( *p == NUL )
					break;
				p++;
			}
#endif
		}

		if ( (b.mm <= 0) || (b.mm > 12) )
		    continue;

		g1 = absoluteFromGregorian( b.dd, b.mm, yy );

		if ( g1 - g == d ) {
		    if ( first ) {
			printf( birthTitle );
			first = 0;
		    }
		    if ( d == 0 )
			printf( "%s さんの誕生日です\n", b.name );
		    else
			printf( "%s さんの誕生日まであと %ld日です\n",
			        b.name, g1 - g );
		}
	    }
	}

	fclose( fp );

	birthday2( g, dd, mm, yy, first );
	return;
}

void
birthday2( g, dd, mm, yy, first )
long	g;
int	dd, mm, yy, first;
{
	struct birthData	b;
	FILE			*fp;
	char			buf[BUFSIZ], *p, *q;
	int			d;
	long			g1;

	getdatapath();
	strcpy( buf, dataPath );
	strcat( buf, birthDataFile2 );

	if ( ( fp = fopen( buf, "r" ) ) == NULL )
		return;

	for ( d = 0; d < 7; d++ ) {
	    if ( d > 0 )
		rewind( fp );
	    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
		if ( (*p == '#') || (*p == '\n') )
			continue;
		b.yy = b.mm = b.dd = 0;

		b.yy = atol( p );
		if ( (q = strchr( p, '/' )) != NULL ) {
		    b.mm = atol( ++q );
		    if ( (p = strchr( q, '/' )) != NULL ) {
			b.dd = atol( ++p );
			q = strchr( p, ' ' );
			if ( q && *++q ) {
			    p = strchr( q, ' ' );
			    if ( p && *++p ) {
				while ( (q = strchr( p, ' ' )) != NULL ) {
				    *q = '\0';
				}
				while ( (q = strchr( p, '\t' )) != NULL ) {
				    *q = '\0';
				}
				strcpy( b.name, p );
				p = b.name;
				while ( (q = strchr( p, '_' )) != NULL ) {
				    *q = ' ';
				    p = q;
				}
				while ( *(p + strlen( p ) - 1) == '\n' ) {
				    *(p + strlen( p ) - 1) = '\0';
				}
			    }
			}
		    }
		}

		if ( (b.mm <= 0) || (b.mm > 12) )
		    continue;

		g1 = absoluteFromGregorian( b.dd, b.mm, yy );

		if ( g1 - g == d ) {
		    if ( first ) {
			printf( birthTitle );
			first = 0;
		    }
		    if ( d == 0 )
			printf( "%s さんの誕生日です\n", b.name );
		    else
			printf( "%s さんの誕生日まであと %ld日です\n",
			        b.name, g1 - g );
		}
	    }
	}

	fclose( fp );
	return;
}


void
idolevent2( g, dd, mm, yy, first )
long	g;
int	dd, mm, yy, *first;
{
	FILE	*fp;
	char	buf[BUFSIZ], *p;
	long	date;
	int	d, m, y;

	getdatapath();
	strcpy( buf, dataPath );
	strcat( buf, eventDataFile );

	if ( ( fp = fopen( buf, "r" ) ) == NULL )
		return;

	while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
		if ( ( *p < '0' ) || ( *p > '9' ) )
			continue;
		date = atol( p );
		if ( date <= 9999L ) {
			date += ( long )( yy - 1900 ) * 10000L;
		}
		if ( date <= 500000 )
		    y = 2000 + ( int )( date / 10000L );
		else
		    y = 1900 + ( int )( date / 10000L );
		m = ( int )( date % 10000L ) / 100;
		d = ( int )( date % 100L );
		if ( ( mm == m ) && ( dd == d ) && ( yy == y ) ) {
			if ( *( p + 6 ) ) {
				if ( *first ) {
					printf( eventTitle );
					*first = 0;
				}
				if ( *( p + 7 ) )
					printf( " %02d%02d%02d %s",
					        yy % 100, mm, dd, p+7 );
			}
		}
		else {
			long	g0 = absoluteFromGregorian( d, m, y );

			if ( ( g0 - g >= 0 ) && ( g0 - g <= 7 ) ) {
			    if ( *( p + 6 ) ) {
				if ( *first ) {
					printf( eventTitle );
					*first = 0;
				}
				if ( *( p + 7 ) )
					printf( "%02d/%02d %s", m, d, p + 7 );
			    }
			}
		}
	}

	fclose( fp );
	return;
}

#ifndef	NUL
#define	NUL	'\0'
#endif
#ifndef	MAXPATHLEN
#define	MAXPATHLEN	128
#endif

extern int	htmlMode;

void
printHeaderOfEvent()
{
    if ( htmlMode ) {
	printf( "\n<HR><H3>イベント</H3>\n<P><CENTER>\n" );
	printf( "<TABLE ALIGN=\"CENTER\" BORDER=1>\n" );
	printf( "<TR><TH ALIGN=\"CENTER\">日付</TH>\n" );
	printf( "<TH ALIGN=\"CENTER\">開演</TH>\n" );
	printf( "<TH ALIGN=\"CENTER\">種別</TH>\n" );
	printf( "<TH ALIGN=\"CENTER\">出演者</TH>\n" );
	printf( "<TH ALIGN=\"CENTER\">場所、その他</TH></TR>\n" );
    }
    else {
	printf( eventTitle );
	printf( "             種\n" );
	printf( "  日付  開演 別 出演者\t\t\t場所、その他\n" );
    }
}

void
printEvent( p, fp )
char	*p;
FILE	*fp;
{
    char    *q, buf[BUFSIZ];
    int     cnt = 1, l;

    do {
	if ( htmlMode )
	    fputs( p, stdout );
	else {
	    q = p;
	    if ( (cnt == 1) && (strncmp( q, "<TR>", 4 ) != 0) )
		cnt += 1;
	    while ( *q ) {
		if ( *q == '<' ) {
		    while ( *++q && (*q != '>') )
			;
		    if ( ((++cnt) % 2) == 1 ) {
			if ( cnt == 9 )
			    l = 0;
			if ( (cnt == 11) && (l <= 7) )
			    putchar( '\t' );
			putchar( (cnt == 11) ? '\t' : ' ' );
		    }
		}
		else if ( *q != '\n' )
		    putchar( *q );
		else
		    putchar( ' ' );
		q++;
		if ( cnt == 9 )
		    l++;
	    }
	}
	if ( *(p + strlen(p) - 1) == '\n' )
	    *(p + strlen(p) - 1) = NUL;
	if ( !strcmp( p + strlen(p) - 5, "</TR>" ) ) {
	    if ( !htmlMode )
		putchar( '\n' );
	    break;
	}
    } while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL );
}

int
event( g, flag )
long	g;
int	*flag;
{
    int     dd, mm, yy;
    char    target[128];
    char    filename[MAXPATHLEN];
    char    *p, buf[BUFSIZ];
    FILE    *fp;
    int	    cnt = 0;

    gregorianFromAbsolute( g, &dd, &mm, &yy );
    sprintf( target, "<TR><TD>%02d%02d%02d", yy % 100, mm, dd );
/*  sprintf( filename, "event/idolE%02d%02d.html", yy % 100, mm ); */
    p = getenv("HOME");
    if ( !p || !(*p) )
	p = ".";
    sprintf( filename, "%s/tmparc/idolE%02d%02d.html", p, yy % 100, mm );
    if ( ( fp = fopen( filename, "r" ) ) == NULL )
	return ( cnt );
    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
	if ( !strncmp( p, target, strlen(target) ) ) {
	    if ( *flag ) {
		*flag = 0;
		printHeaderOfEvent();
	    }
	    printEvent( p, fp );
	    cnt++;
	}
    }
    fclose( fp );

    return ( cnt );
}

void
idolevent( g, dd, mm, yy )
long	g;
int	dd, mm, yy;
{
    char    target[128];
    char    filename[MAXPATHLEN];
    char    *p, buf[BUFSIZ];
    FILE    *fp;
    int	    first = 1, cnt = 0;
    long    g0 = g;

    idolevent2( g, dd, mm, yy, &first );

    sprintf( target, "<TR><TD>%02d%02d%02d", yy % 100, mm, dd );
/*  sprintf( filename, "event/idolE%02d%02d.html", yy % 100, mm ); */
    p = getenv("HOME");
    if ( !p || !(*p) )
	p = ".";
    sprintf( filename, "%s/tmparc/idolE%02d%02d.html", p, yy % 100, mm );
    if ( ( fp = fopen( filename, "r" ) ) == NULL )
	return;

    if ( htmlMode ) {
	fputs( "</PRE>\n", stdout );
	first = 1;
    }

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
	if ( !strncmp( p, target, strlen(target) ) ) {
	    if ( first ) {
		first = 0;
		printHeaderOfEvent();
	    }
	    if ( htmlMode )
		fputs( "<TR BGCOLOR=\"#FFAAFF\">", stdout );
	    p += 4;
	    printEvent( p, fp );
	    cnt++;
	}
    }
    fclose( fp );

    while ( cnt < 20 ) {
	if ( ++g > g0 + 7L )
	    break;
	cnt += event( g, &first );
    }

    if ( !first && htmlMode )
	fputs( "</TABLE></CENTER>\n", stdout );
    if ( htmlMode )
	fputs( "<PRE>\n", stdout );
}

void
printComics( p, publisher, m, d )
char	*p;
char    *publisher;
long    m;
long    d;
{
#if 0
    char    *q, *r;
#else
    char    *q;
#endif
    char    name[BUFSIZ], author[BUFSIZ];
    long    price;
    char    buf[BUFSIZ];
    char    priceString[BUFSIZ];

    strcpy( name,   "???" );
    if ( !htmlMode )
	strcpy( author, "-" );
    else
	strcpy( author, "<TD ALIGN=\"CENTER\">-</TD>" );
    price = 0;

#if	0
    q = strchr( p, '[' );
    while ( q && (*(q - 1) != ' ') ) {
	r = q + 1;
	q = strchr( r, '[' );
    }
#else
    q = strchr2( p, '[' );
#endif
    if ( q ) {
	*q = NUL;
	strcpy( name, p );
	if ( !htmlMode ) {
	    author[0] = '[';
	    strcpy( &author[1], q + 1 );
	}
	else {
	    if ( strncmp(q + 1, "アンソロジー", strlen("アンソロジー")) != 0 )
		sprintf( author, "<TD>%s", q + 1 );
	    else
		sprintf( author, "<TD ALIGN=\"CENTER\">-" );
	}
#if	0
	q = strchr( author, ']' );
	while ( q && (*(q + 1) != ' ') ) {
	    r = q + 1;
	    q = strchr( r, ']' );
	}
#else
	q = strchr2( author, ']' );
#endif
	if ( q ) {
	    *q = NUL;
	    price = atol( q + 1 );
	}
	if ( !htmlMode )
	    strcat( author, "]" );
	else
	    strcat( author, "</TD>" );
    }
    else {
	q = &(p[strlen( p ) - 1]);
	while ( (*q >= '0') && (*q <= '9') ) {
	    q--;
	}
	price = atol( q + 1 );
	*q = NUL;
	strcpy( name, p );
    }
    while ( name[strlen( name ) - 1] == ' ' )
	name[strlen( name ) - 1] = NUL;
    if ( price <= 0 ) {
	if ( htmlMode )
	    strcpy( priceString, "<TD ALIGN=\"CENTER\">未定</TD>" );
	else
	    strcpy( priceString, "  未定" );
    }
    else {
	if ( htmlMode )
	    sprintf( priceString, "<TD ALIGN=\"RIGHT\">%d</TD>", price );
	else
	    sprintf( priceString, "%6d", price );
    }
	    
    switch ( d ) {
    case -1:
	if ( htmlMode )
	    sprintf( buf,
		  "<TR><TD>%02d/上</TD> <TD>%s</TD> %s <TD>%s</TD> %s</TR>\n",
		     m, name, author, publisher, priceString );
	else
	    sprintf( buf, "%02d/上 %-32s %-16s %-12s %s\n",
		     m, name, author, publisher, priceString );
	break;
    case -2:
	if ( htmlMode )
	    sprintf( buf,
		  "<TR><TD>%02d/中</TD> <TD>%s</TD> %s <TD>%s</TD> %s</TR>\n",
		     m, name, author, publisher, priceString );
	else
	    sprintf( buf, "%02d/中 %-32s %-16s %-12s %s\n",
		     m, name, author, publisher, priceString );
	break;
    case -3:
	if ( htmlMode )
	    sprintf( buf,
		  "<TR><TD>%02d/下</TD> <TD>%s</TD> %s <TD>%s</TD> %s</TR>\n",
		     m, name, author, publisher, priceString );
	else
	    sprintf( buf, "%02d/下 %-32s %-16s %-12s %s\n",
		     m, name, author, publisher, priceString );
	break;
    case -4:
	if ( htmlMode )
	    sprintf( buf,
		  "<TR><TD>%02d/末</TD> <TD>%s</TD> %s <TD>%s</TD> %s</TR>\n",
		     m, name, author, publisher, priceString );
	else
	    sprintf( buf, "%02d/末 %-32s %-16s %-12s %s\n",
		     m, name, author, publisher, priceString );
	break;
    default:
	if ( htmlMode )
	    sprintf( buf,
		"<TR><TD>%02d/%02d</TD> <TD>%s</TD> %s <TD>%s</TD> %s</TR>\n",
		     m, d, name, author, publisher, priceString );
	else
	    sprintf( buf, "%02d/%02d %-32s %-16s %-12s %s\n",
		     m, d, name, author, publisher, priceString );
	break;
    }

    if ( !htmlMode ) {
	while ( strlen( buf ) > 76 ) {
	    q = strrchr( buf, ' ' );
	    if ( !q )
		break;
	    if ( *( q - 1 ) == ' ' )
		strcpy( q, q + 1 );
	    else {
		*q = '_';
	    }
	}
    }

    fputs( spacing(buf), stdout );
}

void
comics( g, dd, mm, yy )
long	g;
int	dd, mm, yy;
{
	FILE	*fp;
	char	buf[BUFSIZ], *p, *q, *r;
	char    publisher[BUFSIZ];
	int	d = 0, m = 0, y = 0;
	int     jun   = 0;
	int	first = 1;
	int     stat  = 0;

	getdatapath();
	sprintf( buf, "%scomics%04d-%02d.tbl", dataPath, yy, mm );
	if ( ( fp = fopen( buf, "r" ) ) == NULL ) {
	    strcpy( buf, dataPath );
	    strcat( buf, comicDataFile );
	    if ( ( fp = fopen( buf, "r" ) ) == NULL ) {
		return;
	    }
	}

	while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
	        while ( (*p == ' ') || (*p == '\t') )
		        p++;
		if ( (*p == '\n') || (*p == '^') || !strncmp(p, "＾", 2) )
		        continue;
#if	0
	        p = zen2han( changeCode( buf ) );
#else
	        p = zen2han( buf );
#endif
		if ( !strncmp( p, "<<<<<", 5 ) ) {
		        stat = 1;
			continue;
		}
		if ( !strncmp( p, "-----", 5 ) ) {
		        stat++;
			continue;
		}
		if ( (stat == 2) && (*p >= '0') && (*p <= '9') ) {
		        char    *q;

		        y = atoi( p );
			q = strchr( p, ')' );
			if ( q ) {
			    m = atoi( q + 1 );
			}
			continue;
		}

		if ( stat != 5 )
		        continue;

		if ( !strncmp( p, "上", 2 ) ) {
		        jun = 1;
			strcpy( publisher, strchr( p, '<' ) + 1 );
			p = strchr( publisher, '>' );
			if ( p )
			    *p = NUL;
			continue;
		}
		if ( !strncmp( p, "中", 2 ) ) {
		        jun = 2;
			strcpy( publisher, strchr( p, '<' ) + 1 );
			p = strchr( publisher, '>' );
			if ( p )
			    *p = NUL;
			continue;
		}
		if ( !strncmp( p, "下", 2 ) ) {
		        jun = 3;
			strcpy( publisher, strchr( p, '<' ) + 1 );
			p = strchr( publisher, '>' );
			if ( p )
			    *p = NUL;
			continue;
		}
		if ( !strncmp( p, "末", 2 ) ) {
		        jun = 4;
			strcpy( publisher, strchr( p, '<' ) + 1 );
			p = strchr( publisher, '>' );
			if ( p )
			    *p = NUL;
			continue;
		}
		if ( (*p >= '0') && (*p <= '9') ) {
		        jun = 0;
			d = atol( p );
			strcpy( publisher, strchr( p, '<' ) + 1 );
			p = strchr( publisher, '>' );
			if ( p )
			    *p = NUL;
			continue;
		}

		if ( ( yy > y ) || ( mm > m ) )
			continue;

		r = NULL;
#if	0
		if ( ((q = strrchr(p, '[')) == NULL)            ||
		     (q && ((r = strrchr(q + 1, ']')) == NULL)) ||
		  /* (q && (*(q - 1) != ' '))                   || */
		     (r && (*(r + 1) != ' '))                      ) {
#else
		if ( ((q = strchr2(p, '[')) == NULL)            ||
		     (q && ((r = strchr2(q + 1, ']')) == NULL))    ) {
#endif
		    if ( p[strlen( p ) - 1] == '\n' )
			p[strlen( p ) - 1] = NUL;
		    strcat( p, " " );
		    strcpy( buf, p );
		    p = buf;
		    q = fgets( &(p[strlen(p)]), BUFSIZ - strlen(p) - 1, fp );
		    if ( q == NULL ) {
			break;
		    }
		    p = zen2han( buf );
#ifdef	DEBUG
		    printf( ">>> p = %s", p );
#endif
		}

		if ( p[strlen( p ) - 1] == '\n' )
		    p[strlen( p ) - 1] = NUL;

		if ( ( yy == y ) && ( mm == m )           &&
		          ( ( dd >= 1 ) && ( dd <= 10 ) ) &&
		          (jun == 1)                         ) {
			if ( first ) {
			    if ( htmlMode ) {
				printf( "\n<HR><H3>新刊情報</H3>\n" );
				printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
			    }
			    else {
				printf( comicTitle );
			    }
			    first = 0;
			}
			printComics( p + 6, publisher, m, -jun );
		}
		else if ( ( yy == y ) && ( mm == m )       &&
		          ( ( dd >= 11 ) && ( dd <= 20 ) ) &&
		          (jun == 2)                          ) {
			if ( first ) {
			    if ( htmlMode ) {
				printf( "\n<HR><H3>新刊情報</H3>\n" );
				printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
			    }
			    else {
				printf( comicTitle );
			    }
			    first = 0;
			}
			printComics( p + 6, publisher, m, -jun );
		}
		else if ( ( yy == y ) && ( mm == m )       &&
		          ( ( dd >= 21 ) && ( dd <= 31 ) ) &&
		          (jun == 3)                          ) {
			if ( first ) {
			    if ( htmlMode ) {
				printf( "\n<HR><H3>新刊情報</H3>\n" );
				printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
			    }
			    else {
				printf( comicTitle );
			    }
			    first = 0;
			}
			printComics( p + 6, publisher, m, -jun );
		}
		else if ( ( yy == y ) && ( mm == m )       &&
		          ( ( dd >= 25 ) && ( dd <= 31 ) ) &&
		          (jun == 4)                          ) {
			if ( first ) {
			    if ( htmlMode ) {
				printf( "\n<HR><H3>新刊情報</H3>\n" );
				printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
			    }
			    else {
				printf( comicTitle );
			    }
			    first = 0;
			}
			printComics( p + 6, publisher, m, -jun );
		}
		else if ( ( yy == y ) && ( mm == m ) && ( dd == d ) ) {
			if ( *( p + 6 ) ) {
			    if ( first ) {
				if ( htmlMode ) {
				    printf( "\n<HR><H3>新刊情報</H3>\n" );
				    printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				    printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
				}
				else {
				    printf( comicTitle );
				}
				first = 0;
			    }
			    printComics( p + 6, publisher, m, d );
			}
		}
		else {
		    long	g0 = absoluteFromGregorian( d, m, y );

		    if ( ( g0 - g >= 0 ) && ( g0 - g <= 7 ) ) {
			if ( *( p + 6 ) ) {
			    if ( first ) {
				if ( htmlMode ) {
				    printf( "\n<HR><H3>新刊情報</H3>\n" );
				    printf(
				  "<TABLE BORDER=\"1\" ALIGN=\"CENTER\">\n" );
				    printf( "<TR><TH>発行日</TH><TH>書名</TH><TH>著作者</TH><TH>発行元</TH><TH>価格</TH></TR>\n" );
				}
				else {
				    printf( comicTitle );
				}
				first = 0;
			    }
			    printComics( p + 6, publisher, m, d );
			}
		    }
		}
	}

	fclose( fp );
	if ( htmlMode ) {
	    if ( !first )
		printf( "</TABLE>\n" );
	}

	return;
}

void
flower( g, dd, mm, yy )
long	g;
int	dd, mm, yy;
{
    FILE    *fp;
    char    buf[BUFSIZ], *p = NULL, *q = NULL;
    long    m, d;
    int     found = 0;

    getdatapath();
    strcpy( buf, dataPath );
    strcat( buf, flowerTblFile );
    if ( ( fp = fopen( buf, "r" ) ) == NULL )
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
    fclose( fp );

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
		    printf( flowerTitle );
		    printf( "%sの誕生石は %s で、花は %s です\n",
			    (tomorrow && (dd == 1)) ? "来月" :
			    (yesterday > 1)         ? "先月" :
			                              "今月",
			    birthStone[mm - 1], birthFlower[mm - 1] );
		    printf( "%sの誕生花は %s で、花言葉は『%s』です\n",
		            tomorrow ? "明日" : yesterday ? "昨日" : "今日",
			    p, q );
		}
	    }
	}
    }

    return;
}

void
printCampaign( p, d1, m1, d2, m2 )
char	*p;
int	d1, m1, d2, m2;
{
    static int	count = 0;
    char        *q;

    if ( !p )
	return;

    while ( (*p == ' ') || (*p == '\t') )
	p++;
    q = strrchr( p, '#' );
    if ( q )
	*q = NUL;
    while ( (p[strlen(p) - 1] == ' ' ) ||
	    (p[strlen(p) - 1] == '\t') ||
	    (p[strlen(p) - 1] == '\n')    ) {
	p[strlen(p) - 1] = NUL;
    }

    if ( !(*p) )
	return;

    if ( count == 0 ) {
	printf( campaignTitle );
    }

    printf( "%s (%d月%d日から%d月%d日まで)\n", p, m1, d1, m2, d2 );
    count++;
}

#define	leapyear( year )	( ((year)%4==0) && \
				  (((year)%100!=0) || ((year)%400==0)) )

void
campaign( g, dd, mm, yy )
long	g;
int	dd, mm, yy;
{
    FILE    *fp;
    char    buf[BUFSIZ], *p = NULL, *q = NULL, *r = NULL, *s = NULL;
    long    m1, d1, m2, d2;
    long    g1, g2;

    getdatapath();
    strcpy( buf, dataPath );
    strcat( buf, campaignTblFile );
    if ( ( fp = fopen( buf, "r" ) ) == NULL )
	return;

    while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
	if ( (*p >= '0') && (*p <= '1') ) {
	    q = strchr( p, '/' );
	    if ( q && (*(q + 1) >= '0' && (*(q + 1) <= '9')) ) {
		q++;
		m1 = atoi( p );
		d1 = atoi( q );
		r = strchr( q, ' ' );
		if ( r && (*(r + 1) >= '0' && (*(r + 1) <= '1')) ) {
		    r++;
		    s = strchr( r, '/' );
		    if ( s && (*(s + 1) >= '0' && (*(s + 1) <= '9')) ) {
			s++;
			m2 = atoi( r );
			d2 = atoi( s );

			g1 = absoluteFromGregorian( d1, m1, yy );
			g2 = absoluteFromGregorian( d2, m2, yy );
			if ( g2 < g1 ) {
			    if ( (g2 < g) && (g < g1) )
				continue;
			    if ( g1 <= g ) 
				g2 = absoluteFromGregorian( d2, m2, yy + 1 );
			    else if ( g <= g2 )
				g1 = absoluteFromGregorian( d1, m1, yy - 1 );
			}

			if ( (m1 == 2) && (d1 == 29) ) {
			    if ( !leapyear( yy ) ) {
				g1--;
				d1--;
			    }
			}
			if ( (m2 == 2) && (d2 == 29) ) {
			    if ( !leapyear( yy ) ) {
				g2--;
				d2--;
			    }
			}

			if ( (g1 <= g) && (g <= g2) ) {
			    p = strchr( s + 1, ' ' );
			    if ( !p )
				p = strchr( s + 1, '\t' );
			    if ( p )
				printCampaign( p, d1, m1, d2, m2 );
			}
		    }
		}
	    }
	}
    }
    fclose( fp );

    return;
}

