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
        // Invoke("SpawnPipe2", 1.0f); // 한번만 실행 
        //InvokeRepeating("SpawnPipe2", 1.0f, 1.0f);  // 반복 실행 Name, Delay Time, Repeat Time
	}

	IEnumerator SpawnPipe()
    {
        while (true)
        {
            yield return new WaitForSeconds(interval);            
            Instantiate(pipePrefab, new Vector3(transform.position.x, Random.Range(-range, range), transform.position.z), transform.rotation);
        }
    }

    void SpawnPipe2()
    {
        Debug.Log("<color=red>Spawn Pipe</color>");
    }
}
