/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:46:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/11 12:11:46 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_available(void)
{
	ft_putendl("Mandelbrot");
	ft_putendl("Julia");
}

int		main(int ac, char **av)
{
	t_data *beg;

	if (!(beg = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (ac != 2)
		ft_fractol_available();
	if (ft_strcmp(av[1], "Julia") == 0)
		ft_julia(beg);
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ft_mandel(beg);
	//	if (ft_strcmp(av[1], "third") == 0)
//		ft_third();
}
