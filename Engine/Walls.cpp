#include "Walls.h"

Walls::Walls(const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Walls::Draw(Graphics& gfx) const
{
	gfx.DrawRect(RectF(rect.left - width, rect.left, rect.top, rect.bottom), color);
	gfx.DrawRect(RectF(rect.right, rect.right + width, rect.top, rect.bottom), color);
}
