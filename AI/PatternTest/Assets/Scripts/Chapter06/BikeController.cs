using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using UnityEngine;

namespace Chapter.EventBus
{
	public class BikeController : MonoBehaviour
	{
		private string _status;

		private void OnEnable()
		{
			EventBusManager.Subscribe(RaceEventType.START, StartBike);
			EventBusManager.Subscribe(RaceEventType.STOP, StopBike); 
		}

		private void OnDisable()
		{
			EventBusManager.Unsubscribe(RaceEventType.START, StartBike);
			EventBusManager.Unsubscribe(RaceEventType.STOP, StopBike);			
		}

		private void StartBike()
		{
			_status = "Started";
		}

		private void StopBike()
		{
			_status = "Stopped";
		}

		private void OnGUI()
		{
			GUI.color = Color.green;
			GUI.Label(new Rect(10, 50, 200, 20), "BIKE STATUS: " + _status);
		}
	}
}
