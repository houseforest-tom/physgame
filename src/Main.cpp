#define WIDTH     1920
#define HEIGHT    1080
#define FULLSCRN     1
#define TIME_FACTOR  1

#include "Default.h"
#include "Force.h"
#include "Body.h"

void setupVideo(SDL_Surface *screen);

int main(int argc, char **argv){

    //Physicalical Constants
    double m_sun    = 332964,   r_sun   = 109,
           m_earth  = 1,        r_earth = 500,      v_earth = sqrt(m_sun / r_earth);


    uint64_t ticks = SDL_GetTicks(), dt = 0;

    argc = (int)argv;

    Body bodies[10];
    uint32_t nBodies = sizeof(bodies) / sizeof(bodies[0]);

    srand(ticks);

    bodies[0].setPosition(WIDTH / 2, HEIGHT / 2);
    bodies[0].setMass(m_sun);
    bodies[0].setRadius(r_sun);
    bodies[0].setColor(255, 150, 0);

    for(uint32_t i=1; i<nBodies; ++i){
        bodies[i].setPosition(WIDTH / 2 - 500 + rand() % 1000, HEIGHT / 2 - 500 + rand() % 1000);
        bodies[i].setMass(rand() % 200);
        bodies[i].setRadius(rand() % 20);
        bodies[i].setVelocity(rand() % 5, rand() % 5);
        bodies[i].setColor(50 + rand() % 205, 50 + rand() % 205, 50 + rand() % 205);
    }

    //Event Buffer
    SDL_Event event;

    //Screen Object
    SDL_Surface *pScreen = nullptr;

    //Setup Screen etc.
    setupVideo(pScreen);

    bool done = false;

    //Main Loop
    while (!done){

        //Handle Messages
        while (SDL_PollEvent(&event)){

            switch (event.type){

            /* Quit when either [ESC] or the Window [X] were pressed */
            case SDL_QUIT:
                done = true;
            break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
            break;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        Force bufForce;
        Vector2f distance;
        double    angle     = 0.0f;
        double    magnitude = 0.0f;

        if(SDL_GetTicks() > 2000){
            for(uint32_t i=0; i<nBodies; ++i){

                //Passed Time since last Frame in Seconds
                bodies[i].update(dt * TIME_FACTOR / 1000.0f);
                bodies[i].resetAcceleration();
            }

            //Determine attracting Forces affecting Body I
            for(uint32_t i=0; i<nBodies; ++i){
                for(uint32_t j=0; j<nBodies; ++j){

                    if( i == j ) continue;

                    //J attracts I
                    distance  = bodies[j].getPos();
                    distance -= bodies[i].getPos();

                    cout << "Distance["<<i<<","<<j<<"] = ("<<distance.x<<","<<distance.y<<")"<<endl;

                    angle = toDegrees(atan2f(-distance.y, distance.x));
                    bufForce.setAngle(angle);

                    cout << "Angle["<<i<<","<<j<<"] = ("<<angle<<endl;

                    magnitude  =  bodies[i].getMass() * bodies[j].getMass();
                    magnitude /= (SQR(distance.getLength()) > 1 ? SQR(distance.getLength()) : 1);
                    bufForce.setMagnitude(magnitude);

                    bodies[i].applyForce(bufForce);

                    cout << "Body[" << i << "] m=" << bodies[i].getMass() << "kg attracted by Body[" << j << "] m=" << bodies[j].getMass() << "; @=" << angle << "°; F=" << magnitude << endl;
                }
            }
        }

        for(uint32_t i=0; i<nBodies; ++i){
            bodies[i].draw();
        }

        //Flip Back Buffer
        SDL_GL_SwapBuffers();

        {
            SDL_Delay(1);
            uint64_t tmp = ticks;
            ticks = SDL_GetTicks();
            dt = ticks - tmp;
        }
    }

    SDL_Quit();

    return 0;
}

void setupVideo(SDL_Surface *screen){

    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create Screen
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL | (FULLSCRN ? SDL_FULLSCREEN : 0));
    SDL_WM_SetCaption("Physic's Simulation Game     -     (C) Tom Hauswald, 2014", nullptr);

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE,     8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,   8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE,    8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE,   8 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
    glMatrixMode(GL_MODELVIEW);
}
