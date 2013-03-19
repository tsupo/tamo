/*
;; The following Lisp code is from ``Calendrical Calculations'' by Nachum
;; Dershowitz and Edward M. Reingold, Software---Practice & Experience,
;; vol. 20, no. 9 (September, 1990), pp. 899--928.
;;
;; This code is in the public domain, but any use of it should
;; acknowledge its source.
*/

/*
 *  dates.c
 *      translated and modified by H.Tsujimura tsupo@na.rim.or.jp
 *                                              17 February 1991
 *      このソースプログラムは
 *              "Calendrical Calculations"
 *                      Nachum Dershowitz and Edward M. Reingold,
 *                      Software---Practice & Experience,
 *                      vol. 20, no. 9 (September, 1990), pp. 899--928.
 *      に収録されているLISPプログラムを Hiroshi Tsujimura が C プログ
 *      ラムに移植したものである
 *
 * History :
 * $Log: dates.c $
 * Revision 1.72  2007/02/08  06:42:19  tsujimura543
 * 夏時間関連の処理を修正
 *
 * Revision 1.71  2007/02/08  02:44:01  tsujimura543
 * 夏時間の開始、終了関連処理を変更・追加
 *
 * Revision 1.70  2003/11/11  07:02:19  tsujimura543
 * K&R 表記 → ANSI C 表記 に完全移行
 *
 * Revision 1.69  2003/04/23  06:08:54  tsujimura543
 * ソースコード整理
 *
 * Revision 1.68  2003/04/16  05:55:48  tsujimura543
 * tamo.h 変更に伴う修正 (機能上の修正はない)
 *
 * Revision 1.67  2003/03/31  11:24:31  tsujimura543
 * 和暦(太陽太陰暦)関連およびISO関連修正
 * フランス革命暦の表示可能期間を拡張
 *
 * Revision 1.66  2003/03/31  05:23:50  tsujimura543
 * ヘッダファイルの依存関係を整理
 *
 * Revision 1.65  2003/03/11  01:43:30  tsujimura543
 * 閏年か否かを判定するマクロをヘッダファイルに移動
 *
 * Revision 1.64  2003/02/28  07:30:49  tsujimura543
 * ユリウス暦の月名表示(ラテン語)を追加
 *
 * Revision 1.63  2003/02/19  08:56:52  tsujimura543
 * 0年1月1日を指定するとISO形式の日付を求める処理でクラッシュする
 * 不具合を修正
 *
 * Revision 1.62  2003/02/07  04:46:02  tsujimura543
 * イスラム暦の月名を併記するようにした
 *
 * Revision 1.61  2003/02/06  09:41:58  tsujimura543
 * ユダヤ歴の祝祭日を追加
 *
 * Revision 1.60  2001/02/20  12:23:36  tsujimura543
 * 他の派生バージョンと統合するため、いったん revision を固定
 *
 * 
 * Revision 1.52  2000/08/23  10:57:41  tsujimura543
 * (1) ヨーロッパでの夏時間の開始日算出関数を追加。
 * (2) アメリカでの夏時間の開始日算出関数を修正(1987年以前は、夏時間の開始日の
 *     決定方法が現在と違っていた)
 * 
 * Revision 1.51  1999/02/22  20:56:02  tsujimura543
 * 開発環境を Win32 に移す
 * -- HTML 出力対応作業や動作確認は今後もUNIX (peach.na.rim.or.jp) 上で行なう 
 *
 * Revision 1.50  1997/01/23  18:06:30  tsujimura
 * Withdrawal from `shizuka' (UNIX上での開発終了版)
 *
 * Revision 1.6  95/12/03 11:47:26  tsujimura
 * コメントの整理・修正
 * 
 * Revision 1.5  92/03/29 03:46:08  tsujimura
 * test release
 * 
 * Revision 1.4  91/03/10 07:09:34  tsujimura
 * test version
 * 
 * Revision 1.3  91/03/10 07:09:34  tsujimura
 * changed functions for calculation of old-japanese-calendar
 * 
 * Revision 1.2  91/03/02 05:37:50  tsujimura
 * added many features
 * 
 * Revision 1.1  91/02/17 10:58:32  tsujimura
 * Initial revision
 * 
 */

#ifndef lint
static char     *rcs_id =
        "$Header: C:/user/local/src/tamo/RCS/dates.c 1.72 2007/02/08 06:42:19 tsujimura543 Exp tsujimura543 $";
#endif

/*
(defun quotient (m n)
   (floor (/ m n)))

(defun extract-month (date)
;; Month field of $date$ = (month day year).
  (first date))

(defun extract-day (date)
;; Day field of $date$ = (month day year).
  (second date))
  
(defun extract-year (date)
;; Year field of $date$ = (month day year).
  (third date))

(defmacro sum (expression index initial condition)
;; Sum $expression$ for $index$ = $initial$ and successive integers,
;; as long as $condition$ holds.
  (let* ((temp (gensym)))
    `(do ((,temp 0 (+ ,temp ,expression))
          (,index ,initial (1+ ,index)))
         ((not ,condition) ,temp))))
*/
#ifdef  TAMO
#include <stdio.h>
#include <stdlib.h>
#include "tamo.h"
#else
#include "dates.h"
#endif

#define sum(expression,index,initial,condition,result) \
        for ( (index) = (initial); (condition); (index) += 1 ) \
                (result) += (expression);

/*
(defun last-day-of-gregorian-month (month year)
;; Last day in Gregorian $month$ during $year$.
  (if ;; February in a leap year
      (and (= month 2)
           (= (mod year 4) 0)
           (not (member (mod year 400) (list 100 200 300))))
;; Then return
      29
;; Else return
    (nth (1- month)
         (list 31 28 31 30 31 30 31 31 30 31 30 31))))
*/

int
lastDayOfGregorianMonth( int month, int year )
{
    int     ret = 0;

    if ( ( month == FEBRUARY ) && leapyear( year ) )
        ret = 29;
    else {
        static int  m[] = { 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31 };
        ret = m[month-1];
    }
    return ( ret );
}

