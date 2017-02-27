/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:40:40 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/27 16:50:59 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h> 
# include <fcntl>
# include "libft/libft.h"
# define LEN 1500;
# define HIGHT 1200;

typedef		struct	s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sizeline;
	int		len;
	int		hight;
	int		endian;
	char	*data;
}			t_screen;

#endif
