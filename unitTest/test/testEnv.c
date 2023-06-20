#include "../../minishell.h"

int	main(int ac, char **av, char **en)
{
	t_shell	*sh = init_shell(en);

	ac++;
	av++;
	env(sh->en);
	free_lst(sh->en);
	free(sh);
}
