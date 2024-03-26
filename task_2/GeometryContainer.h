#pragma once
#include "geometry.h"
#include <iostream>
#include <memory>
#include <vector>

typedef struct shape
{
    double x;
    double y;
    double radius;
    void setCircle(double x_, double y_, double r_)
    {
        x = x_;
        y = y_;
        radius = r_;
    }
}shape;

class GeometryContainer
{
public:
	size_t n;
    int typeOfGeom; // 0 for circle, 1 square, 2 for triangle etc. Got as input from txt file
    std::vector<shape> shapes; // Container that has all shapes, all circles or all squares etc..
    std::vector<std::vector<std::string>> geomData; //2D Vector to save all geometry related data from input file

	GeometryContainer();
	~GeometryContainer();
	bool readGeometries(std::string);
	size_t numberOfGeometries();
};

