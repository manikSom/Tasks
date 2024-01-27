#pragma once

namespace utility
{
	class geometry;
};

class utility::geometry
{
public:
	geometry();
	~geometry();
	class GeometryContainer;
	class GeometryUtility;
	typedef struct Point {
		double _x;
		double _y;
	}Point;
};

