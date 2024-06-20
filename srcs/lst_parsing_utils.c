#include "header.h"

void	set_prev_pointers(t_list **head)
{
	t_list *cpy;
	t_list *tmp;

	if (!*head)
		return ;
	tmp = *head;
	cpy = *head;
	cpy = cpy->next;
	while (cpy)
	{
		cpy->prev = tmp;
		cpy = cpy->next;
		tmp = tmp->next;
	}
}

static void	some_func_for_rest(t_list **head)
{
	t_list *cpy;

	cpy = *head;
	while (cpy)
	{
		if (cpy->type == -1)
		{
			if (cpy->content[0] == '-') //option flags.
				cpy->type = 2;
			else if (cpy->prev)
			{
				if (cpy->prev->type == 1) // quick fix non quoted arguments
					cpy->type = 4;
			}
		}
		cpy = cpy->next;
	}
}

static void	set_list_types(t_list **head)
{
	t_list *cpy;

	cpy = *head;
	while (cpy)
	{
		if (cpy->type == -1)
		{
			if (cpy->index == 0)
				cpy->type = 1;
			if (cpy->prev != NULL)
			{
				if (cpy->prev->type == 10)	//after pipe.
					cpy->type = 1;
				if (cpy->prev->type == 8)	//get input after
					cpy->type = 5;
				if (cpy->prev->type == 9)	//write to (out redir.)
					cpy->type = 6;
				if (cpy->prev->type == 11)	//after >> (append)
					cpy->type = 7;
				if (cpy->prev->type == 12)	//the << delimit thing.
					cpy->type = 15;
			}
		}
		cpy = cpy->next;
	}
	some_func_for_rest(head);
}

void	set_list_types_redir(t_list **head)
{
	int		i;
	t_list	*cpy;
	int		result;

	i = 0;
	cpy = *head;
	while (cpy)
	{
		result = ft2_strncmp("<<", cpy->content, ft2_strlen(cpy->content));
		if (result == 0)
			cpy->type = 12;
		result = ft2_strncmp(">>", cpy->content, ft2_strlen(cpy->content));
		if (result == 0)
			cpy->type = 11;
		result = ft2_strncmp("|", cpy->content, ft2_strlen(cpy->content));
		if (result == 0)
			cpy->type = 10;
		result = ft2_strncmp(">", cpy->content, ft2_strlen(cpy->content));
		if (result == 0)
			cpy->type = 9;
		result = ft2_strncmp("<", cpy->content, ft2_strlen(cpy->content));
		if (result == 0)
			cpy->type = 8;
		cpy = cpy->next;
	}
	set_list_types(head);
	return ;
}
