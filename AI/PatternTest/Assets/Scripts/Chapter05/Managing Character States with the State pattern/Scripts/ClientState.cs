using UnityEngine;
public class ClientState : MonoBehaviour
{
	private BikeController _bikeController;

	void Start()
	{
		_bikeController =
			(BikeController)
			FindObjectOfType(typeof(BikeController));
	}

	void OnGUI()
	{
	}
}