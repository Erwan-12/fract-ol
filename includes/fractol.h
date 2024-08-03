/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:28:44 by erwfonta          #+#    #+#             */
/*   Updated: 2024/08/03 14:42:49 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// error message

# define ERROR_MESSAGE_ARGS_USAGE "Right Way to use : ./fractal <fractal_name>"
# define ERROR_MESSAGE_ARGS_CHOOSE "Available : mandelbrot, julia, newton"
# define ERROR_MESSAGE_ALLOCATE "failed to allocate memory for fractal"

# define SIZE_X_WINDOW 700
# define SIZE_Y_WINDOW 700
# define MANDELBROT_ARG_VALUE 1
# define JULIA_ARG_VALUE 2
# define NEWTON_ARG_VALUE 3

// TODO replace by libft -> include the submodule

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putendl_fd(char *str, int fd);

// init
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

int			check_args(int ac, char **av);

// utils
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
int			exit_fractal(t_fractal *fractal);

// draw
int			draw(int check_arg, t_fractal *fractal);
int			draw_mandelbrot(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal);

#endif
