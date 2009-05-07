/*
 *	zen2han.c
 *			by H.Tsujimura		1991/05/07
 *			ANEW Product
 *
 * History:
 * $Log: RCS/ZEN2HAN.Cv $
 * Revision 1.51  95/07/12 23:28:34  tsuporone
 * NUL Ç∆ NULL ÇåµñßÇ…ãÊï Ç∑ÇÈÇÊÇ§Ç…èëÇ´íºÇµ
 * 
 * Revision 1.50  91/11/23 17:49:06  tsuporone
 * for ANEW library
 * 
 * Revision 1.2  91/05/07  18:55:49  tuzimura
 * accepted 2-byte character when input line-range-specification
 * 
 * Revision 1.1  91/05/07  17:16:20  tuzimura
 * Initial revision
 * 
 */

#include <string.h>

#ifndef	lint
static char	*rcs_id =
"$Header: ZEN2HAN.Cv  1.51  95/07/12 23:28:34  tsuporone  Exp $";
#endif

#ifndef	NUL
#define	NUL	'\0'
#endif

char	*getString();

static int
_zen2han( s, t, mode )
char	*s, *t;
int	mode;
{
	int	c = (int)( (unsigned char)*s ) & 0xff;
	int	flag = 0;

	switch ( c ) {
	  case 0x81 :
		c = (int)( (unsigned char)*(s+1) ) & 0xff;
		switch ( c ) {
		  case 0x41 :
		  case 0x43 :
			*t = ',';
			break;
		  case 0x42 :
		  case 0x44 :
			*t = '.';
			break;
	       /* case 0x45 : */
		  case 0x5e :
			*t = '/';
			break;
		  case 0x46 :
			*t = ':';
			break;
		  case 0x47 :
			*t = ';';
			break;
		  case 0x48 :
			*t = '?';
			break;
		  case 0x49 :
			*t = '!';
			break;
		  case 0x4d :
			*t = '`'; /* back-quotation mark */
			break;
		  case 0x4f :
			*t = '^';
			break;
		  case 0x50 :
		  case 0x60 :
			*t = '~';
			break;
		  case 0x51 :
			*t = '_';
			break;
		  case 0x5f :
		  case 0x8f :
		     /* *t = '\\'; */
			*t = ' ';
			break;
		  case 0x62 :
			*t = '|';
			break;
		  case 0x65 :
		  case 0x66 :
			*t = '\'';
			break;
		  case 0x67 :
		  case 0x68 :
			*t = '\"';
			break;
		  case 0x69 :
			*t = '(';
			break;
		  case 0x6a :
			*t = ')';
			break;
		  case 0x6d :
			*t = '[';
			break;
		  case 0x6e :
			*t = ']';
			break;
		  case 0x6f :
			*t = '{';
			break;
		  case 0x70 :
			*t = '}';
			break;
		  case 0x7b :
			*t = '+';
			break;
		  case 0x7c :
			*t = '-';
			break;
		  case 0x81 :
			*t = '=';
			break;
		  case 0x71 :
		  case 0x83 :   /* {@@} */
			*t = '<';
			break;
		  case 0x72 :
		  case 0x84 :   /* {@@} */
			*t = '>';
			break;
		  case 0x90 :
			*t = '$';
			break;
		  case 0x93 :
			*t = '%';
			break;
		  case 0x94 :
			*t = '#';
			break;
		  case 0x95 :
			*t = '&';
			break;
		  case 0x96 :
			*t = '*';
			break;
		  case 0x97 :
			*t = '@';
			break;
		  default :
			*t++ = *s++;
			*t = *s;
			flag = 1;
			break;
		}
		break;
	  case 0x82 :
		c = (int)( (unsigned char)*(s+1) ) & 0xff;
		switch ( c ) {
		  case 0x4f :
		  case 0x50 :
		  case 0x51 :
		  case 0x52 :
		  case 0x53 :
		  case 0x54 :
		  case 0x55 :
		  case 0x56 :
		  case 0x57 :
		  case 0x58 :
			*t = '0' + ( c - 0x4f );
			break;
		  case 0x60 :
		  case 0x61 :
		  case 0x62 :
		  case 0x63 :
		  case 0x64 :
		  case 0x65 :
		  case 0x66 :
		  case 0x67 :
		  case 0x68 :
		  case 0x69 :
		  case 0x6a :
		  case 0x6b :
		  case 0x6c :
		  case 0x6d :
		  case 0x6e :
		  case 0x6f :
		  case 0x70 :
		  case 0x71 :
		  case 0x72 :
		  case 0x73 :
		  case 0x74 :
		  case 0x75 :
		  case 0x76 :
		  case 0x77 :
		  case 0x78 :
		  case 0x79 :
			*t = 'A' + ( c - 0x60 );
			break;
		  case 0x81 :
		  case 0x82 :
		  case 0x83 :
		  case 0x84 :
		  case 0x85 :
		  case 0x86 :
		  case 0x87 :
		  case 0x88 :
		  case 0x89 :
		  case 0x8a :
		  case 0x8b :
		  case 0x8c :
		  case 0x8d :
		  case 0x8e :
		  case 0x8f :
		  case 0x90 :
		  case 0x91 :
		  case 0x92 :
		  case 0x93 :
		  case 0x94 :
		  case 0x95 :
		  case 0x96 :
		  case 0x97 :
		  case 0x98 :
		  case 0x99 :
		  case 0x9a :
			*t = 'a' + ( c - 0x81 );
			break;
		  default :
			if ( mode ) {
				switch ( c ) {
				  case 0xa0 :
					*t = 'a';
					break;
				  case 0xa2 :
					*t = 'i';
					break;
				  case 0xa4 :
					*t = 'u';
					break;
				  case 0xa6 :
					*t = 'e';
					break;
				  case 0xa8 :
					*t = 'o';
					break;
				  default :
					*t++ = *s++;
					*t = *s;
					flag = 1;
					break;
				}
			}
			else {
				*t++ = *s++;
				*t = *s;
				flag = 1;
			}
			break;
		}
		break;
	  default   :
		if ( mode && ( c == 0x83 ) ) {
			c = (int)( (unsigned char)*(s+1) ) & 0xff;
			switch ( c ) {
			  case 0x41 :
				*t = 'a';
				break;
			  case 0x43 :
				*t = 'i';
				break;
			  case 0x45 :
				*t = 'u';
				break;
			  case 0x47 :
				*t = 'e';
				break;
			  case 0x49 :
				*t = 'o';
				break;
			  default :
				*t++ = *s++;
				*t = *s;
				flag = 1;
				break;
			}
		}
		else {
			*t++ = *s++;
			*t = *s;
			flag = 1;
		}
		break;
	}

	return ( flag );
}

