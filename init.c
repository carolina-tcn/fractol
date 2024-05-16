/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:10 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/16 12:49:19 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	//if (!fractal->mlx_ptr)
	//	error
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
	//if (!fractal->win_ptr)
	//	error
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	//if (!fractal->img_ptr)
	//	error
	fractal->addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp, &fractal->line_length, &fractal->endian);
	//if (!fractal->img_ptr)
	//	error
}

void	data_init(t_fractal *fractal)
{
	fractal->shift_c.x = 0.0;
	fractal->shift_c.y = 0.0;
	fractal->zoom = 1.0;
	fractal->definition = 1060;
	fractal->limit = 4.0;
}

void	init(t_fractal *fractal)
{
	start_mlx(fractal);
	data_init(fractal);
	//event_init();
	mlx_loop(fractal->mlx_ptr);
}