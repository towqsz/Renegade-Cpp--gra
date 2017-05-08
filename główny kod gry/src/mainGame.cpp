#include "mainGame.h"


#define WYS 720
#define SZER 1280

using namespace sf;


mainGame::mainGame(sf::RenderWindow &window)
{
    if(!font.loadFromFile("data/arial.ttf"))
	{
		MessageBox(NULL,"Font not found!","ERROR",NULL);
		return;
	}
	goku=true;
    runmainGame(window);
    enmnumb=1;
}

mainGame::~mainGame()
{
    //dtor
}


void mainGame::runmainGame(sf::RenderWindow &window)
{
    enm[0].activate(0);
    music.playMusic();
    menu=false;
    enmnumb=1;
    while(menu == false) {
            Event even;
            Vector2f mouse(Mouse::getPosition(window));

    ////////KOLIZJE
        ////////enemy
            for (int n=0 ; n<ilw ; n++)
                for (int i=n+1 ; i<ilw ; i++)
                    if (check(enm[n].bounds(),enm[i].bounds()))
                    {
                        enm[n].change(Enemy::LEFT);
                        enm[i].change(Enemy::RIGHT);
                    }
        ////////goku & player
            if (check(player.bounds(), staticElement.bounds()) && goku==true)
            {
                music.playSound(Audio::GOKU);
                goku=false;
            } else if (!check(player.bounds(), staticElement.bounds()))
                       goku=true;

        ////////goku & bullet
            for(int i=0; i<ilw ; i++)
            {
                    if (check(bullet[i].bounds(), staticElement.bounds()))
                        bullet[i].destroy();
            }


        ////////player & bullet
            for (int i=0 ; i<ilw ; i++)
            {
                if(check(player.bounds(), bullet[i].bounds()))
                {
                    if (player.guard())
                        bullet[i].repell();
                    else
                    {
                        stats.sublives();
                        bullet[i].destroy();
                        if(stats.getlives()<1)
                        {
                            stats.save();
                            defeat(window);
                            records(window);
                        }
                    }

                }
            }
        ////////enemy & bullet
            for (int n=0 ; n<ilw ; n++)
                for (int i=0 ; i<ilw ; i++)
                {
                    if(check(enm[n].bounds(), bullet[i].bounds()) && bullet[i].isrepelled())
                    {
                        enm[n].die();
                        bullet[n].destroy();
                        enmnumb=enmnumb-1;
                        stats.addpoints(50);
                        if (enmnumb<1)
                        {

                            if (stats.getlevel()>=5)
                            {
                                stats.save();
                                win(window);
                                records(window);
                            }
                            else
                            {

                                stats.addlevel();
                                enmnumb=stats.getlevel();
                                for(int i=0; i<stats.getlevel() ; i++)
                                    enm[i].activate(i);
                            }


                        }
                    }

                }




    ////////ZDARZENIA
            while(window.pollEvent(even)){

                if (even.type == Event::KeyPressed && even.key.code == Keyboard::F1)
                {
                    for (int i=0 ; i<stats.getlevel() ; i++)
                    {
                        enm[i].stop(true);
                        bullet[i].stop();
                    }
                    help(window);
                    player.stopp();
                }

                else if (even.type == Event::KeyPressed && even.key.code == Keyboard::Escape)
                {
                    for (int i=0 ; i<stats.getlevel() ; i++)
                    {
                        enm[i].stop(true);
                        bullet[i].stop();
                    }
                    music.setVolume(false);
                    ensure(window);
                    music.setVolume(true);
                    player.stopp();
                }
                else if (even.type == Event::KeyPressed && even.key.code == Keyboard::F3)
                {
                    for (int i=0 ; i<stats.getlevel() ; i++)
                    {
                        enm[i].stop(true);
                        bullet[i].stop();
                    }
                    records(window);
                    player.stopp();
                }

                else if (even.type == Event::KeyReleased && even.key.code == Keyboard::Space)
                    player.hit();


                else if (even.type == Event::KeyReleased && even.key.code == Keyboard::Left || (even.type == Event::KeyReleased && even.key.code == Keyboard::Right))
                    player.stopp();

                else if (even.type == Event::KeyPressed && even.key.code == Keyboard::F2)
                    stats.save();

                else if (even.type == Event::KeyPressed && even.key.code == Keyboard::F5)
                    stats.clear_rec();

            }
        for (int i=0 ; i<ilw ; i++)
        {
            if (enm[i].isactive())
            {
                enm[i].update();
                if (clock[i].getElapsedTime()>sf::seconds(1))
                {
                    clock[i].restart();
                    if(!bullet[i].isbullet() && stat.los(0,100)<50 )
                    {
                        bullet[i].shoot(enm[i].position(), player.position());
                        sound.playSound(Audio::SHOOT);
                        enm[i].stop(stats.getdifficulty());
                    }
                }


                if(bullet[i].isbullet())
                    bullet[i].update();

            }

        }
        stat.updatestats(&stats);
        player.update();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    player.rightp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    player.leftp();


        window.clear();

        stat.create_g();


        window.draw(stat);


        window.draw(player);
        window.draw(staticElement);

        for (int i=0 ; i<ilw ; i++)
        {


            if(enm[i].isactive())
                window.draw(enm[i]);
            if(bullet[i].isbullet())
                window.draw(bullet[i]);
        }

        window.display();
	}
}
