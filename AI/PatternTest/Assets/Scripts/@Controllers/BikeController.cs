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
	private HUDController _hudController;
	private CameraController _cameraController;

    [SerializeField] 
	private float health = 100.0f;

	private void Awake()
	{
		_hudController = gameObject.AddComponent<HUDController>();
		_cameraController = (CameraController)FindObjectOfType(typeof(CameraController));

	}

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
    }


	public void TakeDamage(float amount)
	{
		health -= amount;
		IsTurboOn = false;

		Notify();

		if (health < 0)
			Destroy(gameObject);
	}

	private void StartEngine()
	{
		_isEngineOn = true;
		Notify();
	}

	public void ToggleTurbo()
	{
		if (_isEngineOn)
			_isTurboOn = !_isTurboOn;
		Notify();
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
		if (_hudController)
			Attach(_hudController);
		if (_cameraController)
			Attach(_cameraController);
	}

	private void OnDisable()
	{
		EventBusManager.Unsubscribe(RaceEventType.START, StartBike);
		EventBusManager.Unsubscribe(RaceEventType.STOP, StopBike);
		if (_hudController)
			Detach(_hudController);
		if (_cameraController)
			Detach(_cameraController);
	}
}