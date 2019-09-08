#pragma once
#include "Math.h"

namespace mge
{
	class Renderer
	{
	protected:
		Vector2f pos;
		Vector2f scale;
		float rotation;

		bool enabled = true;
	public:
		virtual ~Renderer(){}

		virtual void render(sf::RenderWindow* window) = 0;

		virtual void setActive(bool isActive) = 0;
		virtual bool isActive() { return this->enabled; }

		virtual void setPosition(Vector2f pos) { this->pos = pos; }
		virtual void setScale(Vector2f scale) { this->scale = scale; }
		virtual void setRotation(float rotation) { this->rotation = rotation; }
					 
		virtual Vector2f getPosition() { return this->pos; }
		virtual Vector2f getScale() { return this->scale; }
		virtual float getRotation() { return this->rotation; }

		virtual Vector2f getSize() = 0;
		virtual FloatRect getBoundingBox() = 0;
	};
}
