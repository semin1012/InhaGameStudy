using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy2D : MonoBehaviour
{
	public GameObject coinPrefab;
	public GameObject deathEffectPrefab;
	private Rigidbody2D rigidBody;
	private float maxSpeed = 200.0f;
	public float amplitude = 3.0f;  //진폭
	public int maxHp = 1;
	private int curHp = 0;
	public Player2D player;

	void Start()
	{
		rigidBody = GetComponent<Rigidbody2D>();
		curHp = maxHp;
		//Destroy(gameObject, 1.0f);  //1초 뒤에 삭제해라. or OnTriggerEnter2D사용
	}


	void Update()
	{

	}

	private void FixedUpdate()
	{
		Move_2D();  //모든 컴퓨터에서 일정하게 움직이려면 fixed Update으로 해주는게 좋다.
	}


	float yCos = 0.0f;
	void Move_2D()
	{

		Vector3 pos = rigidBody.transform.position;
		pos = new Vector3(
			pos.x + (-1 * maxSpeed * Time.deltaTime),
			pos.y + Mathf.Sin(yCos) * amplitude,    //진폭
			pos.z);
		yCos += (5.0f * Time.deltaTime);   //오르락 내리락 하는 속도
		rigidBody.MovePosition(pos);
	}

	private void OnTriggerEnter2D(Collider2D collision)
	{
		if (collision.tag == "PlayerBullet")
		{
			curHp -= 1;
			if (curHp <= 0)
			{
				player.GetScore(maxHp * 10);
				Destroy(gameObject);
				Destroy(collision.gameObject);
				Instantiate(coinPrefab, transform.position, transform.rotation);
				Instantiate(deathEffectPrefab, transform.position, transform.rotation);
			}
		}
		else if (collision.tag == "EndLine")
		{
			Destroy(gameObject);
		}
	}
}
