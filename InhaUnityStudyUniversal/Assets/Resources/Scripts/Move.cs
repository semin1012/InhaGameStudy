using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
	public float moveSpeed = 10.0f;

	void Start()
    {
		//transform.Translate(new Vector3(0, 5f, 0));
    }

	void Update()
	{
		if (Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.W))
		{
			float moveDelta = moveSpeed * Time.deltaTime;
			transform.Translate(Vector3.forward * moveDelta);
		}
		if ( Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
		{
			float moveDelta = moveSpeed * Time.deltaTime;
			transform.Translate(Vector3.forward * -moveDelta);
		}
	}
}
