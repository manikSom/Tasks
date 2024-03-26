#include "geometry.h"
#include <iostream>
#include <memory>

utility::geometry::geometry()
{
    std::cout << "Created geometry" << std::endl;
};

utility::geometry::~geometry()
{
    std::cout << "Destructed geometry" << std::endl;

};
