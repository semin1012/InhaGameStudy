using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CloudSpawner : MonoBehaviour
{
    public GameObject cloudPrefab;
    public float interval = 3.0f;
    public float range = 200.0f;

    IEnumerator Start()
    {
        while (true)
        {
            yield return new WaitForSeconds(interval);
            GameObject obj = Instantiate(cloudPrefab);
            float randomRange = Random.Range(-range, range);
            obj.transform.position = new Vector2(transform.position.x, obj.transform.position.y + randomRange);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
