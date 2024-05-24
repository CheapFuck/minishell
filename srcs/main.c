#include "header.h"

int main(void)
{
	char *user_input;
	int i = 0;
	HIST_ENTRY **the_history_list;

	// add signal mask
	// initialize_signals();

	// test getenv.
	printf("PATH : %s\n", getenv("PATH"));
	printf("HOME : %s\n", getenv("HOME"));
	printf("ROOT : %s\n", getenv("ROOT"));
	
	// test readline.
	using_history();
	while(1)
	{
		printf("%d - ", i);
		user_input = readline("Enter text: ");
		add_history(user_input);
		printf("%s", user_input);
		printf("\n\n");
		i++;
	}
	// display history?
	// HIST_ENTRY **history_list(void)
	history_get_history_state();
	printf("pointer to hist list: %p\n", &the_history_list);
	// printf("history entry: %s\n", the_history_list->hist_entry);
	// printf("%s\n", the_history_list[0][0]);
	return (0);
}



// int main() {
//     char *input;
//     int status ;
    
//     while(1)
//     {
//         input = readline("myshell> ");
//     if (input && *input)
//         add_history(input);
//     // printf("input = %s\n", input);
//     // status = system(input);
//     if (ft_strncmp(input, "echo -n", ft_strlen(input)) == 0)
//         printf("echo min n\n");
//     if (ft_strncmp(input, "cd", ft_strlen(input)) == 0)
//         printf("cd\n");
//     if (ft_strncmp(input, "pwd", ft_strlen(input)) == 0)
//         printf("pwd\n");
//     if (ft_strncmp(input, "export", ft_strlen(input)) == 0)
//         printf("export\n");
//     if (ft_strncmp(input, "unset", ft_strlen(input)) == 0)
//         printf("unset\n");
//     if (ft_strncmp(input, "env", ft_strlen(input)) == 0)
//         printf("env\n");
//     if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
//         printf("exit\n");
//     }
//     free(input);

//     return 0;
// }