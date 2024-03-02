#pragma 
#include <windows.h>

#include "Group.h"

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
    Group gr;
    shared_ptr<Student> p1 = make_shared<Student>();
    shared_ptr<Starosta> p2 = make_shared<Starosta>();
    menu();
    while (1) {
        cout << "Выберите пункт: " << endl;
        switch (InputCheck(0, 5))
        {
            case 0: { 
              exit(0);
            }
            case 1: {  
                int InpId = gr.sizevector() + 1;
                p1->InputFromConsole(InpId);
                InpId++;
                gr.AddStudent(p1);
                break;
            }
            case 2: {
                int InpId = gr.sizevector() + 1;
                p2->InputFromConsole(InpId);
                InpId++;
                gr.AddStudent(p2);
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