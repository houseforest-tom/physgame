#pragma once

#include "Default.h"
#include "Force.h"
#include "Vector2f.h"

/*
    Describes the physical Body of a circular Shape of the given Radius
    containing the specified Mass. Keeps Track of Acceleration, Movement Speed
    and current Position.
*/

class Body{

private:
    //The Body's Position, Velocity & Acceleration
    Vector2f m_pos = {}, m_vel = {}, m_acc = {};

    //Mass of the Body
    double m_mass = 1;

    //Radius of the Body
    double m_radius = 1;

    //Color of the Body
    uint8_t m_color[3] = { 1, 1, 1 };

public:
    //Default Ctor
    Body(void);

    //Construct Body from Mass and Radius
    Body(double mass, double radius);

    //Construct Body from Mass, Radius and Position
    Body(double mass, double radius, double x, double y);

    //Update the Body's Transformation
    void update(double dt);

    //Apply a Force to the Body
    void applyForce(const Force &force);

    //Draw the Body on the Screen
    void draw(void);

    //Getters
    inline const Vector2f &getPos (void) const{ return m_pos; }
    inline const Vector2f &getVel (void) const{ return m_vel; }
    inline const Vector2f &getAcc (void) const{ return m_acc; }
    inline double getMass  (void) const{ return m_mass;   }
    inline double getRadius(void) const{ return m_radius; }

    //Setters
    inline void setMass        (double mass)   { m_mass = (mass > 0 ? mass : 1); }
    inline void setRadius      (double radius) { m_radius = (radius > 0 ? radius : 1); }
    inline void setPosition    (double x, double y){ m_pos.x = x; m_pos.y = y; }
    inline void setVelocity    (double x, double y){ m_vel.x = x; m_vel.y = y; }
    inline void setAcceleration(double x, double y){ m_acc.x = x; m_acc.y = y; }
    inline void setColor       (uint8_t r, uint8_t g, uint8_t b){ m_color[0] = r; m_color[1] = g; m_color[2] = b; }

    //Reset Acceleration
    inline void resetAcceleration(void){ m_acc.x = 0; m_acc.y = 0; }
};
