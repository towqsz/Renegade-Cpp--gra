#pragma once

#include <SFML\Audio.hpp>

using namespace sf;

class Audio
{
public:
	Audio(bool load_everything=false);
	~Audio(void);

	enum SoundType{SHOOT, GOKU, CLICK, SIZE};

	bool loadMusic();
	bool loadSounds();

	void playMusic();
	void stopMusic();

	void playSound(SoundType sound);
	void setVolume(bool volume);

private:
	Music music;

	Sound sound;
	SoundBuffer bufor[SIZE];
};
