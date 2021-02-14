#pragma once
#include "Graphics.h"
#include "Vec2.h"
class SpriteCodex
{
public:
	static void DrawNumber(int number, const Vec2& pos, Graphics& gfx);
	static void Draw1Player(const Vec2& pos, Graphics& gfx);
	static void Draw2Players(const Vec2& pos, Graphics& gfx);
private:
	static constexpr int width = 42;
	static constexpr int height = 63;
};