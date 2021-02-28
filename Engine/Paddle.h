#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "GameSettings.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(const Vec2& pos_in, const GameSettings& settings);
	void Draw(Graphics& gfx)const;
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt, int paddleNumber);
	void Control(float dt, Ball& ball);
	RectF GetRect()const;
private:
	static constexpr float wingWidth = 2.0f;
	Color wingColor = { 220,215,215 };
	Color color = { 230,220,220 };
	float speed = 260.0f;
	//paddle rebound behaviour
	static constexpr float maximumExitRatio = 2.1f;//2.6
	static constexpr float fixedZoneWitdthRatio = 0.05f;//0.1
	//these are derived from the above
	float exitXFactor;
	float fixedZoneHalfWidth;
	float fixedZoneExitX;
	//
	float halfWidth;
	float halfHeight;
	Vec2 pos;
};