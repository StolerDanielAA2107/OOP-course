using System;
using System.Text;

namespace Stoler_LR5
{
    [Serializable]
    public class Student_Stoler
    {
        public String Name { get; set; } = string.Empty;
        public int Age { get; set; }
        public String Group { get; set; } = string.Empty;

        public virtual void PrintToConsole()
        {
            Console.WriteLine("\n" + "Имя: " + Name + "\n" + "Возраст: " + Age + "\n" + "Группа: " + Group );
        }
        public virtual void Read()
        {
            Console.WriteLine("Введите имя:");
            Name = Console.ReadLine();
            Console.WriteLine("Введите возраст:");
            Age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите название группы:");
            Group = Console.ReadLine();
        }
    }
}
