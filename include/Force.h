#pragma once

#include "Default.h"

/*
    Describes a basic Force defined by a Magnitude and an Angle
    specifying It's Direction of Effect.
*/

class Force{

private:
    //Angle of the Force's Direction of Effect [Degrees]
    double m_angle = 0.0f;

    //Magnitude of the Force
    double m_magnitude = 0.0f;

public:
    //Default Ctor
    Force(void);

    //Construct Force from Angle and Magnitude
    Force(double angle, double mag);

    //Getters
    inline double getAngle    (void) const{ return m_angle; }
    inline double getMagnitude(void) const{ return m_magnitude; }

    //Setters
    inline void setAngle    (double angle) { m_angle = angle; }
    inline void setMagnitude(double mag)   { m_magnitude = mag; }
};
