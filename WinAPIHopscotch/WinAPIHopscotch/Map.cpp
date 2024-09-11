#include "Map.h"

Map::Map() : GameObject(0, 0, 0, EGameObjectType::Map)
{
	stage = 0;
	rectView = nullptr;
}

Map::~Map()
{
	if (rectView) delete rectView;
}

void Map::Update()
{
}

void Map::Draw(HDC hdc)
{
	Graphics graphics(hdc);

	HDC hMemDC;
	HBITMAP hOldBitmap;

	hMemDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMapImg);

	int bx = bitMap.bmWidth;
	int by = bitMap.bmHeight;

	TransparentBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, rectView->right, rectView->bottom, RGB(255, 0, 255));
	//BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hFrontMapImg);

		bx = bitFrontMap.bmWidth;
		by = bitFrontMap.bmHeight;
		
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hFrontMapImg);
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);

		// int size = points.size();
		// POINT* pts = new POINT[size];

		if (points.size() > 2)
		{
			for (int i = 0; i < points.size() - 1; i++)
			{
				MoveToEx(hMemDC, points[i].x, points[i].y, NULL);
				LineTo(hMemDC, points[i + 1].x, points[i + 1].y);
			}
		}

		//for (int i = 0; i < size; i++)
		//{
		//	pts[i] = points[i];
		//}
		//Polygon(hMemDC, pts, points.size());


		SelectObject(hMemDC, oldBrush);
		DeleteObject(hBrush);
		TransparentBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, rectView->right, rectView->bottom, RGB(255, 0, 255));


		//delete[] pts;
	}

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

void Map::Draw(HDC hdc, std::vector<POINT>& points)
{
	
	
}

void Map::Collision()
{
}

void Map::CreateBitmap()
{
	hFrontMapImg = (HBITMAP)LoadImage(NULL, TEXT("../data/images/City3_pale_small.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (hFrontMapImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("맵 이미지1 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}
	else
	{
		GetObject(hFrontMapImg, sizeof(BITMAP), &bitFrontMap);
	}

	hMapImg = (HBITMAP)LoadImage(NULL, TEXT("../data/images/City3_small.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (hMapImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("맵 이미지1 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}
	else
	{
		GetObject(hMapImg, sizeof(BITMAP), &bitMap);
	}
}

void Map::SetRectView(RECT& rectView)
{
	this->rectView = &rectView;
}

void Map::SetPoints(std::vector<POINT>& points)
{
	this->points = points;
}
