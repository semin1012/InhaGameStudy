using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class EnermyAttack : MonoBehaviour, IState<EnermyController>
{
	GameObject player; 
	private float time = 0.0f;
	public void Enter(EnermyController sender)
	{
		time = 0;
		Debug.Log("Enermy Attack Enter");
	}
	public void Stay(EnermyController sender)
	{
		GetPlayer(sender);

		time = time + Time.deltaTime;

		if ( time > 0.5f ) 
		{
			Attack(sender);
		}
	}
	public void Exit(EnermyController sender)
	{
			time = 0;
		Debug.Log("Enermy Attack Exit");
	}

	void GetPlayer(EnermyController sender)
	{
		player = GameObject.FindWithTag("Player");
	}

	void Attack(EnermyController sender)
	{
		GameObject ball = Instantiate(sender.ballPrefab);
		ball.transform.position = sender.transform.position;
		ball.GetComponent<BallController>().Shoot();
		time = 0;
	}
}
