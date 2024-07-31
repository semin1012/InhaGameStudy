using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DontDestroyOnLoad : MonoBehaviour
{
    private static DontDestroyOnLoad s_instance = null;

    void Awake()
    {
        if ( s_instance)
        {
            Destroy(this.gameObject);
            return;
        }

        s_instance = this;
        DontDestroyOnLoad(this.gameObject);
    }
}