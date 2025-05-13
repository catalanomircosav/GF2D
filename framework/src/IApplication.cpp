#include "IApplication.h"
#include <iostream>

namespace App
{
    IApplication::IApplication(const AppParams& params)
        : m_window(nullptr), is_running(false), m_logger(std::make_unique<Core::Logger>())
    {
        m_logger->init(Core::LogLevel::TRACE);
        if (init(params))
            is_running = true;
        else
            m_logger->log(Core::LogLevel::ERROR, "Failed to initialize application.");
    }

    bool IApplication::init(const AppParams& params)
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            m_logger->log(Core::LogLevel::ERROR, "SDL_Init failed: " + std::string(SDL_GetError()));
            return false;
        }

        m_window = SDL_CreateWindow(params.title,
                                    params.width,
                                    params.height,
                                    params.flags);

        if (!m_window)
        {
            m_logger->log(Core::LogLevel::ERROR, "SDL_CreateWindow failed: " + std::string(SDL_GetError()));
            SDL_Quit();
            return false;
        }

        m_logger->log(Core::LogLevel::INFO, "Window created successfully.");
        return true;
    }

    void IApplication::run()
    {
        while (is_running)
        {
            handleEvents();
            update();
            render();
        }

        cleanup();
    }

    void IApplication::handleEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                is_running = false;
            else
                handle(event);
        }
    }

    void IApplication::cleanup()
    {
        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_logger->log(Core::LogLevel::INFO, "Window destroyed.");
        }

        SDL_Quit();
        m_logger->log(Core::LogLevel::INFO, "SDL Quit.");
    }
}
