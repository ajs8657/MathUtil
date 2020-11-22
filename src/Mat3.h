#pragma once

#include "Vec3.h"

#include <complex>
#include <stdexcept>

namespace Math {

    template<typename T>
    class Mat3 {

    public:

        static const Mat3<T> Identity;

        // Empty constructor
        Mat3() = delete;

        // Default constructor
        Mat3(
            T a, T b, T c,
            T d, T e, T f,
            T g, T h, T i);

        // Copy constructor
        Mat3(const Mat3<T>& other) = default;

        // Move contstructor
        Mat3(Mat3&& other) = default;

        // Destructor
        ~Mat3() = default;


        // Const Muliply by other 2x2 Matrix
        Mat3<T> Multiply(const Mat3<T>& other) const;

        // Const Multiply by Vec3
        Vec3<T> Multiply(const Vec3<T>& other) const;

        // Const Transpose
        Mat3<T> Transpose() const;

        // Const Scale
        Mat3<T> Scale(T scalar) const;


        // Mutator Muliply by other 2x2 Matrix
        Mat3<T> Multiply(const Mat3<T>& other);

        // Mutator Transpose
        Mat3<T> Transpose();

        // Mutator Scale
        Mat3<T> Scale(T scalar);


        // Get the determinant of this matrix
        T Determinant() const;

        // Get the inverse of this matrix
        Mat3<T> Inverse() const;

        // Solve for x in the equation Ax = b
        Vec3<T> Solve(const Vec3<T>& bVec) const;

    private:

        T a, b, c, d, e, f, g, h, i;

    };

    struct MatrixException : public std::runtime_error {

        MatrixException(const std::string& message) : std::runtime_error(message) {}

        MatrixException(const char* message) : std::runtime_error(message) {}

    };

    struct MatrixNotInvertibleException : public MatrixException {
        MatrixNotInvertibleException() : MatrixException("Matrix is not invertible") {}
    };

    struct ImaginarySolutionsException : public MatrixException {
        ImaginarySolutionsException() : MatrixException("Imaginary solutions are not supported yet") {}
    };

}
