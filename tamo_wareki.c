/*
 *  tamo_wareki.c
 *          by H.Tsujimura  tsupo@na.rim.or.jp
 *                  17 February 1991
 *  Copyright (c) 1991-1995,1996,1999,2003,2007  Hiroshi Tsujimura
 *  All Rights Reserved.
 *
 * History :
 * $Log: tamo_wareki.c $
 * Revision 1.78  2012/08/21  07:40:48  tsujimura543
 * eto() を修正 (西暦3年以前を指定すると誤動作する不具合があった)
 *
 * Revision 1.77  2012/08/20  06:42:10  tsujimura543
 * 母倉日の算出処理を修正
 *
 * Revision 1.76  2007/02/06  11:00:03  tsujimura543
 * copyright 表記をアップデート
 *
 * Revision 1.75  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.74  2003/03/20  09:18:02  tsujimura543
 * 各種暦注の表示を追加
 *
 * Revision 1.73  2003/03/19  05:01:53  tsujimura543
 * 干支関連の出力内容修正終了
 *
 * Revision 1.72  2003/03/19  04:46:08  tsujimura543
 * 干支の出力方式を他の暦と同じにする
 *
 * Revision 1.71  2003/03/19  03:05:48  tsujimura543
 * 旧暦関係の出力方法を他の暦と同じ方式にする
 *
 * Revision 1.70  2003/03/18  10:20:50  tsujimura543
 * 出力結果がきれいになるように調整
 *
 * Revision 1.69  2003/03/17  05:44:54  tsujimura543
 * HTML出力内容を整理
 *
 * Revision 1.68  2003/03/11  02:07:11  tsujimura543
 * for Tsuporone's Activity Memo
 *
 * Revision 1.67  2003/03/06  10:27:39  tsujimura543
 * 陰遁開始日の九星が1つずれる不具合を修正
 *
 * Revision 1.66  2003/03/06  08:50:26  tsujimura543
 * 九星の算出方法を変更
 *
 * Revision 1.65  2003/02/27  10:07:05  tsujimura543
 * 大化以前は、天皇の名前で年代を表すようにした
 *
 * Revision 1.64  2003/02/27  08:41:01  tsujimura543
 * 大化以降の元号に対応
 *
 * Revision 1.63  2003/02/26  09:28:53  tsujimura543
 * 慶應以前の元号に対応(とりあえず、慶長まで対応)
 *
 * Revision 1.62  2003/02/19  08:50:49  tsujimura543
 * ユリウス日が負の値のときに曜日取得関数が誤動作する不具合を修正
 *
 * Revision 1.61  2003/02/07  04:46:41  tsujimura543
 * 和暦の月名を併記するようにした
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * Revision 1.51  1999/07/06  18:48:12  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう
 *
 * Revision 1.50  1996/08/19  02:10:16  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.6  95/12/16 05:55:16  tsujimura
 * もはや不要となった「潮」の名称のテーブルを削除
 * 
 * Revision 1.5  92/03/29 16:24:14  tsujimura
 * test release
 * 
 * Revision 1.4  91/03/17 16:16:28  tsujimura
 * test version
 * 
 * Revision 1.3  91/03/17 16:16:28  tsujimura
 * (1) changed functions for calculations of old-japanese-calendar
 * (2) added some ETO holidays
 * 
 * Revision 1.2  91/03/02 05:29:46  tsujimura
 * added many features
 * 
 * Revision 1.1  91/02/17 10:58:18  tsujimura
 * Initial revision
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamo.h"

#ifndef	lint
static char	*rcs_id =
	"$Header: C:/user/local/src/tamo/RCS/tamo_wareki.c 1.78 2012/08/21 07:40:48 tsujimura543 Exp tsujimura543 $";
#endif

#if 0
static char *gengo[]         = { "文久","元治","慶應","明治","大正","昭和","平成",0 };
static int  gengo_start_yy[] = { 1861,  1864,  1865,  1868,  1912,  1926,  1989 };
static int  gengo_start_mm[] = {  2,     2,     4,     9,     7,    12,     1 };
static int  gengo_start_dd[] = { 19,    20,     7,     8,    30,    25,     8 };
#else
static struct GENGO_TBL {
    char    *name;      /* 名称    */
    int     start_yy;   /* 開始 年 */
    int     start_mm;   /*      月 */
    int     start_dd;   /*      日 */
}   gengo_tbl[] =   {
    { "西暦",      1,  1,  1 },

    { "(応神)",  270,  1,  1 },
    { "(仁徳)",  313,  1,  3 },
    { "(履中)",  400,  2,  1 },
    { "(反正)",  406,  1,  2 },
    { "(允恭)",  412, 12,  1 },
    { "(安康)",  454,  1,  1 },
    { "(雄略)",  457,  1,  1 },
    { "(清寧)",  480,  1, 15 },
    { "(顕宗)",  485,  1,  1 },
    { "(仁賢)",  488,  1,  5 },
    { "(武烈)",  499,  1,  1 },
    { "(継体)",  507,  2,  4 },
    { "(安閑)",  534,  1,  1 },
    { "(宜化)",  536,  1,  1 },
    { "(欽明)",  540,  1,  1 },
    { "(敏達)",  572,  4,  3 },
    { "(用明)",  586,  1,  1 },
    { "(崇峻)",  588,  1,  1 },
    { "(推古)",  593,  1,  1 },
    { "(舒明)",  629,  1,  4 },
    { "(皇極)",  642,  1, 15 },

    { "大化",    645,  6, 19 },
    { "白雉",    650,  2, 15 }, /* 孝徳天皇崩御後使わなくなった */
    { "(斉明)",  655,  1,  3 },
    { "(天智)",  661,  7, 24 },
    { "(天武)",  672,  1,  1 },
    { "朱鳥",    686,  7, 20 }, /* 天武天皇崩御後使わなくなった */
    { "(持統)",  687,  1,  1 },
    { "(文武)",  697,  8,  1 },
    { "大宝",    701,  3, 21 },
    { "慶雲",    704,  5, 10 },
    { "和銅",    708,  1, 11 },
    { "霊亀",    715,  9,  2 },
    { "養老",    717, 11, 17 },
    { "神亀",    724,  2,  4 },
    { "天平",    729,  8,  5 },
    { "天平感宝",749,  4, 14 },
    { "天平勝宝",749,  7,  2 },
    { "天平宝字",757,  8, 18 },
    { "天平神護",765,  1,  7 },
    { "神護景雲",767,  8, 16 },
    { "宝亀",    770, 10,  1 },
    { "天応",    781,  1,  1 },
    { "延暦",    782,  8, 19 },
    { "大同",    806,  5, 18 },
    { "弘仁",    810,  9, 19 },
    { "天長",    824,  1,  5 },
    { "承和",    834,  1,  3 },
    { "嘉祥",    848,  6, 13 },
    { "仁寿",    851,  4, 28 },
    { "斉衡",    854, 11, 30 },
    { "天安",    857,  2, 21 },
    { "貞観",    859,  4, 15 },
    { "元慶",    877,  4, 16 },
    { "仁和",    885,  2, 21 },
    { "寛平",    889,  4, 27 },
    { "昌泰",    898,  4, 26 },
    { "延喜",    901,  7, 15 },
    { "延長",    923,  4, 11 /* 閏4月 */ },
    { "承平",    931,  4, 26 },
    { "天慶",    938,  5, 22 },
    { "天暦",    947,  4, 22 },
    { "天徳",    957, 10, 27 },
    { "応和",    961,  2, 16 },
    { "康保",    964,  7, 10 },
    { "安和",    968,  8, 15 },
    { "天禄",    970,  3, 25 },
    { "天延",    973, 12, 20 },
    { "貞元",    976,  7, 13 },
    { "天元",    978, 11, 29 },
    { "永観",    983,  4, 15 },
    { "寛和",    985,  4, 27 },
    { "永延",    987,  4,  5 },
    { "永祚",    989,  8,  8 },
    { "正暦",    990, 11,  7 },
    { "長徳",    995,  2, 22 },
    { "長保",    999,  1, 13 },
    { "寛弘",   1004,  7, 20 },
    { "長和",   1012, 12, 25 },
    { "寛仁",   1017,  4, 23 },
    { "治安",   1021,  2,  2 },
    { "万寿",   1024,  7, 13 },
    { "長元",   1028,  7, 25 },
    { "長暦",   1037,  4, 21 },
    { "長久",   1040, 11, 10 },
    { "寛徳",   1044, 11, 24 },
    { "永承",   1046,  4, 14 },   
    { "天喜",   1053,  1, 11 },
    { "康平",   1058,  8, 29 },
    { "治暦",   1065,  8,  2 },
    { "延久",   1069,  4, 13 },
    { "承保",   1074,  8, 23 },
    { "承暦",   1077, 11, 17 },
    { "永保",   1081,  2, 10 },
    { "応徳",   1084,  2,  7 },
    { "寛治",   1087,  4,  7 },
    { "嘉保",   1094, 12, 15 },
    { "永長",   1096, 12, 17 },
    { "承徳",   1097, 11, 21 },
    { "康和",   1099,  8, 28 },
    { "長治",   1104,  2, 10 },
    { "嘉承",   1106,  4,  9 },
    { "天仁",   1108,  8,  3 },
    { "天永",   1110,  7, 13 },
    { "永久",   1113,  7, 13 },
    { "元永",   1118,  4,  3 },
    { "保安",   1120,  4, 10 },
    { "天治",   1124,  4,  3 },
    { "大治",   1126,  1, 22 },
    { "天承",   1131,  1, 29 },
    { "長承",   1132,  8, 11 },
    { "保延",   1135,  4, 27 },
    { "永治",   1141,  7, 10 },
    { "康治",   1142,  4, 28 },
    { "天養",   1144,  2, 23 },
    { "久安",   1145,  7, 22 },
    { "仁平",   1151,  1, 26 },
    { "久寿",   1154, 10, 28 },
    { "保元",   1156,  4, 27 },
    { "平治",   1159,  4, 20 },
    { "永暦",   1160,  1, 10 },
    { "応保",   1161,  9,  4 },
    { "長寛",   1163,  3, 29 },
    { "永万",   1165,  6,  5 },
    { "仁安",   1166,  8, 27 },
    { "嘉応",   1169,  4,  8 },
    { "承安",   1171,  4, 21 },
    { "安元",   1175,  7, 28 },
    { "治承",   1177,  8,  4 },
    { "養和",   1181,  7, 14 },
    { "寿永",   1182,  5, 27 },
    { "元暦",   1184,  4, 16 },
    { "文治",   1185,  8, 14 },
    { "建久",   1190,  4, 11 },
    { "正治",   1199,  4, 27 },
    { "建仁",   1201,  2, 13 },
    { "元久",   1204,  2, 20 },
    { "建永",   1206,  4, 27 },
    { "承元",   1207, 10, 25 },
    { "建暦",   1211,  3,  9 },
    { "建保",   1213, 12,  6 },
    { "承久",   1219,  4, 12 },
    { "貞応",   1222,  4, 13 },
    { "元仁",   1224, 11, 20 },
    { "嘉禄",   1225,  4, 20 },
    { "安貞",   1227, 12, 10 },
    { "寛喜",   1229,  3,  5 },
    { "貞永",   1232,  4,  2 },
    { "天福",   1233,  4, 15 },
    { "文暦",   1234, 11,  5 },
    { "嘉禎",   1235,  9, 19 },
    { "暦仁",   1238, 11, 23 },
    { "延応",   1239,  2,  7 },
    { "仁治",   1240,  7, 16 },
    { "寛元",   1243,  2, 26 },
    { "宝治",   1247,  2, 28 },
    { "建長",   1249,  3, 18 },
    { "康元",   1256, 10,  5 },
    { "正嘉",   1257,  3, 14 },
    { "正元",   1259,  3, 26 },
    { "文応",   1260,  4, 13 },
    { "弘長",   1261,  2, 20 },
    { "文永",   1264,  2, 28 },
    { "建治",   1275,  4, 25 },
    { "弘安",   1278,  2, 29 },
    { "正応",   1288,  4, 28 },
    { "永仁",   1293,  8,  5 },
    { "正安",   1299,  4, 25 },
    { "乾元",   1302, 11, 21 },
    { "嘉元",   1303,  8,  5 },
    { "徳治",   1306, 12, 14 },
    { "延慶",   1308, 10,  9 },
    { "応長",   1311,  4, 28 },
    { "正和",   1312,  3, 20 },
    { "文保",   1317,  2,  3 },
    { "元応",   1319,  4, 28 },
    { "元亨",   1321,  2, 23 },
    { "正中",   1324, 12,  9 },
    { "嘉暦",   1326,  4, 26 },
    { "元徳",   1329,  8, 29 },
   /* 南北朝分裂 */
    { "明徳",   1390,  3, 26 }, /* 1393年閏10月5日、南北朝合一 */
    { "応永",   1394,  7,  5 },
    { "正長",   1428,  4, 27 },
    { "永享",   1429,  9,  5 },
    { "嘉吉",   1441,  2, 17 },
    { "文安",   1444,  2,  5 },
    { "宝徳",   1449,  7, 28 },
    { "享徳",   1452,  7, 25 },
    { "康正",   1455,  7, 25 },
    { "長禄",   1457,  9, 28 },
    { "寛正",   1460, 12, 21 },
    { "文正",   1466,  2, 28 },
    { "応仁",   1467,  3,  5 },
    { "文明",   1469,  4, 28 },
    { "長享",   1487,  7, 20 },
    { "延徳",   1489,  8, 21 },
    { "明応",   1492,  7, 19 },
    { "文亀",   1501,  2, 29 },
    { "永正",   1504,  2, 30 },
    { "大永",   1521,  8, 23 },
    { "享禄",   1528,  8, 20 },
    { "天文",   1532,  7, 29 },
    { "弘治",   1555, 10, 23 },
    { "永禄",   1558,  2, 28 },
    { "元亀",   1570,  4, 23 },
    { "天正",   1573,  7, 28 },
    { "文禄",   1592, 12,  8 },
    { "慶長",   1596, 10, 27 },
    { "元和",   1615,  7, 13 },
    { "寛永",   1624,  2, 30 },
    { "正保",   1644, 12, 16 },
    { "慶安",   1648,  2, 15 },
    { "承應",   1652,  9, 18 },
    { "明暦",   1655,  4, 13 },
    { "萬治",   1658,  7, 23 },
    { "寛文",   1661,  4, 25 },
    { "延寶",   1673,  9, 21 },
    { "天和",   1681,  9, 29 },
    { "貞享",   1684,  2, 21 },
    { "元禄",   1688,  9, 30 },
    { "寶永",   1704,  3, 13 },
    { "正徳",   1711,  4, 25 },
    { "享保",   1716,  6, 22 },
    { "元文",   1736,  4, 28 },
    { "寛保",   1741,  2, 27 },
    { "延享",   1744,  2, 21 },
    { "寛延",   1748,  7, 12 },
    { "寶暦",   1751, 10, 27 },
    { "明和",   1764,  6,  2 },
    { "安永",   1772, 11, 16 },
    { "天明",   1781,  4,  2 },
    { "寛政",   1789,  1, 25 },
    { "享和",   1801,  2,  5 },
    { "文化",   1804,  2, 11 },
    { "文政",   1818,  4, 22 },
    { "天保",   1830, 12, 10 },
    { "弘化",   1844, 12,  2 },
    { "嘉永",   1848,  2, 28 },
    { "安政",   1854, 11, 27 },
    { "萬延",   1860,  3, 18 },
    { "文久",   1861,  2, 19 },
    { "元治",   1864,  2, 20 },
    { "慶應",   1865,  4,  7 },
    { "明治",   1868,  9,  8 },
    { "大正",   1912,  7, 30 },
    { "昭和",   1926, 12, 25 },
    { "平成",   1989,  1,  8 },
    { NULL,     9999, 12, 31 }
};
#define gengo(i)            gengo_tbl[i].name
#define gengo_start_yy(i)   gengo_tbl[i].start_yy
#define gengo_start_mm(i)   gengo_tbl[i].start_mm
#define gengo_start_dd(i)   gengo_tbl[i].start_dd

