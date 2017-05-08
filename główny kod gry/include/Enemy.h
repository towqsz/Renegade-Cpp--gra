#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>


using namespace sf;


class Enemy: public sf::Drawable,
	sf::Transformable
{
    public:
        Enemy();
        virtual ~Enemy();
        void update();
        enum Kierunek {LEFT, RIGHT} kierunek;
        void change(Kierunek kier);
        int difficulty();
        void setdiff(int d);
        bool isactive();
        void activate(int l);
        void disactivate();
        void die();
        void stop(bool notperm);
        sf::FloatRect bounds();
        sf::Vector2f position();

    protected:
    private:
        //enum Kierunek {LEFT, RIGHT} kierunek;
        int lvl, diff, dieframe;
        bool active, notpermament;
        float posx;
        enum State {moves, stops, died} state;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock clock, dies;
        float los(float z1, float z2);
        void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};

#endif // ENEMY_H
