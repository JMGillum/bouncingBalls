#ifndef BALLPIT_H
#define BALLPIT_H

#include <vector>

#include "ball.h"

class Ballpit : public sf::Drawable{

    public:

        Ballpit() : Ballpit(20) {};
        Ballpit(unsigned numBalls);
        ~Ballpit();


        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:

        std::vector<Ball*> mBalls;
        unsigned mNumBalls;


    private:

};




#endif