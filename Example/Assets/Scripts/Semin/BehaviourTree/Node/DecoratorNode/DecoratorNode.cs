using Semin;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Semin
{
    public abstract class DecoratorNode : Node 
    {
        protected Node child;

        public abstract override INode.ENodeState Evaluate();

        public DecoratorNode(Node child)
        {
            this.child = child;
        }

        public void SetChild(Node child)
        {
            this.child = child;
        }

        public INode GetChild()
        {
            return child;
        }
    }

}
