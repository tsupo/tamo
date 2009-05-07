/*
 *  decodeURL.c         tsupo@na.rim.or.jp
 *          by H. Tsujimura     August 1996
 *
 *  Copyright (c) 1996,1997,2003 by Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: decodeURL.c $
 * Revision 1.5  2003/11/11  07:07:10  tsujimura543
 * const 指定を付加
 *
 * Revision 1.4  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.3  2003/03/11  12:13:53  tsujimura543
 * コメントを整理
 *
 * Revision 1.2  2003/03/11  01:45:55  tsujimura543
 * RCSコメントを埋め込むようにする
 *
 * Revision 1.1  2003/02/25  05:52:29  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*
decodeURL( const char *pp )
{
    const char              *p;
    char                    tmp[3], *q;
    static unsigned char    out[BUFSIZ * 2];

    p = pp;
    q = (char *)&out[0];
    while ( *p ) {
        if ( *p == '%' ) {
            if ( (((*(p + 1) >= '0') && (*(p + 1) <= '9')) ||
                  ((*(p + 1) >= 'A') && (*(p + 1) <= 'F')) ||
                  ((*(p + 1) >= 'a') && (*(p + 1) <= 'f'))   ) &&
                 (((*(p + 2) >= '0') && (*(p + 2) <= '9')) ||
                  ((*(p + 2) >= 'A') && (*(p + 2) <= 'F')) ||
                  ((*(p + 2) >= 'a') && (*(p + 2) <= 'f'))   )    ) {
                tmp[0] = *++p;
                tmp[1] = *++p;
                tmp[2] = '\0';
                p++;
                *q++ = (unsigned char)(strtol( tmp, NULL, 16 ) & 0xFF);
                continue;
            }
        }
        else if ( *p == '+' ) {
            p++;
            *q++ = ' ';
            continue;
        }

        *q++ = (unsigned char)(*p++);
    }
    *q = '\0';

    return ( (char *)&out[0] );
}
