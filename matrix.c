/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:07:10 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 22:58:14 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "ft.h"
#include "math.h"
#include <stdlib.h>

bool	matrix(
			t_matrix *m,
			unsigned int rows,
			unsigned int cols,
			const float *data)
{
	m->data = (float *) malloc(sizeof(float) * rows * cols);
	if (m->data == NULL)
		return (false);
	m->rows = rows;
	m->cols = cols;
	ft_memcpy(m->data, data, sizeof(float) * rows * cols);
	return (true);
}

void	free_matrix(t_matrix *m)
{
	free(m->data);
}

float	matrix_get(const t_matrix *m, unsigned int row, unsigned int col)
{
	return (m->data[row * m->cols + col]);
}

bool	matrix_eq(const t_matrix *a, const t_matrix *b)
{
	size_t	i;

	if (a->rows != b->rows || a->cols != b->cols)
		return (false);
	i = 0;
	while (i < a->rows * a->cols)
	{
		if (!eq(a->data[i], b->data[i]))
			return (false);
		i++;
	}
	return (true);
}
