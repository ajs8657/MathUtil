#pragma once

#include "Exception/VectorException.h"
#include <cmath>

namespace Math {

    template <typename T>
    class Vec3 {

    public:

        static const Vec3 Origin;

        // Empty constructor
        Vec3() = delete;

        // Default constructor
        Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

        // Copy constructor
        Vec3(const Vec3<T>& other) = default;

        // Move contstructor
        Vec3(Vec3&& other) = default;

        // Destructor
        ~Vec3() = default;

        // Const Add by vector
        Vec3<T> Add(const Vec3<T>& other) const {
            return Vec3<T>(x + other.x, y + other.y, z + other.z);
        }

        // Const Add by values
        Vec3<T> Add(T dx, T dy, T dz) const {
            return Vec3<T>(x + dx, y + dy, z + dz);
        }

        // Const Scale by vector
        Vec3<T> Scale(const Vec3<T>& other) const {
            return Vec3<T>(x * other.x, y * other.y, z * other.z);
        }

        // Const Scale by values
        Vec3<T> Scale(T dx, T dy, T dz) const {
            return Vec3<T>(x * dx, y * dy, z * dz);
        }

        // Const Scale by one value
        Vec3<T> Scale(T scalar) const {
            return Vec3<T>(x * scalar, y * scalar, z * scalar);
        }

        // Const Normalize
        Vec3<T> Normalize() const {
            auto magnitude = sqrt(x * x + y * y + z * z);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            return Vec3<T>(x / magnitude, y / magnitude, z / magnitude);
        }


        // Mutator Add by vector
        Vec3<T> Add(const Vec3<T>& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        // Mutator Add by values
        Vec3<T> Add(T dx, T dy, T dz) {
            x += dx;
            y += dy;
            z += dz;
            return *this;
        }

        // Mutator Scale by vector
        Vec3<T> Scale(const Vec3<T>& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        // Mutator Scale by values
        Vec3<T> Scale(T dx, T dy, T dz) {
            x *= dx;
            y *= dy;
            z *= dz;
            return *this;
        }

        // Mutator Scale by one value
        Vec3<T> Scale(T scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }

        // Mutator Normalize
        Vec3<T> Normalize() {
            auto magnitude = sqrt(x * x + y * y + z * z);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            x /= magnitude;
            y /= magnitude;
            z /= magnitude;
            return *this;
        }


        // Get normalized direction to another vector
        Vec3<T> DirectionTo(const Vec3<T>& other) const {
            auto newX = other.x - x;
            auto newY = other.y - y;
            auto newZ = other.z - z;
            auto magnitude = sqrt(newX * newX + newY * newY + newZ * newZ);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            newX /= magnitude;
            newY /= magnitude;
            newZ /= magnitude;
            return Vec3<T>(newX, newY, newZ);
        }

        // Get the euclidean distance to the origin (0, 0, 0)
        T Magnitude() const {
            return sqrt(x * x + y * y + z * z);
        }

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec3<T>& other) const {
            auto dx = other.x - x;
            auto dy = other.y - y;
            auto dz = other.z - z;
            return sqrt(dx * dx + dy * dy + dz * dz);
        }

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec3<T>& other) const {
            auto dx = other.x - x;
            auto dy = other.y - y;
            auto dz = other.z - z;
            return dx * dx + dy * dy + dz * dz;
        }

        // Overload stream insertion for pretty printing
        inline friend std::ostream& operator<<(
            std::ostream& stream, const Vec3<T>& vec) {
            stream << "(" << vec.x << ", "
                << vec.y << ", "
                << vec.z << ")";
            return stream;
        }

        inline T GetX() const { return x; }

        inline T GetY() const { return y; }

        inline T GetZ() const { return z; }

    private:

        T x, y, z;

    };

    template<typename T>
    const Vec3<T> Vec3<T>::Origin(0, 0, 0);

}
