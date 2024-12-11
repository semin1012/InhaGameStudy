using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUp : MonoBehaviour
{
    public PowerUp powerup;
	private void OnTriggerEnter(Collider other)
	{
		if (other.GetComponent<BikeController>())
		{
			other.GetComponent<BikeController>().Accept(powerup);
			Destroy(powerup);
		}
	}
}
