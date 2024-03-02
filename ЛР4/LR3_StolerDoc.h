
// LR3_StolerDoc.h: интерфейс класса CLR3StolerDoc 
//


#pragma once
#include "Students_Stoler.h"

class CLR3StolerDoc : public CDocument
{
protected: // создать только из сериализации
	CLR3StolerDoc() noexcept;
	DECLARE_DYNCREATE(CLR3StolerDoc)

// Атрибуты
public:
	Students_Stoler students;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CLR3StolerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
