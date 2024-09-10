#pragma once
#include "framework.h"
#include "GameObject.h"

class Map : public GameObject
{
private:
	const int			Max_Stage = 1;
	int					stage;
	Image*				pImg;
	RECT*				rectView;

public:
	Map();
	void Update() override;
	void Draw(HDC hdc) override;
	void Collision() override;
	void CreateBitmap() override;
	
	void SetRectView(RECT& rectView);
};

