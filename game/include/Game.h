#include <IApplication.h>
#include <iostream>

class Game : public App::IApplication
{
    public:
        Game(const AppParams& params) : IApplication(params) {}

    protected:
        void update() override
        {
            // m_logger->log(Core::LogLevel::DEBUG, "Updating application...");
        }

        void render() override
        {
            // m_logger->log(Core::LogLevel::DEBUG, "Rendering application...");
        }

        void handle(SDL_Event& e) override
        {
            switch(e.type)
            {
                case SDL_EVENT_KEY_DOWN:
                    // m_logger->log(Core::LogLevel::TRACE, SDL_GetKeyName(e.key.key));
                    break;
                
                default:
                    break;
            }
        }
};
