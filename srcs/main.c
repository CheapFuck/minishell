#include "header.h"
#include <signal.h>

// void handler(int num)
// {
// 	(void) num;

// 	printf("don't stop\n");
// 	return ;
// }

void	print_that_table(t_table *array, int count)
{
	int i = 0;

	//if !array go back. || !count maybe..
	i = 0;
	while (i < count)
	{
		printf("\narray[%d]\n", i);
		printf("cmd: %s\n", array[i].cmd);
		printf("opts: %s\n", array[i].options);
		printf("arg: %s\n", array[i].args);
		printf("in: %s\n", array[i].in_redir);
		printf("out: %s\n", array[i].out_redir);
		i++;
	}
	printf("\n");
}

// int main(int argc, char **argv, char **envp) //envp var
int	main(void)
{
	int			status = -1;
	char		*user_input;
	t_table		*array;

	// signal(SIGINT, handler); 		//dit werkt. handler hierboven uit comments halen.
	// printf("pid: %d\n", getpid());	// kill -9 <pid> vanaf andere terminal werkt.

	using_history();
	while(status == -1)
	{
		user_input = readline("-> ");
		array = parse_that_input(user_input);
		if (!array)
			continue ;

		//! Handle commandArray hiero.

		// clean_that_table(array); //dit is een todo.
		add_history(user_input);
	}
	return (0);
}
