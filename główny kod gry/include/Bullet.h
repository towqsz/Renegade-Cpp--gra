#ifndef BULLET_H
#define BULLET_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <windows.h>
#include <math.h>



using namespace sf;

class Bullet: public sf::Drawable
{
    public:
        Bullet();
        virtual ~Bullet();
        void destroy();
        void shoot(Vector2f position, Vector2f pl);
        void update();
        bool isbullet();
        void repell();
        bool isrepelled();
        void stop();
        sf::FloatRect bounds();

    protected:
    private:
        sf::Sprite bullet;
        sf::Vector2f pos;
        sf::Clock posc;
        sf::Texture bullett;
        bool isbulletv=false, repelled, stopv=false;
        void draw(sf::RenderTarget &target,sf::RenderStates states) const;

};

#endif // BULLET_H
