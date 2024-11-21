using System;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class Bird : MonoBehaviour
{
    public float jumpPower = 10.0f;
    public Rigidbody birdRigidbody;
    [SerializeField] public GameObject getScorePrefab;
	[SerializeField] public GameObject gameOverPrefab;
    [SerializeField] public ScoreUI scoreUI;

	void Start()
    {
        birdRigidbody = GetComponent<Rigidbody>();
    }

    void Update()
    {
        if (GameManager.Instance.bGameOver)
            return;

        if (Input.GetKeyDown(KeyCode.Space))
        {
            birdRigidbody.velocity = new Vector3(0, jumpPower, 0);
        }
    }

	private void OnCollisionEnter(Collision collision)
	{
		if (GameManager.Instance.bGameOver)
			return;
		GameManager.Instance.bGameOver = true;
		GameObject obj = Instantiate(gameOverPrefab);
		FloatingUI ui = obj.GetComponent<FloatingUI>();
		Vector3 screenPoint = Camera.main.WorldToScreenPoint(transform.position);
		ui.SetPos(screenPoint);
        Invoke("ActiveGameoverUI", 1.5f);
	}

    void ActiveGameoverUI()
    {
        scoreUI.SetGameOver();
	}

	private void OnTriggerEnter(Collider other)
	{
        if (GameManager.Instance.bGameOver)
            return;
        GameManager.Instance.score += 10;
		GameObject obj = Instantiate(getScorePrefab);
        FloatingUI ui = obj.GetComponent<FloatingUI>();
		Vector3 screenPoint = Camera.main.WorldToScreenPoint(transform.position);
		ui.SetPos(screenPoint);
	}
}
