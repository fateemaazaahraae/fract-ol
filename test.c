#include "fractol.h"

void    my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
    char    *dst;

    dst = fractal->buf + (y * fractal->size_line + x * (fractal->bit_per_pixel / 8));
    *(unsigned int*)dst = color;
}

unsigned int draw_julia(t_fractal *fractal, double x, double y, double cx, double cy)
{
    double temp;

    fractal->iteration = 0;
    fractal->z_r = 4 * x / 700 - 2;
    fractal->z_i = 4 * y / 700 - 2;
    while (fractal->iteration < 50) 
    {
        if ((fractal->z_r * fractal->z_r + fractal->z_i * fractal->z_i) > 4.0)
            break;
        temp = fractal->z_i;
        fractal->z_i = 2 * fractal->z_r * fractal->z_i + cy;
        fractal->z_r = pow(fractal->z_r, 2) - pow(temp, 2) + cx;
        fractal->iteration++;
    }
    if (fractal->iteration == 50)
        return (0x0);
    else
        return (0x222324 * fractal->iteration);
}

int main(int ac, char **av)
{
    t_fractal fractal;

    /* if (av[1])
        usage(); */
    fractal.mlx = mlx_init();
    fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "fractal");
    fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
    fractal.buf = mlx_get_data_addr(fractal.img, &fractal.bit_per_pixel, &fractal.size_line, &fractal.endian);
    for (double x = 0; x < WIDTH; x++)
    {
        for (double y = 0; y < HEIGHT; y++)
        {
            mlx_pixel_put(fractal.mlx, fractal.win, x, y, draw_julia(&fractal, x, y, atof(av[1]) , atof(av[2])));
            // draw_julia(&fractal, x, y, 0, 0.8);
        }
    }
    //mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
    mlx_loop(fractal.mlx);
}