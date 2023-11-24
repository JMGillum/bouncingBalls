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

        void checkCollision();
       
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // Draws the balls

        void move();

        void setScreenSize(sf::Vector2f size) { SCREEN_SIZE = size; }

        class ScreenSizeNotSpecified {};

    protected:

        std::vector<Ball*> mBalls; // Stores the balls
        unsigned mNumBalls; // The number of balls in the ballpit
        bool checkCollision(const Ball* ballOne, const Ball* ballTwo); // Checkes collision between every ball
        bool checkCollisionWalls(const Ball* ball);

        sf::Vector2f SCREEN_SIZE;



    private:

};




#endif