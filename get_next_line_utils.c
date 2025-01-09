#include "get_next_line.h"

char	*append_char(char *str, char c)
{
	size_t	len;
	char	*temp;

	if (!str)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	temp = NULL;
	len = ft_strlen(str);
	temp = (char *)ft_realloc(str, len, len + 2);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	str = temp;
	str[len] = c;
	str[len + 1] = '\0';
	return (str);
}

size_t	ft_strlen(const char *__s)
{
	size_t	i;

	i = 0;
	if (!__s)
		return (0);
	while (__s[i] != '\0')
		i++;
	return (i);
}

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	i;

	if (new_size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (old_ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_ptr)
	{
		i = 0;
		while (i < old_size)
		{
			((unsigned char *)new_ptr)[i] = ((unsigned char *)old_ptr)[i];
			i++;
		}
		free(old_ptr);
	}
	return (new_ptr);
}
