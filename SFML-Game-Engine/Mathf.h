#pragma once

namespace mge
{
	class Mathf
	{
	public:
		// Constants
		/// <summary>
		/// Euler's number, constant e.
		/// </summary>
		const static float E;
		/// <summary>
		/// The famous Pi = 3.14159265.... 
		/// </summary>
		const static float PI;
		/// <summary>
		/// Error for calculating algothms to stop when they reach to. (For floats 1E-7 is almost a 0)
		/// </summary>
		static float err;
		/// <summary>
		/// Maximum number of iterations for calculating algorithms.
		/// </summary>
		static float max_complexity;

		// General Math Functions----------------------------------------------
		/// <summary>
		/// Returns a clamps of a value between two values.
		/// </summary>
		/// <param name="x">Value to clamp.</param>
		/// <param name="min">Min value</param>
		/// <param name="max">Max value</param>
		/// <returns>Value clamped between min and max.</returns>
		static float clamp(float x, float min, float max);
		/// <summary>
		/// Takes the absoulte value of x.
		/// </summary>
		/// <param name="x">Value to get absoulte.</param>
		/// <returns>Absoulute value of x</returns>
		static float abs(float x);
		/// <summary>
		/// Floors the number x.
		/// </summary>
		/// <param name="x">Value to get the floor.</param>
		/// <returns>Returns the greatest integer smaller then x.</returns>
		static int floor(float x);
		/// <summary>
		/// Takes the ceil of number x.
		/// </summary>
		/// <param name="x">Value to get the ceil.</param>
		/// <returns>Returns the smallest integer greater then x</returns>
		static int ceil(float x);
		/// <summary>
		/// Returns the maximum of a and b.
		/// </summary>
		/// <param name="a">Value.</param>
		/// <param name="b">Value.</param>
		/// <returns>Maximum of a and b.</returns>
		static int max(int a, int b);
		/// <summary>
		/// Returns the minimum of a and b.
		/// </summary>
		/// <param name="a">Value.</param>
		/// <param name="b">Value.</param>
		/// <returns>Minimum of a and b</returns>
		static int min(int a, int b);
		/// <summary>
		/// Returns the maximum of a and b.
		/// </summary>
		/// <param name="a">Value.</param>
		/// <param name="b">Value.</param>
		/// <returns>Maximum of a and b.</returns>
		static float max(float a, float b);
		/// <summary>
		/// Returns the minimum of a and b.
		/// </summary>
		/// <param name="a">Value.</param>
		/// <param name="b">Value.</param>
		/// <returns>Minimum of a and b</returns>
		static float min(float a, float b);
		/// <summary>
		/// Raises base to the power <param name="power">power</param>.
		/// </summary>
		/// <param name="base">Base to raise.</param>
		/// <param name="power">Power parameter.</param>
		/// <returns>Returns base^power.</returns>
		static float pow(float base, float power);
		/// <summary>
		/// Raises base to the power <param name="power">power</param>.
		/// </summary>
		/// <param name="base">Base to raise.</param>
		/// <param name="power">Power parameter.</param>
		/// <returns>Returns base^power.</returns>
		static float pow(float base, int power);
		/// <summary>
		/// Takes the root of number to 'degree'th root
		/// </summary>
		/// <param name="number">Number to take root.</param>
		/// <param name="degree">Degree of root.</param>
		/// <returns>Returns number^(1/degree).</returns>
		static float root(float number, float degree);
		/// <summary>
		/// Takes the square root of number.
		/// </summary>
		/// <param name="number">Number to get the square root.</param>
		/// <returns>Returns number^0.5.</returns>
		static float sqrt(float number);
		/// <summary>
		/// Fast inverse square rooting algorithm from Quake 3.
		/// <para>Used for normalization of vectors.</para>
		/// </summary>
		/// <param name="number">Number to take inverse square root.</param>
		/// <returns>Returns ~1/sqrt(number).</returns>
		static float Q_rsqrt(float number);
		/// <summary>
		/// Calculates n!= n*(n-1)!.
		/// Returns n!.
		/// </summary>
		/// <param name="n">Number to calculate its factorial</param>
		/// <returns>Returns n!.</returns>
		static int factorial(unsigned int n);

		// Random--------------------------------------------------------------
		/// <summary>
		/// Returns a random value between 0 and 1.
		/// </summary>
		/// <returns>Random value between 0 and 1</returns>
		static float rand01();
		/// <summary>
		/// Returns a random value between a and b.
		/// </summary>
		/// <param name="a">Minimum of random value.</param>
		/// <param name="b">Maximum of random value.</param>
		/// <returns>Random value between a and b.</returns>
		static float rand(float a, float b);
		/// <summary>
		/// Returns a random value between a and b.
		/// </summary>
		/// <param name="a">Minimum of random value.</param>
		/// <param name="b">Maximum of random value.</param>
		/// <returns>Random value between a and b.</returns>
		static int rand(int a, int b);
		/// <summary>
		/// Returns a random value between 0 and b.
		/// </summary>
		/// <param name="a">Maximum of random value.</param>
		/// <returns>Random value between a and b.</returns>
		static int rand(int a);
		/// <summary>
		/// Sets the seed of random calculator.
		/// </summary>
		/// <param name="seed">Seed of random system.</param>
		static void setRandSeed(unsigned int seed);

		// Trigonometric Functions---------------------------------------------
		static float sin(float angle, bool isRad = false);
		static float cos(float angle, bool isRad = false);
		static float tan(float angle, bool isRad = false);
		static float cot(float angle, bool isRad = false);

		static float asin(float number, bool isRad = false);
		static float acos(float number, bool isRad = false);
		static float atan(float number, bool isRad = false);
		static float acot(float number, bool isRad = false);

		// Logarithmic Functions-----------------------------------------------
		/// <summary>
		/// Returns natural log of number.
		/// </summary>
		/// <param name="number">Number to take the log of.</param>
		/// <returns>Returns ln(number).</returns>
		static float log(float number);
		/// <summary>
		/// Returns log of number in base base.
		/// </summary>
		/// <param name="number">Number to calculate the log of.</param>
		/// <param name="base">Base of log.</param>
		/// <returns>Returns ln(number)/ln(base).</returns>
		static float log(float number, float base);
		/// <summary>
		/// Returns Euler's number e to the power power
		/// </summary>
		/// <param name="power">Power to calculate.</param>
		/// <returns>Returns e^power</returns>
		static float exp(float power);
		/// <summary>
		/// Returns Euler's number e to the power power
		/// </summary>
		/// <param name="power">Power to calculate.</param>
		/// <returns>Returns e^power</returns>
		static float exp(int power);
	};
}