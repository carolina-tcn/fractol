/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:36 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/28 17:49:31 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 600

# define ERROR_1		"INVALID INPUT\n\n"
# define ERROR_2		"·INSTRUCTIONS·\nList of parameters:\n\t"
# define ERROR_3		"Option(1): Mandelbrot\n\t"
# define ERROR_4		"Option(2): Julia <parameter 2> <parameter 3>\n\n" 
# define ERROR_5		"\tRange of parameters for variations...< -2 ≤ X ≤ 2>"
# define ERROR_6						"... < -2 ≤ Y ≤ 2 >\n"
# define ERROR_7		"\t---A maximum of 6 decimals is allowed (use .)---\n"
# define MLX_ERROR	1
# define EXIT_FAILURE 1

# define NEON_BLUE   0x00BFFF

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
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);
int		color(int color, int i);
void	assign_ex_julia(t_fractal *f);
void	ft_error(void);

#endif
