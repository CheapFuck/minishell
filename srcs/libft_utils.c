#include "header.h"

int	ft2_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft2_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i <= n
			&& s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft2_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d_char;
	unsigned char	*s_char;

	d_char = (unsigned char *)dest;
	s_char = (unsigned char *)src;
	i = 0;
	while (i < n && s_char[i] != (unsigned char)c)
	{
		d_char[i] = s_char[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		d_char[i] = s_char[i];
		i++;
		return (&d_char[i]);
	}
}

char	*ft2_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	size_t	len1;
	size_t	len2;

	if (!s1)
		len1 = 0;
	else
		len1 = (size_t)ft2_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = (size_t)ft2_strlen(s2);
	len = len1 + len2;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	ft2_memccpy(&dest[0], s1, '\0', len1);
	ft2_memccpy(&dest[len1], s2, '\0', len2);
	dest[len] = '\0';
	return (dest);
}

char	*ft2_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		if (i >= start && j < len)
		{
			res[j] = s1[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	ft2_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
