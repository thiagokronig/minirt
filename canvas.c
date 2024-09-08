/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:29:43 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 20:25:29 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "ft.h"
#include <stdlib.h>

bool	canvas(t_canvas *canvas, unsigned int width, unsigned int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->pixels = (t_color *) malloc(sizeof(t_color) * width * height);
	if (canvas->pixels != NULL)
		ft_memset(canvas->pixels, 0, sizeof(t_color) * width * height);
	return (canvas->pixels != NULL);
}

void	write_pixel(
			t_canvas *canvas,
			unsigned int x,
			unsigned int y,
			t_color color)
{
	canvas->pixels[y * canvas->width + x] = color;
}

t_color	pixel_at(t_canvas *canvas, unsigned int x, unsigned int y)
{
	return (canvas->pixels[y * canvas->width + x]);
}

void	free_canvas(t_canvas *canvas)
{
	free(canvas->pixels);
}
