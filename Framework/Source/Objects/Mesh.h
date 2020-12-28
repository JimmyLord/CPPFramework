#pragma once

#include "Math/Vector.h"

namespace fw {

class Camera;
class ShaderProgram;
class Texture;

struct VertexFormat
{
    float x;
    float y;
    float u;
    float v;

    VertexFormat(float nx, float ny, float nu, float nv)
    {
        x = nx;
        y = ny;
        u = nu;
        v = nv;
    }
};

class Mesh
{
public:
    Mesh();
    Mesh(int primitiveType, int numVertices, const VertexFormat* pVertices);
    virtual ~Mesh();

    void CreateShape(int primitiveType, int numVertices, const VertexFormat* pVertices);

    void SetUniform1f(ShaderProgram* pShader, char* name, float value);
    void SetUniform2f(ShaderProgram* pShader, char* name, vec2 value);
    void SetUniform4f(ShaderProgram* pShader, char* name, vec4 value);
    void SetUniform1i(ShaderProgram* pShader, char* name, int value);

    void Draw(Camera* pCamera, vec2 pos, ShaderProgram* pShader, Texture* pTexture, vec4 color, vec2 UVScale, vec2 UVOffset);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
};

} // namespace fw
