using UnityEngine;

public class Car : MonoBehaviour
{
    public GameObject frontWheel = null;
    public GameObject backWheel = null;
	public GameObject body = null;

	public float moveSpeed = 10.0f;

	void Update()
    {
		float moveDelta = moveSpeed * Time.deltaTime;
		Vector3 dir = body.transform.forward * -frontWheel.transform.rotation.x;

		if (Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.W))
		{
			body.transform.Rotate(body.transform.up * frontWheel.transform.localRotation.y);
			transform.Translate(body.transform.forward * moveDelta);
		}
		if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
		{
			body.transform.Rotate(body.transform.up * -frontWheel.transform.localRotation.y);
			transform.Translate(-body.transform.forward * moveDelta);
		}
	}
}
