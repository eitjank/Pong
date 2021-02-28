#include "Paddle.h"
#include <cmath>

Paddle::Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos(pos_in),
	halfWidth(halfWidth_in),
	halfHeight(halfHeight_in)
{
	exitXFactor = maximumExitRatio / halfWidth;
	fixedZoneHalfWidth = halfWidth * fixedZoneWitdthRatio;
	fixedZoneExitX = fixedZoneHalfWidth * exitXFactor;
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball& ball)
{
	const RectF rect = GetRect();
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.SpeedUp();
		const Vec2 ballPos = ball.GetPosition();
		const float yDifference = ballPos.y - pos.y;

		float upDown;
		if (yDifference > 0.0f)
		{
			upDown = 1.0f;
		}
		else
		{
			upDown = -1.0f;
		}

		if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x) || ballPos.x >= rect.left && ballPos.x <= rect.right)
		{
			const float xDifference = ballPos.x - pos.x;
			Vec2 dir;
			if (std::abs(xDifference) < fixedZoneExitX)
			{

				if (xDifference < 0.0f)
				{
					dir = Vec2(-fixedZoneExitX, upDown);
				}
				else
				{
					dir = Vec2(fixedZoneExitX, upDown);
				}
			}
			else
			{
				dir = Vec2(xDifference * exitXFactor, upDown);
			}
			ball.SetDirection(dir);
		}
		else
		{
			ball.ReboundX();
		}
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Update(const Keyboard& kbd, float dt, int paddleNumber)
{
	if (paddleNumber == 0)
	{
		if (kbd.KeyIsPressed(VK_LEFT))
		{
			pos.x -= speed * dt;
		}
		if (kbd.KeyIsPressed(VK_RIGHT))
		{
			pos.x += speed * dt;
		}
	}
	else if(paddleNumber == 1)
	{
		if (kbd.KeyIsPressed(0x41))
		{
			pos.x -= speed * dt;
		}
		if (kbd.KeyIsPressed(0x44))
		{
			pos.x += speed * dt;
		}
	}
}

void Paddle::Control(float dt, Ball& ball)
{
	if (pos.x < ball.GetPosition().x)
	{
		pos.x += speed * dt;
	}
	else if (pos.x > ball.GetPosition().x)
	{
		pos.x -= speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