static struct GENGO_TBL southGengo[] =
{  /* 《南朝》 */
    { "元弘",   1331,  8,  9 },
    { "建武",   1334,  1, 29 },
    { "延元",   1336,  2, 29 },
    { "興国",   1340,  4, 28 },
    { "正平",   1346, 12,  8 },
    { "建徳",   1370,  7, 24 },
    { "文中",   1372, 10,  4 },
    { "天授",   1375,  5, 27 },
    { "弘和",   1381,  2, 10 },
    { "元中",   1384,  4, 28 },
   /* 元中9(1392)年閏10月5日、北朝・後小松天皇に譲位(南北朝合一) */
    { NULL,     1394,  7,  5 }
};

static struct GENGO_TBL northGengo[] =
{  /* 《北朝》 */
    { "元徳",   1329,  8, 29 },
    { "正慶",   1332,  4, 28 },
   /* 正慶2(1333)年5月25日 後醍醐天皇に譲位、元号廃止 */
    { "建武",   1334,  1, 29 },
   /* 建武3(1336)年8月15日 北朝・光明天皇即位 */
    { "暦応",   1338,  8, 28 },
    { "康永",   1342,  4, 27 },
    { "貞和",   1345, 10, 21 },
    { "観応",   1350,  2, 27 },
    { "文和",   1352,  9, 27 },
    { "延文",   1356,  3, 28 },
    { "康安",   1361,  3, 29 },
    { "貞治",   1362,  9, 23 },
    { "応安",   1368,  2, 18 },
    { "永和",   1375,  2, 27 },
    { "康暦",   1379,  3, 22 },
    { "永徳",   1381,  2, 24 },
    { "至徳",   1384,  2, 27 },
    { "嘉慶",   1387,  8, 23 },
    { "康応",   1389,  2,  9 },
    { "明徳",   1390,  3, 26 },
    { NULL,     1394,  7,  5 }
};

