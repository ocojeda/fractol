/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:48:49 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/27 17:46:52 by tfaure           ###   ########.fr       */
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

int		algo_mandel()
{
	int x;
	int y;
	int n;
	float a;
	float b;
	int color;

	color = 0x00000000;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < LEN)
		{
			a = map(x, LEN, -2, 2);
			b = map(y, HEIGHT, -2, 2);
			if (calculus(a, b, a, b) == MAX_ITER)
			color = 0x00ffffff;
			((unsigned int *)fst->data)[x + y * len] = color
			x++;
		}
		y++;
	}
}