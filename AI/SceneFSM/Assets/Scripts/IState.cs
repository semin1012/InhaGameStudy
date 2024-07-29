using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IState<T>
{
    void Enter(T sender);
    void Stay(T sender);
    void Exit(T sender);
}
