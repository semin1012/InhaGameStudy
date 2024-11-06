using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.Experimental.GraphView.GraphView;

public class AutoCar : Car
{
	[Range(0, 50)]
	public float distance = 10.0f;

	private RaycastHit rayHit;
	private Ray ray;
	public Camera mainCamera;

	private void Start()
	{
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
		if (rayHit.collider != null)
		{
			frontWheel.isCollided = true;
			if (rayHit.normal.x > 0)
				frontWheel.RotateRight();
			else if (rayHit.normal.x < 0)
				frontWheel.RotateLeft();
		}
		else frontWheel.isCollided = false;

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

		Gizmos.color = Color.yellow;
		Gizmos.DrawLine(rayHit.point, rayHit.point + rayHit.normal);

		Vector3 reflect = Vector3.Reflect(transform.forward, rayHit.normal);
		Gizmos.DrawLine(rayHit.point, rayHit.point + reflect);
	}

	void Ray()
	{
		Physics.Raycast(ray.origin, ray.direction, out rayHit, distance);
	}
}
