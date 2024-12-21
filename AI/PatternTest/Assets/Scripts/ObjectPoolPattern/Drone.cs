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
	private RaycastHit _hit;
	private Vector3 _rayDirection;
	private float _rayAngle = -45.0f;
	private float _rayDistance = 15.0f;

	public float speed = 1.0f;
	public float maxHeight = 5.0f;
	public float weavingDistance = 1.5f;
	public float fallbackDistance = 20.0f;


	private void Start()
	{
        _currentHealth = maxHealth;

		_rayDirection = transform.TransformDirection(Vector3.back) * _rayDistance;
		_rayDirection = Quaternion.Euler(_rayAngle, 0.0f, 0f) * _rayDirection;
	}

	private void Update()
	{
		Debug.DrawRay(transform.position, _rayDirection, Color.blue);

		if (Physics.Raycast(transform.position, _rayDirection, out _hit, _rayDistance))
		{
			if (_hit.collider)
				Debug.DrawRay(transform.position, _rayDirection, Color.green);
		}
	}

	public void ApplyStrategy(IManeuverBehaviour strategy)
	{
		strategy.Maneuver(this);
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
