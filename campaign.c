/*
 *  campaign.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      first revision: 2 March 1991 
 *                      renewal:        6 May   2003
 *  Copyright (c) 1991-1996,1999,2001,2002,2003 Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: campaign.c $
 * Revision 1.7  2007/10/18  12:17:08  tsujimura543
 * �u�Ƒ��̏T�ԁv�ɑΉ�
 *
 * Revision 1.6  2003/11/11  07:07:10  tsujimura543
 * �����s��Z������
 *
 * Revision 1.5  2003/11/11  07:02:19  tsujimura543
 * K&R �\�L �� ANSI C �\�L �Ɋ��S�ڍs
 *
 * Revision 1.4  2003/05/30  07:48:18  tsujimura543
 * 12�����܂ł̃L�����y�[����S�Ĕ��f (2003�N����)
 *
 * Revision 1.3  2003/05/28  10:58:54  tsujimura543
 * ���N���Ԃ��ϓ�����L�����y�[���̑Ή����𑝂₷�@(1��������5����)
 *
 * Revision 1.2  2003/05/27  12:18:07  tsujimura543
 * �Ō�T�ԂɑΉ�
 *
 * Revision 1.1  2003/05/06  09:33:19  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamo.h"

#ifndef	lint
static char	*rcs_id =
    "$Header: C:/user/local/src/tamo/RCS/campaign.c 1.7 2007/10/18 12:17:08 tsujimura543 Exp tsujimura543 $";
#endif


/* �f�[�^�t�@�C���� */
static char *campaignTblFile  = "tbl/week.tbl";

void
printCampaign( char *p, int d1, int m1, int d2, int m2 )
{
    static int  count = 0;
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
        printf( "\n�L�����y�[��\n" );
    }

    printf( "  %s (%d��%d������%d��%d���܂�)\n", p, m1, d1, m2, d2 );
    count++;
}


