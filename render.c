/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:30:27 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/16 13:30:29 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_mandelbrot(t_fractal *fractal)
{
	//z = z^2 + c

}

void	img_julia(t_fractal *fractal)
{
	//z = z^2 + c

}

void	render_fractal(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractal->name == "mandelbrot")
				img_mandelbrot(fractal, x, y);
			else if (fractal->name == "julia")
				img_julia(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_inage_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}