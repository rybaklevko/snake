#pragma once
#include"Graphics.h"
#include"Location.h"
class Board {
public:
	Board(Graphics&);
	void DrawCell(const Location &, Color);
	void DrawBorder(const Location &, Color);
	int get_height();
	int get_width();
	int get_borderheight();
	int get_borderwidth();
	int get_dimension();
	bool IsInsideBoard(Location&)const;
	bool IsInsideBorder(Location &)const;
private:
	static constexpr int borderwidth = 700;
	static constexpr int borderheigt = 550;
	static constexpr int dimension = 20;
	static constexpr int height = 25;
	static constexpr int width = 25;
	Graphics &gfx;

};