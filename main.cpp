#include "qdbmp.h"
#include "vec2.h"
#include <cstdio>
#include <cstdlib>

#define GRID_WIDTH 100
#define GRID_HEIGHT 50

static vec2 _gradients[GRID_HEIGHT][GRID_WIDTH];
static bool _has_init = false;

static void _generate_gradients()
{
    for(u32 y = 0;y < GRID_HEIGHT;++y)
    {
        for(u32 x = 0;x < GRID_WIDTH;++x)
        {
            _gradients[y][x] = { utl::randf01(), utl::randf01() };
        }
    }
}

void perlin_init()
{
    _generate_gradients();
    _has_init = true;
}

float perlin2(float x, float y)
{
    assert(_has_init && "[perlin2] user has to call perlin_init() before using perlin*");

    // TODO: do perlin stuff
    return 0;

}

inline float perlin2(vec2 v)
{
    return perlin2(v.x, v.y);
}

int main()
{
    perlin_init();
    const u32 image_width = 500;
    const u32 image_height = 250;

    BMP* image = BMP_Create(image_width, image_height, 32);

    printf("%f\n", perlin2(3, 5));

    for(u32 y = 0;y < image_height;++y)
    {
        for(u32 x = 0;x < image_width;++x)
        {
            BMP_SetPixelRGB(image, x, y, rand() & 0xFF, rand() & 0xFF, rand() & 0xFF);
        }
    }

    BMP_WriteFile(image, "image.bmp");
    BMP_Free(image);
    return 0;
}