using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StateMachine<T>
{
	private T m_sender;
	public IState<T> CurState { get; set; }
	public StateMachine(T sender, IState<T> state)
	{
		m_sender = sender;
		SetState(state);
	}

	public void SetState(IState<T> state)
	{
		if (m_sender == null)
		{
			Debug.LogError("m_sender ERROR");
			return;
		}

		if (CurState == state)
		{
			return;
		}

		if (CurState != null)
			CurState.Exit(m_sender);

		//상태 교체
		CurState = state;

		if (CurState != null)
			CurState.Enter(m_sender);
	}

	public void DoOperateUpdate()
	{
		if (m_sender == null)
		{
			Debug.LogError("invalid m_sener");
			return;
		}
		CurState.Stay(m_sender);
	}
}
