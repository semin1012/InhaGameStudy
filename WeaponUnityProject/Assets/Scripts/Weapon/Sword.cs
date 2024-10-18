using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sword : Weapon
{
    public void Start()
    {
        Debug.Log("Sword ����");
        SetWeaponInfo(50.0f, 1.5f, 100, true, 5);
        isActive = true;
    }

    public override bool Attack()
    {
        if (durability > 0 && isActive)
        {
            Debug.Log($"�� ����! ������: {strikingPower}, ��Ÿ��: {cooldown}, ���� ������: {durability}");
            StartCoroutine(CoCheckCooldown());
            return true;
        }
        StartCoroutine(CoCheckCooldown());
        return false;
    }
}
