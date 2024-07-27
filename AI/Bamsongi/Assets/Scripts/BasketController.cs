using System.Collections;
using System.Collections.Generic;
using UnityEngine;

static class ItemType
{
    public const string APPLE = "Apple";
	public const string BOMB = "Bomb";
}

public class BasketController : MonoBehaviour
{
    public AudioClip appleSE;
    public AudioClip bombSE;
    AudioSource aud;
    GameObject director;

    void Start()
    {
        Application.targetFrameRate = 60;
        this.aud = GetComponent<AudioSource>();
        this.director = GameObject.Find("GameDirector");
    }

	void OnTriggerEnter(Collider other)
	{
        switch( other.tag )
        {
            case ItemType.APPLE:
				this.aud.PlayOneShot(this.appleSE);
				this.director.GetComponent<GameDirector>().GetApple();
				break;
            case ItemType.BOMB:
				this.aud.PlayOneShot(this.bombSE);
				this.director.GetComponent<GameDirector>().GetBomb();
				break;
        } 

        Destroy(other.gameObject);
	}

	void Update()
    {
        if ( Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if ( Physics.Raycast(ray, out hit, Mathf.Infinity) )
            {
                float x = Mathf.RoundToInt(hit.point.x);
                float z = Mathf.RoundToInt(hit.point.z);
                transform.position = new Vector3(x, 0, z);
            }
        }
    }
}
