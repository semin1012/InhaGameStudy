#pragma once
#include <vector>
#include "framework.h"
#include "GameObject.h"

class Player : public GameObject
{
	float				speed;
	ImageAttributes		imgAttr;
	int					curFrame;
	const int			Frame_Max = 6;
	const int			Frame_Min = 0;
	HBITMAP				hPlayerImg;
	BITMAP				bitPlayer;


public:
	Player(int x, int y, int halfSize);
	~Player();

	void		Update() override;
	void		Draw(HDC hdc) override;
	void		Collision() override;
	void		CreateBitmap() override;

	void		MoveTo(RECT& rectView, int x, int y);

	void		CheckArea(std::vector<POINT>& points);

	int			GetCenterX();
	int			GetCenterY();
};