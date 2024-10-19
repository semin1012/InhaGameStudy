using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IAttackable
{
    float StrikingPower { get; set; }
    public bool Attack();
}
