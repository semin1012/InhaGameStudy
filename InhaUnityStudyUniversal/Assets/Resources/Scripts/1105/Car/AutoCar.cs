using System.Collections;
using System.Collections.Generic;
using System.Drawing;
using UnityEngine;
using UnityEngine.UIElements;

public class AutoCar : Car
{
	[Range(0, 50)]
	public float distance = 20.0f;

	private RaycastHit rayHit;
	private Ray ray;
	private Vector3 reflect;
	public CameraController mainCamera;

	private void Start()
	{
		frontWheel = body.transform.Find("FrontWheelParent").GetComponent<Wheel>();
		ray = new Ray();
		ray.origin = frontWheel.transform.position + frontWheel.transform.forward * 3f;
		ray.direction = frontWheel.transform.forward;
	}
	private void Update()
	{
		ray.origin = frontWheel.transform.position + frontWheel.transform.forward * 3f;
		ray.direction = frontWheel.transform.forward;
		transform.LookAt(body.transform);

		Ray();

		MoveForward();
		if (Input.GetKey(KeyCode.DownArrow))
			MoveBack();
		if (Input.GetKey(KeyCode.LeftArrow))
			frontWheel.RotateLeft();
		if (Input.GetKey(KeyCode.RightArrow))
			frontWheel.RotateRight();
	}

	private void OnDrawGizmos()
	{
		Gizmos.color = new Color32(255, 255, 0, 255);       // new Color(1, 1, 0); // °¡´É
		Gizmos.DrawLine(ray.origin, ray.origin + ray.direction * distance);
		Gizmos.DrawSphere(ray.origin, 0.1f);

		if (rayHit.collider == null)
			return;

		Gizmos.color = new Color32(0, 255, 255, 255);      
		Vector3 incomingVector = ray.direction;
		incomingVector = incomingVector.normalized;
		Vector3 normalVector = rayHit.normal;
		reflect = Vector3.Reflect(incomingVector, normalVector); 
		Gizmos.DrawLine(rayHit.point, rayHit.point + reflect * distance);

		Gizmos.color = new Color32(0, 0, 255, 255);       
		Vector3 tmpDirection = (rayHit.point + reflect * distance) - ray.origin;
		Gizmos.DrawLine(ray.origin, ray.origin + tmpDirection);
		
		//angle = 90 - angle / 2;
		//frontWheel.SetAngle(Vector3.Angle(incomingVector, tmpDirection));
		//frontWheel.tempAngle = Vector3.Angle(incomingVector, tmpDirection);
		frontWheel.SetDirection(tmpDirection);
	}

	void Ray()
	{
		if (Physics.Raycast(ray.origin, ray.direction, out rayHit, distance))
		{
			frontWheel.isTurn = true;
		}
		else
		{
			frontWheel.isTurn = false;
		}
	}
}
