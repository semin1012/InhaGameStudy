using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow : Consumable
{
    private void Start()
    {
        SetConsumableInfo(30f, 100f, 0.2f);
    }

    public override void Use()
    {
        Debug.Log($"Ȱ ���! ��Ÿ� {intersection}m ���� ������ {strikingPower}�� �������� �־����ϴ�. ��Ÿ��: {cooldown}");
        return;
    }
}
