   M S B A M L   `   `   `  ����D  @MatchGame, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:MatchGame	MatchGame  5   	       MatchGame.MainWindow   5   	   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   )localclr-namespace:MatchGame     5   	     � Title$&   Find all of the matching animals��5   	   $	��450��62   $	��400��6?   
���   �.��5	      � -   5         �Name$ mainGrid��5	      
������� J� 	AllowDrop$
 True��60   $
|�True��6A    � ColumnDefinitions 5
   
   �� 5      �� 5      �� 5      �� 5       � RowDefinitions 5   
   �� 5      �� 5      �� 5      �� 5      �� 5      �� 5      .+�5   
   �� -   5        $��36(�5      $��Center=�6"   $��Center=�6?   $
��Wrap=�6Z   $��?��6n   6w   �� 5   
   -   5        $��1��5      $��36(�6$   $��Center=�62   $��Center=�6O   $
��Wrap=�6j   $��?��6~   
�������6�   �� 5   
   -   5        $��2��5      $��36(�6$   $��Center=�62   $��Center=�6O   $
��Wrap=�6j   $��?��6~   
�������6�   �� 5   
   -   5        $��3��5      $��36(�6$   $��Center=�62   $��Center=�6O   $
��Wrap=�6j   $��?��6~   
�������6�   �� 5   
   -   5        $��1��5      $��36(�6!   $��Center=�6/   $��Center=�6L   $
��Wrap=�6g   $��?��6{   
�������6�   �� 5   
   -   5        $��1��5      $��1��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5   
   -   5        $��2��5      $��1��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5   
   -	   5        $��3��5      $��1��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5    
   -
   5        $��2��5       $��36(�6!   $��Center=�6/   $��Center=�6L   $
��Wrap=�6g   $��?��6{   
�������6�   �� 5!   
   -   5        $��1��5!      $��2��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5"   
   -   5        $��2��5"      $��2��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5#   
   -   5        $��3��5#      $��2��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5$   
   -   5        $��3��5$      $��36(�6!   $��Center=�6/   $��Center=�6L   $
��Wrap=�6g   $��?��6{   
�������6�   �� 5%   
   -   5        $��1��5%      $��3��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5&   
   -   5        $��2��5&      $��3��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5'   
   -   5        $��3��5'      $��3��6$   $��36(�61   $��Center=�6?   $��Center=�6\   $
��Wrap=�6w   $��?��6�   
�������6�   �� 5(   
   -   5         ��Name$ TimeTextBlock��5(      $��Center=�6+   $��4��6H   $
��Wrap=�6U   $��Elapsed time��6i   $��Center=�6}   $��4��6�   $��36(�6�   
�������6�   �� 5)   
   -   5        $ BestTimeTextBlock��5)      $��Center=�6/   $��5��6L   $
��Wrap=�6Y   $��최고 기록��6m   $��Center=�6z   $��4��6�   $��20(�6�   
�������6�   �� 5*   
   -   5         ��Name$ startButton��5*      $��게임 시작��6&   $
��Left=�66   $��2��6Q   $	��Top=�6^   $��3��6v   $	��200��6�   $��50��6�   $��1��6�    �� 	IsDefault$
 True��6�    J� IsManipulationEnabled$
 True��6�   6�   5,      5-      