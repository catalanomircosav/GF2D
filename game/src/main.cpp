#include <Game.h>

int main(int argc, char** argv)
{
    AppParams params;
    params.title = "Game";

    Game game(params);
    
    game.run();
    return 0;
}