/*
(defun absolute-from-gregorian (date)
;; Absolute date equivalent to the Gregorian $date$.
  (let* ((month (extract-month date))
         (year (extract-year date)))
;;  Return
    (+ (extract-day date)    ;; Days so far this month.
       (sum                  ;; Days in prior months this year.
        (last-day-of-gregorian-month m year) m 1 (< m month))
       (* 365 (1- year))     ;; Days in prior years.
       (quotient (1- year) 4);; Julian leap days in prior years...
       (-                    ;; ...minus prior century years...
        (quotient (1- year) 100))
       (quotient             ;; ...plus prior years divisible...
        (1- year) 400))))    ;; ...by 400.
*/
long
absoluteFromGregorian( int day, int month, int year )
{
    long    d = day, y = year - 1;
    int     m;

    sum( lastDayOfGregorianMonth(m,year), m, 1, m<month, d );
    d += 365 * y + y / 4 - y / 100 + y / 400;
    return ( d );
}

/*
(defun gregorian-from-absolute (date)
;; Gregorian (month day year) corresponding absolute $date$.
  (let* ((approx (quotient date 366));; Approximation from below.
         (year          ;; Search forward from the approximation.
          (+ approx
             (sum 1 y approx
                  (>= date
                      (absolute-from-gregorian
                       (list 1 1 (1+ y)))))))
         (month         ;; Search forward from January.
          (1+ (sum 1 m 1
                   (> date
                      (absolute-from-gregorian
                       (list m
                             (last-day-of-gregorian-month m year)
                             year))))))
         (day           ;; Calculate the day by subtraction.
          (- date (1- (absolute-from-gregorian
                       (list month 1 year))))))
;;  Return
    (list month day year)))
*/
void
gregorianFromAbsolute( long date, int *d, int *m, int *y )
{
    long    approx = date / 366;
    int     month = 1, year = approx;
    int     mm, yy;

    sum( 1, yy, approx, date>=absoluteFromGregorian(1,1,yy+1), year );
    *y = yy = year;
    sum( 1, mm, 1,
        date>absoluteFromGregorian(lastDayOfGregorianMonth(mm,yy),mm,yy),
        month );
    *m = month;
    *d = date - absoluteFromGregorian( 1, month, year ) + 1L;
}

/*
(defun Kday-on-or-before (date k)
;; Absolute date of the $k$day on or before $date$.
;; $k=0$ means Sunday, $k=1$ means Monday, and so on.
  (- date (mod (- date k) 7)))
*/
long
KdayOnOrBefore( long date, long k )
{
    return ( date - ( ( date - k ) % 7 ) );
}

#if     0
/*
(defun absolute-from-iso (date)
;; Absolute date equivalent to ISO $date$ = (week day year).
  (let* ((week (first date))
         (day (second date))
         (year (third date)))
;;  Return
    (+ (Kday-on-or-before
        (absolute-from-gregorian (list 1 4 year))
        1)                       ;;  Days in prior years.
       (* 7 (1- week))           ;;  Days in prior weeks this year.
       (1- day))))               ;;  Prior days this week.
*/
long
absoluteFromIso( int week, int day, int year )
{
    long    ww = week, dd = day, yy = year;

    return ( KdayOnOrBefore( absoluteFromGregorian(4,1,yy), 1 ) +
                             7 * ( ww - 1 ) + dd - 1 );
}

/*
(defun iso-from-absolute (date)
;; ISO (week day year) corresponding to the absolute $date$.
  (let* ((approx
          (extract-year (gregorian-from-absolute (- date 3))))
         (year (if (>= date
                       (absolute-from-iso (list 1 1 (1+ approx))))
                ;; Then
                   (1+ approx)
                ;; Else
                   approx))
         (week (1+ (quotient
                    (- date (absolute-from-iso (list 1 1 year)))
                    7)))
         (day (if (= 0 (mod date 7))
               ;; Then
                  7
               ;; Else
                  (mod date 7))))
;;  Return
    (list week day year)))
*/
void
isoFromAbsolute( long date, int *w, int *d, int *y )
{
    int     approx;
    int     day, month, year;

    gregorianFromAbsolute( date - 3, &day, &month, &year );
    approx = year;
    *y = (date >= absoluteFromIso(1,1,approx+1)) ? approx + 1 : approx;
    *w = ( date - absoluteFromIso(1,1,*y) ) / 7 + 1;
    *d = (date % 7 == 0) ? 7 : date % 7;
}
#else
/*
 *    ISO 2051
 *      (1) 週は月曜日から始まる
 *      (2) 1月1日が金,土,日曜であれば、1月1日を含む週を前年の最終週とする
 *      (3) 1月1日が月,火,水,木曜であれば、1月1日を含む週を新年の第1週とする
 */
void
isoFromAbsolute( long date, int *w, int *d, int *y )
{
    int     day, month, year, ww, dd, yy;
    long    j;

    if ( *y <= 0 ) {
        return;
    }

    gregorianFromAbsolute( date, &day, &month, &year );
    j = absoluteFromGregorian( 1, 1, year );
    *y = year;
    *w = (date - (j - (((j % 7) == 0) ? 6 : ((j % 7) - 1)))) / 7 + 1;
    *d = (date % 7 == 0) ? 7 : (date % 7);
    if ( ((j % 7) == 0) || ((j % 7) >= 5) ) {
        if ( --(*w) <= 0 ) {
            yy = year;
            isoFromAbsolute( j - 1, &ww, &dd, &yy );
            *y = yy;
            *w = ww;
        }
    }
    if ( (*w == 53) && (month == 12) ) {
        j = absoluteFromGregorian( 1, 1, year + 1 );
        if ( ((j % 7) >= 1) && ((j % 7) <= 4) ) {
            *w = 1;
            *y = year + 1;
        }
    }
}
#endif

/*
(defun last-day-of-julian-month (month year)
;; Last day in Julian $month$ during $year$.
  (if ;; February in a leap year
      (and (= month 2) (= (mod year 4) 0))
;; Then return
      29
;; Else return
    (nth (1- month) (list 31 28 31 30 31 30 31 31 30 31 30 31))))
*/
int
lastDayOfJulianMonth( int month, int year )
{
    int     ret;

    if ( ( month == FEBRUARY ) && ( year % 4 == 0 ) )
        ret = 29;
    else {
        static int  m[] = { 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31 };
        ret = m[month-1];
    }
    return ( ret );
}

/*
(defun absolute-from-julian (date)
;; Absolute date equivalent to Julian $date$.
  (let* ((month (extract-month date))
         (year (extract-year date)))
;;  Return
    (+ (extract-day date)    ;; Days so far this month.
       (sum                  ;; Days in prior months this year.
        (last-day-of-julian-month m year) m 1 (< m month))
       (* 365 (1- year))     ;; Days in prior years.
       (quotient (1- year) 4);; Leap days in prior years.
       -2)))                 ;; Days elapsed before absolute date 1.
*/
long
absoluteFromJulian( int day, int month, int year )
{
    long    d = day, y = year - 1;
    int     m = 1;

    sum( lastDayOfJulianMonth(m,year), m, 1, m<month, d );
         d += 365 * y + y / 4 - 2;
    return ( d );
}

