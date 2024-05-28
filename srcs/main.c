#include "header.h"

int main(void)
{
	int			status = -1;
	char		*user_input;
	char		**args = NULL;
	int			i = 0;
	int			j = 0;
	// HIST_ENTRY	**the_history_list;

	using_history();
	while(status == -1)
	{
		printf("%d-", i);
		user_input = readline(": ");
		args = ft_split(user_input);
		while (args[j])
		{
			printf("args[%d]: %s\n", j, args[j]);
			j++;
		}
		j = 0;
		add_history(user_input);
		printf("\n");
		i++;
	}
	return (0);
}

