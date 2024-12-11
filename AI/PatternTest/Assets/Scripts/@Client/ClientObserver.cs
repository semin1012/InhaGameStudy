using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClientObserver : MonoBehaviour
{
	public BikeController _bikeController;

	private void Start()
	{
		_bikeController = (BikeController)FindObjectOfType(typeof(BikeController)); 
	}

	private void OnGUI()
	{
		GUILayout.BeginArea(new Rect(0, 50, 100, 200));
		if (GUILayout.Button("Damage Bike"))
			if (_bikeController)
				_bikeController.TakeDamage(15.0f);

		if (GUILayout.Button("Toggle Turbo"))
			if (_bikeController)
				_bikeController.ToggleTurbo();
		GUILayout.EndArea();
	}
}
