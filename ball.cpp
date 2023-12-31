/**
 * @file ball.cpp
 * @author Josh Gillum
 * @brief Ball class function implementations
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ball.h"



Ball::Ball(sf::Vector2f position, sf::Vector2f velocity, double radius, sf::Color color){
    if(radius > 0){
        mRadius = radius;
    } else {
        mRadius = 0;
    }

    mVelocity = velocity;
    mPosition = position;
    mColor = color;

    mShape.setRadius(mRadius);
    mShape.setFillColor(color);
    mShape.setPosition(mPosition);
}



Ball::Ball(const Ball &right){
    mRadius = right.radius();
    mColor = right.color();
    mPosition = right.position();
    mVelocity = right.velocity();
}




void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mShape);
}


void Ball::move() {
    mPosition += mVelocity;
    mShape.setPosition(mPosition);
}


