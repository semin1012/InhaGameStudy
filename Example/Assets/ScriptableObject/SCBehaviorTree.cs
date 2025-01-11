using Semin;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

[CreateAssetMenu()]
public class SCBehaviorTree : ScriptableObject
{
	public Node rootNode;
	public INode.ENodeState state = INode.ENodeState.Running;
	public List<Node> nodes = new List<Node>();

	public INode.ENodeState Operate()
	{
		return rootNode.Evaluate();
	}

	public Node CreateNode(System.Type type)
	{
		Node node = ScriptableObject.CreateInstance(type) as Node;
		node.name = type.Name;
		node.guid = GUID.Generate().ToString();
		nodes.Add(node);

		AssetDatabase.AddObjectToAsset(node, this);
		AssetDatabase.SaveAssets();
		return node;
	}

	public void DeleteNode(Node node)
	{
		AssetDatabase.RemoveObjectFromAsset(node);
		AssetDatabase.SaveAssets();
	}

	public void AddChild(Node parent, Node child)
	{
		DecoratorNode decorator = parent as DecoratorNode; 
		if (decorator)
		{
			decorator.SetChild(child);
			return;
		}

		CompositeNode composite = parent as CompositeNode;
		if (composite)
			composite.AddChild(child);
	}

	public void RemoveChild(Node parent, Node child)
	{
		DecoratorNode decorator = parent as DecoratorNode;
		if (decorator)
		{
			decorator.SetChild(null);
			return;
		}

		CompositeNode composite = parent as CompositeNode;
		if (composite)
			composite.RemoveChild(child);
	}

	public List<Node> GetChild(Node parent)
	{
		List<Node> children = new List<Node>();
		DecoratorNode decorator = parent as DecoratorNode;
		if (decorator && decorator.GetChild() != null)
			children.Add(decorator.GetChild() as Node);

		CompositeNode composite = parent as CompositeNode;
		if (composite)
			return composite.GetChild();

		return children;
	}
}
