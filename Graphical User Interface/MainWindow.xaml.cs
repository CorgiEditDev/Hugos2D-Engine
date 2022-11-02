using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;


namespace Graphical_User_Interface
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Image newProject = new Image
        {
            Source = new BitmapImage(new Uri("C:\\Users\\mauri\\source\\repos\\HugosEngine2D\\Graphical User Interface\\Assets\\Source Han Sans JP Normal.png")),
            Width = 200,
            Height = 200,
            Margin = new Thickness(-200, 0, 0, 0),
        };
        public MainWindow()
        {
            InitializeComponent();
            Refresh();
            CompositionTarget.Rendering += tick;
        }
        private void OpenFileButton_Click(object sender, RoutedEventArgs e)
        {
            Process.Start(@"c:\");
        }
        private bool launched = false;
        
        private void tick(object sender, EventArgs e)
        {
            if (newProject.IsMouseOver && launched == false)
            {
                launched = true;
                NewProject window = new NewProject();
                window.Activate();
                window.Show();
            }
        }
        private void Refresh()
        {
            int childrenCount = Projects.Children.Count;
            TextBlock noProj = new TextBlock
            {
                Text = "        No projects",
                Foreground = Brushes.WhiteSmoke
            };

            
            // Projects.Children.Insert(childrenCount, noProj);
            Projects.Children.Insert(childrenCount, newProject);
            
        }
    }
}
