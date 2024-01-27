#include "GeometryContainer.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>

utility::geometry::GeometryContainer::GeometryContainer() : n{ 0 }, typeOfGeom{9}
{
    std::cout << "Created GeometryContainer" << std::endl;
};

utility::geometry::GeometryContainer::~GeometryContainer()
{
    std::cout << "Destroyed GeometryContainer" << std::endl;
};

size_t utility::geometry::GeometryContainer::numberOfGeometries()
{
    return n;
}

bool utility::geometry::GeometryContainer::readGeometries(std::string geomFile)
{
    std::string line;
    std::ifstream myfile(geomFile);
    std::string delimiter = " ";

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::vector<std::string> row;
            size_t pos = 0;
            std::string word;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                word = line.substr(0, pos);
                if (!word.empty()) { row.push_back(word); }
                line.erase(0, pos + delimiter.length());
            }
            row.push_back(line);
            geomData.push_back(row);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;

    typeOfGeom = std::stoi(geomData[0][0]);

    /*Creating Shapes If more shapes come in depending on the variable typeOfGeom
    * different shapes can be created
    */
    for (int i = 2; i < geomData.size(); i++)
    {
        shape shp_;
        shp_.setCircle(std::stod(geomData[i][0]), std::stod(geomData[i][1]), std::stod(geomData[i][2]));
        shapes.push_back(shp_);
    }

    /*  Based on the input file format the no. of geometry files is set
    *   If format of input file changes this needs to change too 
    */
    n = geomData.size() - 2; 

    return true;
}
