using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coin : MonoBehaviour
{
    public AudioClip getClip;
    public float maxSpeed = 100.0f;
    private Rigidbody2D rigidBody;
    private AudioSource audioSource;

    void Start()
    {
		audioSource = GetComponent<AudioSource>();
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
		if (collision.tag == "Player")
        {
            GameManager.Instance.score += 100;
            Destroy(gameObject, 0.3f);
            PlaySound(getClip);
        }
	}

    private void PlaySound(AudioClip clip)
    {
        audioSource.PlayOneShot(clip);
    }
}
