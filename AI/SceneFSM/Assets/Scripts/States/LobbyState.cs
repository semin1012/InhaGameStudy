using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LobbyState : MonoBehaviour, IState<SceneStates>
{
    private SceneStates sceneManager;
    public enum SCENE
    {
        STORE,
        MYROOM,
        UPGRADE,
        BATTLE,
        LOGIN
    }

    static bool isClicked = false;
    static SCENE select;

    public void Enter(SceneStates sender)
    {
        Debug.Log("Lobby Enter");
        sceneManager = sender;
        isClicked = false;
    }
    public void Stay(SceneStates sender)
    {
        //Debug.Log("Lobby Stay");
        if (isClicked == true)
        {
            switch(select)
            {
                case SCENE.STORE:
                    sender.sm.SetState(sender.dicState[SceneStates.SceneState.STORE]);
                    SceneManager.LoadScene("Scenes/Store");
                    break;
                case SCENE.MYROOM:
                    sender.sm.SetState(sender.dicState[SceneStates.SceneState.MYROOM]);
                    SceneManager.LoadScene("Scenes/Myroom");
                    break;
                case SCENE.UPGRADE:
                    sender.sm.SetState(sender.dicState[SceneStates.SceneState.UPGRADE]);
                    SceneManager.LoadScene("Scenes/Upgrade");
                    break;
                case SCENE.BATTLE:
                    sender.sm.SetState(sender.dicState[SceneStates.SceneState.BATTLE]);
                    SceneManager.LoadScene("Scenes/Battle");
                    break;
                case SCENE.LOGIN:
                    sender.sm.SetState(sender.dicState[SceneStates.SceneState.LOGIN]);
                    SceneManager.LoadScene("Scenes/Login");
                    break;
            }
        }
    }
    public void Exit(SceneStates sender)
    {
        Debug.Log("Lobby Exit");
    }

    public void OnClickedStore()
    {
        isClicked = true;
        select = SCENE.STORE;
    }
    public void OnClickedMyRoom()
    {
        isClicked = true;
        select = SCENE.MYROOM;
    }
    public void OnClickedUpgrade()
    {
        isClicked = true;
        select = SCENE.UPGRADE;
    }
    public void OnClickedBattle()
    {
        isClicked = true;
        select = SCENE.BATTLE;
    }
    public void OnClickedLogOut()
    {
        isClicked = true;
        select = SCENE.LOGIN;
    }
}
