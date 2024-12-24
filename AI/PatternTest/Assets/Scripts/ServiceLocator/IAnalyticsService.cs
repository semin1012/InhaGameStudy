using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.ServiceLocator
{
	public interface IAnalyticsService
	{
		void SendEvent(string eventName);
	}
}