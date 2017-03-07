/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:46:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/07 13:01:36 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_available(void)
{
	ft_putendl("coucou");
	/*LA IL ME FAUT AFFICHER LES FRACTALS DISPONIBLES*/
}

int		main(int ac, char **av)
{
	t_data *beg;

	if(!(beg = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (ac != 2)
		ft_fractol_available();
	if (ft_strcmp(av[1], "julia") == 0)
		ft_julia(beg);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		ft_mandel(beg);
//	if (ft_strcmp(av[1], "third") == 0)
//		ft_third();
}
