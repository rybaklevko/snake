#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek({ 2,2 }),
	gl(brd,snek),
	border(gfx),
	enemy(brd,snek,gl)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
		++nSnakeMoveCounter;
		
		if (nSnakeMoveCounter >= SnakeMovePeriod)
		{
			Location next = snek.GetNextHeadLocation(delta_loc);
			nSnakeMoveCounter = 0;
			if (brd.IsInsideBoard(next) ||
				snek.IsEatItself(next)||
				border.IsInsideBorder(next)||
				next==enemy.GetEnemyLocation())
			{
				GameIsOver = true;
			}
			else {
				const bool eating = (next == gl.GetGoalLocation());
				if (eating)
				{
					snek.Grow();
					/*nSnakeMoveChange+=3;
					nSnakeMoveCounter += nSnakeMoveChange;*/
					--SnakeMovePeriod;
				}
				snek.MoveBy(delta_loc);
				if (eating) 
				{
					gl.Respawn(brd, snek);
					//enmsqr[0].EnemyRespawn(brd, snek);
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	snek.Draw(brd);
	gl.Draw(brd);
	border.DrawBorder(bordLocation, Colors::Gray);
	enemy.DrawEnemy(brd);
	if (GameIsOver)
	{
		SpriteCodex::DrawGameOver(350,275,gfx);
	}
	/*srand(time(NULL));
	for(int x=0;x<brd.get_width();x++)
		for(int y=0;y<brd.get_height();y++)
		{
			Location loc = { x,y };
			Color c(rand() % 255, rand() % 255, rand() % 255);
			brd.DrawCell(loc,c);
		}*/

}
