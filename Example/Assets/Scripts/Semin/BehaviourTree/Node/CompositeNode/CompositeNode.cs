using Semin;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

namespace Semin
{
    public abstract class CompositeNode : Node
    {
        protected List<Node> children;

        public abstract override INode.ENodeState Evaluate();

        public void AddChild(Node child)
        {
            children.Add(child);
        }

        public void RemoveChild(Node child)
        {
            children.Remove(child);
        }

        public List<Node> GetChild()
        {
            return children;
        }
    }


}
