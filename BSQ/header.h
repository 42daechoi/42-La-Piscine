#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 1024

typedef struct s_mapinfo
{
	int		x_len;
	int		y_len;
	int		first_len;
	char	empty;
	char	obstacle;
	char	fill;
}	t_mapinfo;

typedef struct s_maxinfo
{
	int	max_x;
	int	max_y;
	int	max_len;
}	t_maxinfo;

void	ft_set_map(char *buff, char **arr, t_mapinfo mi);

char	**ft_do_malloc(char **arr, t_mapinfo mi);

int		**ft_do_intmalloc(int **arr, t_mapinfo mi);

void	ft_find_biggest(int **num_arr, t_mapinfo mi, t_maxinfo *maxinfo);

void	ft_filled_map(char **arr, t_mapinfo mi, t_maxinfo maxinfo);

char	**ft_free(char **arr, t_mapinfo mi);

int		**ft_intfree(int **arr, t_mapinfo mi);

#endif
