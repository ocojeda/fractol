/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:48:49 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/27 18:18:26 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calculus(float a, float b, float ca, float cb)
{
	float aa;
	float bb;
	int n;

	n = 0;
	while (n < MAX_ITER)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = aa + cb;
		if (a + b > 16)
			return (0);
		n++;
	}
	return (n);
}

int		algo_mandel(t_screen *fst, int x)
{
	int y;
	float a;
	float b;
	unsigned int color;

	color = 255;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < LEN)
		{
			a = ft_map(x, LEN, -2, 2);
			b = ft_map(y, HEIGHT, -2, 2);
			if (calculus(a, b, a, b) == MAX_ITER)
				color = 0x00ffffff;
			((unsigned int *)fst->data)[x + y * LEN] = color;
			x++;
		}
		y++;
	}
	return (1);
}
