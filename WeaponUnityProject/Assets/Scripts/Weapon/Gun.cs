using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : Weapon
{
    int ammoCount;

    public void Start()
    {
        Debug.Log("�� ����");
        SetWeaponInfo(30f, 0.5f, 100, true, 3);
    }

    public override void SetWeaponInfo(float strikingPower, float cooldown, int durability, bool isConsumable, int durabilityAmount)
    {
        base.SetWeaponInfo(strikingPower, cooldown, durability, isConsumable, durabilityAmount);
        ammoCount = 35;
    }

    public override bool Attack()
    {
        if (ammoCount <= 0)
        {
            Debug.Log("�Ѿ��� �����մϴ�.");
            return false;
        }
        if (isActive && isActive)
        {
            ammoCount--;
            Debug.Log($"�� ����! ������: {strikingPower}, ��Ÿ��: {cooldown}, ���� ������: {durability}, ���� �Ѿ�: {ammoCount}");
            StartCoroutine(CoCheckCooldown());
            return true;
        }
        StartCoroutine(CoCheckCooldown());
        return false;
    }
}
