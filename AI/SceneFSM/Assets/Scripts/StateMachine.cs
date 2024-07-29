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
        //Debug.Log("SetState : " + state);

        if (m_sender == null)
        {
            Debug.LogError("m_sender ERROR");
            return;
        }

        if (CurState == state)
        {
            // Debug.LogWarningFormat("Same state : ", state);
            return;
        }

        if (CurState != null)
            CurState.Exit(m_sender);

        //상태 교체
        CurState = state;

        //새 상태의 Enter 호출
        if (CurState != null)
            CurState.Enter(m_sender);

        //Debug.Log("SetNextState : " + state);
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
