#include "color.h"
#include "math.h"
#include <assert.h>
#include <stdlib.h>

void test_color()
{
    t_color c = color(-0.5f, 0.4f, 1.7f);
    assert(eq(c.red, -0.5f));
    assert(eq(c.green, 0.4f));
    assert(eq(c.blue, 1.7f));
}

void test_color_add()
{
    t_color c1 = color(0.9f, 0.6f, 0.75f);
    t_color c2 = color(0.7f, 0.1f, 0.25f);
    t_color c3 = color_add(c1, c2);
    assert(eq(c3.red, 1.6f));
    assert(eq(c3.green, 0.7f));
    assert(eq(c3.blue, 1.0f));
}

void test_color_sub()
{
    t_color c1 = color(0.9f, 0.6f, 0.75f);
    t_color c2 = color(0.7f, 0.1f, 0.25f);
    t_color c3 = color_sub(c1, c2);
    assert(eq(c3.red, 0.2f));
    assert(eq(c3.green, 0.5f));
    assert(eq(c3.blue, 0.5f));
}

void test_color_mul()
{
    t_color c1 = color(0.2f, 0.3f, 0.4f);
    t_color c2 = color_mul(c1, 2.0f);
    assert(eq(c2.red, 0.4f));
    assert(eq(c2.green, 0.6f));
    assert(eq(c2.blue, 0.8f));
}

void test_color_blend()
{
    t_color c1 = color(1.0f, 0.2f, 0.4f);
    t_color c2 = color(0.9f, 1.0f, 0.1f);
    t_color c3 = color_blend(c1, c2);
    assert(eq(c3.red, 0.9f));
    assert(eq(c3.green, 0.2f));
    assert(eq(c3.blue, 0.04f));
}

int main(void)
{
    test_color();
    test_color_add();
    test_color_sub();
    test_color_mul();
    test_color_blend();
    return (EXIT_SUCCESS);
}