using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClientObjectPool : MonoBehaviour
{
	private ObjPool<Drone> _pool;

	private void Start()
	{
		_pool = new ObjPool<Drone>();
		Debug.Log(_pool);
	}

	private void OnGUI()
	{
		if (GUILayout.Button("Spawn Drones"))
			_pool.Spawn();
	}
}
