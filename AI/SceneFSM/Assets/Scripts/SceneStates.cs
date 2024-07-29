using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneStates : MonoBehaviour
{
    public enum SceneState
    {
        INTRO,
        LOGIN,
        LOBBY,
        UPGRADE,
        BATTLE,
        STORE,
        MYROOM
    }

    public Dictionary<SceneState, IState<SceneStates>> dicState =
        new Dictionary<SceneState, IState<SceneStates>>();
    public StateMachine<SceneStates> sm;

    public SceneState currentState;

    void Start()
    {
        IState<SceneStates> intro = gameObject.AddComponent<IntroState>();
        IState<SceneStates> login = gameObject.AddComponent<LoginState>();
        IState<SceneStates> lobby = gameObject.AddComponent<LobbyState>();
        IState<SceneStates> store = gameObject.AddComponent<StoreState>();
        IState<SceneStates> myroom = gameObject.AddComponent<MyroomState>();
        IState<SceneStates> upgrade = gameObject.AddComponent<UpgradeState>();
        IState<SceneStates> battle = gameObject.AddComponent<BattleScene>();

        dicState.Add(SceneState.INTRO, intro);
        dicState.Add(SceneState.LOGIN, login);
        dicState.Add(SceneState.LOBBY, lobby);
        dicState.Add(SceneState.STORE, store);
        dicState.Add(SceneState.MYROOM, myroom);
        dicState.Add(SceneState.UPGRADE, upgrade);
        dicState.Add(SceneState.BATTLE, battle);

        string currentScene = SceneManager.GetActiveScene().name;

        switch (currentScene)
        {
            case "Intro":
                currentState = SceneState.INTRO;
                break;
            case "Login":
                currentState = SceneState.LOGIN;
                break;
            case "Lobby":
                currentState = SceneState.LOBBY;
                break;
            case "Upgrade":
                currentState = SceneState.UPGRADE;
                break;
            case "Battle":
                currentState = SceneState.BATTLE;
                break;
            case "Store":
                currentState = SceneState.STORE;
                break;
            case "Myroom":
                currentState = SceneState.MYROOM;
                break;
        }

        sm = new StateMachine<SceneStates>(this, dicState[currentState]);
        sm.SetState(dicState[currentState]);
    }

    // Update is called once per frame
    void Update()
    {
        sm.DoOperateUpdate();
    }
}
