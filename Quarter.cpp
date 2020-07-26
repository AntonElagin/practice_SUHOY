//
// Created by anton1202 on 22.07.2020.
//

#include "Quarter.h"
#include "MathFunc.h"
#include <math.h>





void Quarter::calculateCover() {
    

}

Quarter::Quarter() {
    this->setAngles(0,90, 1);

}

Quarter::Quarter(const std::vector<Point> & _targets) {
    this->setTargets(_targets);
    this->setAngles(0,90, 1);
}

bool Quarter::setAngles(int min, int max, double step) {
    if (min > max || step > max) {
        return false;
    }
    this->minAngle = min;
    this->maxAngle = max;
    this->angleStep = step;
    return true;
}

void Quarter::setTargets(const std::vector<Point> & _targets) {
    this->targets = _targets;
}

double Quarter::getCover() {
    this->cover = 0;
    this->k = 0;
    for (double i = this->minAngle + this->angleStep; i < maxAngle;  i += this->angleStep) {
        const double k = tan(i * 3.14 / 180);
        int targetsCount = 0;
        for (const auto& target: this->targets) {
            if (
                    MathFunc::funcTop(target.getX(), k) >= target.getY()
                    && MathFunc::funcDown(target.getX(), k) <= target.getY()
                    && MathFunc::funcInvert(target.getX(), k) <= target.getY()
                    ) {
                targetsCount +=1;
            }
        }
        if (targetsCount > this->cover) {
            this->cover = targetsCount;
            this->k = k;
        }
    }
    return this->k;
}

double Quarter::getK() {
    return this->k;
}