/* ���N�A�J�n���E�I�������ϓ�����L�����y�[���̕\�� */
void
printCampaign2( long *flag, long g, int dd, int mm, int yy )
{
    int     m1, d1, m2, d2, yyy;
    int     start, end, k;
    long    g1, g2;

    if ( mm == FEBRUARY ) {
        if ( yy >= 1995 ) {
            if ( leapyear( yy ) )
                start = 16;
            else
                start = 17;
            end = start + 6;
            if ( (dd >= start) && (dd <= end) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �A�����M�[�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, start, mm, end );
                            /* �A�����M�[�̓�(2��20��)���܂ޏT��3���O����� */
                            /* 1�T��(2��17���`23��)                         */
                            /* �������A��O�I�ɁA2��16�������1�T�ԂɂȂ邱 */
                            /* �Ƃ�����(��: 2004�N)                         */
                            /* �����J���Ȃ́u�s���E�C�x���g�v�� Web�y�[�W�� */
                            /* ���N�A�A�����M�[�T�Ԃ����ۂ͂����炢�܂� */
                            /* �ɂȂ�̂��f�������B                       */
                (*flag)++;
            }
        }
    }

    if ( mm == APRIL ) {
        start = 0;
        if ( (yy >= 1948) && (yy <= 1988) )
            start = 1;
        else if ( yy >= 1989 )
            start = 23;

        if ( start != 0 ) {
            end = start + 6;
            if ( (dd >= start) && (dd <= end) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  %s�̏T�� (%d��%d������%d��%d���܂�)\n",
                        start == 1 ? "��" : "�݂ǂ�",
                        mm, start, mm, end );
                            /* �݂ǂ�̓�(4��29��)����ɔ����A4��23���` */
                            /* 4��29���ɕύX                            */
                (*flag)++;
            }
        }

        if ( (dd >= 10) && (dd <= 16) ) {
            k = 0;
            if ( (yy >= 1949) && (yy <= 1997) )
                k = 1;
            else if ( yy >= 1998 )
                k = 2;
            if ( k > 0 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  %s (%d��%d������%d��%d���܂�)\n",
                        k == 1 ? "�w�l�T��" : "�����T��",
                        mm, 10, mm, 16 );
                (*flag)++;
            }
        }

        if ( yy >= 1960 ) {
            g1 = NthKday( THIRD, MONDAY, APRIL, yy );
            if ( g1 > absoluteFromGregorian( 18, APRIL, yy ) )
                g1 = NthKday( SECOND, MONDAY, APRIL, yy );
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                m2 = m1;
                d2 = d1 + 6;
                printf( "  �Ȋw�Z�p�T�� (%d��%d������%d��%d���܂�)\n",
                        m1, d1, m2, d2 );
                          /* �����̓�(4��18��)���܂ޏT�̌��j���痂�T�̓��j */
                          /* �܂�                                          */
                (*flag)++;
            }
        }

        if ( yy >= 2000 ) {
            if ( dd >= 23 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���ǂ��̓Ǐ��T�� (%d��%d������%d��%d���܂�)\n",
                        mm, 23, mm + 1, 12 );
                (*flag)++;
            }
        }
    }

    g1 = springStartDay( yy ) + 87 - 3;  /* ���\�����3���O */
    g2 = g1 + 6;
    if ( (g >= g1) && (g <= g2) ) {
        if ( *flag == 0 )
            printf( "\n�L�����y�[��\n" );

        gregorianFromAbsolute( g1, &d1, &m1, &yyy );
        gregorianFromAbsolute( g2, &d2, &m2, &yyy );
        printf( "  �Β��T�� (%d��%d������%d��%d���܂�)\n",
                m1, d1, m2, d2 );
        (*flag)++;
    }

    if ( mm == MAY ) {
        if ( yy >= 1991 ) {
            if ( yy != 2000 ) {
                g1 = NthKday( SECOND, SUNDAY, MAY, yy );
                if ( g1 > absoluteFromGregorian( 12, MAY, yy ) )
                    g1 = NthKday( FIRST, SUNDAY, MAY, yy );
            }
            else
                g1 = NthKday( SECOND, MONDAY, MAY, yy );
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                m2 = m1;
                d2 = d1 + 6;
                printf( "  �Ō�T�� (%d��%d������%d��%d���܂�)\n",
                        m1, d1, m2, d2 );
                            /* �Ō�̓�(5��12��)���܂ޏT�̓��j����y�j�܂�  */
                            /* �������A��O�I�ɁA5��12�����܂ޏT�̌��j����  */
                            /* ���T�̓��j�܂ŁA�ɂȂ邱�Ƃ�����(��: 2000�N) */
                (*flag)++;
            }
        }

        if ( (yy >= 1967) && (yy <= 1999) ) {
            if ( dd <= 14 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���ǂ��̓Ǐ��T�� (%d��%d������%d��%d���܂�)\n",
                        mm, 1, mm, 14 );
                (*flag)++;
            }
        }
        else if ( yy >= 2000 ) {
            if ( dd <= 12 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���ǂ��̓Ǐ��T�� (%d��%d������%d��%d���܂�)\n",
                        mm - 1, 23, mm, 12 );
                (*flag)++;
            }
        }

        if ( yy >= 1995 ) {
            if ( dd >= 15 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���ʐM���� (%d��%d������%d��%d���܂�)\n",
                        mm, 15, mm + 1, 15 );
                (*flag)++;
            }
        }

        if ( dd >= 25 ) {
            if ( (yy >= 1972) && (yy <= 1999) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���R�E�Ɨ�����ѐl���̂��߂ɓ�����A�t���J�����"
                        "���ׂĂ̑��̐A���n�l���Ƃ̘A�яT�� "
                        "(%d��%d������%d��%d���܂�)\n",
                        mm, 25, mm, 31 );
                (*flag)++;
            }
            else if ( yy >= 2000 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �񎩎��n��l���Ƃ̘A�яT�� "
                        "(%d��%d������%d��%d���܂�)\n",
                        mm, 25, mm, 31 );
                (*flag)++;
            }
        }

        if ( yy >= 1991 ) {
            g2 = NthKday( FOURTH, SATURDAY, MAY, yy ) + 1;
            g1 = g2 - 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �̑��T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }

        if ( yy >= 1967 ) {
            g1 = absoluteFromGregorian( 11, MAY, yy );
            g1 += ((7 - (g1 % 7)) % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �t�̍s�����k�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }

    if ( mm == JUNE ) {
        if ( dd <= 15 ) {
            if ( (yy >= 1985) && (yy <= 1994) ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �e���R���{�� (%d��%d������%d��%d���܂�)\n",
                        mm, 1, mm, 15 );
                (*flag)++;
            }
            else if ( yy >= 1995 ) {
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ���ʐM���� (%d��%d������%d��%d���܂�)\n",
                        mm - 1, 15, mm, 15 );
                (*flag)++;
            }
        }

        if ( yy >= 1999 ) {
            if ( *flag == 0 )
                printf( "\n�L�����y�[��\n" );

            printf( "  �C�O���S�L�����y�[�� (%d��%d������%d��%d���܂�)\n",
                    mm, 1,
                    yy >= 2002 ? mm + 1 : mm,
                    yy >= 2002 ? 31     : 30  );
            /* 1999�N���O��11���Ɂu�C�O���S�T�ԁv(1993�N�`) �Ƃ��Ď��{ */
            (*flag)++;
        }

        if ( (yy >= 1949) && (dd >= 4) && (dd <= 10) ) {
            if ( *flag == 0 )
                printf( "\n�L�����y�[��\n" );
            if ( (yy <= 1952) || (yy == 1956) || (yy == 1957) )
                printf( "  ���o�q���T�� (%d��%d������%d��%d���܂�)\n",
                        mm, 4, mm, 10 );
            else if ( yy <= 1955 )
                printf( "  ���o�q�������^�� (%d��%d������%d��%d���܂�)\n",
                        mm, 4, mm, 10 );
            else /* if ( yy >= 1958 ) */
                printf( "  ���̉q���T�� (%d��%d������%d��%d���܂�)\n",
                        mm, 4, mm, 10 );
            (*flag)++;
        }

        if ( yy >= 1990 ) {
            g2 = NthKday( SECOND, SATURDAY, JUNE, yy );
            g1 = g2 - 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �댯�����S�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }

        if ( yy >= 1964 ) {
            g1 = absoluteFromGregorian( 25, JUNE, yy );
            g1 -= (g1 % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �n���Z���a�𐳂�����������T�� "
                        "(%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }

    if ( mm == JULY ) {
        if ( yy >= 2002 ) {
            if ( *flag == 0 )
                printf( "\n�L�����y�[��\n" );

            printf( "  �C�O���S�L�����y�[�� (%d��%d������%d��%d���܂�)\n",
                    mm - 1, 1, mm, 31 );
            (*flag)++;
        }
    }

    if ( mm == AUGUST ) {
        if ( yy >= 1963 ) {
            g1 = NthKday( FIRST, SUNDAY, AUGUST, yy );
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  %s�T�� (%d��%d������%d��%d���܂�)\n",
                        yy <= 1976 ? "�H���ŗ\�h" : "�H�i�q��",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }

    if ( mm == SEPTEMBER ) {
        if ( yy >= 1982 ) {
            g1 = absoluteFromGregorian( 9, SEPTEMBER, yy );
            g1 -= (g1 % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �~�}��ÏT�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }

        if ( yy >= 1966 ) {
            g1 = absoluteFromGregorian( 15, SEPTEMBER, yy );
            g1 -= (g1 % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �V�l�����T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }

    if ( mm == OCTOBER ) {
        g2 = NthKday( SECOND, SATURDAY, OCTOBER, yy );
        g1 = g2 - 6;
        if ( (g >= g1) && (g <= g2) ) {
            gregorianFromAbsolute( g1, &d1, &m1, &yyy );
            d2 = d1 + 6;
            if ( *flag == 0 )
                printf( "\n�L�����y�[��\n" );

            printf( "  �Î����T�C�N���T�� (%d��%d������%d��%d���܂�)\n",
                    mm, d1, mm, d2 );
            (*flag)++;
        }

        if ( yy >= 1967 ) {
            g1 = absoluteFromGregorian( 16, OCTOBER, yy );
            g1 += ((7 - (g1 % 7)) % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �H�̍s�����k�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }

    if ( mm == NOVEMBER ) {
        if ( yy >= 1965 ) {
            g2 = NthKday( SECOND, SATURDAY, NOVEMBER, yy );
            g1 = g2 - 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �S�����A�a�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }

        if ( yy >= 2001 ) {
            g1 = absoluteFromGregorian( 25, NOVEMBER, yy );
            g1 -= (g1 % 7);
            g2 = g1 + 6;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 6;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  ��È��S���i�T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }

        if ( yy >= 2007 ) {
            g1 = NthKday( THIRD, SUNDAY, NOVEMBER, yy );
            g1 -= 7;
            g2 = g1 + 13;
            if ( (g >= g1) && (g <= g2) ) {
                gregorianFromAbsolute( g1, &d1, &m1, &yyy );
                d2 = d1 + 13;
                if ( *flag == 0 )
                    printf( "\n�L�����y�[��\n" );

                printf( "  �Ƒ��̏T�� (%d��%d������%d��%d���܂�)\n",
                        mm, d1, mm, d2 );
                (*flag)++;
            }
        }
    }
}


void
campaign( long g, int dd, int mm, int yy )
{
    FILE    *fp;
    char    buf[BUFSIZ], *p = NULL, *q = NULL, *r = NULL, *s = NULL;
    long    m1, d1, m2, d2;
    long    g1, g2;
    long    cnt = 0;

    if ( ( fp = tfopen( campaignTblFile, "r" ) ) == NULL )
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
                            if ( p ) {
                                printCampaign( p, d1, m1, d2, m2 );
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }
    tfclose( fp );

    printCampaign2( &cnt, g, dd, mm, yy );

    return;
}


/*
 *  �e���񕔏o��
 */

void
tamo_campaign( int yy, int mm, int dd, long g, int htmlMode )
{
    /* �L�����y�[���o�� */
    if ( htmlMode == OFF )
        campaign( g, dd, mm, yy );
}
