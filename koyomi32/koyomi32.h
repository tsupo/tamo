// koyomi32.h : KOYOMI32 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_)
#define AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

//////////////////////////////////////////////////////////////
/////////////////
// CKoyomi32App:
// ���C���X���b�h

//##ModelId=3ED5BCC50261
class CKoyomi32App : public CWinApp
{
public:
	//##ModelId=3ED5BCC50271
	CKoyomi32App();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CKoyomi32App)
	public:
	//##ModelId=3ED5BCC50272
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CKoyomi32App)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_KOYOMI32_H__EBAC3DA5_7810_11D4_8517_00A0246CF736__INCLUDED_)
