using System;
using System.Collections;
using System.Collections.Generic;
using Test;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

namespace Test
{
	public class DropdownAlignment : MonoBehaviour
	{
		[SerializeField] TMP_Dropdown dropdown;
		[SerializeField] bool isClass;
		[SerializeField] bool isAlignment;
		[SerializeField] bool isChance;
		[SerializeField] CharacterCreator characterCreator;

		private void Reset()
		{
			if (this.gameObject.name == "Class")
			{
				isClass = true;
			}
			else if ( this.gameObject.name == "Alignment")
			{
				isAlignment = true;
			}
			else if (this.gameObject.name == "Chance")
			{
				isChance = true; 
			}

			dropdown = GetComponent<TMP_Dropdown>();

			if (dropdown.options.Count != 0)
				return;

			#region SetList
			if (isAlignment)
			{	
				foreach (string name in Enum.GetNames(typeof(EAlignment)))
				{
					if (name == "Max")
						break;

					TMP_Dropdown.OptionData option = new TMP_Dropdown.OptionData();
					option.text = name;
					dropdown.options.Add(option);
				}
			}

			if (isClass)
			{
				foreach (string name in Enum.GetNames(typeof(ECharacterClass)))
				{
					if (name == "Max")
						break;

					TMP_Dropdown.OptionData option = new TMP_Dropdown.OptionData();
					option.text = name;
					dropdown.options.Add(option);
				}
			}

			if (isChance)
			{
				foreach (string name in Enum.GetNames(typeof(EChance)))
				{
					if (name == "Max")
						break;

					TMP_Dropdown.OptionData option = new TMP_Dropdown.OptionData();
					option.text = name;
					dropdown.options.Add(option);
				}
			}
			#endregion
		}


		public void OnDropdownEvent(int index)
		{
			if (isAlignment)
			{
				characterCreator.SetAlignment((EAlignment)Enum.ToObject(typeof(EAlignment), dropdown.value));
			}
			else if (isClass)
			{
				characterCreator.SetCharacterClass((ECharacterClass)Enum.ToObject(typeof(ECharacterClass), dropdown.value));
			}
			else if (isChance)
			{
				characterCreator.SetChance((EChance)Enum.ToObject(typeof(EChance), dropdown.value));
			}
		}
	}

}
