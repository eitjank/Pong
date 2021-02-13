/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	walls(RectF({ float(wallSideSpace), 0 }, Graphics::ScreenWidth - 2 * wallSideSpace, Graphics::ScreenHeight))
{
	ball.Reset();
	pad[0] = Paddle(Vec2(400, 550), 34, 9);
	pad[1] = Paddle(Vec2(400,  50), 34, 9);
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	for (int i = 0;i < players;i++)
	{
		pad[i].Update(wnd.kbd, dt, i);
	}
	if (players == 1)
	{
		pad[1].Control(dt, ball);
	}
	for (int i = 0;i < 2;i++)
	{

		pad[i].DoWallCollision(walls.rect);
		pad[i].DoBallCollision(ball);
	}
	ball.Update(dt);
	Ball::WallCollisions col = ball.DoWallCollision(walls.rect);
	if (col == Ball::WallCollisions::Top)
	{
		sc[0].Add();
		ball.Reset();
	}
	else if (col == Ball::WallCollisions::Bottom)
	{
		sc[1].Add();
		ball.Reset();
	}
}

void Game::ComposeFrame()
{
	for (int i = 0;i < 2;i++)
	{
		pad[i].Draw(gfx);
	}
	sc[0].Draw(Vec2(28, Graphics::ScreenHeight - 66), gfx);
	sc[1].Draw(Vec2(28, 3), gfx);
	ball.Draw(gfx);
	walls.Draw(gfx);
}
