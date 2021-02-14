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
	Vec2 topLeft[2];
	RectF rect[2];
	static constexpr float borderThickness = 3.0f;
	static constexpr Color borderColor = Colors::LightGray;
	static constexpr int spacing = 82;
	static constexpr int width = 345;
	static constexpr int height = 82;
};