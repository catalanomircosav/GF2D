#pragma once
#include <spdlog/spdlog.h>
#include <memory>

namespace Core
{
    enum LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        CRITICAL,
        OFF
    };

    class Logger
    {
        public:    
            static void init(LogLevel l = LogLevel::INFO);
            static void log(LogLevel l, const std::string& msg);
            static void setLogLevel(LogLevel l);
        
        private:
            static spdlog::level::level_enum toSpdlogLevel(LogLevel l);

            static std::shared_ptr<spdlog::logger> s_logger;
    };
}
