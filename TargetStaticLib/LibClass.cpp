#include "pch.h"
#include "LibClass.h"
#include <stdexcept>

using namespace MyStaticLib;

int LibClass::AddValues(int x, int y) const noexcept {
    return x + y;
}

double LibClass::DivideValues(int nume, int denom) const {
    if (denom == 0) {
        throw std::runtime_error("denom is zero.");
    }

    return (double)nume / denom;
}
