/**
 * @file ball.h
 * @author Josh Gillum
 * @brief Ball class definition. Constists of a circle object with a position and velocity
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable {

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

        double mass() const { return 3.14159 * mRadius * mRadius; }

        sf::Color color() const { return mColor; }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void move();


    protected:

        sf::CircleShape mShape; // The shape object
        sf::Color mColor; // Color of the ball
        double mRadius; // Radius of the ball
        sf::Vector2f mVelocity; // Velocity vector for the ball
        sf::Vector2f mPosition; // Position vector for the ball


    private:


};

#endif