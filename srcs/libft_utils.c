#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		dest[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
