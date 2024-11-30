using System.Collections;
using System.Collections.Generic;
using UnityEditor.Experimental.GraphView;
using UnityEngine;

public class BikeController : Subject
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

	public bool IsTurboOn
	{
		get { return _isTurboOn; }
		private set { }
	}

	public float CurrentHealth
	{
		get { return health; }
	}

	private bool _isEngineOn;
    public delegate void DelegateClass<T>(Subject go);
    static public event DelegateClass<Subject> AddObserver;
	static public event DelegateClass<Subject> RemoveObserver;

    [SerializeField] 
	private float health = 100.0f;

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

		StartEngine();
        AddObserver(this);
    }


	public void TakeDamage(float amount)
	{
		health -= amount;
		IsTurboOn = false;

		NotifyObservers();

		if (health < 0)
			Destroy(gameObject);
	}

	private void StartEngine()
	{
		_isEngineOn = true;
		NotifyObservers();
	}

	public void ToggleTurbo()
	{
		if (_isEngineOn)
			_isTurboOn = !_isTurboOn;
		NotifyObservers();
		Debug.Log("Turbo Active: " + _isTurboOn.ToString());
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
		AddObserver(this);
	}

	private void OnDisable()
	{
		EventBusManager.Unsubscribe(RaceEventType.START, StartBike);
		EventBusManager.Unsubscribe(RaceEventType.STOP, StopBike);
		RemoveObserver(this);
	}
}