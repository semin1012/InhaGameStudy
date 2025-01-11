using Semin;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using System.Reflection;
using UnityEditor.UIElements;
using UnityEditor.IMGUI.Controls;

public class InspectorView : VisualElement
{
	[SerializeField]
	DropdownMenu dropDown;
	[SerializeField]
	ObjectField playerObj;

	PlayerController playerController;
	public new class UxmlFactory : UxmlFactory<InspectorView, VisualElement.UxmlTraits> { }
	Editor editor;
	private MethodInfo[] methods;

	public InspectorView()
	{
	}
	public void CreateGUI()
	{
	}

	public void OnGUI()
	{

	}

	internal void UpdateSelection(NodeView nodeView)
	{
		Clear();
		UnityEngine.Object.DestroyImmediate(editor);
		editor = Editor.CreateEditor(nodeView.node);



		IMGUIContainer container = new IMGUIContainer(() => { editor.OnInspectorGUI(); });
		Add(container);	
	}

	private void CallFunction(MethodInfo method)
	{
		// 메서드의 반환 타입에 따라 호출
		if (method.ReturnType == typeof(int))
		{
			int result = (int)method.Invoke(playerController, null);
			Debug.Log($"{method.Name}의 반환값: {result}");
		}
		else if (method.ReturnType == typeof(string))
		{
			string result = (string)method.Invoke(playerController, null);
			Debug.Log($"{method.Name}의 반환값: {result}");
		}
		else if (method.ReturnType == typeof(float))
		{
			float result = (float)method.Invoke(playerController, null);
			Debug.Log($"{method.Name}의 반환값: {result}");
		}
	}
}
