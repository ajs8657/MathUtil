#pragma once

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

}
