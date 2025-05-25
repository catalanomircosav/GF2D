#include <core/Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace gf2d::core
{
    std::shared_ptr<spdlog::logger> Logger::s_logger = [] {
        auto logger = spdlog::stdout_color_mt("GF2D");
        
        logger->set_level(spdlog::level::trace);

        return logger;
    }();

    std::shared_ptr<spdlog::logger>& Logger::getLogger()
    {
        return s_logger;
    }

    void Logger::Log(LogLevel level, const char* msg)
    {
        switch(level)
        {
            case LogLevel::Trace:       s_logger->trace(msg); break;
            case LogLevel::Info:        s_logger->info(msg); break;
            case LogLevel::Warn:        s_logger->warn(msg); break;
            case LogLevel::Error:       s_logger->error(msg); break;
            case LogLevel::Critical:    s_logger->critical(msg); break;
        }
    }
}