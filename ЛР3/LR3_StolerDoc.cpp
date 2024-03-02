
// LR3_StolerDoc.cpp: реализация класса CLR3StolerDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "LR3_Stoler.h"
#endif

#include "LR3_StolerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLR3StolerDoc

IMPLEMENT_DYNCREATE(CLR3StolerDoc, CDocument)

BEGIN_MESSAGE_MAP(CLR3StolerDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CLR3StolerDoc

CLR3StolerDoc::CLR3StolerDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CLR3StolerDoc::~CLR3StolerDoc()
{
}

BOOL CLR3StolerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	students.clear();
	return TRUE;
}




// Сериализация CLR3StolerDoc

void CLR3StolerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		students.fout(ar);
	}
	else
	{
		students.fin(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CLR3StolerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CLR3StolerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CLR3StolerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CLR3StolerDoc

#ifdef _DEBUG
void CLR3StolerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLR3StolerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CLR3StolerDoc