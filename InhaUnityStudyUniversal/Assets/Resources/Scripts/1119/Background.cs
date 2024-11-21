using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Background : MonoBehaviour
{
    private Vector2 startPos;
    private float width;
	public float speed = 2.0f;

	private void Start()
	{
		startPos = transform.position;
		width = GetComponent<BoxCollider2D>().size.x;
	}

	private void FixedUpdate()
	{
		if (transform.position.x <= startPos.x - width)
			transform.position = startPos;
		transform.position = new Vector3(transform.position.x - speed, transform.position.y, 1.0f);
	}
}
