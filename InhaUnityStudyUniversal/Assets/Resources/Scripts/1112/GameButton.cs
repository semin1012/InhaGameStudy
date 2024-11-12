using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameButton : MonoBehaviour
{
	public void GameStart()
	{
		GameManager.Instance.GameStart();
	}

	public void Restart()
	{
		GameManager.Instance.Restart();
	}
}