/*
(defun julian-from-absolute (date)
;; Julian (month day year) corresponding to absolute $date$.
  (let*
      ((approx      ;; Approximation from below.
        (quotient (+ date 2) 366))
       (year        ;; Search forward from the approximation.
        (+ approx
           (sum 1 y approx
                (>= date
                    (absolute-from-julian (list 1 1 (1+ y)))))))
       (month       ;; Search forward from January.
        (1+ (sum 1 m 1
                 (> date
                    (absolute-from-julian
                     (list m
                           (last-day-of-julian-month m year)
                           year))))))
       (day         ;; Calculate the day by subtraction.
        (- date (1- (absolute-from-julian (list month 1 year))))))
;;  Return
    (list month day year)))
*/
void
julianFromAbsolute( long date, int *d, int *m, int *y )
{
    long    approx = ( date + 2 ) / 366;
    int     month = 1, year = approx;
    int     mm, yy;

    sum( 1, yy, approx, date>=absoluteFromJulian(1,1,yy+1), year );
    *y = yy = year;
    sum( 1, mm, 1,
         date>absoluteFromJulian(lastDayOfJulianMonth(mm,yy),mm,yy),
         month );
    *m = month;
    *d = date - absoluteFromJulian(1,month,year) + 1;
}

/*
(defun islamic-leap-year (year)
;; True if $year$ is an Islamic leap year.
  (< (mod (+ 14 (* 11 year)) 30) 11))
*/
BOOL
islamicLeapYear( int year )
{
    long    y = year;

    return ( ( ( 11L * y + 14L ) % 30L < 11L ) ? TRUE : FALSE );
}

/*
(defun last-day-of-islamic-month (month year)
;; Last day in $month$ during $year$ on the Islamic calendar.
  (if (or (oddp month)
          (and (= month 12) (islamic-leap-year year)))
;; Then return
      30
;; Else return
    29))
*/
int
lastDayOfIslamicMonth( int month, int year )
{
    return ((month%2==1)||((month==12)&&islamicLeapYear(year)) ? 30 : 29);
}

/*
(defun absolute-from-islamic (date)
;; Absolute date equivalent to Islamic $date$.
  (let* ((month (extract-month date))
         (year (extract-year date)))
    (+ (extract-day date)     ;; Days so far this month.
       (* 29 (1- month))      ;; Days so far...
       (quotient month 2)     ;;            ...this year.
       (* (1- year) 354)      ;; Non-leap days in prior years.
       (quotient              ;; Leap days in prior years.
        (+ 3 (* 11 year)) 30)
       227014)))              ;; Days before start of calendar.
*/
long
absoluteFromIslamic( int day, int month, int year )
{
    long    d = day, m = month, y = year;
    
    return ( d + ( m - 1 ) * 29 + m / 2 + ( y - 1 ) * 354 +
             ( ( y * 11 ) + 3 ) / 30 + 227014L );
}

/*
(defun islamic-from-absolute (date)
;; Islamic date (month day year) corresponding to absolute $date$.
  (if ;; Pre-Islamic date.
      (<= date 227014)
;; Then return 
      (list 0 0 0)
;; Else
    (let* ((approx         ;; Approximation from below.
            (quotient (- date 227014) 355))
           (year           ;; Search forward from the approximation.
            (+ approx
               (sum 1 y approx
                    (>= date
                        (absolute-from-islamic
                         (list 1 1 (1+ y)))))))
           (month          ;; Search forward from Muharram.
            (1+ (sum 1 m 1
                     (> date
                        (absolute-from-islamic
                         (list m
                               (last-day-of-islamic-month m year)
                               year))))))
           (day            ;; Calculate the day by subtraction.
            (- date (1- (absolute-from-islamic
                         (list month 1 year))))))
      ;; Return
        (list month day year))))
*/
void
islamicFromAbsolute( long date, int *d, int *m, int *y )
{
    long    approx = ( date - 227014L ) / 355;
    int     month = 1, year = approx;
    int     mm, yy;

    if ( date <= 227014L ) {
        *d = *m = *y = 0;
        return;
    }

    sum( 1, yy, approx, date>=absoluteFromIslamic( 1, 1, yy + 1 ), year );
    *y = yy = year;
    sum( 1, mm, 1,
         (date>absoluteFromIslamic(lastDayOfIslamicMonth(mm,yy),mm,yy)),
         month );
    *m = month;
    *d = date - absoluteFromIslamic( 1, month, year ) + 1;
}

/*
(defun hebrew-leap-year (year)
;; True if $year$ is a leap year.
  (< (mod (1+ (* 7 year)) 19) 7))
*/
#if     0
BOOL
hebrewLeapYear( int year )
{
    long    y = year;

    return ( ( ( ( y * 7 ) + 1 ) % 19 ) < 7 ? TRUE : FALSE );
}
#else
#define hebrewLeapYear( year )  (((((long)(year)*7L)+1L)%19L)<7L?TRUE:FALSE)
#endif

/*
(defun last-month-of-hebrew-year (year)
;; Last month of Hebrew $year$.
  (if (hebrew-leap-year year)
;; Then return
      13
;; Else return
    12))
*/
#if     0
int
lastMonthOfHebrewYear( int year )
{
    return ( hebrewLeapYear( year ) ? 13 : 12 );
}
#else
#define lastMonthOfHebrewYear( year )   ( hebrewLeapYear(year) ? 13 : 12 )
#endif

/*
(defun last-day-of-hebrew-month (month year)
;; Last day of $month$ in Hebrew $year$.
  (if (or (member month (list 2 4 6 10 13))
          (and (= month 12) (not (hebrew-leap-year year)))
          (and (= month 8) (not (long-heshvan year)))
          (and (= month 9) (short-kislev year)))
;; Then return
      29
;; Else return
    30))
*/
int
lastDayOfHebrewMonth( int month, int year )
{
    int     ret;

    if ( ( month == 2 ) || ( month == 4 ) || ( month == 6 ) ||
         ( month == 10 ) || ( month == 13 ) ||
         ( ( month == 12 ) && !hebrewLeapYear( year ) ) ||
         ( ( month == 8 ) && !longHeshvan( year ) ) ||
         ( ( month == 9 ) && shortKislev( year ) ) )
        ret = 29;
    else
        ret = 30;
    
    return ( ret );
}

