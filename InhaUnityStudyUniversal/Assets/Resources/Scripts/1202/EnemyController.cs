using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class EnemyController : MonoBehaviour
{
	public GameObject target;
	NavMeshAgent agent;
	Animator animator;

	private void Start()
	{
		agent = GetComponent<NavMeshAgent>();
		animator = GetComponentInChildren<Animator>();
	}

	private void Update()
	{
		if (target != null)
		{
			animator.SetFloat("Speed", agent.velocity.magnitude);
			agent.destination = target.transform.position;	

			if (agent.remainingDistance <= agent.stoppingDistance)
				agent.isStopped = true;
		}
	}

	private void OnDrawGizmos()
	{
		NavMeshPath path = agent.path;
		Vector3 pos = this.transform.position;
		foreach (Vector3 corner in path.corners)
		{
			Gizmos.color = Color.blue;
			Gizmos.DrawSphere(corner, 0.4f);

			Gizmos.color = Color.red;
			Gizmos.DrawLine(pos, corner);
			pos = this.transform.position;
		}
	}

}
