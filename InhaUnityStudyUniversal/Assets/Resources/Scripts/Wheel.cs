using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wheel : MonoBehaviour
{
	public float rotSpeed = 10.0f;
	public bool isFront = false;
	public GameObject left = null;
	public GameObject right = null;
	void Update()
	{
		WheelRotate();

		if (isFront)
		{
			float rot = rotSpeed * Time.deltaTime;

			if (Input.GetKey(KeyCode.A))
				transform.Rotate(Vector3.up * -rot, Space.World);
			if (Input.GetKey(KeyCode.D))
				transform.Rotate(Vector3.up * rot, Space.World);
		}
	}

	void WheelRotate()
	{
		//float rot = rotSpeed * Time.deltaTime;
		//if (Input.GetKey(KeyCode.S))
		//	transform.Rotate(Vector3.up * rot);
		//if (Input.GetKey(KeyCode.W))
		//	transform.Rotate(Vector3.up * -rot);
	}
}
