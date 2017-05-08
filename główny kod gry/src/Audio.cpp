#include "Audio.h"
#include <string>

using namespace std;

Audio::Audio(bool load)
{
		loadMusic();
		loadSounds();
}


Audio::~Audio(void)
{
}


bool Audio::loadMusic()
{
	string path;
		path="data/soundtrack/starwars.wav";

	if(!music.openFromFile(path))
		return false;

	music.setLoop(true);
	return true;
}


bool Audio::loadSounds()
{

    if(!bufor[0].loadFromFile("data/soundtrack/shot.wav"))
			return false;
    else if(!bufor[1].loadFromFile("data/soundtrack/goku.wav"))
            return false;
    else if(!bufor[2].loadFromFile("data/soundtrack/click.wav"))
            return false;
    else return true;
}


void Audio::playMusic()
{
	music.play();
}


void Audio::stopMusic()
{
	music.stop();
}


void Audio::playSound(SoundType type)
{
	sound.setBuffer(bufor[type]);
	sound.play();
}


void Audio::setVolume(bool volume)
{
	if(!volume)
	{
		music.setVolume(0);
	}
	else
	{
		music.setVolume(100);
	}
}
