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
    // free (len1);
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

//signifie: contagous allocation
//alloue la mémoire nécessaire pour un tableau 
//de nmemb éléments de size octets, et renvoie 
//un pointeur vers la mémoire allouée
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*new;
	size_t	sb;

	sb = nmemb * size;
	new = malloc (sb);
	if (new)
	{
		ft_memset(new, 0, sb);
		return (new);
		free(new);
	}
	return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	x;
	unsigned char	*p;

	x = (unsigned char) c;
	p = (unsigned char *) s;
	while (n > 0)
	{
		*p = x;
		p++;
		n--;
	}
	return (s);
}

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}


