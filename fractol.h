/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:40:40 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/28 01:37:38 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h> 
# include <fcntl.h>
# include "libft/libft.h"
# define LEN 1500
# define HEIGHT 1200
# define MAX_ITER 1000

typedef		struct	s_data
{
	int		wich_fractol;
	int		min_val;
	int		max_val;
	int		posx;
	int		posy;
}			t_data;
typedef		struct	s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*data;
}			t_screen;

void	ft_julia(void);
void	ft_third(void);
void	ft_mandel(t_data *begin);
float	ft_map(float x, float lenght, float min, float max);
int 	calculus(float a, float b, float ca, float cb);
int     algo_mandel(t_screen *fst, int x);
#endif
