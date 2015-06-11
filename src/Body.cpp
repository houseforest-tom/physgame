#include "Body.h"

#define DRAW_PRECISION 40

//Default Ctor
Body::Body(void){ ; }

//Construct Body from Mass and Radius
Body::Body(double mass, double radius){
    m_mass = mass;
    m_radius = radius;
}

//Construct Body from Mass, Radius and Position
Body::Body(double mass, double radius, double x, double y){
    m_mass = mass;
    m_radius = radius;
    m_pos.x = x;
    m_pos.y = y;
}

//Update the Body's Transformation
void Body::update(double dt){
    //Adjust X and Y Components of Position and Velocity
    m_vel += m_acc * dt;
    m_pos += m_vel * dt;
}

//Apply a Force to the Body
void Body::applyForce(const Force &force){
    m_acc.x += force.getMagnitude() * cosf(toRadians(force.getAngle())) / m_mass;
    m_acc.y -= force.getMagnitude() * sinf(toRadians(force.getAngle())) / m_mass;
}

//Draw the Body on the Screen
void Body::draw(void){

    glColor3ubv(m_color);

    //Move to Center of Mass
    glTranslatef(m_pos.x, m_pos.y, 0);

    //Draw Circle
    glBegin(GL_TRIANGLE_FAN);
        double angle;
        for(int i = 0; i <= 360; i += 360 / DRAW_PRECISION){
            angle = i / 180.0f * 3.1416f;
            glVertex2f(m_radius * cos(angle), m_radius * -sin(angle));
        }
    glEnd();

    //Draw Velocity & Acceleration Vectors
    glBegin(GL_LINES);
        glColor3ub(0, 0, 255);
        glVertex2f(0, 0);
        glVertex2f(m_vel.x, m_vel.y); //v
        glColor3ub(0, 255, 0);
        glVertex2f(0, 0);
        glVertex2f(m_acc.x * 10, m_acc.y * 10); //a
    glEnd();

    //Move back to Origin
    glTranslatef(-m_pos.x, -m_pos.y, 0);
    glColor3f(1, 1, 1);
}
