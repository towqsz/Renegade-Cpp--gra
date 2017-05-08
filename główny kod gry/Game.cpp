#include "Game.h"
#define WYS 720
#define SZER 1280

RenderWindow window(VideoMode(SZER,WYS),"Renegade Jedi in Africa",Style::Fullscreen);

Game::Game(void){
	state = END;

	if(!font.loadFromFile("data/arial.ttf"))
	{
		MessageBox(NULL,"Font not found!","ERROR",NULL);
		return;
	}

	state = MENU;

}


Game::~Game(void){
}


void Game::runGame(){
	while(state != END)
	{
		switch (state)
		{
		case MENU:
			menu();
			break;
		case GAME:
            mainGame mainGame(window);
            state=MENU;
			break;
		}
	}
}


void Game::menu(){
	Text title("Renegade Jedi in Africa",font,60);
	title.setStyle(Text::Bold);

	title.setPosition(SZER/2-title.getGlobalBounds().width/2,20);

	const int ile = 2;

	Text tekst[ile];

	string str[] = {"Graj","Wyjdz"};
	for(int i=0;i<ile;i++){
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(50);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(SZER/2-tekst[i].getGlobalBounds().width/2,250+i*120);
	}

	while(state == MENU){
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while(window.pollEvent(event)){

			if(event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			else if(tekst[1].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left){
				state = END;
			}

			else if(tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left){
				state = GAME;
			}
		}
		for(int i=0;i<ile;i++)
			if(tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Green);
			else tekst[i].setColor(Color::White);

		window.clear();

		window.draw(title);
		for(int i=0;i<ile;i++)
			window.draw(tekst[i]);

		window.display();
	}


}
