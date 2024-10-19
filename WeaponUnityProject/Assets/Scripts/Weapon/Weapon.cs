using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Weapon : MonoBehaviour, IAttackable
{
	protected float strikingPower;
	public float StrikingPower { get { return strikingPower; } set { strikingPower = value; } }
    protected float cooldown;
    protected int durability;
    protected bool isConsumable;
    protected bool isActive;
    protected int durabilityAmount;
	public void SetWeaponInfo(float strikingPower, float cooldown, int durability, bool isConsumable, int durabilityAmount)
    {
		StrikingPower = strikingPower;
        this.cooldown = cooldown;
        this.durability = durability;
        this.isConsumable = isConsumable;
        this.durabilityAmount = durabilityAmount;
        isActive = true;
	}
	abstract public bool Attack();
	protected IEnumerator CoCheckCooldown()
    {
        if (isActive == false)
        {
            Debug.Log("쿨타임이 진행 중입니다.");
            yield break;
        }
        if (isConsumable)
        {
            durability -= durabilityAmount;
            if (durability < 0)
            {
                durability = 0;
                Debug.Log($"내구도가 {durability}입니다. 사용 불가능합니다.");
                yield break;
            }
        }
        isActive = false;
        yield return new WaitForSeconds(cooldown);
        isActive = true;
    }
    public void Destroy()
    {
        Destroy(gameObject);
    }
}
