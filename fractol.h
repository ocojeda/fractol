/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:40:40 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/07 15:00:37 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h> 
# include <fcntl.h>
# include "libft/libft.h"
# define LEN 1200
# define HEIGHT 1200
# define MAX_ITER 30

typedef		struct	s_data
{
	float				minvalx;
	float				maxvalx;
	float				minvaly;
	float				maxvaly;
	int				posx;
	int				posy;
	float			realnb;
	float			imaginarynb;
	float				zoom;
}					t_data;

typedef		struct	s_screen
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	t_data			*beg;
}					t_screen;

int     clean(t_screen *fst);
void	ft_julia(t_data *begin);
void	ft_third(void);
void	ft_mandel(t_data *begin);
float	ft_map(float x, float lenght, float min, float max);
int     algo_mandel(t_screen *fst, int x, t_data *beg);
int		mouse_hook(int button, int x, int y, t_screen *fst);
int     algo_julia(t_screen *fst, int x, t_data *beg);
#endif
