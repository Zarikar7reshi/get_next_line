#include "get_next_line.h"

char	*get_next_line(int fd);
ssize_t	read_file_chunk(int fd, char *buffer, ssize_t *i, ssize_t *bytes_read);

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	i = 0;
	static ssize_t	bytes_read = 0;
	char			*line;
	char			c;

	line = NULL;
	bytes_read = read_file_chunk(fd, buffer, &i, &bytes_read);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		c = buffer[i++];
		line = append_char(line, c);
		if (!line)
			return (NULL);
		if (c == '\n')
			return (line);
		if (i >= bytes_read)
			bytes_read = read_file_chunk(fd, buffer, &i, &bytes_read);
	}
	return (line);
}

ssize_t	read_file_chunk(int fd, char *buffer, ssize_t *i, ssize_t *bytes_read)
{
	if (*i >= *bytes_read)
	{
		*i = 0;
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			return (*bytes_read);
	}
	return (*bytes_read);
}
