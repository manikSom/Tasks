#include "GeometryUtility.h"
#include "GeometryContainer.h"
#include <iostream>
#include <memory>
#include <vector>

utility::geometry::GeometryUtility::GeometryUtility()
    : R{0.0}, fx{0.0}, fy{0.0}, gx{0.0}, gy{0.0}, ii{0.0 ,0.0},jj{0.0 ,0.0}, d{0.0}
{
    std::cout << "Created GeometryUtility" << std::endl;
};

utility::geometry::GeometryUtility::~GeometryUtility()
{
    std::cout << "Destroyed GeometryUtility" << std::endl;
};


bool utility::geometry::GeometryUtility::computeIntersectionPoints(
    utility::geometry::GeometryContainer geomCont, 
    size_t i, size_t j, 
    std::vector<utility::geometry::Point>& intersectionPoints)
{
    /*Calculating xy coords of 2 intersection points:
        Use of pow is bad for performance. Just for ease of understanding 
        the algorithm it is written this way for this small task only. 

        Better method is definitely:
        m_R2= m_r*m_r
        m_R4 = m_R2*m_R2 
        so on and so forth */ 

    /*  x1 = geomCont.shapes[i].x     y1 = geomCont.shapes[i].y   r1= geomCont.shapes[i].radius
    *   x2 = geomCont.shapes[j].x     y2 = geomCont.shapes[j].y   r2= geomCont.shapes[j].radius
    */

    // Calculating x coords of 2 intersection points

    R = sqrt(pow((geomCont.shapes[j].x - geomCont.shapes[i].x), 2) +
        pow((geomCont.shapes[j].y - geomCont.shapes[i].y), 2));

    fx = (geomCont.shapes[i].x + geomCont.shapes[j].x) / 2;
    fx = fx + ((pow(geomCont.shapes[i].radius, 2) - pow(geomCont.shapes[j].radius, 2)) / (2 * pow(R, 2))) *
        (geomCont.shapes[j].x - geomCont.shapes[i].x);

    gx = (2 * ((pow(geomCont.shapes[i].radius, 2) + pow(geomCont.shapes[j].radius, 2))) / pow(R, 2)) -
        (pow((pow(geomCont.shapes[i].radius, 2) - pow(geomCont.shapes[j].radius, 2)), 2) / pow(R, 4)) - 1;

    ii._x = fx + (sqrt(gx) * (geomCont.shapes[j].y - geomCont.shapes[i].y)) / 2;
    jj._x = fx - (sqrt(gx) * (geomCont.shapes[j].y - geomCont.shapes[i].y)) / 2;

    // Calculating y coords of 2 intersection points

    fy = (geomCont.shapes[i].y + geomCont.shapes[j].y) / 2;
    fy = fy + ((pow(geomCont.shapes[i].radius, 2) - pow(geomCont.shapes[j].radius, 2)) / (2 * pow(R, 2))) *
        (geomCont.shapes[j].y - geomCont.shapes[i].y);
    gy = (2 * ((pow(geomCont.shapes[i].radius, 2) + pow(geomCont.shapes[j].radius, 2))) / pow(R, 2)) -
        (pow((pow(geomCont.shapes[i].radius, 2) - pow(geomCont.shapes[j].radius, 2)), 2) / pow(R, 4)) - 1;

    ii._y = fy + (sqrt(gy) * (geomCont.shapes[j].x - geomCont.shapes[i].x)) / 2;
    jj._y = fy - (sqrt(gy) * (geomCont.shapes[j].x - geomCont.shapes[i].x)) / 2;


    // How The circles touch - at 2 points or 1 point 

    d = sqrt((geomCont.shapes[i].x - geomCont.shapes[j].x) * (geomCont.shapes[i].x - geomCont.shapes[j].x)+
        +(geomCont.shapes[i].y - geomCont.shapes[j].y) * (geomCont.shapes[i].y - geomCont.shapes[j].y));

    if  ((geomCont.shapes[i].x == geomCont.shapes[j].x) && (geomCont.shapes[i].y == geomCont.shapes[j].y) &&
            (geomCont.shapes[i].radius == geomCont.shapes[j].radius))
    {
        std::cout << "Circle " << i << " and " << j << " touch each other in infinite points." << std::endl;
    }
    else if (d <= geomCont.shapes[i].radius - geomCont.shapes[j].radius) {
        std::cout << "Circle "<< j <<"is inside circle"<< i<< std::endl ;
    }
    else if (d <= geomCont.shapes[j].radius - geomCont.shapes[i].radius) {
        std::cout << "Circle "<< i << "is inside circle "<< j << std::endl;
    }
    else if (d < geomCont.shapes[i].radius + geomCont.shapes[j].radius) {
        std::cout << "Circle "<< i<< " and " << j << " intersect with each other" << std::endl;
        intersectionPoints.push_back(ii);
        intersectionPoints.push_back(jj);
        return true;
    }
    else if (d == geomCont.shapes[i].radius + geomCont.shapes[j].radius) {
        std::cout << "Circle " << i << " and " << j << " touch each other." << std::endl;
        intersectionPoints.push_back(ii);
        return true;
    }
    else {
        std::cout << "Circle " << i << " and " << j << " do not touch each other." << std::endl;
    }

    return false;
}