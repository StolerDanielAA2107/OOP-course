// ЛР2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "ЛР2.h"
#include "GroupStoler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Единственный объект приложения

CWinApp theApp;

using namespace std;
void menu() {
    setlocale(LC_ALL, ".1251");
    SetConsoleCP(1251);
    cout << "1. Ввести студента" << endl;
    cout << "2. Ввести старосту" << endl;
    cout << "3. Посмотреть всех студентов" << endl;
    cout << "4. Сохранить в файл" << endl;
    cout << "5. Загрузить из файла" << endl;
    cout << "6. Удалить студентов" << endl;
    cout << "0. Выход" << endl;
}
int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            GroupStoler gr;
            menu();
            while (1) {
                cout << "Выберите пункт: " << endl;
                switch (InputCheck(0, 6))
                {
                case 0: {
                    exit(0);
                }
                case 1: {
                    shared_ptr<Student_Stoler> p1 = make_shared<Student_Stoler>();
                    int InpId = gr.sizevector() + 1;
                    p1->InputFromConsole(InpId);
                    InpId++;
                    gr.AddStudent(p1);
                    break;
                }
                case 2: {
                    shared_ptr<Starosta_Stoler> p2 = make_shared<Starosta_Stoler>();
                    int InpId = gr.sizevector() + 1;
                    p2->InputFromConsole(InpId);
                    InpId++;
                    gr.AddStudent(p2);
                    break;
                }
                case 3: {
                    gr.PrintAll();
                    break;
                }
                case 4: {
                    gr.savetofile();
                    break;
                }
                case 5: {
                    gr.loadfromfile();
                    break;
                }
                case 6: {
                    gr.clearstudents();
                    break;
                }
                }
            }
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
