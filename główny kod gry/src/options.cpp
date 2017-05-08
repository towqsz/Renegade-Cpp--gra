#include "options.h"
#include "mainGame.h"
#define WYS 720
#define SZER 1280

using namespace sf;

options::options()
{
    //ctor
}

options::~options()
{
    //dtor
}



void mainGame::help(sf::RenderWindow &window)
{
	bool pomoc=true;
	const int ile = 7;
	Text tekst[ile];

	string str[] = {"F1 - pomoc","F2-zapisz gre","F3-tabela rekordow","F5-wyczysc tabele", "Strzalki-ruch postaci",  "Spacja-odbij", "Esc-wyjdz"};
	for(int i=0;i<ile;i++){
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(20);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(10,WYS/5+i*30);
	}

	for(int i=0;i<ile;i++)
			tekst[i].setColor(Color::Cyan);

    while (pomoc==true) {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type==Event::KeyPressed)
                pomoc=false;
        }

        for(int i=0;i<ile;i++)
        window.draw(tekst[i]);

        window.display();

    }


}

void mainGame::ensure(sf::RenderWindow &window)
{
    sf::RectangleShape okn;
    bool potwierdzenie=true;
    int i;
	const int ile = 2;
	Text tekst[ile];

	okn.setSize(sf::Vector2f(SZER/4, WYS/4));
    okn.setFillColor(sf::Color(0,0,0));
    okn.setPosition(SZER/2-SZER/8,WYS/2-WYS/8);
    okn.setOutlineColor(sf::Color(255,0,0));
    okn.setOutlineThickness(2);



	Text title("Czy chcesz wyjsc?",font,30);
	title.setStyle(Text::Bold);

	title.setPosition(SZER/2-title.getGlobalBounds().width/2,WYS/2-WYS/20);

    string str[] = {"Tak", "Nie"};
	for(i=0;i<ile;i++){
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(20);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(SZER/2-tekst[i].getGlobalBounds().width+i*40,WYS/2-WYS/20+40);
	}



    while(potwierdzenie == true) {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));

            while (window.pollEvent(event)) {
                if (tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left )
                    {
                    menu=true;
                    potwierdzenie=false;
                    }

                else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                    potwierdzenie=false;
                }





	for(i=0;i<ile;i++)
            if(tekst[i].getGlobalBounds().contains(mouse))
				{
				    tekst[i].setColor(Color::Green);
                    music.playSound(Audio::CLICK);
				}
			else {
                    tekst[i].setColor(Color::White);

                }

    window.draw(okn);
    window.draw(title);
    for(i=0;i<ile;i++)
        window.draw(tekst[i]);



        window.display();

    }

}

void mainGame::win(sf::RenderWindow &window)
{
    sf::RectangleShape okn;
    bool potwierdzenie=true;
    int i;
	const int ile = 1;
	Text tekst[ile];

	okn.setSize(sf::Vector2f(SZER/4, WYS/4));
    okn.setFillColor(sf::Color(0,0,0));
    okn.setPosition(SZER/2-SZER/8,WYS/2-WYS/8);
    okn.setOutlineColor(sf::Color(255,0,0));
    okn.setOutlineThickness(2);



	Text title("GRATULACJE!",font,30);
	title.setStyle(Text::Bold);

	title.setPosition(SZER/2-title.getGlobalBounds().width/2,WYS/2-WYS/20);

    string str[] = {"WYGRALES!"};
	for(i=0;i<ile;i++){
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(20);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(SZER/2-tekst[i].getGlobalBounds().width+i*40,WYS/2-WYS/20+40);
	}




    while(potwierdzenie == true) {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));

            while (window.pollEvent(event)) {
                if (tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left || (event.type == Event::KeyPressed))
                    {
                    menu=true;
                    potwierdzenie=false;
                    }


                }





	for(i=0;i<ile;i++)
            if(tekst[i].getGlobalBounds().contains(mouse))
				{
				    tekst[i].setColor(Color::Green);
				}
			else {
                    tekst[i].setColor(Color::White);

                }

    window.draw(okn);
    window.draw(title);
    for(i=0;i<ile;i++)
        window.draw(tekst[i]);



        window.display();

    }

}

void mainGame::defeat(sf::RenderWindow &window)
{
    sf::RectangleShape okn;
    bool potwierdzenie=true;
    int i;
	const int ile = 1;
	Text tekst[ile];

	okn.setSize(sf::Vector2f(SZER/4, WYS/4));
    okn.setFillColor(sf::Color(0,0,0));
    okn.setPosition(SZER/2-SZER/8,WYS/2-WYS/8);
    okn.setOutlineColor(sf::Color(255,0,0));
    okn.setOutlineThickness(2);



	Text title("Nie masz juz zyc!",font,30);
	title.setStyle(Text::Bold);

	title.setPosition(SZER/2-title.getGlobalBounds().width/2,WYS/2-WYS/20);

    string str[] = {"Przegrales!"};
	for(i=0;i<ile;i++){
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(20);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(SZER/2-tekst[i].getGlobalBounds().width+i*40,WYS/2-WYS/20+40);
	}




    while(potwierdzenie == true) {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));

            while (window.pollEvent(event)) {
                if (tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left || (event.type == Event::KeyPressed))
                    {
                    menu=true;
                    potwierdzenie=false;
                    }


                }





	for(i=0;i<ile;i++)
            if(tekst[i].getGlobalBounds().contains(mouse))
				{
				    tekst[i].setColor(Color::Green);
				}
			else {
                    tekst[i].setColor(Color::White);

                }

    window.draw(okn);
    window.draw(title);
    for(i=0;i<ile;i++)
        window.draw(tekst[i]);



        window.display();

    }

}


void mainGame::records(sf::RenderWindow &window)
{
    sf::RectangleShape okn;
    bool potwierdzenie=true;
    int i;
	const int ile = 5;
	Text tekst[ile];
    char tab[5][50];
	okn.setSize(sf::Vector2f(SZER/4, WYS/2));
    okn.setFillColor(sf::Color(0,0,0));
    okn.setPosition(SZER/2-SZER/8,WYS/2-WYS/4);
    okn.setOutlineColor(sf::Color(255,0,0));
    okn.setOutlineThickness(2);




	Text title("Najlepsze wyniki",font,30);
	title.setStyle(Text::Bold);

	title.setPosition(SZER/2-title.getGlobalBounds().width/2,WYS/2-WYS/5);

    stats.readrec(tab);

	for(i=0;i<ile;i++){

		tekst[i].setFont(font);
		tekst[i].setCharacterSize(20);
        tekst[i].setColor(Color::White);
		tekst[i].setString(tab[i]);
		tekst[i].setPosition(SZER/2-SZER/10,WYS/2-WYS/20+40*i);
	}



    while(potwierdzenie == true) {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));

            while (window.pollEvent(event)) {
                if (event.type==Event::KeyPressed)
                potwierdzenie=false;
                }




    window.draw(okn);
    window.draw(title);
    for(i=0;i<ile;i++)
        window.draw(tekst[i]);



        window.display();

    }

}
