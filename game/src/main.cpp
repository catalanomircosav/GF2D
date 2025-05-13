#include <Core/Logger.h>

int main(int argc, char** argv)
{
    Core::Logger::init(Core::LogLevel::TRACE);

    Core::Logger::log(Core::LogLevel::TRACE, "This is a trace.");
    Core::Logger::log(Core::LogLevel::DEBUG, "This is a debug.");
    Core::Logger::log(Core::LogLevel::INFO, "This is an info.");
    Core::Logger::log(Core::LogLevel::WARN, "This is a warning.");
    Core::Logger::log(Core::LogLevel::ERROR, "This is an error.");
    Core::Logger::log(Core::LogLevel::CRITICAL, "This is a critical.");
    
    return 0;
}