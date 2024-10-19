using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow : AttackConsumable
{
    private void Start()
    {
        SetConsumableInfo(30f, 100f, 0.2f);
    }

    public override bool Use()
	{
		return base.Use();
    }

	public override bool Attack()
	{
		Debug.Log($"활 사용! 사거리 {intersection}m 내의 적에게 {strikingPower}의 데미지를 주었습니다. 쿨타임: {cooldown}");
		return true;
	}
}

