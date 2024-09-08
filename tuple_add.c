/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:55:04 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 18:10:46 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	return (tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	return (tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

t_tuple	tuple_negate(t_tuple a)
{
	return (tuple(-a.x, -a.y, -a.z, -a.w));
}

t_tuple	tuple_mul(t_tuple a, float b)
{
	return (tuple(a.x * b, a.y * b, a.z * b, a.w * b));
}

t_tuple	tuple_div(t_tuple a, float b)
{
	return (tuple(a.x / b, a.y / b, a.z / b, a.w / b));
}
