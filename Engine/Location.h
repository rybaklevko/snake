#pragma once
struct Location {
	void Add(const Location &value) { x += value.x; y += value.y; }
	int x;
	int y;
	bool operator==(Location obj2)
	{
		return (x == obj2.x && y == obj2.y);
	}
};