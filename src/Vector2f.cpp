#include "Vector2f.h"

//Default Ctor
Vector2f::Vector2f(void){ }

//Construct Vector from X- and Y-Values
Vector2f::Vector2f(double x, double y){
    this->x = x;
    this->y = y;
}

//Copy Ctor
Vector2f::Vector2f(const Vector2f &other){
    this->x = other.x;
    this->y = other.y;
}

//Calculate and return Length
double Vector2f::getLength(void) const{
    return sqrtf( x * x + y * y );
}

//Caluculate and return enclosed Angle w/ X-Axis
double Vector2f::getAngle(void) const{
    return atanf( -y / x );
}
