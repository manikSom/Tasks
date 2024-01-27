#pragma once
#include "geometry.h"
#include "GeometryUtility.h"
#include <vector>

class utility::geometry::GeometryUtility
{
public:
	GeometryUtility();
	~GeometryUtility();
	bool computeIntersectionPoints(utility::geometry::GeometryContainer, size_t, size_t, std::vector<utility::geometry::Point>&);

private:
	utility::geometry::Point ii, jj;
	double R, fx, fy, gx, gy, d;
};
