using Semin;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Semin
{
    public abstract class DecoratorNode : Node 
    {
        [SerializeField] protected Node child;

        public abstract override INode.ENodeState Evaluate();

        public DecoratorNode(Node child)
        {
            this.child = child;
        }

        public void SetChild(Node child)
        {
            this.child = child;
        }

        public Node GetChild()
        {
            return child;
        }

		public override Node Clone()
		{
			DecoratorNode node = Instantiate(this);
			node.child = child.Clone();
			return node;
		}
	}

}
