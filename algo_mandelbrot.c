/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:48:49 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/27 19:18:46 by tfaure           ###   ########.fr       */
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
//	ft_putnbr(n);
	return (n);
}

int		algo_mandel(t_screen *fst, int x)
{
	int y;
	float a;
	float b;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			a = ft_map(x, LEN, -1, 1);
			b = ft_map(y, HEIGHT, -1, 1);
//			printf("%f\n",a);
//			printf("%f\n",b);
			color = ft_map(calculus(a, b, a, b), MAX_ITER, 0xFFFF,0xFFFFFF );
			ft_putnbr(color);
			ft_putendl("color : ");
			((unsigned int *)fst->data)[x + y * LEN] = abs(color);
			x++;
		}
		y++;
	}
	return (1);
}
