/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:56:33 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/21 22:56:35 by ctacconi         ###   ########.fr       */
=======
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:02:04 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/22 13:02:21 by carolinat        ###   ########.fr       */
>>>>>>> a2acba6be30f829c87d0d2d34dab32cd348d18d4
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	manage_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		exit(0);
	}
	else if (keycode == ARROW_LEFT)
<<<<<<< HEAD
		fractal->shift_c.x -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_RIGHT)
		fractal->shift_c.x += 0.5 * fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->shift_c.y -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_DOWN)
		fractal->shift_c.y += 0.5 * fractal->zoom;
=======
		fractal->shift.x -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_RIGHT)
		fractal->shift.x += 0.5 * fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->shift.y -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_DOWN)
		fractal->shift.y += 0.5 * fractal->zoom;
>>>>>>> a2acba6be30f829c87d0d2d34dab32cd348d18d4
	else if (keycode == SHIFT)
		fractal->definition += 10;
	else if (keycode == TAB)
		fractal->definition -= 10;
	render_fractal(fractal);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == SCROLLDOWN)
	{
		fractal->zoom *= 0.8;
	}
	else if (keycode == SCROLLUP)
	{
		fractal->zoom *= 1.2;
	}
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	render_fractal(fractal);
	return (0);
}
<<<<<<< HEAD
 
=======

>>>>>>> a2acba6be30f829c87d0d2d34dab32cd348d18d4
int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
	return (0);
<<<<<<< HEAD
}
=======
}

>>>>>>> a2acba6be30f829c87d0d2d34dab32cd348d18d4
