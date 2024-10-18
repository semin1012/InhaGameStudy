using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Player : MonoBehaviour
{
    [SerializeField] public Weapon weaponPrefab;
    [SerializeField] public Consumable consumablePrefab;
    [SerializeField] public int consumableCount;
    private Weapon prevWeaponPrefab;
    private Weapon weapon;
    private Consumable prevConsumablePrefab;
    private Consumable consumable;
    private int mp = 100;
    private bool canUseConsumable = true;

    public int Mp
    {
        get { return mp; }
        set { mp = value; }
    }
    public event EventHandler OnChangedMp;

    private void Reset()
    {
        weaponPrefab = Resources.Load<Weapon>("Prefabs/Sword");
        consumablePrefab = Resources.Load<Consumable>("Prefabs/Bomb");
        consumableCount = 5;
    }

    void Start()
    {
        Debug.Log("����: ZŰ, �Ҹ�ǰ ���: XŰ");
        weapon = Instantiate(weaponPrefab);
        prevWeaponPrefab = weaponPrefab;
        consumable = Instantiate(consumablePrefab);
        prevConsumablePrefab = consumablePrefab;
    }

    void Update()
    {
        #region Function to change weapon & consumable
        if (prevWeaponPrefab != weaponPrefab)
        {
            Debug.Log("���� ����");
            weapon.Destroy();
            weapon = Instantiate(weaponPrefab);
            prevWeaponPrefab = weaponPrefab;
        }
        if(prevConsumablePrefab != consumablePrefab)
        {
            Debug.Log($"�Ҹ�ǰ ����: {consumablePrefab.name}");
            if (consumable != null)
                consumable.Destroy();
            consumable = Instantiate(consumablePrefab);
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
            UseConsumable();
        }
    }

    private IEnumerator CoStartConsumableCooldown()
    {
        canUseConsumable = false;
        yield return new WaitForSeconds(consumable.Cooldown);
        canUseConsumable = true;
    }

    private void UseConsumable()
    {
        if (canUseConsumable)
        {
            if (consumableCount > 0)
            {
                consumable.Use();
                StartCoroutine(CoStartConsumableCooldown());
                consumableCount--;
                if (consumableCount == 0)
                {
                    Debug.Log($"{consumablePrefab.name}�� ��� ����߽��ϴ�.");
                    consumable.Destroy();
                    consumable = null;
                }
            }
        }
        else
        {
            if (consumable != null)
                Debug.Log($"{consumablePrefab.name}�� ��Ÿ���� ���ҽ��ϴ�.");
        }
    }
}
