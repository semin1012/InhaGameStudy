using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Semin
{
	public abstract class Node : ScriptableObject, INode
	{
		public string guid;
		public Vector2 position;

		public abstract INode.ENodeState Evaluate();
	}


}