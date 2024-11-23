using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClientEventBus : MonoBehaviour
{
	static public bool _isButtonEnabled;

	private void Start()
	{
		_isButtonEnabled = true;
	}

	private void OnEnable()
	{
		EventBusManager.Subscribe(RaceEventType.STOP, Restart);
	}

	private void OnDisable()
	{
		EventBusManager.Unsubscribe(RaceEventType.STOP, Restart);
	}

	private void Restart()
	{
		_isButtonEnabled = true;
	}

	public static void DisplayButton()
	{
		_isButtonEnabled = false;
		EventBusManager.Publish(RaceEventType.COUNTDOWN);
	}
}
