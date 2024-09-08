/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:59:15 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 19:09:08 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "math.h"

t_color	color(float red, float green, float blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

t_color	color_add(t_color a, t_color b)
{
	return (color(a.red + b.red, a.green + b.green, a.blue + b.blue));
}

t_color	color_sub(t_color a, t_color b)
{
	return (color(a.red - b.red, a.green - b.green, a.blue - b.blue));
}

t_color	color_mul(t_color a, float b)
{
	return (color(a.red * b, a.green * b, a.blue * b));
}

t_color	color_blend(t_color a, t_color b)
{
	return (color(a.red * b.red, a.green * b.green, a.blue * b.blue));
}
