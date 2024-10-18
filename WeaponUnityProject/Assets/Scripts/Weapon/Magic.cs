using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Magic : Weapon
{
    private int mpAmount;

    public void Start()
    {
        Debug.Log("���� ���");
        SetWeaponInfo(90f, 2.5f, 0, false, 0);

        Player player = FindObjectOfType<Player>();
        player.OnChangedMp -= OnChangedMp;
        player.OnChangedMp += OnChangedMp;
    }

    public override void SetWeaponInfo(float strikingPower, float cooldown, int durability, bool isConsumable, int durabilityAmount)
    {
        base.SetWeaponInfo(strikingPower, cooldown, durability, isConsumable, durabilityAmount);
        mpAmount = 10;
    }

    public override bool Attack()
    {
        Player player = FindObjectOfType<Player>();
        if (player.Mp < mpAmount)
        {
            Debug.Log("Mp�� �����մϴ�.");
            return false;
        }
        if (isActive)
        {
            Debug.Log($"���� ����! ������: {strikingPower}, ��Ÿ��: {cooldown}");
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
        }
        Debug.Log($"�÷��̾� MP: {player.Mp}");
    }
}
