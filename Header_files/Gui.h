#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class Gui {
public:
	sf::RenderWindow window; 
    Gui();
    void CreateWindow(int windowWidth, int windowHeight);
    void DrawBlackground();
    void LoadImage(const std::string& imagePath, float x, float y, float width, float height);
    void Update();
};

#endif // GUI_H
