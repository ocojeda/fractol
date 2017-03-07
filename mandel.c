/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:53:04 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/03/07 15:25:13 by tfaure           ###   ########.fr       */
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
int			mouse_hook(int button, int x, int y, t_screen *fst)
{
	float tmp2;
	float tmp;
	float x2;
	float y2;
	t_data *beg;

	beg = fst->beg;
	ft_putnbr(button);	
	if(button == 4)
	{
		fst->beg->zoom -= 0.01;
	}
	if(button == 1)
	{
		y = y / HEIGHT;
		x2 = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
		tmp = beg->minvalx;
		tmp2 = beg->maxvalx;
		beg->minvalx = x2 - ((x2 - tmp) / 1.1);
		beg->maxvalx = x2 + ((tmp2 - x2) / 1.1);
		y2 = ft_map(y, LEN, beg->minvaly, beg->maxvaly);
		tmp = beg->minvaly;
		tmp2 = beg->maxvaly;
		beg->minvaly = y2 - ((y2 - tmp) / 1.1);
		beg->maxvaly = y2 + ((tmp2 - y2) / 1.1);
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
