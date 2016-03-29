#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//constants:
//1.screen paras
int max_width = 800;
int max_height = 600;

// Program entry point
int main(int argc, char ** argv) {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(max_width, max_height), "Zero");
    sf::Event event;    // For polling events that SFML sends us

    return 0;
}

