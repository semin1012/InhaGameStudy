using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class AttackConsumable : Consumable, IAttackable
{
	protected float strikingPower;
	public float StrikingPower { get { return strikingPower; } set { strikingPower = value; } }
	protected float intersection;

	public virtual void SetConsumableInfo(float strikingPower, float intersection, float cooldown)
	{
		base.SetConsumableInfo(cooldown);
		this.strikingPower = strikingPower;
		this.intersection = intersection;
	}
	public override bool Use()
	{
		if (base.Use())
		{
			Attack();
			return true;
		}
		return false;
	}

	abstract public bool Attack();
}

