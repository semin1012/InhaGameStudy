using Chapter.Facade;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class BikeEngine : MonoBehaviour, IBikeElement
{
	public float burnRate = 1.0f;
	public float fuelAmount = 100.0f;
	public float tempRate = 5.0f;
	public float minTemp = 50.0f;
	public float maxTemp = 65.0f;
	public float currentTemp;
	public float turboDuration = 2.0f;

	private bool _isEngineOn;
	private FuelPump _fuelPump;
	private TurboCharger _turboCharger; 
	private CoolingSystem _coolingSystem;


	public float turboBoost = 25.0f;
	public float maxTurboBoost = 200.0f;

	private bool _isTurboOn;
	private float _defaultSpeed = 300.0f;
	public float CurrentSpeed
	{
		get
		{
			if (_isTurboOn)
				return _defaultSpeed + turboBoost;
			return _defaultSpeed;
		}
	}

	private void Awake()
	{
		_fuelPump = gameObject.AddComponent<FuelPump>();
		_turboCharger = gameObject.AddComponent<TurboCharger>();
		_coolingSystem = gameObject.AddComponent<CoolingSystem>();
	}

	public void TurnOn()
	{
		_isEngineOn = true;
		StartCoroutine(_fuelPump.burnFuel);
		StartCoroutine(_coolingSystem.coolEngine);
	}

	public void TurnOff()
	{
		_isEngineOn = false;
		_coolingSystem.ResetTemperature();
		StopCoroutine(_fuelPump.burnFuel);
		StopCoroutine(_coolingSystem.coolEngine);
	}

	public void ToggleTurbo()
	{
		_isTurboOn = !_isTurboOn;
		if (_isEngineOn)
			_turboCharger.ToggleTurbo(_coolingSystem);
	}

	public void Accept(IVisitor visitor)
	{
		visitor.Visit(this);
	}

	void OnGUI()
	{
		GUI.color = Color.green;
		GUI.Label(new Rect(125, 20, 200, 20), "Turbo Boost: " + turboBoost);

		GUI.color = Color.green;
		GUI.Label(new Rect(100, 0, 500, 20), "Engine Running: " + _isEngineOn);
	}
}
