#include<stdlib.h>
#include<unistd.h>
#include "rush_01.h"

int *input;
int **arr;

int   ft_count_length(char *str)
{
    int   i;

    i = 0;
    while (str[i])
    {
        if (i % 2 == 0 && (str[i] >= 0 && str[i] <= 9))
            return -1;
        else if (i % 2 == 1 && str[i] != 32)
            return -1;
        i++;
    }
    if ((i + 1) % 8 != 0)
        return -1;
    return ((i + 1) / 8);
}

void ft_set_arr_zero(int **arr, int length)
{
	int	i;
	int	j;

	i = 0;
	while(i < length + 2)
	{
		j = 0;
		while (j < length + 2)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int   main(int argv, char *argc[])
{
    int   length;
    int   i;
	int	  k;
    int   j;

    i = 0;
    j = 0;
	k = 0;
    if (argv != 2)
        write(1, "Input error(filename param)", 27);
    else
    {
        length = ft_count_length(argc[1]);
        if (length == -1)
            write(1, "Input error(param error)", 25);
        else
        {
            input = (int *)malloc((length * 4) * sizeof(int));
			arr = (int **)malloc((length + 2) * sizeof(int *));
			while (k < length + 2)
			{
				arr[k] = (int *)malloc((length + 2) * sizeof(int));
				k++;
			}
			ft_set_arr_zero(arr, length);
			i = 0;
			j = 0;
            while (argc[1][i])
            {
                if(i % 2 == 0)
                {
                    input[j] = argc[1][i] - '0';
                    j++;
                }
                i++;
            }
            input[j] = '\0';
        }
        ft_backtracking(1, 1, length);
		free(arr);
		free(input);
    }
    return 0;
}