/*
(defun hebrew-calendar-elapsed-days (year)
;; Number of days elapsed from the Sunday prior to the start of the
;; Hebrew calendar to the mean conjunction of Tishri of Hebrew $year$.
  (let*
      ((months-elapsed
        (+
         (* 235            ;; Months in complete cycles so far.
            (quotient (1- year) 19))
         (* 12             ;; Regular months in this cycle.
            (mod (1- year) 19))
         (quotient         ;; Leap months this cycle
          (1+ (* 7 (mod (1- year) 19)))
          19)))
;;     (parts-elapsed (+ 5604 (* 13753 months-elapsed)))
;;     (day                                    ;; Conjunction day
;;      (+ 1 (* 29 months-elapsed) (quotient parts-elapsed 25920)))
;;     (parts (mod parts-elapsed 25920))       ;; Conjunction parts
;;
;;  The above lines of code are correct, but can have intermediate
;;  values that are too large for a 32-bit machine.  The following
;;  lines of code that replace them are equivalent, but avoid the
;;  problem.
;;
       (parts-elapsed
        (+ 204
           (* 793 (mod months-elapsed 1080))))
       (hours-elapsed
        (+ 5
           (* 12 months-elapsed)
           (* 793 (quotient months-elapsed 1080))
           (quotient parts-elapsed 1080)))
       (day                                    ;; Conjunction day
        (+ 1
           (* 29 months-elapsed)
           (quotient hours-elapsed 24)))
       (parts                                  ;; Conjunction parts
        (+ (* 1080 (mod hours-elapsed 24))
           (mod parts-elapsed 1080)))
       (alternative-day
        (if (or
             (>= parts 19440)  ;; If new moon is at or after midday,
             (and
               (= (mod day 7) 2);; ...or is on a Tuesday...
               (>= parts 9924)  ;; at 9 hours, 204 parts or later...
               (not (hebrew-leap-year year)));; of a common year,
             (and
               (= (mod day 7) 1);; ...or is on a Monday at...
               (>= parts 16789) ;; 15 hours, 589 parts or later...
               (hebrew-leap-year;; at the end of a leap year
                (1- year))))
          ;; Then postpone Rosh HaShanah one day
            (1+ day)
          ;; Else
            day)))
    (if ;; If Rosh HaShanah would occur on Sunday, Wednesday,
        ;; or Friday
        (member (mod alternative-day 7) (list 0 3 5))
  ;; Then postpone it one (more) day and return        
        (1+ alternative-day)
  ;; Else return        
      alternative-day)))
*/
long
hebrewCalendarElapsedDays( int year )
{
    long    monthsElapsed, partsElapsed, hoursElapsed, day, parts,
            alternativeDay, mod, y = year - 1;

    monthsElapsed  = 235*(y/19) + 12*(y%19) + (7*(y%19)+1)/19;
    partsElapsed   = 204 + 793 * ( monthsElapsed % 1080 );
    hoursElapsed   = 5 + 12*monthsElapsed + 793*(monthsElapsed/1080) +
                     partsElapsed/1080;
    day            = 1 + 29 * monthsElapsed + hoursElapsed / 24;
    parts          = 1080 * ( hoursElapsed % 24 ) + partsElapsed % 1080;
    alternativeDay =
            ( (parts>=19440)                                        ||
              ((day%7==2)&&(parts>=9924)&&(!hebrewLeapYear(year)))  ||
              ((day%7==1)&&(parts>=16789)&&(hebrewLeapYear(year-1)))   )
                    ? day + 1
                    : day;
    mod = alternativeDay % 7;

    return ( (mod==0)||(mod==3)||(mod==5) ? alternativeDay + 1
                                          : alternativeDay     );
}

/*
(defun days-in-hebrew-year (year)
;; Number of days in Hebrew $year$.
  (- (hebrew-calendar-elapsed-days (1+ year))
     (hebrew-calendar-elapsed-days year)))
*/
long
daysInHebrewYear( int year )
{
    return ( hebrewCalendarElapsedDays( year + 1 ) -
             hebrewCalendarElapsedDays( year )       );
}

/*
(defun long-heshvan (year)
;; True if Heshvan is long in Hebrew $year$.
  (= (mod (days-in-hebrew-year year) 10) 5))
*/
BOOL
longHeshvan( int year )
{
    return ( ( daysInHebrewYear( year ) % 10 ) == 5 ? TRUE : FALSE );
}

/*
(defun short-kislev (year)
;; True if Kislev is short in Hebrew $year$.
  (= (mod (days-in-hebrew-year year) 10) 3))
*/
BOOL
shortKislev( int year )
{
    return ( ( daysInHebrewYear( year ) % 10 ) == 3 ? TRUE : FALSE );
}

/*
(defun absolute-from-hebrew (date)
;; Absolute date of Hebrew $date$.
  (let* ((month (extract-month date))
         (day (extract-day date))
         (year (extract-year date)))
;; Return
    (+ day                            ;; Days so far this month.
       (if ;; before Tishri
           (< month 7)
     ;; Then add days in prior months this year before and
     ;; after Nisan.
           (+ (sum (last-day-of-hebrew-month m year)
                   m 7 (<= m (last-month-of-hebrew-year year)))
              (sum (last-day-of-hebrew-month m year)
                   m 1 (< m month)))
     ;; Else add days in prior months this year
         (sum (last-day-of-hebrew-month m year) m 7 (< m month)))
    (hebrew-calendar-elapsed-days year);; Days in prior years.
    -1373429)))              ;; Days elapsed before absolute date 1.
*/
long
absoluteFromHebrew( int day, int month, int year )
{
    long    date = day;
    int     mm;

    if ( month < 7 ) {
        sum( lastDayOfHebrewMonth(mm,year), mm, 7,
             mm<=lastMonthOfHebrewYear(year), date );
        sum( lastDayOfHebrewMonth(mm,year), mm, 1, mm<month, date );
    }
    else {
        sum( lastDayOfHebrewMonth(mm,year), mm, 7, mm<month, date );
    }

    date += hebrewCalendarElapsedDays( year ) - 1373429L;

    return ( date );
}

