/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:42 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/24 15:16:54 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int manage_key(int keycode, t_fractal *fractal)
{
    double i;
    i = 0.1;
    if (keycode == ESC)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
        exit(0);
    }
   	if (keycode == ARROW_LEFT)
        fractal->shift.x -= 0.5 * fractal->zoom;
    if (keycode == ARROW_RIGHT)
        fractal->shift.x += 0.5 * fractal->zoom;
    else if (keycode == ARROW_UP)
        fractal->shift.y -= 0.5 * fractal->zoom;
    else if (keycode == ARROW_DOWN)
        fractal->shift.y += 0.5 * fractal->zoom;
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

// int mouse_hook(int keycode, int x, int y, t_fractal *fractal)
// {
//     double zoom_factor;
//     double mouse_x, mouse_y;
//     double new_shift_x, new_shift_y;

//     // Dimensiones de la ventana
//     int width = 800;
//     int height = 600;

//     // Normalizamos las coordenadas del ratón a coordenadas del fractal
//     mouse_x = (x - width / 2.0) / (0.5 * fractal->zoom * width) + fractal->shift.x;
//     mouse_y = (y - height / 1.5) / (0.5 * fractal->zoom * height) + fractal->shift.y;

//     if (keycode == SCROLLDOWN)
//     {
//         zoom_factor = 0.9;
//         fractal->zoom *= zoom_factor;
//     }
//     else if (keycode == SCROLLUP)
//     {
//         zoom_factor = 1.2;
//         fractal->zoom *= zoom_factor;
//     }
//     else
//     {
//         return (0);
//     }

//     printf("before shitf x : %f , shiift y: %f \n",fractal->shift.x, fractal->shift.y);

//     // Ajustamos el desplazamiento para mantener el zoom centrado en el ratón
// 	new_shift_x = mouse_x - (x - width / 2.0) / (0.5 * fractal->zoom * width);
//     new_shift_y = mouse_y - (y - height / 2.0) / (0.5 * fractal->zoom * height);

//     fractal->shift.x = new_shift_x;
//     fractal->shift.y = new_shift_y;

//  	printf("after shitf x : %f , shiift y: %f \n",fractal->shift.x, fractal->shift.y);
//     // Limpiamos la ventana y renderizamos el fractal
//     mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
//     render_fractal(fractal);

//     return (0);
// }


int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
	return (0);
}
