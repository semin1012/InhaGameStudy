using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class HUDController : Observer
{
	private bool _isDisplayOn;
	public BikeController _bikeController;
	public CountdownTimer _countdownTimer;
	public InputHandler _inputHandler;

	private bool _isTurboOn;
	private float _currentHealth;
	delegate void SetBikeControllerObserver(Observer go);

	private void Start()
	{
		SetBikeControllerObserver observer = new SetBikeControllerObserver(BikeController.CallBack);
		observer(this);
	}

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

	void OnGUI()
	{
		//if (_isDisplayOn)
		//{
		//	if (GUILayout.Button("Stop Race"))
		//	{
		//		_isDisplayOn = false;
		//		EventBusManager.Publish(RaceEventType.STOP);
		//	}
		//}

		//if (GUILayout.Button("Next Scene"))
		//	SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);

		//if (GUILayout.Button("Start Countdown"))
		//	ClientEventBus.DisplayButton();

		//if (GUILayout.Button("Start Bike"))
		//	_bikeController.StartBike();

		//if (GUILayout.Button("Turn Left"))
		//	_bikeController.Turn(BikeController.Direction.Left);

		//if (GUILayout.Button("Turn Right"))
		//	_bikeController.Turn(BikeController.Direction.Right);

		//if (GUILayout.Button("Stop Bike"))
		//	_bikeController.StopBike();

		//GUI.color = Color.green;
		//GUILayout.Label("BIKE STATUS: " + _bikeController._status);

		//GUI.color = Color.blue;
		//GUILayout.Label("COUNTDOWN: " + _countdownTimer._currentTime);

		//if (GUILayout.Button("Start Recording"))
		//	_inputHandler.StartRecording();

		//if (GUILayout.Button("Stop Recording"))
		//	_inputHandler.StopRecording();

		//if (!_inputHandler._isRecording)
		//{
		//	if (GUILayout.Button("Start Replay"))
		//		_inputHandler.StartReplay();
		//}

		GUILayout.BeginArea(new Rect(50, 200, 100, 200));
		GUILayout.BeginHorizontal("box");
		GUILayout.Label("Health: " + _currentHealth);
		GUILayout.EndHorizontal();
		if (_isTurboOn)
		{
			GUILayout.BeginHorizontal("box");
			GUILayout.Label("Turbo Activated!");
			GUILayout.EndHorizontal();
		}
		if (_currentHealth <= 50.0f)
		{
			GUILayout.BeginHorizontal("box");
			GUILayout.Label("WARNING: Low Health!");
			GUILayout.EndHorizontal();
		}

		GUILayout.EndArea();
	}

	public override void Notify(Subject subject)
	{
		if (!_bikeController)
			_bikeController = subject.GetComponent<BikeController>();	
		if (_bikeController)
		{
			_isTurboOn = _bikeController.IsTurboOn;
			_currentHealth = _bikeController.CurrentHealth;         
		}	
	}
}
