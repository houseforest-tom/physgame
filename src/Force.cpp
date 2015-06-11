#include "Force.h"

//Default Ctor
Force::Force(void)
    : m_angle(0.0f),
      m_magnitude(0.0f){
}

//Construct Force from Angle and Magnitude
Force::Force(double angle, double mag)
    : m_angle(angle),
      m_magnitude(mag){
}
