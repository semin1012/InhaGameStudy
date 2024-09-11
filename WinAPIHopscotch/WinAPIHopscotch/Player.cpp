#include "Player.h"	

Player::Player(int x, int y, int halfSize) : GameObject(x, y, halfSize, EGameObjectType::Player)
{
	speed = 10;
	curFrame = Frame_Min;
	hPlayerImg = nullptr;
	isPressed = false;
}

Player::~Player()
{
}

bool Player::MoveTo(RECT& rectView, int x, int y)
{
	int moveX = this->GetX() + speed * x;
	int moveY = this->GetY() + speed * y;

	if (moveX >= rectView.right + GetHalfSize())	return false;
	if (moveX <= rectView.left - GetHalfSize() * 2)	return false;
	if (moveY >= rectView.bottom + GetHalfSize())	return false;
	if (moveY <= rectView.top - GetHalfSize() * 2)	return false;

	this->SetX(moveX);
	this->SetY(moveY);

	Collision();

	return true;
}

void Player::CheckArea(std::vector<POINT>& points)
{

}

int Player::GetCenterX()
{
	return GetX() + (bitPlayer.bmWidth / 7) /2 ;
}

int Player::GetCenterY()
{
	return GetY() + (bitPlayer.bmHeight) / 2;
}

bool Player::GetPressed()
{
	return isPressed;
}

void Player::SetPressed(bool pressed)
{
	isPressed = pressed;
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

	TransparentBlt(hdc, GetX(), GetY(), bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 116, 110));
	//BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

void Player::Collision()
{
}

bool Player::CollisionWindow()
{
	if (   GetCenterX()	<= rectView->left 
		|| GetCenterX() >= rectView->right  
		|| GetCenterY() <= rectView->top   
		|| GetCenterY() >= rectView->bottom)
		return true;
	return false;
}

void Player::SetRectView(RECT &rectView)
{
	this->rectView = &rectView;
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