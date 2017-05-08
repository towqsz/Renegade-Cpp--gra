#include "Bullet.h"
#define WYS 720
#define SZER 1280
#define BS SZER/6
#define BG WYS/7

Bullet::Bullet()
{

	if(!bullett.loadFromFile("data/bullet.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(0);
	}
	bullet.setTexture(bullett);
	bullet.setScale(0.5, 0.5);
	bullet.setPosition(500,500);
	bullet.setOrigin(bullet.getGlobalBounds().width/2, 0);


}

Bullet::~Bullet()
{
    //dtor
}



void Bullet::destroy()
{
    isbulletv=false;
    repelled=false;
    bullet.setPosition(0-bullet.getGlobalBounds().width, 0);
}

bool Bullet::isbullet()
{
    return isbulletv;
}

bool Bullet::isrepelled()
{
    if(repelled)
        return true;
    else return false;
}

void Bullet::shoot(Vector2f position, Vector2f player)
{
    pos=position;
    posc.restart();
    bullet.setPosition(position);
    isbulletv=true;
    repelled=false;
    Vector2f norm = player- bullet.getPosition();
	float rotation = atan2(norm.y,norm.x);
	rotation = rotation * 180.f/M_PI;

	rotation += 90;
	bullet.setRotation(rotation);
}

sf::FloatRect Bullet::bounds()
{
    return bullet.getGlobalBounds();
}

void Bullet::update()
{

    float rotation = bullet.getRotation();
    if (stopv)
    {
        posc.restart();
        stopv=false;
    }
    else if (!repelled)
    {
        float vx = sin(( rotation * M_PI ) / 180.0f );
        float vy = -cos(( rotation * M_PI ) / 180.0f );
        //bullet.move (1*vx,1*vy);
        bullet.setPosition(pos.x+posc.getElapsedTime().asMilliseconds()*vx, pos.y+posc.getElapsedTime().asMilliseconds()*vy);
    } else
    {
        bullet.setRotation(0);
        pos=bullet.getPosition();
        bullet.setPosition(pos.x, pos.y-posc.getElapsedTime().asSeconds()*5);
    }

	if(bullet.getPosition().y > SZER || bullet.getPosition().x < BS || bullet.getPosition().x > SZER || bullet.getPosition().y < BG-bullet.getGlobalBounds().height/2)
        destroy();
}

void Bullet::stop()
{
    pos=bullet.getPosition();
    stopv=true;
}

void Bullet::repell()
{
    repelled=true;
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{



        target.draw(bullet);
}
