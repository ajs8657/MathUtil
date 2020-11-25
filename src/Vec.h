#pragma once

#include <array>
#include <initializer_list>
#include <memory>

namespace Math {

    template <typename T, size_t _Size>
    class Vec {

    public:

        const size_t Size;

        // Empty constructor
        Vec() = delete;

        // Default constructor
        Vec(T values...);

        // Initialization constructor
        Vec(std::initializer_list<T> values);

        // Copy constructor
        Vec(const Vec<T, _Size>& other) = default;

        // Move contstructor
        Vec(Vec&& other) = default;

        // Destructor
        ~Vec() = default;

        // Const Move by vector
        Vec<T, _Size> Move(const Vec<T, _Size>& other) const;

        // Const Move by values
        Vec<T, _Size> Move(T values...) const;

        // Const Scale by vector
        Vec<T, _Size> Scale(const Vec<T, _Size>& other) const;

        // Const Scale by values
        Vec<T, _Size> Scale(T values...) const;

        // Const Scale by one value
        Vec<T, _Size> Scale(T scalar) const;

        // Const Normalize
        Vec<T, _Size> Normalize() const;


        // Mutator Move by vector
        Vec<T, _Size> Move(const Vec<T, _Size>& other);

        // Mutator Move by values
        Vec<T, _Size> Move(T values...);

        // Mutator Scale by vector
        Vec<T, _Size> Scale(const Vec<T, _Size>& other);

        // Mutator Scale by values
        Vec<T, _Size> Scale(T values...);

        // Mutator Scale by one value
        Vec<T, _Size> Scale(T scalar);

        // Mutator Normalize
        Vec<T, _Size> Normalize();


        // Get normalized direction to another vector
        Vec<T, _Size> DirectionTo(const Vec<T, _Size>& other) const;

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec<T, _Size>& other) const;

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec<T, _Size>& other) const;

        inline T operator[] (int index) { return values[index]; }

    private:

        std::array<T, _Size> values;

    };

}
