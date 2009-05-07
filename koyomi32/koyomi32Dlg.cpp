// koyomi32Dlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "koyomi32.h"
#include "koyomiDateTime.h"
#include "koyomi32Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////
/////////////////
// �A�v���P�[�V�����̃o�[�W��������\������_�C�A���O

//##ModelId=3ED5BCC50274
class CAboutDlg : public CDialog
{
public:
	//##ModelId=3ED5BCC5029F
	CAboutDlg();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	//##ModelId=3ED5BCC502CE
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//##ModelId=3ED5BCC5029F
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

//##ModelId=3ED5BCC502CE
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// ���b�Z�[�W �n���h��������܂���B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKoyomi32Dlg �_�C�A���O

//##ModelId=3ED5BCC403AB
CKoyomi32Dlg::CKoyomi32Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKoyomi32Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKoyomi32Dlg)
	m_todayMessage = _T("");
	m_targetTime = COleDateTime::GetCurrentTime();
    m_previousTime = m_targetTime;
	m_iyear = 0;
	m_imonth = 0;
	m_iday = 0;
	m_ihour = 0;
	m_iminute = 0;
	m_isecond = 0;
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//##ModelId=3ED5BCC5009D
void CKoyomi32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKoyomi32Dlg)
	DDX_Control(pDX, IDC_TODAY_INFO, m_editTodayInfo);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_monthcal);
	DDX_Text(pDX, IDC_TODAY_INFO, m_todayMessage);
	DDV_MaxChars(pDX, m_todayMessage, 20480);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, m_targetTime);
	DDX_Text(pDX, IDC_YEAR, m_iyear);
	DDV_MinMaxInt(pDX, m_iyear, 1, 9999);
	DDX_Text(pDX, IDC_MONTH, m_imonth);
	DDV_MinMaxInt(pDX, m_imonth, 1, 12);
	DDX_Text(pDX, IDC_DAY, m_iday);
	DDV_MinMaxInt(pDX, m_iday, 1, 31);
	DDX_Text(pDX, IDC_HOUR, m_ihour);
	DDV_MinMaxInt(pDX, m_ihour, 0, 24);
	DDX_Text(pDX, IDC_MINUTE, m_iminute);
	DDV_MinMaxInt(pDX, m_iminute, 0, 59);
	DDX_Text(pDX, IDC_SECOND, m_isecond);
	DDV_MinMaxInt(pDX, m_isecond, 0, 59);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKoyomi32Dlg, CDialog)
	//{{AFX_MSG_MAP(CKoyomi32Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_VERSION, OnButtonVersion)
	ON_NOTIFY(MCN_SELECT, IDC_MONTHCALENDAR1, OnSelectMonthcalendar1)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREV2, OnButtonPrev2)
	ON_BN_CLICKED(IDC_BUTTON_NEXT2, OnButtonNext2)
	ON_BN_CLICKED(IDC_BUTTON_PREV_6H, OnButtonPrev6h)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_6H, OnButtonNext6h)
	ON_BN_CLICKED(IDC_BUTTON_PREV_1H, OnButtonPrev1h)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_1H, OnButtonNext1h)
	ON_BN_CLICKED(IDC_BUTTON_PREV_30min, OnBUTTONPREV30min)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_30min, OnBUTTONNEXT30min)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, OnSelchangeMonthcalendar1)
	ON_BN_CLICKED(IDC_BUTTON_PREV3, OnButtonPrev3)
	ON_BN_CLICKED(IDC_BUTTON_NEXT3, OnButtonNext3)
	ON_EN_CHANGE(IDC_YEAR, OnChangeYear)
	ON_BN_CLICKED(IDC_JUMP, OnJump)
	ON_EN_CHANGE(IDC_MONTH, OnChangeMonth)
	ON_EN_CHANGE(IDC_DAY, OnChangeDay)
	ON_EN_CHANGE(IDC_HOUR, OnChangeHour)
	ON_EN_CHANGE(IDC_MINUTE, OnChangeMinute)
	ON_EN_CHANGE(IDC_SECOND, OnChangeSecond)
	ON_EN_KILLFOCUS(IDC_MONTH, OnKillfocusMonth)
	ON_EN_KILLFOCUS(IDC_YEAR, OnKillfocusYear)
	ON_EN_KILLFOCUS(IDC_DAY, OnKillfocusDay)
	ON_EN_KILLFOCUS(IDC_HOUR, OnKillfocusHour)
	ON_EN_KILLFOCUS(IDC_MINUTE, OnKillfocusMinute)
	ON_EN_KILLFOCUS(IDC_SECOND, OnKillfocusSecond)
	ON_BN_CLICKED(IDC_BUTTON_PREVMONTH, OnButtonPrevMonth)
	ON_BN_CLICKED(IDC_BUTTON_NEXTMONTH, OnButtonNextMonth)
	ON_BN_CLICKED(IDC_BUTTON_PREVDAY, OnButtonPrevDay)
	ON_BN_CLICKED(IDC_BUTTON_NEXTDAY, OnButtonNextDay)
	ON_BN_CLICKED(IDC_BUTTON_TODAY, OnButtonToday)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKoyomi32Dlg ���b�Z�[�W �n���h��

//##ModelId=3ED5BCC500CB
BOOL CKoyomi32Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���ڂ��V�X�e�� ���j���[�֒ǉ����܂��B

	// IDM_ABOUTBOX �̓R�}���h ���j���[�͈̔͂łȂ���΂Ȃ�܂���B
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
    wday[0] = "��";
    wday[1] = "��";
    wday[2] = "��";
    wday[3] = "��";
    wday[4] = "��";
    wday[5] = "��";
    wday[6] = "�y";
    bMonthCalAvailable = TRUE;
    PrintKoyomiMessage();           // �N�����̓��t�� koyomi ���b�Z�[�W��\��

	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// koyomi.exe / tamo.exe ���N�����A�\�����郁�b�Z�[�W���擾����
//##ModelId=3ED5BCC403C8
BOOL    CKoyomi32Dlg::PrintKoyomiMessage(SYSTEMTIME *pSystemTime)
{
    BOOL            bRet = TRUE, bJulian = FALSE;
    SYSTEMTIME      stStart;
    int             yy, mm, dd, HH, MM, SS;
    int             wYy, wMm, wDd;
    int             wDayOfWeek;
    char            todayStr[1024];
    CKoyomiDateTime curTime = COleDateTime::GetCurrentTime();

    if ( pSystemTime == NULL ) {
        m_monthcal.GetCurSel(&stStart);
        RedrawEditBoxes();
    }
    else {
        stStart = *pSystemTime;
    }

    yy = stStart.wYear;
    mm = stStart.wMonth;
    dd = stStart.wDay;
    HH = stStart.wHour;
    MM = stStart.wMinute;
    SS = stStart.wSecond;
    wDayOfWeek = stStart.wDayOfWeek;

    m_previousTime = stStart;

    if ( (curTime.GetYear()   == yy) &&
         (curTime.GetMonth()  == mm) &&
         (curTime.GetDay()    == dd) &&
         (curTime.GetHour()   == HH) &&
         (curTime.GetMinute() == MM)    ) {
        SS = curTime.GetSecond();
        m_targetTime = curTime;
    }
    else {
        CKoyomiDateTime targetTime( stStart );
        m_targetTime = targetTime;
    }

    if ( yy <= 1752 ) {
        CKoyomiDateTime newTime( yy, mm, dd, HH, MM, SS );
        CKoyomiDateTime baseTime( 1752, 9, 20, 0, 0, 0 );
        long    jd   = newTime.AbsoluteFromJulian();
        long    base = baseTime.AbsoluteFromJulian();

        if ( jd < base ) {
            // �O���S���I����ȑO
            newTime.GregorianFromAbsolute( jd );
            yy = newTime.GetYear();
            mm = newTime.GetMonth();
            dd = newTime.GetDay();
            bJulian = TRUE;

            baseTime.SetDateTime( 1752, 9, 1, 0, 0, 0 );
            base = baseTime.AbsoluteFromJulian();
            if ( jd < base ) {
                // CMonthCalCtrl �̓K�p�͈͊O
                DisableMonthCalCtrl();
            }
        }
        else {
            jd = newTime.AbsoluteFromGregorian();
            if ( (yy == 1752) && (mm == 9) && (dd >= 20) ) {
                jd = newTime.AbsoluteFromJulian();
                newTime.GregorianFromAbsolute( jd );
                yy = newTime.GetYear();
                mm = newTime.GetMonth();
                dd = newTime.GetDay();
                CKoyomiDateTime targetTime( yy, mm, dd, HH, MM, SS );
                m_targetTime = targetTime;
                m_monthcal.SetCurSel(m_targetTime);
                RedrawEditBoxes();
            }
            EnableMonthCalCtrl();
        }
        while ( jd < 0 )
            jd += 7;
        wDayOfWeek = (jd % 7);
    }
    else {
        EnableMonthCalCtrl();
    }
    wYy = m_targetTime.GetYear();
    wMm = m_targetTime.GetMonth();
    wDd = m_targetTime.GetDay();

    sprintf( todayStr, "%4d/%02d/%02d(%s) %02d:%02d:%02d [%s��]",
             wYy, wMm, wDd, wday[wDayOfWeek], HH, MM, SS,
             bJulian == TRUE ? "�����E�X" : "�O���S���I" );

    {
        char    cmd[1024];

        sprintf( cmd, "cmd /c tamo %04d%02d%02d %02d%02d%02d > ./result.txt",
                 yy, mm, dd, HH, MM, SS );
//      system( cmd );
        WinExec( cmd, SW_HIDE ); Sleep(500);

        FILE    *fp;
        char    buf[BUFSIZ], *p;

        if ( ( fp = fopen( "./result.txt", "r" ) ) != NULL ) {
            m_todayMessage = _T( "" );
            while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
                buf[strlen(buf) - 1] = '\0';
                m_todayMessage += _T( buf );
                m_todayMessage += _T( "\r\n" );
            }
            fclose( fp );
            unlink( "./result.txt" );
        }
        else {
            bRet = FALSE;
        }
    }

    m_editTodayInfo.SetWindowText( m_todayMessage );
    SetWindowText( todayStr );

    return ( bRet );
}

//##ModelId=3ED5BCC5001F
void CKoyomi32Dlg::EnableMonthCalCtrl( void )
{
    if ( bMonthCalAvailable == FALSE ) {
        CMonthCalCtrl   *p = (CMonthCalCtrl *)GetDlgItem( IDC_MONTHCALENDAR1 );
        p->EnableWindow( TRUE );
        bMonthCalAvailable = TRUE;
    }
}

//##ModelId=3ED5BCC5002E
void CKoyomi32Dlg::DisableMonthCalCtrl( void )
{
    if ( bMonthCalAvailable == TRUE ) {
        CMonthCalCtrl   *p = (CMonthCalCtrl *)GetDlgItem( IDC_MONTHCALENDAR1 );
        p->EnableWindow( FALSE );
        bMonthCalAvailable = FALSE;
    }
}

//##ModelId=3ED5BCC50000
BOOL CKoyomi32Dlg::GetCurSel( void )
{
    BOOL    ret;

    ret = m_monthcal.GetCurSel(m_targetTime);
    if ( m_targetTime.GetYear() < 0 ) {
        // �Ȃ��� COleDateTime ���ƁA���܂� GetCurSel() �ł��Ȃ����Ƃ����邽�߁ACTime �� GetCurSel() ������
        // �������ACTime ���g���ꍇ�A�N�����̗L���͈͂� time_t �Ɠ��l 1970�N1��1��9��0��0�b(���{����) �` 2038�N1��18�� �ƂȂ�
        try {
            CTime       m_targetTime2;
            SYSTEMTIME  sysTime;
            ret = m_monthcal.GetCurSel(m_targetTime2);
            sysTime.wYear   = m_targetTime2.GetYear();
            sysTime.wMonth  = m_targetTime2.GetMonth();
            sysTime.wDay    = m_targetTime2.GetDay();
            sysTime.wHour   = m_targetTime2.GetHour();
            sysTime.wMinute = m_targetTime2.GetMinute();
            sysTime.wSecond = m_targetTime2.GetSecond();
            m_targetTime    = sysTime;
        }
        catch (...) {   // ��O�����������ꍇ
#if 1
            m_targetTime = m_previousTime;                  // ���O�̔N�����ɖ߂�
#else
            m_targetTime = COleDateTime::GetCurrentTime();  // �����I�Ɍ��ݎ����ɖ߂�
#endif
            ret = FALSE;
        }
    }

    return ( ret );
}

//##ModelId=3ED5BCC5000F
void CKoyomi32Dlg::RedrawEditBoxes()
{
    if ( m_targetTime.GetStatus() != COleDateTime::valid ) {
        m_targetTime.Validize();
        m_monthcal.SetCurSel(m_targetTime);
    }
    m_iyear   = m_targetTime.GetYear();
    m_imonth  = m_targetTime.GetMonth();
    m_iday    = m_targetTime.GetDay();
    m_ihour   = m_targetTime.GetHour();
    m_iminute = m_targetTime.GetMinute();
    m_isecond = m_targetTime.GetSecond();
    SetDlgItemInt( IDC_YEAR,   m_iyear   );
    SetDlgItemInt( IDC_MONTH,  m_imonth  );
    SetDlgItemInt( IDC_DAY,    m_iday    );
    SetDlgItemInt( IDC_HOUR,   m_ihour   );
    SetDlgItemInt( IDC_MINUTE, m_iminute );
    SetDlgItemInt( IDC_SECOND, m_isecond );
}


//##ModelId=3ED5BCC500DA
void CKoyomi32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

//##ModelId=3ED5BCC500FA
void CKoyomi32Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
//##ModelId=3ED5BCC50109
HCURSOR CKoyomi32Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//##ModelId=3ED5BCC50119
void CKoyomi32Dlg::OnButtonVersion() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


//##ModelId=3ED5BCC50128
void CKoyomi32Dlg::OnSelectMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    NMDAYSTATE* pDayState= (NMDAYSTATE *)pNMHDR;
	*pResult = 0;

    if ( (pDayState->stStart.wYear  == m_targetTime.GetYear())  &&
         (pDayState->stStart.wMonth == m_targetTime.GetMonth()) &&
         (pDayState->stStart.wDay   == m_targetTime.GetDay())      ) {
        return;
    }

    pDayState->stStart.wHour      = m_targetTime.GetHour();
    pDayState->stStart.wMinute    = m_targetTime.GetMinute();
    pDayState->stStart.wSecond    = m_targetTime.GetSecond();
    pDayState->stStart.wDayOfWeek = m_targetTime.GetDayOfWeek() - 1;
        // SYSTEMTIME   �� wDayOfWeek     �� ���j=0�A���j=1�A...�A�y�j=6
        // COleDateTime �� GetDayOfWeek() �� ���j=1�A���j=2�A...�A�y�j=7

    PrintKoyomiMessage( &(pDayState->stStart) );
    RedrawEditBoxes();
}


