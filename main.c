#include <fcntl.h>
#include <unistd.h>

# include <stdio.h>
# include "get_next_line.h"

int	main(int argc, char *argv)
{
	(void) argc;
	(void) argv;
	int	fd;

	fd = open("text.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}
