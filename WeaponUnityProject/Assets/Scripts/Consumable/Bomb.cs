using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bomb : AttackConsumable
{
    private void Start()
    {
        SetConsumableInfo(100f, 30f, 1f);
    }

    public override bool Use()
    {
        return base.Use();
    }

    public override bool Attack()
	{
		Debug.Log($"��ź ���! ��Ÿ� {intersection}m ���� ���鿡�� {strikingPower}�� �������� �־����ϴ�. ��Ÿ��: {cooldown}");
        return true;
	}
}
