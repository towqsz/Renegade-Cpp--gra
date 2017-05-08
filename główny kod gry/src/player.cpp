#include "Player.h"
#define WYS 720
#define SZER 1280
#include <Windows.h>
#include <iostream>
#define WYS 720
#define SZER 1280
#define BS SZER/6
#define BG WYS/7

using namespace sf;

Player::Player()
{
    if(!texture.loadFromFile("data/sprite2.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		return;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,15,33));
	sprite.setScale(3.0,3.0);

	sprite.setPosition(SZER/2,WYS-sprite.getGlobalBounds().height-20);
	clock.restart();
	state=stop;

}

Player::~Player()
{
    //dtor
}

void Player::update(Kierunek kierunek)
{
    state=moves;
    //by bylo plynnie potrzeba ~50 fps
    p = pos.getElapsedTime();


        if (kierunek==LEFT && sprite.getPosition().x > BS)
            sprite.setPosition(posx-200*p.asSeconds() - 500*p.asSeconds()*p.asSeconds() ,  sprite.getPosition().y);
        else if (kierunek==RIGHT && sprite.getPosition().x < SZER- sprite.getGlobalBounds().width)
            sprite.setPosition(posx+200*p.asSeconds() + 500*p.asSeconds()*p.asSeconds() ,  sprite.getPosition().y);

}

void Player::leftp()
{

    update(LEFT);

    sprite.setTextureRect(IntRect(30, 0, 23, 33));

}

void Player::rightp()
{
    update(RIGHT);

    sprite.setTextureRect(IntRect(53, 0, 23, 33));


}

sf::Vector2f Player::position()
{
    return sprite.getPosition();
}

sf::FloatRect Player::bounds()
{
    return sprite.getGlobalBounds();
}

bool Player::guard()
{
    if (state==hits)
        return true;
    else
        return false;
}


void Player::stopp()
{

    state=stop;

}

void Player::hit()
{
    state=hits;
    sprite.setTextureRect(IntRect(76, 0, 23, 33));
    clock.restart();
}



void Player::update ()
{
    if (state == stop)
    {
        if (clock.getElapsedTime() < sf::seconds(0.2))
            sprite.setTextureRect(IntRect(0,0,15,33));
        else
        {
            sprite.setTextureRect(IntRect(15, 0, 15, 33));
            if(clock.getElapsedTime() > sf::seconds(0.4))
                clock.restart();
        }


        posx=sprite.getPosition().x;

    }

    else if (state==hits)
        {

            if(clock.getElapsedTime()>=sf::seconds(0.7))
            state=stop;
        }

    if (state == stop || state == hits)
            pos.restart();


}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
}

