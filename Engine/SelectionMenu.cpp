#include "SelectionMenu.h"

SelectionMenu::SelectionMenu(Graphics& gfx)
{
	Vec2 topLeft = Vec2((Graphics::ScreenWidth - width) / 2, Graphics::ScreenHeight / 2 - height - spacing);
	rect[0] = RectF(topLeft, width, height);
	rect[1] = RectF(topLeft + Vec2(0, spacing + height), width, height);
}

void SelectionMenu::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect[0], Colors::Red);
	gfx.DrawRect(rect[1], Colors::Blue);
}

SelectionMenu::Selection SelectionMenu::Contains(const Vec2& pos) const
{
	if (rect[0].Contains(pos))
		return Selection::SinglePlayer;
	else if (rect[1].Contains(pos))
		return Selection::MultiPlayer;
	else return Selection::None;
}
