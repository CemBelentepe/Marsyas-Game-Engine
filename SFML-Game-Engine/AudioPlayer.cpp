#include "AudioPlayer.h"
#include "Resources.h"

namespace mge
{
	void AudioPlayer::start()
	{
		if (playOnStart)
		{
			this->play();
		}
	}
	void AudioPlayer::play()
	{
		this->sound.play();
	}
	void AudioPlayer::pause()
	{
		this->sound.pause();
	}
	void AudioPlayer::stop()
	{
		this->sound.stop();
	}
	void AudioPlayer::setAudio(const sf::String& name)
	{
		this->sound.setBuffer(*(Resources::getSound(name)));
	}
	void AudioPlayer::setLoop(bool loop)
	{
		this->sound.setLoop(loop);
	}
	void AudioPlayer::setVolume(float volume)
	{
		this->sound.setVolume(volume);
	}
	sf::String AudioPlayer::getAudio()
	{
		return this->audioName;
	}
	bool AudioPlayer::getLoop()
	{
		return this->sound.getLoop();
	}
	float AudioPlayer::getVolume()
	{
		return this->sound.getVolume();
	}
}