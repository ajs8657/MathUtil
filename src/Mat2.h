#pragma once

#include "Vec2.h"

#include <complex>
#include <stdexcept>

namespace Math {

    template<typename T>
    class Mat2 {

    public:

        static const Mat2<T> Identity;

        // Empty constructor
        Mat2() = delete;

        // Default constructor
        Mat2(T a, T b, T c, T d);

        // Copy constructor
        Mat2(const Mat2<T>& other) = default;

        // Move contstructor
        Mat2(Mat2&& other) = default;

        // Destructor
        ~Mat2() = default;


        // Const Muliply by other 2x2 Matrix
        Mat2<T> Multiply(const Mat2<T>& other) const;

        // Const Multiply by Vec2
        Vec2<T> Multiply(const Vec2<T>& other) const;

        // Const Transpose
        Mat2<T> Transpose() const;

        // Const Scale
        Mat2<T> Scale(T scalar) const;


        // Mutator Muliply by other 2x2 Matrix
        Mat2<T> Multiply(const Mat2<T>& other);

        // Mutator Transpose
        Mat2<T> Transpose();

        // Mutator Scale
        Mat2<T> Scale(T scalar);


        // Get the determinant of this matrix
        T Determinant() const;

        // Get the inverse of this matrix
        Mat2<T> Inverse() const;

        // Solve for x in the equation Ax = b
        Vec2<T> Solve(const Vec2<T>& bVec) const;

    private:

        T a, b, c, d;

    };

}
