/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*           	                                      +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipe(char *s)
{
	return (!ft_strncmp(s, "|", 2) || !ft_strncmp(s, ">", 2)
		|| !ft_strncmp(s, "<", 2) || !ft_strncmp(s, ">>", 3)
		|| !ft_strncmp(s, "<<", 3));
}

t_lst_cmd	tokenize(char **args)
{
	t_lst_cmd	out;
	t_lst_cmd	j;
	int			i;

	i = -1;
	j = (t_cmd *) malloc(sizeof(t_cmd));
	while (args[++i])
	{
		if (i == 0 || args[i - 1] == NULL)
		{
			if (i == 0)
				out = j;
			j->next = (t_cmd *) malloc(sizeof(t_cmd));
			j->next->args = args + i;
		}
		else if (is_pipe(args[i]))
		{
			create_str(args[i], &j->next->pipe);
			args[i] = NULL;
			j = j->next;
		}
	}
	j->next->next = NULL;
	return (out);
}

void	redirect_cmd(t_lst_cmd l, t_lst en)
{
	char	**folders;

	folders = ft_split(find_env_var(en, "PATH"), ':');
	l = l->next;
	while (l != NULL)
	{
		l->path = ft_strdup(find_exec(folders, l->args[0]));
		l = l->next;
	}
	free_split(folders);
}

void	print_lst_cmd(t_lst_cmd l)
{
	int	i;

	l = l->next;
	while (l != NULL)
	{
		i = -1;
		printf("\nCMD_____________\nargs = ");
		while (l->args[++i])
			printf("%s ", l->args[i]);
		printf("\npath = %s\n", l->path);
		printf("pipe = %s\n", l->pipe);
		l = l->next;
	}
	printf("\n");
}
