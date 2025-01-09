#include "get_next_line_bonus.h"
#define MAX_FD 1024

char	*get_next_line(int fd);
ssize_t	read_file_chunk(int fd, char *buffer, ssize_t *i, ssize_t *bytes_read);

char	*get_next_line(int fd)
{
	static t_state	states[MAX_FD];
	char				*line;
	char				c;
	t_state				*ctx;

	if (fd < 0 || fd > MAX_FD)
		return (NULL);
	ctx = &states[fd];
	line = NULL;
	ctx->bytes = read_file_chunk(fd, ctx->buf, &ctx->i, &ctx->bytes);
	if (ctx->bytes < 0)
		return (NULL);
	while (ctx->bytes > 0)
	{
		c = ctx->buf[ctx->i++];
		line = append_char(line, c);
		if (!line)
			return (NULL);
		if (c == '\n')
			return (line);
		if (ctx->i >= ctx->bytes)
			ctx->bytes = read_file_chunk(fd, ctx->buf, &ctx->i, &ctx->bytes);
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
