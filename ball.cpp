#include "ball.h"



Ball::Ball(sf::Vector2f position, double radius, sf::Color color){
    if(radius > 0){
        mRadius = radius;
    } else {
        mRadius = 0;
    }

    mPosition = position;
    mColor = color;

    mVelocity = sf::Vector2f(0,0);
}



Ball::Ball(const Ball &right){


}



Ball::~Ball(){


}