/*
(defun hebrew-from-absolute (date)
;; Hebrew (month day year) corresponding to absolute $date$.
  (let* ((approx    ;; Approximation from below.
          (quotient (+ date 1373429) 366))
         (year      ;; Search forward from the approximation.
          (+ approx (sum 1 y approx
                         (>= date
                             (absolute-from-hebrew
                              (list 7 1 (1+ y)))))))
         (start      ;; Starting month for search for month.
          (if (< date (absolute-from-hebrew (list 1 1 year)))
              ;; Then start at Tishri
                    7
              ;; Else start at Nisan
                  1))
         (month      ;; Search forward from either Tishri or Nisan.
          (+ start
             (sum 1 m start
                  (> date
                     (absolute-from-hebrew
                      (list m
                            (last-day-of-hebrew-month m year)
                            year))))))
         (day        ;; Calculate the day by subtraction.
          (- date (1- (absolute-from-hebrew (list month 1 year))))))
;; Return
    (list month day year)))
*/
void
hebrewFromAbsolute( long date, int *d, int *m, int *y )
{
    long    approx = ( date + 1373429L ) / 366L;
    int     month, year = approx, start;
    int     mm, yy;

    sum( 1, yy, approx, (date>=absoluteFromHebrew(1,7,yy+1)), year );
    *y = yy = year;
    month = start = ( date < absoluteFromHebrew( 1, 1, year ) ? 7 : 1 );
    sum( 1, mm, start,
         (date>absoluteFromHebrew(lastDayOfHebrewMonth(mm,yy),mm,yy)),
         month );
    *m = month;
    *d = date - absoluteFromHebrew( 1, month, year ) + 1L;
}

/*
(defun independence-day (year)
;; Absolute date of American Independence Day in Gregorian $year$.
  (absolute-from-gregorian (list 7 4 year)))
*/
#if     0
long
independenceDay( int year )
{
    return ( absoluteFromGregorian( 4, 7, year ) );
}
#endif

/*
(defun Nth-Kday (n k month year)
;; Absolute date of the $n$th $k$day in Gregorian $month$, $year$.
;; If $n$<0, the $n$th $k$day from the end of month is returned
;; (that is, -1 is the last $k$day, -2 is the penultimate $k$day,
;; and so on).  $k=0$ means Sunday, $k=1$ means Monday, and so on.
  (if (> n 0)
;; Then return
      (+ (Kday-on-or-before             ;; First $k$day in month.
          (absolute-from-gregorian
           (list month 7 year)) k)
         (* 7 (1- n)))                  ;; Advance $n-1$ $k$days.
;; Else return
      (+ (Kday-on-or-before             ;; Last $k$day in month.
          (absolute-from-gregorian
           (list month
                 (last-day-of-gregorian-month month year)
                 year))
          k)
         (* 7 (1+ n)))))                ;; Go back $-n-1$ $k$days.
*/
long
NthKday( int n, int k, int month, int year )
{
    long    ret, m = n;

    if ( n > 0 ) {
        ret = KdayOnOrBefore(absoluteFromGregorian(7,month,year),k) +
              7 * ( m - 1 );
    }
    else {
        ret = KdayOnOrBefore(
                absoluteFromGregorian(
                        lastDayOfGregorianMonth(month,year),
                        month,year),
                k) +
              7 * ( m + 1 );
    }

    return ( ret );
}

/*
(defun labor-day (year)
;; Absolute date of American Labor Day in Gregorian $year$.
  (Nth-Kday 1 1 9 year));; First Monday in September.
*/
long
laborDay( int year )
{
    return ( NthKday( FIRST, MONDAY, SEPTEMBER, year ) );
}

/*
 * Columbus Day           コロンブス記念日 10月の第2月曜日
 */

long
columbusDay( int year )
{
    return ( NthKday( SECOND, MONDAY, OCTOBER, year ) );
}

/*
 * Load Mayor's Day London市長就任式日 11月第2土曜日 (London市長は任期1年)
 */

long
loadMayorDay( int year )
{
    return ( NthKday( SECOND, SATURDAY, NOVEMBER, year ) );
}

/*
(defun memorial-day (year)
;; Absolute date of American Memorial Day in Gregorian $year$.
  (Nth-Kday -1 1 5 year));; Last Monday in May.
*/
long
memorialDay( int year )
{
    return ( NthKday( LAST, MONDAY, MAY, year ) );
}

/*
(defun daylight-savings-start (year)
;; Absolute date of the start of American daylight savings time
;; in Gregorian $year$.
  (Nth-Kday 1 0 4 year));; First Sunday in April.
*/
long
daylightSavingsStart( int year )
{
    if ( year == 1916 )                                     /* {@@} */
        return ( absoluteFromGregorian( 30, 4, year ) );    /* {@@} */
    else if ( (year >= 1940) && (year < 1987) )             /* {@@} */
        return ( NthKday( LAST, SUNDAY, APRIL, year ) );    /* {@@} */
    else if ( year < 2007 )                                 /* {@@} */
        return ( NthKday( FIRST, SUNDAY, APRIL, year ) );
    else if ( year >= 2007 )                                /* {@@} */
        return ( NthKday( SECOND, SUNDAY, MARCH, year ) );  /* {@@} */
    else                                                    /* {@@} */
        return ( -1 );                                      /* {@@} */
}

long
daylightSavingsStartInEurope( int year )
{
    return ( NthKday( LAST, SUNDAY, MARCH, year ) );
}

long
daylightSavingsStartInAustralia( int year )
{
    return ( NthKday( LAST, SUNDAY, OCTOBER, year ) );
}

long
daylightSavingsStartInNewZealand( int year )
{
    return ( NthKday( FIRST, SUNDAY, OCTOBER, year ) );
}

long
daylightSavingsStartInBrazil( int year )
{
    return ( NthKday( THIRD, SUNDAY, OCTOBER, year ) );
}

/*
(defun daylight-savings-end (year)
;; Absolute date of the end of American daylight savings time
;; in Gregorian $year$.
  (Nth-Kday -1 0 10 year));; Last Sunday in October.
*/
long
daylightSavingsEnd( int year )
{
    return ( (year == 1916)
                ? absoluteFromGregorian( 1, 10, year ) :
             (year >= 1940) && (year < 2007)
                ? NthKday( LAST, SUNDAY, OCTOBER, year ) :
             (year >= 2007)
                ? NthKday( FIRST, SUNDAY, NOVEMBER, year ) :
                  -1                                         );
}

long
daylightSavingsEndInEurope( int year )
{
    return ( NthKday( LAST, SUNDAY, OCTOBER, year ) );
}

