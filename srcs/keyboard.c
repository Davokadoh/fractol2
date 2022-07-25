/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:08:26 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 14:25:33 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>

static int	draw_hooks(int key, t_env *env)
{
	int		doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 2)
		env->palette = key - K_DIGIT_1;
	else if (key == K_NUM_ENTER)
		env->smooth = 1 - env->smooth;
	else
		doot = 1;
	if (!doot)
		draw(env);
	return (doot);
}

static void	move(int key, t_env *env)
{
	double	w;
	double	h;

	w = (env->view.xmax - env->view.xmin) * env->view.zoom;
	h = (env->view.ymax - env->view.ymin) * env->view.zoom;
	if (key == K_UP)
		env->view.offy -= h * 0.05f;
	if (key == K_DOWN)
		env->view.offy += h * 0.05f;
	if (key == K_LEFT)
		env->view.offx -= w * 0.05f;
	if (key == K_RIGHT)
		env->view.offx += w * 0.05f;
}

int	hook_keydown(int key, t_env *env)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_view(env);
	if (key == K_NUM_MULT)
		env->view.max *= 2;
	if (key == K_NUM_DIV)
		if (env->view.max / 2 >= 2)
			env->view.max /= 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_W / 2, WIN_H / 2, &env->view, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_W / 2, WIN_H / 2, &env->view, ZOOM);
	move(key, env);
	if (draw_hooks(key, env))
		draw(env);
	return (0);
}
