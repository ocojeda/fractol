/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:53:04 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/03/08 17:12:46 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				re_mandel(t_screen *fst, t_data *beg)
{
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, LEN, HEIGHT);
	algo_mandel(fst, 0, beg);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
}
static int			zoom_out_mandel(t_screen *fst, t_data *beg)
{
	fst->beg->zoom -= 0.1;
	beg->flag = 3;
	re_mandel(fst, beg);
	return (1);
}
static int			zoom_in_mandel(t_screen *fst, t_data *beg, int x, int y)
{
		float xlen;
		float ylen;
		float temp;
		temp = (-1* (beg->minvalx - beg->maxvalx))/2;
		xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
		ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
		beg->minvalx = (xlen-temp);
		beg->maxvalx = (xlen+temp);
		temp = (-1* (beg->minvaly - beg->maxvaly))/2;
		beg->minvaly = (ylen-temp);
		beg->maxvaly = (ylen+temp);
		fst->beg->zoom += 0.1;
		re_mandel(fst, fst->beg);
		beg->flag = 3;
		return (1);
}
int             my_key_func(int keycode, t_screen *fst)
{
	ft_putnbr(keycode);
	ft_putendl("---");
	if(keycode == 53)
	{
		free(fst->beg);
		exit (0);
	}
	re_mandel(fst, fst->beg);
	return (1);
}

static int			mouse_hook(int button, int x, int y, t_screen *fst)
{
	t_data *beg;

	beg = fst->beg;
	if(!beg->flag2)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if(beg->flag2 != button)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if(button == 4)
	{
		beg->flag -= 1;
		if(beg->zoom > 0.6)
		{
		if((beg->flag) == 0)
			return (zoom_out_mandel(fst, beg));
		}
	}
	if(button == 5)
		if((beg->flag--) == 0)
			return (zoom_in_mandel(fst, beg, x, y));
	return 1;
}

void	ft_mandel(t_data *beg)
{
	t_screen fst;

	beg->flag = 2;
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
