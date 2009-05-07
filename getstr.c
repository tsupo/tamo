/*
 *	getstr.c
 *		ANEW product
 *
 * history :
 * $Log: RCS/GETSTR.Cv $
 * Revision 1.52  95/07/12 23:23:16  tsuporone
 * NUL Ç∆ NULL ÇåµñßÇ…ãÊï Ç∑ÇÈÇÊÇ§Ç…èëÇ´íºÇµ
 * 
 * Revision 1.51  91/12/27 04:48:44  tsuporone
 * to initialize string with NULLs
 * 
 * Revision 1.50  91/11/23 17:57:42  tsuporone
 * for ANEW library
 * 
 * Revision 1.1  91/03/18  20:56:00  tuzimura
 * Initial revision
 * 
 */

#include <stdio.h>

#ifndef	lint
static char	*rcs_id  =
	"$Header: GETSTR.Cv  1.52  95/07/12 23:23:16  tsuporone  Exp $";
#endif

#ifndef NUL
#define NUL     '\0'
#endif
#define	MAXSTR	30

static char	buf[MAXSTR][BUFSIZ];
static int	count = 0;

char     *
getString()
{
    char    *p, *q;
    int     i;

    p = q = buf[count];
    count = (count + 1) % MAXSTR;
    for ( i = 0; i < BUFSIZ; i++ )
        *q++ = NUL;

    return ( p );
}

