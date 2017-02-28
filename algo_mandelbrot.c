/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:48:49 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/28 02:43:25 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

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
		b = bb + cb;
		if (a + b > 4)
			return (n);
		n++;
	}
	return (n);
}

int		algo_mandel(t_screen *fst, int x, t_data *beg)
{
	int y;
	float a;
	float b;
	int color;
	int n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			a = ft_map(x, LEN, beg->minval, beg->maxval);
			b = ft_map(y, HEIGHT, beg->minval, beg->maxval);
			n = calculus(a, b, a, b);
			if (n < 20)
				color = 0;
			else if (n == (MAX_ITER / 2))
				color = 0x00777777;
			else if (n > (MAX_ITER / 2) && n != MAX_ITER)
				color = 0x00bbbbbb;
			else if (n == MAX_ITER)
				color = 0x00000000;
			else 
				color = 0x00ffffff;
			ft_putstr("hello");
			if(fst->data != NULL)
			((unsigned int *)fst->data)[x + y * LEN] = abs(color);
			ft_putstr("bye");
			x++;
		}
		y++;
	}
	return (1);
}
