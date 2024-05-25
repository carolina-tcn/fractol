/*void	img_mandelbrot(t_fractal *fractal, int x, int y)
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
}*/

// int	color(int i)
// {
// 	int	color;
// 	int	r;
// 	int	g;
// 	int	b;

// 	r = (i * 9) % 255;
// 	g = (i * 2) % 255;
// 	b = (i * 9) % 255;
// 	color = create_trgb(0, r, g, b);
// 	return (color);
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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