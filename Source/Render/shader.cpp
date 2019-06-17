#include "../dependancies.h"
#include "shader.h"

bool Shader::ReadFile(std::string pFileName, std::string &outFile){
    // Opening the file
    std::ifstream f(pFileName.c_str());
    // Error checking variable
    bool ret = false;

    // See if its actually open
    if(f.is_open()){
        std::string line;
        while(getline(f, line)){
            // Appending lines to the outfile
            outFile.append(line);
            outFile.append("\n");
        }
        f.close();
        ret = true;
    } else {
        std::cout << stderr << " " << pFileName << ": Unable to open file" << std::endl;
    }
    return ret;
}

bool Shader::AddShader(GLuint* ShaderProgram, const char* pShaderText, GLenum ShaderType, GLuint* ShaderObject){
    // Parsing and getting the source code ready for being compiled
    *ShaderObject = glCreateShader(ShaderType);

    if(*ShaderObject == 0){
        std::cout << stderr << " Error creating shader type" << ShaderType << std::endl;
        return false;
    }

    const GLchar* p[1];
    p[0] = pShaderText;

    GLint Lengths[1];
    Lengths[0] = strlen(pShaderText);

    // Compiling
    glShaderSource(*ShaderObject, 1, p, Lengths);
    glCompileShader(*ShaderObject);

    // Error checking
    GLint success;
    glGetShaderiv(*ShaderObject, GL_COMPILE_STATUS, &success);
    if(!success){
        GLchar InfoLog[1024];
        glGetShaderInfoLog(*ShaderObject, sizeof(InfoLog), NULL, InfoLog);
        std::cout << stderr << " Error compiling shader type " << ShaderType << InfoLog << std::endl;
        return false; 
    }

    // Attaching shader to the program
    glAttachShader(*ShaderProgram, *ShaderObject);
    return true;
}

bool Shader::CompileShaders(int ID){
    // Inital directory to look for the shaders setup
    std::stringstream IDAsStringStream;
    IDAsStringStream << ID;
    std::string VertexShaderLocation = GameObjectsLocation + IDAsStringStream.str() + "/vertex.vs";
    std::string FractureShaderLocation = GameObjectsLocation + IDAsStringStream.str() + "/fracture.fs";

    // Creating the shader program
    ShaderProgram = glCreateProgram();
    if(ShaderProgram == 0){
        std::cout << stderr << " Error creating shader program" << std::endl;
        return false;
    }

    // Reading the files and error checking
    std::string vs, fs;
    if(!ReadFile(VertexShaderLocation, vs)){
        std::cout << stderr << " Error Reading Vertex Shader File" << std::endl;
        return false;
    }
    if(!ReadFile(FractureShaderLocation, fs)){
        std::cout << " Error Reading Fragment Shader File" << std::endl;
        return false;
    }

    // Adding Shaders and error checking and if thats the case pushing the error up
    if (AddShader(&ShaderProgram, vs.c_str(), GL_VERTEX_SHADER, &VertexShaderObject)){
        std::cout << "Successfully added Vertex shader" << std::endl;
    } else {
        std::cout << stderr << " Error Adding Vertex shader" << std::endl;
        return false;
    }
    if(AddShader(&ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER, &FractureShaderObject)){
        std::cout << "Successfully added Fragment shader" << std::endl;
    } else {
        std::cout << stderr << " Error Adding Fragment shader" << std::endl;
        return false;
    }

    // Compiling and linking and error checking
    GLint Success = 0;
    GLchar ErrorLog[1024] = {0};
    glLinkProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
    if(Success == 0){
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        std::cout << stderr << "Error linking shader program: " << ErrorLog << std::endl;
        return false;
    }

    // Make sure everything is good
    glValidateProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
    if(!Success){
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        std::cout << stderr << "Invalid shader program: " << ErrorLog << std::endl;
        return false;
    }

    // Cleanup
    glDeleteShader(VertexShaderObject);
    glDeleteShader(FractureShaderObject);
    return true;
}