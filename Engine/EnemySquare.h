#pragma once
#include"Location.h"
#include "Colors.h"
#include"Board.h"
#include"Snake.h"
#include"Goal.h"
class EnemySquare {
public:
	EnemySquare(Board&, Snake&,Goal&);
	void EnemyRespawn(Board&, Snake&,Goal&);
	Location GetEnemyLocation();
	void DrawEnemy(Board&)const;
private:
	Location locEnemy;
	Color cEnemy = Colors::Gray;

};