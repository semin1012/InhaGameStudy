using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class CameraController : MonoBehaviour
{
    public float rotateSpeed = 1000.0f;
    Camera mainCamera;
    void Start()
    {
        mainCamera = GetComponent<Camera>();
    }

    void Update()
    {
        MoveCamera();
        RotateCamera();
        ZoomCamera();
    }

    void MoveCamera()
    {
        if (Input.GetMouseButton(0))
            transform.Translate(Input.GetAxisRaw("Mouse X"), Input.GetAxisRaw("Mouse Y"), 0);
    }

    void RotateCamera()
    {
        if (Input.GetMouseButton(1))
        {
			transform.Rotate(new Vector3(0.0f, Input.GetAxisRaw("Mouse X") * Time.deltaTime * rotateSpeed, 0.0f));
			transform.Rotate(new Vector3(-Input.GetAxisRaw("Mouse Y") * Time.deltaTime * rotateSpeed, 0.0f, 0.0f));
		}
	}

    void ZoomCamera()
    {
        mainCamera.fieldOfView -= 100.0f * Input.GetAxis("Mouse ScrollWheel");
        if ( mainCamera.fieldOfView < 20 )
            mainCamera.fieldOfView = 20;
		if (mainCamera.fieldOfView > 150)
            mainCamera.fieldOfView = 150;
	}
}
