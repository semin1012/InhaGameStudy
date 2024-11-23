using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BikeController : MonoBehaviour
{
	public float maxSpeed = 2.0f;
	public float turnDistance = 2.0f;
	private float _distance = 1.0f;
	public string _status;
	private bool _isTurboOn;

	public float CurrentSpeed { get; set; }
	public enum Direction
	{
		Left = -1,
		Right = 1
	}
	public Direction CurrentTurnDirection
	{
		get; private set;
	}

	private IBikeState
		_startState, _stopState, _turnState;

	private BikeStateContext _bikeStateContext;
	private void Start()
	{
		_bikeStateContext =
			new BikeStateContext(this);

		_startState =
			gameObject.AddComponent<BikeStartState>();
		_stopState =
			gameObject.AddComponent<BikeStopState>();
		_turnState =
			gameObject.AddComponent<BikeTurnState>();

		_bikeStateContext.Transition(_stopState);
	}

	public void StartBike()
	{
		_status = "Started";
		_bikeStateContext.Transition(_startState);
	}

	public void StopBike()
	{
		_status = "Stopped";
		_bikeStateContext.Transition(_stopState);
	}

	public void Turn(Direction direction)
	{
		CurrentTurnDirection = direction;
		_bikeStateContext.Transition(_turnState);

		if (direction == Direction.Left) transform.Translate(Vector3.left * _distance);
		if (direction == Direction.Right) transform.Translate(Vector3.right * _distance);
	}

	public void ResetPosition()
	{
		transform.position = new Vector3(0.0f, 0.0f, 0.0f);
	}

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

	public void ToggleTurbo()
	{
		_isTurboOn = !_isTurboOn;
		Debug.Log("Turbo Active: " + _isTurboOn.ToString());
	}
}