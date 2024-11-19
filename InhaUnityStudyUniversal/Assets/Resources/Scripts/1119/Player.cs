using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2D : MonoBehaviour
{
	private Rigidbody2D rigidBody;

	private float maxSpeed = 300.0f;

	void Start()
	{
		rigidBody = GetComponent<Rigidbody2D>();
	}

	void Update()
	{

	}

	private void FixedUpdate()
	{
		Move_2D();
	}

	void Move_2D()
	{
		float x = Input.GetAxis("Horizontal");
		float y = Input.GetAxis("Vertical");
		Vector3 pos = rigidBody.transform.position;
		rigidBody.MovePosition(
			new Vector3(    //Vector2로 하면 pos.z지우면 됨 둘다 사용가능.
				pos.x + (x * maxSpeed * Time.deltaTime),
				pos.y + (y * maxSpeed * Time.deltaTime),
				pos.z));
	}

	private void OnTriggerEnter2D(Collider2D collision)
	{
		//Debug.Log("<color=red>" + collision.name + " 충돌 </color>");
	}
}
