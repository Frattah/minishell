#include "../minishell.h"

int main(int ac, char **av, char **en)
{
	char	s[100];
	printf("%s\n", getcwd(s, 100));
	cd(av[1], en);
	printf("%s\n", getcwd(s, 100));
}
