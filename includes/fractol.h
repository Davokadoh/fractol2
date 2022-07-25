/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:27:40 by jleroux           #+#    #+#             */
/*   Updated: 2022/07/25 15:50:06 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 1270
# define WIN_H 720
# define ZOOM 1.1f

# define MANDEL 1
# define JULIA 2
# define BS 3

# include "mlx.h"
# include "libft.h"

typedef struct s_palette
{
	int	size;
	int	colors[5];
}				t_palette;

typedef struct s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

typedef struct s_view
{
	t_cmplx	mouse;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	double	offx;
	double	offy;
	long	max;
}				t_view;

typedef struct s_img
{
	void	*bff;
	char	*ptr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_view		view;
	int			palette;
	int			smooth;
	int			name;
}				t_env;

t_env	init(void);
int		match(char *name);
int		hook_keydown(int key, t_env *env);
int		hook_mousedown(int button, int x, int y, t_env *env);
int		hook_mousemove(int x, int y, t_env *env);
void	reset_view(t_env *env);
void	draw(t_env *env);
void	zoom(int x, int y, t_view *v, double z);

int		burn_iterate(t_cmplx c, t_view *v);
int		julia_iterate(t_cmplx c, t_view *v);
int		mandelbrot_iterate(t_cmplx c, t_view *v);

void	burn_view(t_view *v);
void	julia_view(t_view *v);
void	mandelbrot_view(t_view *v);

#endif
