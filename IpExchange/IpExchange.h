
// IpExchange.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIpExchangeApp:
// �йش����ʵ�֣������ IpExchange.cpp
//

class CIpExchangeApp : public CWinAppEx
{
public:
	CIpExchangeApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIpExchangeApp theApp;