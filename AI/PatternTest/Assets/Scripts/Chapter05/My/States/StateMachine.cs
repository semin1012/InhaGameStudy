using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace Chapter.MyState
{
	public class StateMachine<T>
	{
		private T sender;
		public IState<T> CurState { get; set; }

		StateMachine(T sender, IState<T> curState)
		{
			this.sender = sender;
			CurState = curState;
			CurState.Enter();
		}

		public void ChangeState(IState<T> state)
		{
			if (CurState == state)
				return;

			if (CurState == null)
				return;

			CurState.Exit();
			CurState = state;
			CurState.Enter();	
		}

		public void Update()
		{
			CurState.Stay();
		}
	}
}
