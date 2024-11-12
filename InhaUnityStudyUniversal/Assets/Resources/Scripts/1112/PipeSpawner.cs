using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeSpawner : MonoBehaviour
{
    public GameObject pipePrefab;
    public float interval = 1.0f;
    public float range = 2.5f;

	private void Start()
	{
		StartCoroutine("SpawnPipe");
	}

	IEnumerator SpawnPipe()
    {
        while (true)
        {
            yield return new WaitForSeconds(interval);            
            Instantiate(pipePrefab, new Vector3(transform.position.x, Random.Range(-range, range), transform.position.z), transform.rotation);
        }
    }
}
