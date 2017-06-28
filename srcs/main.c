/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 13:00:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 13:33:51 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	ft_fractol_available(void)
{
	ft_putendl("usage is only one of the following options->");
	ft_putendl("Mandelbrot");
	ft_putendl("Julia");
	ft_putendl("Burning ship");
}

int		main(int ac, char **av)
{
	t_data beg;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			ft_julia(&beg);
		else if (ft_strcmp(av[1], "Mandelbrot") == 0)
			ft_mandel(&beg);
		else if (ft_strcmp(av[1], "Burning ship") == 0)
			ft_burning_ship(&beg);
		else
			ft_fractol_available();
	}
	else
		ft_fractol_available();
	return (0);
}
