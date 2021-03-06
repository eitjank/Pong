#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include <random>
#include "GameSettings.h"

class Ball
{
public:
	enum class WallCollisions
	{
		None,
		Side,
		Top,
		Bottom
	};
public:
	Ball() = default;
	Ball(const Vec2& pos_in, const Vec2& dir_in);
	Ball(const GameSettings& settings);
	void Draw(Graphics& gfx)const;
	void Update(float dt);
	WallCollisions DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect()const;
	Vec2 GetVelocity()const;
	Vec2 GetPosition()const;
	void SetDirection(const Vec2& dir);
	void SpeedUp();
	void Reset();
private:
	float radius = 9.0f;
	float startingSpeed = 220.0f;
	float normalSpeed = 340.0f;
	float speed = startingSpeed;
	Vec2 pos;
	Vec2 vel;
};