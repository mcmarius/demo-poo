#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SomeClass.h"

int main() {
    SomeClass c{2};
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 700), "My Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed)
                window.close();
            if(e.type == sf::Event::Resized)
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
        }

        window.clear();
        window.display();
    }

    return 0;
}

