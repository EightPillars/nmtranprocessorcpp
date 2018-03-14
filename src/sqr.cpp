//
// Created by Stuart Moodie on 13/03/2018.
//

#include "sqr.h"


sqr::sqr(double x_val) : x(x_val) {
}

double sqr::get() const {
    return x*x;
}
