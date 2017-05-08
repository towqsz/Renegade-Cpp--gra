
#pragma once
#include "player.h"
#include "options.h"
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Statics.h"
#include "Stats.h"
#include "Enemy.h"
#include "Collision.h"
#include "Audio.h"
#include "staticElements.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

class mainGame: Collision
{
    public:
        mainGame(sf::RenderWindow &window);
        virtual ~mainGame();
        void runmainGame(sf::RenderWindow &window);
        bool menu;
        Player player;
        Statics stat;
        Stats stats;
        Enemy enm[5];
        Audio music, sound;
        staticElements staticElement;
        Bullet bullet[5];

    protected:
    private:
    const int ilw=5;

    Font font;
    Clock clock[5];
    bool goku;
    void help(sf::RenderWindow &window);
	void ensure(sf::RenderWindow &window);
	void records(sf::RenderWindow &window);
	void win(sf::RenderWindow &window);
	void defeat(sf::RenderWindow &window);
	int enmnumb;
};


