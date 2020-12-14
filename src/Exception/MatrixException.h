#pragma once

#include "MathException.h"
#include "MatrixError.h"

namespace Math {

    class MatrixException : public MathException {

    public:


        MatrixException(const char* message) : MathException(message) {}

        MatrixException(const std::string& message) : MathException(message) {}

        MatrixException(const MatrixError& error) : MathException(ErrorToString(error)) {}

    private:

        std::string ErrorToString(const MatrixError& error) {

            switch (error) {
            case MatrixError::NOT_INVERTIBLE:
                return "Matrix is not invertible";
            case MatrixError::UNSPECIFIED:
            default:
                return "Unspecified Matrix Error";
            }
        }

    };

}
