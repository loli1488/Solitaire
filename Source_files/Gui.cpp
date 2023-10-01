#include "Gui.h"

Gui::Gui() {
}

void Gui::CreateWindow(int windowWidth, int windowHeight) {
    window.create(sf::VideoMode(windowWidth, windowHeight), "Solitaire");
}
void Gui::DrawBlackground() {
    window.clear(sf::Color::Black);
    window.display();
}

void Gui::LoadImage(const std::string& imagePath, float x, float y, float width, float height) {
    sf::Texture texture;
    if (texture.loadFromFile(imagePath)) {
        sf::Sprite sprite(texture);
        sprite.setPosition(x, y);
        sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
        // You can also set the rotation or any other properties of the sprite if needed.
        window.draw(sprite);

    } else {
		printf("ERROR IMAGE COULD NOT BE LOADED");
    }
}

void Gui::Update(){
	window.display();
}

