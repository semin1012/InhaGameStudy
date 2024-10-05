using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

public class CharacterInfo : MonoBehaviour
{
	[SerializeField] public TMP_InputField Name;
	[SerializeField] public TMP_InputField Level;
	[SerializeField] public TMP_InputField Alignment;
	[SerializeField] public TMP_InputField CharacterClass;
	[SerializeField] public TMP_InputField Chance;
	[SerializeField] public TMP_InputField Strength;
	[SerializeField] public TMP_InputField Dexterity;
	[SerializeField] public TMP_InputField Intelligence;
	[SerializeField] public TMP_InputField Wisdom;
	[SerializeField] public TMP_InputField Charisma;

	private void Reset()
	{
		Transform[] allChildren = GetComponentsInChildren<Transform>();
		foreach (Transform child in allChildren)
		{
			switch(child.name)
			{
				case "Name":
					Name = child.GetComponent<TMP_InputField>();
					break;
				case "Level":
					Level = child.GetComponent<TMP_InputField>();
					break;
				case "Alignment":
					Alignment = child.GetComponent<TMP_InputField>();
					break;
				case "CharacterClass":
					CharacterClass = child.GetComponent<TMP_InputField>();
					break;
				case "Chance":
					Chance = child.GetComponent<TMP_InputField>();
					break;
				case "Strength":
					Strength = child.GetComponent<TMP_InputField>();
					break;
				case "Dexterity":
					Dexterity = child.GetComponent<TMP_InputField>();
					break;
				case "Intelligence":
					Intelligence = child.GetComponent<TMP_InputField>();
					break;
				case "Wisdom":
					Wisdom = child.GetComponent<TMP_InputField>();
					break;
				case "Charisma":
					Charisma = child.GetComponent<TMP_InputField>();
					break;
			}
		}
	}
}
