#ifndef Shader_H
#define Shader_H

#include "../dependancies.h"

class Shader{
    public:
        void CompileShaders();
        bool ReadFile(const char* pFileName, std::string& outFile);
        void AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType);
    private:
        const char* pVSFileName = "GameObjects/0/vertex.vs";
        const char* pFSFileName = "GameObjects/0/fracture.fs";
};

#endif