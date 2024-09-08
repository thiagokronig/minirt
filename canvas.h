/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:29:43 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 19:53:17 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "color.h"
# include <stdbool.h>

typedef struct s_canvas
{
	t_color			*pixels;
	unsigned int	width;
	unsigned int	height;
}	t_canvas;

bool	canvas(t_canvas *canvas, unsigned int width, unsigned int height);
void	write_pixel(
			t_canvas *canvas,
			unsigned int x,
			unsigned int y,
			t_color color);
t_color	pixel_at(t_canvas *canvas, unsigned int x, unsigned int y);
void	free_canvas(t_canvas *canvas);

#endif
