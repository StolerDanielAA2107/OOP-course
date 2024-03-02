
// LR3_StolerView.h: интерфейс класса CLR3StolerView
//

#pragma once


class CLR3StolerView : public CScrollView
{
protected: // создать только из сериализации
	CLR3StolerView() noexcept;
	DECLARE_DYNCREATE(CLR3StolerView)

// Атрибуты
public:
	CLR3StolerDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	
	// Реализация
public:
	virtual ~CLR3StolerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в LR3_StolerView.cpp
inline CLR3StolerDoc* CLR3StolerView::GetDocument() const
   { return reinterpret_cast<CLR3StolerDoc*>(m_pDocument); }
#endif