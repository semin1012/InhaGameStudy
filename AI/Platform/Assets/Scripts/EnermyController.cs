using System.Collections;
using System.Collections.Generic;
using System.Linq.Expressions;
using Unity.VisualScripting;
using UnityEngine;

public class EnermyController : MonoBehaviour
{
	public enum STATE
	{
		Move,
		Watch,
		Attack
	}

	private Dictionary<STATE, IState<EnermyController>> dicState = new Dictionary<STATE, IState<EnermyController>>();
	private StateMachine<EnermyController> sm;
	public GameObject ballPrefab;


	void Start()
    {
		IState<EnermyController> idle = new EnermyWatch();
		IState<EnermyController> move = gameObject.AddComponent<EnermyMove>();
		IState<EnermyController> turn = new EnermyAttack();

		dicState.Add(STATE.Watch, idle);
		dicState.Add(STATE.Move, move);
		dicState.Add(STATE.Attack, turn);

		sm = new StateMachine<EnermyController>(this, dicState[STATE.Move]);

		Application.targetFrameRate = 60;
	}

    void Update()
	{
		sm.DoOperateUpdate();
	}

	public void SetState(STATE state)
	{
		sm.SetState(dicState[state]);
	}
}
