#include "header.h"

int	count_cmds(t_list **head)
{
	t_list *cpy;
	int		count;

	cpy = *head;
	count = 0;
	while (cpy)
	{
		if (cpy->type == 1)
			count++;
		cpy = cpy->next;
	}
	return (count);
}

t_table	*handle_that_list(t_list **head)
{
	t_list *cpy;
	t_table	*new_array;
	int		cmds;
	int		i = 0;

	cpy = *head;
	cmds = count_cmds(head);
	new_array = malloc(cmds * sizeof(t_table));
	if (!new_array)
		return (NULL);
	ft2_bzero(new_array, cmds * sizeof(t_table));
	while (cpy) //this be where the array gets filled.
	{
		if (cpy->type == 10) // TODO: grab return from previous command.
			i++;
		if (cpy->type == 1)	// = command
			new_array[i].cmd = cpy->content;
		if (cpy->type == 2)	//= option flags.
			new_array[i].options = cpy->content;
		if (cpy->type > 2 && cpy->type < 5) //argument text but no good.. cause doubles.
			new_array[i].args = cpy->content;
		if (cpy->type == 5) // input from.
			new_array[i].in_redir = cpy->content;
		if (cpy->type == 6) // write to.
			new_array[i].out_redir = cpy->content;
		if (cpy->type == 7) // write to (Append)
			new_array[i].out_redir = cpy->content;
		cpy = cpy->next;
	}
	return (new_array);
}

t_table	*parse_that_input(char *user_input)
{
	t_list		*head = NULL;
	t_list		*tmp = NULL;
	t_table		*new_array;
	char		**args;
	int			i;

	i = 0;
	args = ft2_split(user_input);
	if (!args)
		return (NULL);
	while (args[i]) //create list from ' ' new_split.
	{
		tmp = ft2_lstnew(args[i], i, -1);
		ft2_lstadd_back(&head, tmp);
		i++;
	}
	new_find_quotes(&head);			// add -1 return for open quotes!
	set_prev_pointers(&head);		// Fix for pre array list. move somewhere.
	set_list_types_redir(&head);	// Set everything. this continues. add error handl.
	// printf("----\n"); new_print_list(&head); printf("----\n"); // print the pre array list.
	new_array = handle_that_list(&head);
	print_that_table(new_array, count_cmds(&head));
	ft2_clean_list(head); // clean head->content later they be pointed to in array.
	return (new_array);
}