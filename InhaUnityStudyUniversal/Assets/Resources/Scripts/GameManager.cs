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
		//SceneManager.LoadScene("GameScene");
	}

	public void GameStart()
	{
		bGameOver = false;
		SceneManager.LoadScene("BirdGameScene");
	}

	public void Restart()
	{
		SceneManager.LoadScene("TitleScene");
		score = 0;
	}

	public bool bGameOver = false;
	public int score = 0;

	private void OnGUI()
	{

	}
}
