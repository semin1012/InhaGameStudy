using Chapter.MyState;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClientState : MonoBehaviour
{
    private BikeController bikeController;

	private void Start()
	{
		bikeController = (BikeController)FindObjectOfType(typeof(BikeController));
	}

	private void OnGUI()
	{
		if (GUILayout.Button("Start Bike"))
			bikeController.ChangeState(EBikeState.Start);
		if (GUILayout.Button("Stop Bike"))
			bikeController.ChangeState(EBikeState.Stop);
        if (GUILayout.Button("Turn Left"))
            bikeController.ChangeState(EBikeState.Turn);
	}
}
