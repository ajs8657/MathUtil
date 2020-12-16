#pragma once

#include "Exception/VectorException.h"
#include <cmath>

namespace Math {

    template<typename T>
    class Vec2 {

    public:

        static const Vec2<T> Origin;

        // Empty constructor
        Vec2() = delete;

        // Default constructor
        Vec2(T x, T y);

        // Copy constructor
        Vec2(const Vec2<T>& other) = default;

        // Move contstructor
        Vec2(Vec2&& other) = default;

        // Destructor
        ~Vec2() = default;

        // Const Move by vector
        Vec2<T> Move(const Vec2<T>& other) const;

        // Const Move by values
        Vec2<T> Move(T dx, T dy) const;

        // Const Scale by vector
        Vec2<T> Scale(const Vec2<T>& other) const;

        // Const Scale by values
        Vec2<T> Scale(T dx, T dy) const;

        // Const Scale by one value
        Vec2<T> Scale(T scalar) const;

        // Const Normalize
        Vec2<T> Normalize() const;


        // Mutator Move by vector
        Vec2<T> Move(const Vec2<T>& other);

        // Mutator Move by values
        Vec2<T> Move(T x, T y);

        // Mutator Scale by vector
        Vec2<T> Scale(const Vec2<T>& other);

        // Mutator Scale by values
        Vec2<T> Scale(T x, T y);

        // Mutator Scale by one value
        Vec2<T> Scale(T scalar);

        // Mutator Normalize
        Vec2<T> Normalize();


        // Get normalized direction to another vector
        Vec2<T> DirectionTo(const Vec2<T>& other) const;

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec2<T>& other) const;

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec2<T>& other) const;

        inline T GetX() { return x; }

        inline T GetY() { return y; }

    private:

        T x, y;

    };

    template<typename T>
    const Vec2<T> Vec2<T>::Origin = Vec2<T>(0, 0);

    template<typename T>
    Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}

    /* Const Methods */

    template<typename T>
    Vec2<T> Vec2<T>::Move(const Vec2<T>& other) const {
        return Vec2<T>(x + other.x, y + other.y);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Move(T dx, T dy) const {
        return Vec2<T>(x + dx, y + dy);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(const Vec2<T>& other) const {
        return Vec2<T>(x * other.x, y * other.y);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(T dx, T dy) const {
        return Vec2<T>(x * dx, y * dy);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(T scalar) const {
        return Vec2<T>(x * scalar, y * scalar);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Normalize() const {
        auto magnitude = sqrt(x * x + y * y);
        if (magnitude == 0) {
            throw VectorException(VectorError::NORMALIZE_ZERO);
        }
        return Vec2<T>(x / magnitude, y / magnitude);
    }

    /* Mutator Methods */

    template<typename T>
    Vec2<T> Vec2<T>::Move(const Vec2<T>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Move(T dx, T dy) {
        x += dx;
        y += dy;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(const Vec2<T>& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(T dx, T dy) {
        x *= dx;
        y *= dy;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Normalize() {
        auto magnitude = sqrt(x * x + y * y);
        if (magnitude == 0) {
            throw VectorException(VectorError::NORMALIZE_ZERO);
        }
        x /= magnitude;
        y /= magnitude;
        return *this;
    }

    /* Other Methods */

    template<typename T>
    Vec2<T> Vec2<T>::DirectionTo(const Vec2<T>& other) const {
        auto newX = other.x - x;
        auto newY = other.y - y;
        auto magnitude = sqrt(newX * newX + newY * newY);
        if (magnitude == 0) {
            throw VectorException(VectorError::NORMALIZE_ZERO);
        }
        newX /= magnitude;
        newY /= magnitude;
        return Vec2<T>(newX, newY);
    }

    template<typename T>
    T Vec2<T>::DistanceTo(const Vec2<T>& other) const {
        auto dx = other.x - x;
        auto dy = other.y - y;
        return sqrt(dx * dx + dy * dy);
    }

    template<typename T>
    T Vec2<T>::DistanceSqrTo(const Vec2<T>& other) const {
        auto dx = other.x - x;
        auto dy = other.y - y;
        return dx * dx + dy * dy;
    }

}
