using System;
using System.Collections;
using System.Collections.Generic;
using Test;
using Unity.PlasticSCM.Editor.WebApi;
using UnityEngine;

namespace Test
{
	public class CharacterCreator : MonoBehaviour
	{
		[SerializeField] CharacterInfo characterInfo;
		string characterName;
		protected EAlignment alignment;
		[SerializeField] protected ECharacterClass characterClass {  get; private set; }

		protected EChance chance;
		CharacterSheet character;
		ECharacterClass prev;

		public void SetCharacterName(string characterName)
		{
			this.characterName = characterName;
		}

		public void SetAlignment(EAlignment alignment)
		{
			this.alignment = alignment;
		}

		public void SetCharacterClass(ECharacterClass characterClass)
		{
			this.characterClass = characterClass;
			
			// Debug.Log(this.characterClass);
		}

		public void SetChance(EChance chance)
		{
			this.chance = chance;
		}

		public void CreateCharacter()
		{
			if (characterName == null)
				return;
			
			//character = new CharacterSheet(characterName, 1, alignment, characterClass, chance);
			
			if ( character == null )
				character = gameObject.AddComponent<CharacterSheet>();
			character.characterName = characterName;
			character.level = 1;
			character.alignment = alignment;
			character.characterClass = characterClass;
			character.chance = chance;
			character.GenerateRandomScores();
			SetCharacterInfo();
		}

		void SetCharacterInfo()
		{
			characterInfo.Name.text = characterName;
			characterInfo.Level.text = character.level.ToString();
			characterInfo.Alignment.text = character.alignment.ToString();
			characterInfo.CharacterClass.text = character.characterClass.ToString();
			characterInfo.Chance.text = character.chance.ToString();
			characterInfo.Strength.text = character.abillity[(int)EAbillity.Strength].ToString();
			characterInfo.Dexterity.text = character.abillity[(int)EAbillity.Dexterity].ToString();
			characterInfo.Intelligence.text = character.abillity[(int)EAbillity.Intelligence].ToString();
			characterInfo.Wisdom.text = character.abillity[(int)EAbillity.Wisdom].ToString();
			characterInfo.Charisma.text = character.abillity[(int)EAbillity.Charisma].ToString();
		}
	}
}

