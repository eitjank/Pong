#include "ScoreCounter.h"

void ScoreCounter::Add()
{
	score++;
}

void ScoreCounter::Draw(Vec2& pos, Graphics& gfx) const
{
	if (score < 10)
	{
		SpriteCodex::DrawNumber(score, pos + Vec2(width+spacing,0), gfx);
	}
	else
	{
		SpriteCodex::DrawNumber(score % 10, pos + Vec2(width + spacing, 0), gfx);
		SpriteCodex::DrawNumber(score / 10, pos, gfx);
	}
}
