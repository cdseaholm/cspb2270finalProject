#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include "obstacles.hpp"
#include "signs.hpp"
#include "people.hpp"

using namespace std;
namespace fs = std::filesystem;

bool isWithinObstacle(int x, int y, const vector<tuple<int, int, int, int>>& obstacles) {
    for (const auto& obstacle : obstacles) {
        int minX = get<0>(obstacle);
        int minY = get<1>(obstacle);
        int maxX = get<2>(obstacle);
        int maxY = get<3>(obstacle);
        if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
            return true;
        }
    }
    return false;
}

bool isWithinSign(int x, int y, const vector<tuple<int, int, int, int, string>>& signs, string& message) {
    for (const auto& sign : signs) {
        int minX = get<0>(sign);
        int minY = get<1>(sign);
        int maxX = get<2>(sign);
        int maxY = get<3>(sign);
        if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
            message = get<4>(sign);
            return true;
        }
    }
    return false;
}

bool isAPerson(int x, int y, const vector<tuple<int, int, int, int, string>>& people, string& personMessage) {
    for (const auto& person : people) {
        int minX = get<0>(person);
        int minY = get<1>(person);
        int maxX = get<2>(person);
        int maxY = get<3>(person);
        if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
            personMessage = get<4>(person);
            return true;
        }
    }
    return false;
}

int main() {

    if (!fs::exists("image.png")) {
        std::cout << "Image file 'image.png' does not exist in the current working directory." << std::endl;
        return -1;
    }

    sf::Texture texture;
    if (!texture.loadFromFile("image.png")) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    sf::Sprite sprite(texture);

    initializeObstacles();

    initializeSigns();

    initializePeople();

    vector<tuple<int, int>> coordinates;

    int x = 95;
    int y = 130;

    sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "Image");

    sf::CircleShape person(10);
    person.setFillColor(sf::Color::Red);
    person.setPosition(x, y);

    while (window.isOpen()) {

        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                int newX = x;
                int newY = y;
                if (event.key.code == sf::Keyboard::Up) {
                    newY = max(0, y - 5);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    newY = min(static_cast<int>(texture.getSize().y - person.getRadius() * 2), y + 5);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    newX = max(0, x - 5);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    newX = min(static_cast<int>(texture.getSize().x - person.getRadius() * 2), x + 5);
                }

                string message;
                if (isWithinSign(newX, newY, signs, message)) {
                    std::cout << message << std::endl;
                }

                string personMessage;
                if (isAPerson(newX, newY, people, personMessage)) {
                    std::cout << personMessage << std::endl;
                }

                if (!isWithinObstacle(newX, newY, obstacles)) {
                    x = newX;
                    y = newY;
                }

                if (event.key.code == sf::Keyboard::O) {
                    std::cout << "Current position: (" << x << ", " << y << ")" << std::endl;
                    coordinates.push_back({x, y});
                }
            }
        }

        person.setPosition(x, y);
        window.clear();
        window.draw(sprite);
        window.draw(person);
        window.display();

    }

    return 0;
}