#define sGengo(i)            southGengo[i].name
#define sGengo_start_yy(i)   southGengo[i].start_yy
#define sGengo_start_mm(i)   southGengo[i].start_mm
#define sGengo_start_dd(i)   southGengo[i].start_dd

#define nGengo(i)            northGengo[i].name
#define nGengo_start_yy(i)   northGengo[i].start_yy
#define nGengo_start_mm(i)   northGengo[i].start_mm
#define nGengo_start_dd(i)   northGengo[i].start_dd
#endif

static char	*hoshi[]     = { "九紫", "八白", "七赤", "六白", "五黄",
                                 "四緑", "三碧", "二黒", "一白" };
static char	*kan[]       = { "甲", "乙",
                                 "丙", "丁",
                                 "戊", "己",
                                 "庚", "辛",
                                 "壬", "癸" };
static char	*kan_yomi[]  = { "きのえ",   "きのと",
                                 "ひのえ",   "ひのと",
                                 "つちのえ", "つちのと",
                                 "かのえ",   "かのと",
                                 "みづのえ", "みづのと" };
static char	*shi[]       = { "子", "丑", "寅", "卯", "辰", "巳",
                                 "午", "未", "申", "酉", "戌", "亥" };
static char	*shi_yomi[]  = { "ね", "うし", "とら", "う", "たつ", "み",
                                 "うま", "ひつじ", "さる", "とり", "いぬ",
                                 "ゐ" };
