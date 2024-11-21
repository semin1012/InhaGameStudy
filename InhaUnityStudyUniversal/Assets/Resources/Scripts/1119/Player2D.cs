using System;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;

public class Player2D : MonoBehaviour
{
	private Rigidbody2D rigidBody;
	[SerializeField] public GameObject getScorePrefab;
	[SerializeField] public GameObject gameOverPrefab;
	[SerializeField] public GameObject damagePrefab;
	[SerializeField] public ScoreUI scoreUI;
	[SerializeField] public GameObject hitEffectPrefab;

	public int maxHp = 3;
	public int curHp = 0;
	private float maxSpeed = 300.0f;

	private void Reset()
	{
		scoreUI = GameObject.FindGameObjectWithTag("UI").GetComponent<ScoreUI>();
		getScorePrefab = Resources.Load("Prefabs/Flight/GetScoreUI1", typeof(GameObject)) as GameObject;
		gameOverPrefab = Resources.Load("Prefabs/Flight/GameOverUI1", typeof(GameObject)) as GameObject;
		damagePrefab = Resources.Load("Prefabs/Flight/DamagedUI", typeof(GameObject)) as GameObject;
		hitEffectPrefab = Resources.Load("Prefabs/Flight/HitEffect", typeof(GameObject)) as GameObject;

	}

	void Start()
	{
		rigidBody = GetComponent<Rigidbody2D>();
		curHp = maxHp; 
	}

	private void FixedUpdate()
	{
		Move_2D();
	}

	void Move_2D()
	{
		float x = Input.GetAxis("Horizontal");
		float y = Input.GetAxis("Vertical");
		Vector3 pos = rigidBody.transform.position;
		rigidBody.MovePosition(
			new Vector3( 
				pos.x + (x * maxSpeed * Time.deltaTime),
				pos.y + (y * maxSpeed * Time.deltaTime),
				pos.z));
	}

	public void GetScore(int score)
	{
		if (GameManager.Instance.bGameOver)
			return;
		GameManager.Instance.score += score;
		GameObject obj = Instantiate(getScorePrefab);
		FloatingUI ui = obj.GetComponent<FloatingUI>();
		Vector3 screenPoint = Camera.main.WorldToScreenPoint(transform.position);
		ui.SetPos(screenPoint, score);
		//scoreUI.SetHp(curHp);
	}

	public void Damaged(int damage)
	{
		if (GameManager.Instance.bGameOver)
			return;
		curHp -= damage;
		scoreUI.SetHp(curHp);
		Instantiate(hitEffectPrefab, transform.position, transform.rotation);

		Vector3 screenPoint = Camera.main.WorldToScreenPoint(transform.position);

		if (curHp <= 0)
		{
			GameManager.Instance.GameOver();
			GameObject obj = Instantiate(gameOverPrefab);
			FloatingUI ui = obj.GetComponent<FloatingUI>();
			ui.SetPos(screenPoint);
			gameObject.SetActive(false);
			Invoke("ActiveGameoverUI", 1.5f);
		}
		else
		{
			GameObject obj = Instantiate(damagePrefab);
			FloatingUI ui = obj.GetComponent<FloatingUI>();
			ui.SetPos(screenPoint);
		}
	}

	void ActiveGameoverUI()
	{
		scoreUI.SetGameOver();
		Destroy(gameObject);
	}


	private void OnTriggerEnter2D(Collider2D collision)
	{
		if (collision.tag == "Enemy")
		{
			Damaged(1);
		}
	}
}
