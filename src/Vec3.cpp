#include "Vec3.h"

#include <cmath>

namespace Math {

    template<typename T>
    const Vec3<T> Vec3<T>::Origin = Vec3<T>(0, 0, 0);

    template<typename T>
    Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    /* Const Methods */

    template<typename T>
    Vec3<T> Vec3<T>::Move(const Vec3<T>& other) const {
        return Vec3<T>(x + other.x, y + other.y, z + other.z);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Move(T dx, T dy, T dz) const {
        return Vec3<T>(x + dx, y + dy, z + dz);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(const Vec3<T>& other) const {
        return Vec3<T>(x * other.x, y * other.y, z * other.z);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(T dx, T dy, T dz) const {
        return Vec3<T>(x * dx, y * dy, z * dz);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(T scalar) const {
        return Vec3<T>(x * scalar, y * scalar, z * scalar);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Normalize() const {
        auto magnitude = sqrt(x * x + y * y + z * z);
        return Vec3<T>(x / magnitude, y / magnitude, z / magnitude);
    }

    /* Mutator Methods */

    template<typename T>
    Vec3<T> Vec3<T>::Move(const Vec3<T>& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Move(T dx, T dy, T dz) {
        x += dx;
        y += dy;
        z += dz;
        return *this;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(const Vec3<T>& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(T dx, T dy, T dz) {
        x *= dx;
        y *= dy;
        z *= dz;
        return *this;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(T scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Normalize() {
        auto magnitude = sqrt(x * x + y * y + z * z);
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
        return *this;
    }

    /* Other Methods */

    template<typename T>
    Vec3<T> Vec3<T>::DirectionTo(const Vec3<T>& other) const {
        auto newX = other.x - x;
        auto newY = other.y - y;
        auto newZ = other.z - z;
        auto magnitude = sqrt(newX * newX + newY * newY + newZ * newZ);
        newX /= magnitude;
        newY /= magnitude;
        newZ /= magnitude;
        return Vec3<T>(newX, newY, newZ);
    }

    template<typename T>
    T Vec3<T>::DistanceTo(const Vec3<T>& other) const {
        auto dx = other.x - x;
        auto dy = other.y - y;
        auto dz = other.z - z;
        auto distSqr = dx * dx + dy * dy + dz * dz;
        return sqrt(distSqr);
    }

    template<typename T>
    T Vec3<T>::DistanceSqrTo(const Vec3<T>& other) const {
        auto dx = other.x - x;
        auto dy = other.y - y;
        auto dz = other.z - z;
        auto distSqr = dx * dx + dy * dy + dz * dz;
        return distSqr;
    }

}
