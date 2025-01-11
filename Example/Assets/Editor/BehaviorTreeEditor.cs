using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using Semin;
using UnityEditor.UIElements;
using Unity.VisualScripting;
using System.Reflection;
using System.Reflection;
public class BehaviorTreeEditor : EditorWindow
{
    [SerializeField]
    BehaviorTreeView treeView;
    InspectorView inspectorView;

	PlayerController playerController;
	ObjectField playerObj;
	DropdownField dropDown;
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
        treeView.OnNodeSelected = OnNodeSelectionChanged;
        treeView.focusable = true;

        inspectorView.CreateGUI();
        dropDown = root.Q<DropdownField>();
        playerObj = root.Q<ObjectField>();


		playerController = GameObject.FindWithTag("Player").GetComponent<PlayerController>();
		playerObj.objectType = typeof(PlayerController);
		playerObj.allowSceneObjects = true;
		playerObj.value = playerController;

		if (playerController != null)
		{
			methods = playerController.GetType().GetMethods(BindingFlags.Public | BindingFlags.Instance);
			for (int i = 0; i < methods.Length; i++)
			{
                if (methods[i].IsPublic && !methods[i].IsVirtual)
                    dropDown.choices.Add(methods[i].Name);
			}
		}

		OnSelectionChange();
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
    }
}
