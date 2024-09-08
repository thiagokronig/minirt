/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:54 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 16:24:20 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "math.h"

t_tuple	tuple(float x, float y, float z, float w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

bool	tuple_is_point(t_tuple tuple)
{
	return (eq(tuple.w, 1.0f));
}

bool	tuple_is_vector(t_tuple tuple)
{
	return (eq(tuple.w, 0.0f));
}

bool	tuple_equal(t_tuple a, t_tuple b)
{
	return (eq(a.x, b.x) && eq(a.y, b.y) && eq(a.z, b.z) && eq(a.w, b.w));
}
