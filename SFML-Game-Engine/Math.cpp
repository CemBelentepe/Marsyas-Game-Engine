#include "Mathf.h"

namespace mge
{
	float Mathf::clamp(float x, float min, float max)
	{
		if (x > max) return max;
		if (x < min) return min;
		return x;
	}
	float Mathf::abs(float x)
	{
		if (x >= 0) return x;
		return -x;
	}
	int Mathf::floor(float x)
	{
		int a = (int)x;
		if (a == x) return a;
		if (a > 0) return a;
		return a - 1;
	}
	int Mathf::ceil(float x)
	{
		int a = (int)x;
		if (a == x) return a;
		if (a > 0) return a + 1;
		return a;
	}
}