using System.Collections;
using UnityEngine;

public class Wheel : MonoBehaviour
{
	public float rotSpeed = 500f;
	public bool isFront = false;
	public GameObject left = null;
	public GameObject right = null;
	public bool isTurn = false;
	private Vector3 debugDir;
	public float tempAngle;
	private Vector3 direction;

	private void Reset()
	{
		left = transform.Find("Left").gameObject;
		right = transform.Find("Right").gameObject;
	}

	private void Start()
	{
		//StartCoroutine(ISetAngle());
	}

	public void RotateRight()
	{
		if (transform.localRotation.y > 10)
			return;
		float rot = rotSpeed * Time.deltaTime;
		transform.Rotate(Vector3.up * rot, Space.World);
	}
	private void Update()
	{
		if (!isFront)
			return;

		//transform.rotation = Quaternion.Euler(0, tempAngle * Time.deltaTime * rotSpeed, 90);
		//transform.Rotate(Vector3.up * direction.y * Time.deltaTime * rotSpeed);
		debugDir.x = transform.localRotation.x;
		debugDir.y = transform.localRotation.y;
		debugDir.z = transform.localRotation.z;
		if (!isTurn)
		{
			//SetAngle(tempAngle);
			//if (transform.localRotation.y > 0)
			//{
			//	float rot = rotSpeed * Time.deltaTime;
			//	transform.Rotate(Vector3.up * -rot, Space.World);
			//	Debug.Log("!isTurn: -rot");
			//}
			//else if (transform.localRotation.y < 0)
			//{
			//	float rot = rotSpeed * Time.deltaTime;
			//	transform.Rotate(Vector3.up * rot, Space.World);
			//	Debug.Log("!isTurn: rot");
			//}
		}
	}

	IEnumerator ISetAngle()
	{
		while (true)
		{
			SetAngle(0);
			yield return new WaitForSeconds(1.0f);
		}
	}

	public void RotateLeft()
	{
		if (transform.localRotation.y < -10)
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

	private void OnDrawGizmos()
	{
		Gizmos.DrawLine(transform.position, transform.position + debugDir);
	}

	public void SetDirection(Vector3 direction)
	{
		direction = Vector3.Normalize(direction);
		transform.rotation = Quaternion.LookRotation(direction);
		Debug.Log("SetDirection");
	}

	public void SetAngle(float angle)
	{
		UnityEngine.Debug.Log(angle);
		tempAngle = angle;	
	}
}
