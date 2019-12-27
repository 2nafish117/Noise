#pragma once

#include <cassert>
#include "util.h"

struct vec2 
{
    union{
        float v[2];
        struct { float x, y; };
    };
};

inline vec2 plus(vec2 v1, vec2 v2);
inline vec2 minus(vec2 v1, vec2 v2);
inline vec2 scalar_prod(vec2 v, float scalar);
inline float dot(vec2 v1, vec2 v2);

inline vec2 unit(vec2 v);
inline void normalize(vec2* v);
inline float len_sqr(vec2 v);
inline float len(vec2 v);

inline vec2 plus(vec2 v1, vec2 v2)
{
    return {
        v1.x + v2.x,
        v1.y + v2.y
    };
}

inline vec2 minus(vec2 v1, vec2 v2)
{
    return {
        v1.x - v2.x,
        v1.y - v2.y
    };
}

inline vec2 scalar_prod(vec2 v, float scalar)
{
    return {
        v.x * scalar,
        v.y * scalar
    };
}

inline float dot(vec2 v1, vec2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

inline vec2 unit(vec2 v)
{
    float l = len(v);
    //assert(l != 0.0f && "vector of 0 len");
    return {
        v.x / l,
        v.y / l
    };
}

inline void normalize(vec2* v)
{
    float l = len(*v);
    //assert(l != 0.0f && "vector of 0 len");

    v->x = v->x / l;
    v->y = v->y / l;
}

inline float len_sqr(vec2 v)
{
    return dot(v, v);
}

inline float len(vec2 v)
{
    return utl::sqrtf(dot(v, v));
}


