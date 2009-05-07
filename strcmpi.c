/*
 *	strcmpi.c
 *			by H.Tsujimura
 *		compare strings with ingnoring lower/upper case
 *
 * History:
 * $Log: strcmpi.c $
 * Revision 1.1  2003/10/24  01:36:10  tsujimura543
 * Initial revision
 *
 * Revision 1.50  91/11/23 19:58:22  tsuporone
 * for ANEW library
 * 
 * Revision 1.1  91/04/27  15:05:24  tuzimura
 * Initial revision
 * 
 */

#ifndef	lint
static char	*rcs_id =
"$Header: C:/user/local/src/tamo/RCS/strcmpi.c 1.1 2003/10/24 01:36:10 tsujimura543 Exp tsujimura543 $";
#endif

int strlen( const char * );

int
strcmpi( const char *s, const char *t )
{
    int ret = 0;
    int i, j;
    int l1 = strlen( s );
    int l2 = strlen( t );
    int n;

    if ( l1 > l2 )
        n = l2;
    else
        n = l1;

    while ( *s && *t && ( n > 0 ) ) {
	i = *s++; j = *t++;
        if ( i != j ) {
            if ( ( i >= 'a' ) && ( i <= 'z' ) ) {
#if	0
                i = i - 'a' + 'A';
#else
		i &= ~0x20;
#endif
            }
            if ( ( j >= 'a' ) && ( j <= 'z' ) ) {
#if	0
                j = j - 'a' + 'A';
#else
                j &= ~0x20;
#endif
            }
            if ( i != j ) {
                ret = i - j;
                break;
            }
        }
	n--;
    }

    if ( ( ret == 0 ) && ( n > 0 ) ) {
        if ( *s )
            ret = *s;
        if ( *t )
            ret = -(*t);
    }

    return ( ret );
}

