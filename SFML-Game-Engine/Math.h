#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mathf.h"

namespace mge
{
	/// <summary>
	/// An object consisting of two values.
	/// </summary>
	template <class T>
	class Vector2
	{
	public:
		/// <summary>
		/// First element of the vector.
		/// </summary>
		T x;
		/// <summary>
		/// Second element of the vector.
		/// </summary>
		T y;

		/// <summary>
		/// Creates a vector with values 0. 
		/// <para>Equivalent of calling Vector2(0, 0).</para>
		/// </summary>
		Vector2() :x(0), y(0) {}
		/// <summary>
		/// Creates a vector with values x and y.
		/// </summary>
		/// <param name="x">First value of the vector.</param>
		/// <param name="y">Second value of the vector.</param>
		Vector2(T x, T y) : x(x), y(y) {}
		/// <summary>
		/// Creates a vector from a sf::Vector2 object.
		/// </summary>
		/// <param name="sfVector">Source object to create from.</param>
		Vector2(const sf::Vector2<T>& sfVector) : x(sfVector.x), y(sfVector.y) {}

		/// <summary>
		/// Creates a vector using another Vector2 object with different template.
		/// <para>Uses static_cast for type changes.</para>
		/// </summary>
		/// <param name="vector">Vector2 object to copy from.</param>
		template <class U>
		Vector2(const Vector2<U>& vector)
		{
			this->x = static_cast<T>(vector.x);
			this->y = static_cast<T>(vector.y);
		}

		/// <summary>
		/// Calculates and returns the magnitude of the vector.
		/// <para>Uses mge::Mathf::Q_rsqrt if fast paremeter is true.</para>
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		/// <returns>Magnitude of the vector.</returns>
		float magnitude(bool fast = true) const
		{
			float v = x * x + y * y;
			if (fast)
				return 1 / Mathf::Q_rsqrt(v);
			else
				return Mathf::sqrt(v);
		}
		/// <summary>
		/// Returns square of the vector's magnitude.
		/// </summary>
		/// <returns>Squre of vector's magnitude.</returns>
		float sqrMagnitude() const
		{
			return  x * x + y * y;
		}
		/// <summary>
		/// Returns a *new* unit vector with the same direction of the vector.
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		/// <returns>*New* unit vector with the same direction of the vector</returns>
		Vector2<T> getNormalized(bool fast = true) const
		{
			if (fast)
				return (*this) * Mathf::Q_rsqrt(x * x + y * y);
			else
				return (*this) / magnitude(false);
		}
		/// <summary>
		/// Normalizes the vector
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		void normalize(bool fast = true)
		{
			if (fast)
				(*this) *= Mathf::Q_rsqrt(x * x + y * y);
			else
				(*this) /= magnitude(false);
		}
		/// <summary>
		/// Takes the dot product between this vector and parameter vec.
		/// </summary>
		/// <param name="vec">Other vector to dot between.</param>
		/// <returns>Returns the dot product.</returns>
		float dot(const Vector2<T>& vec) const
		{
			return x * vec.x + y * vec.y;
		}

		friend Vector2<T> operator-(const Vector2<T>& right)
		{
			return Vector2(-right.x, -right.y);
		}

		friend Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
		{
			return Vector2(left.x + right.x, left.y + right.y);
		}

		friend Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
		{
			return Vector2<T>(left.x - right.x, left.y - right.y);
		}

		friend Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
		{
			left.x += right.x;
			left.y += right.y;
			return left;
		}

		friend Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
		{
			left.x -= right.x;
			left.y -= right.y;
			return left;
		}

