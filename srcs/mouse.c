/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:12:15 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 15:36:08 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mousedown(int button, int x, int y, t_env *env)
{
	if (button == 4)
	{
		zoom(x, y, &env->view, 1 / ZOOM);
		draw(env);
	}
	else if (button == 5)
	{
		zoom(x, y, &env->view, ZOOM);
		draw(env);
	}
	return (0);
}

static t_cmplx	pixel_to_cmplx(t_view *v, int x, int y)
{
	t_cmplx	c;

	c.r = (((double)x / WIN_W) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	c.i = (((double)y / WIN_H) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (c);
}

int	hook_mousemove(int x, int y, t_env *env)
{
	if (env->name == JULIA)
	{
		if (0 <= x && x < WIN_W && 0 <= y && y < WIN_H)
			env->view.mouse = pixel_to_cmplx(&env->view, x, y);
		draw(env);
	}
	return (0);
}
