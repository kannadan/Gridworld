#ifndef SPRITE_H
#define SPRITE_H
#define GLEW_STATIC
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
        void printID();

    protected:

    private:
        int _x;
        int _y;
        int _width;
        int _height;
        GLuint _vboID;

};

#endif // SPRITE_H
