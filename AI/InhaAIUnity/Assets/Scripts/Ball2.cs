using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBall : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("시작");
    }

	private void FixedUpdate()
	{
		this.transform.Rotate(new Vector3(1, 1, 1));
	}

	// Update is called once per frame
	void Update()
	{

	}
}
