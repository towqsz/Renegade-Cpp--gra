#include "staticElements.h"
#define WYS 720

staticElements::staticElements()
{
    if(!texture.loadFromFile("data/cloud2.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(1);
	}
	sprite.setTexture(texture);
	sprite.setScale(1.2 , 1.5);
	sprite.setPosition(50-sprite.getGlobalBounds().width/2, WYS-sprite.getGlobalBounds().height);

}

staticElements::~staticElements()
{
    //dtor
}

sf::FloatRect staticElements::bounds()
{
    return sprite.getGlobalBounds();
}


void staticElements::draw(sf::RenderTarget &target,sf::RenderStates states) const
{


    target.draw(sprite);
}
