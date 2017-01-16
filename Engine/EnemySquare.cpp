#include "EnemySquare.h"

EnemySquare::EnemySquare(Board & brd, Snake &snk,Goal &gl)
{
	EnemyRespawn(brd, snk,gl);
}

void EnemySquare::EnemyRespawn(Board &brd, Snake &snk,Goal &gl)
{
	bool IsCorrectGenerate;
	Location loc;
	do {
				srand(time(NULL));
				loc.x = rand() % (brd.get_width() - 1);
				loc.y = rand() % (brd.get_height() - 1);
				IsCorrectGenerate = (loc.x*brd.get_dimension() < brd.get_borderwidth() - brd.get_dimension() - 20 &&
					loc.x*brd.get_dimension() >= 20 &&
					loc.y*brd.get_dimension() < brd.get_borderheight() - brd.get_dimension() - 20 &&
					loc.y*brd.get_dimension() >= 20);
	} while (snk.IsEatItself(loc) ||
		gl.GetGoalLocation() == loc || 
		!IsCorrectGenerate);
	locEnemy = loc;
}

Location EnemySquare::GetEnemyLocation()
{
	return locEnemy;
}

void EnemySquare::DrawEnemy(Board &brd) const
{
	brd.DrawCell(locEnemy, cEnemy);
}
