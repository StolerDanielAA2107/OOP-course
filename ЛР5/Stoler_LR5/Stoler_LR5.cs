using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stoler_LR5
{
    class Program
    {
        static void Main(string[] args)
        {
            Group_Stoler Group = new();
            bool check = true;
            Menu();
            while (check)
            {
                int value;
                Console.WriteLine("Выберите пункт" + "\n");
                value = int.Parse(Console.ReadLine());
                switch (value)
                {
                    case 0:
                        check = false;
                        break;
                    case 1:
                        Student_Stoler st = new();
                        st.Read();
                        Group.AddStudent(st);
                        break;
                    case 2:
                        Starosta_Stoler cap = new();
                        cap.Read();
                        Group.AddStudent(cap);
                        break;
                    case 3:
                        Group.PrintAll();
                        break;
                    case 4:
                        Group_Stoler.SaveStudents(Group);
                        break;
                    case 5:
                        Group = Group_Stoler.LoadStudents();
                        break;
                    case 6:
                        Group.DeleteStudents();
                        break;
                }
            }
        }
        static void Menu()
        {
            Console.WriteLine("1.Добавить студента" + "\n"
                            + "2.Добавить старосту" + "\n"
                            + "3.Посмотреть всех студентов" + "\n"
                            + "4.Сохранить в файл" + "\n"
                            + "5.Загрузить из файла" + "\n"
                            + "6.Удалить студентов" + "\n");
        }
    }
}
