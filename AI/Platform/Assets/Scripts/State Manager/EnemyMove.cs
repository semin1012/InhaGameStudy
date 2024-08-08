using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;
//using static System.IO.Enumeration.FileSystemEnumerable<TResult>;

public class EnemyMove : MonoBehaviour, IState<EnemyController>
{
	bool bTurn = true;

	public void Enter(EnemyController sender)
	{
		bTurn = true;
		Debug.Log("Enemy Move Enter");
	}

	public void Stay(EnemyController sender)
	{
		if (bTurn)
		{
			sender.TurnEnemy();
			bTurn = false;
		}

		if (sender.IsEndOfPlatform())	// 플랫폼의 끝이면 Turn
			sender.TurnEnemy();

		sender.MoveForward();   // enemy의 forward 방향으로 전진

		// 플레이어와의 거리가 FAR 이하면 
		if (sender.IsCloseDistance(sender.player.transform.position, EnemyController.DISTANCE.FAR))    
			sender.SetState(EnemyController.STATE.Watch);	// 지켜보는 상태로 변경
	}

	public void Exit(EnemyController sender)
	{
		bTurn = true;
		Debug.Log("Enemy Move Exit");
	}
}
