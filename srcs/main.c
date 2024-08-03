/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:11:47 by erwfonta          #+#    #+#             */
/*   Updated: 2024/08/03 16:57:43 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int ac, char **av)
{
	t_fractal	*fractal;
	int			check_arg;

	check_arg = check_args(ac, av);
	if (check_arg == 0)
	{
		ft_putendl_fd(ERROR_MESSAGE_ARGS_USAGE, 1);
		ft_putendl_fd(ERROR_MESSAGE_ARGS_CHOOSE, 1);
		return (0);
	}
	printf("2");
	fractal = malloc(sizeof(t_fractal));
	printf("3");
	if (!fractal)
	{
		ft_putendl_fd(ERROR_MESSAGE_ALLOCATE, 1);
		return (1);
	}
	printf("4");
	init_fractal(fractal);
	printf("5");
	init_mlx(fractal);
	printf("6");
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw(check_arg, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

int	draw(int check_arg, t_fractal *fractal)
{
	if (check_arg == MANDELBROT_ARG_VALUE)
	{
		draw_mandelbrot(fractal);
	}
	else if (check_arg == JULIA_ARG_VALUE)
	{
		/*
		draw_julia();
		fractal.cx = -0.8;
		fractal.cy = 0.156;
		*/
	}
	else if (check_arg == NEWTON_ARG_VALUE)
	{
		// draw_newton();
	}
	return (0);
}

int	draw_mandelbrot(t_fractal *fractal)
{
	fractal->name = "mandelbrot";
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x <= SIZE_X_WINDOW)
	{
		while (fractal->y <= SIZE_Y_WINDOW)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (0);
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

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
	if (ac == 0)
		return (0);
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
			return (MANDELBROT_ARG_VALUE);
		else if (ft_strncmp(av[1], "julia", 5) == 0)
			return (JULIA_ARG_VALUE);
		else if (ft_strncmp(av[1], "newton", 6) == 0)
			return (NEWTON_ARG_VALUE);
		else
			return (0);
	}
	return (0);
}

// TODO FREE METHODE WHEN FRACTAL ISNT ALLOCATED PROPERLY