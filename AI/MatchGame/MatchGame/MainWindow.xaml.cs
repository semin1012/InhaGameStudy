using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace MatchGame
{
	using System.Windows.Threading;

	public partial class MainWindow : Window
	{
		DispatcherTimer timer = new DispatcherTimer();
		float gameTime = 8.0f;
		int tenthsOfSecondsElapsed;
		int matchesFound;
		bool bGameStart = false;
		int bestScore;
		int currentScore;

		TextBlock lastTextBlockClicked;
		bool findingMatch = false;

		public MainWindow()
		{
			InitializeComponent();

			timer.Interval = TimeSpan.FromSeconds(.1);
			timer.Tick += Timer_Tick;
			SetUpGame();
		}

		private void Timer_Tick(object? sender, EventArgs e)
		{
			if ( bGameStart)
			{
				tenthsOfSecondsElapsed++;
				TimeTextBlock.Text = (tenthsOfSecondsElapsed / 10F).ToString("0.0s");

				CurrentScoreBlock.Text = "현재 점수: " + currentScore;
				BestTimeTextBlock.Text = "최고 기록: " + bestScore;

				if ( tenthsOfSecondsElapsed / 10F >= gameTime)
				{
					StopGame();
				}

				if (matchesFound == 8)
				{
					timer.Stop();
					TimeTextBlock.Text = TimeTextBlock.Text + " - play agian?";
				}
			}
		}
		private void click_Click(object sender, RoutedEventArgs e)
		{
			SetUpGame();
			bGameStart = true;
			startButton.Visibility = Visibility.Hidden;
		}

		private void SetUpGame()
		{
			List<string> animalEmogi = new List<string>()
			{
				"👻", "👻",
				"🐣", "🐣",
				"🐾", "🐾",
				"✨", "✨",
				"🌸", "🌸",
				"🍑", "🍑",
				"🌼", "🌼",
				"🌈", "🌈"
			};

			Random random = new Random();
			foreach(TextBlock textBlock in mainGrid.Children.OfType<TextBlock>())
			{
				if (textBlock.Name != "TimeTextBlock" && textBlock.Name != "BestTimeTextBlock" && textBlock.Name != "CurrentScoreBlock")
				{
					textBlock.Visibility = Visibility.Visible;
					int index = random.Next(animalEmogi.Count);
					string nextemogi = animalEmogi[index];
					textBlock.Text = nextemogi;	
					animalEmogi.RemoveAt(index);
				}
			}

			timer.Start();
			tenthsOfSecondsElapsed = 0;
			matchesFound = 0;
			TimeTextBlock.Text = "0.0s";
			CurrentScoreBlock.Text = "현재 점수: " + currentScore;
			BestTimeTextBlock.Text = "최고 기록: " + bestScore;

		}

		private void TextBlock_MouseDown(object sender, MouseButtonEventArgs e)
		{
			if (bGameStart == false)
				return;

			TextBlock textBlock = sender as TextBlock;
			if (findingMatch == false)
			{
				textBlock.Visibility = Visibility.Hidden;
				lastTextBlockClicked = textBlock;
				findingMatch = true;
			}
			else if (textBlock.Text == lastTextBlockClicked.Text)
			{
				currentScore += 10;
				matchesFound++;
				textBlock.Visibility = Visibility.Hidden;
				findingMatch = false;
			}
			else
			{
				lastTextBlockClicked.Visibility = Visibility.Visible;
				findingMatch = false;
			}

			if ( currentScore >= 8 * 10 )
			{
				if ( currentScore > bestScore )
				{
					bestScore = currentScore;
				}
				StopGame();
			}
		}

		private void StopGame()
		{
			timer.Stop();
			bGameStart = false;
			startButton.Visibility = Visibility.Visible;
			startButton.Content = "다시 시작";
			BestTimeTextBlock.Text = "최고 기록: " + bestScore;
			CurrentScoreBlock.Text = "현재 점수: " + currentScore;
			currentScore = 0;
		}

		private void TimeTextBlock_MouseDown(object sender, MouseButtonEventArgs e)
		{
			if (matchesFound == 8)
			{
				SetUpGame();
			}
		}
	}
}