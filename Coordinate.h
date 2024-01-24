#pragma once

#include <unordered_map>

struct coordinate
{
	int x;
	int y;

	coordinate(): x(-1), y(-1) {};
	coordinate(int xcoord, int ycoord): x(xcoord), y(ycoord) {};

	bool operator==(const coordinate& rhs) const
	{
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
};

namespace std
{
	template<>
	struct hash<coordinate>
	{
		size_t operator()(const coordinate& s) const
		{
			size_t h1 = hash<int>()(s.x);
			size_t h2 = hash<int>()(s.y);
			return h1 ^ (h2 << 1);
		}
	};
}
