using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class Starosta_Stoler: Student_Stoler
    {
        public int rating { get; set; }
        public long Phone_number { get; set; }
        public override void updateForm(Form1 form)
        {
            base.updateForm(form);
            form.ratingLabel.Visible = true;
            form.ratingTextBox.Visible = true;
            form.ratingTextBox.Text = Convert.ToString(rating);

            form.telLabel.Visible = true;
            form.telTextBox.Visible = true;
            form.telTextBox.Text = Convert.ToString(Phone_number);
        }

        public override void saveData(Form1 form)
        {
            base.saveData(form);
            if (form.ratingTextBox.Text != "")
                rating = Convert.ToInt32(form.ratingTextBox.Text);
            if (form.telTextBox.Text != "")
                Phone_number = Convert.ToInt32(form.telTextBox.Text);
        }

        public override string getMainData()
        {
            return String.Format("{0} - Староста", base.getMainData());
        }
    }
}
