#pragma once

#include "MathException.h"

namespace MathUtil {

    enum class VectorError {
        NORMALIZE_ZERO,
        SIZE_MISMATCH,
        UNSPECIFIED
    };

    class VectorException : public MathException {

    public:

        VectorException(const char* message) : MathException(message) {}

        VectorException(const std::string& message) : MathException(message) {}

        VectorException(const VectorError& error) : MathException(ErrorToString(error)) {}

    private:

        char* ErrorToString(const VectorError& error) {
            switch (error) {
            case VectorError::NORMALIZE_ZERO:
                return "Cannot normalize the zero vector";
            case VectorError::SIZE_MISMATCH:
                return "Vector size mismatch";
            case VectorError::UNSPECIFIED:
            default:
                return "Unspecified Vector Error";
            }
        }

    };

}
