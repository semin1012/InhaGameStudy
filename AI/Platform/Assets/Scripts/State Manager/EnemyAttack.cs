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
		sender.SetRotateEnemyToPlayer();    // 플레이어를 바라보도록
		
		// 플레이어와의 거리가 MIDDLE보다 멀어지면
		if (sender.IsFarDistance(sender.player.transform.position, EnemyController.DISTANCE.CLOSE + 1))	
		{
			// 플레이어 지켜보는 상태로 변환
			sender.SetState(EnemyController.STATE.Watch);		
		}

		if ( time > 0.5f ) 
		{
			// 0.5초 지날 때마다 공 날리기
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

