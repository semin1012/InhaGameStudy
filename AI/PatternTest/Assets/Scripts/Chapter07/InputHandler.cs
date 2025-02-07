using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class InputHandler : MonoBehaviour
{
	private Invoker _invoker;
	private bool _isReplaying;
	public bool _isRecording = false;
	private BikeController _bikeController;
	private Command _buttonA, _buttonD, _buttonW;

	private void Start()
	{
		_invoker = gameObject.AddComponent<Invoker>();
		_bikeController = FindObjectOfType<BikeController>();

		_buttonA = new TurnLeft(_bikeController);
		_buttonD = new TurnRight(_bikeController);
		_buttonW = new ToggleTurbo(_bikeController);
	}

	private void Update()
	{
		if (!_isReplaying && _isRecording)
		{
			if (Input.GetKeyUp(KeyCode.A))
				_invoker.ExecuteCommand(_buttonA);
			if (Input.GetKeyUp(KeyCode.D))
				_invoker.ExecuteCommand(_buttonD);
			if (Input.GetKeyUp(KeyCode.W))
				_invoker.ExecuteCommand(_buttonW);
		}
	}

	public void StartRecording()
	{
		_bikeController.ResetPosition();
		_isReplaying = false;
		_isRecording = true;
		_invoker.Record();
	}

	public void StopRecording()
	{
		_bikeController.ResetPosition();
		_isRecording = false;
	}

	public void StartReplay()
	{
		_bikeController.ResetPosition();
		_isRecording = false;
		_isReplaying = true;
		_invoker.Replay();
	}
}
