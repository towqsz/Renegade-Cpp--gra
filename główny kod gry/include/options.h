#ifndef OPTIONS_H
#define OPTIONS_H
#include "mainGame.h"
#pragma once
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>


using namespace std;
using namespace sf;

class options
{
    public:
        options();
        virtual ~options();
        void help(sf::RenderWindow &window);
        void ensure(sf::RenderWindow &window);


    protected:
    private:

    Font font;

};

#endif // OPTIONS_H
