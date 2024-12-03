#include <fcntl.h>
#include <unistd.h>

# include <stdio.h>
# include "get_next_line.h"

int	main(int argc, char *argv)
{
	(void) argc;
	(void) argv;
	int	fd;
	int	fd1;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));

	close(fd);
	close(fd1);
	return (0);
}
