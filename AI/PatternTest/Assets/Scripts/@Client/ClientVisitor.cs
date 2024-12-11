using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClientVisitor : MonoBehaviour
{
	public PowerUp enginePowerUp;
	public PowerUp shieldPowerUp;
	public PowerUp weaponPowerUp;

	private BikeController _bikeController;

	private void Awake()
	{
		_bikeController = (BikeController)FindObjectOfType(typeof(BikeController));
		if (_bikeController == null ) 
			_bikeController = gameObject.AddComponent<BikeController>();
	}

	private void OnGUI()
	{
		if (GUILayout.Button("PowerUp Shield"))
			_bikeController.Accept(shieldPowerUp);
		if (GUILayout.Button("PowerUp Engine"))
			_bikeController.Accept(enginePowerUp);
		if (GUILayout.Button("PowerUp Weapon"))
			_bikeController.Accept(weaponPowerUp);
	}
}
