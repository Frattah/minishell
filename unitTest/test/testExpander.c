#include "../../minishell.h"

int	main(int ac, char **av, char **en)
{
	t_shell	*sh = init_shell(en);

	char	**args = ft_split(av[1]);
	expand(args, sh->en);
	ac++;
	for(int i=0; args[i]; i++)
		printf("%s\n", args[i]);
	free_split(args);
	free_lst(sh->en);
	free(sh);
}
