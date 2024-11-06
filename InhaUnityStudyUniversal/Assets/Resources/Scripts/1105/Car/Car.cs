using UnityEngine;

public class Car : MonoBehaviour
{
    public Wheel frontWheel = null;
    public Wheel backWheel = null;
	public GameObject body = null;

	public float moveSpeed = 5.0f;
	public float rotateSpeed = 1.2f;

	private void Reset()
	{
		//	Debug.Log(transform.Find("FrontWheel").gameObject);
		body = transform.Find("Body").gameObject;
		backWheel = body.transform.Find("BackWheelParent").Find("BackWheel").GetComponent<Wheel>();
		frontWheel = body.transform.Find("FrontWheelParent").Find("FrontWheel").GetComponent<Wheel>();
	}

	protected void MoveForward()
	{
		float moveDelta = moveSpeed * Time.deltaTime;

		body.transform.Rotate(body.transform.up * frontWheel.transform.localRotation.y * rotateSpeed);
		transform.Translate(body.transform.forward * moveDelta);
	}

	protected void MoveBack()
	{
		float moveDelta = moveSpeed * Time.deltaTime;

		body.transform.Rotate(body.transform.up * -frontWheel.transform.localRotation.y * rotateSpeed);
		transform.Translate(-body.transform.forward * moveDelta);
	}
}
