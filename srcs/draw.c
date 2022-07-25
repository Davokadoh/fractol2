/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:56:46 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 14:24:05 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		*(unsigned int *)(img->ptr + (y * img->line_size + x * img->bpp / 8)) \
			= color;
}

static int	color(t_env *env, int i)
{
	static int		palettes[3][5] = {\
		{0x333333, 0x995555, 0x888888, 0xAAAAAA, 0xDDDDDD}, \
		{0x331C0D, 0x3C3717, 0x32682B, 0x4F9340, 0xA1D700}, \
		{0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};

	if (i >= env->view.max)
		return (0);
	return (palettes[env->palette][i % 5]);
}

t_cmplx	pixel_to_cmplx(t_view *v, int x, int y)
{
	t_cmplx	c;

	c.r = (((double)x / WIN_W) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	c.i = (((double)y / WIN_H) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (c);
}

static int	iterate(t_env *env, t_cmplx c)
{
	int		i;

	i = 0;
	if (env->name == JULIA)
		i = julia_iterate(c, &env->view);
	else if (env->name == MANDEL)
		i = mandelbrot_iterate(c, &env->view);
	else if (env->name == BS)
		i = burn_iterate(c, &env->view);
	return (i);
}

void	draw(t_env *env)
{
	int		x;
	int		y;
	double	x_factor;
	double	y_factor;
	t_cmplx	c;

	x_factor = env->view.zoom * (env->view.xmax - env->view.xmin) / (WIN_W - 1);
	y_factor = env->view.zoom * (env->view.ymax - env->view.ymin) / (WIN_H - 1);
	y = -1;
	while (++y < WIN_H)
	{
		c.i = ((double)y * y_factor) + env->view.ymin + env->view.offy;
		x = -1;
		while (++x < WIN_W)
		{
			c.r = ((double)x * x_factor) + env->view.xmin + env->view.offx;
			put_pixel(env->img, x, y, color(env, iterate(env, c)));
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->bff, 0, 0);
}
