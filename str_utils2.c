/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_strconc(char *s1, char *s2)
{
	char	*nw;
	size_t	ln;

	ln = ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1;
	nw = (char *) malloc(sizeof(char) * ln);
	if (nw == NULL)
		return (NULL);
	nw[0] = '\0';
	ft_strlcat(nw, s1, ft_strlen(s1, '\0') + 1);
	ft_strlcat(nw, s2, ln);
	return (nw);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ln;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src, '\0'));
	ln = ft_strlen(dst, '\0');
	i = -1;
	if (dstsize == 0)
		return (ft_strlen(src, '\0'));
	if (ln < dstsize - 1 && dstsize > 0)
	{
		while (src[++i] && ln + i < dstsize - 1)
			dst[ln + i] = src[i];
		dst[ln + i] = '\0';
	}
	if (ln > dstsize)
		ln = dstsize;
	return (ln + ft_strlen(src, '\0'));
}

char	*ft_strdup(const char *s1)
{
	char	*nw;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1, '\0') + 1;
	nw = (char *) malloc(sizeof(char) * len);
	if (nw == NULL)
		return (NULL);
	ft_strlcpy(nw, s1, len);
	return (nw);
}
