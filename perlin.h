#pragma once

#include "vec2.h"
#include "unit_transformations.h" 
#include <cstdlib>

static vec2* _gradients = NULL;
static u32 _grid_width  = 0;
static u32 _grid_height = 0;
static bool _has_init   = false;

inline u32 perlin_width()   { return _grid_width;   }
inline u32 perlin_height()  { return _grid_height;  }

static void _generate_gradients()
{
    _gradients = (vec2*) malloc(_grid_width * _grid_height * sizeof(vec2));
    for(u32 y = 0;y < _grid_height;++y)
    {
        for(u32 x = 0;x < _grid_width;++x)
        {
            _gradients[y * _grid_width + x] = { utl::randf(-1, 1), utl::randf(-1, 1) };
            normalize(&_gradients[y * _grid_width + x]);
        }
    }
}

void perlin_init(u32 grid_width = 50, u32 grid_height = 50, u32 seed = 0)
{
    assert(!_has_init && "[perlin_init] perlin_init() called twice without calling perlin_cleanup()");
    srand(seed);
    _grid_width  = grid_width;
    _grid_height = grid_height;
    _generate_gradients();
    _has_init = true;
}

void perlin_cleanup()
{
    free((void*) _gradients);
    _has_init = false;
    _grid_width = _grid_height = 0;
}

static float _displ_dot_gradient(int ix, int iy, float x, float y)
{
    vec2 displ = { x - ix, y - iy };
    return dot(displ, _gradients[iy * _grid_width + ix]);
}

float perlin2(float x, float y)
{
    assert(_has_init && "[perlin2] user has to call perlin_init() before using perlin*");

    x = utl::float_remainder(x, _grid_width);
    u32 x0 = (u32) x;
    u32 x1 = x0 + 1;
    y = utl::float_remainder(y, _grid_height);
    u32 y0 = (u32) y;
    u32 y1 = y0 + 1;

    float sx = x - (float) x0;
    float sy = y - (float) y0;

    float n0 = _displ_dot_gradient(x0, y0, x, y);
    float n1 = _displ_dot_gradient(x1, y0, x, y);
    float n2 = _displ_dot_gradient(x0, y1, x, y);
    float n3 = _displ_dot_gradient(x1, y1, x, y);

    // sx = utl::lerpf(
    //     ut::smooth_start2f(sx),
    //     ut::smooth_stop2f(sx),
    //     sx
    // );

    // sy = utl::lerpf(
    //     ut::smooth_start2f(sy),
    //     ut::smooth_stop2f(sy),
    //     sy
    // );

    sx = ut::smooth_step2f(sx);
    sy = ut::smooth_step2f(sy);

    float ix0 = utl::lerpf(n0, n1, sx);
    float ix1 = utl::lerpf(n2, n3, sx);

    float val = utl::lerpf(ix0, ix1, sy);
    val = utl::map_to01(val, -1 / utl::SQRT_TWO, 1 / utl::SQRT_TWO);
    return val;
}

inline float perlin2(vec2 v)
{
    return perlin2(v.x, v.y);
}