static char	*yoh[]       = { "日", "月", "火", "水",
                                 "木", "金", "土" };
static char	*tsuki[]     = { "睦月", "如月",   "弥生", "卯月",
                                 "皐月", "水無月", "文月", "葉月",
                                 "長月", "神無月", "霜月", "師走" };
static char	*shuku[]     = { "角", "亢","てい","房", "心", "尾", "箕",
                                 "斗", "牛", "女", "虚", "危", "室", "壁",
                                 "奎", "婁", "胃", "昴", "畢", "觜", "参",
                                 "井", "鬼", "柳", "星", "張", "翼", "軫"};
static char	*choku[]     = { "たつ",   "のぞく", "みつ",   "たいら",
                                 "さだん", "とる",   "やぶる", "あやぶ",
                                 "なる",   "おさん", "ひらく", "とづ"   };

char    *wareki2( int d, int m, int y, int u );

char	*
wareki( int d, int m, int y, int u )
{
    static char	buf[32];
    int		i;

    if ( (y >= 1331) && (y <= 1392) ) {
        long    g      = absoluteFromGregorian( d,  m,    y );
        long    gStart = absoluteFromGregorian( 9,  8, 1331 );
        long    gEnd   = absoluteFromGregorian( 5, 10, 1392 );

        if ( (g >= gStart) && (g <= gEnd) ) {
            return ( wareki2( d, m, y, u ) );
        }
    }

    for ( i = 0; gengo(i); i++ ) {
        if ( y < gengo_start_yy(i) )
            break;
        if ( y == gengo_start_yy(i) ) {
            if ( m < gengo_start_mm(i) )
                break;
            else if ( m == gengo_start_mm(i) ) {
                if ( d < gengo_start_dd(i) )
                    break;
            }
        }
    }
    if ( --i < 0 ) {
        i++;
        y--;
    }
    y -= gengo_start_yy(i) - 1;

    if ( u )
        sprintf( buf, "%s%2d年閏%2d月(%s)%2d日",
                 gengo(i), y, m, tsuki[(m + 11) % 12], d );
    else
        sprintf( buf, "%s%2d年%2d月(%s)%2d日",
                 gengo(i), y, m, tsuki[(m + 11) % 12], d );
    return ( buf );
}


char	*
tsupodate( int day, int month, int year )
{
    static char	buf[20];

    if ( ( month == 1 ) && ( day == 1 ) )
        sprintf( buf, "%4d年    元日", year );
    else if ( ( month == 12 ) && ( day == 31 ) )
        sprintf( buf, "%4d年  大晦日", year );
    else if ( day == 1 )
        sprintf( buf, "%4d年%s朔日", year, tsuki[month-1] );
    else if ( day == lastDayOfGregorianMonth( month, year ) )
        sprintf( buf, "%4d年%s晦日", year, tsuki[month-1] );
    else
        sprintf( buf, "%4d年%s%2d日", year, tsuki[month-1], day );
    if ( ( month != 6 ) && ( month != 10 ) ) {
        register char	*p = &buf[15];
        register int	i;

        for ( i = 0; i < 16; i++, p-- )
            *( p + 2 ) = *p;
        buf[0] = ' ';
        buf[1] = ' ';
    }

    return ( buf );
}

