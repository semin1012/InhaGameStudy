using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class Cloud : MonoBehaviour
{
    private Rigidbody2D rigidBody;
    public float maxSpeed = 150.0f;
    void Start()
    {
        rigidBody = GetComponent<Rigidbody2D>();
    }
    
	private void FixedUpdate()
	{
		Vector2 pos = transform.position;
		pos = new Vector2(pos.x - maxSpeed * Time.deltaTime, pos.y);
		//transform.Translate(pos);
		rigidBody.MovePosition(pos);
	}

	private void OnTriggerEnter2D(Collider2D collision)
	{
		if (collision.tag == "EndLine")
			Destroy(gameObject);
	}
}
