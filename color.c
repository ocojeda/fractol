/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:29:25 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/11 17:07:40 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_square(t_env *env, int px, int py, int color)
{
	int x;
	int y;
	
	y = -1;
	while (y < 100)
	{
		x = -1;
		while (x < 100)
		{
			if (fst->data != NULL)
				((unsigned int *)fst->data)[(px + x) + (py + y) * 200] = color;
		}
	}
}

void	ft_init_color(t_screen *fst)
{
	int x;
	int y;

	y = 0;
	fst->win2 = mlx_new_window(fst->mlx, 200, 200, "Chose your color");
	fst->img = mlx_new_image(fst->mlx, 200, 200);
	fst->data = mlx_get_data_addr(fst->img, &bpp, &sizeline, &endian);
	while (y <= 100)
	{
		x = 0;
		while (x <= 100)
		{
			ft_square(fst, x, y, 0x2e9afe);
			x += 100;
		}
		y += 100;
	}
	mlx_put_image_to_window(fst->mlx, fst->win2, fst->img, 0, 0);
}

void	mouse_hook(int button, int x, int y, int n)
{
	if (button == 4)
	{
		if ((x >= 0 && x <= 100) && (y >= 0 && y <= 100))
			ft_color1(n);
		if ((x >= 100 && x <= 200) && (y >= 0 && y <= 100))
			ft_color2(n);
		if ((x >= 0 && x <= 100) && (y >= 100 && y <= 200))
			ft_color3(n);
		if ((x >= 100 && x <= 200) && (y >= 100 && y <= 200))
			ft_color4(n);
	}
}

void	ft_color(int n, t_screen *fst)
{
	mlx_hook(fst->win2, 4, 3, mouse_hook, n);
}
