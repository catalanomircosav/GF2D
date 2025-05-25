#pragma once
#include <spdlog/spdlog.h>
#include <memory>

namespace gf2d::core
{
    enum class LogLevel
    {
        Trace,
        Info,
        Warn,
        Error,
        Critical
    };

    class Logger
    {
    public:
        ~Logger() = default;

        static std::shared_ptr<spdlog::logger>& getLogger();

        static void Log(LogLevel level, const char* message);

    private:
        Logger() = default;

        static std::shared_ptr<spdlog::logger> s_logger;
    };
}
