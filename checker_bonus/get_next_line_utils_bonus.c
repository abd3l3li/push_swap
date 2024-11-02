/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:11:53 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/08 13:12:32 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

char	*free_buf(char *buf)
{
	free(buf);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!result)
		return (free_buf(str));
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		result[i] = str[i];
	while (buf[j] != '\0')
		result[i++] = buf[j++];
	result[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free(str);
	return (result);
}
