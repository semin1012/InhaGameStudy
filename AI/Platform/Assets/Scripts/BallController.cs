using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;

public class BallController : MonoBehaviour
{
	Vector3 playerDir;
	GameObject player;
	private float time = 0.0f;

	public void Shoot()
    {
		GetComponent<Rigidbody>().AddForce(transform.forward * 500f);
    }
    void Start()
    {
        Application.targetFrameRate = 60;
        player = GameObject.FindWithTag("Player");
        Shoot();
	}

	void Update()
	{
		time += Time.deltaTime;

		if (time > 3.0f)
		{
			Destroy(gameObject);
		}
	}

	void SetRotateEnermyToPlayer()
	{
		// �÷��̾� ������ �ٶ󺸵��� ȸ��
		playerDir = player.transform.position - transform.position;
		playerDir.y = 0;

		Quaternion rot = Quaternion.LookRotation(playerDir.normalized);

		transform.rotation = rot;
	}
}
