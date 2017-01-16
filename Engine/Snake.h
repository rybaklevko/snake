#pragma once
#include"Colors.h"
#include"Location.h"
#include"Board.h"
#include<random>
class Snake {
private:
	class Segment {
	public:
		void InitHead(const Location&loc);
		void Body(Color c);
		void Follow(const Segment& next);
		void Draw(Board& brd)const;
		void MoveBy(const Location&delta_loc);
		Location Get_Location()const;
	private:
		Location locSegment;
		Color cSegment;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location&delta_loc);
	void Grow();
	void Draw(Board&brd)const;
	Location GetNextHeadLocation(const Location&)const;
	bool IsEatItself( Location &)const;
private:
	static constexpr Color headColor = Colors::Blue;
	//static constexpr Color bodyColor = Colors::Yellow;
	static constexpr int nSegmentMax = 100;
	int nSegments = 1;
	Segment segments[nSegmentMax];
};