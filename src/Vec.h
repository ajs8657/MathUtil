#pragma once

#include "Exception/VectorException.h"
#include <array>
#include <cmath>
#include <initializer_list>
#include <memory>
#include <vector>

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

    template<typename T, size_t _Size>
    Vec<T, _Size>::Vec(T values...) : Size(_Size), values(values) {}

    template<typename T, size_t _Size>
    Vec<T, _Size>::Vec(std::initializer_list<T> values) : Size(_Size), values(values) {}

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Move(const Vec<T, _Size>& other) const {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] += other[index];
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Move(T values...) const {
        if (Size != sizeof(values) / sizeof(T)) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] += values[index];
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(const Vec<T, _Size>& other) const {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] *= other[index];
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(T values...) const {
        if (Size != sizeof(values) / sizeof(T)) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] *= values[index];
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(T scalar) const {
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] *= scalar;
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Normalize() const {
        T dist = 0;
        for (T value : values) {
            dist += value * value;
        }
        dist = sqrt(dist);
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] /= dist;
        }
        return Vec<T, _Size>(result);
    }


    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Move(const Vec<T, _Size>& other) {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        for (uint32_t index = 0; index < Size; index++) {
            this->values[index] += other[index];
        }
        return *this;
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Move(T values...) {
        if (Size != sizeof(values) / sizeof(T)) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        for (uint32_t index = 0; index < Size; index++) {
            this->values[index] += values[index];
        }
        return *this;
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(const Vec<T, _Size>& other) {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        for (uint32_t index = 0; index < Size; index++) {
            this->values[index] *= other[index];
        }
        return *this;
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(T values...) {
        if (Size != sizeof(values) / sizeof(T)) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        for (uint32_t index = 0; index < Size; index++) {
            this->values[index] *= values[index];
        }
        return *this;
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Scale(T scalar) {
        for (uint32_t index = 0; index < Size; index++) {
            this->values[index] *= scalar;
        }
        return *this;
    }

    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::Normalize() {
        T dist = 0;
        for (T value : values) {
            dist += value * value;
        }
        dist = sqrt(dist);
        for (T& value : values) {
            value /= dist;
        }
        return *this;
    }


    template<typename T, size_t _Size>
    Vec<T, _Size> Vec<T, _Size>::DirectionTo(const Vec<T, _Size>& other) const {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        std::vector<T> result(this->values);
        for (uint32_t index = 0; index < Size; index++) {
            result[index] = other[index] - values[index];
        }
        return Vec<T, _Size>(result);
    }

    template<typename T, size_t _Size>
    T Vec<T, _Size>::DistanceTo(const Vec<T, _Size>& other) const {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        T distSqr = 0;
        for (uint32_t index = 0; index < Size; index++) {
            T difference = other[index] - values[index];
            distSqr += difference * difference;
        }
        return sqrt(distSqr);
    }

    template<typename T, size_t _Size>
    T Vec<T, _Size>::DistanceSqrTo(const Vec<T, _Size>& other) const {
        if (Size != other.Size) {
            throw VectorException(VectorError::SIZE_MISMATCH);
        }
        T distSqr = 0;
        for (uint32_t index = 0; index < Size; index++) {
            T difference = other[index] - values[index];
            distSqr += difference * difference;
        }
        return distSqr;
    }

}
