using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Player : MonoBehaviour
{
	#region change weapon & consumable
    [SerializeField] public Weapon weaponPrefab;
    [SerializeField] public Consumable consumablePrefab;
    [SerializeField] public int consumableCount;
	private Weapon prevWeaponPrefab;
    private Consumable prevConsumablePrefab;
	#endregion
    private Weapon weapon;
    private Consumable consumable;
	private int mp = 100;
    public int Mp { get { return mp; } set { mp = value; } }
    public event EventHandler OnChangedMp;

    private void Reset()
    {
        weaponPrefab = Resources.Load<Weapon>("Prefabs/Sword");
        consumablePrefab = Resources.Load<Consumable>("Prefabs/Bomb");
        consumableCount = 5;
    }

    void Start()
    {
        Debug.Log("공격: Z키, 소모품 사용: X키");
        weapon = Instantiate(weaponPrefab);
        prevWeaponPrefab = weaponPrefab;
        consumable = Instantiate(consumablePrefab);
        consumable.SetCount(consumableCount);
        prevConsumablePrefab = consumablePrefab;
    }

    void Update()
    {
        #region Function to change weapon & consumable
        if (prevWeaponPrefab != weaponPrefab)
        {
            Debug.Log("웨폰 변경");
            weapon.Destroy();
            weapon = Instantiate(weaponPrefab);
            prevWeaponPrefab = weaponPrefab;
        }
        if(prevConsumablePrefab != consumablePrefab)
        {
            Debug.Log($"소모품 변경: {consumablePrefab.name}");
            if (consumable != null)
                consumable.Destroy();
            consumable = Instantiate(consumablePrefab);
			consumable.SetCount(consumableCount);
			prevConsumablePrefab = consumablePrefab;
        }
        #endregion

        if (Input.GetKeyDown(KeyCode.Z))
        {
            if (weapon.Attack())
            {
			    if (OnChangedMp != null)
				    OnChangedMp(this, EventArgs.Empty);
            }
           
        }
        else if (Input.GetKeyDown(KeyCode.X))
        {
            if (consumable != null)
                consumable.Use();
        }
    }
}

