/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:56:17 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/11 15:33:46 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_julia(t_screen *fst, int button, int x, int y)
{
	float	xlen;
	float	ylen;
	t_data	*beg;
	float	temp;

	beg = fst->beg;
	if (button == 4)
	{
		beg->flag = 2;
		beg->zoom -= 0.5;
		re_fract(fst, fst->beg);
	}
	if (button == 5)
	{
		beg->flag = 2;
		temp = (-1 * (beg->minvalx - beg->maxvalx)) / 2;
		xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
		ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
		beg->minvalx = xlen - temp;
		beg->maxvalx = xlen + temp;
		temp = (-1 * (beg->minvaly - beg->maxvaly)) / 2;
		beg->minvaly = ylen - temp;
		beg->maxvaly = ylen + temp;
		beg->zoom += 0.3;
		re_fract(fst, fst->beg);
	}
	return (1);
}

static int	mouse_hook(int button, int x, int y, t_screen *fst)
{
	t_data *beg;

	beg = fst->beg;
	if (!beg->flag2)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if (beg->flag2 != button)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if (button == 4 && beg->zoom > 0.6)
	{
		beg->flag -= 1;
		if ((beg->flag) == 0)
			return (zoom_julia(fst, button, x, y));
	}
	if (button == 5)
		if ((beg->flag--) == 0)
			return (zoom_julia(fst, button, x, y));
	return (1);
}

static int	mouse_motion(int x, int y, t_screen *fst)
{
	fst->beg->realnb = ft_map(x, LEN, -1, 1);
	fst->beg->imaginarynb = ft_map(y, HEIGHT, -1, 1);
	re_fract(fst, fst->beg);
	return (1);
}

void		ft_julia(t_data *beg)
{
	t_screen fst;

	beg->tfract = 2;
	beg->flag = 3;
	beg->zoom = 1;
	beg->minvalx = -2;
	beg->maxvalx = 2;
	beg->minvaly = -2;
	beg->maxvaly = 2;
	beg->realnb = 0;
	beg->imaginarynb = 0;
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, LEN, HEIGHT);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);
	fst.beg = beg;
	algo_julia(&fst, 0, fst.beg);
	fst.win = mlx_new_window(fst.mlx, LEN, HEIGHT, "Fratol 42");
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 6, 3, mouse_motion, &fst);
	mlx_hook(fst.win, 4, 3, mouse_hook, &fst);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
}
