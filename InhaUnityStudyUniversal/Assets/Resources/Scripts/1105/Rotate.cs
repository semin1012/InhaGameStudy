using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.Rendering.DebugUI.Table;

public class Rotate : MonoBehaviour
{
	public float rotSpeed = 30.0f;
	public GameObject target = null;

	private void Start()
	{
		//transform.eulerAngles = new Vector3(0.0f, 45f, 0.0f);
		// Quaternion quaternion = Quaternion.Euler(0.0f, 45f, 0.0f);
		// transform.rotation = quaternion;
		//transform.Rotate(Vector3.up * 45f);
	}

	void RotateLeft()
	{
		float rot = rotSpeed * Time.deltaTime;
		this.transform.Rotate(Vector3.up * (-rot));
	}

	void RotateRight()
	{
		float rot = rotSpeed * Time.deltaTime;
		this.transform.Rotate(Vector3.up * rot);
	}

	void Look_At()
	{
		Vector3 dirToTarget = target.transform.position - this.transform.position;
		// 1. this.transform.forward = dirToTarget.normalized;
		// 2. this.transform.rotation = Quaternion.LookRotation(dirToTarget, Vector3.up);
		transform.LookAt(dirToTarget); // 3.
	}
}
