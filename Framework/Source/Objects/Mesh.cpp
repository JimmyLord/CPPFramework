#include "FrameworkPCH.h"

#include "Mesh.h"
#include "Objects/Camera.h"
#include "Objects/Texture.h"
#include "Utility/ShaderProgram.h"
#include "Utility/Helpers.h"

namespace fw {

Mesh::Mesh()
{
}

Mesh::Mesh(int primitiveType, int numVertices, const VertexFormat* pVertices)
{
    CreateShape( primitiveType, numVertices, pVertices );
}

Mesh::~Mesh()
{
    glDeleteBuffers( 1, &m_VBO );
}

void Mesh::CreateShape(int primitiveType, int numVertices, const VertexFormat* pVertices)
{
    // Delete the old buffer if we had one.
    glDeleteBuffers( 1, &m_VBO );

    // Generate a buffer for our vertex attributes.
    glGenBuffers( 1, &m_VBO ); // m_VBO is a GLuint.

    // Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    m_NumVertices = numVertices;
    m_PrimitiveType = primitiveType;

    // Copy our attribute data into the VBO.
    glBufferData( GL_ARRAY_BUFFER, sizeof(VertexFormat) * m_NumVertices, pVertices, GL_STATIC_DRAW );
}

void Mesh::SetUniform1f(ShaderProgram* pShader, char* name, float value)
{
    int loc = glGetUniformLocation( pShader->GetProgram(), name );
    glUniform1f( loc, value );
}

void Mesh::SetUniform2f(ShaderProgram* pShader, char* name, vec2 value)
{
    int loc = glGetUniformLocation( pShader->GetProgram(), name );
    glUniform2f( loc, value.x, value.y );
}

void Mesh::SetUniform4f(ShaderProgram* pShader, char* name, vec4 value)
{
    int loc = glGetUniformLocation( pShader->GetProgram(), name );
    glUniform4f( loc, value.x, value.y, value.z, value.w );
}

void Mesh::SetUniform1i(ShaderProgram* pShader, char* name, int value)
{
    int loc = glGetUniformLocation( pShader->GetProgram(), name );
    glUniform1i( loc, value );
}

void Mesh::Draw(Camera* pCamera, vec2 pos, ShaderProgram* pShader, Texture* pTexture, vec4 color, vec2 UVScale, vec2 UVOffset)
{
    glUseProgram( pShader->GetProgram() );

    // Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    // Get the attribute variable’s location from the shader.
    GLint loc = glGetAttribLocation( pShader->GetProgram(), "a_Position" );
    if( loc != -1 )
    {
        glEnableVertexAttribArray( loc );
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)0 );
    }

    loc = glGetAttribLocation( pShader->GetProgram(), "a_UVCoord" );
    if( loc != -1 )
    {
        glEnableVertexAttribArray( loc );
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)8 );
    }

    // Setup our uniforms.
    {
        SetUniform1f( pShader, "u_Time", (float)GetSystemTimeSinceGameStart() );
        SetUniform2f( pShader, "u_ObjectPos", pos );
        SetUniform2f( pShader, "u_ObjectScale", vec2(1,1) );
        SetUniform4f( pShader, "u_Color", color );

        SetUniform2f( pShader, "u_UVScale", UVScale );
        SetUniform2f( pShader, "u_UVOffset", UVOffset );

        SetUniform2f( pShader, "u_CameraPosition", pCamera->GetPosition() );
        SetUniform2f( pShader, "u_ProjectionScale", pCamera->GetProjectionScale() );

        if( pTexture != nullptr )
        {
            glActiveTexture( GL_TEXTURE0 );
            glBindTexture( GL_TEXTURE_2D, pTexture->GetHandle() );
            SetUniform1i( pShader, "u_Texture", 0 );
        }
    }

    // Draw the primitive.
    glDrawArrays( m_PrimitiveType, 0, m_NumVertices );
}

} // namespace fw
