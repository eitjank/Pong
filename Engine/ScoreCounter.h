#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "SpriteCodex.h"

class ScoreCounter
{
public:
	void Add();
	void Draw(Vec2& pos, Graphics& gfx)const;
private:
	int score = 0;
	static constexpr int width = 42;
	static constexpr int spacing = 2;
};