//##ModelId=3ED5BCC50138
void CKoyomi32Dlg::OnButtonPrev() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() <= 1 )
        return;

	// 1�N�O�ɖ߂�
    CKoyomiDateTime newTime( m_targetTime.GetYear() - 1,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50148
void CKoyomi32Dlg::OnButtonNext() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() >= 9999 )
        return;

	// 1�N��ɐi��
    CKoyomiDateTime newTime( m_targetTime.GetYear() + 1,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50157
void CKoyomi32Dlg::OnButtonPrev2() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() <= 10 )
        return;

    // 10�N�O�ɖ߂�
    CKoyomiDateTime newTime( m_targetTime.GetYear() - 10,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50167
void CKoyomi32Dlg::OnButtonNext2() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() >= 9990 )
        return;

	// 10�N��ɐi��
    CKoyomiDateTime newTime( m_targetTime.GetYear() + 10,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501C5
void CKoyomi32Dlg::OnButtonPrev3() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() <= 100 )
        return;

    // 100�N�O�ɖ߂�
    CKoyomiDateTime newTime( m_targetTime.GetYear() - 100,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501C7
void CKoyomi32Dlg::OnButtonNext3() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( m_targetTime.GetYear() >= 9900 )
        return;

    // 100�N��ɐi��
    CKoyomiDateTime newTime( m_targetTime.GetYear() + 100,
                             m_targetTime.GetMonth(),
                             (m_targetTime.GetMonth() !=  2) ||
                               (m_targetTime.GetDay() != 29)
                                 ? m_targetTime.GetDay()
                                 : m_targetTime.GetDay() - 1,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50177
void CKoyomi32Dlg::OnButtonPrev6h() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 1) &&
         (m_targetTime.GetMonth() == 1) &&
         (m_targetTime.GetDay()   == 1) &&
         (m_targetTime.GetHour()  <  6)    )
        return;

	// 6���ԑO�ɖ߂�
    COleDateTimeSpan    diff( 0, 6, 0, 0 );
    m_targetTime -= diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50179
