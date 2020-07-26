//
// Created by anton1202 on 20.07.2020.
//

#include "Map.h"
#include "MathFunc.h"
#include "Quarter.h"


void Map::setTargets(const std::vector<Point>& _targets) {
    this->targets = _targets;
    this->targetsCount = _targets.size();
    for (const auto& point : this->targets) {
        if ( MathFunc::isInCircle(point.getX(), point.getY())) {
            this->quaters[4].push_back(point);
        } else if ( point.getX() * point.getY() > 0 ) {
            if (point.getX() > 0) {
                this->quaters[0].push_back(point);
            } else {
                this->quaters[2].push_back(point);
            }
        } else {
            if (point.getX() > 0) {
                this->quaters[1].push_back(point);
            } else {
                this->quaters[3].push_back(point);
            }
        }
    }
}

double Map::getBestAngle() {
    double cover[4];
    double angle[4];
    for (int i =0; i < 4; i++) {
        cover[0] = 0;
            angle[0] = 0;
    }
    int min = 0;
    int max =90;
    for (int i = 0; i < 4; i++) {
        Quarter quarter;
        quarter.setTargets(this->quaters[i]);
        quarter.setAngles(0,90,1);
        cover[i] = quarter.getCover();
        angle[i] = quarter.getK();
    }
    double a = std::max(cover[0], cover[1]);
    double b = std::max(cover[2], cover[3]);
    if (a > b) {
        this->k = (cover[0] > cover[1]) ? angle[0] : angle[1];
        this->quater = true;
    } else {
        this->k = (cover[2] > cover[3]) ? angle[2] : angle[3];
        this->quater = false;
    }
    return this->k;
}

bool Map::getQuater() {
    return this->quater;
}

Map::Map() {
    return;
}

