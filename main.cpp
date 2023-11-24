#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "ballpit.h"


int main(){

    const float SCREEN_RES_X = 1000, SCREEN_RES_Y = 800, FRAME_RATE = 60;

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/ FRAME_RATE);

    sf::Clock clock; // Clock object for tracking time for each loop
    sf::Time timeSinceLastUpdate = sf::Time::Zero; // Tracks when the screen was last updated

    // create window of size 800 x 800 with title "Balls"
    sf::RenderWindow window(sf::VideoMode(SCREEN_RES_X, SCREEN_RES_Y), "Balls");

    Ballpit balls(2);
    
    // Below loop continues until the window is closed
    while (window.isOpen()){
        timeSinceLastUpdate += clock.restart(); // Adds the time since the clock was last reset to the total
        sf::Event event;

        // Below loop searches through each event and deals with them accordingly
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){ // The x in the corner is pressed, closes the window
                window.close();
            }
        }
        while (timeSinceLastUpdate > TIME_PER_FRAME){ // Prevents drawing to the screen faster than the specified frame rate
            timeSinceLastUpdate -= TIME_PER_FRAME;
            window.clear();
            balls.move();
            window.draw(balls);
            window.display();
        }   
    }

    return 0;
}