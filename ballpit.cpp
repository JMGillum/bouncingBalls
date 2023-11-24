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
        ptr = new Ball(sf::Vector2f(200*(i+1),200),sf::Vector2f(1,3),40,sf::Color::Green);
        mBalls.push_back(ptr);
    }

    SCREEN_SIZE = sf::Vector2f(-1,-1);

}



Ballpit::~Ballpit(){
    for(unsigned i = 0; i < mBalls.size(); ++i){
        if(mBalls[i] != nullptr){
            delete mBalls[i];
            mBalls[i] = nullptr;
        }
    }
}


void Ballpit::checkCollision(){
    for(unsigned i = 0; i < mNumBalls - 1; i++){
        if(mBalls[i] != nullptr){
            for(unsigned j = i+1; j < mNumBalls; ++j){
                if(mBalls[j] != nullptr){
                    checkCollision(mBalls[i],mBalls[j]);
                }
            }
            checkCollisionWalls(mBalls[i]);
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
bool Ballpit::checkCollision(const Ball* ballOne, const Ball* ballTwo){
    double distance = 0;
    double maxDistance = 0;

    maxDistance = ballOne->radius() + ballTwo->radius();

    double x = 0, y = 0;

    x = ballOne->x() - ballTwo->x();
    if(x < 0) { x *= -1; }

    y = ballOne->y() - ballTwo->y();
    if(y < 0) { y *= -1; }

    distance = (x * x) + (y * y);

    distance = std::sqrt(distance);

    if(distance > maxDistance) { return false; }
    return true;
}

bool Ballpit::checkCollisionWalls(const Ball* ball){
    if(SCREEN_SIZE.x < ball->radius() || SCREEN_SIZE.y < ball->radius()){
        throw ScreenSizeNotSpecified();
    }
    if((ball->x() + ball->radius()) > SCREEN_SIZE.x){
        return true;
    }
    if((ball->x() - ball->radius()) < 0){
        return true;
    }
    if((ball->y() + ball->radius()) > SCREEN_SIZE.y){
        return true;
    }
    if((ball->y() + ball->radius()) < 0){
        return true;
    }

    return false;
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