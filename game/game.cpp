#include "game.h"
#include "GameState.h"
#include <windows.h>



using namespace std;


game::game(): _omatila(tila::KAYNNISSA), _omasuunta(suunta::NONE), _dir(0)
{

}

void game::run(){
    GameState state(1);
    state.printWindow();
    while (_omatila == tila::KAYNNISSA){
        cout << "make a move \n";
        cin >> _dir;
        state = state.makeMove(_dir);
        if (_dir == 5){
            break;
        }
        state.printWindow();
        cout << "\n";
        if (state.endGame() != 0){
            _omatila = tila::KIINNI;
            if (state.endGame() == 1){
                cout << "Voitit pelin";
            }
            else{
                cout << "Hävisit pelin";
            }
        }
    }
}

void game::runG(){
    initSystem();
    _sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
    drawGame();
    GameState state(1);
    state.printWindow();
    cout << endl;
    while (_omatila == tila::KAYNNISSA){
        processInput();
        if (_omasuunta != suunta::NONE){
            switch (_omasuunta){
                case suunta::UP:
                    _dir = 1;
                    break;
                case suunta::DOWN:
                    _dir = 2;
                    break;
                case suunta::LEFT:
                    _dir = 3;
                    break;
                case suunta::RIGHT:
                    _dir = 4;
                    break;
            }
            state = state.makeMove(_dir);
            state.printWindow();
            cout << "\n";
            _omasuunta = suunta::NONE;
        }
        if (state.endGame() != 0){
            _omatila = tila::KIINNI;
            if (state.endGame() == 1){
                cout << "Voitit pelin";
            }
            else{
                cout << "Hävisit pelin";
            }
        }
    }
}


void game::initSystem(){        // mainly initializes graphics stuff
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight  = 600;
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("GridWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    if (_window == nullptr){
        fatalError("SDL window could not be created");
    }
    SDL_GLContext glcontext = SDL_GL_CreateContext(_window);
    if (glcontext == nullptr){
        fatalError("SDL_GL context could not be crated");
    }
    GLenum error = glewInit();
    if (error != GLEW_OK){
        fatalError("glew not ok");
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f,1.0f,0.0f,1.0);


}

void game::processInput(){
    SDL_Event act;

    while(SDL_PollEvent(&act)){
        switch(act.type){

            case SDL_QUIT:
                _omatila = tila::KIINNI;
                break;
            case SDL_MOUSEMOTION:
                break;

            case SDL_KEYDOWN:
                switch (act.key.keysym.sym){
                    case SDLK_UP:
                        _omasuunta = suunta::UP;
                        break;
                    case SDLK_DOWN:
                        _omasuunta = suunta::DOWN;
                        break;
                    case SDLK_LEFT:
                        _omasuunta = suunta::LEFT;
                        break;
                    case SDLK_RIGHT:
                        _omasuunta = suunta::RIGHT;
                        break;
                }

                break;


        }

    }
}
void game::fatalError(string errorString){
    cout << errorString << endl;
    cout << "enter any key to quit: ";
    int temp;
    cin >> temp;
    _omatila = tila::KIINNI;
}

void game::drawGame(){
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _sprite.draw();

    SDL_GL_SwapWindow(_window);

}








