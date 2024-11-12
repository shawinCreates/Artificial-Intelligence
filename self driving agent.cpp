#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#define GREEN 1
#define RED 0

void drawTrafficLight(int lightState) {
    if (lightState == GREEN) {
        std::cout << "[Traffic Light: GREEN]" << std::endl;
    } else {
        std::cout << "[Traffic Light: RED]" << std::endl;
    }
}

void drawCar(int position) {
    std::string road(50, '-');
    road[position] = 'C';  // Mark the car position with 'C'
    std::cout << road << std::endl;
}

void selfDrivingCar() {
    int position = 0;
    int lightState = GREEN;

    while (position < 49) {
        system("CLS");  // Clear the console screen (Windows-specific)
        
        drawTrafficLight(lightState);

        if (position == 10 || position == 30) {  // Checkpoints at position 10 and 30
            if (lightState == RED) {
                std::cout << "Car stopped at checkpoint..." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));  // Wait for 2 seconds
            } else {
                position++;
            }
        } else {
            position++;
        }

        drawCar(position);

        // Toggle the light state randomly (for demonstration)
        if (rand() % 2 == 0) {
            lightState = GREEN;
        } else {
            lightState = RED;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simulate car movement
    }

    std::cout << "The car has reached its destination!" << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    selfDrivingCar();

    return 0;
}

