/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_var(char **envp, char *var)
{
	size_t	ln;

	ln = ft_strlen(var, '\0');
	if (var == NULL)
		return (NULL);
	while (*envp)
	{
		if (!ft_strncmp(*envp, var, ln)
			&& (*envp)[ln] == '=')
			return ((*envp) + ln + 1);
		envp++;
	}
	return (NULL);
}

void	*expand(char **args, char **en)
{
	char	*tmp;

	while (*args)
	{
		if ((*args)[0] == '$')
		{
			tmp = find_env_var(en, (*args) + 1);
			if (tmp != NULL)
			{
				free(*args);
				*args = malloc(sizeof(char)
						* ft_strlen(tmp, '\0'));
				ft_strlcpy(*args, tmp, ft_strlen(tmp, '\0')
					+ 1);
			}
		}
		args++;
	}
}

char	*delimit_env(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !((s[i] >= 9 && s[i] <= 13 || s[i] == ' ')))
		i++;
	return (s + i);
}
