using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarController : MonoBehaviour
{
    // Start is called before the first frame update
    float speed = 0;
    Vector2 startPos;
    void Start()
    {
        Application.targetFrameRate = 60;
    }

    // Update is called once per frame
    void Update()
    {
        // 스와이프의 길이를 구한다.
        if ( Input.GetMouseButtonDown(0))
        {
            // 마우스 클릭한 좌표
            this.startPos = Input.mousePosition; 
        }
        else if (Input.GetMouseButtonUp(0))
        {
            // 마우스 버튼에서 손가락을 떼었을 때 좌표
            Vector2 endPos = Input.mousePosition;
            float swipeLength = endPos.x - startPos.x;

            // 스와이프 길이를 처음 속도로 변경한다.
            this.speed = swipeLength / 500.0f;
        }

        transform.Translate(this.speed, 0, 0);
        this.speed *= 0.98f;
    }
}
