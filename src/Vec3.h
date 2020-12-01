#pragma once

namespace Math {

    template <typename T>
    class Vec3 {

    public:

        static const Vec3<T> Origin;

        // Empty constructor
        Vec3() = delete;

        // Default constructor
        Vec3(T x, T y, T z);

        // Copy constructor
        Vec3(const Vec3<T>& other) = default;

        // Move contstructor
        Vec3(Vec3&& other) = default;

        // Destructor
        ~Vec3() = default;

        // Const Move by vector
        Vec3<T> Move(const Vec3<T>& other) const;

        // Const Move by values
        Vec3<T> Move(T dx, T dy, T dz) const;

        // Const Scale by vector
        Vec3<T> Scale(const Vec3<T>& other) const;

        // Const Scale by values
        Vec3<T> Scale(T dx, T dy, T dz) const;

        // Const Scale by one value
        Vec3<T> Scale(T scalar) const;

        // Const Normalize
        Vec3<T> Normalize() const;


        // Mutator Move by vector
        Vec3<T> Move(const Vec3<T>& other);

        // Mutator Move by values
        Vec3<T> Move(T x, T y, T z);

        // Mutator Scale by vector
        Vec3<T> Scale(const Vec3<T>& other);

        // Mutator Scale by values
        Vec3<T> Scale(T x, T y, T z);

        // Mutator Scale by one value
        Vec3<T> Scale(T scalar);

        // Mutator Normalize
        Vec3<T> Normalize();


        // Get normalized direction to another vector
        Vec3<T> DirectionTo(const Vec3<T>& other) const;

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec3<T>& other) const;

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec3<T>& other) const;

        inline T GetX() { return x; }

        inline T GetY() { return y; }

        inline T GetZ() { return z; }

    private:

        T x, y, z;

    };

}
