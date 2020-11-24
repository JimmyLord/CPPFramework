
attribute vec2 a_Position;
attribute vec2 a_UVCoord; // Input from VBO in C++.

uniform vec2 u_ObjectPos;
uniform vec2 u_UVScale;
uniform vec2 u_UVOffset;

varying vec2 v_UVCoord; // Output to frag shader.

void main()
{
    // Object Scale.
    // Object tranlation.
    vec2 pos = a_Position;
    pos *= 1;               
    pos += u_ObjectPos;     

    // Apply camera translation.
    pos -= vec2( 5, 5 );

    // Scale into clip space.
    pos /= vec2( 5, 5 );

    v_UVCoord = a_UVCoord * u_UVScale + u_UVOffset;

    gl_Position = vec4( pos, 0, 1 );
}
