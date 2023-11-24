/**
 * @file ballpit.cpp
 * @author Josh Gillum
 * @brief Ballpit class function implementations
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ballpit.h"


Ballpit::Ballpit(unsigned numBalls){
    mNumBalls = numBalls;

    Ball* ptr = nullptr;
    for(unsigned i = 0; i < mNumBalls; ++i){
        ptr = new Ball(sf::Vector2f(200*(i+1),200),40,sf::Color::Green);
        mBalls.push_back(ptr);
    }

}



Ballpit::~Ballpit(){
    for(unsigned i = 0; i < mBalls.size(); ++i){
        if(mBalls[i] != nullptr){
            delete mBalls[i];
            mBalls[i] = nullptr;
        }
    }
}


/**
 * @brief Checks the collision betwen two balls
 * 
 * @param ballOne, one of the two balls
 * @param ballTwo, the other of the two balls
 * @return true, they are colliding
 * @return false, they are not colliding
 */
bool Ballpit::checkCollision(const Ball& ballOne, const Ball& ballTwo){
    double distance = 0;
    double maxDistance = 0;

    maxDistance = ballOne.radius() + ballTwo.radius();

    double x = 0, y = 0;

    x = ballOne.x() - ballTwo.x();
    if(x < 0) { x *= -1; }

    y = ballOne.y() - ballTwo.y();
    if(y < 0) { y *= -1; }

    distance = (x * x) + (y * y);

    distance = std::sqrt(distance);

    if(distance > maxDistance) { return false; }
    return true;
}


void Ballpit::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(unsigned i = 0; i < mNumBalls; ++i){
        if(mBalls[i] != nullptr){
            mBalls[i]->draw(target,states);
        }
    }
}

void Ballpit::move() {
    for(unsigned i = 0; i < mNumBalls; ++i){
        if(mBalls[i] != nullptr){
            mBalls[i]->move();
        }
    }
}