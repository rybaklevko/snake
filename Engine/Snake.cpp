#include "Snake.h"

Snake::Snake(const Location & loc)
{
	
	Color PullofColours[4] = {
		{10,100,32},
		{10,150,48},
		{18,180,100},
		{10,150,48}
	};
	for (int i(0); i <nSegmentMax; i++)
	{
		segments[i].Body(PullofColours[i%4]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentMax) {
		//segments[nSegments].Body();
		++nSegments;
		
	}

}

void Snake::Draw(Board & brd) const
{
	for (int i(0); i < nSegments; i++)
		segments[i].Draw(brd);
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].Get_Location());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsEatItself( Location & body) const
{
	bool IsEat = false;
	for (int i(0); i < nSegments; i++)
	{
		if (segments[i].Get_Location()==body)
			IsEat=true;

	}
	return IsEat;
}

void Snake::Segment::InitHead(const Location & loc)
{
	locSegment.x = loc.x;
	locSegment.y = loc.y;
	cSegment = Snake::headColor;
}

void Snake::Segment::Body(Color c)
{
	cSegment = c;
}

void Snake::Segment::Follow(const Segment & next)
{
	locSegment = next.locSegment;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(locSegment, cSegment);
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	locSegment.Add(delta_loc);
}

Location Snake::Segment::Get_Location()const
{
	return locSegment;
}
