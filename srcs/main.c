#include "header.h"
// #include <signal.h>

// void handler(int num)
// {
// 	(void) num;

// 	printf("don't stop\n"); // use write
// 	//segfaults because... ?
// 	return ;
// }

// int main(int argc, char **argv, char **envp) //envp var
int	main(void)
{
	int			status = -1;
	char		*user_input;
	char		**args = NULL;
	int			j = 0;
	// HIST_ENTRY	**the_history_list;

	t_list		*head = NULL;
	t_list		*tmp = NULL;

	// Test envp var.
	// printf("PATH : %s\n", getenv("PATH"));
	// printf("HOME : %s\n", getenv("HOME"));
	// printf("ROOT : %s\n", getenv("ROOT"));
	// printf("PWD : %s\n\n", getenv("PWD"));
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	// end envp var.

	//signal time
	// signal(SIGINT, handler);
	// printf("pid: %d\n", getpid());

	using_history();
	while(status == -1)
	{
		user_input = readline("-> ");
		args = ft_split(user_input);
		while (args[j])
		{
			tmp = ft_lstnew(args[j], j);
			ft_lstadd_back(&head, tmp);
			j++;
		}
		j = 0;
		// parse it
		check_spelling(&head);
		// hieronder lelijkheid.
		if (ft_strncmp(head->content, "exit", ft_strlen(head->content)) == 0)
			status = 1;

		if (ft_strncmp(head->content, "cd", ft_strlen(head->content)) == 0)
		{
			handle_chdir(args[1]);
		}
		if (ft_strncmp(head->content, "pwd", ft_strlen(head->content)) == 0)
		{
			printf("%s\n", getenv("PWD"));
		}
		// print_list(&head); //print list
		clean_list(head);
		head = NULL;

		add_history(user_input);
		printf("\n");
	}
	return (0);
}