char	*
zen2han( s )
char	*s;
{
	char	*t; 
	char	*p = getString();
	int	flag = 0;

	t = p;
	while ( *s ) {
		if ( (unsigned char)*s < 0x80 ) {
			*t++ = *s++;
		}
		else {
			flag = _zen2han( s, t, 0 );
			if ( flag )
				t += 2;
			else
				t++;
			s += 2;
		}
	}

	*t = NUL;

	return ( p );
}

char	*
zen2hani( s )
char	*s;
{
	char	*t; 
	char	*p = getString();
	int	flag = 0;

	t = p;
	while ( *s ) {
		if ( (unsigned char)*s < 0x80 ) {
			*t++ = *s++;
		}
		else {
			flag = _zen2han( s, t, 1 );
			if ( flag )
				t += 2;
			else
				t++;
			s += 2;
		}
	}

	*t = NUL;

	return ( p );
}

#ifdef  __STDC__
char	*
zen2hanf( char *s, char stopper )
#else
char	*
zen2hanf( s, stopper )
char	*s;
char	stopper;
#endif
{
	char	*p = getString();
	char	*t; 
	int	flag = 0;

	t = p;
	while ( *s ) {
		if ( (unsigned char)*s < 0x80 ) {
			*t++ = *s++;
		}
		else {
			flag = _zen2han( s, t, 1 );
			if ( flag )
				t += 2;
			else
				t++;
			s += 2;
		}

		if ( flag || ( *( t - 1 ) == stopper ) ) {
			strcpy( t, s );
			goto EXIT;
		}
	}

	*t = NUL;

EXIT:
	return ( p );
}

