// koyomi32.h : KOYOMI32 アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_)
#define AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

//////////////////////////////////////////////////////////////
/////////////////
// CKoyomi32App:
// メインスレッド

//##ModelId=3ED5BCC50261
class CKoyomi32App : public CWinApp
{
public:
	//##ModelId=3ED5BCC50271
	CKoyomi32App();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CKoyomi32App)
	public:
	//##ModelId=3ED5BCC50272
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CKoyomi32App)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_)
