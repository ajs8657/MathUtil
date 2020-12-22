#pragma once

#include "Vec3.h"
#include "Exception/MatrixException.h"

namespace Math {

    template<typename T>
    class Mat3 {

    public:

        static const Mat3<T> Identity = Mat3<T>(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1);

        // Empty constructor
        Mat3() = delete;

        // Default constructor
        Mat3(
            T a, T b, T c,
            T d, T e, T f,
            T g, T h, T i) :
            a(a), b(b), c(c),
            d(d), e(e), f(f),
            g(g), h(h), i(i) {}

        // Copy constructor
        Mat3(const Mat3<T>& other) = default;

        // Move contstructor
        Mat3(Mat3&& other) = default;

        // Destructor
        ~Mat3() = default;


        // Const Muliply by other 2x2 Matrix
        Mat3<T> Multiply(const Mat3<T>& other) const {
            return Mat3<T>(
                a * other.a + b * other.d + c * other.g, a * other.b + b * other.e + c * other.h, a * other.c + b * other.f + c * other.i,
                d * other.a + e * other.d + f * other.g, d * other.b + e * other.e + f * other.h, d * other.c + e * other.f + f * other.i,
                g * other.a + h * other.d + i * other.g, g * other.b + h * other.e + i * other.h, g * other.c + h * other.f + i * other.i);
        }

        // Const Multiply by Vec3
        Vec3<T> Multiply(const Vec3<T>& other) const {
            return Vec3<T>(
                a * other.x + b * other.y, c * other.z,
                d * other.x + e * other.y, f * other.z,
                g * other.x + h * other.y, i * other.z);
        }

        // Const Transpose
        Mat3<T> Transpose() const {
            return Mat3<T>(
                a, d, g,
                b, e, h,
                c, f, i);
        }

        // Const Scale
        Mat3<T> Scale(T scalar) const {
            return Mat3<T>(
                a * scalar, b * scalar, c * scalar,
                d * scalar, e * scalar, f * scalar,
                g * scalar, h * scalar, i * scalar);
        }


        // Mutator Muliply by other 2x2 Matrix
        Mat3<T> Multiply(const Mat3<T>& other) {
            auto A = a * other.a + b * other.d + c * other.g;
            auto B = a * other.b + b * other.e + c * other.h;
            c = a * other.c + b * other.f + c * other.i;
            auto D = d * other.a + e * other.d + f * other.g;
            auto E = d * other.b + e * other.e + f * other.h;
            f = d * other.c + e * other.f + f * other.i;
            auto G = g * other.a + h * other.d + i * other.g;
            auto H = g * other.b + h * other.e + i * other.h;
            i = g * other.c + h * other.f + i * other.i;

            a = A;
            b = B;
            d = D;
            e = E;
            g = G;
            h = H;

            return *this;
        }

        // Mutator Transpose
        Mat3<T> Transpose() {
            auto temp = d;
            d = b;
            b = temp;
            temp = g;
            g = c;
            c = temp;
            temp = h;
            h = f;
            f = temp;

            return *this;
        }

        // Mutator Scale
        Mat3<T> Scale(T scalar) {
            a *= scalar;
            b *= scalar;
            c *= scalar;
            d *= scalar;
            e *= scalar;
            f *= scalar;
            g *= scalar;
            h *= scalar;
            i *= scalar;
            return *this;
        }


        // Get the determinant of this matrix
        T Determinant() const {
            return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
        }

        // Get the inverse of this matrix
        Mat3<T> Inverse() const {
            auto det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
            if (det == 0) {
                throw MatrixException(MatrixError::NOT_INVERTIBLE);
            }
            return Mat3<T>(
                (e * i - f * h) / det, (c * h - b * i) / det, (b * f - c * e) / det,
                (f * g - d * i) / det, (a * i - c * g) / det, (c * d - a * f) / det,
                (d * h - e * g) / det, (b * g - a * h) / det, (a * e - b * d) / det);
        }

        // Solve for x in the equation Ax = b
        Vec3<T> Solve(const Vec3<T>& bVec) const {
            auto det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
            if (det == 0) {
                throw MatrixException(MatrixError::NOT_INVERTIBLE);
            }
            auto xOverDet = bVec.x / det;
            auto yOverDet = bVec.y / det;
            auto zOverDet = bVec.z / det;
            return Vec3<T>(
                ((e * i - f * h) * xOverDet) + ((c * h - b * i) * yOverDet) + ((b * f - c * e) * zOverDet),
                ((f * g - d * i) * xOverDet) + ((a * i - c * g) * yOverDet) + ((c * d - a * f) * zOverDet),
                ((d * h - e * g) * xOverDet) + ((b * g - a * h) * yOverDet) + ((a * e - b * d) * zOverDet));
        }

        // Overload stream insertion for pretty printing
        inline friend std::ostream& operator<<(
            std::ostream& stream, const Mat2<T>& mat) {
            stream << "{{" << mat.a << ", " << mat.b << ", " << mat.c << "}, "
                << "{" << mat.d << ", " << mat.e << ", " << mat.f << "}, "
                << "{" << mat.g << ", " << mat.h << ", " << mat.i << "}}";
            return stream;
        }

    private:

        T a, b, c, d, e, f, g, h, i;

    };

}
