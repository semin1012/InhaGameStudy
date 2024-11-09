using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.EventBus
{
	public class HUDController : MonoBehaviour
	{
		private bool _isDisplayOn;

		private void OnEnable()
		{
			EventBusManager.Subscribe(RaceEventType.START, DisplayHUD);
		}

		private void OnDisable()
		{
			EventBusManager.Unsubscribe(RaceEventType.START, DisplayHUD);
		}

		void DisplayHUD()
		{
			_isDisplayOn = true;
		}

		private void OnGUI()
		{
            if (_isDisplayOn)
            {
                if(GUILayout.Button("Stop Race"))
				{
					_isDisplayOn = false;
					EventBusManager.Publish(RaceEventType.STOP);
				}
            }
        }
	}

}
