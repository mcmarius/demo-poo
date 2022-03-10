#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "SomeClass.h"

SomeClass *getC() {
    return new SomeClass{2};
}

int main() {
    SomeClass *c = getC();
    std::cout << c << "\n";
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
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(8000ms);
        return 0;

        window.clear();
        window.display();
    }

    return 0;
}
