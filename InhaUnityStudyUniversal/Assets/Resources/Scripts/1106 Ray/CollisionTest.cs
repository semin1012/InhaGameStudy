using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionTest : MonoBehaviour
{
	float speedMove = 10.0f;
	float speedRot = 100.0f;

	private void Update()
	{
		Move_Rotate();
	}

	private void Move_Rotate()
	{
		float rot = Input.GetAxis("Horizontal");
		float move = Input.GetAxis("Vertical");

		rot = rot * speedRot * Time.deltaTime;
		move = move * speedMove * Time.deltaTime;

		gameObject.transform.Rotate(Vector3.up * rot);
		gameObject.transform.Translate(Vector3.forward * move);
	}

	private void OnCollisionEnter(Collision collision)
	{
		GameObject hitObject = collision.gameObject;
		print("<color=red>Collider : " + hitObject.name + "</color> 충돌 시작");
	}

	private void OnCollisionStay(Collision collision)
	{
		GameObject hitObject = collision.gameObject;
		print("<color=yellow>Collider : " + hitObject.name + "</color> 충돌 중");
	}

	private void OnCollisionExit(Collision collision)
	{
		GameObject hitObject = collision.gameObject;
		print("<color=blue>Collider : " + hitObject.name + "</color> 충돌 끝");
	}

	private void OnTriggerEnter(Collider other)
	{
		GameObject hitObject = other.gameObject;
		print("<color=red>Trigger : " + hitObject.name + "</color> 충돌 시작");
	}

	private void OnTriggerStay(Collider other)
	{
		GameObject hitObject = other.gameObject;
		print("<color=yellow>Trigger : " + hitObject.name + "</color> 충돌 중");
	}
	private void OnTriggerExit(Collider other)
	{
		GameObject hitObject = other.gameObject;
		print("<color=blue>Trigger : " + hitObject.name + "</color> 충돌 끝");
	}
}
