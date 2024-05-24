/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:51 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/20 19:05:54 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	printf("Memory allocation failure\n");
}

void ft_terminate(t_fractal *fractal)
{
	if (fractal && fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
}

void	start_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		ft_error();
		exit(MLX_ERROR);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!fractal->win_ptr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->win_ptr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
	fractal->addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp, &fractal->line_length, &fractal->endian);
	if (!fractal->addr)
	{
		ft_error();
		ft_terminate(fractal);
		exit(MLX_ERROR);
	}
}

/*void	data_init(t_fractal *fractal)
{
	fractal->shift.x = 0.0;
	fractal->shift.y = 0.0;
	fractal->zoom = 1.0;
	fractal->definition = 250;
	fractal->limit = 4.0;
	fractal->z.x = 0.0;
	fractal->z.y = 0.0;
}*/

void    data_init(t_fractal *fractal)
{
    fractal->shift.x= 0.0;
    fractal->shift.y = 0.0;
    fractal->zoom = 1.0;
    fractal->definition = 150;
    fractal->limit = 4.0;
    fractal->z.x = 0.0;
    fractal->z.y = 0.0;
    fractal->color = PURPLE;
}

void	init(t_fractal *fractal)
{
	start_mlx(fractal);
	//events_init(fractal);
	data_init(fractal);
}
