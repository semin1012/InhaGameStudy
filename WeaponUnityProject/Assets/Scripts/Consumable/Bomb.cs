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
        Debug.Log($"폭탄 사용! 사거리 {intersection}m 내의 적들에게 {strikingPower}의 데미지를 주었습니다. 쿨타임: {cooldown}");
        return;
    }
}
