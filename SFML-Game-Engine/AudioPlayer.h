#pragma once
#include <SFML/Audio.hpp>
#include "Component.h"

namespace mge
{
	class AudioPlayer : public Component
	{
	private:
		sf::String audioName;
		sf::Sound sound;
	public:
		bool playOnStart;

		AudioPlayer(GameObject* gameObject) : Component(gameObject), playOnStart(false) {}

		void start() override;

		void play();
		void pause();
		void stop();

		void setAudio(const sf::String& name);
		void setLoop(bool loop);
		void setVolume(float volume);
		
		sf::String getAudio();
		bool getLoop();
		float getVolume();
	};
}
