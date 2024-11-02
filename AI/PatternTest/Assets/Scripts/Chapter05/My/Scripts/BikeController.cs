using Chapter.State;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.MyState
{

	public class BikeController : MonoBehaviour
	{
		public float maxSpeed = 2.0f;
		public float turnDistance = 2.0f;

		public float CurrentSpeed { get; set; }

		public Direction CurrentTurnDirection { get; private set; }
		private BikeStateContext context;

		BikeController()
		{
			context = new BikeStateContext(this);
		}

		public void ChangeState(EBikeState state)
		{
			context.ChangeState(state);
		}
	}

}
