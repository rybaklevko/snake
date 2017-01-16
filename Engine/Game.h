#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include"Board.h"
#include"Snake.h"
#include"SpriteCodex.h"
#include"Goal.h"
#include"EnemySquare.h"
#include<vector>
#include<random>
#include<time.h>
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Board brd;
	Board border;
	Snake snek;
	Location delta_loc = {1,0};
	Location bordLocation = { 20,20 };
	Goal gl;
	//EnemySquare enmsqr[10];
	EnemySquare enemy;
	//auto it = enmsqr.begin();
	 int SnakeMovePeriod = 18;
	int nSnakeMoveCounter = 0;
	bool GameIsOver = false;
};