/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:01:31 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 14:25:46 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterate(t_cmplx c, t_view *v)
{
	t_cmplx	z;
	t_cmplx	temp;
	int		i;

	z = c;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return (i);
}

void	mandelbrot_view(t_view *view)
{
	view->xmin = -2.0f;
	view->xmax = 1.0f;
	view->ymin = -1.0f;
	view->ymax = 1.0f;
	view->offx = -0.5f;
}
