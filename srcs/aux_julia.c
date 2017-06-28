/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:50:29 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 13:21:18 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_i(t_screen *fst, int x, int y)
{
	float	xlen;
	float	ylen;
	float	temp;
	t_data	*beg;

	beg = fst->beg;
	beg->flag = 2;
	temp = (-1 * (beg->minvalx - beg->maxvalx)) / 2;
	xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
	ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
	beg->minvalx = xlen - temp;
	beg->maxvalx = xlen + temp;
	temp = (-1 * (beg->minvaly - beg->maxvaly)) / 2;
	beg->minvaly = ylen - temp;
	beg->maxvaly = ylen + temp;
	beg->zoom += beg->zoom_rate;
	printf("%f\n", beg->zoom);
	re_fract(fst, fst->beg);
}

void		motion_on_off(t_data *beg)
{
	if (beg->motion == 0)
		beg->motion = 1;
	else if (beg->motion == 1)
		beg->motion = 0;
}
