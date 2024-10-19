using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public abstract class Consumable : MonoBehaviour, IUsable
{
    protected float cooldown;
    protected int count;
    private bool canUseConsumable;
	private IEnumerator CoStartConsumableCooldown()
	{
		canUseConsumable = false;
		yield return new WaitForSeconds(cooldown);
		canUseConsumable = true;
	}
	public virtual void SetConsumableInfo(float cooldown)
    {
        this.cooldown = cooldown;
		canUseConsumable = true;

	}
    public void SetCount(int count)
    {
        this.count = count; 
    }

    virtual public bool Use()
    {
		if (canUseConsumable)
		{
			count--;
			if (count <= 0)
			{
				Debug.Log($"{gameObject.name}을 모두 사용했습니다.");
				Destroy();
				return true;
			}
			Debug.Log($"{gameObject.name}의 남은 개수: {count}");
			StartCoroutine(CoStartConsumableCooldown());
			return true;
		}
		else
		{
			Debug.Log($"{gameObject.name}의 쿨타임이 남았습니다.");
			return false;
		}
    }

    public void Destroy()
    {
        Destroy(gameObject);
    }
}
