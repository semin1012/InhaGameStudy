using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

namespace Chapter.Adapter
{
	public interface IInventorySystem
	{
		void SyncInventories();
		void AddItem(InventoryItem item, SaveLocation location);
		void RemoveItem(InventoryItem item, SaveLocation location);
		List<InventoryItem> GetInventory(SaveLocation location);
	}

}
