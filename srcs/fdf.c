#include "../incl/fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"

int	put_error(char *error)
{
	if (error)
		ft_printf("%s\n", error);
	exit(1);
}

t_plist	build_plist(char *file)
{
	int		lines;
	char	*line;
	t_point	*list;
	size_t	size;
	t_plist	plist;
}

/*
void	draw(void)
{

}

t_frame *build_frame(int width, int height,  
*/

int main(int ac, char **av)
{
	int		fd;
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (ac != 2)
		exit(1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(1);
	close(fd);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1600, 1000, "fdf"); //golden ratio
	while(1);
}
