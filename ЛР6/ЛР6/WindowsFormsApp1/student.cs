using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WindowsFormsApp1
{
    [XmlInclude(typeof(Starosta_Stoler))]
    public class Student_Stoler
    {
        public string name, group;
        public int age, id;

        public virtual void updateForm(Form1 form)
        {
            form.nameTextBox.Text = name;
            form.groupTextBox.Text = group;
            form.ageTextBox.Text = Convert.ToString(age);

            form.nameLabel.Visible = true;
            form.nameTextBox.Visible = true;

            form.ageLabel.Visible = true;
            form.ageTextBox.Visible = true;

            form.groupLabel.Visible = true;
            form.groupTextBox.Visible = true;

            form.telLabel.Visible = false;
            form.telTextBox.Visible = false;
            
            form.ratingLabel.Visible = false;
            form.ratingTextBox.Visible = false;
        }

        public virtual void saveData(Form1 form)
        {
            name = form.nameTextBox.Text;
            group = form.groupTextBox.Text;
            if (form.ageTextBox.Text != "")
                age = Convert.ToInt32(form.ageTextBox.Text);
        }

        public virtual string getMainData()
        {
            return String.Format("{0} {1} {2}", name, age, group);
        }
    }
}
