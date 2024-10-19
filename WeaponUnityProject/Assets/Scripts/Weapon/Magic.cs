using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Magic : Weapon
{
    private int mpAmount;
    public int MpAmount { get { return mpAmount; } }
    public void Start()
    {
        Debug.Log("마법 장착");
        SetWeaponInfo(90f, 2.5f, 0, false, 0, 10);
        Player player = FindObjectOfType<Player>();
        player.OnChangedMp -= OnChangedMp;
        player.OnChangedMp += OnChangedMp;
    }
    public void SetWeaponInfo(float strikingPower, float cooldown, int durability, bool isConsumable, int durabilityAmount, int mpAmount)
    {
        SetWeaponInfo(strikingPower, cooldown, durability, isConsumable, durabilityAmount);
        this.mpAmount = mpAmount;
    }

    public override bool Attack()
	{
		Player player = FindObjectOfType<Player>();
        if ( player.Mp < mpAmount)
        {
            Debug.Log("MP가 부족합니다.");
            return false;
        }
        if (isActive)
        {
            Debug.Log($"마법 공격! 데미지: {strikingPower}, 쿨타임: {cooldown}");
            StartCoroutine(CoCheckCooldown());
            return true;
        }
        StartCoroutine(CoCheckCooldown());
        return false;
    }

    private void OnChangedMp(object sender, EventArgs eventArgs)
    {
        Player player = sender as Player;
        if (player != null)
        {
            player.Mp -= mpAmount;
			Debug.Log($"플레이어 MP: {player.Mp}");
		}
    }
}
