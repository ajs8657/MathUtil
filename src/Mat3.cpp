#include "Mat3.h"

#include "Exception/MatrixException.h"

namespace Math {

    template<typename T>
    const Mat3<T> Mat3<T>::Identity = Mat3<T>(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1);

    template<typename T>
    Mat3<T>::Mat3(
        T a, T b, T c,
        T d, T e, T f,
        T g, T h, T i) :
        a(a), b(b), c(c),
        d(d), e(e), f(f),
        g(g), h(h), i(i) {}

    /* Const Methods */

    template<typename T>
    Mat3<T> Mat3<T>::Multiply(const Mat3<T>& other) const {
        return Mat3<T>(
            a * other.a + b * other.d + c * other.g, a * other.b + b * other.e + c * other.h, a * other.c + b * other.f + c * other.i,
            d * other.a + e * other.d + f * other.g, d * other.b + e * other.e + f * other.h, d * other.c + e * other.f + f * other.i,
            g * other.a + h * other.d + i * other.g, g * other.b + h * other.e + i * other.h, g * other.c + h * other.f + i * other.i);
    }

    template<typename T>
    Vec3<T> Mat3<T>::Multiply(const Vec3<T>& other) const {
        return Vec3<T>(
            a * other.x + b * other.y, c * other.z,
            d * other.x + e * other.y, f * other.z,
            g * other.x + h * other.y, i * other.z);
    }

    template<typename T>
    Mat3<T> Mat3<T>::Transpose() const {
        return Mat3<T>(
            a, d, g,
            b, e, h,
            c, f, i);
    }

    template<typename T>
    Mat3<T> Mat3<T>::Scale(T scalar) const {
        return Mat3<T>(
            a * scalar, b * scalar, c * scalar,
            d * scalar, e * scalar, f * scalar,
            g * scalar, h * scalar, i * scalar);
    }

    /* Mutator Methods */

    template<typename T>
    Mat3<T> Mat3<T>::Multiply(const Mat3<T>& other) {
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

    template<typename T>
    Mat3<T> Mat3<T>::Transpose() {
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

    template<typename T>
    Mat3<T> Mat3<T>::Scale(T scalar) {
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

    /* Other Methods */

    template<typename T>
    T Mat3<T>::Determinant() const {
        return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    }

    template<typename T>
    Mat3<T> Mat3<T>::Inverse() const {
        auto det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
        if (det == 0) {
            throw MatrixException(MatrixError::NOT_INVERTIBLE);
        }
        return Mat3<T>(
            (e * i - f * h) / det, (c * h - b * i) / det, (b * f - c * e) / det,
            (f * g - d * i) / det, (a * i - c * g) / det, (c * d - a * f) / det,
            (d * h - e * g) / det, (b * g - a * h) / det, (a * e - b * d) / det);
    }

    template<typename T>
    Vec3<T> Mat3<T>::Solve(const Vec3<T>& bVec) const {
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

}
