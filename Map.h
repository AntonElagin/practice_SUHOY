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
    std::vector<Point> quaters[5];
    bool quater;
    double k;
public:
    Map();
    void setTargets(const std::vector<Point>& _targets);
    double getBestAngle();
    bool getQuater();
};


#endif //MODULE_3_MAP_H
