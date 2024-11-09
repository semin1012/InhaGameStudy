using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.EventBus
{
	public class ClientEventBus : MonoBehaviour
	{
		private bool _isButtonEnabled;

		private void Start()
		{
			gameObject.AddComponent<HUDController>();
			gameObject.AddComponent<CountdownTimer>();
			gameObject.AddComponent<BikeController>();

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

		private void OnGUI()
		{
			if (_isButtonEnabled)
			{
				if (GUILayout.Button("Start Countdown"))
				{
					_isButtonEnabled = false;
					EventBusManager.Publish(RaceEventType.COUNTDOWN);
				}
			}
		}
	}
}

