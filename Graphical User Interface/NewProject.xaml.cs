using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.IO;
namespace Graphical_User_Interface
{
    /// <summary>
    /// Interaction logic for NewProject.xaml
    /// </summary>
    
    public partial class NewProject : Window
    {
        
        public NewProject()
        {
            InitializeComponent();
        }
        string projectName = "New Project";
        private void createBtn_Click(object sender, RoutedEventArgs e)
        {
            projectName = prName_inp.Text;
            string folderName = "C:\\Users\\mauri\\source\\repos\\HugosEngine2D\\PROJECTS\\" + projectName;
            try {
                if (!Directory.Exists(folderName))
                {
                    Directory.CreateDirectory(folderName);
                    File.Create(folderName + "\\Config.cfg");         // Configuration file
                    File.Create(folderName + "\\GameObjects.gmo");         // Gameobjects file
                    File.Create(folderName + "\\Scene.scene");         // Gameobjects file
                    Directory.CreateDirectory(folderName + "\\Shaders");
                    string shader = folderName + "\\Shaders";
                    File.Create(shader + "\\Fragment.frag");
                    File.Create(shader + "\\Vertex.vert");
                    //File.Create(folderName + "\\Script.cpp");

                }
            } catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            Editor editor = new Editor(folderName);
            editor.Show();
            this.Close();
        }
    }
}
