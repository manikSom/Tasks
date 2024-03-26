#include "GeometryUtility.h"
#include "GeometryContainer.h"
#include <iostream>
#include <memory>
#include <vector>

GeometryUtility::GeometryUtility()
    :fx{0.0}, fy{0.0}, gx{0.0}, gy{0.0}, ii{0.0 ,0.0},jj{0.0 ,0.0}, d{0.0}
{
    std::cout << "Created GeometryUtility" << std::endl;
};

GeometryUtility::~GeometryUtility()
{
    std::cout << "Destroyed GeometryUtility" << std::endl;
};


bool GeometryUtility::computeIntersectionPoints(
    GeometryContainer geomCont, 
    size_t i, size_t j, 
    std::vector<Point>& intersectionPoints)
{

    /*  x1 = geomCont.shapes[i].x     y1 = geomCont.shapes[i].y   r1= geomCont.shapes[i].radius
    *   x2 = geomCont.shapes[j].x     y2 = geomCont.shapes[j].y   r2= geomCont.shapes[j].radius
    */

     //Calculating x coords of 2 intersection points
    double A = geomCont.shapes[j].x - geomCont.shapes[i].x;
    double A_2 = A * A;
    double B = geomCont.shapes[j].y - geomCont.shapes[i].y;
    double B_2 = B * B;
    double R1_2 = geomCont.shapes[i].radius * geomCont.shapes[i].radius;
    double R2_2 = geomCont.shapes[j].radius * geomCont.shapes[j].radius;
    double C = R1_2 - R2_2;
    double C_2 = C * C;

    double R = sqrt(A_2 + B_2);
    double R_2 = R * R;
    double R_4 = R_2 * R_2;

    fx = (geomCont.shapes[i].x + geomCont.shapes[j].x) / 2;
    fx = fx + (C / (2 * R_2)) * A;

    gx = (2 * ((R1_2 + R2_2)) / R_2) -
        (C_2 / R_4) - 1;

    ii._x = fx + (sqrt(gx) * B) / 2;
    jj._x = fx - (sqrt(gx) * B) / 2;

    // Calculating y coords of 2 intersection points

    fy = (geomCont.shapes[i].y + geomCont.shapes[j].y) / 2;
    fy = fy + (C / (2 * R_2)) * B;
    gy = (2 * ((R1_2 + R2_2)) / R_2) -
        (C_2 / R_4) - 1;

    ii._y = fy + (sqrt(gy) * A) / 2;
    jj._y = fy - (sqrt(gy) * A) / 2;


    // How The circles touch - at 2 points or 1 point 

    d = sqrt((geomCont.shapes[i].x - geomCont.shapes[j].x) * (geomCont.shapes[i].x - geomCont.shapes[j].x)+
        +(geomCont.shapes[i].y - geomCont.shapes[j].y) * (geomCont.shapes[i].y - geomCont.shapes[j].y));

    if  ((geomCont.shapes[i].x == geomCont.shapes[j].x) && (geomCont.shapes[i].y == geomCont.shapes[j].y) &&
            (geomCont.shapes[i].radius == geomCont.shapes[j].radius))
    {
        std::cout << "Circle " << i << " and " << j << " touch each other in infinite points." << std::endl;
    }
    else if (d <= geomCont.shapes[i].radius - geomCont.shapes[j].radius) {
        std::cout << "Circle "<< j <<" is inside circle"<< i<< std::endl ;
    }
    else if (d <= geomCont.shapes[j].radius - geomCont.shapes[i].radius) {
        std::cout << "Circle "<< i << " is inside circle "<< j << std::endl;
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


