/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:53:04 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/28 04:11:27 by ocojeda-         ###   ########.fr       */
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
	if(button == 1)
	{	
	ft_putnbr(button);
	ft_putstr("-");
	ft_putnbr(x);
	ft_putstr("-");
	ft_putnbr(y);
	ft_putendl("-");
	mlx_destroy_image(fst->mlx, fst->img);
	ft_putendl("-");
	ft_putendl("mandel");
	fst->img = mlx_new_image(fst->mlx, LEN, HEIGHT);
	free(fst->data);
	ft_putendl("mandel");
	fst->data = mlx_get_data_addr(fst->img, fst->bpp, fst->sizeline, 
			fst->endian);
	ft_putendl("mandel");
	algo_mandel(&fst, 0, fst->beg);
	ft_putendl("newimage");
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	ft_putendl("put");
	}
	return (1);
}
void	ft_mandel(t_data *beg)
{
	t_screen fst;

	beg->minval = -2;
	beg->maxval = 2;
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
