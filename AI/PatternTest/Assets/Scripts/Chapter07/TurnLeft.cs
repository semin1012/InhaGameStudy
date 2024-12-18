using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurnLeft : Command
{
	private BikeController _controller;

	public TurnLeft(BikeController controller)
	{
		_controller = controller;
	}

	public override void Execute()
	{
		_controller.Turn(BikeController.Direction.Left);
	}
} 
