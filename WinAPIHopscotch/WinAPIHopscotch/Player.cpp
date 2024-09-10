#include "Player.h"	

Player::Player(int x, int y, int halfSize) : GameObject(x, y, halfSize, EGameObjectType::Player)
{
	speed = 5;
	curFrame = Frame_Min;
}

Player::~Player()
{
}

void Player::MoveTo(RECT& rectView, int x, int y)
{
	int moveX = this->GetX() + speed * x;
	int moveY = this->GetY() + speed * y;

	if (moveX >= rectView.right + GetHalfSize())	return;
	if (moveX <= rectView.left - GetHalfSize() * 2)	return;
	if (moveY >= rectView.bottom + GetHalfSize())	return;
	if (moveY <= rectView.top - GetHalfSize() * 2)	return;

	this->SetX(moveX);
	this->SetY(moveY);
}

void Player::CheckArea(std::vector<POINT>& points)
{

}

int Player::GetCenterX()
{
	return GetX() + GetHalfSize();
}

int Player::GetCenterY()
{
	return GetY() - bitPlayer.bmHeight / 2;
}

void Player::Update()
{
	curFrame++;
	if (curFrame > Frame_Max)
		curFrame = Frame_Min;

	SetCollisionBox();
}

void Player::Draw(HDC hdc)
{
	RECT pos = GetCollisionBox();

	Graphics graphics(hdc);

	HDC hMemDC;
	HBITMAP hOldBitmap;

	hMemDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hPlayerImg);

	int bx = bitPlayer.bmWidth / 7;
	int by = bitPlayer.bmHeight / 1;

	int xStart = curFrame * bx;
	int yStart = 0;

	TransparentBlt(hdc, GetX() - GetHalfSize(), GetY() - GetHalfSize(), bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 116, 110));
	//BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

void Player::Collision()
{
}

void Player::CreateBitmap()
{
	hPlayerImg = (HBITMAP)LoadImage(NULL, TEXT("../data/images/player.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (hPlayerImg == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("플레이어 애니메이션 파일을 열 수 없습니다."), _T("에러"), MB_OK);
	}
	else
	{
		GetObject(hPlayerImg, sizeof(BITMAP), &bitPlayer);
	}
}