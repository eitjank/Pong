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
	//if (!isCooldown)
	{
		const RectF rect = GetRect();
		if (rect.IsOverlappingWith(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPosition();

			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x) || ballPos.x >= rect.left && ballPos.x <= rect.right)
			{
				const float xDifference = ballPos.x - pos.x;
				Vec2 dir;
				if (std::abs(xDifference) < fixedZoneExitX)
				{
					if (xDifference < 0.0f)
					{
						dir = Vec2(-fixedZoneExitX, -1.0f);
					}
					else
					{
						dir = Vec2(fixedZoneExitX, -1.0f);
					}
				}
				else
				{
					dir = Vec2(xDifference * exitXFactor, -1.0f);
				}
				ball.SetDirection(dir);
			}
			else
			{
				ball.ReboundX();
			}
			isCooldown = true;
			return true;
		}
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
	}
}

void Paddle::Update(const Keyboard& kbd, float dt, int paddleNumber)
{
	
	if (paddleNumber == 0)
	{
		if (kbd.KeyIsPressed(0x57))
		{
			pos.y -= speed * dt;
		}
		if (kbd.KeyIsPressed(0x53))
		{
			pos.y += speed * dt;
		}
	}
	else if (paddleNumber == 1)
	{
		if (kbd.KeyIsPressed(VK_UP))
		{
			pos.y -= speed * dt;
		}
		if (kbd.KeyIsPressed(VK_DOWN))
		{
			pos.y += speed * dt;
		}
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}

void Paddle::ResetCooldown()
{
	isCooldown = false;
}