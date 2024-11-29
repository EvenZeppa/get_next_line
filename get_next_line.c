/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:01:42 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/29 01:06:04 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	ptr = malloc(sizeof(char) * s_len + 1);
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s, s_len + 1);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;


	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char *add_new_read(int fd, char *ptr)
{
	char	*new_ptr;
	char	buffer[BUFFER_SIZE + 1];
	int		read_nb;

	read_nb = read(fd, buffer, BUFFER_SIZE);
	if (read_nb <= 0)
		return (ptr);
	buffer[read_nb] = '\0';
	size_t old_len = (ptr) ? strlen(ptr) : 0;
	new_ptr = malloc(old_len + read_nb + 1);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		strcpy(new_ptr, ptr);
		free(ptr);
	}
	else
		new_ptr[0] = '\0';
	strcat(new_ptr, buffer);
	return (new_ptr);
}

char	*str_until_i(char *ptr, int i)
{
	char	*res;

	res = malloc(i + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, ptr, i + 2);
	res[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*res;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = add_new_read(fd, ptr);
	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		ptr = add_new_read(fd, ptr);
		if (!ptr || ptr[0] == '\0')
			return (NULL);
		return (get_next_line(fd));
	}
	res = str_until_i(ptr, i);
	temp = ptr;
	ptr = ft_strdup(ptr + i + 1);
	return (free(temp), res);
}
