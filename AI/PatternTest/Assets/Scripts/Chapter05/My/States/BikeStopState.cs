using Chapter.State;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.MyState
{
	public class BikeStopState : MonoBehaviour, IState<BikeController>
	{
		public void Enter()
		{
            BikeController.Instance.CurrentSpeed = 0;
		}

		public void Stay()
		{
			return;
		}

		public void Exit()
		{
			return;
		}
	}
}