long
daylightSavingsEndInAustralia( int year )
{
    return ( NthKday( LAST, SUNDAY, MARCH, year ) );
}

long
daylightSavingsEndInNewZealand( int year )
{
    return ( NthKday( THIRD, SUNDAY, MARCH, year ) );
}

long
daylightSavingsEndInBrazil( int year )
{
    return ( NthKday( THIRD, SUNDAY, FEBRUARY, year ) );
}

/*
(defun christmas (year)
;; Absolute date of Christmas in Gregorian $year$.
  (absolute-from-gregorian (list 12 25 year)))
*/
#if     0
long
christmas( int year )
{
    return ( absoluteFromGregorian( 25, 12, year ) );
}
#endif

/*
(defun advent (year)
;; Absolute date of Advent in Gregorian $year$.
  (Kday-on-or-before (absolute-from-gregorian (list 12 3 year)) 0))
*/
long
advent( int year )
{
    return ( KdayOnOrBefore( absoluteFromGregorian( 3, 12, year ), 0 ) );
}

/*
(defun epiphany (year)
;; Absolute date of Epiphany in Gregorian $year$.
  (+ 12 (christmas year)))
*/
#if     0
long
epiphany( int year )
{
    return ( christmas( year ) + 12 );
}
#endif

/*
(defun eastern-orthodox-christmas (year)
;; List of zero or one absolute dates of Eastern Orthodox
;; Christmas in Gregorian $year$.
  (let* ((jan1 (absolute-from-gregorian (list 1 1 year)))
         (dec31 (absolute-from-gregorian (list 12 31 year)))
         (y (extract-year (julian-from-absolute jan1)))
         (c1 (absolute-from-julian (list 12 25 y)))
         (c2 (absolute-from-julian (list 12 25 (1+ y)))))
   (append
    (if ;; c1 occurs in current year
        (<= jan1 c1 dec31)
;;   Then that date; otherwise, none
        (list c1) nil)
    (if ;; c2 occurs in current year
        (<= jan1 c2 dec31)
;;   Then that date; otherwise, none
        (list c2) nil))))
*/
#if     0
dateList        *
easternOrthodoxChristmas( int year )
{
    long            jan1, dec31, c1, c2;
    static dateList dates;
    long            *p = dates;
    int             d, m, y, i;

    for ( i = 0; i < MAXLIST; i++ )
        dates[ i ] = 0;

    jan1  = absoluteFromGregorian(  1,  1, year );
    dec31 = absoluteFromGregorian( 31, 12, year );
    julianFromAbsolute( jan1, &d, &m, &y );
    c1 = absoluteFromJulian( 25, 12, y );
    c2 = absoluteFromJulian( 25, 12, y + 1 );

    i = 0;
    if ( ( jan1 <= c1 ) && ( c1 <= dec31 ) )
        dates[ i++ ] = c1;
    if ( ( jan1 <= c2 ) && ( c2 <= dec31 ) )
        dates[ i ] = c2;

    return ( ( dateList *)p );
}
#endif

/*
(defun nicaean-rule-easter (year)
;; Absolute date of Easter in Julian $year$, according to the rule
;; of the Council of Nicaea.
  (let* ((shifted-epact ;; Age of moon for April 5.
          (mod (+ 14
                  (* 11 (mod year 19)))
               30))
         (paschal-moon  ;; Day after full moon on or after March 21.
          (- (absolute-from-julian (list 4 19 year))
             shifted-epact)))
;; Return the Sunday following the Paschal moon
    (Kday-on-or-before (+ paschal-moon 7) 0)))
*/
long
nicaeanRuleEaster( int year )
{
    long    shiftedEpact, paschalMoon, y = year;

    shiftedEpact = ( 14 + ( 11 * ( y % 19 ) ) ) % 30;
    paschalMoon  = absoluteFromJulian( 19, 4, year ) - shiftedEpact;

    return ( KdayOnOrBefore( paschalMoon + 7, 0 ) );
}

/*
(defun easter (year)
;; Absolute date of Easter in Gregorian $year$.
  (let* ((century (1+ (quotient year 100)))
         (shifted-epact        ;; Age of moon for April 5...
          (mod
           (+ 14 (* 11 (mod year 19));;     ...by Nicaean rule
              (-      ;; ...corrected for the Gregorian century rule
               (quotient (* 3 century) 4))
              (quotient;; ...corrected for Metonic cycle inaccuracy.
               (+ 5 (* 8 century)) 25)
              (* 30 century));;              Keeps value positive.
           30))
         (adjusted-epact       ;;  Adjust for 29.5 day month.
          (if (or (= shifted-epact 0)
                  (and (= shifted-epact 1) (< 10 (mod year 19))))
        ;; Then
              (1+ shifted-epact)
        ;; Else
            shifted-epact))
         (paschal-moon;; Day after full moon on or after March 21.
          (- (absolute-from-gregorian (list 4 19 year))
             adjusted-epact)))
;; Return the Sunday following the Paschal moon.
    (Kday-on-or-before (+ paschal-moon 7) 0)))
*/
/*
 *      イースターの日付を求める
 *              イースター（復活祭）の日は春分（西洋では3月21日に固定）の
 *              あとの最初の満月のあとの日曜日である
 */
#if     0
long
easter( int year )
{
    long    century, shiftedEpact, adjustedEpact, paschalMoon, y = year;

    century       = y / 100 + 1;
    shiftedEpact  = ( 14 + 11 * ( y % 19 ) + century * 3 / 4 -
                      ( 5 + century * 8 ) / 25 + century * 30 ) % 30;
    adjustedEpact = ( shiftedEpact == 0 ) ||
                      ( ( shiftedEpact == 1 ) && ( year % 19 < 10 ) )
                            ? shiftedEpact + 1
                            : shiftedEpact;
    paschalMoon   = absoluteFromGregorian( 19, 4, year ) - adjustedEpact;

    return ( KdayOnOrBefore( paschalMoon + 7, 0 ) );
}
#else
long
easter( int year )
{
    long    j;
    int     age;

    /* 3月21日のユリウス日を算出する */
    j = absoluteFromGregorian( 21, 3, year ) + 1721425L - 2400000L;
                                                    /* 修正ユリウス日 */
    /* 最初の満月の日を求める */
    do {
        age = geturei( ++j );
        if ( age <= 14 ) {
            j += 15L - (long)age;
            age = 15;
        }
        if ( age >= 16 )
            j += 14L;
    } while ( age != 15 );
    j -= 1721425L - 2400000L;       /* ユリウス日 */

    /* 満月の日の直後の日曜を求める */
    if ( j % 7 != 0 )
        j = j + ( 7L - ( j % 7L ) );
    else
        j += 7L;

    return ( j );
}
#endif

