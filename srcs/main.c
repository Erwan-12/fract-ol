/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:11:47 by erwfonta          #+#    #+#             */
/*   Updated: 2024/08/06 14:39:53 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int ac, char **av)
{
	t_fractal	*fractal;
	int			temp_fractal_number;

	temp_fractal_number = check_args(ac, av);
	if (temp_fractal_number == 0)
	{
		ft_putendl_fd(ERROR_MESSAGE_ARGS_USAGE, 1);
		ft_putendl_fd(ERROR_MESSAGE_ARGS_CHOOSE, 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	fractal->fractal_number = temp_fractal_number;
	init_mlx(fractal);
	init_fractal(fractal);
	mlx_mouse_hook(fractal->window, mouse, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw(fractal->fractal_number, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

int	draw(int check_arg, t_fractal *fractal)
{
	if (check_arg == MANDELBROT_ARG_VALUE)
	{
		draw_mandelbrot(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE_X_WINDOW)
	{
		fractal->y = 0;
		while (fractal->y < SIZE_Y_WINDOW)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (0);
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
				* i));
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			return (MANDELBROT_ARG_VALUE);
		else if (ft_strcmp(av[1], "julia") == 0)
			return (JULIA_ARG_VALUE);
		else if (ft_strcmp(av[1], "newton") == 0)
			return (NEWTON_ARG_VALUE);
		else
			return (0);
	}
	return (0);
}
