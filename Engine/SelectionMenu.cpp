#include "SelectionMenu.h"
#include "SpriteCodex.h"

SelectionMenu::SelectionMenu(Graphics& gfx)
{
	topLeft[0] = Vec2((Graphics::ScreenWidth - width) / 2, Graphics::ScreenHeight / 2 - height - spacing);
	topLeft[1] = topLeft[0] + Vec2(0, spacing + height);
	rect[0] = RectF(topLeft[0], width, height);
	rect[1] = RectF(topLeft[1], width, height);
}

void SelectionMenu::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect[0].GetExpanded(borderThickness),borderColor);
	SpriteCodex::Draw1Player(topLeft[0], gfx);
	gfx.DrawRect(rect[1].GetExpanded(borderThickness), borderColor);
	SpriteCodex::Draw2Players(topLeft[1], gfx);
}

SelectionMenu::Selection SelectionMenu::Contains(const Vec2& pos) const
{
	if (rect[0].Contains(pos))
		return Selection::SinglePlayer;
	else if (rect[1].Contains(pos))
		return Selection::MultiPlayer;
	else return Selection::None;
}
