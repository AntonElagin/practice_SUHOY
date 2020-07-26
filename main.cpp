#include <iostream>
#include "Map.h"
#include "Point.h"

int main() {
    Map map;
    Point a(11,4), b(4,3), c(5,3), d(-2,5), e(-10,  -10);
    std::vector<Point> vector = {a, b, c, d, e};
    map.setTargets(vector);
    std::cout <<     map.getBestAngle() << std::endl;
    return 0;
}
