/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:53:04 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/27 18:14:30 by tfaure           ###   ########.fr       */
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

void	ft_mandel(void)
{
	t_screen fst;

	ft_putendl("je suis la !");
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, LEN, HEIGHT);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);
	algo_mandel(&fst, 0);
	fst.win = mlx_new_window(fst.mlx, LEN, HEIGHT, "mathilde aime trop la polla!");
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
}
