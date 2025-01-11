using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class BehaviorTreeRunner : MonoBehaviour
{
    [SerializeField] public SCBehaviorTree tree;
    void Start()
    {
        tree = tree.Clone();
    }

    void Update()
    {
        tree.Operate();
    }
}
