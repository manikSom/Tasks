# Tasks
 varied C++, pythons tasks and their solutions

## Shape Intersection

This [C++ Project](./ShapeIntersection/) takes in an [input file](./ShapeIntersection/Circles.txt), which contains 
information regarding properties of a certain shape. Right now it is
written keeping Circle in mind. The class structure is written in a
way to extend it to other geometries. The first line has the information
of which shape it is (0 = Circle)
This project reads the properies of all Circles like x & y coordinates
of the center and radius. And Finds out which circles intersects with each
other and in which points. The edge cases of them touching at only one point,
and 2 circles completely lying on top of each other is also considered. This
output is written into the [Output file](./ShapeIntersection/Output.txt)

In Visual Studio one needs to go to Properties-> Debugging-> Command Arguments
and enter "Circles.txt Output.txt" to be taken as input arguments (argv[]).

Future Improvements: Write out as an image to visualise the shapes and result. 
Also extend to other shapes and 3D.

## Continuous Prime String

This [simple C++ program](./ContinuousPrimeString/) Outputs a set of n digits that occur after the 
Nth digit when all prime numbers are written continously one after the 
other without space.

Example: If 3 digits after the 10th digit in such a continous number
is expected then the out shall be:
2357111317**192**3293137....