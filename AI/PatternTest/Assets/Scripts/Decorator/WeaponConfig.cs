using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.Decorator
{
	[CreateAssetMenu(fileName = "NewWeaponConfig", menuName = "Weapon/Config", order = 1)]
	public class WeaponConfig : ScriptableObject, IWeapon
	{
		[Range(0, 60)]
		[Tooltip("Rate of firing per second")]
		[SerializeField]
		private float rate;

		[Range(0, 50)]
		[Tooltip("Weapon Range")]
		[SerializeField]
		private float range;

		[Range(0, 100)]
		[Tooltip("Weapon Strength")]
		[SerializeField]
		private float strength;

		[Range(0, 5)]
		[Tooltip("Cooldown duration")]
		[SerializeField]
		private float cooldown;

		public string weaponName;
		public GameObject weaponPrefab;
		public string weaponDescription;

		public float Range
		{
			get { return range; }
		}

		public float Rate
		{
			get { return rate; }
		}
		public float Strength
		{
			get { return strength; }
		}

		public float Cooldown
		{
			get { return cooldown; }
		}
	}
}

