//
// Created by anton1202 on 22.07.2020.
//

#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}
Point::Point(const int& _x,const int& _y) {
    this->x = _x;
    this->y = _y;
}
Point::Point(const Point& point) {
    this->x = point.x;
    this->y = point.y;
}
void Point::set(const int& _x,const int& _y) {
    this->x = _x;
    this->y = _y;
}
int Point::getX() const {
    return this->x;
}
int Point::getY() const  {
    return this->y;
}