void CKoyomi32Dlg::OnButtonNext6h() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 9999) &&
         (m_targetTime.GetMonth() ==   12) &&
         (m_targetTime.GetDay()   ==   31) &&
         (m_targetTime.GetHour()  >=   18)    )
        return;

	// 6���Ԍ�ɐi��
    COleDateTimeSpan    diff( 0, 6, 0, 0 );
    m_targetTime += diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50187
void CKoyomi32Dlg::OnButtonPrev1h() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 1) &&
         (m_targetTime.GetMonth() == 1) &&
         (m_targetTime.GetDay()   == 1) &&
         (m_targetTime.GetHour()  <  1)    )
        return;

	// 1���ԑO�ɖ߂�
    COleDateTimeSpan    diff( 0, 1, 0, 0 );
    m_targetTime -= diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50196
void CKoyomi32Dlg::OnButtonNext1h() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 9999) &&
         (m_targetTime.GetMonth() ==   12) &&
         (m_targetTime.GetDay()   ==   31) &&
         (m_targetTime.GetHour()  >=   23)    )
        return;

	// 1���Ԍ�ɐi��
    COleDateTimeSpan    diff( 0, 1, 0, 0 );
    m_targetTime += diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50198
void CKoyomi32Dlg::OnBUTTONPREV30min() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()   ==  1) &&
         (m_targetTime.GetMonth()  ==  1) &&
         (m_targetTime.GetDay()    ==  1) &&
         (m_targetTime.GetHour()   ==  0) &&
         (m_targetTime.GetMinute() <  30)    )
        return;

	// 30���O�ɖ߂�
    COleDateTimeSpan    diff( 0, 0, 30, 0 );
    m_targetTime -= diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501A6
