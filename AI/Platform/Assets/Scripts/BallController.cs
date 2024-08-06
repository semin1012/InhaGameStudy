using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallController : MonoBehaviour
{
	Vector3 playerDir;
	GameObject player;

    public void Shoot()
    {
        GetComponent<Rigidbody>().AddForce(transform.forward * 300f);
    }
    void Start()
    {
        Application.targetFrameRate = 60;
        player = GameObject.FindWithTag("Player");
		SetRotateEnermyToPlayer();
        Shoot();
	}

	void SetRotateEnermyToPlayer()
	{
		// 플레이어 방향을 바라보도록 회전
		playerDir = player.transform.position - transform.position;
		playerDir.y = 0;

		Quaternion rot = Quaternion.LookRotation(playerDir.normalized);

		transform.rotation = rot;
	}
}
