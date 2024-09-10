#include "Player.h"	

Player::Player(int x, int y, int halfSize) : GameObject(x, y, halfSize)
{
	speed = 5;
	curFrame = Frame_Min;
	pImg = nullptr;
}

Player::~Player()
{
	if (pImg) delete pImg;
}

void Player::MoveTo(RECT& rectView, int x, int y)
{
	int moveX = this->GetX() + speed * x;
	int moveY = this->GetY() + speed * y;

	if (moveX >= rectView.right)	return;
	if (moveX <= rectView.left)		return;
	if (moveY >= rectView.bottom)	return;
	if (moveY <= rectView.top)		return;

	this->SetX(moveX);
	this->setY(moveY);
}

void Player::Update()
{
	curFrame++;
	if (curFrame > Frame_Max)
		curFrame = Frame_Min;
}

void Player::Draw(HDC hdc)
{
	RECT pos = GetCollisionBox();

	Graphics graphics(hdc);


	if (pImg)
	{
		int w = pImg->GetWidth() / 7;
		int h = pImg->GetHeight() / 1;

		int xStart = curFrame * w;
		int yStart = 0;

		imgAttr.SetColorKey(Color(255, 116, 110), Color(255, 116, 110));
		graphics.DrawImage(pImg, Rect(GetX() - w/2, GetY() - h/2, w, h), xStart, yStart, w, h, UnitPixel, &imgAttr);
	}
}

void Player::Collision()
{
}

void Player::CreateBitmap()
{
	pImg = Image::FromFile((WCHAR*)L"../data/images/player.png");
	if (pImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("플레이어 애니메이션 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}

	hPlayerAnimImg = (HBITMAP)LoadImage(NULL, TEXT("../Data/images/player.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (hPlayerAnimImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("애니메이션 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}
	else
	{
		GetObject(hPlayerAnimImg, sizeof(BITMAP), &bitPlayerAnim);
	}

}