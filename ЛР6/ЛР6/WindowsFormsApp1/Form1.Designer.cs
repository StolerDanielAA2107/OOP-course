namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.файлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.сохранитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.загрузитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.добавитьСтудентаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.добавитьСтудентаToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.добавитьСтаростуToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nameLabel = new System.Windows.Forms.Label();
            this.ageLabel = new System.Windows.Forms.Label();
            this.ratingLabel = new System.Windows.Forms.Label();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.telTextBox = new System.Windows.Forms.TextBox();
            this.ageTextBox = new System.Windows.Forms.TextBox();
            this.ratingTextBox = new System.Windows.Forms.TextBox();
            this.delBtn = new System.Windows.Forms.Button();
            this.groupLabel = new System.Windows.Forms.Label();
            this.groupTextBox = new System.Windows.Forms.TextBox();
            this.telLabel = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 16;
            this.listBox1.Location = new System.Drawing.Point(392, 58);
            this.listBox1.Margin = new System.Windows.Forms.Padding(4);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(375, 340);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.файлToolStripMenuItem,
            this.добавитьСтудентаToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(5, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(780, 28);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // файлToolStripMenuItem
            // 
            this.файлToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.сохранитьToolStripMenuItem,
            this.загрузитьToolStripMenuItem});
            this.файлToolStripMenuItem.Name = "файлToolStripMenuItem";
            this.файлToolStripMenuItem.Size = new System.Drawing.Size(59, 24);
            this.файлToolStripMenuItem.Text = "Файл";
            // 
            // сохранитьToolStripMenuItem
            // 
            this.сохранитьToolStripMenuItem.Name = "сохранитьToolStripMenuItem";
            this.сохранитьToolStripMenuItem.Size = new System.Drawing.Size(166, 26);
            this.сохранитьToolStripMenuItem.Text = "Сохранить";
            this.сохранитьToolStripMenuItem.Click += new System.EventHandler(this.сохранитьToolStripMenuItem_Click);
            // 
            // загрузитьToolStripMenuItem
            // 
            this.загрузитьToolStripMenuItem.Name = "загрузитьToolStripMenuItem";
            this.загрузитьToolStripMenuItem.Size = new System.Drawing.Size(166, 26);
            this.загрузитьToolStripMenuItem.Text = "Загрузить";
            this.загрузитьToolStripMenuItem.Click += new System.EventHandler(this.загрузитьToolStripMenuItem_Click);
            // 
            // добавитьСтудентаToolStripMenuItem
            // 
            this.добавитьСтудентаToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.добавитьСтудентаToolStripMenuItem1,
            this.добавитьСтаростуToolStripMenuItem});
            this.добавитьСтудентаToolStripMenuItem.Name = "добавитьСтудентаToolStripMenuItem";
            this.добавитьСтудентаToolStripMenuItem.Size = new System.Drawing.Size(153, 24);
            this.добавитьСтудентаToolStripMenuItem.Text = "Добавить студента";
            // 
            // добавитьСтудентаToolStripMenuItem1
            // 
            this.добавитьСтудентаToolStripMenuItem1.Name = "добавитьСтудентаToolStripMenuItem1";
            this.добавитьСтудентаToolStripMenuItem1.Size = new System.Drawing.Size(222, 26);
            this.добавитьСтудентаToolStripMenuItem1.Text = "Добавить студента";
            this.добавитьСтудентаToolStripMenuItem1.Click += new System.EventHandler(this.добавитьСтудентаToolStripMenuItem1_Click);
            // 
            // добавитьСтаростуToolStripMenuItem
            // 
            this.добавитьСтаростуToolStripMenuItem.Name = "добавитьСтаростуToolStripMenuItem";
            this.добавитьСтаростуToolStripMenuItem.Size = new System.Drawing.Size(222, 26);
            this.добавитьСтаростуToolStripMenuItem.Text = "Добавить старосту";
            this.добавитьСтаростуToolStripMenuItem.Click += new System.EventHandler(this.добавитьСтаростуToolStripMenuItem_Click);
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(18, 36);
            this.nameLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(33, 16);
            this.nameLabel.TabIndex = 2;
            this.nameLabel.Text = "Имя";
            // 
            // ageLabel
            // 
            this.ageLabel.AutoSize = true;
            this.ageLabel.Location = new System.Drawing.Point(18, 97);
            this.ageLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.ageLabel.Name = "ageLabel";
            this.ageLabel.Size = new System.Drawing.Size(62, 16);
            this.ageLabel.TabIndex = 5;
            this.ageLabel.Text = "Возраст";
            // 
            // ratingLabel
            // 
            this.ratingLabel.AutoSize = true;
            this.ratingLabel.Location = new System.Drawing.Point(18, 283);
            this.ratingLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.ratingLabel.Name = "ratingLabel";
            this.ratingLabel.Size = new System.Drawing.Size(61, 16);
            this.ratingLabel.TabIndex = 6;
            this.ratingLabel.Text = "Рейтинг";
            // 
            // nameTextBox
            // 
            this.nameTextBox.Location = new System.Drawing.Point(18, 58);
            this.nameTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(351, 22);
            this.nameTextBox.TabIndex = 7;
            this.nameTextBox.TextChanged += new System.EventHandler(this.NameTextBox_TextChanged);
            // 
            // telTextBox
            // 
            this.telTextBox.Location = new System.Drawing.Point(18, 244);
            this.telTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.telTextBox.Name = "telTextBox";
            this.telTextBox.Size = new System.Drawing.Size(351, 22);
            this.telTextBox.TabIndex = 8;
            this.telTextBox.TextChanged += new System.EventHandler(this.telTextBox_TextChanged);
            // 
            // ageTextBox
            // 
            this.ageTextBox.Location = new System.Drawing.Point(21, 117);
            this.ageTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.ageTextBox.Name = "ageTextBox";
            this.ageTextBox.Size = new System.Drawing.Size(351, 22);
            this.ageTextBox.TabIndex = 10;
            this.ageTextBox.TextChanged += new System.EventHandler(this.ageTextBox_TextChanged);
            // 
            // ratingTextBox
            // 
            this.ratingTextBox.Location = new System.Drawing.Point(18, 312);
            this.ratingTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.ratingTextBox.Name = "ratingTextBox";
            this.ratingTextBox.Size = new System.Drawing.Size(351, 22);
            this.ratingTextBox.TabIndex = 11;
            this.ratingTextBox.TextChanged += new System.EventHandler(this.RatingTextBox_TextChanged);
            // 
            // delBtn
            // 
            this.delBtn.Location = new System.Drawing.Point(18, 357);
            this.delBtn.Margin = new System.Windows.Forms.Padding(4);
            this.delBtn.Name = "delBtn";
            this.delBtn.Size = new System.Drawing.Size(351, 28);
            this.delBtn.TabIndex = 13;
            this.delBtn.Text = "Удалить";
            this.delBtn.UseVisualStyleBackColor = true;
            this.delBtn.Click += new System.EventHandler(this.delBtn_Click);
            // 
            // groupLabel
            // 
            this.groupLabel.AutoSize = true;
            this.groupLabel.Location = new System.Drawing.Point(18, 152);
            this.groupLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.groupLabel.Name = "groupLabel";
            this.groupLabel.Size = new System.Drawing.Size(54, 16);
            this.groupLabel.TabIndex = 14;
            this.groupLabel.Text = "Группа";
            // 
            // groupTextBox
            // 
            this.groupTextBox.Location = new System.Drawing.Point(18, 175);
            this.groupTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.groupTextBox.Name = "groupTextBox";
            this.groupTextBox.Size = new System.Drawing.Size(351, 22);
            this.groupTextBox.TabIndex = 15;
            this.groupTextBox.TextChanged += new System.EventHandler(this.groupTextBox_TextChanged);
            // 
            // telLabel
            // 
            this.telLabel.AutoSize = true;
            this.telLabel.Location = new System.Drawing.Point(18, 215);
            this.telLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.telLabel.Name = "telLabel";
            this.telLabel.Size = new System.Drawing.Size(67, 16);
            this.telLabel.TabIndex = 3;
            this.telLabel.Text = "Телефон";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(780, 433);
            this.Controls.Add(this.groupTextBox);
            this.Controls.Add(this.groupLabel);
            this.Controls.Add(this.delBtn);
            this.Controls.Add(this.ratingTextBox);
            this.Controls.Add(this.ageTextBox);
            this.Controls.Add(this.telTextBox);
            this.Controls.Add(this.nameTextBox);
            this.Controls.Add(this.ratingLabel);
            this.Controls.Add(this.ageLabel);
            this.Controls.Add(this.telLabel);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem файлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem сохранитьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem загрузитьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem добавитьСтудентаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem добавитьСтудентаToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem добавитьСтаростуToolStripMenuItem;
        public System.Windows.Forms.Label nameLabel;
        public System.Windows.Forms.Label ageLabel;
        public System.Windows.Forms.Label ratingLabel;
        public System.Windows.Forms.TextBox nameTextBox;
        public System.Windows.Forms.TextBox telTextBox;
        public System.Windows.Forms.TextBox ageTextBox;
        public System.Windows.Forms.TextBox ratingTextBox;
        private System.Windows.Forms.Button delBtn;
        public System.Windows.Forms.Label groupLabel;
        public System.Windows.Forms.TextBox groupTextBox;
        public System.Windows.Forms.Label telLabel;
    }
}

