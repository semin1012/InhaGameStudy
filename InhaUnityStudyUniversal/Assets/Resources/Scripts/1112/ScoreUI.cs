using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class ScoreUI : MonoBehaviour
{
    [SerializeField] public TextMeshProUGUI text;
    [SerializeField] public Button button;
    
    void Start()
    {
        text.text = "0";
		button.gameObject.SetActive(false); 
	}

    // Update is called once per frame
    void Update()
    {
        text.text = GameManager.Instance.score.ToString();
    }

    public void SetGameOver()
    {
        button.gameObject.SetActive(true);
    }
}
