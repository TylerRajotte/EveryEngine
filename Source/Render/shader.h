#ifndef Shader_H
#define Shader_H

#include "../dependancies.h"

class Shader{
    public:
        GLuint CompileShaders(int ID);
        bool ReadFile(std::string pFileName, std::string& outFile);
        void AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType);
    private:
};

#endif