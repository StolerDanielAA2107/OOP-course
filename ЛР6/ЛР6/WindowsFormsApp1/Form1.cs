using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        int index;
        public List<Student_Stoler> allStudents = new List<Student_Stoler>();
        bool state = false;
        bool block = true;
        public Form1()
        {
            InitializeComponent();
            index = listBox1.SelectedIndex;
            if (index <= 0)
            {
                telTextBox.Visible = false;
                telLabel.Visible = false;
                nameLabel.Visible = false;
                nameTextBox.Visible = false;
                groupLabel.Visible = false;
                groupTextBox.Visible = false;
                ageLabel.Visible = false;
                ageTextBox.Visible = false;
                ratingLabel.Visible = false;
                ratingTextBox.Visible = false;
            }

        }
        public void listBoxRewrite()
        {
            listBox1.Items.Clear();
            foreach (var student in allStudents)
            {
                listBox1.Items.Add(student.getMainData());
            }
        }

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void load(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void save(StringBuilder path);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void clear();

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void addStudent();

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void addCaptain();

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int getSize();

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int getType(int n);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void getName(int n, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void setName(int n, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]

        private static extern void getGroup(int n, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void setGroup(int n, StringBuilder str);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int getAge(int n);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int setAge(int n, int age);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int getRating(int n);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int setRating(int n, int bonus);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int getPhone(int n);

        [DllImport("MFCLibrary1.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int setPhone(int n, long bonus);

        private void загрузитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog
            {
                Filter = "All files (*.*)|*.*",
                FilterIndex = 2,
                RestoreDirectory = true
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(fileDialog.FileName);
                load(fileName);
                allStudents.Clear();
                for (int i = 0; i < getSize(); i++)
                {
                    if (getType(i) == 0)
                    {
                        Student_Stoler student = new Student_Stoler();
                        var buffer = new StringBuilder(256);

                        getName(i, buffer);
                        student.name = buffer.ToString();

                        getGroup(i, buffer);
                        student.group = buffer.ToString();

                        student.age = getAge(i);

                        allStudents.Add(student);
                    }
                    else
                    {
                        Starosta_Stoler student = new Starosta_Stoler();
                        var buffer = new StringBuilder(256);

                        getName(i, buffer);
                        student.name = buffer.ToString();

                        getGroup(i, buffer);
                        student.group = buffer.ToString();

                        student.age = getAge(i);

                        student.rating = getRating(i);
                        student.Phone_number = getPhone(i);
                        allStudents.Add(student);
                    }
                }
                listBoxRewrite();
            }
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog fileDialog = new SaveFileDialog
            {
                Filter = "All files (*.*)|*.*",
                FilterIndex = 2,
                RestoreDirectory = true
            };

            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                clear();
                for (int i = 0; i < allStudents.Count; i++)
                {
                    var buffer = new StringBuilder();
                    if (allStudents[i].GetType() == typeof(Student_Stoler))
                    {
                        addStudent();
                        buffer.Clear();
                        buffer.Append(allStudents[i].name);
                        setName(i, buffer);
                        buffer.Clear();
                        buffer.Append(allStudents[i].group);
                        setGroup(i, buffer);
                        setAge(i, allStudents[i].age);
                    }
                    else
                    {
                        addCaptain();
                        buffer.Clear();
                        buffer.Append(allStudents[i].name);
                        setName(i, buffer);
                        buffer.Clear();
                        buffer.Append(allStudents[i].group);
                        setGroup(i, buffer);
                        setAge(i, allStudents[i].age);
                        setPhone(i, ((Starosta_Stoler)allStudents[i]).Phone_number);
                        setRating(i, ((Starosta_Stoler)allStudents[i]).rating);
                    }
                }
                save(new StringBuilder(fileDialog.FileName));
            }
        }

        private void добавитьСтудентаToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            listBox1.ClearSelected();
            Student_Stoler student = new Student_Stoler();
            allStudents.Add(student);
            listBox1.Items.Add(student.getMainData());
            clearControls();
            listBox1.SetSelected(listBox1.Items.Count - 1, true);
        }

        private void добавитьСтаростуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listBox1.ClearSelected();
            Starosta_Stoler student = new Starosta_Stoler();
            allStudents.Add(student);
            listBox1.Items.Add(student.getMainData());
            clearControls();
            listBox1.SetSelected(listBox1.Items.Count - 1, true);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex >= 0)
            {
                if (state == false)
                {
                    var student = allStudents[listBox1.SelectedIndex];
                    block = true;
                    student.updateForm(this);
                    block = false;
                }
            } else {
                clearControls();
                telTextBox.Visible = false;
                telLabel.Visible = false;
                nameLabel.Visible = false;
                nameTextBox.Visible = false;
                groupLabel.Visible = false;
                groupTextBox.Visible = false;
                ageLabel.Visible = false;
                ageTextBox.Visible = false;
                ratingLabel.Visible = false;
                ratingTextBox.Visible = false;

            }
        }

        private void clearControls()
        {
            nameTextBox.Text = "";
            telTextBox.Text = "";
            groupTextBox.Text = "";
            ageTextBox.Text = "";
            ratingTextBox.Text = "";
        }


        private void onChangeFormTextBox()
        {
            if (listBox1.SelectedIndex >= 0 && !block)
            {
                state = true;
                index = listBox1.SelectedIndex;
                var student = allStudents[index];
                student.saveData(this);
                listBoxRewrite();
                listBox1.SetSelected(index, true);
                state = false;
            }
        }

        private void NameTextBox_TextChanged(object sender, EventArgs e)
        {
            onChangeFormTextBox();
        }

        private void telTextBox_TextChanged(object sender, EventArgs e)
        {
            onChangeFormTextBox();
        }

        private void ageTextBox_TextChanged(object sender, EventArgs e)
        {
            onChangeFormTextBox();
        }

        private void groupTextBox_TextChanged(object sender, EventArgs e)
        {
            onChangeFormTextBox();
        }

        private void RatingTextBox_TextChanged(object sender, EventArgs e)
        {
            onChangeFormTextBox();
        }

        private void delBtn_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count >= 1) 
            {
                index = listBox1.SelectedIndex;
                listBox1.Items.RemoveAt(index);
                if (index < listBox1.Items.Count)
                {
                    allStudents.RemoveAt(index);
                    listBox1.SelectedIndex = index;
                }
                else
                {
                    allStudents.RemoveAt(index);
                    listBox1.SelectedIndex = index - 1;
                }
            }
          
        }

    }
}
