#include <fcntl.h>
#include <unistd.h>

# include <stdio.h>
# include "get_next_line.h"

int	min(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);

	get_next_line(fd);

	close(fd);
	return (0);
}
