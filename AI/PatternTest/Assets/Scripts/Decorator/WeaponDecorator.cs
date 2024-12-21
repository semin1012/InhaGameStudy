using System.Collections;
using System.Collections.Generic;
using UnityEngine;


namespace Chapter.Decorator
{
	public class WeaponDecorator : IWeapon
	{
		private readonly IWeapon _decorateWeapon;
		private readonly WeaponAttachment _attachment;

		public WeaponDecorator(IWeapon weapon, WeaponAttachment attachment)
		{
			_attachment = attachment;
			_decorateWeapon = weapon;
		}

		public float Rate
		{
			get { return _decorateWeapon.Rate; }
		}

		public float Range
		{
			get { return _decorateWeapon.Range; }
		}

		public float Strength
		{
			get { return _decorateWeapon.Strength; }
		}

		public float Cooldown
		{
			get { return _decorateWeapon.Cooldown; }
		}
	}
}
