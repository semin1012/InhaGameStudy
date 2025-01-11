using Semin;
using System.Reflection;
using System;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.UIElements;
using Unity.VisualScripting.FullSerializer.Internal;

public class FuncDropdownFieldView : DropdownField
{
    public Action<FuncDropdownFieldView> OnSelected;
    public new class UxmlFactory : UxmlFactory<FuncDropdownFieldView, DropdownField.UxmlTraits> { }
    private MethodInfo[] methods;
    public MethodInfo SelectMethod;
    public PlayerController gameObj;
    public Func<INode.ENodeState> SelectFunc;

    public FuncDropdownFieldView()
    {

    }

    public void SetDropdownMenu(ClassDropdownFieldView field)
    {
        if (field != null)
        {
            gameObj = GameObject.FindWithTag("Player").GetComponent<PlayerController>();
            methods = field.SelectType.GetDeclaredMethods();
            for (int i = 0; i < methods.Length; i++)
            {
                if (methods[i].IsPublic)
                    choices.Add(methods[i].Name);
            }
        }
    }

    public override void SetValueWithoutNotify(string newValue)
    {
        base.SetValueWithoutNotify(newValue);
        if (methods != null)
        {
            for (int i = 0; i < methods.Length; i++)
            {
                if (newValue == methods[i].Name)
                {
                    SelectFunc = gameObj.RotatePlayer;
                    SelectMethod = methods[i];
                }
            }
        }
        if (OnSelected != null)
            OnSelected.Invoke(this);
    }
}
