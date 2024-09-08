/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:56:12 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 19:07:44 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

t_color	color(float red, float green, float blue);
t_color	color_add(t_color a, t_color b);
t_color	color_sub(t_color a, t_color b);
t_color	color_mul(t_color a, float b);
t_color	color_blend(t_color a, t_color b);

#endif
