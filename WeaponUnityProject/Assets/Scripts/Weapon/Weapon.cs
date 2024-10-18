using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Weapon : MonoBehaviour
{
    protected float strikingPower;
    protected float cooldown;
    protected int durability;
    protected bool isConsumable;
    protected bool isActive;
    protected int durabilityAmount;

    public virtual void SetWeaponInfo(float strikingPower, float cooldown, int durability, bool isConsumable, int durabilityAmount)
    {
        this.strikingPower = strikingPower;
        this.cooldown = cooldown;
        this.durability = durability;
        this.isConsumable = isConsumable;
        this.durabilityAmount = durabilityAmount;
        isActive = true;
    }

    protected IEnumerator CoCheckCooldown()
    {
        if (isActive == false)
        {
            Debug.Log("��Ÿ���� ���� ���Դϴ�.");
            yield break;
        }
        if (isConsumable)
        {
            durability -= durabilityAmount;
            if (durability < 0)
            {
                durability = 0;
                Debug.Log($"�������� {durability}�Դϴ�. ��� �Ұ����մϴ�.");
                yield break;
            }
        }
        isActive = false;
        yield return new WaitForSeconds(cooldown);
        isActive = true;
    }

    abstract public bool Attack();
    public bool GetIsConsumable()
    {
        return isConsumable;
    }
    public void Destroy()
    {
        Destroy(gameObject);
    }
}
