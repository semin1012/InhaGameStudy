using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : Observer
{
	private bool _isTurboOn;
	private Vector3 _initialPosition;
	private float _shakeMagnitude = 0.1f;

    private void Start()
    {

    }

    private void OnEnable()
	{
		_initialPosition = gameObject.transform.localPosition;
	}

	private void Update()
	{
		if (_isTurboOn)
			gameObject.transform.localPosition = _initialPosition + (Random.insideUnitSphere * _shakeMagnitude);
		else
			gameObject.transform.localPosition = _initialPosition;
	}

	public override void Notify(Subject subject)
	{
		if (subject is BikeController bike)
			_isTurboOn = bike.IsTurboOn;
	}
}
