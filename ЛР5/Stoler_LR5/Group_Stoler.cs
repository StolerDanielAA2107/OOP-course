using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace Stoler_LR5
{
    [Serializable]
    public class Group_Stoler
    {
        public List<Student_Stoler> Group { get; set; } = [];
        public void AddStudent(Student_Stoler st)
        {
            Group.Add(st);
        } 
        public void PrintAll()
        {
            if (Group.Count == 0) { Console.WriteLine("Список пустой" + "\n"); };
            foreach (var i in Group)
            {
                i.PrintToConsole();
            }
        }
        public void DeleteStudents()
        {
            Group.Clear();
            Console.WriteLine("Студенты удалены" + "\n");
        }
        static public void SaveStudents(in Group_Stoler Group)
        {
            XmlSerializer xmlsr = new XmlSerializer(typeof(Group_Stoler), new Type[] { typeof(Student_Stoler), typeof(Starosta_Stoler) });
            using (FileStream fs = new FileStream("Group.xml", FileMode.OpenOrCreate))
            {
                xmlsr.Serialize(fs, Group);
            }
            Console.WriteLine("Файл сохранен." + "\n");
        }
        static public Group_Stoler LoadStudents()
        {
            XmlSerializer xmlsr = new XmlSerializer(typeof(Group_Stoler), new Type[] { typeof(Student_Stoler), typeof(Starosta_Stoler) });
            using (FileStream fs = new FileStream("Group.xml", FileMode.Open))
            {
                Console.WriteLine("Студенты успешно загружены" + "\n");
                return (Group_Stoler)xmlsr.Deserialize(fs);
            }
        }
    }
}