/*
 * 九星算出処理
 *	九星はある種の日を境目にして遷移方向が逆転する
 *	例えば 1990年12月24日 までは 九紫→八白→七赤→…→一白 の順で遷移す
 *	るが、 1990年12月25日 からは 一白→二黒→三碧→…→九紫 の順で遷移す
 *	る。次はいつ変わるのか、不勉強のため不明である。遷移方向の逆転日の算
 *	出は今後の課題である                                  1991.02.17
 *  -----------------------------------------------------------------------
 *      暦を見てみると180日（甲子3回）毎に変わるようである
 *      (または、夏至に最も近い九紫、冬至に最も近い一白で変わる??)
 *                                                            1991.02.24
 *  -----------------------------------------------------------------------
 *  九星の算出方法は流派により、いろいろなものが存在することが判明。
 *  九星は中国で考案されたものだが、日本に入ってくるときに、日本独自のアレ
 *  ンジが加えられ、さらにいろいろな流派に分かれたことが原因。
 *
 *    ・陽遁
 *       一白→二黒→三碧→…→九紫 の順位で遷移
 *    ・陰遁
 *       九紫→八白→七赤→…→一白 の順位で遷移
 *
 *   陽遁と陰遁の切替え時期
 *    以下のように、いろいろな流派が存在する
 *     * 夏至、冬至
 *     * 冬至に最も近い甲子の日を一白として陽遁を始め、夏至に
 *       最も近い甲子の日を九紫として陰遁を始める
 *       (冬至・夏至の直後ではなく、直前の場合もあり得る)
 *     * 冬至に最も近い甲子の日を一白として陽遁を始め、夏至に
 *       最も近い甲子の日を九紫として陰遁を始める。ただし、冬
 *       至・夏至の前後1日以内に甲午がある場合、つまり冬至・
 *       夏至が癸巳・甲午・乙未のいづれかである場合は、その甲
 *       午の日で切り替えるが、冬至前後の甲午日は七赤から、夏
 *       至前後の甲午日は三碧から始める(これを閏という)。
 *     * 冬至直後の九紫、夏至直後の一白
 *     * 冬至直前の九紫、夏至直前の一白
 *     * 夏至・冬至ではなく、小暑・小寒で陰遁・陽遁を切り替える
 *     * 60年ごとに、陰遁・陽遁の順序を逆転させる(「夏至近辺で陽
 *       遁開始、冬至近辺で陰遁開始」というパターンと「夏至近辺
 *       で陰遁開始、冬至近辺で陽遁開始」というパターンを60年ご
 *       とに切替える)
 *     * 流派によっては「陰遁」のみで「陽遁」は存在しない
 *     * その他、いろいろ
 *
 *   本プログラムでは、以下の算出方法を採用する。
 *     陽遁開始: 冬至に最も近い甲子(一白)
 *     陰遁開始: 陽遁開始日の180日後(九紫)
 *
 *     [以前採用していた算出方法]
 *       陽遁開始: 1990年12月25日および、その360の倍数日前・後
 *       陰遁開始: 陽遁開始日の180日前・後
 *         この方法だと、夏至や冬至の日を求めることなく、全ての日の
 *         九星を算出可能である(正確に180日ごとに陽遁・陰遁が入れ替
 *         わる)。しかし、毎年、365 - 180 * 2 = 5日(または6日)づつ陽
 *         遁開始日がずれていくという欠点がある。
 *
 *   参考
 *    Yoshifumi Mori(森佳史)氏の today では、
 *      冬至の干支が
 *        甲子 ～ 壬辰 のとき
 *          陽遁開始: 冬至の直前の一白の日から
 *        丙申 ～ 癸亥 のとき
 *          陽遁開始: 冬至の直後の一白の日から
 *        それ以外 (癸巳,甲午,乙未) のとき
 *          陽遁開始: 冬至に近い七赤の日から
 *      夏至の干支が
 *        甲子 ～ 壬辰 のとき
 *          陰遁開始: 夏至の直前の九紫の日から
 *        丙申 ～ 癸亥 のとき
 *          陰遁開始: 夏至の直後の九紫の日から
 *        それ以外 (癸巳,甲午,乙未) のとき
 *          陰遁開始: 夏至に近い三碧の日から
 *    という算出方法を採用している。
 *
 *      例: 2003年 3月 6日
 *        本プログラム [以前採用していた算出方法]
 *           グレゴリオ暦    2003年   3月(March) 6日  木曜日  Lent
 *           和暦 太陽歴     平成15年 3月(弥生)  6日  九紫  角  とづ  三隣亡
 *                太陰太陽暦 平成15年 2月(如月)  4日  大安  啓蟄  中潮
 *                干支       癸未(みづのとひつじ)の年 戊寅(つちのえとら)の日
 *                           小犯土
 *
 *        本プログラム [新しい算出方法]
 *           グレゴリオ暦    2003年   3月(March) 6日  木曜日  Lent
 *           和暦 太陽歴     平成15年 3月(弥生)  6日  三碧  角  とづ  三隣亡
 *                太陰太陽暦 平成15年 2月(如月)  4日  大安  啓蟄  中潮
 *                干支       癸未(みづのとひつじ)の年 戊寅(つちのえとら)の日
 *                           小犯土
 *
 *        森氏の today
 *           2003年 3月 6日 (木曜日)
 *           旧暦     2003年 2月 4日 (大安) [中潮] 
 *           干支     癸未 (みずのとひつじ) の年、戊寅 (つちのえとら) の日
 *           九星     三碧
 *           十二直   閉
 *           二十八宿 角
 *           啓蟄 三隣亡 一粒万倍日 小犯土 帰忌日 天赦日
 */

char	*
kyusei( long j )    /* j: ユリウス日 */
{
    int     hday;

#if 0
    long    change;

    /* 以下の計算式は、1990年12月25日が陽遁開始日である、という事実(?)を
       基にしている */
    j -= 3;
    change = ( j + 17 ) % 360;

    /* 180日ごとに陽遁・陰遁を繰り返す */
    hday   = ( change >= 180 ) ? ( j - 1 ) % 9      /* 陰遁 */
                               : ( 9 - j % 9 ) % 9; /* 陽遁 */
#else
    int     yy, mm, dd;
    long    midWinterDay, kouShiDay;
    int     kanShi;

    gregorianFromAbsolute( j, &dd, &mm, &yy );
    midWinterDay = getSekkiDate( 20, 12, yy );      /* 冬至 */

    /* 冬至に近い甲子の日 */
    do {
        kanShi = ( midWinterDay + 14 ) % 60;    /* 冬至の干支 */
        if ( kanShi < 30 ) {
            /* 冬至に近い甲子の日は、冬至より前 */
            kouShiDay = midWinterDay - kanShi;
        }
        else {
            /* 冬至に近い甲子の日は、冬至より後 */
            kouShiDay = midWinterDay + (60 - kanShi);
        }
        if ( j < kouShiDay ) {
            yy--;
            midWinterDay = getSekkiDate( 20, 12, yy );  /* 1年前の冬至 */
        }
    } while ( j < kouShiDay );

    hday   = (j >= kouShiDay + 180)
                ? ( j - kouShiDay + 9 ) % 9    	        /* 陰遁 */
                : ( 9 - ( j - kouShiDay + 1 ) % 9) % 9; /* 陽遁 */
#endif

    return ( hoshi[ hday ] );	/* 九星 */
}

/*
 *	干支
 *
 * 甲子 0 乙丑 1 丙寅 2 丁卯 3 戊辰 4 己巳 5 庚午 6 辛未 7 壬申 8 癸酉 9
 * 甲戌10 乙亥11 丙子12 丁丑13 戊寅14 己卯15 庚辰16 辛巳17 壬午18 癸未19
 * 甲申20 乙酉21 丙戌22 丁亥23 戊子24 己丑25 庚寅26 辛卯27 壬辰28 癸巳29
 * 甲午30 乙未31 丙申32 丁酉33 戊戌34 己亥35 庚子36 辛丑37 壬寅38 癸卯39
 * 甲辰40 乙巳41 丙午42 丁未43 戊申44 己酉45 庚戌46 辛亥47 壬子48 癸丑49
 * 甲寅50 乙卯51 丙辰52 丁巳53 戊午54 己未55 庚申56 辛酉57 壬戌58 癸亥59
 */
