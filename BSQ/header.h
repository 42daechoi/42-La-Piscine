#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 1000005

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

char	*ft_do_charmalloc(char *arr, int cnt);

void	ft_find_biggest(int **num_arr, t_mapinfo mi, t_maxinfo *maxinfo);

void	ft_filled_map(char **arr, t_mapinfo mi, t_maxinfo maxinfo);

void	ft_free(char **arr, t_mapinfo mi);

void	ft_intfree(int **arr, t_mapinfo mi);

int		ft_check_arr(char **arr, t_mapinfo mi);

void	ft_err_msg(void);

int		ft_check_line(char *buff, t_mapinfo mapinfo);

int		ft_cnt_file(char **av, int *cnt, int i);

int		ft_atoi(char *str);

char	ft_strcpy(char *dest, char *src);

char	*ft_strcat(char *dest, char *src);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		read_std(t_mapinfo *mapinfo, char *buff);

void	to_do_std(void);

int		ft_strlen(char *str);

char	*malloc_buff_size(void);

int		ft_cnt_y(char *buff, int *cnt, t_mapinfo *mi);

void	ft_open_file(char **av, int cnt, int i);

int		ft_file_read(int fd, int cnt);

#endif
