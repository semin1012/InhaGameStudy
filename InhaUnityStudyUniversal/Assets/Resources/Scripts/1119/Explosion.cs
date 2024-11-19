using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Explosion : MonoBehaviour
{
    private Animator animator;

    public AudioClip getClip;
    private AudioSource audioSource;
    void Start()
    {
        animator = GetComponent<Animator>();
        animator.speed = 2.0f;
        StartCoroutine("Explosion_Time");
        audioSource = GetComponent<AudioSource>();
        PlaySound(getClip);
    }

    IEnumerator Explosion_Time()
    {
        while (animator.GetCurrentAnimatorStateInfo(0).normalizedTime < 1.0f)
            yield return null;
        Destroy(gameObject);
	}

	private void PlaySound(AudioClip clip)
	{
		audioSource.PlayOneShot(clip);
	}
}
