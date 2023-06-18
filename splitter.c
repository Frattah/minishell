/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:50 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	cntword(char const *s)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] && !(s[i] >= 9 && s[i] <= 13 || s[i] == ' '))
			i++;
		while (s[i] && (s[i] >= 9 && s[i] <= 13 || s[i] == ' '))
		{
			if (i != 0 && !(s[i - 1] >= 9 && s[i - 1] <= 13 || s[i - 1] == ' '))
				w++;
			i++;
		}
	}
	if (s[i - 1] != '\0'
		&& !(s[i - 1] >= 9 && s[i - 1] <= 13 || s[i - 1] == ' '))
		w++;
	return (w);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src, '\0'));
}

char	*skpstr(char *s)
{
	while (*s && (*s >= 9 && *s <= 13 || *s == ' '))
		s++;
	return (s);
}

size_t	word_len(const char *s)
{
	size_t	ln;

	ln = 0;
	while (s[ln]
		&& !(s[ln] >= 9 && s[ln] <= 13 || s[ln] == ' '))
		ln++;
	return (ln);
}

char	**ft_split(char const *s)
{
	char	**split;
	size_t	words;
	char	*s_cpy;
	size_t	len;

	words = cntword(s);
	split = (char **) malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	s_cpy = (char *) s;
	split[words] = NULL;
	while (s != NULL && *s != 0 && words--)
	{
		s_cpy = skpstr(s_cpy);
		len = word_len(s_cpy);
		*split = (char *) malloc(sizeof(char) * (len + 1));
		if (*split == NULL)
			return (NULL);
		ft_strlcpy(*split++, s_cpy, len + 1);
		s_cpy += len;
	}
	return (split - cntword(s));
}