void CKoyomi32Dlg::OnBUTTONNEXT30min() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()   == 9999) &&
         (m_targetTime.GetMonth()  ==   12) &&
         (m_targetTime.GetDay()    ==   31) &&
         (m_targetTime.GetHour()   ==   23) &&
         (m_targetTime.GetMinute() >=   30)    )
        return;

	// 30����ɐi��
    COleDateTimeSpan    diff( 0, 0, 30, 0 );
    m_targetTime += diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501B5
void CKoyomi32Dlg::OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    NMDAYSTATE* pDayState = (NMDAYSTATE *)pNMHDR;
	*pResult = 0;

    if ( pDayState->stStart.wYear < 1752 )
        return;
    if ( pDayState->stStart.wYear == 1752 ) {
        CKoyomiDateTime baseTime( 1752, 9, 1, 0, 0, 0 );
        CKoyomiDateTime newTime( pDayState->stStart );
        long    jd   = newTime.AbsoluteFromJulian();
        long    base = baseTime.AbsoluteFromJulian();

        if ( jd < base ) {
            return;
        }
    }

    if ( (pDayState->stStart.wYear  == m_targetTime.GetYear())  &&
         (pDayState->stStart.wMonth == m_targetTime.GetMonth()) &&
         (pDayState->stStart.wDay   == m_targetTime.GetDay())      ) {
        return;
    }

    pDayState->stStart.wHour      = m_targetTime.GetHour();
    pDayState->stStart.wMinute    = m_targetTime.GetMinute();
    pDayState->stStart.wSecond    = m_targetTime.GetSecond();

    GetCurSel();
    pDayState->stStart.wDayOfWeek = m_targetTime.GetDayOfWeek() - 1;
        // SYSTEMTIME   �� wDayOfWeek     �� ���j=0�A���j=1�A...�A�y�j=6
        // COleDateTime �� GetDayOfWeek() �� ���j=1�A���j=2�A...�A�y�j=7

    PrintKoyomiMessage( &(pDayState->stStart) );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501E4
