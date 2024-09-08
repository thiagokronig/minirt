/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:19:00 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 18:01:29 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	point(float x, float y, float z)
{
	return (tuple(x, y, z, 1.0f));
}

t_tuple	vector(float x, float y, float z)
{
	return (tuple(x, y, z, 0.0f));
}
