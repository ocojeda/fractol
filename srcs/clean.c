/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:59:56 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 12:59:59 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		clean(t_screen *fst)
{
	int y;
	int x;
	int color;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			if (fst->data != NULL)
				((unsigned int *)fst->data)[x + y * LEN] = color;
			x++;
		}
		y++;
	}
	return (1);
}
