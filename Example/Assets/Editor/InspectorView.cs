using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;

public class InspectorView : VisualElement
{
	public new class UxmlFactory : UxmlFactory<InspectorView, VisualElement.UxmlTraits> { }

	public InspectorView()
	{
		var styleSheet = AssetDatabase.LoadAssetAtPath<StyleSheet>("Assets/Editor/BehaviorTreeEditor.uss");
		styleSheets.Add(styleSheet);
	}

}
