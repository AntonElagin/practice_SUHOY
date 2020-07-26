//
// Created by anton1202 on 26.07.2020.
//

#include "MathFunc.h"

bool MathFunc::isInCircle(double x, double y) {
    return (x * x + y * y) < 100;
}

double MathFunc::funcTop(double x, double k) {
    return (k * x) + 10;
}

double MathFunc::funcDown(double x, double k) {
    return (k * x) - 10;
}

double MathFunc::funcInvert(double x, double k) {
    return -k * x;
}

