#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>>

class Ball : sf::Drawable {

    public:
        Ball() : Ball(sf::Vector2f(0,0), 5, sf::Color::Black) {}
        Ball(sf::Vector2f position, double radius, sf::Color color);
        Ball(const Ball &right);

        // Returns information about the object's location
        sf::Vector2f position() const { return mPosition; }
        float x() const { return mPosition.x; }
        float y() const { return mPosition.y; }

        // Returns information about the object's velocity
        sf::Vector2f velocity() const { return mVelocity; }
        float velocityX() const { return mVelocity.x; }
        float velocityY() const { return mVelocity.y; }
        
        double radius() const { return mRadius; }

        sf::Color color() const { return mColor; }


    protected:

        sf::Sprite mSprite;
        sf::Color mColor;
        double mRadius;
        sf::Vector2f mVelocity;
        sf::Vector2f mPosition;


    private:


};

#endif