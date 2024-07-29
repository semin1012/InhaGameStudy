using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MyroomState : MonoBehaviour, IState<SceneStates>
{
    private SceneStates sceneManager;

    static bool isClicked = false;

    public void Enter(SceneStates sender)
    {
        Debug.Log("MyRoom Enter");
        sceneManager = sender;
        isClicked = false;
    }
    public void Stay(SceneStates sender)
    {
        if (isClicked == true)
        {
            sender.sm.SetState(sender.dicState[SceneStates.SceneState.LOBBY]);
            SceneManager.LoadScene("Scenes/Lobby");
        }
    }
    public void Exit(SceneStates sender)
    {
        Debug.Log("MyRoom Exit");
    }

    public void OnClicked()
    {
        isClicked = true;
    }
}
