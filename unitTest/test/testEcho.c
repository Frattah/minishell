#include "../../minishell.h"

int	main(int ac, char **av)
{
	ac++;
	echo(av + 1);
}
