#pragma once

#include "Exception/VectorException.h"
#include <array>
#include <cmath>
#include <initializer_list>
#include <memory>
#include <vector>

namespace Math {

    template <typename T, size_t Size>
    class Vec {

    public:

        // Empty constructor
        Vec() = delete;

        // Default constructor
        Vec(T values...) : Size(Size), values(values) {}

        // Initialization constructor
        Vec(std::initializer_list<T> values) : Size(Size), values(values) {}

        // Copy constructor
        Vec(const Vec<T, Size>& other) = default;

        // Move contstructor
        Vec(Vec&& other) = default;

        // Destructor
        ~Vec() = default;

        // Const Add by vector
        Vec<T, Size> Add(const Vec<T, Size>& other) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] += other[index];
            }
            return Vec<T, Size>(result);
        }

        // Const Add by values
        Vec<T, Size> Add(T values...) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] += values[index];
            }
            return Vec<T, Size>(result);
        }

        // Const Scale by vector
        Vec<T, Size> Scale(const Vec<T, Size>& other) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] *= other[index];
            }
            return Vec<T, Size>(result);
        }

        // Const Scale by values
        Vec<T, Size> Scale(T values...) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] *= values[index];
            }
            return Vec<T, Size>(result);
        }

        // Const Scale by one value
        Vec<T, Size> Scale(T scalar) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] *= scalar;
            }
            return Vec<T, Size>(result);
        }

        // Const Normalize
        Vec<T, Size> Normalize() const {
            T magnitude = T(0);
            for (T value : values) {
                magnitude += value * value;
            }
            magnitude = sqrt(magnitude);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] /= magnitude;
            }
            return Vec<T, Size>(result);
        }


        // Mutator Add by vector
        Vec<T, Size> Add(const Vec<T, Size>& other) {
            for (uint32_t index = 0; index < Size; index++) {
                this->values[index] += other[index];
            }
            return *this;
        }

        // Mutator Add by values
        Vec<T, Size> Add(T values...) {
            for (uint32_t index = 0; index < Size; index++) {
                this->values[index] += values[index];
            }
            return *this;
        }

        // Mutator Scale by vector
        Vec<T, Size> Scale(const Vec<T, Size>& other) {
            for (uint32_t index = 0; index < Size; index++) {
                this->values[index] *= other[index];
            }
            return *this;
        }

        // Mutator Scale by values
        Vec<T, Size> Scale(T values...) {
            for (uint32_t index = 0; index < Size; index++) {
                this->values[index] *= values[index];
            }
            return *this;
        }

        // Mutator Scale by one value
        Vec<T, Size> Scale(T scalar) {
            for (uint32_t index = 0; index < Size; index++) {
                this->values[index] *= scalar;
            }
            return *this;
        }

        // Mutator Normalize
        Vec<T, Size> Normalize() {
            T magnitude = T(0);
            for (T value : values) {
                magnitude += value * value;
            }
            magnitude = sqrt(magnitude);
            if (magnitude == T(0)) {
                throw VectorException(VectorError::NORMALIZE_ZERO);
            }
            for (T& value : values) {
                value /= magnitude;
            }
            return *this;
        }


        // Get normalized direction to another vector
        Vec<T, Size> DirectionTo(const Vec<T, Size>& other) const {
            std::vector<T> result(this->values);
            for (uint32_t index = 0; index < Size; index++) {
                result[index] = other[index] - values[index];
            }
            return Vec<T, Size>(result);
        }

        // Get the euclidean distance to the origin
        T Magnitude() const {
            T magnitude = T(0);
            for (T value : values) {
                magnitude += value * value;
            }
            return sqrt(magnitude);
        }

        // Get the euclidean distance to another vector
        T DistanceTo(const Vec<T, Size>& other) const {
            T distSqr = 0;
            for (uint32_t index = 0; index < Size; index++) {
                T difference = other[index] - values[index];
                distSqr += difference * difference;
            }
            return sqrt(distSqr);
        }

        // Get the euclidean distance squared to another vector
        T DistanceSqrTo(const Vec<T, Size>& other) const {
            T distSqr = 0;
            for (uint32_t index = 0; index < Size; index++) {
                T difference = other[index] - values[index];
                distSqr += difference * difference;
            }
            return distSqr;
        }

        // Overload stream insertion for pretty printing
        inline friend std::ostream& operator<<(
            std::ostream& stream, const Vec<T>& vec) const {
            stream << "(";
            for (uint32_t index = 0; index < Size - 1; index++) {
                stream << values[index] << ", ";
            }
            stream << values[Size - 1] << ")";
            return stream;
        }

        // Similar to Get*() methods, but takes an index instead
        inline T operator[] (int index) const { return values[index]; }

    private:

        std::array<T, Size> values;

    };

}
