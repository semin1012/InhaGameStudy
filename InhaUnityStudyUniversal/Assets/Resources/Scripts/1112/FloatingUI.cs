using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class FloatingUI : MonoBehaviour
{
    [SerializeField] public TextMeshProUGUI getScore;
    public int speed = 20;
    
	void Update()
    {
        getScore.alpha -= Time.deltaTime;
        getScore.transform.position += new Vector3(0, Time.deltaTime * speed, 0);
		if ( getScore.alpha <= 0 )
            Destroy(gameObject);
	}
	public void SetPos(Vector3 pos)
	{
		getScore.transform.position = new Vector3(getScore.transform.position.x, pos.y, getScore.transform.position.z);
	}
}
