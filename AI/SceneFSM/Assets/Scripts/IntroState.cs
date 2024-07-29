using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class IntroState : MonoBehaviour, IState<SceneStates>
{
    private SceneStates sceneManager;

    private float time = 0.0f;

    public void Enter(SceneStates sender)
    {
        Debug.Log("Intro Enter");
        sceneManager = sender;
    }
    public void Stay(SceneStates sender)
    {
        // Debug.Log("Intro Stay");
        time = time + Time.deltaTime;

        if (time > 6.5f)   // 6.5초면 인트로 끝 
        {
            //Debug.Log("Time: " + time);
            sender.sm.SetState(sender.dicState[SceneStates.SceneState.LOGIN]);
            SceneManager.LoadScene("Scenes/Login");
        }
    }
    public void Exit(SceneStates sender)
    {
        Debug.Log("Intro Exit");
    }
}
