using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class ScoreUI : MonoBehaviour
{
    [SerializeField] public TextMeshProUGUI text;
    [SerializeField] public Button button;
	[SerializeField] public GameObject bestScore;
	[SerializeField] public GameObject[] hearts;

	private void Reset()
	{
        text = GameObject.Find("Num").GetComponent<TextMeshProUGUI>();
        button = GameObject.Find("ReplayButton").GetComponent<Button>();
        bestScore = GameObject.Find("BestScore").GetComponent<GameObject>();
        hearts = GameObject.FindGameObjectsWithTag("Heart");
	}

	void Start()
    {
        text.text = "0";
		button.gameObject.SetActive(false);
        bestScore.SetActive(false);
        hearts = GameObject.FindGameObjectsWithTag("Heart");
	}

    // Update is called once per frame
    void Update()
    {
        text.text = GameManager.Instance.score.ToString();
    }

    public void SetHp(int curHp)
    {
        for(int i = 0; i < hearts.Count(); i++)
        {
            if ( i < curHp)
                hearts[i].GetComponent<SpriteRenderer>().gameObject.SetActive(true);
            else
				hearts[i].GetComponent<SpriteRenderer>().gameObject.SetActive(false);
		}
    }

    public void SetGameOver()
    {
        button.gameObject.SetActive(true);
        bestScore.gameObject.SetActive(true);
        TextMeshProUGUI text = bestScore.transform.Find("Text").GetComponent<TextMeshProUGUI>();
        text.text = "최고 점수: " + GameManager.Instance.bestScore.ToString();
    }
}
