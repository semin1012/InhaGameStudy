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

	public bool bGameOver = false;
	public int score = 0;

	private void OnGUI()
	{
		GUI.TextArea(new Rect(100, 50, 100, 30), "Test Text1");
		GUI.TextArea(new Rect(100, 80, 100, 30), "Test Text2");
		GUI.Box(new Rect(100, 110, 100, 30), "Test Text3");

		if (bGameOver)
		{
			if (GUI.Button(new Rect(100, 240, 200, 30), "Ω√¿€"))
			{
				bGameOver = false;
				SceneManager.LoadScene("GameScene");
			}
		}
	}
}