void CKoyomi32Dlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
    // m_iyear, m_imonth, ..., m_isecond �ɔ͈͊O�̒l�������Ă���ƁA�u�I���v�{�^����
    // �����Ă��I���ł��Ȃ����߁A�����I�� m_targetTime �̓��e��ݒ肵�Ă���A�I������
    RedrawEditBoxes();

	CDialog::OnOK();
}

//##ModelId=3ED5BCC501E6
void CKoyomi32Dlg::OnJump() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    // �w��N���������b�ֈړ�
 /* COleDateTime */ CKoyomiDateTime
                   newTime( m_iyear,
                            m_imonth,
                            m_iday,
                            m_ihour,
                            m_iminute,
                            m_isecond );
    newTime.Validize();
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC501D4
void CKoyomi32Dlg::OnChangeYear() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curYear = m_iyear;
    m_iyear = GetDlgItemInt( IDC_YEAR );
    if ( (m_iyear < 0) || (m_iyear > 9999 ) ) {
        m_iyear = curYear;
        SetDlgItemInt( IDC_YEAR, m_iyear );
    }
}

//##ModelId=3ED5BCC501F4
void CKoyomi32Dlg::OnChangeMonth() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curMonth = m_imonth;
    m_imonth = GetDlgItemInt( IDC_MONTH );
    if ( (m_imonth < 0) || (m_imonth > 99 ) ) {
        m_imonth = curMonth;
        SetDlgItemInt( IDC_MONTH, m_imonth );
    }
}

