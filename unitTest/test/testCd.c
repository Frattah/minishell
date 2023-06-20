#include "../../minishell.h"

int main(int ac, char **av, char **en)
{
	t_shell	*sh = init_shell(en);
	char	cwd[100];

	printf("%s\n", getcwd(cwd, 100));
	ac++;
	cd(av[1], sh->en);
	printf("%s\n", getcwd(cwd, 100));
	free_lst(sh->en);
	free(sh);
}
