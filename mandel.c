/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:53:04 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/03/08 11:15:11 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int             my_key_func(int keycode, t_screen *fst)
{
	ft_putnbr(keycode);
	if(keycode == 53)
		exit (0);
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, LEN, HEIGHT);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	return (1);
}

static int			mouse_hook(int button, int x, int y, t_screen *fst)
{
	float xlen;
	float ylen;
	float temp;
	t_data *beg;

	beg = fst->beg;
	ft_putnbr(button);	
	if(button == 4)
	{
		fst->beg->zoom -= 0.3;
	}
	if(button == 1)
	{
		temp = (-1* (beg->minvalx - beg->maxvalx))/2;
		xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
		ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
		beg->minvalx = (xlen-temp);
		beg->maxvalx = (xlen+temp);
		temp = (-1* (beg->minvaly - beg->maxvaly))/2;
		beg->minvaly = (ylen-temp);
		beg->maxvaly = (ylen+temp);
		fst->beg->zoom += 1;
	}
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, LEN, HEIGHT);
	algo_mandel(fst, 0, beg);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	return (1);
}

void	ft_mandel(t_data *beg)
{
	t_screen fst;

	beg->zoom = 1;
	beg->minvalx = -2;
	beg->maxvalx = 2;
	beg->minvaly = -2;
	beg->maxvaly = 2;
	ft_putendl("je suis la !");
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, LEN, HEIGHT);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);
	fst.beg = beg;
	algo_mandel(&fst, 0, fst.beg);
	fst.win = mlx_new_window(fst.mlx, LEN, HEIGHT, "mathilde aime trop la polla!");
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 4, 3, mouse_hook, &fst);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
}
