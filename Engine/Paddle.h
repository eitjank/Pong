#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx)const;
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect()const;
	void ResetCooldown();
private:
	static constexpr float wingWidth = 2.0f;
	Color wingColor = { 190,185,185 };
	Color color = { 200,195,195 };
	static constexpr float speed = 350.0f;
	//paddle rebound behaviour
	static constexpr float maximumExitRatio = 2.6f;
	static constexpr float fixedZoneWitdthRatio = 0.1f;
	//these are derived from the above
	float exitXFactor;
	float fixedZoneHalfWidth;
	float fixedZoneExitX;
	//
	float halfWidth;
	float halfHeight;
	Vec2 pos;
	bool isCooldown = false;
};