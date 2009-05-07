/*
 *  bmt.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                      29 May 2006
 *  Copyright (c) 2006  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: bmt.c $
 * Revision 1.2  2006/05/30  01:49:05  tsujimura543
 * @000 �ƕ\�����ׂ��Ƃ���� @1000 �ƕ\�����Ă��܂��s����C��
 *
 * Revision 1.1  2006/05/29  05:09:16  tsujimura543
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamo.h"

/* Swatch Internet Time (Beat) / Biel Mean Time (BMT)                */
/* Beat �Ƃ́ASwatch �{�Ђ̂���X�C�X�̕W������ 0 ���� @000 �Ƃ��āA */
/* 1����1000������������ (1000Beat=1�� / 1�b=5/432 Beat)             */

char    *
beatFromAbsolute( int HH, int MM, int SS )
{
    static char dateString[16];
    long        gmt  = ((HH * 60 + MM) * 60 + SS) - 9 * 60 * 60;    /* GMT */
    long        bmt  = (gmt < 0 ? gmt + 24 * 60 * 60 : gmt) + 1 * 60 * 60;
                                                           /* �X�C�X�W���� */
    long        beat = bmt * 1000 / (24 * 60 * 60);

    sprintf( dateString, "@%03d", beat % 1000 );
    return ( dateString );
}