//##ModelId=3ED5BCC501F6
void CKoyomi32Dlg::OnChangeDay() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curDay = m_iday;
    m_iday = GetDlgItemInt( IDC_DAY );
    if ( (m_iday < 0) || (m_iday > 99 ) ) {
        m_iday = curDay;
        SetDlgItemInt( IDC_DAY, m_iday );
    }
}

//##ModelId=3ED5BCC501F8
void CKoyomi32Dlg::OnChangeHour() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curHour = m_ihour;
    m_ihour = GetDlgItemInt( IDC_HOUR );
    if ( (m_ihour < 0) || (m_ihour > 99 ) ) {
        m_ihour = curHour;
        SetDlgItemInt( IDC_HOUR, m_ihour );
    }
}

//##ModelId=3ED5BCC50204
void CKoyomi32Dlg::OnChangeMinute() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curMinute = m_iminute;
    m_iminute = GetDlgItemInt( IDC_MINUTE );
    if ( (m_iminute < 0) || (m_iminute > 99 ) ) {
        m_iminute = curMinute;
        SetDlgItemInt( IDC_MINUTE, m_iminute );
    }
}

//##ModelId=3ED5BCC50206
void CKoyomi32Dlg::OnChangeSecond() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CDialog::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    int curSecond = m_isecond;
    m_isecond = GetDlgItemInt( IDC_SECOND );
    if ( (m_isecond < 0) || (m_isecond > 99 ) ) {
        m_isecond = curSecond;
        SetDlgItemInt( IDC_SECOND, m_isecond );
    }
}

//##ModelId=3ED5BCC50216
void CKoyomi32Dlg::OnKillfocusYear() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_iyear = GetDlgItemInt( IDC_YEAR );
    if ( (m_iyear <= 0) || (m_iyear > 9999 ) ) {
        m_iyear = m_targetTime.GetYear();
        SetDlgItemInt( IDC_YEAR, m_iyear );
    }
}

//##ModelId=3ED5BCC50214
void CKoyomi32Dlg::OnKillfocusMonth() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_imonth = GetDlgItemInt( IDC_MONTH );
    if ( (m_imonth <= 0) || (m_imonth > 12 ) ) {
        m_imonth = m_targetTime.GetMonth();
        SetDlgItemInt( IDC_MONTH, m_imonth );
    }
}

//##ModelId=3ED5BCC50222
void CKoyomi32Dlg::OnKillfocusDay() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_iday = GetDlgItemInt( IDC_DAY );
    if ( (m_iday <= 0) || (m_iday > 31 ) ) {
        m_iday = m_targetTime.GetDay();
        SetDlgItemInt( IDC_DAY, m_iday );
    }
}

//##ModelId=3ED5BCC50224
void CKoyomi32Dlg::OnKillfocusHour() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_ihour = GetDlgItemInt( IDC_HOUR );
    if ( (m_ihour < 0) || (m_ihour > 24 ) ) {
        m_ihour = m_targetTime.GetHour();
        SetDlgItemInt( IDC_HOUR, m_ihour );
    }
}

//##ModelId=3ED5BCC50226
void CKoyomi32Dlg::OnKillfocusMinute() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_iminute = GetDlgItemInt( IDC_MINUTE );
    if ( (m_iminute < 0) || (m_iminute > 59 ) ) {
        m_iminute = m_targetTime.GetMinute();
        SetDlgItemInt( IDC_MINUTE, m_iminute );
    }
}

