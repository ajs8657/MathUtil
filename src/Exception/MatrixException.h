#pragma once

#include "MathException.h"

namespace MathUtil {

    enum class MatrixError {
        NOT_INVERTIBLE,
        UNSPECIFIED
    };

    class MatrixException : public MathException {

    public:

        MatrixException(const char* message) : MathException(message) {}

        MatrixException(const std::string& message) : MathException(message) {}

        MatrixException(const MatrixError& error) : MathException(ErrorToString(error)) {}

    private:

        char* ErrorToString(const MatrixError& error) {

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
