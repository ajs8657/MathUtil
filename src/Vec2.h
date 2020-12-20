#pragma once

#include "Exception/VectorException.h"
#include <cmath>

namespace Math {

    template<typename T>
    class Vec2 {

    public:

        static const Vec2 Origin;

        // Empty constructor
        Vec2() = delete;

        // Default constructor
        Vec2(T x, T y) : x(x), y(y) {}

        // Copy constructor
        Vec2(const Vec2<T>& other) = default;

        // Move contstructor
        Vec2(Vec2&& other) = default;

        // Destructor
        ~Vec2() = default;

        // Const Add by vector
        Vec2<T> Add(const Vec2<T>& other) const {
            return Vec2<T>(x + other.x, y + other.y);
        }

        // Const Add by values
        Vec2<T> Add(T dx, T dy) const {
            return Vec2<T>(x + dx, y + dy);
        }

        // Const Scale by vector
        Vec2<T> Scale(const Vec2<T>& other) const {
            return Vec2<T>(x * other.x, y * other.y);
        }

        // Const Scale by values
        Vec2<T> Scale(T dx, T dy) const {
            return Vec2<T>(x * dx, y * dy);
        }

        // Const Scale by one value
        Vec2<T> Scale(T scalar) const {
            return Vec2<T>(x * scalar, y * scalar);
        }

        // Const Normalize
        Vec2<T> Normalize() const {
            auto magnitude = sqrt(x * x + y * y);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            return Vec2<T>(x / magnitude, y / magnitude);
        }


        // Mutator Add by vector
        Vec2<T> Add(const Vec2<T>& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        // Mutator Add by values
        Vec2<T> Add(T dx, T dy) {
            x += dx;
            y += dy;
            return *this;
        }

        // Mutator Scale by vector
        Vec2<T> Scale(const Vec2<T>& other) {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        // Mutator Scale by values
        Vec2<T> Scale(T dx, T dy) {
            x *= dx;
            y *= dy;
            return *this;
        }

        // Mutator Scale by one value
        Vec2<T> Scale(T scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        // Mutator Normalize
        Vec2<T> Normalize() {
            auto magnitude = sqrt(x * x + y * y);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            x /= magnitude;
            y /= magnitude;
            return *this;
        }


        // Get normalized direction to another vector
        Vec2<T> DirectionTo(const Vec2<T>& other) const {
            auto newX = other.x - x;
            auto newY = other.y - y;
            auto magnitude = sqrt(newX * newX + newY * newY);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            newX /= magnitude;
            newY /= magnitude;
            return Vec2<T>(newX, newY);
        }

        // Get the euclidean distance to the origin (0, 0)
        T Magnitude() const {
            return sqrt(x * x + y * y);
        }

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec2<T>& other) const {
            auto dx = other.x - x;
            auto dy = other.y - y;
            return sqrt(dx * dx + dy * dy);
        }

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec2<T>& other) const {
            auto dx = other.x - x;
            auto dy = other.y - y;
            return dx * dx + dy * dy;
        }

        inline T GetX() const { return x; }

        inline T GetY() const { return y; }

    private:

        T x, y;

    };

    template<typename T>
    const Vec2<T> Vec2<T>::Origin(0, 0);

}