/*
(defun pentecost (year)
;; Absolute date of Pentecost in Gregorian $year$.
  (+ 49 (easter year)))
*/
#if     0
long
pentecost( int year )
{
    return ( easter( year ) + 49 );
}
#endif

/*
(defun islamic-date (month day year)
;; List of the absolute dates of Islamic $month$, $day$
;; that occur in Gregorian $year$.
  (let* ((jan1 (absolute-from-gregorian (list 1 1 year)))
         (dec31 (absolute-from-gregorian (list 12 31 year)))
         (y (extract-year (islamic-from-absolute jan1)))
;; The possible occurrences in one year are
         (date1 (absolute-from-islamic (list month day y)))
         (date2 (absolute-from-islamic (list month day (1+ y))))
         (date3 (absolute-from-islamic (list month day (+ 2 y)))))
;; Combine in one list those that occur in current year
    (append
      (if (<= jan1 date1 dec31)
          (list date1) nil)
      (if (<= jan1 date2 dec31)
          (list date2) nil)
      (if (<= jan1 date3 dec31)
          (list date3) nil))))        
*/
dateList        *
islamicDate( int day, int month, int year )
{
    long            jan1, dec31, date1, date2, date3;
    int             i, d, m, y;
    static dateList dates;
    long            *p = dates;

    for ( i = 0; i < MAXLIST; i++ )
        dates[ i ] = 0;
    
    jan1  = absoluteFromGregorian(  1,  1, year );
    dec31 = absoluteFromGregorian( 31, 12, year );
    islamicFromAbsolute( jan1, &d, &m, &y );
    date1 = absoluteFromIslamic( day, month, y );
    date2 = absoluteFromIslamic( day, month, y + 1 );
    date3 = absoluteFromIslamic( day, month, y + 2 );

    if ( ( jan1 <= date1 ) && ( date1 <= dec31 ) )
        dates[ i++ ] = date1;
    if ( ( jan1 <= date2 ) && ( date2 <= dec31 ) )
        dates[ i++ ] = date2;
    if ( ( jan1 <= date3 ) && ( date3 <= dec31 ) )
        dates[ i ] = date3;

    return ( ( dateList *)p );
}

#if     0
/*
(defun mulad-al-nabi (year)
;; List of absolute dates of Mulad-al-Nabi occurring in
;; Gregorian $year$.
  (islamic-date 3 12 year))
*/
dateList        *
muladAlNabi( int year )
{
    return ( islamicDate( 12, 3, year ) );
}
#endif

/*
(defun yom-kippur (year)
;; Absolute date of Yom Kippur occurring in Gregorian $year$.
  (absolute-from-hebrew (list 7 10 (+ year 3761))))
*/
long
yomKippur( int year )
{
    return ( absoluteFromHebrew( 10, 7, year + 3761 ) );
}

/*
(defun passover (year)
;; Absolute date of Passover occurring in Gregorian $year$.
  (absolute-from-hebrew (list 1 15 (+ year 3760))))
*/
long
passover( int year )
{
    return ( absoluteFromHebrew( 15, 1, year + 3760 ) );
}

/*
(defun purim (year)
;; Absolute date of Purim occurring in Gregorian $year$.
  (absolute-from-hebrew
    (list
      (last-month-of-hebrew-year (+ year 3760));; Adar or Adar II
      14
      (+ year 3760))))
*/
long    purim( int year )
{
    year += 3760;

    return ( absoluteFromHebrew( 14, lastMonthOfHebrewYear(year), year ) );
}

long    tuBShvat( int year )
{
    year += 3760;

    return ( absoluteFromHebrew(15, lastMonthOfHebrewYear(year)-1, year) );
}

/*
(defun ta-anit-esther (year)
;; Absolute date of Purim occurring in Gregorian $year$.
  (let* ((purim-date (purim year)))
    (if ;; Purim is on Sunday
        (= (mod purim-date 7) 0)
  ;; Then return prior Thursday
        (- purim-date 3)
  ;; Else return previous day
      (1- purim-date))))
*/
long
taAnitEsther( int year )
{
    long    purimDate = purim( year );

    return ( purimDate % 7 == 0 ? purimDate - 3 : purimDate - 1 );
}

/*
(defun tisha-b-av (year)
;; Absolute date of Tisha B'Av occurring in Gregorian $year$.
  (let* ((ninth-of-av
          (absolute-from-hebrew (list 5 9 (+ year 3760)))))
    (if ;; Ninth of Av is Saturday
        (= (mod ninth-of-av 7) 6)
  ;; Then return the next day
        (1+ ninth-of-av) 
  ;; Else return
      ninth-of-av)))
*/
long
tishaBAv( int year )
{
    long    ninthOfAv = absoluteFromHebrew( 9, 5, year + 3760 );

    return ( ninthOfAv % 7 == 6 ? ninthOfAv + 1 : ninthOfAv );
}

/*
(defun hebrew-birthday (birthdate year)
;; Absolute date of the anniversary of Hebrew $birthdate$
;; occurring in Hebrew $year$.
  (let* ((birth-day (extract-day birthdate))
         (birth-month (extract-month birthdate))
         (birth-year (extract-year birthdate)))
    (if ;; It's Adar in a normal year or Adar II in a leap year,
        (= birth-month (last-month-of-hebrew-year birth-year))
  ;; Then use the same day in last month of $year$.
        (absolute-from-hebrew
         (list (last-month-of-hebrew-year year) birth-day year))
  ;; Else use the normal anniversary of the birth date,
  ;; or the corresponding day in years without that date
      (absolute-from-hebrew (list birth-month birth-day year)))))
*/
long
hebrewBirthday( int bday, int bmonth, int byear, int year )
{
    return ( bmonth == lastMonthOfHebrewYear( byear )
                ? absoluteFromHebrew(bday,lastMonthOfHebrewYear(year),year)
                : absoluteFromHebrew(bday,bmonth,year) );
}

