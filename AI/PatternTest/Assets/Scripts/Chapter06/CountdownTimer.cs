using Chapter.Singleton;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CountdownTimer : MonoBehaviour
{
	public float _currentTime;
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
		while (_currentTime > 0)
		{
			yield return new WaitForSeconds(1f);
			_currentTime--;
		}
		EventBusManager.Publish(RaceEventType.START);
	}
}
