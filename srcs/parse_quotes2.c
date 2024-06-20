#include "header.h"

void	remove_quotes_from_args(t_list **head)
{
	t_list	*cpy;
	char	*tmp;

	cpy = *head;
	while (cpy)
	{
		if (cpy->type == 3 || cpy->type == 4)
		{
			tmp = ft2_substr(cpy->content, 1, (ft2_strlen(cpy->content) - 2));
			if (!tmp)
				return ; //meer error handling required.
			free(cpy->content);
			cpy->content = tmp;
		}
		cpy = cpy->next;
	}
}

// combine content from list items start till end.
// also set some types for some reason.
static void	shorten_that_list(t_list **head, int start, int end)
{
	int		i;
	t_list	*new_head;
	t_list	*tmp;
	t_list	*cpy;
	char	*new_content = NULL;

	i = 0;
	cpy = *head;
	new_head = NULL;
	//if end == -1 -> quotes are on one item.
	if (end == -1)
	{
		while (cpy)
		{
			if (i == start)
			{
				if (cpy->content[0] == '\"') // weird place for types assignment
					cpy->type = 3;
				if (cpy->content[0] == '\'')
					cpy->type = 4;
			}
			i++;
			cpy = cpy->next;
		}
		return ;
	}
	//here is the actual merging of list items.
	while (cpy)
	{
		if (i >= start && i <= end)
		{
			if (i > start)
				new_content = ft2_strjoin(new_content, " ");
			new_content = ft2_strjoin(new_content, cpy->content);
			if (i == end)
			{
				if (cpy->content[ft2_strlen(cpy->content) - 1] == '\"')
					tmp = ft2_lstnew(new_content, i, 3);
				else
					tmp = ft2_lstnew(new_content, i, 4);
				ft2_lstadd_back(&new_head, tmp);
			}
			// free(cpy->content); // stil wrong place. but catches something.
			i++;
			cpy = cpy->next;
		}
		else
		{
			tmp = ft2_lstnew(cpy->content, i, cpy->type);
			ft2_lstadd_back(&new_head, tmp);
			i++;
			cpy = cpy->next;
			continue ;
		}
	}
	// fix index. -> move maybe.
	tmp = new_head;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	//clean & reassign.
	ft2_clean_list(*head);
	*head = new_head;
	return ;
}

//add an int of how many skips of sets have to happen?
int merge_quoted_shit(t_list **head, int skip, char c)
{
	t_list	*cpy;
	int		i = 0;
	int		k = -1; //first quote
	int		l = -1;	//second quote

	cpy = *head;
	while (cpy)
	{
		i = 0;
		while (cpy->content[i])
		{
			if (cpy->content[i] == c)
			{
				if (skip > 0)
				{
					skip--;
					i++;
					continue ;
				}
				if (k >= 0)
					l = cpy->index;
				else if (k < 0)
				{
					k = cpy->index;
					break ;
				}
			}
			i++;
		}
		if (k > 0 && l > 0)
			break ;
		cpy = cpy->next;
	}
	if (k >= 0 || l >= 0)
	{
		if (k != l)
			shorten_that_list(head, k, l);
	}
	return (0);
}
