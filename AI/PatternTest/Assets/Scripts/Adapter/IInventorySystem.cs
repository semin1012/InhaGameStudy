using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Chapter.Adapter
{
	public interface IInventorySystem
	{
		void SyncInventories();
		void AddItem(InventoryItem item, SaveLocation location);

	}

}
