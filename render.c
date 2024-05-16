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

//to rescale from 0..799 to -2...+2
double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z1.y;
	return (result);
}

//real = pow(x, 2) - pow(y, 2);
//imag = 2*x*y
t_complex square_complex(t_complex z)
{
	t_complex	result;

	result.x = pow(x, 2) - pow(y, 2);
	result.y = 2 * z.x * z.y;
	return (result);

}

void	put_pixel(int x, int y, int color, t_fractal *fractal)
{
	int pixels;

	pixels = (y * fractal.line_length) + (x * fractal.bpp / 8);
	*(unsigned int *)(fractal->addr + pixels) = color;
}

//handle pixel
void	img_mandelbrot(t_fractal *fractal, int x, int y)
{
	int i;
	int color;
	//z = z^2 + c
	//z initially is 0
	//c is the actual point
	x = map(x, -2, 2, 0, WIDTH);
	y = map(y, -2, 2, 0, HEIGHT);
	fractal->c.x = x * fractal.zoom + fractal->shift_c.x;
	fractal->c.y = y * fractal.zoom + fractal->shift_c.y;
	i = 0;

	while (i < fractal.definition)
	{
		fractal.z = sum_complex(square_complex(z), c);
		if((pow(fractal->z.x, 2) + pow(fractal->z.y, 2)) > fractal.limit)
		{
			color = map(i, BLACK, WHITE, fractal.definition);
			put_pixel(x, y, &fractal, color);
		}
	}
	put_pixel(x, y, &fractal, NEON_BLUE);
}

/*oid	img_julia(t_fractal *fractal, int x, int y)
{
	//z = z^2 + c

}*/

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
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}