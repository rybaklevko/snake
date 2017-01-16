#pragma once
#include"Board.h"
#include"Location.h"
#include"Snake.h"
#include"Graphics.h"
#include<random>
#include<time.h>
class Goal {
public:
	Goal(Board &brd, Snake &snake);
	void Respawn(Board &brd, Snake &snake);
	void Draw(Board &brd)const;
	Location GetGoalLocation();
private:
	Location locGoal;
	Color cGoal = Colors::Red;
};