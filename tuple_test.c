#include "tuple.h"
#include "math.h"
#include <assert.h>
#include <math.h>
#include <stdlib.h>

void test_tuple_w0_is_point()
{
	t_tuple a = tuple(4.3f, -4.2f, 3.1f, 1.0f);

	assert(a.x == 4.3f);
	assert(a.y == -4.2f);
	assert(a.z == 3.1f);
	assert(a.w == 1.0f);
	assert(!tuple_is_vector(a));
	assert(tuple_is_point(a));
}

void test_tuple_w1_is_vector()
{
	t_tuple a = tuple(4.3f, -4.2f, 3.1f, 0.0f);

	assert(a.x == 4.3f);
	assert(a.y == -4.2f);
	assert(a.z == 3.1f);
	assert(a.w == 0.0f);
	assert(!tuple_is_point(a));
	assert(tuple_is_vector(a));
}

void test_point_is_tuple_with_w1()
{
	assert(tuple_equal(point(4, -4, 3), tuple(4, -4, 3, 1.0f)));
}

void test_vector_is_tuple_with_w0()
{
	assert(tuple_equal(vector(4, -4, 3), tuple(4, -4, 3, 0.0f)));
}

void test_tuple_add()
{
	t_tuple a1 = tuple(3, -2, 5, 1);
	t_tuple a2 = tuple(-2, 3, 1, 0);
	t_tuple a3 = tuple_add(a1, a2);

	assert(tuple_equal(a3, tuple(1, 1, 6, 1)));
}

void test_tuple_sub_two_points()
{
	t_tuple p1 = point(3, 2, 1);
	t_tuple p2 = point(5, 6, 7);
	t_tuple p3 = tuple_sub(p1, p2);

	assert(tuple_equal(p3, vector(-2, -4, -6)));
}

void test_tuple_sub_vector_from_point()
{
	t_tuple p = point(3, 2, 1);
	t_tuple v = vector(5, 6, 7);
	t_tuple p2 = tuple_sub(p, v);

	assert(tuple_equal(p2, point(-2, -4, -6)));
}

void test_tuple_sub_two_vectors()
{
	t_tuple v1 = vector(3, 2, 1);
	t_tuple v2 = vector(5, 6, 7);
	t_tuple v3 = tuple_sub(v1, v2);

	assert(tuple_equal(v3, vector(-2, -4, -6)));
}

void test_tuple_sub_vector_from_zero()
{
	t_tuple	zero = vector(0, 0, 0);
	t_tuple	v = vector(1, -2, 3);
	t_tuple	v2 = tuple_sub(zero, v);

	assert(tuple_equal(v2, vector(-1, 2, -3)));
}

void test_tuple_negate()
{
	t_tuple	a = tuple(1, -2, 3, -4);
	t_tuple	a2 = tuple_negate(a);

	assert(tuple_equal(a2, tuple(-1, 2, -3, 4)));
}

void test_tuple_mul_scalar()
{
	t_tuple	a = tuple(1, -2, 3, -4);
	t_tuple	a2 = tuple_mul(a, 3.5f);

	assert(tuple_equal(a2, tuple(3.5f, -7, 10.5f, -14)));
}

void test_tuple_mul_fraction()
{
	t_tuple a = tuple(1, -2, 3, -4);
	t_tuple a2 = tuple_mul(a, 0.5f);
	assert(tuple_equal(a2, tuple(0.5f, -1, 1.5f, -2)));
}

void test_tuple_div_scalar()
{
	t_tuple a = tuple(1, -2, 3, -4);
	t_tuple a2 = tuple_div(a, 2.0f);
	assert(tuple_equal(a2, tuple(0.5f, -1, 1.5f, -2)));
}

void test_tuple_magnitude_100()
{
	t_tuple v = vector(1, 0, 0);
	assert(eq(tuple_magnitude(v), 1.0f));
}

void test_tuple_magnitude_010()
{
	t_tuple v = vector(0, 1, 0);
	assert(eq(tuple_magnitude(v), 1.0f));
}

void test_tuple_magnitude_001()
{
	t_tuple v = vector(0, 0, 1);
	assert(eq(tuple_magnitude(v), 1.0f));
}

void test_tuple_magnitude_123()
{
	t_tuple v = vector(1, 2, 3);
	assert(eq(tuple_magnitude(v), sqrtf(14.0f)));
}

void test_tuple_magnitude_minus123()
{
	t_tuple v = vector(-1, -2, -3);
	assert(eq(tuple_magnitude(v), sqrtf(14.0f)));
}

void test_tuple_normalize_400()
{
	t_tuple v = vector(4, 0, 0);
	t_tuple norm = tuple_normalize(v);
	assert(tuple_equal(norm, vector(1, 0, 0)));
}

void test_tuple_normalize_123()
{
	t_tuple v = vector(1, 2, 3);
	t_tuple norm = tuple_normalize(v);
	assert(tuple_equal(norm, vector(0.26726f, 0.53452f, 0.80178f)));
}

void test_tuple_normalize_123_magnitude_1()
{
	t_tuple v = vector(1, 2, 3);
	t_tuple norm = tuple_normalize(v);
	assert(eq(tuple_magnitude(norm), 1.0f));
}

void test_tuple_dot_product()
{
	t_tuple a = vector(1, 2, 3);
	t_tuple b = vector(2, 3, 4);
	assert(eq(tuple_dot(a, b), 20.0f));
}

void test_tuple_cross_product()
{
	t_tuple a = vector(1, 2, 3);
	t_tuple b = vector(2, 3, 4);
	t_tuple a_x_b = vector(-1, 2, -1);
	t_tuple b_x_a = vector(1, -2, 1);
	assert(tuple_equal(tuple_cross(a, b), a_x_b));
	assert(tuple_equal(tuple_cross(b, a), b_x_a));
}

int	main(void)
{
	test_tuple_w0_is_point();
	test_tuple_w1_is_vector();
	test_point_is_tuple_with_w1();
	test_vector_is_tuple_with_w0();
	test_tuple_add();
	test_tuple_sub_two_points();
	test_tuple_sub_vector_from_point();
	test_tuple_sub_vector_from_zero();
	test_tuple_negate();
	test_tuple_mul_scalar();
	test_tuple_mul_fraction();
	test_tuple_div_scalar();
	test_tuple_magnitude_001();
	test_tuple_magnitude_010();
	test_tuple_magnitude_100();
	test_tuple_magnitude_123();
	test_tuple_magnitude_minus123();
	test_tuple_normalize_400();
	test_tuple_normalize_123();
	test_tuple_normalize_123_magnitude_1();
	test_tuple_dot_product();
	test_tuple_cross_product();
	return (EXIT_SUCCESS);
}
