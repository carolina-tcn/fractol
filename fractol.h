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

# define ERROR_1		"'NO INPUT\n"
# define ERROR_2		"INVALID INPUT\n\n"
# define ERROR_3		"·INSTRUCTIONS·\nList of parameters:\n\tOption(1): Mandelbrot\n\tOption(2): Julia <parameter 2> <parameter 3>\n\n" 
# define ERROR_4		"\tRange of parameters for variations ... < -2 ≤ X ≤ 2> ... < -2 ≤ Y ≤ 2 >\n"
# define ERROR_5		"\t---A maximum of 6 decimals is allowed---\n"

# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define MAGENTA 0xFF00FF
# define CYAN    0x00FFFF
# define ORANGE  0xFFA500
# define PURPLE  0x800080
# define SKYBLUE 0x87CEEB
# define AQUA    0x00FFFF
# define LIME    0x00FF00
# define NEON_PINK   0xFF69B4
# define NEON_GREEN  0x39FF14
# define NEON_YELLOW 0xFFFF00
# define NEON_ORANGE 0xFF8C00
# define NEON_BLUE   0x00BFFF
# define NEON_PURPLE 0xBA55D3
# define NEON_SKYBLUE 0x87CEEB
# define NEON_RED    0xFF0000
# define NEON_AQUA   0x00FFFF
# define NEON_LIME   0x00FF7F

typedef struct s_complex
{
	double x; //real
	double y; //imaginary
}			t_complex;

typedef struct	s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int 		bpp;
	int			line_lenght;
	int			endian;
	char 		*name;
	t_complex	c;
	t_complex	shift_c;
	t_complex	z;
	double		zoom;
	double		definition;
	double		limit;

}			t_fractal;

void	check_args(int argc, char **argv, t_fractal *fractal);
double	ft_atod(const char *str, double res, double decimal, int i);
void	print_error_exit(void);

#endif
