#ifndef COLLISION_H
#define COLLISION_H
#include <vector>
#include <SFML\Graphics.hpp>

using namespace sf;

class Collision
{
    public:
        Collision();
        virtual ~Collision();

        bool check(sf::FloatRect o1, sf::FloatRect o2);

    protected:
    private:
};

#endif // COLLISION_H
