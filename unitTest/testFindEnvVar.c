#include "../minishell.h"

int	main(int ac, char **av, char **en)
{
	char	*path = find_env_var(en, av[1]);
	if (path != NULL)
		printf("%s\n", path);
	else
		printf("NON TROVATO\n");
}
