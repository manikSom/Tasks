#pragma once
#include "geometry.h"
#include "GeometryUtility.h"
#include "GeometryContainer.h"
#include <vector>

typedef struct Point {
	double _x;
	double _y;
	Point(double xCoord, double yCoord) : _x(xCoord), _y(yCoord) {}
}Point;

class GeometryUtility
{
public:
	GeometryUtility();
	~GeometryUtility();
	bool computeIntersectionPoints(GeometryContainer, size_t, size_t, std::vector<Point>&);

private:
	Point ii, jj;
	double fx, fy, gx, gy, d;
};
