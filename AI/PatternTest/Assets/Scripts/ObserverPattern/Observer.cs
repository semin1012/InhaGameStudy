using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Observer : MonoBehaviour
{
	public abstract void Notify(Subject subject);

    public void AddObserver(Subject subj)
    {
        subj.Attach(this);
        Debug.Log(this);
    }

    public void RemoveObserver(Subject subj)
    {
        subj.Detach(this);
    }
}
