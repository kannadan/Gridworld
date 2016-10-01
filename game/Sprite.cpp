#include "Sprite.h"

Sprite::Sprite()
{
    _vboID = 0;
}

Sprite::~Sprite(){
    if(_vboID != 0){
        glDeleteBuffers(1, &_vboID);
    }
}


void Sprite::init(float x, float y, float width, float height){
    float _x = x;
    float _y = y;
    float _width = width;
    float _height = height;

    if (_vboID == 0){                   //if vertex buffer not initialized, initialize it
        glGenBuffers(1, &_vboID);
    }
    float vertexData[12] = {_x+_width, _y+_height,       // first triangle vertexes
                            _x, _y+_height,
                            _x, _y,

                            _x, _y,                     //second triangle vertexes
                            _x+_width, _y,
                            _x+_width, _y+_height};

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);                  //put the vertex data in to the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


}
void Sprite::draw(){

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);          //position info for gl
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);


    glDisableVertexAttribArray(0);              //cleaning up
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::printID(){
    cout << _vboID;

}
