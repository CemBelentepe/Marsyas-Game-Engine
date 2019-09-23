#pragma once
#include "Camera.h"
#include "Math.h"

namespace mge
{
	enum AlignMode
	{
		TOP_LEFT, TOP_CENTER, TOP_RIGHT,
		CENTER_LEFT, CENTER, CENTER_RIGHT,
		BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT
	};

	class Renderer
	{
	protected:
		Vector2f pos;
		Vector2f scale;
		float rotation;

		AlignMode align;

		bool enabled = true;
	public:
		Vector2f offset;
		virtual ~Renderer() {}

		virtual void render(sf::RenderWindow& window, Camera& camera) = 0;

		virtual void setActive(bool isActive) = 0;
		virtual bool isActive() { return this->enabled; }

		virtual void setPosition(Vector2f pos)	 { this->pos = pos;			  }
		virtual void setScale(Vector2f scale)	 { this->scale = scale;		  }
		virtual void setRotation(float rotation) { this->rotation = rotation; }
		virtual void setAlign(AlignMode align)	 { this->align = align;		  }

		virtual Vector2f  getPosition()	{ return this->pos;		 }
		virtual Vector2f  getScale()	{ return this->scale;	 }
		virtual float	  getRotation()	{ return this->rotation; }
		virtual AlignMode getAlign()	{ return this->align;	 }

		virtual Vector2f getSize() = 0;
		virtual FloatRect getBoundingBox() = 0;
	};
}
