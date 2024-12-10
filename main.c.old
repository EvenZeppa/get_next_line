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
	char *line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);

	while ((line = get_next_line(fd1)) != NULL)
	{
		// Utilisez la ligne comme nécessaire, par exemple l'afficher
		printf("%s", line);
		free(line); // Libérez la mémoire allouée pour chaque ligne
	}

	line = get_next_line(fd1);
	printf("%s", line);
	free(line); // Libérez la mémoire allouée pour chaque ligne

	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));

	// printf("%s", get_next_line(STDIN_FILENO));
	// printf("%s", get_next_line(STDIN_FILENO));

	close(fd);
	close(fd1);
	return (0);
}
