using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class ToggleTurbo : Command
{
	private BikeController _controller;

	public ToggleTurbo(BikeController controller)
	{
		_controller = controller;
	}

	public override void Execute()
	{
		_controller.ToggleTurbo();
	}
}