using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;
//using static System.IO.Enumeration.FileSystemEnumerable<TResult>;

public class EnermyMove : MonoBehaviour, IState<EnermyController>
{
	float rand;

	Vector3 rad = new Vector3(0, -1, 0);
	RaycastHit hit;
	Ray ray;
	int lineSize = 10;
	bool bTurn = true;

	public float moveSpeed = 0.05f;

	public void Enter(EnermyController sender)
	{
		bTurn = true;
		Debug.Log("Enermy Move Enter");
	}

	public void Stay(EnermyController sender)
	{
		if (bTurn)
		{
			TurnEnermy(sender);
			bTurn = false;
		}
		if (IsEndOfPlatform(sender))	// 플랫폼의 끝이면 Turn
			TurnEnermy(sender);

		
		sender.transform.position = sender.transform.position + sender.transform.forward * moveSpeed;	// forward 방향으로 계속 전진


		if (FindPlayer(sender))     // 플레이어를 발견하면 Watch 상태로 변경
			sender.SetState(EnermyController.STATE.Watch);
	}

	public void Exit(EnermyController sender)
	{
		bTurn = true;
		Debug.Log("Enermy Move Exit");
	}

	bool FindPlayer(EnermyController sender)
	{
		Collider[] colliders = Physics.OverlapSphere(sender.transform.position, (float)EnermyController.DISTANCE.FAR);

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

	void TurnEnermy(EnermyController sender)
	{
		Debug.Log("Turn");
		rand = Random.Range(90, 270);

		sender.transform.Rotate(0, rand, 0);
	}

	private bool IsEndOfPlatform(EnermyController sender)
	{
		ray = new Ray(sender.transform.position, sender.transform.forward + rad);
		Debug.DrawRay(sender.transform.position, (sender.transform.forward + rad) * lineSize, Color.yellow);

		if (!Physics.Raycast(ray, out hit, lineSize))   // ray에 닿는 게 없으면 더 갈 수 없음
		{
			return true;
		}

		return false;
	}
}
