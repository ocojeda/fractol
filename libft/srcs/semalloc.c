/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:46:35 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 11:46:38 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*semalloc(size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		err_found("malloc failed");
	return (new);
}
