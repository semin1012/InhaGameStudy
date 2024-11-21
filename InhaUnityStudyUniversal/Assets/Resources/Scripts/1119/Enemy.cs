using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy2D : MonoBehaviour
{
	public GameObject coinPrefab;
	public GameObject deathEffectPrefab;
	private Rigidbody2D rigidBody;
	private float maxSpeed = 200.0f;
	public float amplitude = 3.0f;  //����
	public int maxHp = 1;
	private int curHp = 0;
	public Player2D player;

	void Start()
	{
		rigidBody = GetComponent<Rigidbody2D>();
		curHp = maxHp;
		//Destroy(gameObject, 1.0f);  //1�� �ڿ� �����ض�. or OnTriggerEnter2D���
	}


	void Update()
	{

	}

	private void FixedUpdate()
	{
		Move_2D();  //��� ��ǻ�Ϳ��� �����ϰ� �����̷��� fixed Update���� ���ִ°� ����.
	}


	float yCos = 0.0f;
	void Move_2D()
	{

		Vector3 pos = rigidBody.transform.position;
		pos = new Vector3(
			pos.x + (-1 * maxSpeed * Time.deltaTime),
			pos.y + Mathf.Sin(yCos) * amplitude,    //����
			pos.z);
		yCos += (5.0f * Time.deltaTime);   //������ ������ �ϴ� �ӵ�
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
