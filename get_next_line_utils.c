/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:16:51 by hbombur           #+#    #+#             */
/*   Updated: 2021/12/01 18:31:30 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*c)

{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*dst1;
	const char		*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (const char *)src;
	i = 0;
	if (dst == src || n == 0)
		return (dst);
	while (n--)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}

char	*ft_strdup(const char	*s1)
{
	char	*copy;
	size_t	i;

	i = ft_strlen(s1) + 1;
	copy = (char *) malloc(i * sizeof(char));
	if (!copy)
		return (NULL);
	else
		ft_memcpy(copy, s1, i);
	return (copy);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*dst;
	size_t	l;
	int		i;

	i = 0;
	if (s2 == 0)
		return (0);
	if (s1 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc(l);
	if (!dst)
		return (NULL);
	l = 0;
	while (s1[i] != '\0')
		dst[l++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dst[l++] = s2[i++];
	dst[l] = '\0';
	return (dst);
}

char	*ft_strchr(const char	*s, int	c)
{
	char	b;
	char	*str;

	b = (unsigned char)c;
	str = (char *) s;
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == b)
			return (str);
		str++;
	}
	if (*str == b)
		return (str);
	return (0);
}
