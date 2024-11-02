using Chapter.State;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.MyState
{
	public interface IState<T>
	{
		void Enter();
		void Stay();
		void Exit();
	}
}