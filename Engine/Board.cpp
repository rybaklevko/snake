#include "Board.h"
#include<assert.h>
Board::Board(Graphics & gfx):
	gfx(gfx)
{
}

void Board::DrawCell(const Location &loc , Color c)
{
	/*assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);*/
	Color clr = Colors::Black;
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension, dimension, c);
	gfx.DrawRectBorder(loc.x*dimension, loc.y*dimension, dimension, dimension, clr);
}

void Board::DrawBorder(const Location & loc, Color c)
{
	gfx.DrawRectBorder(loc.x, loc.y, borderwidth,borderheigt, c);
}

int Board::get_height()
{
	return height;
}

int Board::get_width()
{
	return width;
}

int Board::get_borderheight()
{
	return borderheigt;
}

int Board::get_borderwidth()
{
	return borderwidth;
}

int Board::get_dimension()
{
	return dimension;
}

bool Board::IsInsideBoard(Location & loc) const
{
	return loc.x<=0 && loc.x>=width 
		&& loc.y<=0 && loc.y>=height;
}

bool Board::IsInsideBorder(Location & loc) const
{
	return loc.x*dimension<20 || loc.x*dimension>borderwidth || loc.y*dimension<20 || loc.y*dimension>borderheigt;
}
