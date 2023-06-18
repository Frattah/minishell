#include "../minishell.h"

int	main(int ac, char **av, char **en)
{
	char	**args = ft_split(av[1]);
	expand(args, en);
	for(int i=0; args[i]; i++)
		printf("%s\n", args[i]);
	free_split(args);
}
