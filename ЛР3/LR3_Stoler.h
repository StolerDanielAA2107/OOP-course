
// LR3_Stoler.h: основной файл заголовка для приложения LR3_Stoler
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CLR3StolerApp:
// Сведения о реализации этого класса: LR3_Stoler.cpp
//

class CLR3StolerApp : public CWinApp
{
public:
	CLR3StolerApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLR3StolerApp theApp;
