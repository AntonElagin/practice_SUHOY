#include <iostream>
#include "Map.h"
#include "Point.h"

int main() {
    Map map;
    int targetCount;
    std::cout << "Write targets count: " ;
    std::cin >> targetCount;
    std::vector<Point> vector;
    for (int i = 0; i < targetCount; ++i) {
        int x,y;
        std::cout << "Target " << i << " :" << std::endl;
        std::cin >> x >> y;
        std::cout << std::endl;
        vector.emplace_back(x,y);
    }
    map.setTargets(vector);

    std::cout << "Angle: " << map.getAngle(1.0) << " degrees." << std::endl;
    return 0;
}