		friend bool operator==(const Vector2<T>& left, const Vector2<T>& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		friend bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
		{
			return left.x != right.x || left.y != right.y;
		}

		friend Vector2<T> operator*(const T left, const Vector2<T>& right)
		{
			return Vector2(left * right.x, left * right.y);
		}

		friend Vector2<T> operator*(const Vector2<T>& left, const T right)
		{
			return Vector2(right * left.x, right * left.y);
		}

		friend Vector2<T> operator/(const Vector2<T>& left, const T right)
		{
			return Vector2(left.x / right, left.y / right);
		}

		friend Vector2<T>& operator*=(Vector2<T>& left, const T right)
		{
			left.x *= right;
			left.y *= right;
			return left;
		}

		friend Vector2<T>& operator/=(Vector2<T>& left, const T right)
		{
			left.x /= right;
			left.y /= right;
			return left;
		}

		friend std::ostream& operator<<(std::ostream& out, Vector2<T> vector)
		{
			out << "(" << vector.x << ", " << vector.y << ")";
			return out;
		}

		operator sf::Vector2<T>()
		{
			return sf::Vector2<T>(x, y);
		}
	};

	/// <summary>
	/// An object consisting of three values.
	/// </summary>
	template <class T>
	class Vector3
	{
	public:
		/// <summary>
		/// First value of the vector.
		/// </summary>
		T x;
		/// <summary>
		/// Second value of the vector.
		/// </summary>
		T y;
		/// <summary>
		/// Third value of the vector.
		/// </summary>
		T z;

		/// <summary>
		/// Creates a vector with values 0. 
		/// <para>Equivalent of calling Vector3(0, 0).</para>
		/// </summary>
		Vector3() :x(0), y(0), z(0) {}
		/// <summary>
		/// Creates a vector whose z value is 0.
		/// <para>Equivalent of calling Vector3(x, y, 0).</para>
		/// </summary>
		/// <param name="x">First value of the vector.</param>
		/// <param name="y">Second value of the vector.</param>
		Vector3(T x, T y) : x(x), y(y), z(0) {}
		/// <summary>
		/// Creates a vector with values x, y and z.
		/// </summary>
		/// <param name="x">First value of the vector.</param>
		/// <param name="y">Second value of the vector.</param>
		/// <param name="z">Third value of the vector.</param>
		Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
		/// <summary>
		/// Creates a new vector whose z value is 0, and x and y values are the vector parameter's x and y values.
		/// </summary>
		/// <param name="vector">Vector2 object to copy from.</param>
		Vector3(const Vector2<T>& vector) : x(vector.x), y(vector.y), z(0) {}
		/// <summary>
		/// Creates a new vector whose z value is parameter z, and x and y values are the vector parameter's x and y values.
		/// </summary>
		/// <param name="vector">Vector2 object to copy from.</param>
		/// <param name="z">z value of the vector.</param>
		Vector3(const Vector2<T>& vector, float z) : x(vector.x), y(vector.y), z(z) {}

		/// <summary>
		/// Creates a new vector from sf::Vector2 object, whose z value is 0;
		/// </summary>
		/// <param name="sfVector">Source object to create from.</param>
		Vector3(const sf::Vector2<T>& sfVector) : x(sfVector.x), y(sfVector.y), z(0) {}
		/// <summary>
		/// Creates a new vector from sf::Vector2 object, whose z value is parameter z.
		/// </summary>
		/// <param name="sfVector">Source object to create from.</param>
		/// <param name="z">z value of the vector.</param>
		Vector3(const sf::Vector2<T>& sfVector, float z) : x(sfVector.x), y(sfVector.y), z(z) {}
		/// <summary>
		/// Creates a new vector from sf::Vector3 object.
		/// </summary>
		/// <param name="sfVector">Source object to create from.</param>
		Vector3(const sf::Vector3<T>& sfVector) : x(sfVector.x), y(sfVector.y), z(sfVector.z) {}

		/// <summary>
		/// Creates a vector using another Vector3 object with different template.
		/// <para>Uses static_cast for type changes.</para>
		/// </summary>
		/// <param name="vector">Vector3 object to copy from.</param>
		template <class U>
		Vector3(const Vector3<U>& vector)
		{
			this->x = static_cast<T>(vector.x);
			this->y = static_cast<T>(vector.y);
			this->z = static_cast<T>(vector.z);
		}

