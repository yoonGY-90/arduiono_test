using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms_helloworld
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text = "안녕하세요. 반갑습니다.";
            label1.BackColor = Color.Azure;
            label1.ForeColor = Color.DarkSalmon;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = "";
        }
    }
}
