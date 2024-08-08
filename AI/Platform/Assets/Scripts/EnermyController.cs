using System.Collections;
using System.Collections.Generic;
using System.Linq.Expressions;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.XR;

public class EnemyController : MonoBehaviour
{
	public enum STATE
	{
		Move,
		Watch,
		Attack
	}

	public enum DISTANCE
	{
		FAR = 10,
		CLOSE = 7
	}

	private Dictionary<STATE, IState<EnemyController>> dicState = new Dictionary<STATE, IState<EnemyController>>();
	private StateMachine<EnemyController> sm;
	public GameObject ballPrefab;

	public GameObject player;
	Vector3 playerDir;
	Vector3 rad = new Vector3(0, -1, 0);
	RaycastHit hit;
	Ray ray;
	int lineSize = 10;

	private float moveSpeed = 0.05f;

	void Start()
    {
		IState<EnemyController> idle = gameObject.AddComponent<EnemyWatch>();
		IState<EnemyController> move = gameObject.AddComponent<EnemyMove>();
		IState<EnemyController> turn = gameObject.AddComponent<EnemyAttack>();

		dicState.Add(STATE.Watch, idle);
		dicState.Add(STATE.Move, move);
		dicState.Add(STATE.Attack, turn);

		sm = new StateMachine<EnemyController>(this, dicState[STATE.Move]);

		Application.targetFrameRate = 60;

		GetPlayer();
	}

    void Update()
	{
		sm.DoOperateUpdate();
	}

	public void SetState(STATE state)
	{
		sm.SetState(dicState[state]);
	}

	public bool IsCloseDistance(Vector3 playerPosition, DISTANCE state)
	{
		if (Vector3.Distance(playerPosition, transform.position) <= (float)state)
			return true;
		return false;
	}

	public bool IsFarDistance(Vector3 playerPosition, DISTANCE state)
	{
		if (Vector3.Distance(playerPosition, transform.position) > (float)state)
			return true;
		return false;
	}

	public bool IsEndOfPlatform()
	{
		ray = new Ray(transform.position, transform.forward + rad);
		Debug.DrawRay(transform.position, (transform.forward + rad) * lineSize, Color.yellow);

		if (!Physics.Raycast(ray, out hit, lineSize))   // ray에 닿는 게 없으면 더 갈 수 없음
		{
			return true;
		}

		return false;
	}
	public void Attack()
	{
		GameObject ball = Instantiate(ballPrefab);
		ball.transform.position = transform.position;
		ball.transform.forward = transform.forward;
		ball.transform.LookAt(player.transform);
		ball.GetComponent<BallController>().Shoot();
	}

	public void SetRotateEnemyToPlayer()
	{
		// 플레이어 방향을 바라보도록 회전
		playerDir = player.transform.position - transform.position;
		playerDir.y = 0;

		Quaternion rot = Quaternion.LookRotation(playerDir.normalized);

		transform.rotation = rot;
	}

	void GetPlayer()
	{
		player = GameObject.FindWithTag("Player");
	}

	public void TurnEnemy()
	{
		transform.Rotate(0, Random.Range(90, 270), 0);
	}

	public void MoveForward()
	{
		transform.position = transform.position + transform.forward * moveSpeed;   // forward 방향으로 계속 전진
	}
}
