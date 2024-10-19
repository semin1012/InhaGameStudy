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
		Debug.Log($"Ȱ ���! ��Ÿ� {intersection}m ���� ������ {strikingPower}�� �������� �־����ϴ�. ��Ÿ��: {cooldown}");
		return true;
	}
}

