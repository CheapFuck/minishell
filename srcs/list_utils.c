
#include "header.h"

void	new_print_list(t_list **head) //tmp
{
	t_list *cpy;

	cpy = *head;
	printf("\n");
	while (cpy)
	{
		printf("index: %d\n", cpy->index);
		printf("type: %d\n", cpy->type);
		printf("content: %s\n", cpy->content);
		if (cpy->prev)
			printf("type before = %d\n", cpy->prev->type);
		if (cpy->next)
			printf("type after = %d\n", cpy->next->type);
		printf("\n");
		cpy = cpy->next;
	}
}

void	print_list(t_list **head) //tmp
{
	t_list *cpy;

	cpy = *head;
	printf("\n");
	while (cpy)
	{
		printf("index: %d\n", cpy->index);
		printf("type: %d\n", cpy->type);
		printf("content: %s\n", cpy->content);
		printf("\n");
		cpy = cpy->next;
	}
}

t_list	*ft2_lstnew(char *content, int nbr, int type)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->index = nbr;
	new->type = type;
	new->content = content;
	return (new);
}

void	ft2_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tail;

	if (!*(head))
	{
		*(head) = new;
		return ;
	}
	tail = *(head);
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new;
}

void	ft2_clean_list(t_list *head)
{
	t_list	*next;

	while (head)
	{
		next = head->next;
		// free(head->content); //invalid reads?
		free(head);
		head = next;
	}
}
