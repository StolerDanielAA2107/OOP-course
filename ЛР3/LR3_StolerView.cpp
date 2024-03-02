
// LR3_StolerView.cpp: реализация класса CLR3StolerView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "LR3_Stoler.h"
#endif

#include "LR3_StolerDoc.h"
#include "LR3_StolerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLR3StolerView

IMPLEMENT_DYNCREATE(CLR3StolerView, CScrollView)

BEGIN_MESSAGE_MAP(CLR3StolerView, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение CLR3StolerView

CLR3StolerView::CLR3StolerView() noexcept
{
	// TODO: добавьте код создания

}

CLR3StolerView::~CLR3StolerView()
{
}

BOOL CLR3StolerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CLR3StolerView

void CLR3StolerView::OnDraw(CDC* pDC)
{
	CLR3StolerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CSize sizeTotal = pDoc->students.drow(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CLR3StolerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

// Диагностика CLR3StolerView

#ifdef _DEBUG
void CLR3StolerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CLR3StolerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLR3StolerDoc* CLR3StolerView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLR3StolerDoc)));
	return (CLR3StolerDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CLR3StolerView
