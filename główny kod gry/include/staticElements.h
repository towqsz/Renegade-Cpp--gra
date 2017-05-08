#ifndef STATICELEMENTS_H
#define STATICELEMENTS_H
#include <SFML\Graphics.hpp>
#include <windows.h>
#pragma once

using namespace std;
using namespace sf;

class staticElements: public sf::Drawable
{
    public:
        staticElements();
        virtual ~staticElements();
        sf::FloatRect bounds();
    protected:
    private:
        void draw(sf::RenderTarget &target,sf::RenderStates states) const;
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif // STATICELEMENTS_H
