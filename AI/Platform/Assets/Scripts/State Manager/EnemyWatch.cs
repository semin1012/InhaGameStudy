using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyWatch : MonoBehaviour, IState<EnemyController>
{
	public void Enter(EnemyController sender)
	{
		Debug.Log("Enemy Watch Enter");
	}

	public void Stay(EnemyController sender)
	{
		if ( sender.IsCloseDistance(sender.player.transform.position, EnemyController.DISTANCE.CLOSE)) // 플레이어와 거리가 MIDDLE 이하면 Attack(공격)으로
		{
			sender.SetState(EnemyController.STATE.Attack);
		}

		if ( sender.IsFarDistance(sender.player.transform.position, EnemyController.DISTANCE.FAR + 1))	// 플레이어와 거리가 FAR 이상이면 Move(순찰)로
		{
			sender.SetState(EnemyController.STATE.Move);
		}

		// 계속 플레이어를 주시하도록 Set Rotate
		sender.SetRotateEnemyToPlayer();
	}

	public void Exit(EnemyController sender)
	{
		Debug.Log("Enemy Watch Exit");
	}

}
