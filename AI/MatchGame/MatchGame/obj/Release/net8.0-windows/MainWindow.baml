   M S B A M L   `   `   `  ���� D  @MatchGame, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:MatchGame	MatchGame      MatchGame.MainWindow   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     )localclr-namespace:MatchGame       � Title$&   Find all of the matching animals��$	��450��$	��400��
���   �.��� -    �Name$ mainGrid��
������� J� 	AllowDrop$
 True��$
|�True�� � ColumnDefinitions �� �� �� ��  � RowDefinitions �� �� �� �� �� �� .+��� -   $��36(�$��Center=�$��Center=�$
��Wrap=�$��?���� -   $��1��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��2��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��3��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��1��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��1��$��1��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��2��$��1��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -	   $��3��$��1��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -
   $��2��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��1��$��2��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��2��$��2��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��3��$��2��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��3��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��1��$��3��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��2��$��3��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -   $��3��$��3��$��36(�$��Center=�$��Center=�$
��Wrap=�$��?��
��������� -    ��Name$ TimeTextBlock��$��Center=�$��4��$
��Wrap=�$��Elapsed time��$��Center=�$��4��$��36(�
��������� -    ��Name$ startButton��$��게임 시작��$
��Left=�$��2��$	��Top=�$��3��$	��200��$��50��$��1�� �� 	IsDefault$
 True�� J� IsManipulationEnabled$
 True���� -   $ BestTimeTextBlock��$
��Left=�$��5��$
��Wrap=�$��현재 점수: ��$��Bottom=�$��4��$��17(�
�������$	��170���� -   $ CurrentScoreBlock��$��Right=�$��5��$
��Wrap=�$��최고 점수: ��$��Bottom=�$��4��$��17(�
�������$	��170��