#include "header.h"

static void	shorten_that_list(t_list **head, int start, int end)
{
	// int		len;
	int		i;
	t_list	*new_head;
	t_list	*tmp;
	t_list	*cpy;
	char	*new_content;
	int		x = -1;

	// len = ft_lstsize(*head); //Unused?
	i = 0;
	cpy = *head;
	while (cpy)
	{
		if (i >= start && i <= end)
		{
			// quoted list items found here.
			if (x == -1)
			{
				x = 1;
				new_content = ft_strjoin(cpy->content, " ");
			}
			else
			{
				new_content = ft_strjoin(new_content, " ");
				new_content = ft_strjoin(new_content, cpy->content);
			}
			if (i == end)
			{
				printf("new: %s\n", new_content);
				tmp = ft_lstnew(new_content, i);
				ft_lstadd_back(&new_head, tmp);
			}
			i++;
			cpy = cpy->next;
		}
		else
		{
			tmp = ft_lstnew(cpy->content, i + 1);
			ft_lstadd_back(&new_head, tmp);
			i++;
			cpy = cpy->next;
		}
	}
	print_list(&new_head);
}

void check_spelling(t_list **head)
{
	t_list	*cpy;
	int		i = 0;

	int		k = -1; //bunny ear finder.
	int		l = -1;

	cpy = *head;
	while (cpy)
	{
		i = 0;
		while (cpy->content[i])
		{
			if (cpy->content[i] == '"')
			{
				if (k >= 0)
					l = cpy->index;
				else if (k < 0)
					k = cpy->index;
			}
			i++;
		}
		cpy = cpy->next;
	}
	if (k > 0 || l > 0)
	{
		if (k < 0 || l < 0)
			printf("open quotes\n"); // is a problem.
		else
		{
			if (k != l)
				shorten_that_list(head, k, l);
		}
	}
}
