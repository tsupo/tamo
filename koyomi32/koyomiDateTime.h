
#include <math.h>

// 日時情報を扱うためのクラス。
// MFC標準の COleDateTime は 
//西暦100年以降しか扱えない(西暦9998年以降も
// 扱えない)ので、西暦 1 ～ 
//99年、9998年～9999年も扱えるように拡張したクラスを用
// 意する

//##ModelId=3ED5BCC401B9
class CKoyomiDateTime : public COleDateTime
{
#define	sum(expression,index,initial,condition,result) \
	for ( (index) = (initial); (condition); (index) += 1 ) \
		(result) += (expression);
#define leapyear( year )    ( ((year)%4==0) && \
                              (((year)%100!=0) || ((year)%400==0)) )
private:
	//##ModelId=3ED5BCC401C5
    int m_year;     // 年
	//##ModelId=3ED5BCC401D4
    int m_month;    // 月
	//##ModelId=3ED5BCC401E4
    int m_day;      // 日
	//##ModelId=3ED5BCC401F4
    int m_hour;     // 時
	//##ModelId=3ED5BCC40203
    int m_min;      // 分
	//##ModelId=3ED5BCC40204
    int m_sec;      // 秒

public:
	//##ModelId=3ED5BCC40213
    CKoyomiDateTime(): COleDateTime()
    {
        GetDateTime();
    }

	//##ModelId=3ED5BCC40214
    CKoyomiDateTime( const COleDateTime& dateSrc ): COleDateTime( dateSrc )
    {
        GetDateTime();
    }

	//##ModelId=3ED5BCC40222
    CKoyomiDateTime( const CKoyomiDateTime& dateSrc ):
        COleDateTime( dateSrc.m_year, dateSrc.m_month, dateSrc.m_day,
                      dateSrc.m_hour, dateSrc.m_min,   dateSrc.m_sec )
    {
        GetDateTime();
        if ( (COleDateTime::GetStatus() == COleDateTime::invalid)  ||
             (COleDateTime::GetYear()   == AFX_OLE_DATETIME_ERROR)    ) {
            m_year  = dateSrc.m_year;
            m_month = dateSrc.m_month;
            m_day   = dateSrc.m_day;
            m_hour  = dateSrc.m_hour;
            m_min   = dateSrc.m_min;
            m_sec   = dateSrc.m_sec;
        }
    }

	//##ModelId=3ED5BCC40224
    CKoyomiDateTime( const VARIANT& varSrc ): COleDateTime( varSrc )
    {
        GetDateTime();
    }

	//##ModelId=3ED5BCC40232
    CKoyomiDateTime( DATE dtSrc ): COleDateTime( dtSrc )
    {
        // DATE 型は 8 バイトの浮動小数点数値で、実数部が日付、小数部が時刻を示す。
        // 日付は 1899 年 12 月 30 日の午前零時がゼロで、1 日ごとに 1 増加する。時刻は 1.0 が 24 時間の小数
        // 1899 年 12 月 30 日より前は、日付は 1 日さかのぼるごとに 1 減少する。時刻は -1.0 を 24 時間とした小数
        GetDateTime();
        if ( (COleDateTime::GetStatus() == COleDateTime::invalid)  ||
             (COleDateTime::GetYear()   == AFX_OLE_DATETIME_ERROR)    ) {
            double  d  = dtSrc - (double)(AbsoluteFromGregorian( 1899, 12, 30 ) * 1.0);
            double  dd = floor( d );
            long    jd = (long)dd;
            double  t  = d - dd;

            t *= 24.0;
            dd     = floor( t );
            m_hour = (long)dd;
            t -= dd;

            t *= 60.0;
            dd     = floor( t );
            m_min  = (long)dd;
            t -= dd;

            t *= 60.0;
            dd     = floor( t );
            m_sec  = (long)dd;

            GregorianFromAbsolute( jd );
            if ( (m_year < 1752)                      ||
                 ((m_year == 1752) && (m_month <= 9))    )
                JulianFromAbsolute( AbsoluteFromJulian() );
        }
    }

	//##ModelId=3ED5BCC40234
    CKoyomiDateTime( time_t timeSrc ): COleDateTime( timeSrc )
    {
        // time_t 型は 1970 年 1 月 1 日の 00:00:00 からの経過時間を秒単位で表した数値
        GetDateTime();
    }

	//##ModelId=3ED5BCC40242
    CKoyomiDateTime( const SYSTEMTIME& systimeSrc ): COleDateTime( systimeSrc )
    {
        GetDateTime();
        if ( (COleDateTime::GetStatus() == COleDateTime::invalid)  ||
             (COleDateTime::GetYear()   == AFX_OLE_DATETIME_ERROR)    ) {
            m_year  = systimeSrc.wYear;
            m_month = systimeSrc.wMonth;
            m_day   = systimeSrc.wDay;
            m_hour  = systimeSrc.wHour;
            m_min   = systimeSrc.wMinute;
            m_sec   = systimeSrc.wSecond;
        }
    }

	//##ModelId=3ED5BCC40244
    CKoyomiDateTime( const FILETIME& filetimeSrc ): COleDateTime( filetimeSrc )
    {
        // FILETIME 構造体は 1601 年 1 月 1 日からの 100 ナノ秒間隔の数を表す 64 ビットの値
        GetDateTime();
    }

	//##ModelId=3ED5BCC40246
    CKoyomiDateTime( int year, int month, int day, int hour, int min, int sec ):
        COleDateTime( year, month, day, hour, min, sec )
    {
        GetDateTime();
        if ( (COleDateTime::GetStatus() == COleDateTime::invalid)  ||
             (COleDateTime::GetYear()   == AFX_OLE_DATETIME_ERROR)    ) {
            m_year  = year;
            m_month = month;
            m_day   = day;
            m_hour  = hour;
            m_min   = min;
            m_sec   = sec;
        }
    }

	//##ModelId=3ED5BCC40261
    CKoyomiDateTime( WORD wDosDate, WORD wDosTime ):
        COleDateTime( wDosDate, wDosTime )
    {
        GetDateTime();
    }

	//##ModelId=3ED5BCC40264
    int     GetYear( void )
    {
        int ret = COleDateTime::GetYear();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_year;

        return ( ret );
    }

	//##ModelId=3ED5BCC40271
    int     GetMonth( void )
    {
        int ret = COleDateTime::GetMonth();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_month;

        return ( ret );
    }

	//##ModelId=3ED5BCC40273
    int     GetDay( void )
    {
        int ret = COleDateTime::GetDay();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_day;

        return ( ret );
    }

	//##ModelId=3ED5BCC40280
    int     GetHour( void )
    {
        int ret = COleDateTime::GetHour();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_hour;

        return ( ret );
    }

	//##ModelId=3ED5BCC40282
    int     GetMinute( void )
    {
        int ret = COleDateTime::GetMinute();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_min;

        return ( ret );
    }

	//##ModelId=3ED5BCC40284
    int     GetSecond( void )
    {
        int ret = COleDateTime::GetSecond();

        if ( ret == AFX_OLE_DATETIME_ERROR )
            ret = m_sec;

        return ( ret );
    }

	//##ModelId=3ED5BCC40291
    int     GetDayOfWeek( void )
    {
        int ret = COleDateTime::GetDayOfWeek();

        if ( ret == AFX_OLE_DATETIME_ERROR ) {
            long    jd = AbsoluteFromJulian();
            while ( jd < 0 )
                jd += 7;
            ret = (jd % 7) + 1;
        }

        return ( ret );
    }

	//##ModelId=3ED5BCC40293
    BOOL    GetAsSystemTime( SYSTEMTIME& sysTime ) 
    {
        BOOL    ret = FALSE;

        if ( (COleDateTime::GetStatus() == COleDateTime::valid) && (m_year >= 100) ) {
            ret = COleDateTime::GetAsSystemTime( sysTime );
            if ( ret == TRUE )
                return ( ret );
        }

        sysTime.wYear      = GetYear();
        sysTime.wMonth     = GetMonth();
        sysTime.wDay       = GetDay();
        sysTime.wHour      = GetHour();
        sysTime.wMinute    = GetMinute();
        sysTime.wSecond    = GetSecond();
        sysTime.wDayOfWeek = GetDayOfWeek() - 1;
        if ( (sysTime.wDayOfWeek >= 0) && (sysTime.wDayOfWeek < 7) )
            ret = TRUE;

        return ( ret );
    }

	//##ModelId=3ED5BCC4029F
    void    GetDateTime( void )
    {
        m_year  = COleDateTime::GetYear();
        m_month = COleDateTime::GetMonth();
        m_day   = COleDateTime::GetDay();
        m_hour  = COleDateTime::GetHour();
        m_min   = COleDateTime::GetMinute();
        m_sec   = COleDateTime::GetSecond();
    }

	//##ModelId=3ED5BCC402A1
    void    GetDateTime( int& year, int& month, int& day, int& hour, int& min, int& sec )
    {
        year  = m_year  = COleDateTime::GetYear();
        month = m_month = COleDateTime::GetMonth();
        day   = m_day   = COleDateTime::GetDay();
        hour  = m_hour  = COleDateTime::GetHour();
        min   = m_min   = COleDateTime::GetMinute();
        sec   = m_sec   = COleDateTime::GetSecond();
    }

	//##ModelId=3ED5BCC402B2
    void    GetDate( int& year, int& month, int& day )
    {
        year  = m_year  = COleDateTime::GetYear();
        month = m_month = COleDateTime::GetMonth();
        day   = m_day   = COleDateTime::GetDay();
    }

	//##ModelId=3ED5BCC402C0
    void    GetTime( int& hour, int& min, int& sec )
    {
        hour  = m_hour  = COleDateTime::GetHour();
        min   = m_min   = COleDateTime::GetMinute();
        sec   = m_sec   = COleDateTime::GetSecond();
    }


	//##ModelId=3ED5BCC402C4
    CKoyomiDateTime operator+(const COleDateTimeSpan& dateSpan) const
    {
        CKoyomiDateTime dt( m_year, m_month, m_day, m_hour, m_min, m_sec );
        long    d  = (long)dateSpan.m_span;
        long    h, m, s;
        long    jd = dt.AbsoluteFromGregorian() + d;
        double  df = dateSpan.m_span - floor( dateSpan.m_span ), dd;
        dt.GregorianFromAbsolute( jd );

        df *= 24.0;
        dd  = floor( df );
        h   = (long)dd;
        df -= dd;

        df *= 60.0;
        dd = floor( df );
        m  = (long)dd;
        df -= dd;

        df *= 60.0;
        dd  = floor( df );
        s   = (long)dd;

        dt.m_hour += h;
        dt.m_min  += m;
        dt.m_sec  += s;
        while ( dt.m_sec >= 60 ) {
            dt.m_sec -= 60;
            (dt.m_min)++;
        }
        while ( dt.m_min >= 60 ) {
            dt.m_min -= 60;
            (dt.m_hour)++;
        }
        while ( dt.m_hour >= 24 ) {
            dt.m_hour -= 24;
            (dt.m_day)++;
            dt.Validize();
        }

        return ( dt );
    }

	//##ModelId=3ED5BCC402D0
    CKoyomiDateTime operator-(const COleDateTimeSpan& dateSpan) const
    {
        CKoyomiDateTime dt( m_year, m_month, m_day, m_hour, m_min, m_sec );
        long    d  = (long)dateSpan.m_span;
        long    h, m, s;
        long    jd = dt.AbsoluteFromGregorian() - d;
        double  df = dateSpan.m_span - floor( dateSpan.m_span ), dd;
        dt.GregorianFromAbsolute( jd );

        df *= 24.0;
        dd  = floor( df );
        h   = (long)dd;
        df -= dd;

        df *= 60.0;
        dd = floor( df );
        m  = (long)dd;
        df -= dd;

        df *= 60.0;
        dd  = floor( df );
        s   = (long)dd;

        dt.m_hour -= h;
        dt.m_min  -= m;
        dt.m_sec  -= s;
        while ( dt.m_sec < 0 ) {
            dt.m_sec += 60;
            (dt.m_min)--;
        }
        while ( dt.m_min < 0 ) {
            dt.m_min += 60;
            (dt.m_hour)--;
        }
        while ( dt.m_hour < 0 ) {
            dt.m_hour += 24;
            jd--;
            dt.GregorianFromAbsolute( jd );
        }

        return ( dt );
    }

	//##ModelId=3ED5BCC402D3
    const CKoyomiDateTime& operator+=( const COleDateTimeSpan dateSpan )
	{
        *this = *this + dateSpan;
        return *this;
    }

	//##ModelId=3ED5BCC402DF
    const CKoyomiDateTime& operator-=( const COleDateTimeSpan dateSpan )
	{
        *this = *this - dateSpan;
        return *this;
    }

	//##ModelId=3ED5BCC402E1
    int
    LastDayOfGregorianMonth( int month, int year = 0 )
    {
        int	ret = 0;

        if ( year == 0 )
            year = m_year;

        if ( ( month == 2 ) && leapyear( year ) )
            ret = 29;
        else {
            static int	m[] = { 31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31 };
            ret = m[month-1];
        }

        return ( ret );
    }

	//##ModelId=3ED5BCC402EE
    long
    AbsoluteFromGregorian( void )
    {
        long    d = m_day, y = m_year - 1;
        int     m;

        sum( LastDayOfGregorianMonth( m ), m, 1, m < m_month, d );
        d += 365 * y + y / 4 - y / 100 + y / 400;
        return ( d );
    }

	//##ModelId=3ED5BCC402F0
    long
    AbsoluteFromGregorian( int day, int month, int year )
    {
        long    d = day, y = year - 1;
        int     m;

        sum( LastDayOfGregorianMonth( m, year ), m, 1, m < month, d );
        d += 365 * y + y / 4 - y / 100 + y / 400;
        return ( d );
    }

	//##ModelId=3ED5BCC402FD
    void
    GregorianFromAbsolute( long date )
    {
        long    approx = date / 366;
        int     month = 1, year = approx;
        int     mm, yy;

        sum( 1, yy, approx, date >= AbsoluteFromGregorian( 1, 1, yy + 1 ), year );
        m_year = yy = year;
        sum( 1, mm, 1,
             date > AbsoluteFromGregorian( LastDayOfGregorianMonth( mm, yy ), mm, yy ),
             month );
        m_month = month;
        m_day   = date - AbsoluteFromGregorian( 1, month, year ) + 1L;

        COleDateTime::SetDateTime( m_year, m_month, m_day, m_hour, m_min, m_sec );
    }


	//##ModelId=3ED5BCC402FF
    int
    LastDayOfJulianMonth( int month, int year = 0 )
    {
        int ret = 0;

        if ( year == 0 )
            year = m_year;

        if ( ( month == 2 ) && ( year % 4 == 0 ) )
            ret = 29;
        else {
            static int	m[] = { 31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31 };
            ret = m[month-1];
        }
        return ( ret );
    }

	//##ModelId=3ED5BCC40302
    long
    AbsoluteFromJulian( void )
    {
        long    d = m_day, y = m_year - 1;
        int     m = 1;

        sum( LastDayOfJulianMonth( m ), m, 1, m < m_month, d );
        d += 365 * y + y / 4 - 2;
        return ( d );
    }

	//##ModelId=3ED5BCC4030E
    long
    AbsoluteFromJulian( int day, int month, int year )
    {
        long    d = day, y = year - 1;
        int     m = 1;

        sum( LastDayOfJulianMonth( m, year ), m, 1, m < month, d );
        d += 365 * y + y / 4 - 2;
        return ( d );
    }

	//##ModelId=3ED5BCC40312
    void
    JulianFromAbsolute( long date )
    {
        long    approx = ( date + 2 ) / 366;
        int     month = 1, year = approx;
        int     mm, yy;

        sum( 1, yy, approx, date >= AbsoluteFromJulian( 1, 1, yy + 1 ), year );
        m_year = yy = year;
        sum( 1, mm, 1,
	         date > AbsoluteFromJulian( LastDayOfJulianMonth( mm, yy ), mm, yy ),
	         month );
        m_month = month;
        m_day   = date - AbsoluteFromJulian( 1, month, year ) + 1;

        COleDateTime::SetDateTime( m_year, m_month, m_day, m_hour, m_min, m_sec );
    }

	//##ModelId=3ED5BCC4031D
    void
    Validize( void )
    {
        if ( (m_year < 1752)                      ||
             ((m_year == 1752) && (m_month <= 9))    )
            JulianFromAbsolute( AbsoluteFromJulian() );
        else
            GregorianFromAbsolute( AbsoluteFromGregorian() );
    }

#undef  sum
#undef  leapyear
};
