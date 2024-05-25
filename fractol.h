/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:36 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/25 15:43:11 by ctacconi         ###   ########.fr       */
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
# define HEIGHT 600

# define ERROR_1		"INVALID INPUT\n\n"
# define ERROR_2		"·INSTRUCTIONS·\nList of parameters:\n\tOption(1): Mandelbrot\n\tOption(2): Julia <parameter 2> <parameter 3>\n\n" 
# define ERROR_3		"\tRange of parameters for variations ...< -2 ≤ X ≤ 2> ... < -2 ≤ Y ≤ 2 >\n"
# define ERROR_4		"\t---A maximum of 6 decimals is allowed (use .)---\n"
# define MLX_ERROR	1
# define EXIT_FAILURE 1

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

# define ESC				53
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define ARROW_DOWN			125
# define ARROW_UP			126
# define SCROLLUP			4
# define SCROLLDOWN			5
# define SHIFT				257
# define TAB				48

typedef struct _complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			type;
	t_complex	shift;
	t_complex	c;
	t_complex	z;
	int			color;
	double		zoom;
	double		definition;
	double		limit;
}			t_fractal;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	check_args(int argc, char **argv, t_fractal *fractal);
double	ft_atod(const char *str, double res, double decimal, int i);
void	print_error_exit(void);
void	init(t_fractal *fractal);
void	render_fractal(t_fractal *fractal);
int		manage_key(int keycode, t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);
int		close_red_cross(t_fractal *fractal);
void	assign_type(char *str, t_fractal *f);
double	map(double unscaled_num, double new_min, double new_max, double old_max);
int	color(int color, int i);

#endif
