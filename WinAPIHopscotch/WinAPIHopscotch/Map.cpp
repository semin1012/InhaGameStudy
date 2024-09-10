#include "Map.h"

Map::Map() : GameObject(0, 0, 0, EGameObjectType::Map)
{
	stage = 0;
	pImg = nullptr;
	rectView = nullptr;
}

void Map::Update()
{
}

void Map::Draw(HDC hdc)
{
	Graphics graphics(hdc);

	if (pImg)
	{
		int w = pImg->GetWidth() / 3;
		int h = pImg->GetHeight();

		graphics.DrawImage(pImg, Rect(0, 0, rectView->right, rectView->bottom + rectView->bottom / 3), 0, 0, w, h, UnitPixel);
		graphics.DrawImage(pImg, Rect(0, 0, rectView->right, rectView->bottom + rectView->bottom / 3), w, 0, w, h, UnitPixel);
		graphics.DrawImage(pImg, Rect(0, 0, rectView->right, rectView->bottom + rectView->bottom / 3), w * 2, 0, w, h, UnitPixel);
	}
}

void Map::Collision()
{
}

void Map::CreateBitmap()
{
	pImg = Image::FromFile((WCHAR*)L"../data/images/background.png");
	if (pImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("배경 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}
}

void Map::SetRectView(RECT& rectView)
{
	this->rectView = &rectView;
}