/*
(defun yahrzeit (death-date year)
;; Absolute date of the anniversary of Hebrew $death$-$date$
;; occurring in Hebrew $year$.
  (let* ((death-day (extract-day death-date))
         (death-month (extract-month death-date))
         (death-year (extract-year death-date)))
    (cond
     ;; If it's Heshvan 30 it depends on the first anniversary; if
     ;; that was not Heshvan 30, use the day before Kislev 1.
     ((and (= death-month 8)
           (= death-day 30)
           (not (long-heshvan (1+ death-year))))
      (1- (absolute-from-hebrew (list 9 1 year))))
     ;; If it's Kislev 30 it depends on the first anniversary; if
     ;; that was not Kislev 30, use the day before Teveth 1.
     ((and (= death-month 9)
           (= death-day 30)
           (short-kislev (1+ death-year)))
      (1- (absolute-from-hebrew (list 10 1 year))))
     ;; If it's Adar II, use the same day in last month of
     ;; year (Adar or Adar II).
     ((= death-month 13)
      (absolute-from-hebrew
       (list (last-month-of-hebrew-year year) death-day year)))
     ;; If it's the 30th in Adar I and $year$ is not a leap year
     ;; (so Adar has only 29 days), use the last day in Shevat.
     ((and (= death-day 30)
           (= death-month 12)
           (not (hebrew-leap-year death-year)))
      (absolute-from-hebrew (list 11 30 year)))
     ;; In all other cases, use the normal anniversary of the
     ;; date of death.
     (t (absolute-from-hebrew
         (list death-month death-day year))))))
*/
long
yahrzeit( int dday, int dmonth, int dyear, int year )
{
    long    ret;

    if ( ( dmonth == 8 ) && ( dday == 30 ) && !longHeshvan( dyear + 1 ) )
        ret = absoluteFromHebrew( 1, 9, year ) - 1;
    else if ( ( dmonth == 9 ) && ( dday == 30 ) && shortKislev( dyear + 1 ) )
        ret = absoluteFromHebrew( 1, 10, year ) - 1;
    else if ( dmonth == 13 )
        ret = absoluteFromHebrew(dday,lastMonthOfHebrewYear(year),year);
    else if ( ( dmonth == 12 ) && ( dday == 30 ) && !hebrewLeapYear( dyear ) )
        ret = absoluteFromHebrew( 30, 11, year );
    else
        ret = absoluteFromHebrew( dday, dmonth, year );

    return ( ret );
}

/*
 *      追加
 */
long
rememberanceDay( int year )
{
#if     0
    long    g, g1, g2;

    g  = absoluteFromGregorian( 11, 11, year );   /* veterans day */
    g1 = NthKday(SECOND, SUNDAY, NOVEMBER, year); /* 2nd Sunday in November */
    if ( g1 > g ) {
        g2 = g1;
        g1 = NthKday( FIRST, SUNDAY, NOVEMBER, year );
    }
    else
        g2 = NthKday( THIRD, SUNDAY, NOVEMBER, year );
    return ( g2 - g < g - g1 ? g2 : g1 );
#else
    return ( NthKday( SECOND, SUNDAY, NOVEMBER, year ) );
#endif
}

long
thanksGivingDay( int year )
{
    return ( NthKday( FOURTH, THURSDAY, NOVEMBER, year ) );
}

long
secretarysDay( int year )
{
    return ( NthKday( LAST, SATURDAY, APRIL, year ) - 3L );
}


long
harvestMoon( int year )
{
    long    j;
    int     age;

    /* 9月1日のユリウス日を算出する */
    j = absoluteFromGregorian( 1, 9, year ) + 1721425L - 2400000L;
                                                    /* 修正ユリウス日 */
    /* 最初の満月の日を求める */
    do {
        age = geturei( ++j );
        if ( age <= 14 ) {
            j += 15L - (long)age;
            age = 15;
        }
        if ( age >= 16 )
            j += 14L;
    } while ( age != 15 );
    j -= 1721425L - 2400000L;       /* ユリウス日 */

    return ( j );
}


long
huntersMoon( int year )
{
    long    j = harvestMoon( year ) + 1L + 1721425L - 2400000L;
    int     age;

    /* 仲秋の満月の次の満月の日を求める */
    do {
        age = geturei( ++j );
        if ( age <= 14 ) {
            j += 15L - (long)age;
            age = 15;
        }
        if ( age >= 16 )
            j += 14L;
    } while ( age != 15 );
    j -= 1721425L - 2400000L;       /* ユリウス日 */

    return ( j );
}

char    *
hebrewMonthName( int mm, int yy )
{
    static char *monthName[] = {
                        /* ユダヤ暦の1年は7月に始まり、6月で終わる */
                        /*  ┌koyomi.exe で表示する月              */
                        /*  ↓    ↓年初を1月とした場合の月        */
        "Tishrey",      /*    7月(   1月)       */
        "Heshvan",      /*    8月(   2月)       */
        "Kislev",       /*    9月(   3月)       */
        "Tevet",        /*   10月(   4月)       */
        "Shvat",        /*   11月(   5月)       */
        "Adar",         /*   12月(   6月[平年]) */
        "Nisan",        /*    1月(   7月)       */
        "Iyar",         /*    2月(   8月)       */
        "Sivan",        /*    3月(   9月)       */
        "Tamuz",        /*    4月(  10月)       */
        "Av",           /*    5月(  11月)       */
        "Elul",         /*    6月(  12月)       */
        "Adar I",       /*   12月(   6月[閏年]) */
        "Adar II"       /*   13月(閏 6月[閏年]) */
    };
    char    *p = NULL;

    if ( hebrewLeapYear( yy ) ) {
        switch ( mm ) {
        case 12:
            p = monthName[12];
            break;
        case 13:
            p = monthName[13];
            break;
        }
    }

    if ( !p ) {
        p = monthName[(mm + 5) % 12];
    }

    return ( p );
}

char    *
englishMonthName( int mm )
{
    static char *monthName[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return ( monthName[(mm + 11) % 12] );
}

char    *
latinMonthName( int mm )
{
    static char *monthName[] = {
        "Januarius", "Februarius", "Martius", "Aprilis", "Maius", "Junius",
        "Julius", "Augustus", "September", "October", "November", "December"
    };

    return ( monthName[(mm + 11) % 12] );
}

char    *
islamicMonthName( int mm )
{
    static char *monthName[] = {
        "Muharram", "Safar", "Rabi I", "Rabi II", "Jumada I", "Jumada II",
        "Rajab", "Shaban", "Ramadan", "Shawwal", "Dhu al-Qada", "Dhu al-Hijja"
    };

    return ( monthName[(mm + 11) % 12] );
}

