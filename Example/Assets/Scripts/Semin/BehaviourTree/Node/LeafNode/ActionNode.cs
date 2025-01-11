using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

namespace Semin
{
	public class ActionNode : Node
	{
		Func<INode.ENodeState> act = null;
		
		public ActionNode(Func<INode.ENodeState> onUpdate)
		{
			act = onUpdate;
		}

		public override INode.ENodeState Evaluate()
		{
			Debug.Log("Action Node");
			if (act != null)
				return act.Invoke();
			else return INode.ENodeState.Fail;
		}
	}
}
