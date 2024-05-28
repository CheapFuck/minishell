#include "header.h"

/**
* split input into words - all illegal funcs
*/
static int		count_words(char *str)
{
	int	i = 0;
	int count = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
		{
			if (i == 0 || str[i - 1] == '\t' || str[i - 1] == ' ' || str[i - 1] == '\n')
			{
				i++;
				continue;
			}
			count++;
		}
		else if (str[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int	wcount = 0;
	char **ret = NULL;
	int	i = 0;
	int	j = 0;
	int k = 0;
	int l = 0;

	wcount = count_words(str);
	if (wcount <= 0)
		return (NULL);
	ret = malloc((wcount + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
		{
			if (i == 0 || str[i - 1] == '\t' || str[i - 1] == ' ' || str[i - 1] == '\n')
			{
				i++;
				j++;
				continue;
			}
			ret[k] = malloc(((i - j) + 1) * sizeof(char));
			if (!ret[k])
				return (NULL);
			while (j < i)
			{
				ret[k][l] = str[j];
				j++;
				l++;
			}
			ret[k][l] = '\0';
			j++;
			k++;
			l = 0;
		}
		else if (str[i + 1] == '\0')
		{
			i++;
			ret[k] = malloc(((i - j) + 1) * sizeof(char));
			if (!ret[k])
				return (NULL);
			while (j < i)
			{
				ret[k][l] = str[j];
				j++;
				l++;
			}
			ret[k][l] = '\0';
			j++;
			k++;
			l = 0;
			break ;
		}
		i++;
	}
	ret[k] = NULL;
	return (ret);
}