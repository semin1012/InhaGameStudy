#pragma once
#include "framework.h"
#include "GameObject.h"

class Player : public GameObject
{
	float				speed;
	HBITMAP				hPlayerAnimImg;
	BITMAP				bitPlayerAnim;
	int					Run_Frame_Max;
	int					Run_Frame_Min;
	Image*				pImg;
	ImageAttributes		imgAttr;
	int					curFrame;
	const int			Frame_Max = 7;
	const int			Frame_Min = 0;


public:
	Player(int x, int y, int halfSize);
	~Player();

	void		Update() override;
	void		Draw(HDC hdc) override;
	void		Collision() override;
	void		CreateBitmap() override;

	void		MoveTo(RECT& rectView, int x, int y);
};