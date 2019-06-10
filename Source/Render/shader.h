#ifndef Shader_H
#define Shader_H

#include "../dependancies.h"

class Shader{
    public:
        bool CompileShaders(int ID);
        bool ReadFile(std::string pFileName, std::string& outFile);
        GLuint* AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType);
        GLuint ShaderProgram;
    private:

};

#endif