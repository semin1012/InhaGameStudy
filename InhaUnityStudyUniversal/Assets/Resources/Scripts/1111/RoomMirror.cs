using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoomMirror : MonoBehaviour
{
    private Camera roomMirror;
	public Camera _RoomMirror
	{
		get
		{
			return roomMirror;
		}
		set
		{
			roomMirror = value;
		}
	}
    void Start()
    {
		_RoomMirror = GetComponent<Camera>();
    }

	private void OnPreCull()
	{
		// Cull 방향을 바꿔준다.
        _RoomMirror.ResetProjectionMatrix();
		_RoomMirror.projectionMatrix = _RoomMirror.projectionMatrix * Matrix4x4.Scale(new Vector3(-1, 1, 1)); // x축 반전
	}

	private void OnPreRender()
	{
		GL.invertCulling = true;
	}


	private void OnPostRender()
	{
		GL.invertCulling = false;
		// OnPreCull -> OnPreRender -> OnPostRender -> Update 
	}

	void Update()
    {
        
    }
}
