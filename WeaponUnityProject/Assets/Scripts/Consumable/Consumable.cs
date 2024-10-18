using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Consumable : MonoBehaviour
{
    protected float strikingPower;
    protected float intersection;
    protected float cooldown;
    public float Cooldown
    {
        get { return cooldown; }
    }

    public virtual void SetConsumableInfo(float strikingPower, float intersection, float cooldown)
    {
        this.strikingPower = strikingPower;
        this.intersection = intersection;
        this.cooldown = cooldown;
    }

    abstract public void Use();

    public void Destroy()
    {
        Destroy(gameObject);
    }
}
