//
// Created by anton1202 on 22.07.2020.
//

#ifndef MODULE_3_POINT_H
#define MODULE_3_POINT_H


class Point {
    int x,y;

public:
    Point();
    Point(const int& _x,const int& _y);
    Point(const Point& point);
    void set(const int& _x,const int& _y);
    int getX() const;
    int getY() const ;
};


#endif //MODULE_3_POINT_H