char	*
eto( long j, int year, int htmlMode )
{
    int         kyear, syear, kday, sday;
    static char buf[64];

    kyear = ( year - 4 ) % 10; syear = ( year - 4 ) % 12;
    kday  = ( j + 4 ) % 10;    sday  = ( j + 2 ) % 12;

    while (kyear < 0)
        kyear += 10;
    while (syear < 0)
        syear += 12;

    sprintf( buf, "%s%s(%s%s)の年%s%s%s(%s%s)の日",
             kan[kyear],       shi[syear],
             kan_yomi[kyear],  shi_yomi[syear],
             htmlMode ? "<BR>" : " ",
             kan[kday],        shi[sday],
             kan_yomi[kday],   shi_yomi[sday] );

    return ( buf );
}

void
checkEto( long j, int htmlMode )
{
    long    ks;
    int     reset = 1;

    ks = ( j + 14 ) % 60;
    if ( ( ks >= 20 ) && ( ks <= 29 ) ) /* 甲申 から 癸巳 */
        tprintf( htmlMode, &reset, "  十方暮" );
    if ( ks == 29 )                     /* 癸巳 */
        tprintf( htmlMode, &reset, "  天一天上" );
    if ( ( ks == 48 ) || ( ( ks >= 50 ) && ( ks <= 53 ) ) ||
         ( ks == 56 ) || ( ks == 57 ) || ( ks == 59 ) )
        /* 壬子, 甲寅, 乙卯, 丙辰, 丁巳, 庚申, 辛酉, 癸亥 */
        tprintf( htmlMode, &reset, "  八専" );
    if ( ( ks >=6 ) && ( ks <= 12 ) )   /* 庚午 から 丙子 */
        tprintf( htmlMode, &reset, "  大犯土" );
    if ( ( ks >= 14 ) && ( ks <= 20 ) ) /* 戊寅 から 甲申 */
        tprintf( htmlMode, &reset, "  小犯土" );

    if ( reset == 1 ) {
        if ( htmlMode )
            fputs( "<BR>", stdout );
    }
}

/*
 *	七曜
 */
char	*
weekday( long g )
{
    while ( g < 0 ) {
        g += 7;
    }

    return ( yoh[ g % 7 ] );	/* 曜日 */
}

/*
 *	廿八宿
 */
char	*
nijuhachishuku( long g )
{
	return ( shuku[ ( g - 4 ) % 28 ] );
}

/*
 *	十二直 (中段)
 *		二十四節気の「節」とその前日 (本来の「節分」) で同一の「直」を
 *		用いる以外は、順に遷移していく
 *		したがって、任意の日の「直」を求めるには二十四節気を求める必要
 *		がある
 *
 *	たつ	 0	のぞく	 1	みつ	 2	たいら	 3
 *	さだん	 4	とる	 5	やぶる	 6	あやぶ	 7
 *	なる	 8	おさん	 9	ひらく	10	とづ	11
 */

char	*
junichoku( long g, int dd, int mm, int yy, int *tsuki, long *fushi )
{
    static char	buf[80];
    long        g0 = 0, g2;
    int		si, sday;

    *fushi = g0 = setsuStartDay( mm, yy );	/* 節入りの日 */
    si = mm % 12;
    g2 = g0;
    do {
        sday = ( g2 + 2 ) % 12;
        g2++;
    } while ( sday != si );
    g2--;	/* g2: 節に対応する最初の「建(たつ)」の日 */
    if ( g >= g2 ) {
        strcpy( buf, choku[(g-g2)%12] );
        *tsuki = (mm - 1) % 12;
    }
    else if ( g >= g0 ) {
        strcpy( buf, choku[(12-((g2-g)%12))%12] );
        *tsuki = (mm - 1) % 12;
    }
    else {
        strcpy( buf, choku[(12-((g2-g-1)%12))%12] );
        *tsuki = (mm - 2) % 12;
    }

    return ( buf );
}


char    *
sanrinbou( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "三隣亡";

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  4 : /* 旧 4月 */
    case  7 : /* 旧 7月 */
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 11 )	/* 亥 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
    case  5 : /* 旧 5月 */
    case  8 : /* 旧 8月 */
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 2 )	/* 寅 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
    case  6 : /* 旧 6月 */
    case  9 : /* 旧 9月 */
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 6 )	/* 午 */
            p = q;
        break;
    }

    return( p );
}

char    *
manbaibi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "一粒万倍日";
    int     eto = ( g + 2 ) % 12;

#if     0
    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
	if ( (eto == 1) || (eto == 6) ) /* 丑, 午 */
	    p = q;
	break;
    case  2 : /* 旧 2月 */
	if ( (eto == 2) || (eto == 9) ) /* 寅, 酉 */
	    p = q;
	break;
    case  3 : /* 旧 3月 */
	if ( (eto == 3) || (eto == 0) ) /* 卯, 子 */
	    p = q;
	break;
    case  4 : /* 旧 4月 */
	if ( (eto == 4) || (eto == 3) ) /* 辰, 卯 */
	    p = q;
	break;
    case  5 : /* 旧 5月 */
	if ( (eto == 5) || (eto == 6) ) /* 巳, 午 */
	    p = q;
	break;
    case  6 : /* 旧 6月 */
	if ( (eto == 6) || (eto == 9) ) /* 午, 酉 */
	    p = q;
	break;
    case  7 : /* 旧 7月 */
	if ( (eto == 7) || (eto == 0) ) /* 未, 子 */
	    p = q;
	break;
    case  8 : /* 旧 8月 */
	if ( (eto == 8) || (eto == 3) ) /* 申, 卯 */
	    p = q;
	break;
    case  9 : /* 旧 9月 */
	if ( (eto == 9) || (eto == 6) ) /* 酉, 午 */
	    p = q;
	break;
    case 10 : /* 旧10月 */
	if ( (eto == 10) || (eto == 9) )/* 戌, 酉 */
	    p = q;
        break;
    case 11 : /* 旧11月 */
	if ( (eto == 11) || (eto == 0) )/* 亥, 子 */
	    p = q;
        break;
    case  0 : /* 旧12月 */
	if ( (eto == 0) || (eto == 3) ) /* 子, 卯 */
	    p = q;
        break;
    }
