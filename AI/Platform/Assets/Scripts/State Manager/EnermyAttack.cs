using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;

public class EnermyAttack : MonoBehaviour, IState<EnermyController>
{
	Vector3 playerDir;
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
		SetRotateEnermyToPlayer(sender);    // 플레이어를 바라보도록
		if (IsBecomeDistanceToPlayer(sender))
		{
			sender.SetState(EnermyController.STATE.Watch);
		}

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
		ball.transform.forward = sender.transform.forward;
		ball.transform.LookAt(player.transform);
		ball.GetComponent<BallController>().Shoot();
		time = 0;
	}
	void SetRotateEnermyToPlayer(EnermyController sender)
	{
		// 플레이어 방향을 바라보도록 회전
		playerDir = player.transform.position - sender.transform.position;
		playerDir.y = 0;

		Quaternion rot = Quaternion.LookRotation(playerDir.normalized);

		sender.transform.rotation = rot;
	}
	bool IsBecomeDistanceToPlayer(EnermyController sender)
	{
		Collider[] colliders = Physics.OverlapSphere(sender.transform.position, (float)EnermyController.DISTANCE.MIDDLE + 1);

		if (colliders.Length > 0)
		{
			for (int i = 0; i < colliders.Length; i++)
			{
				if (colliders[i].tag == "Player")
				{
					return false;
				}
			}
		}
		return true;
	}
}
