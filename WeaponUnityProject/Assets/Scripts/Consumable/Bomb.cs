using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bomb : Consumable
{
    private void Start()
    {
        SetConsumableInfo(100f, 30f, 1f);
    }

    public override void Use()
    {
        Debug.Log($"��ź ���! ��Ÿ� {intersection}m ���� ���鿡�� {strikingPower}�� �������� �־����ϴ�. ��Ÿ��: {cooldown}");
        return;
    }
}
