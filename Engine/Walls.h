#pragma once

#include "RectF.h"
#include "Graphics.h"

class Walls
{
public:
	Walls(const RectF& rect_in);
	void Draw(Graphics& gfx)const;
	RectF rect;
private:
	Color color = Colors::Blue;
	static constexpr int width = 2;
};