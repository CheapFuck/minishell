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