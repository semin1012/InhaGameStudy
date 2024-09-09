#pragma once
class GameObject
{
private:
	int			x;
	int			y;

public:
	GameObject(int x, int y) : x(x), y(y) { }

	void			SetX(int x);
	void			setY(int y);
	int				GetX();
	int				GetY();

	virtual void	Update() = 0;
	virtual void	Draw() = 0;
	virtual void	Collision() = 0;
};

