#include "Mathf.h"
#include <cstdint>
#include <cmath>


namespace mge
{
	const float Mathf::E = 2.71828;
	const float Mathf::PI = 3.14159265;
	float Mathf::err = 1E-6;
	float Mathf::max_complexity = 20;

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
	int Mathf::max(int a, int b)
	{
		if (a > b) return a;
		return b;
	}
	int Mathf::min(int a, int b)
	{
		if (a < b) return a;
		return b;
	}
	float Mathf::max(float a, float b)
	{
		if (a > b) return a;
		return b;
	}
	float Mathf::min(float a, float b)
	{
		if (a < b) return a;
		return b;
	}
	float Mathf::pow(float base, float power)
	{
		int a = floor(power);
		float b = power - a;
		float p1 = pow(base, a);
		float p2 = exp(b * log(base));
		return p1 * p2;
	}
	float Mathf::pow(float base, int power)
	{
		if (power == 0) return 1;
		if (power == 1) return base;

		float num = 1;

		bool reverse = power < 0;
		if (reverse) power *= -1;

		for (int i = 0; i < power; i++)
		{
			num *= base;
		}

		if (reverse) return 1.0f / num;
		return num;
	}
	float Mathf::root(float number, float degree)
	{
		return pow(number, 1.f / degree);
	}
	float Mathf::sqrt(float number)
	{
		return pow(number, 0.5f);
	}
	float Mathf::Q_rsqrt(float number)
	{
		const float x2 = number * 0.5F;
		const float threehalfs = 1.5F;

		union
		{
			float f;
			uint32_t i;
		} conv = { number }; // member 'f' set to value of 'number'.
		conv.i = 0x5f3759df - (conv.i >> 1);
		conv.f *= (threehalfs - (x2 * conv.f * conv.f));
		return conv.f;
	}
	int Mathf::factorial(unsigned int n)
	{
		if (n == 0 || n == 1) return 1;
		return n * factorial(n - 1);
	}
	float Mathf::rand01()
	{
		return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
	}
	float Mathf::rand(float a, float b)
	{
		return ((static_cast<float>(std::rand()) * (b - a) / static_cast<float>(RAND_MAX)) + a);
	}
	int Mathf::rand(int a, int b)
	{
		return std::rand() % (b - a) + a;
	}
	int Mathf::rand(int b)
	{
		return std::rand() % b;
	}
	void Mathf::setRandSeed(unsigned int seed)
	{
		std::srand(seed);
	}
	float Mathf::sin(float angle, bool isRad)
	{
		if (isRad)
			return sinf(angle);
		else
			return sinf(angle / 180.0f);
	}
	float Mathf::cos(float angle, bool isRad)
	{
		if (isRad)
			return std::cosf(angle);
		else
			return std::cosf(angle / 180.0f);
	}
	float Mathf::tan(float angle, bool isRad)
	{
		if (isRad)
			return std::tanf(angle);
		else
			return std::tanf(angle / 180.0f);
	}
	float Mathf::cot(float angle, bool isRad)
	{
		return 1.0f / tan(angle, isRad);
	}
	float Mathf::asin(float number, bool isRad)
	{
		if (isRad)
			return std::asinf(number);
		else
			return 180.0 * std::asinf(number);
	}
	float Mathf::acos(float number, bool isRad)
	{
		if (isRad)
			return std::acosf(number);
		else
			return 180.0f * std::acosf(number);
	}
	float Mathf::atan(float number, bool isRad)
	{
		if (isRad)
			return std::atanf(number);
		else
			return 180*std::atanf(number);
	}
	float Mathf::acot(float number, bool isRad)
	{
		return atan(1/number, isRad);
	}
	float Mathf::log(float number)
	{
		if (number > 1) return 1 + log(number / E);
		if (number == 1) return 0;

		float sum = 0;
		float x = number - 1;
		bool k = true;
		for (int i = 1; i < max_complexity + 1; i++)
		{
			float a = pow(x, i) / i;

			if (k) sum += a;
			else sum -= a;
			k = !k;
			if (abs(a) <= err) break;
		}
		return sum;
	}
	float Mathf::log(float number, float base)
	{
		return log(number) / log(base);
	}
	float Mathf::exp(float power)
	{
		int a = floor(power);
		float b = power - a;

		float p1 = exp(a);
		float p2 = 1 + b;

		float b0 = b;
		float f0 = 1;
		for (int i = 2; i < max_complexity; i++)
		{
			b0 *= b;
			f0 *= i;

			float inc = b0 / f0;
			p2 += inc;
			if (abs(inc) <= err) break;
		}
		return p1 * p2;
	}
	float Mathf::exp(int power)
	{
		return pow(E, power);
	}
}