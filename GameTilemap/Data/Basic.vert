attribute vec2 a_Position;
attribute vec2 a_UVCoord; // Input from VBO in C++.

uniform vec2 u_ObjectPos;
uniform vec2 u_ObjectScale;

uniform vec2 u_UVScale;
uniform vec2 u_UVOffset;

uniform vec2 u_CameraPosition;
uniform vec2 u_ProjectionScale;

varying vec2 v_UVCoord; // Output to frag shader.

void main()
{
    // Local space position.
    vec2 pos = a_Position;

    // Apply object scale and translation.
    pos *= u_ObjectScale;
    pos += u_ObjectPos;

    // Apply camera translation.
    pos -= u_CameraPosition;

    // Scale into clip space.
    pos /= u_ProjectionScale;

    gl_Position = vec4( pos, 0, 1 );

    // Transform UV coordinates.
    v_UVCoord = a_UVCoord * u_UVScale + u_UVOffset;
}
