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


void Ballpit::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(unsigned i = 0; i < mNumBalls; ++i){
        if(mBalls[i] != nullptr){
            mBalls[i]->draw(target,states);
        }
    }
}