using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : Weapon
{
    int ammoCount;

    public void Start()
    {
        Debug.Log("ÃÑ ÀåÂø");
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
            Debug.Log("ÃÑ¾ËÀÌ ºÎÁ·ÇÕ´Ï´Ù.");
            return false;
        }
        if (isActive && isActive)
        {
            ammoCount--;
            Debug.Log($"ÃÑ °ø°Ý! µ¥¹ÌÁö: {strikingPower}, ÄðÅ¸ÀÓ: {cooldown}, ³²Àº ³»±¸µµ: {durability}, ³²Àº ÃÑ¾Ë: {ammoCount}");
            StartCoroutine(CoCheckCooldown());
            return true;
        }
        StartCoroutine(CoCheckCooldown());
        return false;
    }
}
