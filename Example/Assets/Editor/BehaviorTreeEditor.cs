using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using Semin;
using UnityEditor.UIElements;
using Unity.VisualScripting;
using System.Reflection;

public class BehaviorTreeEditor : EditorWindow
{
    [SerializeField]
    BehaviorTreeView treeView;
    InspectorView inspectorView;
    ObjectFieldView fieldView;
    FuncDropdownFieldView funcDropdownView;
    ClassDropdownFieldView classDropdownView;

    PlayerController playerController;
	private MethodInfo[] methods;

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

        fieldView = root.Q<ObjectFieldView>();
        funcDropdownView = root.Q<FuncDropdownFieldView>();
        classDropdownView = root.Q<ClassDropdownFieldView>();

        treeView.OnNodeSelected = OnNodeSelectionChanged;
        treeView.focusable = true;

        fieldView.OnChanged = OnObjectSelectionChanged;
        fieldView.OnChanged.Invoke(fieldView);

        classDropdownView.OnSelected = OnClassSelectionChanged;

        funcDropdownView.OnSelected = OnFuncSelectionChanged;

        fieldView.SetEnabled(false);
        funcDropdownView.SetEnabled(false);
        classDropdownView.SetEnabled(false);
    }

	private void OnSelectionChange()
	{
		SCBehaviorTree tree = Selection.activeObject as SCBehaviorTree;

        if (tree)
            treeView.PopulateView(tree);
	}

    void OnNodeSelectionChanged(NodeView node)
    {
        inspectorView.UpdateSelection(node);

        if (inspectorView.SelectNode.node is CompositeNode || inspectorView.SelectNode.node is RootNode)
        {
            classDropdownView.SetEnabled(false);
            funcDropdownView.SetEnabled(false);
        }

        else
        {
            fieldView.SetEnabled(true);
            funcDropdownView.SetEnabled(true);
            classDropdownView.SetEnabled(true);
        }
    }

    void OnObjectSelectionChanged(ObjectFieldView field)
    {
        classDropdownView.SetDropdownMenu(field);
    }

    void OnClassSelectionChanged(ClassDropdownFieldView field)
    {
        funcDropdownView.SetDropdownMenu(field);
    }

    void OnFuncSelectionChanged(FuncDropdownFieldView field)
    {
        inspectorView.SelectNode.SetUpdate(field);
    }
}