#else
    if ( (eto == tsuki) || (eto == (((tsuki + 1) * 3) % 12)) )
	p = q;
#endif

    return( p );
}


char    *
kurobi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "受死日";

#if     0
    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
        if ( ( g + 2 ) % 12 == 10 )	/* 戌 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
        if ( ( g + 2 ) % 12 == 4 )	/* 辰 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
        if ( ( g + 2 ) % 12 == 11 )	/* 亥 */
            p = q;
        break;
    case  4 : /* 旧 4月 */
        if ( ( g + 2 ) % 12 == 5 )	/* 巳 */
            p = q;
        break;
    case  5 : /* 旧 5月 */
        if ( ( g + 2 ) % 12 == 0 )	/* 子 */
            p = q;
        break;
    case  6 : /* 旧 6月 */
        if ( ( g + 2 ) % 12 == 6 )	/* 午 */
            p = q;
        break;
    case  7 : /* 旧 7月 */
        if ( ( g + 2 ) % 12 == 1 )	/* 丑 */
            p = q;
        break;
    case  8 : /* 旧 8月 */
        if ( ( g + 2 ) % 12 == 7 )	/* 未 */
            p = q;
        break;
    case  9 : /* 旧 9月 */
        if ( ( g + 2 ) % 12 == 2 )	/* 寅 */
            p = q;
        break;
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 8 )	/* 申 */
            p = q;
        break;
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 3 )	/* 卯 */
            p = q;
        break;
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 9 )	/* 酉 */
            p = q;
        break;
    }
#else
    if ( (tsuki % 2) == 1 ) {
        if ( (( g + 2 ) % 12) == (((tsuki / 2) + 10) % 12) )
            p = q;
    }
    else {
	if ( tsuki == 0 )
	    tsuki = 12;
        if ( (( g + 2 ) % 12) == (((tsuki / 2) +  3) % 12) )
            p = q;
    }
#endif

    return( p );
}


char    *
jisshinichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "十死日";

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  4 : /* 旧 4月 */
    case  7 : /* 旧 7月 */
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 9 )	/* 酉 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
    case  5 : /* 旧 5月 */
    case  8 : /* 旧 8月 */
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 5 )	/* 巳 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
    case  6 : /* 旧 6月 */
    case  9 : /* 旧 9月 */
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 1 )	/* 丑 */
            p = q;
        break;
    }

    return( p );
}


char    *
kikonichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "帰忌日";

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  4 : /* 旧 4月 */
    case  7 : /* 旧 7月 */
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 1 )	/* 丑 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
    case  5 : /* 旧 5月 */
    case  8 : /* 旧 8月 */
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 2 )	/* 寅 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
    case  6 : /* 旧 6月 */
    case  9 : /* 旧 9月 */
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 0 )	/* 子 */
            p = q;
        break;
    }

    return( p );
}


char    *
fukunichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "復日";
    int     kan = ( g + 4 ) % 10;

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  7 : /* 旧 7月 */
        if ( (kan == 0) || (kan == 6) )	/* 甲, 庚 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
    case  8 : /* 旧 8月 */
        if ( (kan == 1) || (kan == 7) )	/* 乙, 辛 */
            p = q;
	break;
    case  3 : /* 旧 3月 */
    case  6 : /* 旧 6月 */
    case  9 : /* 旧 9月 */
    case  0 : /* 旧12月 */
        if ( (kan == 4) || (kan == 5) )	/* 戊, 己 */
            p = q;
	break;
    case  4 : /* 旧 4月 */
    case 10 : /* 旧10月 */
        if ( (kan == 2) || (kan == 8) )	/* 丙, 壬 */
            p = q;
        break;
    case  5 : /* 旧 5月 */
    case 11 : /* 旧11月 */
        if ( (kan == 3) || (kan == 9) )	/* 丁, 癸 */
            p = q;
        break;
    }

    return( p );
}


char    *
chiImiNichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "血忌日";

#if     0
    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
        if ( ( g + 2 ) % 12 == 1 )	/* 丑 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
        if ( ( g + 2 ) % 12 == 7 )	/* 未 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
        if ( ( g + 2 ) % 12 == 2 )	/* 寅 */
            p = q;
        break;
    case  4 : /* 旧 4月 */
        if ( ( g + 2 ) % 12 == 8 )	/* 申 */
            p = q;
        break;
    case  5 : /* 旧 5月 */
        if ( ( g + 2 ) % 12 == 3 )	/* 卯 */
            p = q;
        break;
    case  6 : /* 旧 6月 */
        if ( ( g + 2 ) % 12 == 9 )	/* 酉 */
            p = q;
        break;
    case  7 : /* 旧 7月 */
        if ( ( g + 2 ) % 12 == 4 )	/* 辰 */
            p = q;
        break;
    case  8 : /* 旧 8月 */
        if ( ( g + 2 ) % 12 == 10 )	/* 戌 */
            p = q;
        break;
    case  9 : /* 旧 9月 */
        if ( ( g + 2 ) % 12 == 5 )	/* 巳 */
            p = q;
        break;
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 11 )	/* 亥 */
            p = q;
        break;
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 6 )	/* 午 */
            p = q;
        break;
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 0 )	/* 子 */
            p = q;
        break;
    }
#else
    if ( (tsuki % 2) == 1 ) {
        if ( (( g + 2 ) % 12) == (((tsuki / 2) + 1) % 12) )
            p = q;
    }
    else {
	if ( tsuki == 0 )
	    tsuki = 12;
        if ( (( g + 2 ) % 12) == (((tsuki / 2) +  6) % 12) )
            p = q;
    }
#endif

    return( p );
}


