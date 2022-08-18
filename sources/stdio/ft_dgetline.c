#include <stdlib.h>
#include "ft_stdio.h"
#include "ft_string.h"

static ssize_t getline_alloc_fail(char **buffer, size_t *size)
{
	free(*buffer);
	*buffer = NULL;
	*size = 0;
	return -1;
}

ssize_t ft_dgetline(int fd, char **line)
{
	static char *buffer = NULL;
	static size_t size = 0;
	ssize_t readSize;
	char readBuf[1024];

	if (read(fd, NULL, 0) == -1)
		return -1;

	char *tmp = ft_memchr(buffer, '\n', size);

	while (tmp == NULL)
	{
		readSize = read(fd, readBuf, 1024);

		if (readSize <= 0)
			break ;

		tmp = malloc(size + (size_t)readSize);

		if (tmp == NULL)
			return getline_alloc_fail(&buffer, &size);

		ft_memcpy(tmp, buffer, size);
		ft_memcpy(tmp + size, readBuf, (size_t)readSize);
		free(buffer);
		buffer = tmp;

		tmp = ft_memchr(buffer + size, '\n', (size_t)readSize);
		size += (size_t)readSize;
	}

	size_t lineSize = (tmp != NULL) ? (size_t)(tmp - buffer + 1) : size;

	if (lineSize == 0)
	{
		free(buffer);
		buffer = NULL;
		return 0;
	}

	*line = malloc(lineSize + 1);

	if (*line == NULL)
		return getline_alloc_fail(&buffer, &size);

	ft_memcpy(*line, buffer, lineSize);
	(*line)[lineSize] = '\0';
	size -= lineSize;
	ft_memmove(buffer, buffer + lineSize, size);
	return (ssize_t)lineSize;
}
