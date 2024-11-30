using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;
using UnityEngine.Pool;

public class Obj<T> : MonoBehaviour where T : Obj<T>
{
	public IObjectPool<T> Pool { get; set; }
}
