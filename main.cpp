#include "qdbmp.h"
#include "vec2.h"
#include <cstdio>
#include <cstdlib>
#include "perlin.h"

int main()
{
    perlin_init(20, 20, 0);
    const u32 image_width = 1000;
    const u32 image_height = 1000;

    BMP* image = BMP_Create(image_width, image_height, 32);

    float repeatx = 8;
    float repeaty = 8;

    for(u32 y = 0;y < image_height;++y)
    {
        for(u32 x = 0;x < image_width;++x)
        {
            float fx = utl::map(x, 0, image_width, 0, repeatx * perlin_width());
            float fy = utl::map(y, 0, image_height, 0, repeaty * perlin_height());

            float intensity = perlin2(fx, fy);
            u8 grey = (u8) (intensity * 255.0);
            BMP_SetPixelRGB(image, x, y, grey & 0x0F, grey & 0xF0, grey);
        }
    }

    BMP_WriteFile(image, "image.bmp");
    BMP_Free(image);
    perlin_cleanup();
    return 0;
}