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
using System.Diagnostics;
using System.IO;

namespace Graphical_User_Interface
{
    /// <summary>
    /// Interaction logic for Editor.xaml
    /// </summary>
    public class CurrentGameObject
    {
        public float height,width;
        public float x, y;
        public Color color;
        public string location;
    };


    public class PropetyWindow
    {
        public Rectangle rectangle = new Rectangle { Width = 100, Height = 100, Fill = Brushes.Gray };
        public PropetyWindow(Canvas canvas)
        {
            TextBox name = new TextBox { Width=100,Height=10};
            canvas.Children.Add(rectangle);
            canvas.Children.Add(name);
        }
    }

    public class RectangleObject
    {
        public RectangleObject(Rectangle r, Canvas canvas)
        {
            this.r = r;
            window = new PropetyWindow(canvas);
        }
        public PropetyWindow window;
        public Rectangle r;
    }
    public class ImageObject
    {
        public ImageObject(Image i, Canvas canvas)
        {
            this.i = i;
            window = new PropetyWindow(canvas);
        }
        public PropetyWindow window;
        public Image i;
    }
    public partial class Editor : Window
    {
        CurrentGameObject curGamObj = new CurrentGameObject();
        // List for gameobject prefrence
        List<ImageObject> images = new List<ImageObject>();
        List<RectangleObject> rectangles = new List<RectangleObject>();

        string foldName = "New Project";
        public Editor(string foldName)
        {
            this.foldName = foldName;
            InitializeComponent();
            curGamObj.x = 50;
            curGamObj.y = 50;
            curGamObj.width = 50;
            curGamObj.height = 50;
            curGamObj.location = "NUL";
            curGamObj.color = Color.FromRgb(100, 100, 100);
            GenerateBoilerPlate();
            CompositionTarget.Rendering += tick;
            
        }
        public void GenerateBoilerPlate()
        {
            try
            {
                string text = "" +
                "#include \"Game.h\"\n" +
                "void Game::gameInit(){\n}\n" +
                "void Game::gameLoop(float delta){}";
                File.WriteAllText(foldName + "\\Script.cpp", text);
                codeArea.Text = text;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
        }
        void execute()
        {
            var r = File.ReadAllLines(foldName + "\\Script.cpp");
            File.WriteAllText(r[0], "");
        }

        private void tick(object sender, EventArgs e)
        {
            foreach(var rect in rectangles){
                
            }
        }

        private void save_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                File.WriteAllText(foldName + "\\Script.cpp", codeArea.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void close_Click(object sender, RoutedEventArgs e)
        {
            MessageBoxResult result = MessageBox.Show("Do you want to close this window?",
            "Confirmation", MessageBoxButton.YesNo);
            switch (result)
            {
                case MessageBoxResult.Yes:
                    this.Close();
                    break;
                case MessageBoxResult.No:
                    return;
            }
            
        }
        Random r = new Random();
        private void rect_Click(object sender, RoutedEventArgs e)
        {
            Rectangle newRectangle = new Rectangle
            {
                Width = curGamObj.width,
                Height = curGamObj.height,
                Fill = Brushes.Black
            };

            Canvas.SetLeft(newRectangle, curGamObj.x);
            Canvas.SetTop(newRectangle, curGamObj.y);

            canvas.Children.Add(newRectangle);
            curGamObj.x += 100;
            rectangles.Add(new RectangleObject(newRectangle,canvas));


        }

        private void codeArea_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.F11)
            {
                codeArea.FontSize++;
            }
        }

        private void Run_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Debug_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
