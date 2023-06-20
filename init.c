/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c   	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_occ(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*out;

	if (len >= ft_strlen(s, '\0'))
		len = ft_strlen(s, '\0');
	if (start >= ft_strlen(s, '\0'))
		len = 0;
	out = (char *) malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	i = start - 1;
	while (s[++i] && i < len + start)
		out[i - start] = s[i];
	out[i - start] = '\0';
	return (out);
}

t_shell	*init_shell(char **en)
{
	t_shell	*out;
	char	*s;	

	out = (t_shell *) malloc(sizeof(t_shell));
	out->en = (t_entry *) malloc(sizeof(t_entry));
	out->en->next = NULL;
	while (*en)
	{
		s = ft_substr(*en, 0, first_occ(*en, '='));
		put_lst(out->en, s, *en + first_occ(*en, '=') + 1);
		free(s);
		en++;
	}
	return (out);
}
