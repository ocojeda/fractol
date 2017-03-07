/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:37:24 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/07 15:07:28 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static int		calculus(float a, float b, t_data *beg)
{
	float aa;
	float bb;
	int n;

	n = 0;
	while (n < MAX_ITER)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + beg->realnb;
		b = bb + beg->imaginarynb;
		if (a + b > 5)
			return (n);
		n++;
	}
	return (n);
}

int		algo_julia(t_screen *fst, int x, t_data *beg)
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
//			if(x < LEN/2 && y < HEIGHT/2)
			a = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
//			else 
//			a = ft_map(x, LEN, beg->minval , beg->maxval );
			if(x >LEN/2)
			b = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);

			n = calculus(a, b, beg);
		//	color = ft_map(n, MAX_ITER, 0x00, 0xFF);
			if (n < (MAX_ITER / 2) / 2)
				color = 0x0;
			else if (n == MAX_ITER )
				color = 0x0;
			else if (n < MAX_ITER / 2)
				color = 0x333333;
			else if (n > MAX_ITER * 0.75)
				color = 0x999999;
			else if (n > MAX_ITER / 2)
				color = 0xdddddd;
			else 
				color = 0x0;
			if(fst->data != NULL)
			((unsigned int *)fst->data)[x + y * LEN] = abs(color);
			x++;
		}
		y++;
	}
	return (1);
}
