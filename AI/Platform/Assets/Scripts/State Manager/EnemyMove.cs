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

		if (sender.IsEndOfPlatform())	// �÷����� ���̸� Turn
			sender.TurnEnemy();

		sender.MoveForward();   // enemy�� forward �������� ����

		// �÷��̾���� �Ÿ��� FAR ���ϸ� 
		if (sender.IsCloseDistance(sender.player.transform.position, EnemyController.DISTANCE.FAR))    
			sender.SetState(EnemyController.STATE.Watch);	// ���Ѻ��� ���·� ����
	}

	public void Exit(EnemyController sender)
	{
		bTurn = true;
		Debug.Log("Enemy Move Exit");
	}
}
