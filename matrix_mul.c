/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:00:52 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 23:13:20 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "ft.h"
#include <stdlib.h>

static void	do_matrix_mul(t_matrix *r, const t_matrix *a, const t_matrix *b)
{
	size_t	i;
	size_t	j;
	size_t	k;

	ft_memset(r->data, 0, sizeof(float) * r->rows * r->cols);
	i = 0;
	while (i < r->rows)
	{
		j = 0;
		while (j < r->cols)
		{
			k = 0;
			while (k < a->cols)
			{
				r->data[i * r->cols + j] += a->data[i * a->cols + k]
					* b->data[k * b->cols + j];
				k++;
			}
			j++;
		}
		i++;
	}
}

bool	matrix_mul(t_matrix *r, const t_matrix *a, const t_matrix *b)
{
	if (a->cols != b->rows)
		return (false);
	r->rows = a->rows;
	r->cols = b->cols;
	r->data = (float *) malloc(sizeof(float) * r->rows * r->cols);
	if (r->data == NULL)
		return (false);
	do_matrix_mul(r, a, b);
	return (true);
}
