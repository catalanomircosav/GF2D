#include <core/Logger.h>

int main()
{
    using gf2d::core::Logger;
    using gf2d::core::LogLevel;

    Logger::Log(LogLevel::Info, "Hello from GF2D!");
    Logger::getLogger()->warn("Direct access to spdlog also works!");
}