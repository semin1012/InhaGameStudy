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
	bool				isPressed;
	RECT*				rectView;


public:
	Player(int x, int y, int halfSize);
	~Player();

	void		Update() override;
	void		Draw(HDC hdc) override;
	void		Collision() override;
	bool		CollisionWindow();
	void		CreateBitmap() override;

	void		SetRectView(RECT& rectView);

	bool		MoveTo(RECT& rectView, int x, int y);

	void		CheckArea(std::vector<POINT>& points);

	int			GetCenterX();
	int			GetCenterY();

	bool		GetPressed();
	void		SetPressed(bool pressed);
};