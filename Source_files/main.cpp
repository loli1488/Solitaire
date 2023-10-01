#include "Gui.h"
#include <filesystem> // Include the C++17 filesystem library
#include <iostream>   // Include for debugging prints

int main() {
    Gui gui;
    gui.CreateWindow(640,480);
    gui.DrawBlackground();
    gui.Update();
    
    // Get the current working directory
    std::string currentDirectory = std::filesystem::current_path().string();
    std::cout << "Current Directory: " << currentDirectory << std::endl;

    while (gui.window.isOpen()) {
        sf::Event event;
        while (gui.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gui.window.close();
        }

        // Load image using a relative path
        std::string relativePath = "Resources/tile0.png"; // Adjust this to your relative path
        std::string absolutePath = currentDirectory + "/" + relativePath;
        
        // Debug prints
        std::cout << "Relative Path: " << relativePath << std::endl;
        std::cout << "Absolute Path: " << absolutePath << std::endl;

        gui.LoadImage(absolutePath, 0.0f, 0.0f, 50.0f, 50.0f);

        gui.Update();
    }
    
    return 0;
}
