#pragma once

#include "MathException.h"
#include "VectorError.h"

namespace Math {

    class VectorException : public MathException {

    public:

        VectorException(const char* message) : MathException(message) {}

        VectorException(const std::string& message) : MathException(message) {}

        VectorException(const VectorError& error) : MathException(ErrorToString(error)) {}

    private:

        std::string ErrorToString(const VectorError& error) {
            switch (error) {
            case VectorError::NORMALIZE_ZERO:
                return "Cannot normalize the zero vector";
            case VectorError::UNSPECIFIED:
            default:
                return "Unspecified Vector Error";
            }
        }

    };

}
