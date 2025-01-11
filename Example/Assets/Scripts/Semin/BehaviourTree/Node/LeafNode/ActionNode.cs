using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.Events;

namespace Semin
{
	public class ActionNode : Node
	{
        public UnityEvent<INode.ENodeState> act;
        public string methodName { get { return act.ToString(); }}

        public ActionNode(Action<INode.ENodeState> onUpdate)
		{
			act.AddListener(() => onUpdate?.Invoke());
        }

		public override INode.ENodeState Evaluate()
		{
			Debug.Log(act);
			if (act != null)
				return act.Invoke();
			else return INode.ENodeState.Fail;
		}
	}
}
