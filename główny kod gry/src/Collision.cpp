#include "Collision.h"


Collision::Collision()
{
    //ctor
}

Collision::~Collision()
{
    //dtor
}

bool Collision::check(sf::FloatRect o1, sf::FloatRect o2)
{
        if (o1.intersects(o2))
            return true;
        else return false;

}
