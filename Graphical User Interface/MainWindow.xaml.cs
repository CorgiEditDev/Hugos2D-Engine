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

        public MainWindow()
        {
            InitializeComponent();
            refresh();
        }
        private void OpenFileButton_Click(object sender, RoutedEventArgs e)
        {
            
            Process.Start(@"c:\");
        }
        private void refresh()
        {
            int childrenCount = Projects.Children.Count;
            TextBlock noProj = new TextBlock
            {
                Text = "        No projects",
                Foreground = Brushes.WhiteSmoke
            };
            Projects.Children.Insert(childrenCount, noProj);

        }
    }
}
