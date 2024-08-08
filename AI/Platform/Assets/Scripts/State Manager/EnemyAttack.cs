using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;

public class EnemyAttack : MonoBehaviour, IState<EnemyController>
{
	private float time = 0.0f;
	
	public void Enter(EnemyController sender)
	{
		time = 0;
		Debug.Log("Enemy Attack Enter");
	}

	public void Stay(EnemyController sender)
	{
		time = time + Time.deltaTime;
		sender.SetRotateEnemyToPlayer();    // �÷��̾ �ٶ󺸵���
		
		// �÷��̾���� �Ÿ��� MIDDLE���� �־�����
		if (sender.IsFarDistance(sender.player.transform.position, EnemyController.DISTANCE.CLOSE + 1))	
		{
			// �÷��̾� ���Ѻ��� ���·� ��ȯ
			sender.SetState(EnemyController.STATE.Watch);		
		}

		if ( time > 0.5f ) 
		{
			// 0.5�� ���� ������ �� ������
			sender.Attack();		
			time = 0f;
		}
	}

	public void Exit(EnemyController sender)
	{
		time = 0;
		Debug.Log("Enemy Attack Exit");
	}
}

