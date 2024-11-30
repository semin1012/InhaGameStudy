using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;

public class ObjPool<T> : MonoBehaviour where T : Obj<T>
{
	public int maxPoolSize = 10;
	public int stackDefaultCapacity = 10;
	public GameObject par = null;

	public IObjectPool<T> Pool
	{
		get
		{
			if (_pool == null)
				_pool = new ObjectPool<T>(
					CreatedPooledItem,
					OnTakeFromPool, 
					OnReturnedToPool,
					OnDestroyPoolObject,
					true,
					stackDefaultCapacity,
					maxPoolSize);
			return _pool;
		}
	}

	private IObjectPool<T> _pool;

	private T CreatedPooledItem()
	{
		var go = GameObject.CreatePrimitive(PrimitiveType.Cube);
		T obj = go.AddComponent<T>();
		go.name = obj.GetType().ToString();
		if (par == null)
			par = new GameObject("@" + obj.GetType().ToString());
		go.transform.parent = par.transform;
		obj.Pool = Pool;
		return obj;
	}

	private void OnReturnedToPool(T obj)
	{
		obj.gameObject.SetActive(false);
	}

	private void OnTakeFromPool(T obj)
	{
		obj.gameObject.SetActive(true);
	}

	private void OnDestroyPoolObject(T obj)
	{
		Object.Destroy(obj.gameObject);
	}

	public void Spawn()
	{
		var amount = Random.Range(1, 10);	
		for ( int i =0; i < amount; ++i)
		{
			var obj = Pool.Get();
			obj.transform.position = Random.insideUnitSphere * 10;
		}
	}
}
