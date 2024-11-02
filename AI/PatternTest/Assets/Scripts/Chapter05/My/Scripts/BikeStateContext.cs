using Chapter.State;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.MyState
{
	public enum EBikeState
	{
		Stop,
		Start,
		Turn,
		Max,
	}
	public class BikeStateContext : MonoBehaviour
	{
		private readonly BikeController bikeController;
		private EBikeState currentState;

		private Dictionary<EBikeState, IState<BikeController>> dicState;

		StateMachine<BikeController> stateMachine;

		public BikeStateContext(BikeController bikeController)
		{
			if (bikeController == null)
				return;
			this.bikeController = bikeController;
			dicState[(int)EBikeState.Stop] = gameObject.AddComponent<BikeStopState>();
		}

		private void Update()
		{
			stateMachine.Update();
		}

		public void ChangeState(EBikeState state)
		{
			currentState = state;
			stateMachine.ChangeState(dicState[currentState]);
		}
	}
}
