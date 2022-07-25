/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:00:51 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 15:51:39 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int	close(int i)
{
	exit(i);
}

static int	ft_error(char *msg)
{
	if (msg != NULL)
		ft_putendl(msg);
	ft_putendl("Choose one of the following:");
	ft_putendl("Mandelbrot, Julia, Burningship");
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (ft_error("Error: Invalid number of arguments"));
	if (match(av[1]) == 0)
		return (ft_error("Error: Invalid name"));
	env = init();
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		return (ft_error("Error: Mlx init fail"));
	env.name = match(av[1]);
	reset_view(&env);
	draw(&env);
	mlx_key_hook(env.win, hook_keydown, &env);
	mlx_hook(env.win, 4, 1L << 2, hook_mousedown, &env);
	mlx_hook(env.win, 6, 1L << 6, hook_mousemove, &env);
	mlx_hook(env.win, 17, 1L << 5, close, 0);
	mlx_loop(env.mlx);
}
