using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;
using UnityEngine.AI;

public class GameDirector : MonoBehaviour
{
    GameObject timerText;
    GameObject pointText;
    TextMeshProUGUI timerTextMesh;
	TextMeshProUGUI pointTextMesh;
    int point = 0;
    GameObject generator;
    ItemGenerator itemGenerator;

	int interval = 1;	// 0은 게임 끝, 1은 5초까지, 2는 10초까지, 3은 20초, 4는 30초까지

	public float time = 30.0f;
	public float[] span;
	public float[] speed;
	public int[] ratio;

    public void GetApple()
    {
        this.point += 100;
    }

    public void GetBomb()
    {
        this.point /= 2;
    }

    void Start()
    {
        this.timerText = GameObject.Find("Time");
        this.timerTextMesh = this.timerText.GetComponent<TextMeshProUGUI>();
        this.pointText = GameObject.Find("Point");
		this.pointTextMesh = this.pointText.GetComponent<TextMeshProUGUI>();
        this.generator = GameObject.Find("ItemGenerator");
		this.itemGenerator = this.generator.GetComponent<ItemGenerator>();
	}

    // Update is called once per frame
    void Update()
    {
        this.time -= Time.deltaTime;

        if ( this.time < 0)
        {
			this.time = 0;
			itemGenerator.SetParmeter(10000.0f, 0, 0);
		}
        else if (this.time < 5 )
		{
			interval = 3;
		}
		else if (this.time < 10)
		{
			interval = 2;
		}
		else if (this.time < 20)
		{
			interval = 1;
		}
		else if (this.time < 30)
		{
			interval = 0;
		}

		if ( this.time != 0 )
		{
			itemGenerator.SetParmeter(span[interval], speed[interval], ratio[interval]);
		}


		this.timerTextMesh.text = this.time.ToString("F1");
		this.pointTextMesh.text = this.point.ToString() + " point";
	}
}
