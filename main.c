/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:46:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/27 14:11:39 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.c"

void	ft_fractol_available(void)
{
	LA IL ME FAUT AFFICHER LES FRACTALS DISPONIBLES
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_fractol_available(void);
	if (ft_strcmp(av[1], "Julia") == 0)
		ft_julia(void);
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ft_mandel(void);
	if (ft_strcmp(av[1], "third") == 0)
		ft_third(void);
	
}
