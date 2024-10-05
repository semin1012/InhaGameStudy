using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.TextCore.Text;

namespace Test
{
	public enum EAlignment
	{
		LawfulGood = 0,
		NeutralGood,
		ChaoticGood,
		LawfulNeutral,
		TrueNeutral,
		ChaoticNeutral,
		LawfulEvil,
		NeutralEvil,
		ChaoticEvil,
		Max,
	}

	public enum ECharacterClass
	{
		Knight,
		Archer,
		Magician,
	}

	public enum EChance
	{
		SpellSavingThrow,
		PoisonSavingThrow,
		MagicWandSavingThrow,
		ArrowSavingThrow,
		Max,
	}

	public enum EAbillity
	{
		Strength = 0,
		Dexterity,
		Intelligence,
		Wisdom,
		Charisma,
		Max,
	}

	public class CharacterSheet : MonoBehaviour
	{
		public string			characterName;
		public int				level;
		public EAlignment		alignment;
		public ECharacterClass	characterClass;
		public EChance			chance;
		public int[]			abillity;

		public CharacterSheet(string characterName, int level, EAlignment alignment, ECharacterClass characterClass, EChance chance)
		{
			this.characterName = characterName;
			this.level = level;
			this.alignment = alignment;
			this.characterClass = characterClass;
			this.chance = chance;
		}

		private void Start()
		{
			GenerateRandomScores();
		}

		void ClearSheet()
		{
			Destroy(this);
		}

		public void GenerateRandomScores()
		{
			 abillity = new int[(int)EAbillity.Max];

			for ( int i = 0; i < (int)EAbillity.Max; i++ )
			{
				int result = 0;

				for ( int j = 0; j < 4; j++ )
					result += Random.Range(1, 7);
				float temp = result / 1.75f;
				temp += 2;
				result = (int)temp;
				if (result < 3)
					result = 3;

				abillity[i] = result;
			}
		}
	}

}
