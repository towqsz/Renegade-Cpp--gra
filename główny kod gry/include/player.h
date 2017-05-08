#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <SFML\Graphics.hpp>



class Player: public sf::Drawable,
	sf::Transformable
{
    public:
        Player();
        virtual ~Player();
        void leftp();
        void rightp();
        void stopp();
        void update();
        void hit();
        bool guard();
        sf::FloatRect bounds();
        sf::Vector2f position();



    protected:

    private:

        enum Kierunek {LEFT, RIGHT};
        Kierunek kierunek;
        void update(Kierunek kierunek);
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock clock;
        sf::Clock pos;
        sf::Time p;
        int posx;
        enum states {stop, moves, hits} state;
        virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};

#endif // PLAYER_H
