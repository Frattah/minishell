#include "minishell.h"

int	main(int ac, char **av, char **en)
{
	t_shell	*sh = init_shell(en);
	char	**splitted = ft_split(av[1], ' ');
	t_lst_cmd l = tokenize(splitted);
	print_lst_cmd(l);
	redirect_cmd(l, sh->en);
	free_split(splitted);
	free_lst(sh->en);
	free(sh);
}
