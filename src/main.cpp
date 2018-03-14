#include <iostream>
#include "sqr.h"

int main() {
    sqr x = sqr(33.0);
    std::cout << x.get() << std::endl;

}