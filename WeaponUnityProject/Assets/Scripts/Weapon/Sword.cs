using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sword : Weapon
{
    public void Start()
    {
        Debug.Log("Sword 장착");
        SetWeaponInfo(50.0f, 1.5f, 100, true, 5);
        isActive = true;
    }

    public override bool Attack()
    {
        if (durability > 0 && isActive)
        {
            Debug.Log($"검 공격! 데미지: {strikingPower}, 쿨타임: {cooldown}, 남은 내구도: {durability}");
            StartCoroutine(CoCheckCooldown());
            return true;
        }
        StartCoroutine(CoCheckCooldown());
        return false;
    }
}
