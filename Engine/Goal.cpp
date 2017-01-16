#include "Goal.h"

Goal::Goal(Board & brd, Snake & snake)
{
	Respawn(brd, snake);
}

void Goal::Respawn(Board & brd, Snake & snake)
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
	} while (snake.IsEatItself(loc) || !IsCorrectGenerate);
	locGoal = loc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(locGoal, cGoal);
}

Location Goal::GetGoalLocation()
{
	return locGoal;
}
