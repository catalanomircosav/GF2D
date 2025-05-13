#include <Core/Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Core
{
    std::shared_ptr<spdlog::logger> Logger::s_logger;

    void Logger::init(LogLevel l)
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        
        console_sink->set_level(spdlog::level::trace);

        s_logger = std::make_shared<spdlog::logger>("GF2D", console_sink);
        s_logger->set_pattern("[%Y-%m-%d %H:%M] [%^%l%$] %v");
                
        setLogLevel(l);
    }

    void Logger::log(LogLevel l, const std::string& msg)
    {
        if(!s_logger)
            init(LogLevel::INFO);

        switch(l)
        {
            case LogLevel::TRACE:
                s_logger->trace(msg);
                break;
            
            case LogLevel::DEBUG:
                s_logger->debug(msg);
                break;
            
            case LogLevel::INFO:
                s_logger->info(msg);
                break;
            
            case LogLevel::WARN:
                s_logger->warn(msg);
                break;

            case LogLevel::ERROR:
                s_logger->error(msg);
                break;
            
            case LogLevel::CRITICAL:
                s_logger->critical(msg);
                break;
            
            case LogLevel::OFF:
                s_logger->flush();
                break;
        }
    }

    void Logger::setLogLevel(LogLevel l)
    {
        if(s_logger)
            s_logger->set_level(toSpdlogLevel(l));
    }

    spdlog::level::level_enum Logger::toSpdlogLevel(LogLevel l)
    {
        switch (l)
        {
            case LogLevel::TRACE: return spdlog::level::trace;
            case LogLevel::DEBUG: return spdlog::level::debug;
            case LogLevel::INFO: return spdlog::level::info;
            case LogLevel::WARN: return spdlog::level::warn;
            case LogLevel::ERROR: return spdlog::level::err;
            case LogLevel::CRITICAL: return spdlog::level::critical;
            case LogLevel::OFF: return spdlog::level::off;
            
            default: return spdlog::level::info;
        }
    }
}
