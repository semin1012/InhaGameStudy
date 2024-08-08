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
		// �÷��̾�� �Ÿ��� MIDDLE ���ϸ� Attack(����)����
		if ( sender.IsCloseDistance(sender.player.transform.position, EnemyController.DISTANCE.CLOSE)) 
		{
			sender.SetState(EnemyController.STATE.Attack);
		}

		// �÷��̾�� �Ÿ��� FAR �̻��̸� Move(����)��
		if ( sender.IsFarDistance(sender.player.transform.position, EnemyController.DISTANCE.FAR + 1))
		{
			sender.SetState(EnemyController.STATE.Move);
		}

		// ��� �÷��̾ �ֽ��ϵ��� Set Rotate
		sender.SetRotateEnemyToPlayer();
	}

	public void Exit(EnemyController sender)
	{
		Debug.Log("Enemy Watch Exit");
	}
}

