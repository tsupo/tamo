// koyomi32Dlg.h : ヘッダー ファイル
//

#if !defined(AFX_KOYOMI32DLG_H__EBAC3DA7_7810_11D4_8517_00A0246CF736__INCLUDED_)
#define AFX_KOYOMI32DLG_H__EBAC3DA7_7810_11D4_8517_00A0246CF736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////
/////////////////
// CKoyomi32Dlg ダイアログ
//(アプリケーション本体。メインのダイアログ)

//##ModelId=3ED5BCC40399
class CKoyomi32Dlg : public CDialog
{
// 構築
private:
	//##ModelId=3ED5BCC403A9
    char    *wday[7];
	//##ModelId=3ED5BCC403AA
    BOOL    bMonthCalAvailable;

public:
	//##ModelId=3ED5BCC403AB
	CKoyomi32Dlg(CWnd* pParent = NULL);	// 標準のコンストラクタ
	//##ModelId=3ED5BCC403C8
    BOOL    PrintKoyomiMessage(SYSTEMTIME *pSystemTime = NULL);
	//##ModelId=3ED5BCC50000
	BOOL    GetCurSel( void );
	//##ModelId=3ED5BCC5000F
    void    RedrawEditBoxes( void );
	//##ModelId=3ED5BCC5001F
    void    EnableMonthCalCtrl( void );
	//##ModelId=3ED5BCC5002E
    void    DisableMonthCalCtrl( void );

// ダイアログ データ
	//{{AFX_DATA(CKoyomi32Dlg)
	enum { IDD = IDD_KOYOMI32_DIALOG };
	//##ModelId=3ED5BCC5004F
	CEdit	m_editTodayInfo;
	//##ModelId=3ED5BCC50054
	CMonthCalCtrl	m_monthcal;
	//##ModelId=3ED5BCC5005D
	CString	m_todayMessage;
	//##ModelId=3ED5BCC5005F
	CKoyomiDateTime	m_targetTime;
	//##ModelId=3ED5BCC5006E
	CKoyomiDateTime	m_previousTime;
	//##ModelId=3ED5BCC50072
	int		m_iyear;
	//##ModelId=3ED5BCC5007D
	int		m_imonth;
	//##ModelId=3ED5BCC5007E
	int		m_iday;
	//##ModelId=3ED5BCC5008C
	int		m_ihour;
	//##ModelId=3ED5BCC5008D
	int		m_iminute;
	//##ModelId=3ED5BCC5009C
	int		m_isecond;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CKoyomi32Dlg)
	protected:
	//##ModelId=3ED5BCC5009D
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//##ModelId=3ED5BCC500BB
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CKoyomi32Dlg)
	//##ModelId=3ED5BCC500CB
	virtual BOOL OnInitDialog();
	//##ModelId=3ED5BCC500DA
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//##ModelId=3ED5BCC500FA
	afx_msg void OnPaint();
	//##ModelId=3ED5BCC50109
	afx_msg HCURSOR OnQueryDragIcon();
	//##ModelId=3ED5BCC50119
	afx_msg void OnButtonVersion();
	//##ModelId=3ED5BCC50128
	afx_msg void OnSelectMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=3ED5BCC50138
	afx_msg void OnButtonPrev();
	//##ModelId=3ED5BCC50148
	afx_msg void OnButtonNext();
	//##ModelId=3ED5BCC50157
	afx_msg void OnButtonPrev2();
	//##ModelId=3ED5BCC50167
	afx_msg void OnButtonNext2();
	//##ModelId=3ED5BCC50177
	afx_msg void OnButtonPrev6h();
	//##ModelId=3ED5BCC50179
	afx_msg void OnButtonNext6h();
	//##ModelId=3ED5BCC50187
	afx_msg void OnButtonPrev1h();
	//##ModelId=3ED5BCC50196
	afx_msg void OnButtonNext1h();
	//##ModelId=3ED5BCC50198
	afx_msg void OnBUTTONPREV30min();
	//##ModelId=3ED5BCC501A6
	afx_msg void OnBUTTONNEXT30min();
	//##ModelId=3ED5BCC501B5
	afx_msg void OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=3ED5BCC501C5
	afx_msg void OnButtonPrev3();
	//##ModelId=3ED5BCC501C7
	afx_msg void OnButtonNext3();
	//##ModelId=3ED5BCC501D4
	afx_msg void OnChangeYear();
	//##ModelId=3ED5BCC501E4
	virtual void OnOK();
	//##ModelId=3ED5BCC501E6
	afx_msg void OnJump();
	//##ModelId=3ED5BCC501F4
	afx_msg void OnChangeMonth();
	//##ModelId=3ED5BCC501F6
	afx_msg void OnChangeDay();
	//##ModelId=3ED5BCC501F8
	afx_msg void OnChangeHour();
	//##ModelId=3ED5BCC50204
	afx_msg void OnChangeMinute();
	//##ModelId=3ED5BCC50206
	afx_msg void OnChangeSecond();
	//##ModelId=3ED5BCC50214
	afx_msg void OnKillfocusMonth();
	//##ModelId=3ED5BCC50216
	afx_msg void OnKillfocusYear();
	//##ModelId=3ED5BCC50222
	afx_msg void OnKillfocusDay();
	//##ModelId=3ED5BCC50224
	afx_msg void OnKillfocusHour();
	//##ModelId=3ED5BCC50226
	afx_msg void OnKillfocusMinute();
	//##ModelId=3ED5BCC50233
	afx_msg void OnKillfocusSecond();
	//##ModelId=3ED5BCC50235
	afx_msg void OnButtonPrevMonth();
	//##ModelId=3ED5BCC50242
	afx_msg void OnButtonNextMonth();
	//##ModelId=3ED5BCC50244
	afx_msg void OnButtonPrevDay();
	//##ModelId=3ED5BCC50246
	afx_msg void OnButtonNextDay();
	//##ModelId=3ED5BCC50252
	afx_msg void OnButtonToday();
	//##ModelId=3ED5BCC50254
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_KOYOMI32DLG_H__EBAC3DA7_7810_11D4_8517_00A0246CF736__INCLUDED_)
