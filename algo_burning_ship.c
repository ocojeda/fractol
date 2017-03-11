/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:34:26 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/11 15:54:12 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		calculus(float a, float b, float ca, float cb)
{
	float	aa;
	float	bb;
	int		n;

	n = 0;
	while (n < MAX_ITER)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		bb = fabs(bb);
		a = aa + ca;
		b = bb + cb;
		if (a + b > 4)
			return (n);
		n++;
	}
	return (n);
}

int		algo_burning_ship(t_screen *fst, int x, t_data *beg)
{
	int		y;
	float	a;
	float	b;
	int		color;
	int		n;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < LEN)
		{
			a = ft_map(x, LEN, beg->minvalx / beg->zoom, beg->maxvalx / beg->zoom);
			b = ft_map(y, HEIGHT, beg->minvaly / beg->zoom, beg->maxvaly / beg->zoom);
			n = calculus(a, b, a, b);
			if (n < MAX_ITER / 2)
				color = 0;
			else if (n == (MAX_ITER / 2))
				color = 0x00777777;
			else if (n > (MAX_ITER / 2) && n != MAX_ITER)
				color = 0x00bbbbbb;
			else if (n == MAX_ITER)
				color = 0x00000000;
			else
				color = 0x00ffffff;
			if (fst->data != NULL)
				((unsigned int *)fst->data)[x + y * LEN] = abs(color);
		}
	}
	return (1);
}
