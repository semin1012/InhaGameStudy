using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StoreState : MonoBehaviour, IState<SceneStates>
{
    private SceneStates sceneManager;

    static bool isClicked = false;

    public void Enter(SceneStates sender)
    {
        Debug.Log("Store Enter");
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
        Debug.Log("Store Exit");
    }

    public void OnClicked()
    {
        isClicked = true;
    }
}
