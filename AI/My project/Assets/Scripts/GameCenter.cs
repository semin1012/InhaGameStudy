using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameCenter : MonoBehaviour
{
    // Start is called before the first frame update
    GameObject car;
    GameObject flag;
    GameObject distance;
    void Start()
    {
        this.car = GameObject.Find("car");
        this.flag = GameObject.Find("flag");
        this.distance = GameObject.Find("Distance");
    }

    // Update is called once per frame
    void Update()
    {
        float length = this.flag.transform.position.x - this.car.transform.position.x;
        if ( length >= 0 )
        {
            this.distance.GetComponent<TextMeshProUGUI>().text = "Distance" + length.ToString("F2") + "m";
		}
        else
        {
            this.distance.GetComponent<TextMeshProUGUI>().text = "GameOver";
        }
    }
}
