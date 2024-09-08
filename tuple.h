/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:39:49 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 18:31:03 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdbool.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	tuple(float x, float y, float z, float w);
bool	tuple_is_point(t_tuple tuple);
bool	tuple_is_vector(t_tuple tuple);
bool	tuple_equal(t_tuple a, t_tuple b);
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
t_tuple	tuple_negate(t_tuple a);
t_tuple	tuple_mul(t_tuple a, float b);
t_tuple	tuple_div(t_tuple a, float b);
float	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);
float	tuple_magnitude(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);

#endif
