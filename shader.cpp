#include "renderer.h"
#include "shader.h"

bool Shader::ReadFile(const char* pFileName, std::string& outFile){
    std::ifstream f(pFileName);
    bool ret = false;
    if(f.is_open()){
        std::string line;
        while(getline(f, line)){
            outFile.append(line);
            outFile.append("\n");
        }
        f.close();
        ret = true;
    } else {
        std::cout << stderr << pFileName << ": Unable to open file" << std::endl;
    }
    return ret;
}

void Shader::AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType){
    GLuint ShaderObj = glCreateShader(ShaderType);

    if(ShaderObj == 0){
        std::cout << stderr << " Error creating shader type" << ShaderType << std::endl;
        exit(0);
    }

    const GLchar* p[1];
    p[0] = pShaderText;

    GLint Lengths[1];
    Lengths[0] = strlen(pShaderText);

    glShaderSource(ShaderObj, 1, p, Lengths);
    glCompileShader(ShaderObj);

    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if(!success){
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);
        std::cout << stderr << " Error compiling shader type " << ShaderType << InfoLog << std::endl; 
    }

    glAttachShader(*ShaderProgram, ShaderObj);
}

void Shader::CompileShaders(){
    GLuint ShaderProgram = glCreateProgram();

    if(ShaderProgram == 0){
        std::cout << stderr << " Error creating shader program" << std::endl;
        exit(0);
    }

    std::string vs, fs;

    if(!ReadFile(pVSFileName, vs)){
        std::cout << " Error Reading File I think... this one is the vs shader file" << std::endl;
        exit(1);
    }

    if(!ReadFile(pFSFileName, fs)){
        std::cout << " Error Reading File I think... this one is the fs shader file" << std::endl;
        exit(1);
    }

    AddShader(&ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);
    AddShader(&ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

    GLint Success = 0;
    GLchar ErrorLog[1024] = {0};
    glLinkProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
    if(Success == 0){
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        std::cout << stderr << "Error linking shader program: " << ErrorLog << std::endl;
        exit(1);
    }

    glValidateProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
    if(!Success){
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        std::cout << stderr << "Invalid shader program: " << ErrorLog << std::endl;
        exit(1);
    }

    glUseProgram(ShaderProgram);
}