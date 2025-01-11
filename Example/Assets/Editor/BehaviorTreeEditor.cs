using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using Semin;
using Unity.VisualScripting;
public class BehaviorTreeEditor : EditorWindow
{
    [SerializeField]
    BehaviorTreeView treeView;
    InspectorView inspectorView;

    [MenuItem("My Funcion/Behaviour Tree/Editor ...")]
    public static void OpenWindow()
    {
        BehaviorTreeEditor wnd = GetWindow<BehaviorTreeEditor>();
        wnd.titleContent = new GUIContent("BehaviorTreeEditor");
    }

    public void CreateGUI()
    {
        // Each editor window contains a root VisualElement object
        VisualElement root = rootVisualElement;

        var visualTree = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>("Assets/Editor/BehaviorTreeEditor.uxml");
        visualTree.CloneTree(root);

        // Style
        var styleSheet = AssetDatabase.LoadAssetAtPath<StyleSheet>("Assets/Editor/BehaviorTreeEditor.uss");
        root.styleSheets.Add(styleSheet);

        treeView = root.Q<BehaviorTreeView>();
        inspectorView = root.Q<InspectorView>();
		treeView.focusable = true;

        OnSelectionChange();
	}

	private void OnSelectionChange()
	{
		SCBehaviorTree tree = Selection.activeObject as SCBehaviorTree;

        if (tree)
        {
            treeView.PopulateView(tree);
        }
	}
}
