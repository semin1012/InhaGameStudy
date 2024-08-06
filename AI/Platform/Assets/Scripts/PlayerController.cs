using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    float moveX;
    float moveZ;

	public float moveSpeed = 7.0f;
	public float jumpForce = 10.0f;
	private Rigidbody rb;

	bool isJumping = false;

	void Start()
    {
		rb = GetComponent<Rigidbody>();
        Application.targetFrameRate = 60;       
    }

    void FixedUpdate()
    {
		float h = Input.GetAxis("Horizontal");
		float v = Input.GetAxis("Vertical");

		transform.position += new Vector3(h, 0, v) * moveSpeed * Time.deltaTime;

		if (Input.GetKey(KeyCode.Space) && !isJumping)
		{
			isJumping = true;
			rb.AddForce(new Vector3(0, 10, 0), ForceMode.Impulse);
		}
	}

	private void OnCollisionEnter(Collision collision)
	{
		isJumping=false;
	}
}
