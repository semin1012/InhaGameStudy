using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class GameManager : MonoBehaviour
{
	private static GameManager sInstance;

	//생성 막기
	public static GameManager Instance
	{
		get
		{
			if (sInstance == null)
			{
				GameObject newGameObject = new GameObject("_GameManager");
				sInstance = newGameObject.AddComponent<GameManager>();
			}
			return sInstance;
		}
	}

	//new 생성막기
	private void Awake()
	{
		if (sInstance != null && sInstance != this)
		{
			Destroy(this.gameObject);
			return;
		}
		sInstance = this;

		DontDestroyOnLoad(this.gameObject);
	}


	public bool bGameOver = false;
	public int score = 0;
	public int bestScore = 0;

	public void Restart()
	{

	}

	public void GameStart()
	{

	}

	public void GameOver()
	{

	}

	//private void OnGUI()
	//{
	//    //GUI.TextArea(new Rect(100, 50, 100, 30), "Test Text1");
	//    //GUI.TextField(new Rect(100, 80, 100, 30), "Test Text2");
	//    //GUI.Box(new Rect(100, 110, 100, 30), "Test Text3");
	//    GUI.TextArea(new Rect(100, 50, 100, 30), "Score : " + GameManger.Instance.score);


	//    if (bGameOver)
	//    {
	//        if (GUI.Button(new Rect(100, 240, 200, 30), "시작"))
	//        {
	//            bGameOver = false;
	//            SceneManager.LoadScene(("Test"));
	//        }
	//    }
	//}



}
