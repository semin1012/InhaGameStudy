using Chapter.Singleton;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class EventBusManager : Singleton<EventBusManager>
{
	private static readonly IDictionary<RaceEventType, UnityEvent> Events = new Dictionary<RaceEventType, UnityEvent>();

	public static void Subscribe(RaceEventType eventType, UnityAction listener)
	{
		UnityEvent thisEvent;

		if (Events.TryGetValue(eventType, out thisEvent))
			thisEvent.AddListener(listener);
		else
		{
			thisEvent = new UnityEvent();
			thisEvent.AddListener(listener);
			Events.Add(eventType, thisEvent);
		}
	}

	public static void Unsubscribe(RaceEventType type, UnityAction listener)
	{
		UnityEvent thisEvent;
		if (Events.TryGetValue(type, out thisEvent))
			thisEvent.RemoveListener(listener);
	}

	public static void Publish(RaceEventType type)
	{
		UnityEvent thisEvent;
		if (Events.TryGetValue(type, out thisEvent))
			thisEvent.Invoke();
	}
}