#ifndef SIMPLERAYTRACING_GEOMETRY_H
#define SIMPLERAYTRACING_GEOMETRY_H


#include <cmath>

struct Vec3f{
    float x, y, z;

    //Constructors
    Vec3f() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Vec3f(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float& operator[](int index) {
        if (index == 0) return x;
        else if (index == 1) return y;
        else if (index == 2) return z;
        else {
            // Handle out-of-range error
            throw std::out_of_range("Index out of range in Vec3f subscript operator.");
        }
    }
};

#endif //SIMPLERAYTRACING_GEOMETRY_H