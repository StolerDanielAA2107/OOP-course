using System;

namespace Stoler_LR5
{
    [Serializable]
    public class Starosta_Stoler : Student_Stoler
    {
        public double Rating { get; set; }
        public long Phone_number { get; set; }
        public override void PrintToConsole()
        {
            base.PrintToConsole();
            Console.WriteLine("Рейтинг: " + Rating + "\n" + "Номер телефона: " + Phone_number);
        }
        public override void Read()
        {
            base.Read();
            Console.WriteLine("Введите рейтинг старосты");
            Rating = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите номер телефона старосты");
            Phone_number = (long)Convert.ToDouble(Console.ReadLine());
        }
    }
}
