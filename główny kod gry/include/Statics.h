#ifndef STATICS_H
#define STATICS_H
#include <SFML\Graphics.hpp>
#pragma once
#include "Stats.h"
#include <string>
#define L 10

using namespace std;
using namespace sf;



class Statics: public sf::Drawable,
	sf::Transformable
{
    public:

        Statics();
        virtual ~Statics();
        float los(float z1, float z2);
        void create_g();
        void updatestats(Stats *stats);


    protected:
    private:
        void draw(sf::RenderTarget &target,sf::RenderStates states) const;
        void pomocf();
        sf::RectangleShape border[2], livess[2];
        sf::Sprite bgs, grasss[L], plhds;
        sf::Image bgi;
        sf::Texture bgt, grasst, plhdt;
        sf::Clock clock;
        sf::Clock pos;
        sf::Clock clos;
        int gtab[L];
        const int ile = 4;
        Font font;
        Text pomoc, statsy[4], statsr[4];

        void borders();
        void bgf();
        void grassf();
        void playerhead();
        void stats();
        void livesf();
        void livesupd(int lives);


};

#endif // STATICS_H
