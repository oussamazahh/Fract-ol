#include "mlx.h"

// #include	"minilibx-linux/mlx_int.h"
// #include "minilibx_opengl_20191021/mlx_int.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

    void *image = mlx_new_image(mlx, 640, 360);
    
    // The following code goes here.    

    mlx_loop(mlx);
}