//##ModelId=3ED5BCC50233
void CKoyomi32Dlg::OnKillfocusSecond() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    m_isecond = GetDlgItemInt( IDC_SECOND );
    if ( (m_isecond < 0) || (m_isecond > 59 ) ) {
        m_isecond = m_targetTime.GetSecond();
        SetDlgItemInt( IDC_SECOND, m_isecond );
    }
}

#define leapYearOfGregorian( year ) ( ((year) % 4 == 0) && (((year) % 100 != 0) || ((year) % 400 == 0)) )
#define leapYearOfJulian( year )    ((year) % 4 == 0)

//##ModelId=3ED5BCC50235
void CKoyomi32Dlg::OnButtonPrevMonth() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 1) &&
         (m_targetTime.GetMonth() <= 1)    )
        return;

	// 1���O�ɖ߂�
    int yy, mm, dd;
    yy = m_targetTime.GetYear();
    mm = m_targetTime.GetMonth();
    dd = m_targetTime.GetDay();

    if ( (mm == 3) && (dd >= 29) ) {
        if ( ((yy >  1752) && leapYearOfGregorian( yy )) ||
             ((yy <= 1752) && leapYearOfJulian( yy ))       )
            dd = 29;
        else
            dd = 28;
    }
    else if ( ((mm ==  1) ||
               (mm ==  5) ||
               (mm ==  7) ||
               (mm ==  8) ||
               (mm == 10) ||
               (mm == 12)   ) && (dd == 31) ) {
        dd = 30;
    }

    mm--;
    if ( mm <= 0 ) {
        mm += 12;
        yy--;
    }

    CKoyomiDateTime newTime( yy,
                             mm,
                             dd,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50242
void CKoyomi32Dlg::OnButtonNextMonth() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 9999) &&
         (m_targetTime.GetMonth() >=   12)    )
        return;

	// 1����ɐi��
    int yy, mm, dd;
    yy = m_targetTime.GetYear();
    mm = m_targetTime.GetMonth();
    dd = m_targetTime.GetDay();

    if ( (mm == 1) && (dd >= 29) ) {
        if ( ((yy >  1752) && leapYearOfGregorian( yy )) ||
             ((yy <= 1752) && leapYearOfJulian( yy ))       )
            dd = 29;
        else
            dd = 28;
    }
    else if ( ((mm ==  3) ||
               (mm ==  5) ||
               (mm ==  7) ||
               (mm ==  8) ||
               (mm == 10) ||
               (mm == 12)   ) && (dd == 31) ) {
        dd = 30;
    }

    mm++;
    if ( mm > 12 ) {
        mm -= 12;
        yy++;
    }

    CKoyomiDateTime newTime( yy,
                             mm,
                             dd,
                             m_targetTime.GetHour(),
                             m_targetTime.GetMinute(),
                             m_targetTime.GetSecond() );
    m_targetTime = newTime;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50244
void CKoyomi32Dlg::OnButtonPrevDay() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 1) &&
         (m_targetTime.GetMonth() == 1) &&
         (m_targetTime.GetDay()   <= 1)    )
        return;

	// 1���O�ɖ߂�
    COleDateTimeSpan    diff( 1, 0, 0, 0 );
    m_targetTime -= diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50246
void CKoyomi32Dlg::OnButtonNextDay() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    if ( (m_targetTime.GetYear()  == 9999) &&
         (m_targetTime.GetMonth() == 9999) &&
         (m_targetTime.GetDay()   >=   12)    )
        return;

	// 1����ɐi��
    COleDateTimeSpan    diff( 1, 0, 0, 0 );
    m_targetTime += diff;

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50252
void CKoyomi32Dlg::OnButtonToday() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	// �����ɖ߂�
    m_targetTime = COleDateTime::GetCurrentTime();

    m_monthcal.SetCurSel(m_targetTime);
    m_previousTime = m_targetTime;

    SYSTEMTIME  _sysTime;
    m_targetTime.GetAsSystemTime( _sysTime );
    PrintKoyomiMessage( &_sysTime );
    RedrawEditBoxes();
}

//##ModelId=3ED5BCC50254
void CKoyomi32Dlg::OnButtonHelp() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	MessageBox( "���݁A�s�Ӎ쐬���ł��B", "�w���v", MB_ICONINFORMATION | MB_OK );
}