		/// /// <summary>
		/// Calculates and returns the magnitude of the vector.
		/// <para>Uses mge::Mathf::Q_rsqrt if fast paremeter is true.</para>
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		/// <returns>Magnitude of the vector.</returns>
		float magnitude(bool fast = true) const
		{
			float v = x * x + y * y + z * z;
			if (fast)
				return 1 / Mathf::Q_rsqrt(v);
			else
				return Mathf::sqrt(v);
		}
		/// <summary>
		/// Returns square of the vector's magnitude.
		/// </summary>
		/// <returns>Squre of vector's magnitude.</returns>
		float sqrMagnitude() const
		{
			return  x * x + y * y + z * z;
		}
		/// <summary>
		/// Returns a *new* unit vector with the same direction of the vector.
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		/// <returns>*New* unit vector with the same direction of the vector</returns>
		Vector3<T> getNormalized(bool fast = true) const
		{
			if (fast)
				return (*this) * Mathf::Q_rsqrt(x * x + y * y + z * z);
			else
				return (*this) / magnitude(false);
		}
		/// <summary>
		/// Normalizes the vector
		/// </summary>
		/// <param name="fast">If true uses mge::Mathf::Q_rsqrt, else uses mge::Mathf::sqrt for calculating.</param>
		void normalize(bool fast = true)
		{
			if (fast)
				(*this) *= Mathf::Q_rsqrt(x * x + y * y + z * z);
			else
				(*this) /= magnitude(false);
		}
		/// <summary>
		/// Takes the dot product between this vector and parameter vec.
		/// </summary>
		/// <param name="vec">Other vector to dot between.</param>
		/// <returns>Returns the dot product.</returns>
		float dot(const Vector3<T>& vec) const
		{
			return x * vec.x + y * vec.y + z * vec.z;
		}

		/// <summary>
		/// Calculates the cross product between this vector and parameter other vector.
		/// Returns a new vector, normal to the both vector and have the magnitude of their area.
		/// </summary>
		/// <param name="other">Other vector to calculate the cross product.</param>
		/// <returns></returns>
		Vector3<T> cross(const Vector3<T>& other) const
		{
			float x_ = (this->y * other.z) - (this->z * other.y);
			float y_ = (this->z * other.x) - (this->x * other.z);
			float z_ = (this->x * other.y) - (this->y * other.x);
			return Vector3<T>(x_, y_, z_);
		}

		friend Vector3<T> operator-(const Vector3<T>& right)
		{
			return Vector3(-right.x, -right.y, -right.z);
		}

		friend Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
		{
			return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
		}

		friend Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
		{
			return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
		}

		friend Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right)
		{
			left.x += right.x;
			left.y += right.y;
			left.z += right.z;
			return left;
		}

		friend Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right)
		{
			left.x -= right.x;
			left.y -= right.y;
			left.z -= right.z;
			return left;
		}

