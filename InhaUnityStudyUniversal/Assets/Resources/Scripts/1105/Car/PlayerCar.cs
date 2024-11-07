using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCar : Car
{
	private void Update()
	{
		if ( Input.GetKey(KeyCode.W))
			MoveForward();
		if ( Input.GetKey(KeyCode.S)) 
			MoveBack();
		if (Input.GetKey(KeyCode.A))
		{
			frontWheel.RotateLeft();
			frontWheel.isTurn = true;
		}
		else frontWheel.isTurn = false;
		if (Input.GetKey(KeyCode.D))
		{
			frontWheel.RotateRight();
			frontWheel.isTurn = true;
		}
		else frontWheel.isTurn = false;
	}
}
