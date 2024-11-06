using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;
using static UnityEngine.Rendering.DebugUI.Table;

public class Wheel : MonoBehaviour
{
	public float rotSpeed = 20.0f;
	public bool isFront = false;
	public GameObject left = null;
	public GameObject right = null;
	public bool isCollided = false;

	private void Reset()
	{
		left = transform.Find("Left").gameObject;
		right = transform.Find("Right").gameObject;
	}

	public void RotateRight()
	{
		if (transform.rotation.y > 0.5)
			return;
		float rot = rotSpeed * Time.deltaTime;
		transform.Rotate(Vector3.up * rot, Space.World);
	}
	private void Update()
	{
		if (!isFront)
			return;

		if (!isCollided)
		{
			if (transform.rotation.y > 0.1)
			{
				float rot = rotSpeed * Time.deltaTime;
				transform.Rotate(Vector3.up * -rot, Space.World);
			}
			else if ( transform.rotation.y < -0.1)
			{
				float rot = rotSpeed * Time.deltaTime;
				transform.Rotate(Vector3.up * rot, Space.World);
			}
		}
	}

	public void RotateLeft()
	{
		if (transform.rotation.y < -0.5)
			return;

		float rot = rotSpeed * Time.deltaTime;
		transform.Rotate(Vector3.up * -rot, Space.World);
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
