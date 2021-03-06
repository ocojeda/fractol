/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:53:02 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/26 15:53:05 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculus(float a, float b, t_data *beg)
{
	float	aa;
	float	bb;
	int		n;

	n = 0;
	while (n < MAX_ITER)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + beg->realnb;
		b = bb + beg->imaginarynb;
		if (a + b > 16)
			return (n);
		n++;
	}
	return (n);
}

int			algo_julia(t_screen *fst, int x, t_data *beg)
{
	int		y;
	float	a;
	float	b;
	int		n;
	int		color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < LEN)
		{
			a = ft_map(x, LEN, beg->minvalx / beg->zoom, \
					beg->maxvalx / beg->zoom);
			b = ft_map(y, HEIGHT, beg->minvaly / beg->zoom, \
					beg->maxvaly / beg->zoom);
			n = calculus(a, b, beg);
			color = ft_map(n, MAX_ITER, fst->colortable->curcol << 4, \
					fst->colortable->curcol >> 4);
			if (fst->data != NULL)
				((unsigned int *)fst->data)[x + y * LEN] = abs(color);
		}
	}
	return (1);
}
