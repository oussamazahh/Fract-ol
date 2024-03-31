#include <mlx.h>
#include <stdio.h>



int	main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 700, 700, "Tutorial Window - Create Image");
	// void *win = mlx_new_window(mlx, 700, 700, "Tutorial Window
	// - Create Image");

	void *image = mlx_new_image(mlx, 700, 700);
	int pixel_bits;
	int line_bytes;
	int endian;
	// char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes,
	// &endian);
	// int color = 255;
	// color |= (255) << 8;
	// color |= (255) << 16;
	// int b = color;
	// b |= (255) << 24;
	int *buffer = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes,
			&endian);
	line_bytes /= 4;

	int color = 0xABCDEF;

	for (int y = 0; y < 360; ++y)
		for (int x = 0; x < 640; ++x)
		{
			buffer[(y * line_bytes) + x] = color;
		}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(mlx);
}
// #include <stdio.h>

// double rescale(double value, double old_value_min, double old_value_max, double new_value_min, double new_value_max)
// {
//     return ((value - old_value_min) * (new_value_max - new_value_min) / (old_value_max - old_value_min)) + new_value_min;
// }
// int main()
// {
//     double value = 9; // example value
//   // university vs shool in italy grades
//     printf("Rescaled Value: %.0lf\\n", rescale(value, 0, 10, 0, 30));
//     return 0;
// }