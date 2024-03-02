// MFCLibrary1.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFCLibrary1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


extern "C"
{
	__declspec(dllexport) void F()
	{

	}
}

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibrary1App

BEGIN_MESSAGE_MAP(CMFCLibrary1App, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibrary1App

CMFCLibrary1App::CMFCLibrary1App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibrary1App

CMFCLibrary1App theApp;


// Инициализация CMFCLibrary1App

BOOL CMFCLibrary1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C" _declspec(dllexport) void load(const char* fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.load(fileName);
}

extern "C" _declspec(dllexport) void save(const char* fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.save(fileName);
}

extern "C" _declspec(dllexport) void clear()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	students.clear();
}

extern "C" _declspec(dllexport) void addStudent()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.addStudent();
}

extern "C" _declspec(dllexport) void addCaptain()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.addCaptain();
}

extern "C" _declspec(dllexport) int getSize()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return students.getSize();
}

extern "C" _declspec(dllexport) int getType(int n)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return students.getType(n);
}

extern "C" _declspec(dllexport) void setName(int n, char *str)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.setName(n, str);
}

extern "C" _declspec(dllexport) void getName(int n, char *str)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	strcpy(str, students.getName(n).c_str());
}

extern "C" _declspec(dllexport) void setGroup(int n, char* str)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.setGroup(n, str);
}

extern "C" _declspec(dllexport) void getGroup(int n, char* str)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	strcpy(str, students.getGroup(n).c_str());
}

extern "C" _declspec(dllexport) void setAge(int n, int age)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.setAge(n, age);
}

extern "C" _declspec(dllexport) int getAge(int n)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return students.getAge(n);
}

extern "C" _declspec(dllexport) void setRating(int n, int bonus)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.setRating(n, bonus);
}

extern "C" _declspec(dllexport) int getRating(int n)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return students.getRating(n);
}

extern "C" _declspec(dllexport) void setPhone(int n, int num)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	students.setPhone(n, num);
}

extern "C" _declspec(dllexport) int getPhone(int n)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return students.getPhone(n);
}