using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameButton : MonoBehaviour
{
	public AudioClip onMouseEnterSound;
	public AudioClip onMouseDownSound;
	private AudioSource audioSource;

	private void Start()
	{
		audioSource = GetComponent<AudioSource>();
	}

	public void GameStart()
	{
		GameManager.Instance.GameStart();
	}

	public void Restart()
	{
		GameManager.Instance.Restart();
	}

	public void OnMouseEnterEvent()
	{
		PlaySound(onMouseEnterSound);
	}

	public void OnMouseDownEvent()
	{
		PlaySound(onMouseEnterSound);
	}

	public void GameExit()
	{
		Application.Quit();
	}

	private void PlaySound(AudioClip clip)
	{
		audioSource.PlayOneShot(clip);
	}
}
