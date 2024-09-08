/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:15:43 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 18:31:29 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <math.h>

float	tuple_dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_tuple	tuple_cross(t_tuple a, t_tuple b)
{
	return (vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

float	tuple_magnitude(t_tuple a)
{
	return (sqrtf(tuple_dot(a, a)));
}

t_tuple	tuple_normalize(t_tuple a)
{
	return (tuple_div(a, tuple_magnitude(a)));
}
