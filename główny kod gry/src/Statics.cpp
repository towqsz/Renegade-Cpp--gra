#include "Statics.h"
#define WYS 720
#define SZER 1280
#define BS SZER/6
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#define L 10

using namespace sf;



Statics::Statics()
{
    bgf();
    borders();
    clock.restart();
    grassf();
    srand(time(NULL));
    playerhead();
	pomocf();
	stats();
	livesf();
}

Statics::~Statics()
{
    //dtor
}

void Statics::playerhead()
{
    if(!plhdt.loadFromFile("data/plhd.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(1);
	}

	plhds.setTexture(plhdt);
	plhds.setPosition(10,10);
	plhds.setScale(1.7,1.7);

}

void Statics::livesf()
{
        livess[0].setSize(sf::Vector2f(100, statsy[0].getGlobalBounds().height-5));
        livess[0].setOutlineThickness(1);
        livess[0].setOutlineColor(sf::Color(255,0,0));
        livess[0].setFillColor(sf::Color(255,0,0, 1));
        livess[0].setPosition(160+plhds.getGlobalBounds().width, 30);
        livess[1].setSize(sf::Vector2f(100, statsy[0].getGlobalBounds().height-5));
        livess[1].setFillColor(sf::Color(255,0,0));
        livess[1].setPosition(160+plhds.getGlobalBounds().width, 30);


}

void Statics::livesupd(int lives)
{
    livess[1].setSize(sf::Vector2f(lives*100/5, statsy[0].getGlobalBounds().height-5));
}

void Statics::stats()
{


	string str[] = {"Nazwa gracza:", "Zycie:", "Punkty:",  "Poziom:"};
	for(int i=0 ; i<ile ; i++)
    {
		statsy[i].setFont(font);
		statsy[i].setCharacterSize(15);
		statsy[i].setString(str[i]);
		statsy[i].setPosition(150+plhds.getGlobalBounds().width-statsy[i].getGlobalBounds().width, 10+i*15);
		statsy[i].setColor(Color::Cyan);
	}

}

void Statics::updatestats(Stats *stats)
{
    char bufor[50];


    livesupd(stats->getlives());
    statsr[0].setString(stats->getname());
    sprintf(bufor, "%d", stats->getlives());
    statsr[1].setString(bufor);
    sprintf(bufor, "%d", stats->getpoints());
    statsr[2].setString(bufor);
    sprintf(bufor, "%d", stats->getlevel());
    statsr[3].setString(bufor);

    for(int i=0 ; i<ile ; i++)
    {
		statsr[i].setFont(font);
		statsr[i].setCharacterSize(15);
		statsr[i].setPosition(160+plhds.getGlobalBounds().width, 10+i*15);
		statsr[i].setColor(Color::Cyan);
	}
}

void Statics::pomocf()
{
    if(!font.loadFromFile("data/arial.ttf"))
	{
		MessageBox(NULL,"Font not found!","ERROR",NULL);
		exit(1);
	}
    string str[] = {"F1-rozwin pomoc"};

		pomoc.setFont(font);
		pomoc.setCharacterSize(20);
		pomoc.setString(str[0]);
        pomoc.setPosition(10,WYS/6);
}

float Statics::los(float z1, float z2)
{
    float l;


        l=z1+rand()/((float)(RAND_MAX)+1)*(z2-z1);
        return l ;

}

void Statics::create_g()
{
    static int i;

    if ( i<0 || i>L-2)
        i=0;

 /////////////ruch podloza
    if(pos.getElapsedTime()<sf::seconds(0.2))
        {
            bgs.setPosition(0,41/3);
        }
    else
        {

            if(pos.getElapsedTime() < sf::seconds(0.4))
                bgs.setPosition(0,41/3*2);
            else if (pos.getElapsedTime() < sf::seconds(0.6))
                bgs.setPosition(0,0);
            else
                pos.restart();
        }

/////////// generowanie i przemieszczanie elementu "grass"

    if (clos.getElapsedTime() > sf::seconds(1))
        {
            if(los(0,100)<20)
            {
                gtab[i]=1;
                i++;
            }
        clos.restart();
        }

    for (int n=0 ; n<L ; n++)
        if (gtab[n]==1)
        {
            gtab[n]=2;
            grasss[n].setPosition(los(5+BS,SZER-grasss[0].getGlobalBounds().width),0);

        }

    if (clock.getElapsedTime() > sf::seconds(0.2))
        {
            for (int n=0 ; n<L ; n++)
                if (gtab[n]==2)
                {
                    grasss[n].move(0,41/3);
                }
            clock.restart();

        }

    for (int n=0 ; n<L ; n++)
                if (grasss[n].getPosition().y>WYS)
                {
                    gtab[n]=0;
                    grasss[i].setPosition(SZER/2,0);
                }


}

void Statics::grassf()
{
    if(!grasst.loadFromFile("data/grass.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(1);
	}
	for(int i=0 ; i <L ; i++)
    {
        grasss[i].setTexture(grasst);
        grasss[i].setPosition(SZER/2,0);
    }
    for (int i=0 ; i<L; i++ )
    {
        gtab[i]=0;
    }
}

void Statics::borders()
{
    int i;


    border[0].setSize(sf::Vector2f(BS, WYS));
    border[0].setFillColor(sf::Color(0,0,0));
    border[0].setPosition(0,0);
    border[1].setSize(sf::Vector2f(SZER, WYS/7));
    border[1].setPosition(0,0);
    border[1].setFillColor(sf::Color(10,10,10));


}

void Statics::bgf()
{

    if(!bgt.loadFromFile("data/bg.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		exit(1);
	}
	bgt.setRepeated(true);
    bgs.setPosition(0,0);
    bgs.setTexture(bgt);
    bgs.setTextureRect(sf::IntRect(0,0,SZER,WYS));


}

void Statics::draw(sf::RenderTarget &target,sf::RenderStates states) const
{

    states.transform *= getTransform();
    target.draw(bgs);

    for(int i=0 ; i<L ; i++)
        target.draw(grasss[i]);

    for(int i=0 ; i <2 ; i++)
        target.draw(border[i]);

    target.draw(pomoc);
    target.draw(plhds);

    for(int i=0 ; i<ile ; i++)
    {
		target.draw(statsy[i]);
    }

    for(int i=0 ; i<ile ; i++)
    {
		target.draw(statsr[i]);
    }

    for(int i=0 ; i<2 ; i++)
    {
		target.draw(livess[i]);
    }
}
