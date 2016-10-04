#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H



using namespace std;

class GLSLProgram
{
    public:
        GLSLProgram();
        void compileShaders(const string& vertex, const string& fragment);
        void linkShaders();

    protected:

    private:
        GLuint _programID;
};

#endif // GLSLPROGRAM_H
