using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BikeShield : MonoBehaviour, IBikeElement
{
	public float health = 50.0f;

	public float Damage(float damage)
	{
		health -= damage;
		return health;
	}

	public void Accept(IVisitor visitor)
	{
		visitor.Visit(this);
	}

	void OnGUI()
	{
		GUI.color = Color.green;
		GUI.Label(new Rect(125, 0, 200, 0), "Shield Health: " + health);
	}
}
