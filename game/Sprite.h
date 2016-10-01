#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <windows.h>
#include "glew.h"
#include "SDL.h"


using namespace std;

class Sprite
{
    public:
        Sprite();
        ~Sprite();

        void init(float x, float y, float width, float height);
        void draw();

    protected:

    private:
        int _x;
        int _y;
        int _width;
        int _height;
        GLuint _vboID;

};

#endif // SPRITE_H
