/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:35:56 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/14 13:54:46 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define ESC 53
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define ERROR_1		"NO INPUT\n"
# define ERROR_2		"INVALID INPUT\n"
# define ERROR_3		"List of parameters:\n\tMandelbrot\n\tJulia (-2 <= x <= 2, -2 <= y <= 2)\n" 

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int 	bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		fractal_type;
}				t_data;

void	check_args(int argc, char **argv);


#endif
