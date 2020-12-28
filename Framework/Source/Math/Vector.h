#pragma once

namespace fw {

inline bool fequal(float a, float b, float epsilon = 0.00001f)
{
    return( fabsf(a-b) < epsilon );
}

class vec2
{
public:
    vec2() { x = 0; y = 0; }
    vec2(float nx, float ny) { x = nx; y = ny; }

    void Set(float nx, float ny) { x = nx; y = ny; }

    vec2 operator+(float o) const { return vec2( x+o, y+o ); }
    vec2 operator-(float o) const { return vec2( x-o, y-o ); }
    vec2 operator*(float o) const { return vec2( x*o, y*o ); }
    vec2 operator/(float o) const { return vec2( x/o, y/o ); }

    vec2 operator+(const vec2& o) const { return vec2( x+o.x, y+o.y ); }
    vec2 operator-(const vec2& o) const { return vec2( x-o.x, y-o.y ); }
    vec2 operator*(const vec2& o) const { return vec2( x*o.x, y*o.y ); }
    vec2 operator/(const vec2& o) const { return vec2( x/o.x, y/o.y ); }

    vec2& operator+=(float o) { x += o; y += o; return *this; }
    vec2& operator-=(float o) { x -= o; y -= o; return *this; }
    vec2& operator*=(float o) { x *= o; y *= o; return *this; }
    vec2& operator/=(float o) { x /= o; y /= o; return *this; }

    vec2& operator+=(const vec2& o) { x += o.x; y += o.y; return *this; }
    vec2& operator-=(const vec2& o) { x -= o.x; y -= o.y; return *this; }
    vec2& operator*=(const vec2& o) { x *= o.x; y *= o.y; return *this; }
    vec2& operator/=(const vec2& o) { x /= o.x; y /= o.y; return *this; }

    bool operator==(const vec2& o) const { return( fequal( x, o.x ) && fequal( y, o.y ) ); }
    bool operator!=(const vec2& o) const { return( !fequal( x, o.x ) || !fequal( y, o.y ) ); }

    vec2 operator-() const { return vec2( -x, -y ); }

    float GetLength() const { return sqrtf( x*x + y*y ); }
    float DistanceFrom(const vec2& o) const { return (*this - o).GetLength(); }

    void Normalize() { float mag = GetLength(); if( mag == 0 ) return; x /= mag; y /= mag; }
    vec2 GetNormalized() const { float mag = GetLength(); return vec2( x/mag, y/mag ); }

    float Dot(const vec2& o) const { return (x*o.x + y*o.y); }

public:
    float x;
    float y;
};

inline vec2 operator*(float scalar, const vec2& vector) { return vec2( scalar*vector.x, scalar*vector.y ); }

class vec4
{
public:
    vec4() { x = 0; y = 0; z = 0; w = 0; }
    vec4(float nx, float ny, float nz, float nw) { x = nx; y = ny; z = nz; w = nw; }

    static const vec4 Red()      { return vec4( 1.0f, 0.0f, 0.0f, 1.0f ); }
    static const vec4 Green()    { return vec4( 0.0f, 1.0f, 0.0f, 1.0f ); }
    static const vec4 Yellow()   { return vec4( 1.0f, 1.0f, 0.0f, 1.0f ); }
    static const vec4 Blue()     { return vec4( 0.0f, 0.0f, 1.0f, 1.0f ); }
    static const vec4 DarkBlue() { return vec4( 0.0f, 0.0f, 0.3f, 1.0f ); }
    static const vec4 White()    { return vec4( 1.0f, 1.0f, 1.0f, 1.0f ); }
    static const vec4 Black()    { return vec4( 0.0f, 0.0f, 0.0f, 1.0f ); }

public:
    union
    {
        float x;
        float r;
    };
    union
    {
        float y;
        float g;
    };
    union
    {
        float z;
        float b;
    };
    union
    {
        float w;
        float a;
    };
};

} // namespace fw
