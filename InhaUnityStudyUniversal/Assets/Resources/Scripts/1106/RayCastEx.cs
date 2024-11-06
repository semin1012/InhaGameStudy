using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayCastEx : MonoBehaviour
{
    [Range(0, 50)]
    public float distance = 10.0f;

    private RaycastHit rayHit;
	private RaycastHit[] rayHits;
	private Ray ray;

    private Transform other = null;

	private void Awake()
	{
        // GameObject.Find 라는 함수는 부하가 많이 걸리는 작업이다.
        // Awake와 같이 시작할때 찾는 것은 괜찮은데, Update 같은 곳에서 사용은 지양할 것.
		other = GameObject.Find("Cylinder").transform;
	}

	void Start()
    {
        ray = new Ray();
        ray.origin = transform.position;
        // 빈 오브젝트가 아니라면 원점에 맞출 경우 자기 자신을 검출할 수도 있음 < 확인 필요
        ray.direction = transform.forward;
        // ray = new Ray(transform.position, transform.forward); // 위 세 줄을 한 줄로 표현
    }

    void Update()
    {
        //Ray_1();
        //Ray_2();
        Ray_3();

        //DrawRay();
    }

    void DrawRay()
    {
        // 방향
        Vector3 dir = other.position - this.transform.position;
        dir.Normalize();

        // 거리
        float distance = Vector3.Distance(other.position, transform.position);
        Debug.DrawRay(ray.origin, dir * distance, Color.red);
    }

	private void OnDrawGizmos()
	{
        Gizmos.DrawLine(ray.origin, ray.direction * distance);
        Gizmos.color = new Color32(255, 255, 0, 255);       // new Color(1, 1, 0); // 가능
        Gizmos.DrawSphere(ray.origin, 0.1f);

        if(rayHits != null)
        {
            for (int i = 0; i < rayHits.Length; i++)
            {
                if (rayHits[i].collider != null)
                {
                    Gizmos.color = Color.red;
                    Gizmos.DrawSphere(rayHits[i].point, 0.1f);

                    Gizmos.color = Color.cyan;
                    Gizmos.DrawLine(transform.position, transform.position + transform.forward * rayHits[i].distance);

                    Gizmos.color = Color.yellow;
                    Gizmos.DrawLine(rayHits[i].point, rayHits[i].point + rayHits[i].normal);

                    Gizmos.color = new Color(1, 0, 1);
                    Vector3 reflect = Vector3.Reflect(transform.forward, rayHits[i].normal);
                    Gizmos.DrawLine(rayHits[i].point, rayHits[i].point + reflect);
                }
            }
        }
	}

	void Ray_1()
    {
        if (Physics.Raycast(ray.origin, ray.direction, out rayHit, distance))
        {
            Debug.Log(rayHit.collider.gameObject.name);
        }
    }
    void Ray_2()
    {
        rayHits = Physics.RaycastAll(ray, distance);
		//Physics.SphereCastAll(ray, distance); // 범위 공격 처리 가능 
		for ( int i = 0; i < rayHits.Length; i++ )
        {
			Debug.Log("<color=red>" + rayHits[i].collider.gameObject.name + "</color>" + " hit!");
		}
    }
    void Ray_3()
	{
		rayHits = Physics.RaycastAll(ray, distance);
		//Physics.SphereCastAll(ray, distance); // 범위 공격 처리 가능 
		for (int i = 0; i < rayHits.Length; i++)
		{
            if (rayHits[i].collider.gameObject.tag == "Sphere")
			    Debug.Log("<color=red>Tag : Sphere </color>" + rayHits[i].collider.gameObject.name + " hit!");
			if (rayHits[i].collider.gameObject.layer == LayerMask.NameToLayer("Box"))
				Debug.Log("<color=red>Layer : Box </color>" + rayHits[i].collider.gameObject.name + " hit!");
		}
	}
}
