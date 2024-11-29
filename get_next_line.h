/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:01:45 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/29 01:07:20 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct	s_reader
{
	int				fd;
	int				pos;
	char			*ptr;
	struct s_reader	*next;
}	t_reader;

t_reader	*create_reader(int fd, int pos);
void		add_back_reader(t_reader **readers, t_reader *reader);
void		free_reader(t_reader **readers, t_reader *reader);
t_reader	*get_reader_by_fd(t_reader **readers, int fd);
char		*get_next_line(int fd);

char		**ft_split(char const *s, char c);

#endif
