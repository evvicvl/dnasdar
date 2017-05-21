#include <iostream>
#include <ctime>

enum GAME_STATE
{
    GAME_TERMINATED = 0,
    GAME_MORE,
    GAME_LESS
};

class Game
{
public:
    Game();
    Game(int maxint);
    GAME_STATE move(int m);
    int tryed;

    ~Game();

private:
    int         _maxint;
    GAME_STATE  _gamestate;
};

Game::Game()            { ; }
Game::Game(int maxint)
{
    if(maxint < 0)
    {
        _maxint = 0;
        return;
    }
    srand(time(NULL));
    _maxint = rand() % maxint;
}
GAME_STATE Game::move(int m)
{
    if(_gamestate == GAME_STATE::GAME_TERMINATED)
        return _gamestate;
    if(m > _maxint)
    {
        _gamestate = GAME_STATE::GAME_MORE;
        tryed++;
        return _gamestate;
    }
    if(m < _maxint)
    {
        _gamestate = GAME_STATE::GAME_LESS;
        tryed++;
        return _gamestate;
    }
    if(m == _maxint)
    {
        _gamestate = GAME_STATE::GAME_TERMINATED;
        tryed;
        return _gamestate;
    }
}
Game::~Game() {}

int main()
{
    int maxint = 0;
    std::cout << "Enter max integer: ";
    std::cin >> maxint;
    Game game(maxint);

    int t = 0;
    GAME_STATE s;
    do
    {
        std::cout << "Make a move: ";
        std::cin >> t;
        s = game.move(t);
        switch(s)
        {
        case GAME_STATE::GAME_MORE:
            std::cout << "More.\n";
            break;
        case GAME_STATE::GAME_LESS:
            std::cout << "Less\n";
            break;
        case GAME_STATE::GAME_TERMINATED:
            std::cout << "Done\n";
            break;
        }
    }
    while(s != GAME_STATE::GAME_TERMINATED);
    std::cout << "With " << game.tryed << " moves.\n";
    return 0;
}
