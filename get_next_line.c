#include "get_next_line.h"

char	*read_line(int fd, char *buff, char *buffer)
{
	int	count;

	count = 1;
	while (!ft_strchr(buff, '\n') && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		buff = ft_strjoin(buff, buffer);
		if (!buff)
			return (NULL);
	}
	return (buff);
}

char	*new_line(char *line)
{
	char	*line_next;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	line_next = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*line_next)
		return (NULL);
	line[i + 1] = '\0';
	return (line_next);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff);
		buff = (NULL);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = read_line(fd, buff, buffer);
	free(buffer);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	buff = new_line(line);
	return (line);
}
