/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagokronig <thiagokronig@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:04:28 by thiagokroni       #+#    #+#             */
/*   Updated: 2024/09/08 23:12:35 by thiagokroni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>

typedef struct s_matrix
{
	unsigned int	rows;
	unsigned int	cols;
	float			*data;
}	t_matrix;

bool	matrix(
			t_matrix *m,
			unsigned int rows,
			unsigned int cols,
			const float *data);
void	free_matrix(t_matrix *m);
float	matrix_get(const t_matrix *m, unsigned int row, unsigned int col);
bool	matrix_eq(const t_matrix *a, const t_matrix *b);
bool	matrix_mul(t_matrix *r, const t_matrix *a, const t_matrix *b);

#endif
