#include "Enemy.h"
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define WYS 720
#define SZER 1280
#define BS SZER/6
#define BG WYS/7

Enemy::Enemy()
{
    if(!texture.loadFromFile("data/soldier2.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(0);
	}
    srand(time(NULL));
    disactivate();
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,70,35,52));
	sprite.setScale(2.3,1.7);
    sprite.rotate(180);
	clock.restart();

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::activate(int l)
{
    active=true;
    state=moves;
    clock.restart();
    if (los(0,100) < 50)
        kierunek=RIGHT;
    else
        kierunek=LEFT;
    posx=BS+sprite.getGlobalBounds().width+100*l+200;
    sprite.setPosition(posx, BG+sprite.getGlobalBounds().height);
}

void Enemy::stop(bool notperm)
{
    state=stops;
    posx=sprite.getPosition().x;
    clock.restart();
    notpermament=notperm;
}

sf::FloatRect Enemy::bounds()
{
    return sprite.getGlobalBounds();
}

void Enemy::disactivate()
{
    active=false;
    sprite.setPosition(0, -sprite.getGlobalBounds().height);

}

bool Enemy::isactive()
{
    return active;
}

void Enemy::die()
{
    disactivate();
    state=died;
    dies.restart();
    dieframe=0;
}

void Enemy::update()
{
    if (state==moves)
        {
            if (kierunek==RIGHT)
                sprite.setPosition(posx+200*clock.getElapsedTime().asSeconds(),  sprite.getPosition().y);
            else if (kierunek==LEFT)
                sprite.setPosition(posx-200*clock.getElapsedTime().asSeconds(),  sprite.getPosition().y);

            if (sprite.getPosition().x < BS + sprite.getGlobalBounds().width || sprite.getPosition().x > SZER)
            {
                change(LEFT);
            }


        } else if (state==died)
        {
            if (dies.getElapsedTime().asSeconds() > 1)
            {
                dies.restart();
                dieframe++;
                if(dieframe>2)
                    disactivate();
                sprite.setTextureRect(IntRect(0+75*dieframe,0,100,122));
            }

        } else if (state==stops && notpermament)

            {
                state=moves;
                clock.restart();
            }
}

void Enemy::change(Kierunek kier)
{
    clock.restart();
    posx=sprite.getPosition().x;

    if (sprite.getPosition().x < BS + sprite.getGlobalBounds().width)
    {
        kierunek=RIGHT;

    } else if(sprite.getPosition().x > SZER)
    {
        kierunek=LEFT;

    }else
        kierunek=kier;
}

sf::Vector2f Enemy::position()
{
    Vector2f bullet;
    bullet=sprite.getPosition();
    bullet.x -= sprite.getGlobalBounds().width*2/3;
    bullet.y += 20;

    return bullet;
}

void Enemy::setdiff(int d)
{
    diff=d;
}

float Enemy::los(float z1, float z2)
{
    float l;


        l=z1+rand()/((float)(RAND_MAX)+1)*(z2-z1);
        return l ;

}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();


        target.draw(sprite);
}
