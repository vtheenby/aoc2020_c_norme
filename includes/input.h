#ifndef INPUT_H
# define INPUT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024

char	**get_input(char *filename);

#endif