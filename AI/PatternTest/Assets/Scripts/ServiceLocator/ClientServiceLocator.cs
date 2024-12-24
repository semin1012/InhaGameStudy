using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;


namespace Chapter.ServiceLocator
{
	public class ClientServiceLocator : MonoBehaviour
	{
		void Start()
		{
			RegisterService();
		}

		private void RegisterService()
		{
			ILoggerService logger = new Logger();
			ServiceLocator.RegisterService(logger);

			IAnalyticsService analytics = new Analytics();
			ServiceLocator.RegisterService(analytics);

			IAdvertisement advertisement = new Advertisement();
			ServiceLocator.RegisterService(advertisement);
		}

		private void OnGUI()
		{
			GUILayout.Label("Review output in the console: ");

			if (GUILayout.Button("Log Event"))
			{
				ILoggerService logger = ServiceLocator.GetService<ILoggerService>();
				logger.Log("Hello World!");
			}

			if (GUILayout.Button("Send Analytics"))
			{
				IAnalyticsService analytics = ServiceLocator.GetService<IAnalyticsService>();
				analytics.SendEvent("Hello World!");
			}

			if (GUILayout.Button("Display Advertisement"))
			{
				IAdvertisement advertisement = ServiceLocator.GetService<Advertisement>();
				advertisement.DisplayAd();
			}
		}
	}
	
}