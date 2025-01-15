#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);
size_t	ft_strlen(const char *__s);
char	*append_char(char *str, char c);
ssize_t	read_file_chunk(int fd, char *buffer, ssize_t *i, ssize_t *bytes_read);
#endif