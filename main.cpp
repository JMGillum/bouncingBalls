#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "ballpit.h"


int main(){

    const float SCREEN_RES_X = 1000, SCREEN_RES_Y = 800, FRAME_RATE = 60;

    //granularity used to update the game
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/ FRAME_RATE);
    sf::Clock clock;
    //start the clock
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // create window of size 800 x 800 with title Space Invaders
    sf::RenderWindow window(sf::VideoMode(SCREEN_RES_X, SCREEN_RES_Y), "Balls");

    Ballpit balls(2);
    
    while (window.isOpen()){
        timeSinceLastUpdate += clock.restart();
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        while (timeSinceLastUpdate > TIME_PER_FRAME){
            timeSinceLastUpdate -= TIME_PER_FRAME;
            window.clear();
            window.draw(balls);
            window.display();
        }   
    }

    return 0;
}