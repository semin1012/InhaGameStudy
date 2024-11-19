using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet1 : MonoBehaviour
{
	private Rigidbody2D rigidBody;
	public GameObject effectPrefab;

	private float maxSpeed = 400.0f;

	void Start()
	{
		Application.runInBackground = true;
		rigidBody = GetComponent<Rigidbody2D>();

		Destroy(gameObject, 3.0f);
	}

	private void FixedUpdate()
	{
		Move_2D();
	}
	void Move_2D()
	{
		Vector2 pos = rigidBody.transform.position;
		rigidBody.MovePosition(
			new Vector2(    
				pos.x + (maxSpeed * Time.deltaTime),
				pos.y));
	}
	private void OnTriggerEnter2D(Collider2D collision)
	{
		//Debug.Log("<color=red>" + collision.name + " Ãæµ¹ </color>");
		if (collision.tag == "Enemy")
		{
			// : score up
			Destroy(gameObject);
			Instantiate(effectPrefab, transform.position, transform.rotation);
		}
	}
}
