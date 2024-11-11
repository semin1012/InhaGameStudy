using Chapter.Singleton;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.EventBus
{
	public class CountdownTimer : MonoBehaviour
	{
		private float _currentTime;
		private float duration = 3.0f;

		private void OnEnable()
		{
			EventBusManager.Subscribe(RaceEventType.COUNTDOWN, StartTimer);
		}

		private void OnDisable()
		{
			EventBusManager.Unsubscribe(RaceEventType.COUNTDOWN, StartTimer);
		}

		private void StartTimer()
		{
			StartCoroutine(Countdown());
		}

		private IEnumerator Countdown()
		{
			_currentTime = duration;
			while ( _currentTime > 0 )
			{
				yield return new WaitForSeconds(1f);
				_currentTime--;
			}
			EventBusManager.Publish(RaceEventType.START);
		}

		private void OnGUI()
		{
			GUI.color = Color.blue;
			GUI.Label(new Rect(225, 0, 100, 20), "COUNTDOWN: " + _currentTime);
		}
	}
}
