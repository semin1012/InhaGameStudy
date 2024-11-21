using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
	public GameObject enemyPrdfab;
	public float interval = 1.0f;
	public float range = 200.0f;
	public Player2D player;

	IEnumerator Start()
	{

		while (true)
		{
			yield return new WaitForSeconds(interval);

			Vector3 pos = new Vector3(transform.position.x,
				Random.Range(-range, range),
				transform.position.z);

			GameObject obj = Instantiate(enemyPrdfab, pos, transform.rotation);
			Enemy2D enemy = obj.GetComponent<Enemy2D>();
			if ( enemy != null ) 
				enemy.player = player;
		}
	}
}
