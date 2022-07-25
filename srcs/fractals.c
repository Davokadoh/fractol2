/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:56:53 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 15:49:13 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	view_fit(t_view *v)
{
	double	w;
	double	h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIN_W / WIN_H)
	{
		v->ymin = -(w * WIN_H / WIN_W / 2);
		v->ymax = w * WIN_H / WIN_W / 2;
	}
	else
	{
		v->xmin = -(h * WIN_W / WIN_H / 2);
		v->xmax = (h * WIN_W / WIN_H / 2);
	}
}

void	reset_view(t_env *env)
{
	env->view.offx = 0;
	env->view.offy = 0;
	if (env->name == JULIA)
		julia_view(&env->view);
	else if (env->name == BS)
		burn_view(&env->view);
	else if (env->name == MANDEL)
		mandelbrot_view(&env->view);
	view_fit(&env->view);
	env->view.max = 42;
	env->view.zoom = 1.0f;
}

int	match(char *name)
{
	if (!ft_strncmp("Mandelbrot", name, 11))
		return (MANDEL);
	else if (!ft_strncmp("Julia", name, 6))
		return (JULIA);
	else if (!ft_strncmp("Burningship", name, 12))
		return (BS);
	else
		return (0);
}
