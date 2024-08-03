using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    float moveX;
    float moveZ;

	public float moveSpeed = 7.0f;
	void Start()
    {
        Application.targetFrameRate = 60;       
    }

    void Update()
    {
		float h = Input.GetAxis("Horizontal");
		float v = Input.GetAxis("Vertical");

		transform.position += new Vector3(h, 0, v) * moveSpeed * Time.deltaTime;
	}
}
