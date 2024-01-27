#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "GeometryContainer.h"
#include "GeometryUtility.h"

int main(int argc, char* argv[])
{
    utility::geometry::GeometryContainer geometryContainer;

    if (!geometryContainer.readGeometries(std::string(argv[1])))
    {
        std::cout << "Could not read circles file " << argv[1] << std::endl;
        return 0;
    }

    utility::geometry::GeometryUtility geometryUtility;

    std::vector<utility::geometry::Point> intersectionPoints;
    std::ofstream outfile(argv[2]);
    if (!outfile.is_open())
    {
        std::cout << "Could not open output file " << argv[3] << std::endl;
        return -1;
    }

    for (size_t i = 0; i < geometryContainer.numberOfGeometries(); ++i)
    {
        for (size_t j = i + 1; j < geometryContainer.numberOfGeometries(); ++j)
        {
            std::vector<utility::geometry::Point> intersectionPoints;
            outfile << "Results for geometry " << i << " vs geometry " << j << std::endl;
            if (geometryUtility.computeIntersectionPoints(geometryContainer, i, j, intersectionPoints))
            {
                if (intersectionPoints.size() == 0)
                {
                    outfile << "No intersection points found!" << std::endl;
                }
                else
                {
                    for (size_t i = 0; i < intersectionPoints.size(); ++i)
                    {
                        outfile << "Intersection point " << i << std::endl;
                        outfile << intersectionPoints[i]._x << " " << intersectionPoints[i]._y << std::endl;
                    }
                }
            }
            else
            {
                outfile << "Error determining intersection points, coz they don't touch or intersect!" << std::endl;
            }
        }
    }
    return 0;

}