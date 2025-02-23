# include "get_next_line.h"

// join and free
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];   
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buff)
{
	char	*buffer;
	int		count;

	if (!buff)
		buff = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	count = 1;
	while (count > 0)
	{
		// while not eof read
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[count] = 0;
		// join and free
		buff = ft_free(buff, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buff);
}




char    *get_next_line(int fd)
{
    static char	*buff;
	char		*line;

	// if (fd == -1 || line == NULL)
	while (1)
	{
		if (fd < 0)
		{
			free(buff);
			return (NULL);
		}
		if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
			return (NULL);
		buff = read_file(fd, buff);
		if(buff == 0)
			break;
		if (!buff)
			return (NULL);
		line = ft_line(buff);
		buff = ft_next(buff);
		return(line);
	}
	return (line);
}