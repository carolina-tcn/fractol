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

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex result;

	result.x = pow(z.x, 2) - pow(z.y, 2) + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}


void	my_put_pixel(int x, int y, int color, t_fractal *fractal)
{
	char *pixels;

	pixels = fractal->addr + (y * fractal->line_length + x * (fractal->bpp / 8));
	*(unsigned int *)pixels = color;
}

//z = z^2 + c
//z initially is 0
//c is the actual point
void	img_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int i;
	int color;
	
	c.x = (map(x, -2, 1.2, WIDTH) * fractal->zoom) + fractal->shift_c.x;
	c.y = (map(y, -1.2, 1.2, HEIGHT) * fractal->zoom) + fractal->shift_c.x;
	i = 0;

	while (i < fractal->definition)
	{
		z = sum_complex(z, c);
		if(pow(z.x, 2) + pow(z.y, 2) > fractal->limit)
		{
			color = map(i, BLUE, PURPLE, fractal->definition);
			my_put_pixel(x, y, color, fractal);
			return ;
		}
		i++;
	}
	my_put_pixel(x, y, BLACK, fractal);
}

void	img_julia(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	//t_complex	c;
	int i;
	int color;
	
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_c.x;
	z.y = (map(y, -1.5, 1.5, HEIGHT) * fractal->zoom) + fractal->shift_c.x;
	i = 0;

	while (i < fractal->definition)
	{
		z = sum_complex(z, fractal->c);
		if(pow(z.x, 2) + pow(z.y, 2) > fractal->limit)
		{
			color = map(i, BLUE, PURPLE, fractal->definition);
			my_put_pixel(x, y, color, fractal);
			return ;
		}
		i++;
	}
	my_put_pixel(x, y, BLACK, fractal);
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
			if (!ft_strncmp("mandelbrot", fractal->name, 10))
				img_mandelbrot(fractal, x, y); 
			else if (!ft_strncmp("julia", fractal->name, 5))
				img_julia(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}