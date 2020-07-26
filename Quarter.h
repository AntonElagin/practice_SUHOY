//
// Created by anton1202 on 22.07.2020.
//

#ifndef MODULE_3_QUARTER_H
#define MODULE_3_QUARTER_H

#include <vector>
#include "Point.h"


class Quarter {
    int maxAngle;
    int minAngle;
    double angleStep;
    int cover;
    double k;
    std::vector<Point> targets;
    void calculateCover();
public:

    Quarter();
    Quarter(const std::vector<Point>&);
    bool setAngles(int , int, double );
    void setTargets(const std::vector<Point>&);
    double getCover();
    double getK();
};


#endif //MODULE_3_QUARTER_H
