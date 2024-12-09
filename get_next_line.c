/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:01:42 by ezeppa            #+#    #+#             */
/*   Updated: 2024/12/09 19:54:31 by ezeppa           ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr && *ptr != (unsigned char)c)
		ptr++;
	if (*ptr != (unsigned char)c)
		return (NULL);
	return (ptr);
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

char	*ft_strldup(const char *s, size_t size)
{
	int		s_len;
	char	*ptr;

	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s, size);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strldup("", 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, &s[start], (len + 1));
	return (ptr);
}

typedef struct	s_reader
{
	int				fd;
	char			*ptr;
	struct s_reader	*next;
}	t_reader;

t_reader	*add_back_reader(t_reader *reader, int fd)
{
	t_reader	*new;
	t_reader	*current;

	new = malloc(sizeof(t_reader) * 1);
	if (!new)
		return (NULL);
	new->fd = fd;
	new->ptr = ft_strldup("", 1);
	new->next = NULL;
	current = reader;
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = new;
	return (new);
}

t_reader	*get_reader_by_fd(t_reader *reader, int fd)
{
	t_reader		*current_reader;

	current_reader = reader;
	while (current_reader)
	{
		if (current_reader->fd == fd)
			return (current_reader);
		current_reader = current_reader->next;
	}
	return (add_back_reader(reader, fd));
}

char	*get_next_line(int fd)
{
	static t_reader	*reader;
	t_reader		*current_reader;
	char			*buffer;
	int				len;

	if (!reader)
		reader = add_back_reader(reader, fd);
	current_reader = get_reader_by_fd(reader, fd);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!current_reader || !buffer)
		return (NULL);
	len = read(current_reader->fd, buffer, BUFFER_SIZE);
	buffer[len] = '\0';
	current_reader->ptr = ft_strjoin(current_reader->ptr, buffer);
	if (!ft_strchr(current_reader->ptr, '\n'))
		return (free(buffer), get_next_line(fd));
	free(buffer);
	buffer = ft_strldup(current_reader->ptr,
		(ft_strchr(current_reader->ptr, '\n') - current_reader->ptr + 1));
	return (free(buffer), current_reader->ptr);
}
