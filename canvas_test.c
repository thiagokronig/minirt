#include "canvas.h"
#include "math.h"
#include <assert.h>
#include <stdlib.h>

void test_canvas()
{
    t_canvas c;
    assert(canvas(&c, 10, 20));
    assert(c.width == 10);
    assert(c.height == 20);
    for (unsigned int i = 0; i < 10; i++)
        for (unsigned int j = 0; j < 20; j++)
        {
            t_color color = pixel_at(&c, i, j);
            assert(eq(color.red, 0.0f));
            assert(eq(color.green, 0.0f));
            assert(eq(color.blue, 0.0f));
        }
    free_canvas(&c);
}

void test_write_pixel()
{
    t_canvas c;
    assert(canvas(&c, 10, 20));
    t_color red = color(1, 0, 0);
    write_pixel(&c, 2, 3, red);
    t_color pixel = pixel_at(&c, 2u, 3u);
    assert(eq(pixel.red, red.red));
    assert(eq(pixel.green, red.green));
    assert(eq(pixel.blue, red.blue));
    free_canvas(&c);
}

int main(void)
{
    test_canvas();
    test_write_pixel();
    return (EXIT_SUCCESS);
}