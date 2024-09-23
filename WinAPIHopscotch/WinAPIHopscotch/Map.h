#pragma once
#include <vector>
#include "framework.h"
#include "GameObject.h"

class Map : public GameObject
{
private:
	const int			Max_Stage = 1;
	int					stage;
	RECT*				rectView;
	HBITMAP				hMapImg;
	HBITMAP				hFrontMapImg;
	BITMAP				bitMap;
	BITMAP				bitFrontMap;
	std::vector<POINT>*	points;
	std::vector<POINT>*	area;

public:
	Map();
	~Map();
	void		Update() override;
	void		Draw(HDC hdc) override;
	void		Draw(HDC hdc, std::vector<POINT>& points);
	void		Collision() override;
	void		CreateBitmap() override;
	
	void		SetRectView(RECT& rectView);
	void		SetPoints(std::vector<POINT>& points, std::vector<POINT>& area);
};

