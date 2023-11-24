/**
 * @file ballpit.h
 * @author Josh Gillum
 * @brief Ballpit class definition. Offers a way to manage multiple ball objects
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BALLPIT_H
#define BALLPIT_H

#include <vector>
#include <cmath>

#include "ball.h"

class Ballpit : public sf::Drawable{

    public:

        Ballpit() : Ballpit(20) {};
        Ballpit(unsigned numBalls);
        ~Ballpit();

        bool checkCollision(const Ball& ballOne, const Ball& ballTwo); // Checkes collision between every ball

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // Draws the balls

        void move();

    protected:

        std::vector<Ball*> mBalls; // Stores the balls
        unsigned mNumBalls; // The number of balls in the ballpit


    private:

};




#endif