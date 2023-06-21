#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include "../Libft/libft.h"

typedef struct s_data
{
	char	**envp;
}   t_data;


char	**copy_char_matrix(char **src);
void	ft_print_env(char	**matrix);
void	free_matrix(char **src);
#endif
