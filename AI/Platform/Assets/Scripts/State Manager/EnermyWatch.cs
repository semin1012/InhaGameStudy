using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnermyWatch : IState<EnermyController>
{
	Vector3 playerDir;
	Collider player;

	public void Enter(EnermyController sender)
	{
		Debug.Log("Enermy Watch Enter");
	}
	public void Stay(EnermyController sender)
	{
		if ( IsClosedPlayer(sender) )	// 플레이어와 가까워졌다면 Attack(공격)으로
		{
			sender.SetState(EnermyController.STATE.Attack);
		}

		if ( IsBecomeDistanceToPlayer(sender) )	// 플레이어와 멀어졌다면 Move(순찰)로
		{
			sender.SetState(EnermyController.STATE.Move);
		}

		// 계속 플레이어를 주시하도록 Set Rotate
		SetRotateEnermyToPlayer(sender);
	}
	public void Exit(EnermyController sender)
	{
		Debug.Log("Enermy Watch Exit");
	}

	bool IsClosedPlayer(EnermyController sender)
	{
		Collider[] colliders = Physics.OverlapSphere(sender.transform.position, 2f);

		if (colliders.Length > 0)
		{
			for (int i = 0; i < colliders.Length; i++)
			{
				if (colliders[i].tag == "Player")
				{
					return true;
				}
			}
		}
		return false;
	}

	bool IsBecomeDistanceToPlayer(EnermyController sender)
	{
		Collider[] colliders = Physics.OverlapSphere(sender.transform.position, 8.5f);

		if (colliders.Length > 0)
		{
			for (int i = 0; i < colliders.Length; i++)
			{
				if (colliders[i].tag == "Player")
				{
					player = colliders[i];
					return false;
				}
			}
		}
		return true;
	}
	void SetRotateEnermyToPlayer(EnermyController sender)
	{
		// 플레이어 방향을 바라보도록 회전
		playerDir = player.transform.position - sender.transform.position;
		playerDir.y = 0;

		Quaternion rot = Quaternion.LookRotation(playerDir.normalized);

		sender.transform.rotation = rot;
	}
}
