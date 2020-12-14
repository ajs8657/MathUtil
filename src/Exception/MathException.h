#pragma once

#include <stdexcept>
#include <string>

namespace Math {

    class MathException : public std::runtime_error {

    public:

        MathException(const char* message) : std::runtime_error(message) {}

        MathException(const std::string& message) : std::runtime_error(message) {}

    };

}
