#ifndef Shader_H
#define Shader_H

#include "renderer.h"

class Shader{
    public:
        void CompileShaders();
        bool ReadFile(const char* pFileName, std::string& outFile);
        void AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType);
    private:
        const char* pVSFileName = "GameObjects/TestTriangle/vertex.vs";
        const char* pFSFileName = "GameObjects/TestTriangle/fracture.fs";
};

#endif