using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
	private static GameManager sInstance;
	public static GameManager Instance
	{
		get
		{
			if ( sInstance == null)
			{
				GameObject newGameManager = new GameObject("_GameManager");
				sInstance = newGameManager.AddComponent<GameManager>();
			}
			return sInstance;
		}
	}

	private void Awake()
	{
		if (sInstance != null && sInstance != this)
		{
			Destroy(gameObject);
			return;
		}
		sInstance = this;
		DontDestroyOnLoad(gameObject);
	}

	public void GameOver()
	{
		bGameOver = true;
		if (bestScore < score)
			bestScore = score;
	}

	public void GameStart()
	{
		score = 0;
		bGameOver = false;
		SceneManager.LoadScene("CarrotFlight");
	}

	public void Restart()
	{
		SceneManager.LoadScene("Title_CarrotFlight");
	}

	public bool bGameOver = false;
	public int score = 0;
	public int bestScore = 0;

	private void OnGUI()
	{

	}
}
