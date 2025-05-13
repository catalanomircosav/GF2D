#pragma once
#include <memory>
#include <SDL3/SDL.h>

#include <Core/Logger.h>

struct AppParams
{
    const char* title = "GF2D";

    int width = 1280;
    int height = 720;

    SDL_WindowFlags flags = SDL_WINDOW_HIGH_PIXEL_DENSITY;
};

namespace App
{
    class IApplication
    {
        public:
            void run();

        protected:
            IApplication(const AppParams&);

            virtual void update() = 0;
            virtual void render() = 0;
            virtual void handle(SDL_Event&) = 0;

            inline SDL_Window* getNativeWindow() const { return m_window; }
            // inline SDL_Renderer* getNativeRenderer() const { return m_renderer; }

            void setNativeWindow(SDL_Window* window) { m_window = window; }

            std::unique_ptr<Core::Logger> m_logger;

        private:
            bool init(const AppParams&);
            void cleanup();

            void handleEvents();

            SDL_Window* m_window;
            // SDL_Renderer* m_renderer;


            bool is_running;
    };
}