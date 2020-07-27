//
// Created by anton1202 on 20.07.2020.
//

#include <math.h>
#include "Map.h"
#include "MathFunc.h"


void Map::setTargets(const std::vector<Point>& _targets) {
    this->targets = _targets;
    this->targetsCount = _targets.size();
}

Map::Map() {
    return;
}

double Map::getAngle(double _angleStep) {
    double minAngle = 0;
    double maxAngle = 359;
    double angleStep = _angleStep;
    int cover =0;
    this->k = 0;
    for (double i = minAngle + angleStep; i < maxAngle;  i += angleStep) {
        const double k = tan(i * 3.14 / 180);
        int targetsCount = 0;
        for (const auto& target: this->targets) {
            if (i == 0 || i == 180) {
                if (i == 0) {
                    if ( target.getX() > 0 && ( target.getY() > -10 || target.getY() < -10 )) {
                        targetsCount +=1;
                    }
                } else {
                    if ( target.getX() < 0 && ( target.getY() > -10 || target.getY() < -10 )) {
                        targetsCount +=1;
                    }
                }
            } else
                if (i < 180) {
                    if (
                            MathFunc::funcTop(target.getX(), k) >= target.getY()
                            && MathFunc::funcDown(target.getX(), k) <= target.getY()
                            && MathFunc::funcInvert(target.getX(), k) <= target.getY()
                            ) {
                        targetsCount += 1;

                    }
                } else {
                    if (
                            MathFunc::funcTop(target.getX(), k) >= target.getY()
                            && MathFunc::funcDown(target.getX(), k) <= target.getY()
                            && MathFunc::funcInvert(target.getX(), k) >= target.getY()
                    ) {
                        targetsCount += 1;
                    }
                }
        }

        if (targetsCount > cover) {
            cover = targetsCount;
            this->k = i;
        }
    }
    return this->k;
}

