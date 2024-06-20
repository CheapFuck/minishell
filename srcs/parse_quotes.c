#include "header.h"

static int	quote_counter(t_list **head, char c)
{
	int		i;
	int		count;
	t_list	*cpy;

	
	count = 0;
	cpy = *head;
	while (cpy)
	{
		i = 0;
		while(cpy->content[i])
		{
			if (cpy->content[i] == c)
				count++;
			i++;
		}
		cpy = cpy->next;
	}
	return (count);
}

void	new_find_quotes(t_list **head)
{
	int		singles_count;
	int		doubles_count;
	t_list	*cpy;
	int		tmp;

	tmp = 0;
	cpy = *head;
	singles_count = quote_counter(head, '\'');
	doubles_count = quote_counter(head, '\"');
	if (doubles_count % 2 != 0)
	{
		printf("open double quotes is nono. \n");
		return ;//-1 time.
	}
	while (tmp < doubles_count)
	{
		merge_quoted_shit(&*head, tmp, '\"');
		tmp += 2;
	}
	tmp = 0;
	if (singles_count % 2 != 0)
	{
		printf("open single quotes is nono. \n");
		return ; //-1 time.
	}
	while (tmp < singles_count)
	{
		merge_quoted_shit(&*head, tmp, '\'');
		tmp += 2;
	}
	remove_quotes_from_args(head); // temp fix for quote removal from args.
	check_for_dollah(head); // Expand $VARs to vallue. (not yet, only finds it)
	return ;
}

//find variables $var in quoted text.
void	check_for_dollah(t_list **head)
{
	t_list	*cpy;
	int		i;
	int		j;
	char	*res = NULL;

	cpy = *head;
	while (cpy)
	{
		if (cpy->type == 3)
		{
			i = 0;
			while (cpy->content[i])
			{
				if (cpy->content[i] == '$')
				{
					printf("TEST find $\n"); 
					j = i + 1;
					while (cpy->content[j])
					{
						j++;
						if (cpy->content[j] == ' ' || cpy->content[j] == '\0' || cpy->content[j] == '\"')
						{
							res = ft2_substr(cpy->content, i, j - i);
							printf("res: -%s-\n", res);
							// tijd om $var te vervangen voor de waarde? //also cleaning...
							break ;
						}
					}
				}
				i++;
			}
		}
		cpy = cpy->next;
	}
}
