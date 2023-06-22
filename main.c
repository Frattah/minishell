#include "minishell.h"

int	main(int ac, char **av)
{
	char	**splitted = ft_split(av[1]);
	t_lst_cmd l = tokenize(splitted);
	print_lst_cmd(l);
	free_split(splitted);
}