char    *
tenKaNichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "天火日";

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  5 : /* 旧 5月 */
    case  9 : /* 旧 9月 */
        if ( ( g + 2 ) % 12 == 0 )	/* 子 */
            p = q;
        break;
    case  2 : /* 旧 2月 */
    case  6 : /* 旧 6月 */
    case 10 : /* 旧10月 */
        if ( ( g + 2 ) % 12 == 3 )	/* 卯 */
            p = q;
        break;
    case  3 : /* 旧 3月 */
    case  7 : /* 旧 7月 */
    case 11 : /* 旧11月 */
        if ( ( g + 2 ) % 12 == 6 )	/* 午 */
            p = q;
        break;
    case  4 : /* 旧 4月 */
    case  8 : /* 旧 8月 */
    case  0 : /* 旧12月 */
        if ( ( g + 2 ) % 12 == 9 )	/* 酉 */
            p = q;
        break;
    }

    return( p );
}


char    *
jiKaNichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "地火日";

    if ( (( g + 2 ) % 12) == ((tsuki + 4) % 12) )
	p = q;

    return( p );
}


char    *
ouMouNichi( long g, int tsuki, long fushi )
{
    char    *p = NULL;
    char    *q = "往亡日";

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
        if ( g == fushi + 6 )
            p = q;
        break;
    case  2 : /* 旧 2月 */
        if ( g == fushi + 13 )
            p = q;
        break;
    case  3 : /* 旧 3月 */
        if ( g == fushi + 20 )
            p = q;
        break;
    case  4 : /* 旧 4月 */
        if ( g == fushi + 7 )
            p = q;
        break;
    case  5 : /* 旧 5月 */
        if ( g == fushi + 15 )
            p = q;
        break;
    case  6 : /* 旧 6月 */
        if ( g == fushi + 23 )
            p = q;
        break;
    case  7 : /* 旧 7月 */
        if ( g == fushi + 8 )
            p = q;
        break;
    case  8 : /* 旧 8月 */
        if ( g == fushi + 17 )
            p = q;
        break;
    case  9 : /* 旧 9月 */
        if ( g == fushi + 26 )
            p = q;
        break;
    case 10 : /* 旧10月 */
        if ( g == fushi + 9 )
            p = q;
        break;
    case 11 : /* 旧11月 */
        if ( g == fushi + 19 )
            p = q;
        break;
    case  0 : /* 旧12月 */
        if ( g == fushi + 29 )
            p = q;
        break;
    }

    return( p );
}


char    *
boSouNichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "母倉日";
    int     eto = ( g + 2 ) % 12;

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  2 : /* 旧 2月 */
	if ( (eto == 0) || (eto == 11) )/* 子, 亥 */
	    p = q;
	break;
    case  3 : /* 旧 3月 */
    case  6 : /* 旧 6月 */
    case  9 : /* 旧 9月 */
    case  0 : /* 旧12月 */
	if ( (eto == 5) || (eto == 6) )	/* 巳, 午 */
	    p = q;
	break;
    case  4 : /* 旧 4月 */
    case  5 : /* 旧 5月 */
	if ( (eto == 2) || (eto == 3) )	/* 寅, 卯 */
            p = q;
        break;
    case  7 : /* 旧 7月 */
    case  8 : /* 旧 8月 */
	if ( (eto == 1) || (eto == 4) ||
	     (eto == 7) || (eto == 10))	/* 丑, 辰, 未, 戌 */
            p = q;
        break;
    case 10 : /* 旧10月 */
    case 11 : /* 旧11月 */
	if ( (eto == 8) || (eto == 9) )	/* 申, 酉 */
            p = q;
        break;
    }

    return( p );
}


char    *
tsukiTokuNichi( long g, int tsuki )
{
    char    *p = NULL;
    char    *q = "月徳日";
    int     kan = ( g + 4 ) % 10;

    switch ( tsuki ) {
    case  1 : /* 旧 1月 */
    case  5 : /* 旧 5月 */
    case  9 : /* 旧 9月 */
	if ( kan == 2 )     /* 丙 */
	    p = q;
	break;
    case  2 : /* 旧 2月 */
    case  6 : /* 旧 6月 */
    case 10 : /* 旧10月 */
	if ( kan == 0 )     /* 甲 */
	    p = q;
	break;
    case  3 : /* 旧 3月 */
    case  7 : /* 旧 7月 */
    case 11 : /* 旧11月 */
	if ( kan == 8 )     /* 壬 */
            p = q;
        break;
    case  4 : /* 旧 4月 */
    case  8 : /* 旧 8月 */
    case  0 : /* 旧12月 */
	if ( kan == 8 )     /* 己 */
            p = q;
	break;
    }

    return( p );
}


char	*
japaneseMonthName( int mm )
{
    return ( tsuki[(mm + 11) % 12] );
}


/* 南北朝時代の和暦表示 */
char	*
wareki2( int d, int m, int y, int u )
{
    static char buf[48];
    int         i, j;
    int         nY = y, sY = y;

    for ( i = 0; nGengo(i); i++ ) {
        if ( nY < nGengo_start_yy(i) )
            break;
        if ( nY == nGengo_start_yy(i) ) {
            if ( m < nGengo_start_mm(i) )
                break;
            else if ( m == nGengo_start_mm(i) ) {
                if ( d < nGengo_start_dd(i) )
                    break;
            }
        }
    }
    if ( --i < 0 ) {
        i++;
        nY--;
    }
    nY -= nGengo_start_yy(i) - 1;

    for ( j = 0; sGengo(j); j++ ) {
        if ( sY < sGengo_start_yy(j) )
            break;
        if ( sY == sGengo_start_yy(j) ) {
            if ( m < sGengo_start_mm(j) )
                break;
            else if ( m == sGengo_start_mm(j) ) {
                if ( d < sGengo_start_dd(j) )
                    break;
            }
        }
    }
    if ( --j < 0 ) {
        j++;
        sY--;
    }
    sY -= sGengo_start_yy(j) - 1;

    if ( u )
	    sprintf( buf, "%s%2d年(北)/%s%2d年(南) 閏%2d月(%s)%2d日",
                 nGengo(i), nY, sGengo(j), sY,
                 m, tsuki[(m + 11) % 12], d );
    else
	    sprintf( buf, "%s%2d年(北)/%s%2d年(南) %2d月(%s)%2d日",
                 nGengo(i), nY, sGengo(j), sY,
                 m, tsuki[(m + 11) % 12], d );
    return ( buf );
}

