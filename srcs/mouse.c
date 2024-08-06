/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:55:53 by erwfonta          #+#    #+#             */
/*   Updated: 2024/08/06 15:06:38 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == SCROLL_UP)
	{
		zoom_in(fractal, x, y);
	}
	else if (button == SCROLL_DOWN)
	{
		zoom_out(fractal, x, y);
	}
	draw(fractal->fractal_number, fractal);
	return (0);
}

void	zoom_in(t_fractal *fractal, int x, int y)
{
	double	zoom_multi;

	zoom_multi = 1.42;
	fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
			/ (fractal->zoom * zoom_multi));
	fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
			/ (fractal->zoom * zoom_multi));
	fractal->zoom *= zoom_multi;
}

void	zoom_out(t_fractal *fractal, int x, int y)
{
	double	zoom_multi;

	zoom_multi = 1.42;
	fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
			/ (fractal->zoom / zoom_multi));
	fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
			/ (fractal->zoom / zoom_multi));
	fractal->zoom /= zoom_multi;
}

// void	zoom(t_fractal *fractal, int x, int y, int zoom)
// {
// 	double	zoom_level;

// 	zoom_level = 1.42;
// 	if (zoom == 1)
// 	{
// 		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
// 				/ (fractal->zoom * zoom_level));
// 		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
// 				/ (fractal->zoom * zoom_level));
// 		fractal->zoom *= zoom_level;
// 	}
// 	else if (zoom == -1)
// 	{
// 		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
// 				/ (fractal->zoom / zoom_level));
// 		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
// 				/ (fractal->zoom / zoom_level));
// 		fractal->zoom /= zoom_level;
// 	}
// 	else
// 		return ;
// }

// int	mouse(int mouse_code, int x, int y, t_fractal *fractal)
// {
// 	if (mouse_code == SCROLL_UP)
// 		zoom(fractal, x, y, 1);
// 	else if (mouse_code == SCROLL_DOWN)
// 		zoom(fractal, x, y, -1);
// 	draw(fractal->fractal_number, fractal);
// 	return (0);
// }