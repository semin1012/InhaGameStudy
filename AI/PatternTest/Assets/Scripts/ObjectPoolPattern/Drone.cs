using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;

public class Drone : Obj<Drone>
{
    public float _currentHealth;
    [SerializeField] 
    private float maxHealth = 100.0f;
    [SerializeField]
    private float timeToSelfDestruct = 3.0f;

	private void Start()
	{
        _currentHealth = maxHealth;
	}

	private void OnEnable()
	{
		AttackPlayer();
		StartCoroutine(SelfDestruct());
	}
	private void OnDisable()
	{
		ResetDrone();
	}

	IEnumerator SelfDestruct()
	{
		yield return new WaitForSeconds(timeToSelfDestruct);
		TakeDamage(maxHealth);
	}

	private void ReturnToPool()
	{
		Pool.Release(this);
	}

	private void ResetDrone()
	{
		_currentHealth = maxHealth;
	}

	public void AttackPlayer()
	{
		Debug.Log("Attack Player!");
	}


	public void TakeDamage(float damage)
	{
		_currentHealth -= damage;

		if (_currentHealth <= 0.0f)
			ReturnToPool();
	}
}
