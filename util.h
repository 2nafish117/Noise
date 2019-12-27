#pragma once

#include <cstdlib>

typedef long long			s64;
typedef unsigned long long	u64;
typedef unsigned long long	b64;

typedef int					s32;
typedef unsigned int    	u32;
typedef unsigned int    	b32;

typedef short           	s16;
typedef unsigned short  	u16;
typedef unsigned short  	b16;

typedef char            	s8;
typedef unsigned char   	u8;
typedef unsigned char   	b8;

typedef float 				f32;
typedef double				f64;

namespace utl
{
    const float INF = ((float)(1e+300 * 1e+300));

	inline float lerpf(float v1, float v2, float t)
	{
		return v1 * (1 - t) + v2 * t;
	}

    inline float randf01()
    {
        return (float) rand() / RAND_MAX;
    }

    inline float randf(float min, float max)
    {
        return randf01() * (max - min) + min;
    }

    inline float isqrtf(float number)
    {
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y  = number;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
        // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

        return y;
    }

    inline float sqrtf(float number)
    {
        return 1 / isqrtf(number);
    }

    inline unsigned int in_range(float t, float min, float max)
    {
        return t >= min && t <= max;
    }

    inline float maxf(float n1, float n2)
    {
        return n1 > n2 ? n1 : n2;
    }

    inline float minf(float n1, float n2)
    {
        return n1 < n2 ? n1 : n2;
    }

    inline float powf(float base, unsigned int rad)
    {
        while(--rad)
            base *= base;

        return base;
    }

    inline float absf(float val)
    {
        return val > 0 ? val : -val;
    }

    float clampf01(float val)
    {
        return (val < 0) ? 0 : (1 < val) ? 1 : val;
    }

} // namespace utl
 