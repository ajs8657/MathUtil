#pragma once

#include "Vec2.h"
#include "Exception/MatrixException.h"

namespace Math {

    template<typename T>
    class Mat2 {

    public:

        static const Mat2<T> Identity = Mat2<T>(1, 0, 0, 1);

        // Empty constructor
        Mat2() = delete;

        // Constructor
        Mat2(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {}

        // Copy constructor
        Mat2(const Mat2<T>& other) = default;

        // Move contstructor
        Mat2(Mat2&& other) = default;

        // Destructor
        ~Mat2() = default;


        // Const Multiply by other 2x2 Matrix
        Mat2<T> Multiply(const Mat2<T>& other) const {
            return Mat2<T>(
                a * other.a + b * other.c,
                a * other.b + b * other.d,
                c * other.a + d * other.c,
                c * other.b + d * other.d);
        }

        // Const Multiply by Vec2
        Vec2<T> Multiply(const Vec2<T>& other) const {
            return Vec2<T>(
                a * other.x + b * other.y,
                c * other.x + d * other.y);
        }

        // Const Transpose
        Mat2<T> Transpose() const {
            return Mat2<T>(a, c, b, d);
        }

        // Const Scale
        Mat2<T> Scale(T scalar) const {
            return Mat2<T>(
                a * scalar,
                b * scalar,
                c * scalar,
                d * scalar);
        }


        // Mutator Multiply by other 2x2 Matrix
        Mat2<T> Multiply(const Mat2<T>& other) {
            a = a * other.a + b * other.c;
            b = a * other.b + b * other.d;
            c = c * other.a + d * other.c;
            d = c * other.b + d * other.d;
            return *this;
        }

        // Mutator Transpose
        Mat2<T> Transpose() {
            auto temp = b;
            b = c;
            c = temp;
            return *this;
        }

        // Mutator Scale
        Mat2<T> Scale(T scalar) {
            a *= scalar;
            b *= scalar;
            c *= scalar;
            d *= scalar;
            return *this;
        }


        // Get the determinant of this matrix
        T Determinant() const {
            return a * d - b * c;
        }

        // Get the inverse of this matrix
        Mat2<T> Inverse() const {
            auto det = a * d - b * c;
            if (det == 0) {
                throw MatrixException(MatrixError::NOT_INVERTIBLE);
            }
            return Mat2<T>(
                d / det,
                -b / det,
                -c / det,
                a / det);
        }

        // Solve for x in the equation Ax = b
        Vec2<T> Solve(const Vec2<T>& bVec) const {
            auto det = a * d - b * c;
            if (det == 0) {
                throw MatrixException(MatrixError::NOT_INVERTIBLE);
            }
            auto xOverDet = bVec.x / det;
            auto yOverDet = bVec.y / det;
            return Vec2<T>(
                d * xOverDet - b * yOverDet,
                a * yOverDet - c * xOverDet);
        }

    private:

        T a, b, c, d;

    };

}
