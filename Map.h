//
// Created by anton1202 on 20.07.2020.
//

#ifndef MODULE_3_MAP_H
#define MODULE_3_MAP_H

#include <vector>
#include "Point.h"


class Map {
private:
    int targetsCount;
    std::vector<Point> targets;
    double k;
public:
    Map();
    void setTargets(const std::vector<Point>& _targets);
    double getAngle(double _angleStep);
};


#endif //MODULE_3_MAP_H
