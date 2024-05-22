/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:11 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/20 19:06:13 by ctacconi         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//useful to color the fractal and to show the depth of the fractal
int	color_mandelbrot(int i)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = (i * 9) % 255;
	g = (i * 2) % 255;
	b = (i * 9) % 255;
	color = create_trgb(0, r, g, b);
	return (color);
}

int	color_julia(int i)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = (i * 2) % 255;
	g = (i * 5) % 255;
	b = (i * 9) % 255;
	color = create_trgb(0, r, g, b);
	return (color);
}
//z = z^2 + c
//z initially is 0
//c is the actual point
void	img_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int i;
	double	tmp_x;
	//int color;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, 1.2, WIDTH) * fractal->zoom) + fractal->shift.x;
	c.y = (map(y, -1.2, 1.2, HEIGHT) * fractal->zoom) + fractal->shift.y;
	i = 0;

	while (i < fractal->definition)
	{
		
		if((z.x * z.x + z.y * z.y) > fractal->limit)
		{
			//color = map(i, BLUE, PURPLE, fractal->definition);
			//color = color_fractal(i);
			my_put_pixel(x, y, color_mandelbrot(i), fractal);
			return ;
		}
		tmp_x = z.x * z.x - z.y * z.y + c.x;
                z.y = 2 * z.x * z.y + c.y;
                z.x = tmp_x;
		i++;
	}
	my_put_pixel(x, y, BLACK, fractal);
}

void	img_julia(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	//t_complex	c;
	int i;
	//int color;
	
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift.x;
	z.y = (map(y, -1.5, 1.5, HEIGHT) * fractal->zoom) + fractal->shift.x;
	i = 0;

	while (i < fractal->definition)
	{
		z = sum_complex(z, fractal->c);
		if(pow(z.x, 2) + pow(z.y, 2) > fractal->limit)
		{
			//color = map(i, BLUE, PURPLE, fractal->definition);
			//color = color_fractal(i);
			my_put_pixel(x, y, color_julia(i), fractal);
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
