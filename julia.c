/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:56:17 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/10 13:17:23 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int             my_key_func(int keycode, t_screen *fst)
{
	ft_putnbr(keycode);
	ft_putendl("---");
	if(keycode == 53)
	{
		free(fst->beg);
		exit (0);
	}
	re_fract(fst, fst->beg);
	return (1);
}

static int mouse_hook(int button, int x, int y, t_screen *fst)
{
	float xlen;
	float ylen;
	t_data *beg;
	float temp;

	beg = fst->beg;
	ft_putnbr(button);
	if (button == 4)
	{
		beg->zoom -= 1;
	}
	if (button == 5)
	{
		temp = (-1 * (beg->minvalx - beg->maxvalx))/2;
		xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
		ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
		beg->minvalx = xlen - temp;
		beg->maxvalx = xlen + temp;
		temp = (-1 * (beg->minvaly - beg->maxvaly))/2;
		beg->minvaly = ylen - temp;
		beg->maxvaly = ylen + temp;
		beg->zoom += 1;
	}
	re_fract(fst, fst->beg);
	return (1);
}

static int		mouse_motion(int x, int y, t_screen *fst)
{
	fst->beg->realnb = ft_map(x, LEN, -1 , 1);
	fst->beg->imaginarynb = ft_map(y, HEIGHT, -1 , 1);
	re_fract(fst, fst->beg);
	return (1);
}

void			ft_julia(t_data *beg)
{
	t_screen fst;

	beg->tfract = 2;
	beg->zoom = 1;
	beg->minvalx = -2;
	beg->maxvalx = 2;
	beg->minvaly = -2;
	beg->maxvaly = 2;
	beg->realnb = 0;
	beg->imaginarynb = 0;
	ft_putendl("je suis la !");
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, LEN, HEIGHT);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);
	fst.beg = beg;
	algo_julia(&fst, 0, fst.beg);
	fst.win = mlx_new_window(fst.mlx, LEN, HEIGHT, "mathilde aime trop la polla!");
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 6, 3, mouse_motion, &fst);
	mlx_hook(fst.win, 4, 3, mouse_hook, &fst);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
}
