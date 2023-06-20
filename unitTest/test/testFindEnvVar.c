#include "../../minishell.h"

int	main(int ac, char **av, char **en)
{
	t_shell	*sh = init_shell(en);

	ac++;
	char	*path = find_env_var(sh->en, av[1]);
	if (path != NULL)
		printf("%s\n", path);
	else
		printf("NON TROVATO\n");
	free_lst(sh->en);
	free(sh);
}
