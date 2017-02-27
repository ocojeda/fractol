/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:41:25 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/27 17:33:18 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_map(float x, float lenght, float min, float max)
{
	float	a;

	return (a = (x / (lenght / (max - min))) - max);
}
