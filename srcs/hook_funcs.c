/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:54:11 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 14:36:24 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			my_key_func(int keycode, t_screen *fst)
{
	printf("%d\n",keycode);
	if (keycode == 69)
	{
		fst->beg->zoom_rate += 0.1;
		printf("%f\n",fst->beg->zoom_rate);
	}
	if (keycode == 78)
	{
		if(fst->beg->zoom_rate >= 0.1)
			fst->beg->zoom_rate = 0.1;
	}
	if (keycode == 87)
	{
		if (fst->beg->tfract == 2)
			reset_julia(fst->beg);
		if (fst->beg->tfract == 1)
			reset_mandel(fst->beg);
		if (fst->beg->tfract == 3)
			reset_burning(fst->beg);
	}
	if (keycode == 53)
		exit(0);
	re_fract(fst, fst->beg);
	return (1);
}

void		re_fract(t_screen *fst, t_data *beg)
{
	if (beg->tfract == 1)
		algo_mandel(fst, 0, beg);
	else if (beg->tfract == 2)
		algo_julia(fst, 0, beg);
	else if (beg->tfract == 3)
		algo_burning_ship(fst, 0, beg);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
}
