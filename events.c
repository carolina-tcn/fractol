
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
    {
        fractal->xmin -= (fractal->xmax - fractal->xmin) * i;
        fractal->xmax -= (fractal->xmax - fractal->xmin) * i;
    }
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

int	close_red_cross(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
	return (0);
}