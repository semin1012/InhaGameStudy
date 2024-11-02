using Chapter.State;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.MyState
{
	public class BikeStopState : MonoBehaviour, IState<BikeController>
	{
		public void Enter(BikeController sender)
		{
			if (sender == null)
				return;

			sender.CurrentSpeed = 0;
		}

		public void Stay(BikeController sender)
		{
			return;
		}

		public void Exit(BikeController sender)
		{
			return;
		}
	}
}
