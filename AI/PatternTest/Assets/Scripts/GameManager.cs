using System;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace Chapter.Singleton
{
	public class GameManager : Singleton<GameManager>
	{
		private DateTime _sessionStartTime;
		private DateTime _sessionEndTime;

		void Start()
		{
			// TODO:
			// - 플레이어 세이브 로드
			// - 세이브가 없으면 플레이어를 등록 씬으로 리다이렉션한다.
			// - 백엔드를 호출하고 일일 챌린지와 보상을 얻는다. 

			_sessionStartTime = DateTime.Now;
			Debug.Log("Game session start @: " + DateTime.Now);
		}
		void OnApplicationQuit()
		{
			_sessionEndTime = DateTime.Now;
			TimeSpan timeDifference = _sessionEndTime.Subtract(_sessionStartTime);
			Debug.Log("Game session ended @: " + DateTime.Now);
			Debug.Log("Game session lasted: " + timeDifference);
		}
	}
}

