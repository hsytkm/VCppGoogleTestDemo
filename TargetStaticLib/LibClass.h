#pragma once

namespace MyStaticLib {

    class LibClass
    {
    public:
        int AddValues(int x, int y) const noexcept;
        double DivideValues(int nume, int denom) const;

    };
}
