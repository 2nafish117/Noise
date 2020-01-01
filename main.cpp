#include "qdbmp.h"
#include "vec2.h"
#include <cstdio>
#include <cstdlib>
#include "perlin.h"

int main()
{
    perlin_init(50, 50, 0);
    const u32 image_width = 500;
    const u32 image_height = 500;

    BMP* image = BMP_Create(image_width, image_height, 32);

    for(u32 y = 0;y < image_height;++y)
    {
        for(u32 x = 0;x < image_width;++x)
        {
            float fx = utl::map(x, 0, image_width, 0, perlin_width());
            float fy = utl::map(y, 0, image_height, 0, perlin_height());
            float intensity = utl::map_to01(perlin2(fx, fy), -1 / utl::SQRT_TWO, 1 / utl::SQRT_TWO);
            u8 grey = (u8) (intensity * 255.0);
            BMP_SetPixelRGB(image, x, y, grey, grey, grey);
        }
    }

    BMP_WriteFile(image, "image.bmp");
    BMP_Free(image);
    perlin_cleanup();
    return 0;
}