		friend bool operator==(const Vector3<T>& left, const Vector3<T>& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		friend bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
		{
			return left.x != right.x || left.y != right.y || left.z != right.z;
		}

		friend Vector3<T> operator*(const T left, const Vector3<T>& right)
		{
			return Vector3(left * right.x, left * right.y, left * right.z);
		}

		friend Vector3<T> operator*(const Vector3<T>& left, const T right)
		{
			return Vector3(right * left.x, right * left.y, right * left.z);
		}

		friend Vector3<T> operator*(const Vector3<T>& left, const Vector3<T> right)
		{
			float x_ = (left.y * right.z) - (left.z * right.y);
			float y_ = (left.z * right.x) - (left.x * right.z);
			float z_ = (left.x * right.y) - (left.y * right.x);
			return Vector3<T>(x_, y_, z_);
		}

		friend Vector3<T> operator/(const Vector3<T>& left, const T right)
		{
			return Vector3(left.x / right, left.y / right, left.z / right);
		}

		friend Vector3<T>& operator*=(Vector3<T>& left, const T right)
		{
			left.x *= right;
			left.y *= right;
			left.z *= right;
			return left;
		}

		friend Vector3<T>& operator/=(Vector3<T>& left, const T right)
		{
			left.x /= right;
			left.y /= right;
			left.z /= right;
			return left;
		}

		friend std::ostream& operator<<(std::ostream& out, Vector3<T> vector)
		{
			out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return out;
		}

		operator sf::Vector3<T>()
		{
			return sf::Vector3<T>(x, y, z);
		}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
	typedef Vector2<unsigned int> Vector2u;

	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;
	typedef Vector3<unsigned int> Vector3u;

	/// <summary>
	/// An object holding a position and size for a rectangle.
	/// </summary>
	template <class T>
	class Rect
	{
	public:
		/// <summary>
		/// Top-left corner point's x value.
		/// </summary>
		T left;
		/// <summary>
		/// Top-left corner point's y value.
		/// </summary>
		T top;
		/// <summary>
		/// Width of the rectangle
		/// </summary>
		T width;
		/// <summary>
		/// Height of the rectangle.
		/// </summary>
		T height;

	public:
		/// <summary>
		/// Creates a rectangle at the top-left point (0, 0), with the size (0, 0).
		/// </summary>
		Rect() :left(0), top(0), width(0), height(0) {}
		/// <summary>
		/// Creates a rectangle at the top-left point (rectLeft, rectTop), with the size (rectWidth, rectHeight).
		/// </summary>
		/// <param name="rectLeft">x position of the rectangle's top-left corner.</param>
		/// <param name="rectTop">y position of the rectangle's top-left corner.</param>
		/// <param name="rectWidth">Width of the rectangle.</param>
		/// <param name="rectHeight">Height of the rectangle.</param>
		Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight) : left(rectLeft), top(rectTop), width(rectWidth), height(rectHeight) {}
		/// <summary>
		/// Creates a rectangle  at the top-left point (position), with the size (size).
		/// </summary>
		/// <param name="position">Position of the rectangle's top-left corner.</param>
		/// <param name="size">Size of the rectangle as (width, height) vector.</param>
		Rect(const Vector2<T>& position, const Vector2<T>& size) : left(position.x), top(position.y), width(size.x), height(size.y) {}
		/// <summary>
		/// Creates a new Rect object from a sf::Rect object.
		/// </summary>
		/// <param name="rect">Source object to create from.</param>
		Rect(const sf::Rect<T>& rect) : left(rect.left), top(rect.top), width(rect.width), height(rect.height) {}

		/// <summary>
		/// Creates a rectangle using another Rect object with different template.
		/// <para>Uses static_cast for type changes.</para>
		/// </summary>
		/// <param name="rect">Rect object to copy from.</param>
		template <class U>
		Rect(const Rect<U>& rect)
		{
			this->left = static_cast<T>(rect.left);
			this->top = static_cast<T>(rect.top);
			this->width = static_cast<T>(rect.width);
			this->height = static_cast<T>(rect.height);
		}

		/// <summary>
		/// Looks if the point (x, y) is in the rectangle's bounds.
		/// <para>Returns false if it is on the edges of the rectangle.</para>
		/// </summary>
		/// <param name="x">x value of the point.</param>
		/// <param name="y">y value of the point.</param>
		/// <returns>Returns whether if the point is inside of the rectengle or not. 
		/// Edges do not count as inside on this function.</returns>
		bool contains(T x, T y) const
		{
			return (x > left && x < left + width && y > top && y < top + height);
		}

		/// <summary>
		/// Looks if the parameter point is in the rectangle's bounds.
		/// <para>Returns false if it is on the edges of the rectangle.</para>
		/// </summary>
		/// <param name="point">Point to look if its inside or not.</param>
		/// <returns>Returns whether if the point is inside of the rectengle or not. 
		/// Edges do not count as inside on this function.</returns>
		bool contains(const Vector2<T>& point) const
		{
			T x = point.x;
			T y = point.y;
			return (x > left && x < left + width && y > top && y < top + height);
		}

		/// <summary>
		/// Checks for the intersection of the rectangles.
		/// </summary>
		/// <param name="rectangle">Other rectangle to check.</param>
		/// <returns>Returns true if two rectangles are intersecting.</returns>
		bool intersects(const Rect<T>& rectangle) const
		{
			return (left < rectangle.left + rectangle.width && left + width > rectangle.left &&
				top < rectangle.top + rectangle.height && top + height > rectangle.top);
		}

		/// <summary>
		/// Checks for the intersection of the rectangles. *And* calculates the intersection region rectangle.
		/// </summary>
		/// <param name="rectangle">Other rectangle to check.</param>
		/// <param name="intersection">Referance to return intersection at.</param>
		/// <returns>Returns true if two rectangles are intersecting.</returns>
		bool intersects(const Rect<T>& rectangle, Rect<T>& intersection) const
		{
			T x5 = Mathf::max(left, rectangle.left);
			T y5 = Mathf::max(top, rectangle.top);

			T x6 = Mathf::min(left + width, rectangle.left + rectangle.width);
			T y6 = Mathf::min(top + height, rectangle.top + rectangle.height);

			// no intersection 
			if (x5 > x6 || y5 > y6)
				return false;

			intersection.left = x5;
			intersection.top = y5;
			intersection.width = x6 - x5;
			intersection.height = y6 - y5;

			return true;
		}

		/// <summary>
		/// Sets the position of the rect.
		/// </summary>
		/// <param name="x">Left position of the rect</param>
		/// <param name="y">Top position of the rect.</param>
		void setPosition(T x, T y)
		{
			this->left = x;
			this->top = y;
		}

		/// <summary>
		/// Sets the position of the rect.
		/// </summary>
		/// <param name="pos">Position of the top-left position of the rect.</param>
		void setPosition(const Vector2<T>& pos)
		{
			this->left = pos.x;
			this->top = pos.y;
		}

		/// <summary>
		/// Sets the size of the rect.
		/// </summary>
		/// <param name="width">Width of the rect.</param>
		/// <param name="height">Height of the rect.</param>
		void setSize(T width, T height)
		{
			this->width = width;
			this->height = height;
		}

		/// <summary>
		/// Sets the size of the rect.
		/// </summary>
		/// <param name="size">A vector whose x, y parameters are width and height of the size respectively.</param>
		void setSize(const Vector2<T>& size)
		{
			this->width = size.x;
			this->height = size.y;
		}

		/// <summary>
		/// Returns the position of the rect as Vector2(left, top).
		/// </summary>
		/// <returns>Position of the rect as a Vector2.</returns>
		Vector2<T> getPosition()
		{
			return Vector2<T>(left, top);
		}

		/// <summary>
		/// Returns the size of the rect as Vector2(width, height).
		/// </summary>
		/// <returns>Size of the rect as a Vector2.</returns>
		Vector2<T> getSize()
		{
			return Vector2<T>(width, height);
		}

		friend bool operator==(const Rect<T>& left, const Rect<T>& right)
		{
			return left.left == right.left && left.top == right.top && left.width == right.width && left.height == right.height;
		}

		friend bool operator!=(const Rect<T>& left, const Rect<T>& right)
		{
			return left.left != right.left || left.top != right.top || left.width != right.width || left.height != right.height;
		}


		friend std::ostream& operator<<(std::ostream& out, Rect<T> rect)
		{
			out << "([" << rect.left << ", " << rect.top << "], [" << rect.width << ", " << rect.height << "])";
			return out;
		}

		operator sf::Rect<T>()
		{
			return sf::Rect<T>(left, top, width, height);
		}
	};

	typedef Rect<int> IntRect;
	typedef Rect<float> FloatRect;
	typedef Rect<double> DoubleRect;
	typedef Rect<unsigned int> UIntRect;
}
