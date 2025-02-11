# include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == 0)
		return (NULL);
	while (i < len1)
	{
		res = ft_memcpy(res, s1, len1);
		i++;
	}
	while (j < len2)
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
    free (len1);
	return (res);
}

//search un char ds chaine & renvoie 1 ptr lrsq 1ere occurence du char trouve
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char) c)
	{
		if (!*str++)
		{
			return (NULL);
		}
	}
	return ((char *)str);
}



