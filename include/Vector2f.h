#pragma once

#include "Default.h"

/*
    Represents a 2-dimensional Vector of Floats.
*/

class Vector2f{

public:
    //Components of the Vector
    double x = 0, y = 0;

    //Default Ctor
    Vector2f(void);

    //Construct Vector from X- and Y-Values
    Vector2f(double x, double y);

    //Copy Ctor
    Vector2f(const Vector2f &other);

    //Calculate and return Length
    double getLength(void) const;

    //Caluculate and return enclosed Angle w/ X-Axis
    double getAngle(void) const;

    //Component-wise Addition
    inline Vector2f operator +(const Vector2f &rhs){ return Vector2f(x + rhs.x, y + rhs.y); }
    inline void operator +=(const Vector2f &rhs){ x += rhs.x; y += rhs.y; }

    //Component-wise Subtraction
    inline Vector2f operator -(const Vector2f &rhs){ return Vector2f(x - rhs.x, y - rhs.y); }
    inline void operator -=(const Vector2f &rhs){ x -= rhs.x; y -= rhs.y; }

    //Scalar Multiplication
    inline Vector2f operator *(double factor){ return Vector2f(x * factor, y * factor); }
    inline void operator *=(double factor){ x *= factor; y *= factor; }
};
