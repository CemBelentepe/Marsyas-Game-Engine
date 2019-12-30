#pragma once
#include "Math.h"

namespace mge
{
	class Camera
	{
	private:
		// Scale
	public:
		Vector2f pos;
		Vector2f size;
		float	 rotation;

		Camera(const Vector2f& pos, const Vector2f& size, float rotation):pos(pos), size(size), rotation(rotation){}

		//void update();
	};
}
