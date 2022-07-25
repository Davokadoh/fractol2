/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:54:27 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 15:49:43 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static t_img	*del_img(t_env *env)
{
	if (env->img)
	{
		if (env->img->bff)
			mlx_destroy_image(env->mlx, env->img->bff);
	}
	return (NULL);
}

static t_img	*new_image(t_env *env)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->bff = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (img->bff == NULL)
		return (del_img(env));
	img->ptr = mlx_get_data_addr(img->bff, &img->bpp, \
			&img->line_size, &img->endian);
	return (img);
}

static void	del_env(t_env *env)
{
	if (env->win != NULL)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img != NULL)
		del_img(env);
}

t_env	init(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, "fract'ol - ");
	env.img = new_image(&env);
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		del_env(&env);
	env.palette = 2;
	return (env);
}
