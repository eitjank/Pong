#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Vec2.h"

class SelectionMenu
{
public:
	enum class Selection
	{
		None,
		SinglePlayer,
		MultiPlayer
	};
public:
	SelectionMenu(Graphics& gfx);
	void Draw(Graphics& gfx)const;
	Selection Contains(const Vec2& pos)const;
private:
	RectF rect[2];
	static constexpr int spacing = 70;
	static constexpr int width = 220;
	static constexpr int height = 45;
};